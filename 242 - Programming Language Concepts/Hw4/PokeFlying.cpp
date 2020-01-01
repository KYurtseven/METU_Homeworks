#include <string>
#include "Pokemon.h"
#include "Enums.h"
#include "PokeFlying.h"
#include <iostream>
using namespace Helpers;

PokeFlying::PokeFlying(int pokemonID,const std::string& name):Pokemon(pokemonID, name){
	HP = 650;
	ATK = 55;
	MAG_DEF = 0;
	PHY_DEF = 15;
	burning = false;
	drowning = false;
	electrified = false;
	rooted = false;
	BASEATK = ATK;
	BASEHP = HP;
}
PokeFlying::~PokeFlying(){
	
}
void PokeFlying::levelUp(){
	HP = HP + 65;
	ATK = ATK + 5;
	MAG_DEF = MAG_DEF + 0;
	PHY_DEF = PHY_DEF + 3;
	BASEATK = BASEATK + 5;
	BASEHP = BASEHP + 65;
}

void PokeFlying::attackTo(Pokemon* rhstarget, Arena rhscurrentArena){
	char dmg;
	switch(rhscurrentArena){
		case SKY		: dmg = '+';
						break;
		case OCEAN 		: dmg = '-';
						break;
		case ELECTRICITY: dmg = '-';
						break;
		default			: dmg = '/';
						break;
	}
	if(getHP() <= 0 ){
		return;
	}
	int a = std::max(1, ATK - rhstarget->getPHY_DEF());
	std::cout << "\t\t\t" << this->getName() << "(" << HP << ")" << " hit " << rhstarget->getName() << "(" << rhstarget->getHP() << ") " << a << "(" << dmg << ")" <<std::endl;
	rhstarget->setHP(rhstarget->getHP() - a);
}

int PokeFlying::immune()const{
	return 5;
}


void PokeFlying::setBurning(bool rhs){
	burning = false;
}
void PokeFlying::setDrowning(bool rhs){
	drowning = false;
}
void PokeFlying::setElectrified(bool rhs){
	electrified = false;
}
void PokeFlying::setRooted(bool rhs){
	rooted = false;
}