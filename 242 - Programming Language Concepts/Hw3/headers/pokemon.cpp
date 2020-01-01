#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "pokemon.h"

using namespace std;

Pokemon::Pokemon(const string& a, const string& b , int c){
	name = a;
	type = b;
	exphave = 0;
	expevolve = c;
}
Pokemon::Pokemon(const Pokemon& rhs){
	name = rhs.name;
	type = rhs.type;
	exphave = rhs.exphave;
	expevolve = rhs.expevolve;
}

Pokemon::~Pokemon(){

}

const string& Pokemon::getName() const{
	return name;
}

bool Pokemon::operator>>(const Pokemon& rhs){
	if (this->expevolve == -1)
		return false;
	if(this->exphave >= this->expevolve){
		this->name = rhs.name;
		this->type = rhs.type;
		this->expevolve = rhs.expevolve;
		return true;
	}
	else
		return false;		
}

Pokemon operator&(Pokemon& lhs, Pokemon& rhs){
	if (lhs.type == "fire"){
		if (rhs.type == "water"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "grass"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "electric"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "flying"){
			rhs.exphave ++;
			return rhs;
		}
	}
	else if (lhs.type == "water"){
		if (rhs.type == "fire"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "grass"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "electric"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "flying"){
			lhs.exphave ++;
			return lhs;
		}
	}
	else if (lhs.type == "grass"){
		if (rhs.type == "fire"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "water"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "electric"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "flying"){
			rhs.exphave ++;
			return rhs;
		}
	}
	else if (lhs.type == "electric"){
		if (rhs.type == "fire"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "water"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "grass"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "flying"){
			lhs.exphave ++;
			return lhs;
		}
	}
	else if (lhs.type == "flying"){
		if (rhs.type == "fire"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "water"){
			rhs.exphave ++;
			return rhs;
		}
		else if (rhs.type == "grass"){
			lhs.exphave ++;
			return lhs;
		}
		else if (rhs.type == "electric"){
			rhs.exphave ++;
			return rhs;
		}
	}		
}

Pokemon& Pokemon::operator=(const Pokemon& rhs){
	name = rhs.name;
	type = rhs.type;
	exphave = rhs.exphave;
	expevolve = rhs.expevolve;
	return *this;
}
