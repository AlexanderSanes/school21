#include "../include/Harl.hpp"

int main()
{
	Harl	harl;

	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("something else");
	return 0;
}
