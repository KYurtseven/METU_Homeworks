#include <string>
#include "Pokemon.h"
#include "Enums.h"
#include <iostream>

Pokemon::Pokemon(int rhspokemonID, const std::string& rhsname){
	pokemonID = rhspokemonID;
	name = rhsname;
}

Pokemon::~Pokemon(){

}

int Pokemon::getPokemonID()const{
	return pokemonID;
}

const std::string& Pokemon::getName() const{
	return name;
}
void Pokemon::setHP(int rakam){
	HP = rakam;
}
void Pokemon::setBurning(bool rhs){
}
void Pokemon::setDrowning(bool rhs){
}
void Pokemon::setElectrified(bool rhs){
}
void Pokemon::setRooted(bool rhs){
}
void Pokemon::setBaseATK(int rhs){
	BASEATK = rhs;
}
int Pokemon::getBaseATK()const{
	return BASEATK;
}
void Pokemon::setBaseHP(int rhs){
	BASEHP = rhs;
}
int Pokemon::getBaseHP()const{
	return BASEHP;
}
void Pokemon::setATK(int rhs){
	ATK = rhs;
}
int Pokemon::getHP() const{
	return HP;
}
int Pokemon::getATK() const{
	return ATK;
}
int Pokemon::getMAG_DEF() const{
	return MAG_DEF;
}
int Pokemon::getPHY_DEF() const{
	return PHY_DEF;
}
bool Pokemon::isBurning() const{
	if(burning)
		return true;
	else 
		return false;
}
bool Pokemon::isDrowning() const{
	if(drowning)
		return true;
	else 
		return false;
}
bool Pokemon::isElectrified() const{
	if(electrified)
		return true;
	else 
		return false;
}
bool Pokemon::isRooted() const{
	if(rooted)
		return true;
	else 
		return false;
}