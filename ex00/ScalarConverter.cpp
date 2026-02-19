#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){}

ScalarConverter::ScalarConverter( const ScalarConverter &old )
{
	(void)old;
}

ScalarConverter	&ScalarConverter::operator=( const ScalarConverter &old )
{
	(void)old;
	return (*this);
}

int	check_char( std::string &data )
{
	int	len = data.length();

	if (len == 1)
	{
		if (data[0] >= 'a' && data[0] <= 'z')
		{
			std::cout << "Invalid input ✅\n";
			return (1);
		}
	}
	// std::cout << "Invalid input ❌\n";
	return (0);

}

int	check_int( std::string &data )
{
	int	len = data.length();
	int	i = 0;

	while (i < len)
	{
		if (!isdigit(static_cast<int>(data[i])))
		{
			// std::cout << "Invalid input ❌\n";
			return (0);
		}
		i++;
	}
	std::cout << "Invalid input ✅\n";
	return (1);
}

int	check_float( std::string &data )
{
	int	len = data.length();
	int	i = 0;
	int	flag = 0;

	while (i < len)
	{
		if (!isdigit(static_cast<int>(data[i])))
		{
			// std::cout << "Invalid input ❌\n";

			return (0);
		}
		i++;
	}
	std::cout << "Invalid input ✅\n";
	return (1);
}

void	parser( std::string &data )
{
	if (check_char(data))
	{
		std::cout <<  "1\n";
		return ;
	}

	if (check_int(data))
	{
		std::cout <<  "2\n";
		return ;
	}
	
}

void	ScalarConverter::convert( std::string literal )
{
	parser(literal);

	

}

ScalarConverter::~ScalarConverter( void ){}
