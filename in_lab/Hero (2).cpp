#include <iostream>
#include <cstring>
#include "hero.h"
using namespace std;

namespace sict {
	Hero::Hero(){
		heroName[0] = '\0';
		hp = 0;
		attack = 0;
	}
	Hero::Hero(char heroName_, int hp_, int attack_) {
		if (heroName_[1] != '\0' && hp_ > 0 && atack > 0) {
			strncpy_s(heroName, heroName_);
			hp = hp_;
			attack = attack_;
		}
		else {
			heroName[0] = '\0';
			hp = 0;
			attack = 0;
		}
	}

	void Hero::operator-=(int attack_){
		if (attack_ > 0) {
			hp = hp - attack;
			if (hp <= 0) {
				hp = 0;
			}
		}
	}

	bool Hero::isAlive(){
		if (hp > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int Hero::attackStrength() const{
		if (heroName[0] == '\0' && hp = 0 && attack = 0) {
			return 0;
		}
		else {
			return attack;
		}
	}


	ostream & operator<<(ostream &, conste Hero &)
	{
		// TODO: insert return statement here
	}

}