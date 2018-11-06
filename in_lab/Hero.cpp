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
	Hero::Hero(char* heroName_, int hp_, int attack_) {
		if (strcmp(heroName_, '\0') == 0 && hp_ <= 0 && attack <= 0) {
			heroName[0] = '\0';
			hp = 0;
			attack = 0;
		}
		else {
			strncpy_s(heroName, heroName_, 40);
			hp = hp_;
			attack = attack_;
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
		if (isEmpty() == true) {
			return 0;
		}
		else {
			return attack;
		}
	}

	const char * Hero::showName(){
		return heroName;
	}

	bool Hero::isEmpty(){
		if (heroName[0] == '\0' && hp = 0 && attack = 0) {
			return true;
		}
		else {
			return false;
		}
	}




	std::ostream & operator<<(ostream & ostr, const Hero& hero){
		Hero hero_ = hero;
		if (hero_.isEmpty() == true) {
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
		for (int i = 0; i < MAX_ROUNDS && (hero1.isAlive() == true && hero2.isAlive() == true); i++) {
			hero1 -= hero2.attackStrength();
			hero2 -= hero2.attackStrength();
			roundCount++;
		}
		if (hero1.isAlive() == false) {
			winner = hero2;
		}
		else if (hero2.isAlive() == false) {
			winner = hero1;
		}
		else if (hero1.isAlive() == true && hero2.isAlive() && roundCount == 100) {
			winner = hero1;
		}
		cout << "Ancient Battle! " << hero1.showName() << " vs " << hero2.showName() << " : Winner is " << winner.showName() << " in "<< roundCount <<" rounds." << endl;
}
