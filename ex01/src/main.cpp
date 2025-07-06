#include "ScalarConverter.hpp"
#include "Data.h"
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

// take in the data for the Data struct and then pass into serialize
/*
	Data* player
	...
	raw = serialize(player)
	restored = deserialize(raw);
	...
*/
int	main(void)
{
	std::string input;

	std::cout << "Enter: " << std::endl;
	while (std::cin >> input)
	{
		if (makeLower(input) == "quit" )
			break ;
		std::cout << "Enter: " << std::endl;
	}
	return (0);
}
