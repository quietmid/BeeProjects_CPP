#include <iostream>

int main(int argc, char **argv) {
	int i = 1;
	int j;

	if (argc < 2)
		std::cout << "HEY YOU! Ain't no body got time for that!";
	while (argv[i])
	{
		j = 0;
		while (argv[i][j]){
			std::cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	return (0);
};
