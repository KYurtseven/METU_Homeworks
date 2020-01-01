#ifndef POKEGRASS_H
#define POKEGRASS_H

#include "Pokemon.h"

class PokeGrass : public Pokemon
{
public:
	// Add your public methods/attributes here.
	PokeGrass(int,const std::string& rhsname);
	virtual void levelUp();
	virtual void attackTo(Pokemon* target, Arena currentArena);
	virtual int immune()const;
	~PokeGrass();
	virtual void setBurning(bool rhs);
	virtual void setDrowning(bool rhs);
	virtual void setElectrified(bool rhs);
	virtual void setRooted(bool rhs);
protected:
	// Add your protected methods/attributes here.

private:
	// Add your private methods/attributes here.
	
};

#endif