#include <string>
#include "Pokemon.h"
#include "Enums.h"
#include "PokeGrass.h"
#include <iostream>
using namespace Helpers;

PokeGrass::PokeGrass(int pokemonID,const std::string& name):Pokemon(pokemonID, name){
	HP = 800;
	ATK = 40;
	MAG_DEF = 0;
	PHY_DEF = 30;
	burning = false;
	drowning = false;
	electrified = false;
	rooted = false;
	BASEATK = ATK;
	BASEHP = HP;
}
PokeGrass::~PokeGrass(){
	
}
void PokeGrass::levelUp(){
	HP = HP + 80;
	ATK = ATK + 4;
	MAG_DEF = MAG_DEF + 0;
	PHY_DEF = PHY_DEF + 3;
	BASEATK = BASEATK + 4;
	BASEHP = BASEHP + 80;
}

void PokeGrass::attackTo(Pokemon* rhstarget, Arena rhscurrentArena){
	char dmg;
	switch(rhscurrentArena){
		case FOREST		: dmg = '+';
						break;
		case MAGMA 		: dmg = '-';
						break;
		case SKY 		: dmg = '-';
						break;
		default			: dmg = '/';
						break;
	}
	if(burning){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is burning!!!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(BURNING) * 2 - MAG_DEF));
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
	
	if(electrified){
		std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " is electrified!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(ELECTRIFIED) - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}

	rhstarget->setRooted(true);

	int a = std::max(1, ATK - rhstarget->getPHY_DEF());
	std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " hit " << rhstarget->getName() << "(" << rhstarget->getHP() << ") " << a << "(" << dmg << ")" <<std::endl;
	rhstarget->setHP(rhstarget->getHP() - a);
}

int PokeGrass::immune()const{
	return 4;
}
void PokeGrass::setBurning(bool rhs){
	burning = rhs;
}
void PokeGrass::setDrowning(bool rhs){
	drowning = rhs;
}
void PokeGrass::setElectrified(bool rhs){
	electrified = rhs;
}
void PokeGrass::setRooted(bool rhs){
	rooted = false;
}