/* This header file consist second functions 
   for project 
   Name file - algostuff.hpp */
#ifndef ALGOSTUFF_HPP
#define ALGOSTUFF_HPP

//#include <iostream>
template <typename T>
inline void PRINT_ELEMENTS(const T &collection, const std::string &optstr="") {
	std::cout << optstr; //Print header (default "")
	for (auto elem : collection){
		std::cout <<elem << ' ';
	}
	std::cout << std::endl;
}

template <typename T>
inline std::string JOIN_ELEMENTS(const T & collection) {
	std::ostringstream os;
	for (auto elem : collection){
		os << elem << " ";
	}
	return os.str();
}


#endif // ALGOSTUFF_HPP
