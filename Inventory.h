#pragma once
#include "Character.h"
#include <iostream>

using namespace std;

class Inventory: public Map
{
protected:
	int sunscreen = 5;
	int money = 0;
	int knifex = 1;
	int knifey = 5;
	int water = 5;
	int food = 10;
	int plus = 0;
	string pick = "";
	bool have;
	bool poke = true;

public:
	
	// string array used for the inventory 
	string backpack[6] =
	{
		 " ",
		 " ",
		 " ",
		 " ",
		 " ",
		 " ",
	};

	// setters for inventory variables
	void setsunscreen(int s) { sunscreen = s; }
	void setmoney(int m) { money = m; }
	void setwater(int w) { water = w; }
	void setfood(int f) { food = f; }
	void setpick(string s) { pick = s; }
	void sethave(bool h) { have = h; }
	void setplus(int a) { plus = plus + a; }
	void setpoke(bool p) { poke = p; }

	// getters for inventory variables
	int getsun() { return sunscreen; }
	int getmoney() { return money; }
	int getknifex() { return knifex; }
	int getwater() { return water; }
	int getfood() { return food; }
	int getplus() { return plus; }
	string getpick() { return pick; }
	bool gethave() { return have; }
	bool getpoke() { return poke; }

	Inventory();

	// functions used to get objects, add objects to the backpack array, show what is in your inventory.
	// use whats in your inventory and buy something from the store.
	void get();
	void add(string b);
	void showarray();
	void use(string u);
	void buy(string m);

};