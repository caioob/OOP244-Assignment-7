#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {
	const int MAX_ROUNDS = 100;
	class Hero {
		char heroName[41];
		int hp;
		int attack;
	public:
		Hero();
		Hero(char*, int, int);
		void operator -=(int);
		bool isAlive();
		int attackStrength() const;
		const char* showName();
		bool isEmpty();
	};
	//ostream& operator << (ostream&, const Hero&);
	const Hero& operator* (const Hero&, const Hero&);
};
#endif 