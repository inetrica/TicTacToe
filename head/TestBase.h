#ifndef TESTBASE_H
#define TESTBASE_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#define BLOCK_PIXEL_SZ 70

/*
 * custom assert
 */
int 
assert(std::string testName, bool condition){
	std::cout << "###############\n" << testName
		<< "\n###############" << std::endl;
	if(condition){
		std::cout << "Passed!" << std::endl;
	} else {
		std::cout << "Failed~" << std::endl;
	}

	std::cout << "______________________________________________\n" 
		<< std::endl;

	return 0;
}
#endif
