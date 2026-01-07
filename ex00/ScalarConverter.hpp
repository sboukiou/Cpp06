#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID_TYPE
};

class ScalarConverter {
	private:
		Type type;
		ScalarConverter(void);
		~ScalarConverter(void);
		static Type	getType(const std::string &type);
		static void		printConvertedVar(double &var); /* Using the double type cause it can include all
													  the other types (char/int/float ..) */
		static void		printConvertedCustomType(const std::string &param);
		static bool		isCustomType(const std::string &param);
	public:
		static void	convert(const std::string &param);
};

class InvalidArgException: public std::exception {
	public:
		const char *what() const throw();
};

#endif /* SCALAR_CONVERTER_HPP */
