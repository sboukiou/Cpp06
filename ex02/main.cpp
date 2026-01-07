#include "./Factory.hpp"
#include "./FalseA.hpp"
#include <iostream>



int main(void) {
	Base	*obj = generate();
	Base	*falseObj = new FalseA();
	if (obj == NULL)
		return (0);
	Base	&objRef = *falseObj;
	(void)objRef;
	try {
		identify(falseObj);
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		identify(objRef);
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
