#include "./ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>


Type	ScalarConverter::getType(const std::string &param) {
	size_t	dotCount = 0;

	for (size_t i = 0; i < param.length(); i += 1)
		if (param[i] == '.')
			dotCount += 1;
	if (dotCount > 1)
		return (INVALID_TYPE);
	for (size_t i = 0; i < param.length(); i += 1) {
		if (!isdigit(param[i])) {
			if (param[i] != '.') {
				if (param[i] != 'f')
					return (INVALID_TYPE);
				if (i !=  param.length() - 1 || !dotCount || !isdigit(param[i - 1])) {
					std::cout << i << " " << param[i] << std::endl;
					return (INVALID_TYPE);
				}
			}
			else if (i == param.length() - 1)
				return (INVALID_TYPE);
		}
	}
	if (dotCount == 1)
		return (DOUBLE);
	else
		return (INT);
	return (INVALID_TYPE);
}

void	ScalarConverter::printConvertedVar(double &var) {

		int value = var;
		if (isprint(value))
			std::cout << "char : " << static_cast<char>(value) << std::endl;
		else
			std::cout << "char : " << "Non displayable" << std::endl;
		std::cout << "int : " << value << std::endl;
		std::cout << "float : " << static_cast<float>(var) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(var) << ".0" << std::endl;

}

bool	ScalarConverter::isCustomType(const std::string &param) {
	if (param == "nan" || param == "nanf")
		return (true);
	if (param == "+inf" || param == "inf" || param == "-inf")
		return (true);
	if (param == "+inff" || param == "inff" || param == "-inff")
		return (true);
	return (false);
}

void	ScalarConverter::printConvertedCustomType(const std::string &param) {

	std::cout << "char : " << "impossible" << std::endl;
	std::cout << "int : " << "impossible" << std::endl;
	std::cout << "float : " << ((param[param.length() - 1] == 'f') ? param : param + "f");
	if (param != "nan" && param != "nanf" && param != "inff" && param != "+inff" && param != "-inff")
		std::cout << "f";
	std::cout << std::endl;
	if (param[param.length() - 1] != 'f')
		std::cout << "double : "  << param << std::endl;
	else {
		std::cout << "double : ";
		for (size_t i = 0; i < param.length() - 1; i += 1)
			std::cout << param[i];
	}
	if (param != "nan" && param != "nanf")
		std::cout << "f";
	std::cout << std::endl;

}

void	ScalarConverter::convert(const std::string &param) {
	Type type;

	type = getType(param);
	if (isCustomType(param)) {
		printConvertedCustomType(param);
		return ;
	}
	if (type == INVALID_TYPE) {
		std::cout << "Invalid argument given\n";
		throw InvalidArgException();
	}
	else if (type == CHAR) {
		double value = static_cast<double>(param[0]);
		printConvertedVar(value);
	}
	else {
		double value = atof(param.c_str());
		printConvertedVar(value);
	}

	return;
}

const char *InvalidArgException::what() const throw() {
	return ("Invalid argument was passed\n");
}
