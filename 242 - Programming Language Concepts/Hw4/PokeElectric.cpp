#include <string>
#include "Pokemon.h"
#include "Enums.h"
#include "PokeElectric.h"
#include <iostream>
using namespace Helpers;

PokeElectric::PokeElectric(int pokemonID,const std::string& name):Pokemon(pokemonID, name){
	HP = 500;
	ATK = 70;
	MAG_DEF = 30;
	PHY_DEF = 0;
	burning = false;
	drowning = false;
	electrified = false;
	rooted = false;
	BASEATK = ATK;
	BASEHP = HP;
}
PokeElectric::~PokeElectric(){
	
}
void PokeElectric::levelUp(){
	HP = HP + 50;
	ATK = ATK + 7;
	MAG_DEF = MAG_DEF + 3;
	PHY_DEF = PHY_DEF + 0;
	BASEATK = BASEATK + 7;
	BASEHP = BASEHP + 50;
}

void PokeElectric::attackTo(Pokemon* rhstarget, Arena rhscurrentArena){
	char dmg;
	switch(rhscurrentArena){
		case ELECTRICITY: dmg = '+';
						break;
		case MAGMA 		: dmg = '-';
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
	
	if(drowning){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is drowning!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(DROWNING) - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}
	
	if(rooted){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is rooted!!!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(ROOTED) * 2 - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}

	rhstarget->setElectrified(true);

	int a = std::max(1, ATK - rhstarget->getPHY_DEF());
	std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " hit " << rhstarget->getName() << "(" << rhstarget->getHP() << ") " << a << "(" << dmg << ")" <<std::endl;
	rhstarget->setHP(rhstarget->getHP() - a);
}

int PokeElectric::immune()const{
	return 3;
}

void PokeElectric::setBurning(bool rhs){
	burning = rhs;
}
void PokeElectric::setDrowning(bool rhs){
	drowning = rhs;
}
void PokeElectric::setElectrified(bool rhs){
	electrified = false;
}
void PokeElectric::setRooted(bool rhs){
	rooted = rhs;
}