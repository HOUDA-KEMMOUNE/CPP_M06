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
			std::cout << "char -> valid input ✅\n";
			return (1);
		}
	}
	std::cout << "Invalid input (Not a char) ❌\n";
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
			std::cout << "Invalid input (not an int) ❌\n";
			return (0);
		}
		i++;
	}
	std::cout << "int -> valid input ✅\n";
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
			if (i + 1 == len && data[i] == 'f')
			{
				std::cout << "float -> valid input ✅\n";
				return (1);
			}
			if (data[i] == '.' && flag == 0)
				flag++;
			else
			{
				std::cout << "Invalid input (Not a float) ❌\n";
				return (0);
			}
		}
		if (i + 1 == len && data[i] != 'f')
		{
			std::cout << "Invalid input (Not a float) ❌\n";
			return (0);
		}
		i++;
	}
	std::cout << "float -> valid input ✅\n";
	return (1);
}

int	check_double( std::string &data )
{
	int	len = data.length();
	int	i = 0;
	int	flag = 0;

	while (i < len)
	{
		if (!isdigit(static_cast<int>(data[i])))
		{
			if (data[i] == '.' && flag == 0)
				flag++;
			else
			{
				std::cout << "Invalid input (Not a double) ❌\n";
				return (0);
			}
		}
		i++;
	}
	std::cout << "double -> valid input ✅\n";
	return (1);
}

void	parser( std::string &data )
{

	if (check_char(data))
		return ;

	if (check_int(data))
		return ;
	
	if (check_float(data))
		return ;

	if (check_double(data))
		return ;
}

void	ScalarConverter::convert( std::string literal )
{
	parser(literal);
}

ScalarConverter::~ScalarConverter( void ){}
