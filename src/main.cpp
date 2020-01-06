/* This is a main project source file.
This file included function main().*/
#include "app.hpp"
#include <functional>
#include <numeric>
#include <iostream>
#include "algostuff.hpp"

double sum(const double, const double);

int main(int argc, char **argv){
	//const double x = 1.2323;// = 1.345;
	//const double y = 23.1212;// = 10012.78762;
	double result;
	App app(argc, argv);
	app.exec();
	const std::vector<double> &args = app.getArgs();
	//result = sum(x,y);
	result = std::accumulate(args.cbegin(), args.cend(), 0.0, std::plus<double>());
	std::cout << "Сумма чисел " <<  "[ " << JOIN_ELEMENTS(args) << "] " << result << std::endl;
	return 0;
}
