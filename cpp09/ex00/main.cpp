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
	btc.getValue(argv[1]);
	//calculate rates
	return 0;
}