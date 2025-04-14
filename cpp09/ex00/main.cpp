#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	//check input
	if (argc != 2)
	{
		std::cerr << "Error: Too many or too little arguments" << std::endl;
		return 1;
	}
	// (void)argv;
	//initialize btcExchange
	btcExchange btc;
		//load database
	try {
		//calculate rates
		btc.getValue(argv[1]);
	} catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
		
	return 0;
}