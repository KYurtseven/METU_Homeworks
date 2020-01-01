#include "Tournament.h"
#include "Trainer.h"
#include "Pokemon.h"
#include <vector>
#include <iostream>
#include "Enums.h"

Tournament::Tournament(const std::string& rhstournamentName){
	tournamentName = rhstournamentName;

}

Tournament::~Tournament(){
	
}

Trainer* Tournament::commence(){
	std::vector<Trainer*> newtrainers;
	while(true){
		for(int i = 0; i < (trainers.size() / 2); i++){
			std::cout << "Started Round: " <</*trainers[i]->getName()*/ i << " vs "<</*trainers[trainers.size() -1 - i]->getName()*/ (trainers.size() - 1 - i)<< std::endl;
			newtrainers.push_back(bigDuel(trainers[i],trainers[(trainers.size() - 1) - i]));
			std::cout << "Round Winner: " << newtrainers[i]->getName() << "!"  << std::endl;
		}
		trainers.clear();
		for(int j = 0; j < newtrainers.size() ; j++){
			trainers.push_back(newtrainers[j]);
		}
		newtrainers.clear();
		if(trainers.size() == 1){
			
			return trainers[0];
		}		
	}
}

const std::string& Tournament::getTournamentName() const{
	return tournamentName;
}

void Tournament::registerTrainers(const std::vector<Trainer*>& rhstrainers){
	for(int i = 0; i < rhstrainers.size() ; i++){
		trainers.push_back(rhstrainers[i]);
	}
}

Trainer* Tournament::bigDuel(Trainer* trainer1, Trainer* trainer2){
	int w_1 = 0; //win count of trainer1
	int w_2 = 0; //win count of trainer2

	if(duelBetween(trainer1, trainer2, trainer1->getFavoriteArena()) == -1){
		w_2 = w_2 + 1;
		std::cout << "\t"<<"WinnerT:" <<trainer2->getName() << "\n" << std::endl;
	}
	else{
		std::cout << "\t"<<"WinnerT:" <<trainer1->getName() << "\n" << std::endl;
		w_1 = w_1 + 1;
	}
		
	refresh(trainer1->getVector());
	refresh(trainer2->getVector());

	if(duelBetween(trainer2, trainer1, trainer2->getFavoriteArena()) == 1){
		w_2 = w_2 + 1;
		std::cout << "\t"<<"WinnerT:" <<trainer2->getName() << "\n" << std::endl;
	}
	else{
		std::cout << "\t"<<"WinnerT:" <<trainer1->getName() << "\n" << std::endl;
		w_1 = w_1 + 1;
	}
	refresh(trainer1->getVector());
	refresh(trainer2->getVector());

	if(duelBetween(trainer1, trainer2, STADIUM) == -1){
		w_2 = w_2 + 1;
		std::cout << "\t"<<"WinnerT:" <<trainer2->getName() << "\n" << std::endl;
	}
	else{
		std::cout << "\t"<<"WinnerT:" <<trainer1->getName() << "\n" << std::endl;
		w_1 = w_1 + 1;
	}
	refresh(trainer1->getVector());
	refresh(trainer2->getVector());
	
	if(w_1 > w_2)//pokemonlarin canini doldur, winner bu
	{
		return trainer1;
	}
	else{
		return trainer2;
	}
		
}


int Tournament::duelBetween(Trainer* trainer1, Trainer* trainer2, Arena currentArena){
	int t1PS = 0;//trainer1 pokemon index
	int t2PS = 0;//trainer2 pokemon index
	int turn = 1;
	std::cout << "\t"<< trainer1->getName() << " vs " << trainer2->getName()<< ": " << Helpers::getArenaName(currentArena) << std::endl; 
	
	for(int i = 0; i< trainer1->getVector().size();i++)
		duelBetween_helper(trainer1->getVector()[i],trainer2->getVector()[i],currentArena);
	
	while(true){
		if(turn == 1){
			if(duelBetweenP(trainer1->getVector()[t1PS], trainer2->getVector()[t2PS],currentArena) == 1){
			//birinci poke kazandi
				t2PS++;
				turn = 2;
			}
			else{
				t1PS++;
				turn = 1;
			}
		}
		if(t1PS == (trainer1->getVector().size()) || t2PS == (trainer2->getVector().size()))
			break;
		if(turn == 2){
			if(duelBetweenP(trainer2->getVector()[t2PS], trainer1->getVector()[t1PS],currentArena) == 1){
			//birinci poke kazandi
				t1PS++;
				turn = 1;
			}
			else{
				t2PS++;
				turn = 2;
			}
		}
		if(t1PS == (trainer1->getVector().size()) || t2PS == (trainer2->getVector().size()))
			break;
	}
	if(t1PS > t2PS) //trainer2 nin daha cok pokemonu harcanmis
		return -1;
	else
		return 1;

}

void Tournament::refresh(std::vector<Pokemon *>& rhspokemons){
	for(int i = 0;i < rhspokemons.size() ;i++){
		rhspokemons[i]->setHP(rhspokemons[i]->getBaseHP());
		rhspokemons[i]->setATK(rhspokemons[i]->getBaseATK());
		rhspokemons[i]->setBurning(false);
		rhspokemons[i]->setDrowning(false);
		rhspokemons[i]->setElectrified(false);
		rhspokemons[i]->setRooted(false);
	}
}

