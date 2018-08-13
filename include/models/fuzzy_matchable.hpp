#ifndef __FUZZY_MATCHABLE__
#define __FUZZY_MATCHABLE__

#include <stdint.h>
#include <iostream>
#include "./matchable.hpp"

template <class T>
class FuzzyMatchable: public Matchable<T> {
	public:
		bool matchAgainst(T* target) {
			int d = this->levenshteinDistance(target);
			return d < this->max_distance;
		}
		void setMaxDistance(uint8_t max_distance) {
			this->max_distance = max_distance;
		};
	protected:
		virtual uint8_t levenshteinDistance(T* target);
	private:
		uint8_t max_distance = 1;
};

#endif
