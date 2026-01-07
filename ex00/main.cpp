#include "./ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

void	testParsing(void) {
	/* Should Work ! */
	std::cout << "\n\n-------------Valid tests---------------\n";
		ScalarConverter::convert("0.0f");
		ScalarConverter::convert("0");
		ScalarConverter::convert("00");
	std::cout << "\n\n-------------Invalid tests---------------\n";
	/* Should Not Work ! */
		ScalarConverter::convert("0.");
		ScalarConverter::convert("0f");
		ScalarConverter::convert("0..f");
		ScalarConverter::convert("0.ff");
		ScalarConverter::convert("0.f");
}

int	testGivenArgs(int ac, char **av) {
	if (ac == 1) {
		std:: cout << "No argument was given\n";
		return (0);
	}
	for (int i = 1; i < ac; i += 1) {
		std::cout << "\n--------------------\n";
		try {
		ScalarConverter::convert(av[i]);
		}
		catch (std::exception &e) {
			std::cout << "Oops catched something: " << e.what() << std::endl;
		}
		std::cout << "--------------------\n";
	}
	return (0);
}

int main(int ac, char **av) {
	// testParsing();
	testGivenArgs(ac, av);
	return (0);
}
