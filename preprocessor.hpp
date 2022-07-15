class Macro {
	public: 
	std::vector<std::string> code; 
	std::unordered_map<std::string, std::string> params = {}; 
	std::unordered_map<std::string, unsigned int> labels{}; 
	std::vector<std::string> param_names = {}; 
}; 
void expand_macros(std::unordered_map<std::string, Macro>& macros, std::string name) {
	std::vector<std::string> program = {}; 
	int num_params = 0; bool in_macro = false; 
	std::string macro_name = ""; 
	for(std::string str : macros[name].code) {
		if(str[0] == '@') {
			in_macro = true; 
			macro_name = str.substr(1); 
			if(num_params != macros[name].param_names.size()) {
				continue;
			}
		}
		if(str[0] == '!') {
			std::cout << macros[name].param_names[num_params] << std::endl; 
			macros[macro_name].params[macros[name].param_names[num_params]] = str.substr(1); 
			num_params++; 
			if(num_params != macros[name].param_names.size()) {
				continue;
			}
		}
		if(num_params == macros[name].param_names.size() && in_macro) {
			expand_macros(macros, macro_name); 
			for(std::string code : macros[macro_name].code) {
				if(code[0] == ';') {
					program.push_back(macros[macro_name].params[code.substr(1)]);
					continue;
				}
				program.push_back(code);
			}
			in_macro = false; 
			num_params = 0; 
			continue; 
		}
		program.push_back(str); 
	}
	macros[name].code = program;
}
std::vector<std::string> preprocessor(std::vector<std::string>& program) {
	std::unordered_map<std::string, Macro> macros{};
	std::unordered_map<std::string, unsigned int> labels{}; 
	std::string macro; 
	for(int i = 0; i < program.size(); i++) {
		std::string str = program[i]; 
		if(str[0] == ':') { // Macros
			macro = str.substr(1); 
			continue; 
		}
		if(str[0] == '?') {
			macros[macro].params[str.substr(1)] = ""; 
			macros[macro].param_names.push_back(str.substr(1)); 
			std::cout << macros[macro].param_names.back() << " "; 
			continue; 
		}
		macros[macro].code.push_back(str);
	}
	// Expand Macros
	// expand_macros(macros, "main");
	// Labels
	std::vector<std::string> final_program = {}; 
	int label_num = 0; 
	for(int i = 0; i < macros["main"].code.size(); i++) {
		std::string str = macros["main"].code[i]; 
		if(str[0] == '.') { 
			labels[str.substr(1)] = i - label_num; 
			label_num++; 
			continue; 
		}
		final_program.push_back(str); 
	}
	macros["main"].code = final_program;
	final_program = {}; 
	for(std::string str : macros["main"].code) {
		if(str[0] == '&') {
			final_program.push_back(std::to_string(labels[str.substr(1)])); 
			continue; 
		}
		final_program.push_back(str); 
	}
	return final_program; 
	// print_map(macros);
}
