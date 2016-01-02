#ifndef TESTBASE_H
#define TESTBASE_H

#include <iostream>
#include <string>

/*
 * custom assert
 */
int 
assert(std::string testName, bool condition){
	std::cout << "###############" << testName
		<< "###############" << std::endl;
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
