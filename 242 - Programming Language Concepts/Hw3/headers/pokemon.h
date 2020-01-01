#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon {
	private:
		// Add private members, methods and constructors here as you need
		string name;
		string type;
		int exphave; //sahip oldugu exp
		int expevolve; //bir sonraki seviye icin gereken exp
	public:
		// Do NOT make any modifications below
		Pokemon(const string&, const string&, int);
		Pokemon(const Pokemon&);
		~Pokemon();
		const string& getName() const;
		bool operator>>(const Pokemon&);
		friend Pokemon operator&(Pokemon&, Pokemon&);
		Pokemon& operator=(const Pokemon&);
};

#endif
