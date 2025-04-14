#pragma once

#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <map>

#define DataBase "./data.csv"

class btcExchange
{
	private:
		std::map<std::string, float> _database;
		
	public:
	btcExchange();
	btcExchange(const btcExchange& copy);
	~btcExchange();
	
	btcExchange &operator=(const btcExchange& copy);
	void loadDatabase(const std::string& dbFile);
	void getValue(const std::string& inputFile);
	float getRate(const std::string& dateStr) const;
	
	//debug
	void printMap() const;
};
