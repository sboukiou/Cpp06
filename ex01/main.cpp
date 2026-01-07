#include "./Serializer.hpp"
#include <iostream>


int main(void) {
	Data rand = {12, 23};
	uintptr_t	raw_rand;
	Data *new_rand_ptr;

	raw_rand = Serializer::serialize(&rand);
	std::cout << "raw address: " << raw_rand << std::endl;
	new_rand_ptr = Serializer::deserialize(raw_rand);
	std::cout << "new rand address: " << new_rand_ptr << std::endl;
	std::cout << "key : " << new_rand_ptr->key << std::endl;
	std::cout << "value : " << new_rand_ptr->value << std::endl;

	return (0);
}
