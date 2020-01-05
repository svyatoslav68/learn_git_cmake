/* File realisation of class application
   filename - app.cpp */

#include <iostream>
#include <vector>
#include <string>
#include "app.hpp"

App::App(int argc, char **argv){
	ops_desc.add_options()
		("help,h", "Show help")
		("version,v", "Show version of application")
		("args", po::value< std::vector<std::string> >(), "Arguments")
	;
	pos_desc.add("args", -1);
	po::store(po::command_line_parser(argc, argv).options(ops_desc).positional(pos_desc).run(), op_store);
	po::notify(op_store);
}

void App::exec() const{
	if (op_store.count("help")){
		std::cout << "Help on application:" << std::endl;
		std::cout << ops_desc << std::endl;
	}
	if (op_store.count("args")){
		std::cout << "Args for summing: " << op_store["args"].as< std::vector<std::string> >()[0] << std::endl;
	}
}

