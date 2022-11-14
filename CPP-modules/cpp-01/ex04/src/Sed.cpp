#include "../include/Sed.hpp"

Sed::Sed(std::string filename) :
	_inputFile(filename), _outputFile(filename + ".replace")
{
}

Sed::~Sed()
{
}

void	Sed::replace(std::string s1, std::string s2)
{
	std::ifstream input(_inputFile);
	if (input.is_open())
	{
		std::string	str;
		if (std::getline(input, str, '\0'))
		{
			input.close();
			size_t pos = str.find(s1);
			while (pos != std::string::npos)
			{
				str.erase(pos, s1.length());
				str.insert(pos, s2);
				pos = str.find(s1);
			}
			std::ofstream output(_outputFile);
			if (!output.is_open())
			{
				std::cerr << "Error: could not open \"" << _outputFile << "\".\n";
				exit(EXIT_FAILURE);
			}
			output << str;
			output.close();
		}
	} else
	{
		std::cerr << "Error: could not open \"" << _inputFile << "\".\n";
		exit(EXIT_FAILURE);
	}
}
