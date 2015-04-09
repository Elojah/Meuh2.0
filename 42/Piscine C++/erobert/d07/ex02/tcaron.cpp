#include <string>
#include <iostream>
#include "Array.hpp"

int main()
{
	Array<std::string>  string_array(2);
	Array<int>   int_array(5);
	Array<>      void_array;

	int_array[1] = 20;
	string_array[0] = "coucou";

	Array<std::string>  string_array_bis(string_array);

	std::cout << int_array[1] << std::endl;
	std::cout << int_array[4] << std::endl;
	std::cout << string_array[0] << std::endl;
	std::cout << string_array_bis[0] << std::endl;

	std::cout << "Modify string_array original" << std::endl;
	string_array_bis[0] = "coucou_encore";
	std::cout << string_array[0] << std::endl;
	std::cout << string_array_bis[0] << std::endl;

	std::cout << "Test equal --" << std::endl;
	Array<std::string>  string_array_bis2;

	string_array_bis2 = string_array_bis;
	std::cout << string_array_bis[0] << std::endl;
	std::cout << string_array_bis2[0] << std::endl;
	std::cout << "Modify string_array original" << std::endl;
	string_array_bis[0] = "coucou_encore_encore";
	std::cout << string_array_bis[0] << std::endl;
	std::cout << string_array_bis2[0] << std::endl;

	try {
		std::cout << void_array[0] << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
