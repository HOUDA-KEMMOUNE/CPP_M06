#include "convert.hpp"

Base	*generate(void)
{
	srand(time(NULL));
	int	r = rand();

	Base	*a  = new A;
	Base	*b  = new B;
	Base	*c  = new C;

	if (r % 2 == 0)
	{
		delete b;
		delete c;
		return (a);
	}
	else if (r % 3 == 0)
	{
		delete a;
		delete c;
		return (b);
	}
	else
	{
		delete a;
		delete b;
		return (c);
	}	
}

void	identify(Base* p)
{
	A	*a  = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "A\n";
		return ;
	}

	B	*b  = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "B\n";
		return ;
	}

	C	*c  = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "C\n";
		return ;
	}
}

void	identify(Base& p)
{
	try
	{
		A	&a  = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	
	try
	{
		B	&b  = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		C	&c  = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
}

