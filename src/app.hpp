/* Header file of class application
   filename - app.hpp              */

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class App {
public:
	App(){};
	App(int, char **);
	void exec() const;
private:
	po::options_description ops_desc; // Options description (Описание опций)
	po::positional_options_description pos_desc; // Positional options description
	po::variables_map op_store;		// Container for store received options
};

