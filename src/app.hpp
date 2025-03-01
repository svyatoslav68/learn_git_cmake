/* Header file of class application
   filename - app.hpp              */

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class App {
public:
	enum type_op{sum, multiply} ;
	App(){};
	App(int, char **);
	void exec() ;//const;
	const std::vector<double> &getArgs() const{return args;}
	type_op getTypeOp();
private:
	po::options_description ops_desc; // Options description (Описание опций)
	po::positional_options_description pos_desc; // Positional options description
	po::variables_map op_store;		// Container for store received options
	std::vector<double> args;
	void conflicting_option(const char *opt1,
			const char *opt2);
};

