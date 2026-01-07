#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <cinttypes>

typedef struct Data_s {
	int key;
	int value;
}	Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif  /* SERIALIZER_HPP */
