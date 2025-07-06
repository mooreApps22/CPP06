#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>

// Type Enumeration

enum Type {
	CHAR, INT, FLOAT, DOUBLE, UNKNOWN
};

// Static Parser Utils

static bool isCharValue(const std::string& input) {
	return (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]));
}

static bool isSpecialFloatValue(const std::string& input) {
	return (input == "-inff" || input == "+inff" || input == "nanf");
}

static bool isSpecialDoubleValue(const std::string& input) {
	return (input == "-inf" || input == "+inf" || input == "nan");
}

static Type	parser(const std::string& input) {
	if (isCharValue(input))	
		return (CHAR);
	if (isSpecialFloatValue(input))	
		return (FLOAT);
	if (isSpecialDoubleValue(input))	
		return (DOUBLE);

	std::istringstream	intStream(input);
	int intValue;

	if ((intStream >> intValue) && intStream.eof())
		return (INT);

	if (input.length() > 1 && input[input.length() - 1] == 'f') {
		std::string			floatPart = input.substr(0, input.length() - 1);
		std::istringstream	floatStream(floatPart);
		float floatValue;

		if ((floatStream >> floatValue) && floatStream.eof())
			return (FLOAT);
	}

	std::istringstream	doubleStream(input);
	double doubleValue;
	
	if ((doubleStream >> doubleValue) && doubleStream.eof())
		return (DOUBLE);
	return (UNKNOWN);
}

//Static Displayer Utils

static void printChar(double doubleValue) {
	if (std::isnan(doubleValue) || doubleValue < 0 || doubleValue > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(doubleValue)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(doubleValue) << std::endl;
}

static void printInt(double doubleValue) { 
	const int intMin = std::numeric_limits<int>::min();
	const int intMax = std::numeric_limits<int>::max();

	if (std::isnan(doubleValue) || doubleValue < intMin || doubleValue > intMax)	
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
}

static void printFloat(double doubleValue) { 
	float floatValue = static_cast<float>(doubleValue);	

	std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
}

static void printDouble(double doubleValue) { 
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
}

static void displayer(double output)
{
	printChar(output);
	printInt(output);
	printFloat(output);
	printDouble(output);
}

void	ScalarConverter::convert(const std::string& input) {
	Type type = parser(input);
	double output;

	try {
		switch (type) {
			case CHAR:
				output = static_cast<double>(input[0]);
				break ;
			case INT: {
				std::istringstream	stream(input);
				int	intValue;
				
				if ((stream >> intValue) && stream.eof())
					output = static_cast<double>(intValue);
				else
					throw std::runtime_error("Invalid int input");
				break ;
			}
			case FLOAT: {
				if (input == "nanf")
					output = std::numeric_limits<float>::quiet_NaN();
				else if (input == "+inff")
					output = std::numeric_limits<float>::infinity();
				else if (input == "-inff")
					output = -std::numeric_limits<float>::infinity();
				else
				{
					std::string			floatStr = input;
					if (floatStr[floatStr.length() - 1] == 'f')
						floatStr = floatStr.substr(0, floatStr.length() - 1);

					std::istringstream	stream(floatStr);
					float				floatValue;

					if ((stream >> floatValue) && stream.eof())
						output = static_cast<double>(floatValue);
					else
						throw std::runtime_error("Invalid float input");
				}
				break ;
			}
			case DOUBLE: {
				if (input == "nan")
					output = std::numeric_limits<float>::quiet_NaN();
				else if (input == "+inf")
					output = std::numeric_limits<float>::infinity();
				else if (input == "-inf")
					output = -std::numeric_limits<float>::infinity();
				else
				{
					std::istringstream	stream(input);
					double				doubleValue;

					if ((stream >> doubleValue) && stream.eof())
						output = doubleValue;
					else
						throw std::runtime_error("Invalid double input");
				}
				break ;	
			}
			default:
				std::cerr << "Some crazy shit happened" << std::endl;
				return ;
		}
	}
	catch (...) {
		std::cerr << "EXCEPTION CAUGHT: conversion failed" << std::endl;
		return ;
	}

	displayer(output);
}
