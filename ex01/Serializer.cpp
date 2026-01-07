#include "./Serializer.hpp"


Serializer::Serializer(void) {
}

Serializer::~Serializer(void) {
}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t	value;

	value = reinterpret_cast<uintptr_t>(ptr);
	return (value);
}

Data	*Serializer::deserialize(uintptr_t	raw) {
	Data *ptr;

	ptr = reinterpret_cast<Data*>(raw);
	return (ptr);
}
