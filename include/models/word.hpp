#ifndef __WORD__
#define __WORD__

#include "./fuzzy_matchable.hpp"
#include <string>

class Word: public FuzzyMatchable<Word> {
	private:
		std::string word;
	protected:
		uint8_t levenshteinDistance(Word*);
	public:
		Word(std::string word);
		~Word();
		std::string getWord();
};

#endif
