#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"
#include <iostream>
#include <new>
#include "./Factory.hpp"


Base	*FA(void) {
	return  (new A());
}

Base	*FB(void) {
	return  (new B());
}
Base	*FC(void) {
	return  (new C());
}
Base	*generate(void) {
	int	Id;
	Base	*obj;
	Base *(*objFactories[3])(void) = {FA, FB, FC};

	Id = rand() % 3;
	obj = objFactories[Id]();

	return (obj);
}

void	identify(Base *ptr) {

	if (ptr == NULL)
		throw (std::runtime_error("Given Base ptr is NULL !\n"));

	A	*a = dynamic_cast<A*>(ptr);
	if (a == NULL) {
		B *b = dynamic_cast<B*>(ptr);
		if (b == NULL) {
			C *c = dynamic_cast<C*>(ptr);
			if (c == NULL)
				throw  std::runtime_error("Object type not found\n");
			else {
				std::cout << "Successfully casted (PTR) to : C --> " << c << std::endl;;
				return ;
			}
		}
		else {
			std::cout << "Successfully casted (PTR) to : B --> " << b << std::endl;;
			return ;
		}
	}
	std::cout << "Successfully casted (PTR) to : A --> " << a << std::endl;
}



void	identify(Base &ptr) {
	try {
		A	&a = dynamic_cast<A&>(ptr);
				std::cout << "Successfully casted (REF) to: A --> " << &a << std::endl;
	}
	catch (std::exception &eA) {
		try {
			B	&b = dynamic_cast<B&>(ptr);
				std::cout << "Successfully casted (REF) to: B --> " << &b << std::endl;
		}
		catch (std::exception &eB) {
			try {
				C	&c = dynamic_cast<C&>(ptr);
				std::cout << "Successfully casted (REF) to: C --> " << &c << std::endl;
			}
			catch (std::exception &e) {
				throw (std::runtime_error("Given reference doesn't match any know types\n"));
			}
		}
	}
}

