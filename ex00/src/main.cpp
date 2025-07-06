#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

std::string	makeLower(std::string input)
{
	typedef std::string::iterator Iterator;

	for (Iterator it = input.begin(); it != input.end(); ++it) {
		*it = static_cast<char>(std::tolower(*it));	
	}
	return (input);
}

int	main(void)
{
	std::string input;

	std::cout << "Enter a scalar value to convert (or the quit command): " << std::endl;
	while (std::cin >> input)
	{
		if (makeLower(input) == "quit" )
			break ;
		ScalarConverter::convert(input);
		std::cout << "Enter a scalar value to convert (or the quit command): " << std::endl;
	}
	return (0);
}
