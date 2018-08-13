#ifndef __MATCHABLE__
#define __MATCHABLE__

#include <stdint.h>

template <class T>
class Matchable {
	public:
		virtual bool matchAgainst(T*) = 0;
};

#endif
