#pragma once
#include <iostream>


using namespace std;

class Map
{
protected:
	int posx = 2;
	int posy = 3;
	bool play = true;
	int moves = 0;
	int inc = 0;

	// moving north will move up a column, moving south will move down a column
	// moving east will move one row over to the right, moving west will move one row over to the left.
	string locations[5][5] =
	{
		{"You are standing at the edge of a big park.. There is a big hole in the ground, looks like they're doing construction.\n", // [0][0]
		"You are now behind Holomua Elementary School, which connects to the park and the golf course.\n", // [0][1]
		"You continue walking and end up in a big park that connects all the way from the golf course.\n",  // [0][2]
		"Good News: Youve managed to run across the golf course and escape security.\nBad News: Youve run into a big chasm ahead.. Doesn't look like there is much down there..\n",  // [0][3]
		"You continue to walk straight and are now at the 711. You see the highschool just right up ahead!\n\nBut it's blocked off by construction! Looks like you will have to find a way around.\n",}, // [0][4]

		{"You are now inside a big park in a sketchy part of town..You find a knife on the ground..\n", // [1][0]
		"You are now inside Holomua Elementary School.. You see one of your old teachers and they give you an apple.\nI thought the students were supposed to give the teachers the apples?\n", // [1][1]
		"You have walked into the neighborhood left of the golf course..\nThis is your neighborhood, i thought you were supposed to be walking to school not walking back home?\n\n  ", // [1][2]
		"You walked into the golf course, congrats the security is now chasing you.\n", // [1][3]
		"You walked right on pass safeway and now see a big green park on your right and 711 a ways down the road.\n",}, // [1][4]

		{"You come across a big park in a sketchy part of town, just past the elemetary school..\n", // [2][0]
		"Now you are standing in front of Holomua Elementary School.\nI thought you were starting your freshman year not the first grade..\n", // [2][1]
		"You have come across the dog park next to your house, you do not own a dog...\n", // [2][2]
		"Oh great job! You're right back where you started!\nThe Hawaiian Prince Golf Course is right in front of you, maybe try doing something different this time..\n\n", //starting point [2][3]
		"You begin walking down the road and see safeway on the right of you.\n"}, // [2][4] right path

		{"You walk south of a park and end up at a 711. You see foodland in the distance,\nI thought foodland was the opposite direction from school?\n", // [3][0]
		"You are now in a neighborhood south of the elementary school..\n", // [3][1]
		"You are now in a park playing on the playground,how old are you?\nYou see a basketball lying on the ground.\n", // [3][2]
		"You walk into a nice neighborhood directly south of the golf course, too bad this is not your neighborhood.\n", // [3][3]
		"You are walking down the sidewalk and you see foodland, I thought that was the opposite direction from school?\n",}, // [3][4]

		{"You walk south of a 711 and see the sign that you are leaving Ewa Beach and now entering Waipahu.\nYou dont go to Waipahu High School.\n", // [4][0]
		"You have stumbled across a neighborhood at the edge of Ewa Beach.\nThere is actually a bus here that takes kids to Campbell Highschool! Would you like to get on?\n", // [4][1]
		"You see a park in the distance as you continue to walk through a neighborhood on the edge of town.\n", // [4][2]
		"You keep walking and come across a basketball court, too bad you dont have a basketball with you..\n", // [4][3]
		"You have been walking for so long you reach the end of a neighborhood.\nYou look over the edge of a cliff and it looks like there is some kind of weird black hole down there..\n",}, // [4][4]

	};

public:
	
	
	// setters for map variables
	void setmoves(int m) { moves = moves + m; }
	void setinc(int x) { inc = inc + x; }
	void setplay(bool b) { play = b; }
	void setposx(int x) { posx = x; }
	void setposy(int y) { posy = y; }
	void setlocations(int a, int b, string s) {locations[a][b] = s; }

	// getters for map variables
	string getlocations(int x, int y) { return locations[x][y]; }
	int getposx() { return posx; }
	int getposy() { return posy; }
	bool getplay() { return play; }
	int getmoves() { return moves; }
	int getinc() { return inc;}

	// map functions to move, and check win
	void move();
	void north();
	void south();
	void east();
	void west();
	void checkwin();

};

