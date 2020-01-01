#include "pokemon.h"
#include "region.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void generatePokemons(Region* region) {
	region->placePokemon(Pokemon("Pikachu", "electric", 12), 7, 2, 1);
	// Pokemon-2
	region->placePokemon(Pokemon("Raichu", "electric", -1), 3, 1, 3);
	// Pokemon-3
	region->placePokemon(Pokemon("Voltorb", "electric", 3), 2, 0, 1);
	// Pokemon-4
	region->placePokemon(Pokemon("Electrode", "electric", -1), 5, 2, 3);

	/*************** Grass Pokemons ***************/
	// Pokemon-5
	region->placePokemon(Pokemon("Bulbasaur", "grass", 10), 2, 3, 3);
	// Pokemon-6
	region->placePokemon(Pokemon("Ivysaur", "grass", 20), 6, 0, 2);
	// Pokemon-7
	region->placePokemon(Pokemon("Venusaur", "grass", -1), 4, 0, 3);
	// Pokemon-8
	region->placePokemon(Pokemon("Oddish", "grass", 2), 0, 3, 1);
	// Pokemon-9
	region->placePokemon(Pokemon("Gloom", "grass", 4), 6, 2, 2);
	// Pokemon-10
	region->placePokemon(Pokemon("Vileplume", "grass", -1), 3, 3, 3);

	/*************** Fire Pokemons ***************/
	// Pokemon-11
	region->placePokemon(Pokemon("Charmander", "fire", 5), 1, 2, 2);
	// Pokemon-12
	region->placePokemon(Pokemon("Charmeleon", "fire", 7), 2, 1, 3);
	// Pokemon-13
	region->placePokemon(Pokemon("Charizard", "fire", -1), 1, 0, 3);
	// Pokemon-14
	region->placePokemon(Pokemon("Vulpix", "fire", 1), 2, 1, 1);
	// Pokemon-15
	region->placePokemon(Pokemon("Ninetales", "fire", -1), 5, 3, 0);
	// Pokemon-16
	region->placePokemon(Pokemon("Ponyta", "fire", 3), 1, 2, 0);
	// Pokemon-17
	region->placePokemon(Pokemon("Rapidash", "fire", -1), 3, 2, 1);

	/*************** Water Pokemons ***************/
	// Pokemon-18
	region->placePokemon(Pokemon("Squirtle", "water", 12), 6, 3, 0);
	// Pokemon-19
	region->placePokemon(Pokemon("Wartortle", "water", 15), 4, 1, 2);
	// Pokemon-20
	region->placePokemon(Pokemon("Blastoise", "water", -1), 2, 0, 2);
	// Pokemon-21
	region->placePokemon(Pokemon("Psyduck", "water", 10), 1, 1, 0);
	// Pokemon-22
	region->placePokemon(Pokemon("Golduck", "water", -1), 7, 0, 1);
	// Pokemon-23
	region->placePokemon(Pokemon("Staryu", "water", 8), 6, 1, 1);
	// Pokemon-24
	region->placePokemon(Pokemon("Starmie", "water", -1), 5, 0, 3);

	/************* Flying Pokemons *************/
	// Pokemon-25
	region->placePokemon(Pokemon("Pidgey", "flying", 3), 6, 1, 2);
	// Pokemon-26
	region->placePokemon(Pokemon("Pidgeotto", "flying", 6), 7, 2, 0);
	// Pokemon-27
	region->placePokemon(Pokemon("Pidgeot", "flying", -1), 6, 3, 2);
	// Pokemon-28
	region->placePokemon(Pokemon("Caterpie", "grass", 1), 0, 0, 2);
	// Pokemon-29
	region->placePokemon(Pokemon("Metapod", "grass", 2), 4, 3, 3);
	// Pokemon-30
	region->placePokemon(Pokemon("Butterfree", "flying", -1), 3, 2, 3);
	// Pokemon-31
	region->placePokemon(Pokemon("Zubat", "flying", 5), 4, 0, 0);
	// Pokemon-32
	region->placePokemon(Pokemon("Golbat", "flying", -1), 0, 3, 0);

}

//g++ -ansi -pedantic pokemon.cpp region.cpp trainer.cpp main.cpp -o hw3

int main(int argc, char* argv[]) {

	/*************** Pokemon Class Tests ***************/
	Pokemon pokemon1("Pikachu", "electric", 12);
	Pokemon pokemon2("Rattata", "grass", 4);

	cout << pokemon1.getName() << "\n";
	cout << pokemon2.getName() << "\n";
	cout << (pokemon1 & pokemon2).getName() << "\n"; // Pikachu & Rattata => Rattata wins
	cout << (pokemon2 & pokemon1).getName() << "\n"; // Rattata & Pikachu => Rattata wins
	Pokemon pokemon3(pokemon1);			// Copy Pikachu
	cout << pokemon3.getName() << "\n";
	cout << (pokemon3 & pokemon2).getName() << "\n";// Copied Pikachu & Rattata => Rattata wins

	Pokemon pokemon4("Raticate", "grass", 0);
	cout << (pokemon2 >> pokemon4) << "\n";	// Try to evolve Rattata into Raticate => not possible

	cout << (pokemon2 & pokemon3).getName() << "\n";// Rattata & Copied Pikachu => Rattata wins

	cout << (pokemon2 >> pokemon4) << "\n";	// Try to evolve Rattata into Raticate => evolved
	cout << pokemon2.getName() << "\n";	// Check Ratata has evolved into Raticate or not => It is Raticate

	/*************** Region Class Tests ***************/
	int corner1[3] = { 0, 0, 0 };
	int corner2[3] = { 7, 3, 3 };
	Region world(corner1, corner2);

	cout << "min x is " << world.getMinBorder('x') << endl; //prints 0
	cout << "max y is " << world.getMaxBorder('y') << endl;
	generatePokemons(&world);
	Region mars(world);
	cout << mars.getPokemonCount(corner1, corner2) << "\n";	// 32*

	cout << world.getPokemonCount(corner1, corner2) << "\n";	// 32*
	cout << (world(6, 0, 2)).getName() << "\n";	// Ivysaur
	cout << (world(1, 1, 0)).getName() << "\n";	// Psyduck
	cout << (world(2, 1, 3)).getName() << "\n";	// Charmeleon
	/*cout << (world(0, 0, 0)).getName() << "\n";	// Exception: "There does not exist any pokemon in the given coordinates!"
/*
	//Region mars(world);
	int cornerX[3] = { 4, 0, 2 };
	int cornerY[3] = { 7, 3, 3 };
	world.crop(cornerX, cornerY);*/
	//int cornerW[3] = {7, 2, 2};
	///int cornerZ[3] = {7, 3, 3};
	////Region jupiter(cornerW, cornerZ);
	//jupiter.placePokemon(Pokemon("Togepi", "unknown", -1), 7, 2, 3); // you can change the type if you wish
	//jupiter.placePokemon(Pokemon("Gastly", "unknown", -1), 7, 3, 2); // "unkonwn" type of pokemons will not be put into challenge
	//mars.patch(jupiter);

	return 0;
}

