#include <iostream>

int	main()
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*ps = &s;
	std::string	&rs = s;

	std::cout << "The memory address of the string:\t\t" << &s << std::endl;
	std::cout << "The memory address held by the pointer:\t\t" << ps << std::endl;
	std::cout << "The memory address held by the reference:\t" << &rs << std::endl;

	std::cout << "The value of the string:\t\t" << s << std::endl;
	std::cout << "The value pointed to by the pointer:\t" << *ps << std::endl;
	std::cout << "The value pointed to by the reference:\t" << rs << std::endl;

}