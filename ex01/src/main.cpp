#include "Serializer.hpp"
#include "Data.h"
#include <string>
#include <iostream>
#include <stdint.h>
#include <cstddef>
#include <cstring>

int	main(void)
{
	Data*			player = new Data;
	uintptr_t		raw;
	Data*			restored;

	std::cout << "Enter player name: " << std::endl;
	std::cin >> player->name;
	std::cout << "Enter player level: " << std::endl;
	std::cin >> player->level;
	std::cout << "Enter player health: " << std::endl;
	std::cin >> player->health;
	std::cout << "The player's state is set. Serializing..." << std::endl;

	raw = Serializer::serialize(player);

	std::cout << "Raw uintptr_t value: " << raw << std::endl;
	std::cout << "Original pointer: " << player << std::endl;

	restored = Serializer::deserialize(raw);

	std::cout << "Deserialized  pointer: " << restored << std::endl;
	std::cout << "Player's state has been restored: " << std::endl;
	std::cout << "\tRestored name: " << restored->name << std::endl;
	std::cout << "\tRestored level: " << restored->level << std::endl;
	std::cout << "\tRestored health: " << restored->health << std::endl;
	std::cout << std::endl;
	delete player;
	return (0);
}
