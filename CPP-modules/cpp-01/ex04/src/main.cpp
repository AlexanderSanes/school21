#include <iostream>
#include "../include/Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments.\n";
		return 1;
	}
	Sed sd(argv[1]);
	sd.replace(argv[2], argv[3]);
	return 0;
}