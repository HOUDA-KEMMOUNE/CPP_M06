#include "Serializer.hpp"

int	main()
{
	Data	simple_data;

	simple_data.c = 'a';
	// std::cout << "test\n";
	simple_data.n = 2;
	Data	*ptr = &simple_data;

	uintptr_t	ser = Serializer::serialize(ptr);
	Data		*ptr2 = Serializer::deserialize(ser);

	std::cout << "ptr -> " << ptr << std::endl;
	std::cout << "ptr->c: " << ptr->c <<  " ptr->n: " << ptr->n << std::endl;
	std::cout << "\n---------------------------------------------------\n";

	std::cout << "Serialization: " << ser << std::endl;
	// std::cout << "ptr->c " << ptr->c <<  " ptr->n " << ptr->n << std::endl;
	std::cout << "\n---------------------------------------------------\n";

	std::cout << "Deserialization: " << ptr2 << std::endl;
	std::cout << "ptr2->c: " << ptr2->c <<  " ptr2->n: " << ptr2->n << std::endl;
	std::cout << "\n---------------------------------------------------\n";

}