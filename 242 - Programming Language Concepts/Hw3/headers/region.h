#ifndef REGION_H
#define REGION_H

#include "pokemon.h"
#include <iostream>
#include <exception>

using namespace std;

class Region {
	private:
		// Add private members, methods and constructors here as you need
		struct Bvh
		{
			Bvh * left = NULL;
			Bvh * right = NULL;
			Bvh * parent = NULL;
			Pokemon * data;
			int x1,x2,y1,y2,z1,z2;
			Bvh(): left(NULL),right(NULL),parent(NULL),x1(0), x2(0),
										    		   y1(0), y2(0),
										    		   z1(0), z2(0),
										    		   data(NULL){}
			Bvh(Bvh *l,Bvh *r, Bvh *p,const int f[],const int s[],Pokemon *d)
			: left(l), right(r), parent(p), x1(f[0]), x2(s[0]),
										    y1(f[1]), y2(s[1]),
										    z1(f[2]), z2(s[2]),
										    data(d){}

		};
		Bvh * root;
		void destruction_helper(Bvh *);
		void parent_helper(Bvh *);
		Bvh * copy_helper(const Bvh*);
		int count_helper(Bvh *, int, int, int, int, int, int) const;
		Bvh* crop_helper(Bvh *, int, int, int, int, int, int) const;
	public:
		// Do NOT make any modifications below
		Region(const int[3], const int[3]);
		Region(const Region&);
		~Region();
		int getMinBorder(char) const;
		int getMaxBorder(char) const;
		void placePokemon(const Pokemon&, int, int, int);
		Pokemon& operator()(int, int, int);
		int getPokemonCount(const int[3], const int[3]) const;
		Region crop(const int[3], const int[3]) const;
		void patch(Region);
		Region& operator=(const Region&);
};

class pokemonException: public exception {
 	virtual const char* what() const throw() {
    		return "There does not exist any pokemon in the given coordinates!";
	}
};

#endif
