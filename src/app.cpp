/* File realisation of class application
   filename - app.cpp */

#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "app.hpp"

App::App(int argc, char **argv){
	ops_desc.add_options()
		("help,h", "Show help")
		("version,v", "Show version of application")
		("sum,s", "Summing arguments")
		("multiply,m", "Multiplication of argument")
		("args", po::value< std::vector<std::string> >(), "Arguments")
	;
	pos_desc.add("args", -1);
	po::store(po::command_line_parser(argc, argv).options(ops_desc).positional(pos_desc).run(), op_store);
	po::notify(op_store);
}

void App::exec() {//const{
try{
	if (op_store.count("help")){
		std::cout << "Help on application:" << std::endl;
		std::cout << ops_desc << std::endl;
	}
	if (op_store.count("args")){
		using boost::lexical_cast;
		using boost::bad_lexical_cast;
		auto it = op_store["args"].as<std::vector<std::string>>().begin();
		//std::cout << "Args for summing: ";
		while(it != op_store["args"].as<std::vector<std::string>>().end()){
			args.push_back(lexical_cast<double>(*it++));
			//std::cout << lexical_cast<double>(*it++) << " ";
		}
		std::cout << std::endl;
		//std::cout << "Args for summing: " << op_store["args"].as< std::vector<std::string> >()[0];
		//std::cout << ", " << op_store["args"].as<std::vector<std::string> >()[1] << std::endl;
	}
	else {
		std::cout << "Few parametrs" << std::endl;
		exit(1);
	}
	conflicting_option("multiply", "sum");
}
catch (std::exception &e){
	std::cerr << e.what() << std::endl;
	exit(1);
}
}

// Функция предназначена для определения конфликтующих опций
void App::conflicting_option(const char *opt1, const char *opt2){
	if (op_store.count(opt1) && op_store.count(opt2)) {
		throw std::logic_error(std::string("Conflicting option"));
	}
}

App::type_op App::getTypeOp(){
	if(op_store.count("multiply"))
		return multiply;
	return sum;
}

