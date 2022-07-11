std::vector<std::string> preprocessor(std::vector<std::string>& program) {
	std::unordered_map<std::string, std::vector<std::string>> macros{};
	std::unordered_map<std::string, unsigned int> labels{}; 
	std::vector<std::string> macro_names = {};
	std::string macro; 
	for(int i = 0; i < program.size(); i++) {
		std::string str = program[i]; 
		if(str[0] == ':') { // Macros
			macro_names.push_back(str.substr(1)); 
			macro = macro_names.back(); 
			continue; 
		}
		macros[macro].push_back(str);
	}
	for(std::string name : macro_names) {
		std::vector<std::string> temp_program = {};
		for(int i = 0; i < macros[name].size(); i++) {
			std::string str = macros[name][i]; 
			// logic
			if(str[0] == '@') { // Macros
				for(std::string macro_code : macros[str.substr(1)]) {
					temp_program.push_back(macro_code); 
				}
				continue; 
			}
			temp_program.push_back(str); 
		}
		macros[name] = temp_program; 
	}
	// Labels
	std::vector<std::string> final_program = {}; 
	int label_num = 0; 
	for(int i = 0; i < macros["main"].size(); i++) {
		std::string str = macros["main"][i]; 
		if(str[0] == '.') { 
			labels[str.substr(1)] = i - label_num; 
			label_num++; 
			continue; 
		}
		final_program.push_back(str); 
	}
	macros["main"] = final_program; 
	final_program = {}; 
	for(std::string str : macros["main"]) {
		if(str[0] == '&') {
			final_program.push_back(std::to_string(labels[str.substr(1)])); 
			continue; 
		}
		final_program.push_back(str); 
	}
	return final_program; 
	// print_map(macros);
}
