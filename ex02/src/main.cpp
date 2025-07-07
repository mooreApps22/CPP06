#include <string>
#include <iostream>
#include "Classes.hpp"
#include <stdlib.h> 
#include <ctime> 

Base*	generate(void)
{
	int random = rand() % 3;

	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try 
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			
		}
		catch (...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;	
			}
			catch (...)
			{
				std::cerr << "What class is this??" << std::endl;
			}
		}
	}
}


int	main(void)
{
	std::srand(std::time(NULL));
	Base* base = generate();
	std::cout << "Indentify by pointer: ";
	identify(base);
	std::cout << "Indentify by reference: ";
	identify(*base);
	return (0);
}
