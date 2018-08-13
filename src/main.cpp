#include <iostream>
#include <string>
#include <stdint.h>
#include "../include/main.hpp"
#include "../include/models/word.hpp"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "You must supply a source word" << std::endl;
		return 1;
	}
	std::string source = argv[1];
	Word* word = new Word(source);
	if (argc > 2) {
		uint8_t max_distance = std::atoi(argv[2]);
		word->setMaxDistance(max_distance);
	}
	std::string target;
	while (std::cin >> target) {
		bool match = word->matchAgainst(new Word(target));
		if (match) {
			std::cout << target << std::endl;
		}
	}
	return 0;
}
