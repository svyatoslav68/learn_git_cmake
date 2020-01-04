/* This is a main project source file.
This file included function main().*/
#include <iostream>

double sum(const double, const double);

int main(int argc, char **argv){
	const double x = 1.345;
	const double y = 10012.78762;
	double result;
	result = sum(x,y);
	std::cout << "Сумма чисел " << x << " и " << y << " = " << result << std::endl;
	return 0;
}
