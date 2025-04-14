#include "BitcoinExchange.hpp"


//static helper
static inline bool isSpace(char c) {
    return std::isspace(static_cast<unsigned char>(c));
}

static std::string lineTrim(std::string line) {
    // Trim leading spaces
    size_t start = 0;
    while (start < line.size() && isSpace(line[start]))
        ++start;

    // Trim trailing spaces
    size_t end = line.size();
    while (end > start && isSpace(line[end - 1]))
        --end;

    return line.substr(start, end - start);
}
//need to check if its valid date like if its DD 34 MM 15 
static bool isValidDate(const std::string& date) {
    // Simple check: YYYY-MM-DD format
    if (date.length() != 10 ||
        date[4] != '-' || date[7] != '-')
        return false;

    // You can also check if the parts are digits
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) 
            continue;
        if (!std::isdigit(date[i])) 
            return false;
    }
    // Extract year, month, and day
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    // Validate real date
    if (day < 1 || day > 31) 
        return false;
    if (month < 1 || month > 12) 
        return false;

    // April, June, September, November have max 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    // February leap year check
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if ((isLeap && day > 29) || (!isLeap && day > 28))
            return false;
    }
    return true;
}
//need to validate the valueStr
static bool isValidValue(const std::string& valueStr) {
    // Trim spaces from the string
    // std::cout << "the value str is: " << valueStr << std::endl;
    std::string str = valueStr;
    str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);

    // Regular expression for a valid float or integer
    std::regex numberPattern(R"(^[-+]?\d*\.?\d+(e[-+]?\d+)?$)", std::regex::icase);

    if (!std::regex_match(str, numberPattern)) {
        std::cerr << "Error: invalid number format => " << valueStr << std::endl;
        return false;
    }
    try {
        float value = std::stof(str);
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            return false;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            return false;
        }
        return true;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << " => " << str << std::endl;
        return false;
    }
}

btcExchange::btcExchange()
{
	loadDatabase(DataBase);
}

btcExchange::btcExchange(const btcExchange& copy)
{
	(void)copy;
}

btcExchange::~btcExchange()
{

}

btcExchange& btcExchange::operator=(const btcExchange& copy)
{
	if (this != &copy)
	{
		(void)copy;
	}
	return (*this);
}

void btcExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile);
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open the file: " << dbFile << std::endl;
		return;
	}
    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) 
	{
        std::istringstream ss(line); //getline expects stream as its first argument, 
        std::string date;
		std::string rateStr;

		std::getline(ss, date, ',');
		std::getline(ss, rateStr);
   
        float rate = std::stof(rateStr);
        _database[date] = rate;
    }
}

void btcExchange::getValue(const std::string& inputFile)
{
	std::ifstream file(inputFile);
	if (!file.is_open())
	{
		std::cerr << "Error: couldn't open the file: " << inputFile << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line); //skip header

	while (std::getline(file, line))
	{
		line = lineTrim(line);
		size_t sepa = line.find(" | ");
		if (sepa == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sepa);
		std::string valueStr = line.substr(sepa + 3);
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad date => " << date << std::endl;
			continue;
		}
		if (!isValidValue(valueStr))
			continue;
		float value = std::stof(valueStr);
		float rate = getRate(date);
		float result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

float btcExchange::getRate(const std::string& dateStr) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(dateStr);

    if (it != _database.end() && it->first == dateStr) {
        // Exact match
        return it->second;
    }

    if (it == _database.begin()) {
        // No earlier date exists
        throw std::runtime_error("Error: no earlier date available in database for " + dateStr);
    }

    // Move to the closest earlier date
    --it;
    return it->second;
}

//debug
void btcExchange::printMap() const
{
	for (std::map<std::string, float>::const_iterator it = _database.begin(); it != _database.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}