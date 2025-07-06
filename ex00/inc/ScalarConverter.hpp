#pragma once
# include <iostream>

class ScalarConverter
{
	public:
		static void	convert(const std::string& input);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
};
