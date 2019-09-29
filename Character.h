#pragma once
#include <iostream>
#include "Map.h"

using namespace std;


class Character
{
protected:
	// character variables
	string name = " ";
	int health = 100;
	int points = 0;
	int i = 0;

	// damage variables
	int sun = 20;
	const int THIRST = 30;
	const int HUNGER = 40;
	
public:

	// setters for variables
	void setsun(int s) { sun = s; }
	void sethealth(int h) { health = health + h; }
	void setpoints(int p) { points = p + points; }
	void setname(string n) { name = n; }
	void seti(int j) { i = i + j; }
	
	// getters for variables
	int gethealth() { return health; }
	int getpoints() { return points;}
	string getname() { return name; }
	int getsun(){ return sun; }
	const int getTHIRST() { return THIRST; }
	const int getHUNGER() { return HUNGER; }

	// character functions for damage, and death
	void damage();
	void checkifdead();

	Character();


};