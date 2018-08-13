#include "../../include/models/word.hpp"

#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>

Word::Word(std::string word) {
	this->word = word;
};

Word::~Word() {
	
};

std::string Word::getWord() {
	return this->word;
};

uint8_t Word::levenshteinDistance(Word* word) {
	uint8_t cost;
	std::string source_word_str = this->getWord();
	std::string target_word_str = word->getWord();
	uint8_t source_word_len = source_word_str.length();
	uint8_t target_word_len = target_word_str.length();
	char source_word_chars[source_word_len];
	char target_word_chars[target_word_len];
	strcpy(source_word_chars,source_word_str.c_str());
	strcpy(target_word_chars,target_word_str.c_str());
	uint8_t d[source_word_len+1][target_word_len+1];
	for (uint8_t i=0;i<source_word_len;i++) {
		d[i][0] = i;
	}
	for (uint8_t i=0;i<target_word_len;i++) {
		d[0][i] = i;
	}
	for (uint8_t i=1;i<=source_word_len;i++) {
		for (uint8_t j=1;j<=target_word_len;j++) {
			if (source_word_chars[i-1] == target_word_chars[j-1]) {
				cost = 0;
			} else {
				cost = 1;
			}
			uint8_t del = d[i-1][j] + 1;
			uint8_t ins = d[i][j-1] + 1;
			uint8_t sub = d[i-1][j-1] + cost;
			d[i][j] = std::min(del, std::min(ins, sub));
			if (
				i > 1 &&
				j > 1 &&
				source_word_chars[i-1] == target_word_chars[j-2] &&
				source_word_chars[i-2] == target_word_chars[j-1]
			) {
				uint8_t transpose = d[i-2][j-2] + cost;
				d[i][j] = std::min(d[i][j],transpose);
			}
		}
	}
	return d[source_word_len][target_word_len];
}
