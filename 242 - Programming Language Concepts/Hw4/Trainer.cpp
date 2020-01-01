#include <string>
#include <vector>
#include "Trainer.h"


Trainer::Trainer(int rhstrainerID, const std::string& rhsname, Arena rhsfavoriteArena, 
	std::vector<Pokemon *>& rhspokemons){

	name = rhsname;
	trainerID = rhstrainerID;
	favoriteArena = rhsfavoriteArena;
	for(int i = 0; i < rhspokemons.size(); i++){
		pokemons.push_back(rhspokemons[i]);
	}

}

Trainer::~Trainer(){
	/*for(int i = 0; i< this->pokemons.size(); i++){
		delete pokemons[i];
	}
	pokemons.clear();*/
}
std::vector<Pokemon*>& Trainer::getVector(){
	return this->pokemons;
}
int Trainer::getTrainerID()const{
	return trainerID;
}

const std::string& Trainer::getName()const{
	return name;
}

Arena Trainer::getFavoriteArena()const{
	return favoriteArena;
}