void run(std::vector<std::string>& program) {
	std::stack<bool> stack = {}; 
	bool a = 0; bool b = 0; 
	bool jmp = false; 
	for(int i = 0; i < program.size(); i++) {
		std::string str = program[i]; 
		if(jmp) {
			i = std::stoi(str); 
			str = program[i]; 
			jmp = false; 
		}
		if(str == "pop") {
			if(stack.size() > 0) {
				a = stack.top(); 
				stack.pop();
				continue; 
			}
			std::cout << "\nERROR: No items in stack\n"; 
			return; 
		}
		if(str == "psh") {
			stack.push(a); 
			continue; 
		}
		if(str == "swp") {
			bool a_temp = a; 
			a = b; 
			b = a_temp; 
			continue; 
		}
		if(str == "out") {
			std::cout << a; 
			continue; 
		}
		if(str == "inp") {
			char a_char; 
			std::cin >> a_char; 
			a = a_char - 48; 
			continue; 
		}
		if(str == "jmp") {
			if(a) {
				jmp = true; 
			}
			continue; 
		}
		if(str == "1") {
			stack.push(1); 
			continue; 
		}
		if(str == "0") {
			stack.push(0); 
		}
	}
}
