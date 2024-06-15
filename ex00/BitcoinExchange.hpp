#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <stdexcept>

class BitcoinExchange
{
private:
	std::map <std::string, float> m_bitcoinPrices;
public:
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	float getBitcoinPrice(const std::string& date) const;
};


#endif
