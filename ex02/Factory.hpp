#ifndef FACTORY_HPP
# define FACTORY_HPP

#include "./Base.hpp"

Base	*FA(void);
Base	*FB(void);
Base	*FC(void);

Base	*generate(void);
void	identify(Base *ptr);
void	identify(Base &ptr);

#endif /* FACTORY_HPP */
