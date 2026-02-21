#include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::Serializer( const Serializer &old )
{
	(void)old;
}

Serializer	&Serializer::operator=( const Serializer &old )
{
	(void)old;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	dec =  reinterpret_cast<uintptr_t>(ptr);
	return (dec);
}

Data*	Serializer::deserialize( uintptr_t raw )
{
	Data*	ptr =  reinterpret_cast<Data*>(raw);
	return (ptr);
}

Serializer::~Serializer( void ) {}
