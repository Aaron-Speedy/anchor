#include <iostream> 
#include <fstream>
#include <sstream> 
#include <string>
#include <vector>
#include <unordered_map>
#include "useful.hpp"
#include "preprocessor.hpp"
#include "run.hpp"
int main() {
	std::ifstream inFile;
	inFile.open("main.ancr"); 
	std::stringstream strStream;
	strStream << inFile.rdbuf(); 
	std::string program_string = strStream.str(); 
	std::vector<std::string> program = split(program_string, " \n\t");
	program = preprocessor(program);
	run(program);
	std::cout << std::endl;
}
