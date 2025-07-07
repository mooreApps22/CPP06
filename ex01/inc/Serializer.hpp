#pragma once
# include <iostream>
# include "Data.h" 
# include <stdint.h>
# include <cstddef>
# include <cstring>

class Serializer
{
	public:
			static uintptr_t	serialize(Data* ptr);
			static Data*		deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
};
