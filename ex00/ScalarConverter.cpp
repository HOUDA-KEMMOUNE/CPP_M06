#include "ScalarConverter.hpp"
#include "enum.hpp"

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

int	check_char( std::string &data, type *t )
{
	int	len = data.length();

	if (len == 1)
	{
		if (data[0] >= 'a' && data[0] <= 'z')
		{
			*t = CHAR;
			return (1);
		}
	}
	return (0);
}

int	check_int( std::string &data, type *t )
{
	int	len = data.length();
	int	i = 0;

	while (i < len)
	{
		if (i == 0 && (data[i] == '-' || data[i] == '+'))
		{
			i++;
			continue;
		}
		if (!isdigit(static_cast<int>(data[i])))
			return (0);
		i++;
	}
	// std::cout << "int -> valid input ✅\n";
	*t = INT;
	return (1);
}

int	check_float( std::string &data, type *t )
{
	int	len = data.length();
	int	i = 0;
	int	flag = 0;

	while (i < len)
	{
		if (i == 0 && (data[i] == '-' || data[i] == '+'))
		{
			i++;
			continue;
		}
		if (!isdigit(static_cast<int>(data[i])))
		{
			if (i + 1 == len && data[i] == 'f')
			{
				// std::cout << "float -> valid input ✅\n";
				*t = FLOAT;
				return (1);
			}
			if (data[i] == '.' && data[i + 1] != 'f' && flag == 0)
				flag++;
			else
				return (0);
		}
		if (i + 1 == len && data[i] != 'f')
			return (0);
		i++;
	}
	*t = FLOAT;
	return (1);
}

int	check_double( std::string &data, type *t )
{
	int	len = data.length();
	int	i = 0;
	int	flag = 0;

	while (i < len)
	{
		if (i == 0 && (data[i] == '-' || data[i] == '+'))
		{
			i++;
			continue;
		}
		if (!isdigit(static_cast<int>(data[i])))
		{
			if (data[i] == '.' && data[i + 1] != '\0' && flag == 0)
				flag++;
			else
				return (0);
		}
		i++;
	}
	*t = DOUBLE;

	return (1);
}

int	check_others( std::string &data, type *t )
{
	if (data == "nan" || data == "nanf" || data == "-inff"
		|| data == "+inff" || data == "-inf" || data == "+inf")
	{
		*t = OTHERS;
		return (1);
	}
	else
		return (0);
}

int	parser( std::string &data, type *t )
{

	if (data.empty())
	{
		std::cerr << "Empty string :/\n";
		return (0);
	}

	if (check_char(data, t))
		return (1) ;

	if (check_int(data, t))
		return (1) ;
	
	if (check_float(data, t))
		return (1) ;

	if (check_double(data, t))
		return (1) ;

	if (check_others(data, t))
		return (1) ;
	
	std::cerr << "Invalid input :/\n";
	return (0);
}

void	cast_char( double d )
{
	if (d < CHAR_MIN || d > CHAR_MAX)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	char	c = static_cast<char>(d);
	if (std::isprint(c))	
			std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable\n";
}

void	cast_int( double d )
{
	if (d < INT_MIN || d > INT_MAX)
	{
		std::cout << "int: impossible\n";
		return ;
	}
	int		i = static_cast<int>(d);
	std::cout << "int: " << i << std::endl;
}

void	int_part( double d )
{
	cast_char(d);

	cast_int(d);

	float	f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;

	double	db = static_cast<double>(d);
	if (std::isinf(f))
	{
		std::cout << std::scientific << std::setprecision(1);
		std::cout << "double: " << db << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << db << std::endl;
	}
}

void	float_double_part( double d )
{
	cast_char(d);

	if (std::isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "int: impossible\n";
	else
	{
		int		i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	
	float	f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "float: " << f << "f" << std::endl;

	double	db = static_cast<double>(d);
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "double: " << db << std::endl;
}

void	others_part( double d )
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";

	float	f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;

	double	db = static_cast<double>(d);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << db << std::endl;
}

void	cast( double d, type t )
{
	if (t == INT)
		int_part(d);
	else if (t == FLOAT || t == DOUBLE)
		float_double_part(d);
	else if (t == OTHERS)
		others_part(d);
	return ;
}

void	char_case( std::string literal )
{
	char	c = literal[0];
	
	std::cout << "char: " << c << std::endl;
	
	int		i = static_cast<int>(c);
	std::cout << "int: "  << i << std::endl;
	
	float	f = static_cast<float>(c);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";

	double	d = static_cast<double>(c);
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convert( std::string literal )
{
	type	t;
	if (!parser(literal, &t))
		return ;

	char	**end  = NULL;
	if (t == 0)
		char_case(literal);
	else
	{
		double	d = strtod(literal.c_str(), end);
		if (end == NULL)
			cast(d, t);
	}
}

ScalarConverter::~ScalarConverter( void ){}
