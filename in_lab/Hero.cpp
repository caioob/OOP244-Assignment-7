#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict {
	Hero::Hero(){
		heroName[0] = '\0';
		hp = 0;
		attack = 0;
	}
	Hero::Hero(const char* heroName_, int hp_, int attack_) {
		if (heroName_[0] == '\0' && hp_ <= 0 && attack <= 0) {
			heroName[0] = '\0';
			hp = 0;
			attack = 0;
		}
		else {
			strncpy(heroName, heroName_, 40);
			hp = hp_;
			attack = attack_;
		}
	}

	void Hero::operator-=(int attack_){
		if (attack_ > 0 && hp > 0) {
			hp = hp - attack_;
			if (hp < 0) {
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
		if (heroName[0] == 0 && hp <= 0 && attack <= 0){
			return 0;
		}
		else {
			return attack;
		}
	}

	const char* Hero::showName(){
		return heroName;
	}

	int Hero::showHp(){
        return hp;
	}

	std::ostream & operator<<(ostream & ostr, const Hero& hero){
		Hero hero_ = hero;
		if (hero_.showName() == 0 && hero_.showHp() <= 0 && hero_.attackStrength() <= 0){
			ostr << "No Hero";
		}
		else {
			ostr << hero_.showName();
		}
		return ostr;
	}

	const Hero& operator*(const Hero& first, const Hero& second){
		Hero hero1 = first, hero2 = second, winner;
		int roundCount = 0;

		for (int i = 0; i < MAX_ROUNDS && (hero1.isAlive() == true && hero2.isAlive() == true); ++i) {
			hero1 -= hero2.attackStrength();
			hero2 -= hero1.attackStrength();
			roundCount++;
		}
		if (hero1.isAlive() == false) {
			cout << "Ancient Battle! " << hero1.showName() << " vs " << hero2.showName() << " : Winner is " << hero2.showName() << " in "<< roundCount <<" rounds." << endl;
			return second;
		}
		else if (hero2.isAlive() == false) {
			cout << "Ancient Battle! " << hero1.showName() << " vs " << hero2.showName() << " : Winner is " << hero1.showName() << " in "<< roundCount <<" rounds." << endl;
			return first;
		}
		else if (hero1.isAlive() == true && hero2.isAlive() && roundCount == 100) {
			cout << "Ancient Battle! " << hero1.showName() << " vs " << hero2.showName() << " : Winner is " << hero1.showName() << " in "<< roundCount <<" rounds." << endl;
			return first;
		}
		return first;//it's only here for fixing a compiller warning in matrix's gcc, because the submission scrpits doesn't accept warnings aswell
    }
}
