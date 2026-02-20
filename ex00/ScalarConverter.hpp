# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream> 
#include <string> 
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>

class	ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &old );
		ScalarConverter	&operator=( const ScalarConverter &old );
		~ScalarConverter( void );
	
	public:
		static void	convert( std::string literal );
};

# endif
