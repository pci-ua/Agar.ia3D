#include <fstream>
#include <iostream>
#include <string>
#include <map>

namespace config {

	std::map<std::string,std::string> data;

	void readFromFile(std::string path) {
		std::ifstream configFile;
		configFile.open(path);
		if( configFile.is_open() ) {
			std::string line;
			while( std::getline( configFile, line ) ) {
				if(line.length() > 0 && line[0] != '#') {
					auto pos = line.find('=');
					if( 
						pos == std::string::npos
						||
						pos == 0
					) {
						std::cerr << "Invalid configuration line in config file : " << std::endl << "\t" << line << std::endl;
					} else {
						std::string key = line.substr(0,pos);
						std::string value = line.substr(pos+1,std::string::npos);
						data.insert_or_assign(key,value);
					}
				}
			}
		} else {
			std::cerr << "Unable to open config file (" << path << ")" << std::endl;
		}
	}

	std::string get(std::string key) {
		try {
			return data.at(key);
		} catch(std::out_of_range & e) {
			return "";
		}
	}

};