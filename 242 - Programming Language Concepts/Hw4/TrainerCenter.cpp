#include "TrainerCenter.h"
#include <iostream>
#include <fstream>
#include <string>


TrainerCenter::TrainerCenter(const std::string& inputFileName){
	//std::ifstream infile(inputFileName.c_str());
	/*std::ifstream infile("2Trainers.txt");
	if(infile.is_open()){
		std::string line;
		while(std::getline(infile,line)){
			//getline(infile,line);
			std::cout << line << "\n";
		}
	}
	*/

	/*while(std::getline(infile, line)){
		int a = std::stoi(infile, nullptr);
		std::istringstream iss(line);
		int b;
		if(iss >> "Trainer " >> "Count:" >> b)
			continue;
		else
			break;
	}*/
	/*int b;
	while(true){
		if(infile >> "Trainer" >> " " >>  "Count:" >> b){
			std::cout << "ALLAHUEKBER WUHU" << std::endl;
			continue;
		}
		else
			break;
	}*/
}
TrainerCenter::~TrainerCenter(){

}
    
std::vector<Trainer*>& TrainerCenter::getAllTrainers(){

}

Trainer* TrainerCenter::getTrainerWithID(int trainerID){

}