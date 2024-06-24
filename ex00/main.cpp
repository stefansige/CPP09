#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <filename>\n";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Could not open file\n";
		return 1;
	}
	std::string date;
	std::string middle;
	std::string first_line;
	float amount;
	BitcoinExchange exchange("data.csv");
	std::getline(file, first_line);
	if (first_line != "date | value")
	{
		std::cerr << "bad format => " << first_line << "\n";
		return 1;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		ss >> date >> middle >> amount;
		if (ss.fail())
		{
			std::cerr << "Error: bad input => " << line << "\n";
			continue;
		}
		if (middle != "|")
		{
			std::cerr << "Error: bad input => " << date << " " << middle << " " << amount << "\n";
			continue;
		}
		else if (amount < 0)
		{
			std::cout << "Error: not a positive number." << "\n";
			continue;
		}
		else if (amount > 1000)
		{
			std::cout << "Error: too large a number." << "\n";
			continue;
		}
		try
		{
			float price = exchange.getBitcoinPrice(date);
			std::cout << date << " => " << amount << " = " << amount * price << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
