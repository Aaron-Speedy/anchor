std::vector<std::string> split(const std::string& source, const std::string& delimiters) {
	std::size_t prev = 0;
	std::size_t currentPos = 0;
	std::vector<std::string> results; 
	while ((currentPos = source.find_first_of(delimiters, prev)) != std::string::npos) {
		if (currentPos > prev) {
			results.push_back(source.substr(prev, currentPos - prev));
		}
		prev = currentPos + 1;
	}
	if (prev < source.length()) {
		results.push_back(source.substr(prev));
	}
	return results;
}
void print_map(const auto& table) {
	for (auto const & [k, v] : table) {
		std::cout << k << " "; 
		for(std::string str : v) {
			std::cout << str << " ";
		}
		std::cout << std::endl; 
	}
}
