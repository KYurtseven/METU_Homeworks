#include <string>
#include "Pokemon.h"
#include "Enums.h"
#include "PokeFire.h"
#include <iostream>
using namespace Helpers;

PokeFire::PokeFire(int pokemonID,const std::string& name):Pokemon(pokemonID, name){
	HP = 600;
	ATK = 60;
	MAG_DEF = 20;
	PHY_DEF = 10;
	burning = false;
	drowning = false;
	electrified = false;
	rooted = false;
	BASEATK = ATK;
	BASEHP = HP;
}
PokeFire::~PokeFire(){
	
}
void PokeFire::levelUp(){
	HP = HP + 60;
	ATK = ATK + 6;
	MAG_DEF = MAG_DEF + 2;
	PHY_DEF = PHY_DEF + 1;
	BASEATK = BASEATK + 6;
	BASEHP = BASEHP + 60;
}

void PokeFire::attackTo(Pokemon* rhstarget, Arena rhscurrentArena){
	char dmg;
	switch(rhscurrentArena){
		case MAGMA		: dmg = '+';
						break;
		case OCEAN 		: dmg = '-';
						break;
		case SKY 		: dmg = '-';
						break;
		default			: dmg = '/';
						break;
	}
	if(drowning){
		std::cout << "\t\t\t" << name << "(" << HP << ")" << " is drowning!!!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(DROWNING) * 2 - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}
	
	if(electrified){
		std::cout << "\t\t\t" << name << "(" << HP << ")" << " is electrified!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(ELECTRIFIED) - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}
	
	if(rooted){
		std::cout << "\t\t\t" << name << "(" << HP << ")" << " is rooted!!" << std::endl;
		HP = HP - std::max(0, (getEffectDamage(ROOTED) - MAG_DEF));
	}
	if(getHP() <= 0 ){
		return;
	}
	rhstarget->setBurning(true);

	int a = std::max(1, ATK - rhstarget->getPHY_DEF());
	std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " hit " << rhstarget->getName() << "(" << rhstarget->getHP() << ") " << a << "(" << dmg << ")" <<std::endl;
	rhstarget->setHP(rhstarget->getHP() - a);
}

int PokeFire::immune()const{
	return 1;
}
void PokeFire::setBurning(bool rhs){
	burning = false;
}
void PokeFire::setDrowning(bool rhs){
	drowning = rhs;
}
void PokeFire::setElectrified(bool rhs){
	electrified = rhs;
}
void PokeFire::setRooted(bool rhs){
	rooted = rhs;
}