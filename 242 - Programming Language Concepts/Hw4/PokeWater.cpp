#include <string>
#include "Pokemon.h"
#include "Enums.h"
#include "PokeWater.h"
#include <iostream>

using namespace Helpers;

PokeWater::PokeWater(int pokemonID,const std::string& name):Pokemon(pokemonID, name){
	HP = 700;
	ATK = 50;
	MAG_DEF = 10;
	PHY_DEF = 20;
	burning = false;
	drowning = false;
	electrified = false;
	rooted = false;
	BASEATK = ATK;
	BASEHP = HP;
}
PokeWater::~PokeWater(){
	
}
void PokeWater::levelUp(){
	HP = HP + 70;
	ATK = ATK + 5;
	MAG_DEF = MAG_DEF + 1;
	PHY_DEF = PHY_DEF + 2;
	BASEATK = BASEATK + 5;
	BASEHP = BASEHP + 70;
}

void PokeWater::attackTo(Pokemon* rhstarget, Arena rhscurrentArena){
	char dmg;
	switch(rhscurrentArena){
		case OCEAN		: dmg = '+';
						break;
		case ELECTRICITY: dmg = '-';
						break;
		case FOREST		: dmg = '-';
						break;
		default			: dmg = '/';
						break;
	}
	if(burning){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is burning!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(BURNING) - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}
	
	if(electrified){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is electrified!!!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(ELECTRIFIED) * 2 - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}
	
	if(rooted){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is rooted!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(ROOTED) - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}

	rhstarget->setDrowning(true);

	int a = std::max(1, ATK - rhstarget->getPHY_DEF());
	std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " hit " << rhstarget->getName() << "(" << rhstarget->getHP() << ") " << a << "(" << dmg << ")" <<std::endl;
	rhstarget->setHP(rhstarget->getHP() - a);
}
int PokeWater::immune()const{
	return 2;
}

void PokeWater::setBurning(bool rhs){
	burning = rhs;
}
void PokeWater::setDrowning(bool rhs){
	drowning = false;
}
void PokeWater::setElectrified(bool rhs){
	electrified = rhs;
}
void PokeWater::setRooted(bool rhs){
	rooted = rhs;
}