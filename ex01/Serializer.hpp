# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "data.h"
#include <iostream>
#include <string>
#include <string>
#include <stdint.h>

class	 Serializer
{
	private:
		Serializer( void );
		Serializer( const Serializer &old );
		Serializer	&operator=( const Serializer &old );
		~Serializer( void );

	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );

};

# endif