int Tournament::duelBetweenP(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena){
	//check flag for buffs and debuffs
	//set HP's and ATK's for the currentArena
	

	while(pokemon1->getHP() > 0 && pokemon2->getHP() >0){
		pokemon1->attackTo(pokemon2,currentArena);
		if(pokemon1->getHP() > 0 && pokemon2->getHP() >0)
			pokemon2->attackTo(pokemon1,currentArena);
	}
	if(pokemon1->getHP() > 0){
		std::cout << "\t\t" << "WinnerP:" << pokemon1->getName() << std::endl;
		pokemon1->levelUp();
		return 1;
	}
	else{
		std::cout << "\t\t" << "WinnerP:" << pokemon2->getName() << std::endl;
		pokemon2->levelUp();
		return -1;
	}
}
void Tournament::duelBetween_helper(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena){
	switch(currentArena){
		case MAGMA	:
			if(pokemon1->immune() == 1){ 
				pokemon1->setATK(pokemon1->getATK() + 10);
				pokemon1->setHP(pokemon1->getHP() + 100);
			}
			if(pokemon1->immune() == 3 || pokemon1->immune() == 4){
				pokemon1->setATK(pokemon1->getATK() - 10);
				pokemon1->setHP(pokemon1->getHP() - 100);
			}

			if(pokemon2->immune() == 1){
				pokemon2->setATK(pokemon2->getATK() + 10);
				pokemon2->setHP(pokemon2->getHP() + 100);
			}
			if(pokemon2->immune() == 3 || pokemon2->immune() == 4){
				pokemon2->setATK(pokemon2->getATK() - 10);
				pokemon2->setHP(pokemon2->getHP() - 100);
			}
			break;
		case OCEAN	:
			if(pokemon1->immune() == 2){ 
				pokemon1->setATK(pokemon1->getATK() + 10);
				pokemon1->setHP(pokemon1->getHP() + 100);
			}
			if(pokemon1->immune() == 1 || pokemon1->immune() == 5){
				pokemon1->setATK(pokemon1->getATK() - 10);
				pokemon1->setHP(pokemon1->getHP() - 100);
			}
			if(pokemon2->immune() == 2){
				pokemon2->setATK(pokemon2->getATK() + 10);
				pokemon2->setHP(pokemon2->getHP() + 100);
			}
			if(pokemon2->immune() == 1 || pokemon2->immune() == 5){
				pokemon2->setATK(pokemon2->getATK() - 10);
				pokemon2->setHP(pokemon2->getHP() - 100);
			}
			break;
		case ELECTRICITY	:
			if(pokemon1->immune() == 3){ 
				pokemon1->setATK(pokemon1->getATK() + 10);
				pokemon1->setHP(pokemon1->getHP() + 100);
			}
			if(pokemon1->immune() == 2 || pokemon1->immune() == 5){
				pokemon1->setATK(pokemon1->getATK() - 10);
				pokemon1->setHP(pokemon1->getHP() - 100);
			}
			if(pokemon2->immune() == 3){
				pokemon2->setATK(pokemon2->getATK() + 10);
				pokemon2->setHP(pokemon2->getHP() + 100);
			}
			if(pokemon2->immune() == 2 || pokemon2->immune() == 5){
				pokemon2->setATK(pokemon2->getATK() - 10);
				pokemon2->setHP(pokemon2->getHP() - 100);
			}
			break;
		case FOREST	:
			if(pokemon1->immune() == 4){ 
				pokemon1->setATK(pokemon1->getATK() + 10);
				pokemon1->setHP(pokemon1->getHP() + 100);
			}
			if(pokemon1->immune() == 2 || pokemon1->immune() == 3){
				pokemon1->setATK(pokemon1->getATK() - 10);
				pokemon1->setHP(pokemon1->getHP() - 100);
			}
			if(pokemon2->immune() == 4){
				pokemon2->setATK(pokemon2->getATK() + 10);
				pokemon2->setHP(pokemon2->getHP() + 100);
			}
			if(pokemon2->immune() == 2 || pokemon2->immune() == 3){
				pokemon2->setATK(pokemon2->getATK() - 10);
				pokemon2->setHP(pokemon2->getHP() - 100);
			}
			break;
		case SKY	:
			if(pokemon1->immune() == 5){
				pokemon1->setATK(pokemon1->getATK() + 10);
				pokemon1->setHP(pokemon1->getHP() + 100);
			}
			if(pokemon1->immune() == 1 || pokemon1->immune() == 4){
				pokemon1->setATK(pokemon1->getATK() - 10);
				pokemon1->setHP(pokemon1->getHP() - 100);
			}
			if(pokemon2->immune() == 5){
				pokemon2->setATK(pokemon2->getATK() + 10);
				pokemon2->setHP(pokemon2->getHP() + 100);
			}
			if(pokemon2->immune() == 1 || pokemon2->immune() == 4){
				pokemon2->setATK(pokemon2->getATK() - 10);
				pokemon2->setHP(pokemon2->getHP() - 100);
			}
			break;
		default	:	//STADIUM
			//no buffs or debuffs
			break;
	}
	return;
}
