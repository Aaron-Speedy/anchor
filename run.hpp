void run(std::vector<std::string>& program) {
	std::vector<bool> stack = {}; 
	bool a = 0; bool b = 0; unsigned int c = 0; 
	for(int i = 0; i < program.size(); i++) {
		std::string str = program[i]; 
		if(str == "pop") {
			if(stack.size() > 0) {
				a = stack.back(); 
				stack.pop_back();
				continue; 
			}
			std::cout << "\nERROR: No items in stack\n"; 
			return; 
		}
		if(str == "psh") {
			stack.push_back(a); 
			continue; 
		}
		if(str == "swp") {
			bool a_temp = a; 
			a = b; 
			b = a_temp; 
			continue; 
		}
		if(str == "inp") {
			char a_char; 
			std::cin >> a_char; 
			a = a_char - 48; 		
			continue; 
		}
		if(str == "out") {
			std::cout << a; 
			continue;
		}
		if(str == "con") {
			if(!a) {
				if(c != 0) {
					c--;
				}
				continue; 
			}
			c++; continue;  
		}
		if(str == "1") {
			stack.push_back(1); 
			continue; 
		}
		if(str == "0") {
			stack.push_back(0); 
			continue; 
		}
		if(str.size() > 4 && split(str, "-")[0] == "jmp") {
			if(c == 0) {
				std::vector<std::string> split_jmp = split(str, "-"); 
				if(split_jmp[1] == "#") {
					i = c - 1; continue;
				}
				i = std::stoi(split_jmp[1]) - 1; continue;
			}
			continue; 
		}
	}
}
