#include "Serializer.hpp"
#include "Data.h"

int	main()
{
	Data		*data = new Data;
	Data		*res;
	uintptr_t	ptr;

	data->var = 58;
	data->text = "test";

	std::cout << "initial data info:" << std::endl << "var: " << data->var << std::endl << "text: " << data->text << std::endl << std::endl;

	ptr = Serializer::serialize(data);
	res = Serializer::deserialize(ptr);

	std::cout << "initial pointer: " << data << std::endl << "serialized pointer: " << ptr << std::endl << "deserialized pointer: " << res << std::endl << std::endl;
	std::cout << "deserialized data info:" << std::endl << "var: " << res->var << std::endl << "text: " << res->text << std::endl;

	delete res;

	return (0);
}