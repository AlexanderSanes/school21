#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
private:
    std::string _inputFile;
    std::string _outputFile;

public:
    Sed(std::string filename);
    ~Sed();

	void	replace(std::string s1, std::string s2);
};

#endif