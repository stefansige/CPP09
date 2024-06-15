#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file");
	}
	std::string date;
	float price;
	std::getline(file, date);
	while (std::getline(file, date, ',') && file >> price)
	{
		m_bitcoinPrices[date] = price;
		file.ignore();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	m_bitcoinPrices = other.m_bitcoinPrices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		m_bitcoinPrices = other.m_bitcoinPrices;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

float BitcoinExchange::getBitcoinPrice(const std::string& date) const
{
	if (date < m_bitcoinPrices.begin()->first || date > m_bitcoinPrices.rbegin()->first)
	{
		throw std::runtime_error("bad input => " + date);
	}
	std::map<std::string, float>::const_iterator it = m_bitcoinPrices.lower_bound(date);
	if (it->first != date)
	{
		it--;
	}
	return it->second;
}
