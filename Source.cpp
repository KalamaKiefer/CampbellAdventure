#include <iostream>
#include <string>
#include "Help.h"
#include "Character.h"
#include "Inventory.h"
#include "Map.h"

using namespace std;

// objects 
Character user;
Map map;
Inventory backpack;
string pickit = "";
string answer1 = "";

int main()
{
	string player = " ";
	string use = " ";
	string purchase = " ";
	Help user1;
	bool p = true;
	

	cout << "Hello! Welcome to Crazy Campbell(highschool) Adventure! \n";
	cout << "-------------------------------------------------------- \n";
	cout << "It is the first day of school at Campbell Highschool, the first day of your freshman year!\n\n";
	cout << "Your objective is to walk to school and make it to your first class... ALIVE!!! \n\n";
	cout << "Ewa Beach, Oahu can be a very treateruous place.\n\nThe path to school is a";
	cout << " perilous one, so you must be concious of your health!\n\n";
	cout << "There are many things in this game that can take away your health!\n\n";
	cout << "The sun, dehydration, hunger, and even other characters...\n\n"; 
	cout << "You will be awarded points for visiting different areas in the map, picking up objects, and acomplishing tasks.\n\n";
	cout << "If at any time during the game you get lost you can always type help to get a list of commands you could use.\n\n";
	cout << "What is your name young student?\n";
	getline(cin, player); // gets players name
	user.setname(player);
	cout << "\n";
	cout << "Well then " << user.getname();
	cout << " are you ready to start your journey?! \n";
	

Start:
	getline(cin, answer1);
	cout << " \n";

	if (answer1 == "yes" || answer1 == "Yes" || answer1 == "y" || answer1 == "Y")
	{
		cout << "You have just walked outside of your house, it is a really hot day.\n";
		cout << "Right in front of you is the hawaiian prince golf course. Which direction do you want to go?\n\n";

		while (map.getplay()) // runs a loop till the game is over
		{
				answer1 = " ";
			Play:
				map.checkwin(); // checks if the user won
				 // checks if users health = 0
				user.damage(); // implements damage on user after certain amount of moves
				cin >> answer1;
				if (answer1 == "north" || answer1 == "North" || answer1 == "N" || answer1 == "n") // checks the users input
				{
					map.north(); // subtracts 1 from the users x position
					if (map.getposx() < 0) // outputs messages if the x position does not exist in the array
					{
						if (map.getposy() == 4)
						{
							cout << "I guess you didn't listen and tried to go through the construction to get to school..\n";
							cout << "Poor kid, death by jackhammer.\n\n";
							map.setplay(false);
						}
						else if (map.getposy() == 3)
						{
							cout << "Congrats, you have fell in the chasm and died.. oh well you were warned.\n\n";
							map.setplay(false);
						}
						else if (map.getposy() == 2)
						{
							cout << "You walk straight into the entrance of a construction zone. The construction workers need help and you are young.\n";
							cout << "Congrats you just got yourself a job, and a job means money..\n\n";
							backpack.setmoney(30);
							backpack.add("money");
							map.setposx(0);
							map.setposy(1);
						}
						else if (map.getposy() == 1)
						{
							cout << "You walk straight through the golf course and dont notice the lake ahead, you fall into the lake,\n";
							cout << "You try to swim out only to find out that the golf courses alligator is hungry. Better luck next time..\n\n";
							map.setplay(false);
						}
						else if (map.getposy() == 0)
						{
							cout << "You continue to walk straight regardless of seeing the big whole in the ground.\n";
							cout << "You fall in the whole and break both your legs.. Your new objective is finding a hospital, you lose.\n\n";
							map.setplay(false);
						}
					}
					else {
						map.move(); // outputs the appropriate message with the players x and y value
					}
				} // ends north
				else if (answer1 == "south" || answer1 == "South" || answer1 == "S" || answer1 == "s")
				{
					map.south();
					if (map.getposx() > 4)
					{
						if (map.getposy() == 4)
						{
							cout << "You jump off the cliff with pride and curiosity and dive into the black hole.\n";
							cout << "You see your life flash before your eyes and all of a sudden..\n\n";
							user.setpoints(1000);
							map.setposx(2);
							map.setposy(3);
							cout << map.getlocations(2, 3);

						}
						else if (map.getposy() == 3)
						{
							cout << "You walk past the basketball court and a wild boar comes up out of nowhere and stabs you in the heart with its tusks.\n";
							cout << "Man you are unlucky.\n\n";
							map.setplay(false);
						}
						else if (map.getposy() == 2)
						{
							cout << "Your mom is driving out of town to go to work and sees you all the way out here.\n";
							cout << "She takes you back to where you started because she does not have enough time to drop you to school.\n\n";
							map.setposx(2);
							map.setposy(3);
							cout << map.getlocations(2, 3);
						}
						else if (map.getposy() == 1)
						{
							cout << "Instead of getting on the bus you walk in front of it and it runs you over..\n";
							cout << "Watch where you are going next time.\n\n";
							map.setplay(false);
						}
						else if (map.getposy() == 0)
						{
							cout << "You walk right on into Waipahu, wearing your Campbell High School uniform..\n";
							cout << "Not a very smart idea, you are mugged on sight. Now you must make a trip to the hospital, no school today.\n\n";
							map.setplay(false);
						}
					}
					else {
						map.move();
					}
				} // ends south
				else if (answer1 == "east" || answer1 == "East" || answer1 == "E" || answer1 == "e")
				{
					map.east();
					if (map.getposy() > 4)
					{
						if (map.getposx() == 4)
						{
							cout << "You dive over the cliff but too far to the right!\n";
							cout << "You miss the black hole and end up falling to your death.To bad your aim wasnt better.\n\n";
							map.setplay(false);
						}
						else if (map.getposx() == 3)
						{
							cout << "You turn right at foodland and catch the bus!\n";
							cout << "Well.. more like the bus catches you.. You got ran over..\n\n";
							map.setplay(false);
						}
						else if (map.getposx() == 2)
						{
							cout << "You turn right to go to safeway but get run over.\n";
							cout << "Maybe look both ways when crossing a really busy intersection..\n\n";
							map.setplay(false);
						}
						else if (map.getposx() == 1) // pick up knife
						{
							cout << "You walk into the big park and see a knife on the ground, You decide you should'nt be here much longer..\n";
							
								map.setposx(1);
								map.setposy(4);
							
						}
						else if (map.getposx() == 0)
						{
							// map(0,5) doesnt exist
							cout << "You have gone right, pass the 711 and it leads into an alley way next to the taco bell.\n";
							cout << "All of a sudden a homeless man walks up behind you and tells you to give him all your money!\n\n";
							cout << "What do you do!\n";
							answer1 = " ";
							cin >> answer1;
							cout << "\n";
							if (answer1 == "north" || answer1 == "North" || answer1 == "N" || answer1 == "n")
							{
								cout << "You try to run north past the guy but he stops you, the man kills you and takes your things.\n";
								cout << "Maybe next time dont go into an alley way without a weapon..\n\n";
								map.setplay(false);
							} // ends north
							else if (answer1 == "south" || answer1 == "South" || answer1 == "S" || answer1 == "s")
							{
								cout << "You try turn around and run behimd you but you just run into the wall, the man kills you and takes your things.\n";
								cout << "Maybe next time dont go into an alley way without a weapon..\n\n";
								system("pause");
								return 0;

							} // ends south
							else if (answer1 == "east" || answer1 == "East" || answer1 == "E" || answer1 == "e")
							{
								cout << "You try to turn right but there is a dumpster in your way, the man kills you and takes your things.\n";
								cout << "Maybe next time dont go into an alley way without a weapon..\n\n";
								system("pause");
								return 0;

							} // ends east
							else if (answer1 == "west" || answer1 == "West" || answer1 == "W" || answer1 == "w")
							{
								cout << "You try to turn left but there is nothing but a brick wall thats at least 12 feet high, the man kills you and takes your things.\n";
								cout << "Maybe next time dont go into an alley way without a weapon..\n\n";
								system("pause");
								return 0;

							}
							else if (answer1 == "use" || answer1 == "Use")
							{
								pickit = " ";
								cout << "What do you want to use?\n";
								cin >> pickit;
								cout << "\n";

								backpack.use(pickit);
								if (backpack.gethave())
								{
									if (pickit == "Knife" || pickit == "knife")
									{
										cout << "You stab the homeless man and run back to the 711.\n";
										cout << "Good thing you picked up that knife, although i dont suggest going back.\n";
										cout << "You still stabbed someone and the cops are on the scene.\n\n";
										user.setpoints(10000);
										map.setposx(0);
										map.setposy(4);

										cout << map.getlocations(0, 4);

									}
								}
								else
								{
									cout << "You look for something to use against the man but you have no weapons.\n";
									cout << "The man kills you for the things you do have in your backpack..\n";
									cout << "Maybe next time dont go into an alley way without a weapon..\n\n";
									map.setplay(false);
								}
							}
							else
							{
								goto Play;
							}
						}
					}
					else {
						map.move();
					}
				} // ends east
				else if (answer1 == "west" || answer1 == "West" || answer1 == "W" || answer1 == "w")
				{
					map.west();
					if (map.getposy() < 0)
					{
						if (map.getposx() == 4)
						{
							cout << "You try to turn left to avoid waipahu and dont see the onslaught of runners coming your way.\n";
							cout << "Cause of death.. human stampede.\n\n";
							map.setplay(false);

						}
						else if (map.getposx() == 3) // 711 store where you can buy things
						{
							cout << "You have entered the 711. Would you like to purchase anything?\n";
							cout << "You can buy sunscreen for 5 dollars, food for 10 dollars, and water for 5 dollars.\n";
							while (p)
							{
								purchase = " ";
								cin >> purchase;

								if (purchase == "sunscreen")
								{
									backpack.buy(purchase);
								}
								else if (purchase == "water")
								{
									backpack.buy(purchase);
								}
								else if (purchase == "food")
								{
									backpack.buy(purchase);
								}
								else if (purchase == "exit")
								{
									map.setposx(3);
									map.setposy(0);
									cout << map.getlocations(3, 0);

									p = false;
								}
								else
								{
									cout << "Please type water, food, or sunscreen to buy one of these products.\n";
									cout << "Or type exit to leave the store.\n\n";
								}
							} // ends p while
						}
						else if (map.getposx() == 2)
						{
							cout << "You turn left into a neighborhood in a sketchy part of town.. not very smart.\n";
							cout << "You are immediately arrested by the police!\n";
							cout << "You just so happen to walk into an undercover police officer that thought you were selling drugs in this neighborhood.\n";
							cout << "You are going to jail punk..\n\n";
							map.setplay(false);
						}
						else if (map.getposx() == 1) // different ending, pokemon
						{
							cout << "You walk left across the park and notice and notice a little ball lying in the grass.\n";
							cout << "Do you want to pick it up?\n";
							while (backpack.getpoke())
							{
								pickit = " ";
								cin >> pickit;
								if (pickit == "yes" || pickit == "Yes")
								{
									backpack.add("pokeball");
									cout << "You have picked up this peculiar looking ball, it looks like a pokeball..?\n\n";
									map.setposx(1);
									map.setposy(0);
									cout << map.getlocations(1, 0);
									backpack.setpoke(false);
								}
								else if (pickit == "no" || pickit == "No")
								{
									cout << "You decide to walk away from it..\n\n";
									map.setposx(1);
									map.setposy(0);
									cout << map.getlocations(1, 0);
									backpack.setpoke(false);
								}
								else {
									cout << "Please enter yes or no.\n\n";
								}
							}
						}
						else if (map.getposx() == 0)
						{
							cout << "You stare at the big hole in the ground, you know theres construction going on.\n";
							cout << "So you try to go around it by going left, only to get slammed with a wrecking ball!\n";
							cout << "Better luck next time, remember to look both ways before crossing a construction zone.\n\n";
							map.setplay(false);
						}
					}
					else {
						map.move();
					}
				} // ends west 
				else if (answer1 == "help" || answer1 == "Help")
				{
					cout << user1;
					goto Play;
				}
				else if (answer1 == "points" || answer1 == "Points")
				{
					cout << "You have: " << user.getpoints() << " Points!\n\n";
					goto Play;
				}
				else if (answer1 == "Health" || answer1 == "health")
				{
					cout << "Your health is at: " << user.gethealth() << "%" << " \n\n";
					goto Play;
				}
				else if (answer1 == "backpack" || answer1 == "Backpack")
				{
					backpack.showarray();
					goto Play;
				}
				else if (answer1 == "get" || answer1 == "grab")
				{
				cout << "What do you want to get?\n";
				pickit = " ";
				cin >> pickit;
				cout << "\n";
				backpack.get();
				goto Play;
				}
				else if (answer1 == "use" || answer1 == "Use")
				{
					cout << "What do you wish to use?\n";
					pickit = " ";
					cin >> pickit;
					cout << "\n";
					backpack.use(pickit);
					cout << "\n";
				}
				else {
					cout << "Please enter a correct command. If you are stuck type help for some command options.\n\n";
					answer1 = " ";
					goto Play;
				}
				user.checkifdead();
		} // ends while
	}
	else if (answer1 == "no" || answer1 == "No")
	{
		cout << "Ok dont play a super fun game..\n";
		system("pause");
		return 0;
	} 
	else {
		cout << "Please enter yes or no.\n";
		goto Start;
	} // ends first if statement 
	
	cout << "You ended with: " << user.getpoints() << " Points!\n\n";

	system("pause");
	return 0;
}

void Map::move() // moves character
{
	setmoves(1);
	cout << locations[posx][posy] << "\n";
	if (getposx() == 1 && getposy() == 1)
	{
		backpack.add("apple");
	}
	else if (getposx() == 4 && getposy() == 1) // different ending
	{
		answer1 = " ";
		cout << "Type yes to get on bus or no to no get on the bus.\n";
		cin >> answer1;
		cout << "\n";
		if (answer1 == "yes" || answer1 == "Yes")
		{
			cout << "The bus takes you directly to school and you arrive on time!\n";
			cout << "Didn't know you were the lazy type, but regardless... You still win.\n\n";
			user.setpoints(500);
			map.setplay(false);
		}
		else if (answer1 == "no" || answer1 == "No")
		{
			cout << "Ok your loss, now you have to walk to school..\n\n";
			map.setposx(4);
			map.setposy(2);
		}
	}
}

void Map::checkwin() // checks if they won
{
	string end = ("You decide to jump a fence and go through Ilima Intermediate to get to Campbell.\n"
		"You have made it to school, and with style!\n"
		"You walk through your old middle school and see all your old friends and teachers.\n\n");
	if (getposx() == 2 && getposy() == 4)
	{
		setinc(1);
	}
	else if (getposx() == 1 && getposy() == 4)
	{
		if (getinc() == 1)
		{
			setinc(1);
		}
	}
	else if (getposx() == 0 && getposy() == 4)
	{
		if (getinc() == 2)
		{
			setlocations(0, 3, end);
			if(map.getmoves() <= 4) // awards player points based off of how many moves it took to beat the game.
			{
				user.setpoints(10000);
			}
		else if (map.getmoves() > 4 && map.getmoves() < 8)
		{
			user.setpoints(5000);
		}
		else if (map.getmoves() > 8 && map.getmoves() < 12)
		{
			user.setpoints(1000);
		}
		else if (map.getmoves() > 12)
		{
			user.setpoints(500);
		}
		setplay(false);
		}
	}
}

void Map::north()
{
		posx--;
}

void Map::south()
{
	posx++;
}

void Map::east()
{
	posy++;
}

void Map::west()
{
	posy--;
}

Inventory::Inventory()
{


}

void Inventory::get()  // gets items and checks if you can add them to your backpack
{
	if (pickit == "knife")
	{
		if (map.getposx() == 1 && map.getposy() == 4 || map.getposx() == 1 && map.getposy() == 0)
		{
			add("knife");
			cout << "You have picked up a knife.\n\n";
			user.setpoints(15);
		}
	}
	else if (pickit == "basketball")
	{
		if (map.getposx() == 3 && map.getposy() == 2)
		{
			add("basketball");
			cout << "You have picked up a basketball.\n\n";
			user.setpoints(10);
		}
	}
	else if (pickit == "pokeball")
	{
	     if (map.getposx() == 1 && map.getposy() < 0)
	     {
		   add("pokeball");
		   user.setpoints(25);
		   setpoke(true);
	     }
	}
	else {
		cout << "There is nothing to get here.\n\n";
		setpoke(false);
	}
}

void Inventory::add(string b) // adds items to your backpack
{
	backpack[plus] = b;
	setplus(1);
}

// shows whats in the inventory
void Inventory::showarray()
{
	for (int i = 0; i < 6; i++)
	{
		if (backpack[i] == " ")
		{
			cout << "You have nothing else in your backpack.\n\n";
			break;
		}
		else if (backpack[i] == "sunscreen") {
			cout << "You have sunscreen in your backpack, stops the sun from damaging you.\n\n";
		}
		else if (backpack[i] == "water")
		{
			cout << "You have water in your backpack, restores 30 health.\n";
		}
		else if (backpack[i] == "food")
		{
			cout << "You have food in your backpack, restores 40 health.\n";
		}
		else if (backpack[i] == "knife")
		{
			cout << "You have a knife in your backpack.\n";
		}
		else if (backpack[i] == "basketball")
		{
			cout << "You have a basketball in your backpack.\n";
		}
		else if (backpack[i] == "apple")
		{
			cout << "You have an apple in your backpack, restores 10 health.\n";
		}
		else if (backpack[i] == "pokeball")
		{
			cout << "You have a pokeball in your backpack.\n";
		}
	}
}

// uses what you type in in your inventory
void Inventory::use(string u)
{
	for (int i = 0; i < 7; i++)
	{
		if (u == backpack[i])
		{
			if (u == "sunscreen")
			{
				user.setsun(0);
			}
			else if (u == "apple")
			{
				user.sethealth(10);
			}
			else if (u == "water")
			{
				user.sethealth(30);
			}
			else if (u == "food")
			{
				user.sethealth(40);
			}
			else if (u == "pokeball")
			{
				cout << "You take the pokeball out of your backpack and throw it on the ground.\n";
				cout << "All of a sudden a giant charizard bursts out of the ball and stands in front of you!!\n";
				cout << "You are its master now, it will fly you to school and burn all of your enemies..\n";
				user.setpoints(1000000);
				map.setplay(false);
			}
			else if (u == "basketball")
			{
				if (map.getposx() == 4 && map.getposy() == 3)
				{
					cout << "You pull out your basketball and shoot some hoops.\n";
					cout << "You had a great time procrastinating and not worrying about how to get to school.\n";
					user.setpoints(10000);
				}
			}
			backpack[i] = " ";
			cout << "You have used: " << u << "\n";
			have = true;
			break;
		}
		if (i == 6)
		{
			cout << "You do not have that item in your backpack.\n\n";
			have = false;
			break;
		}	
	}
}

void Inventory::buy(string m) // checks if you have enough money to buy from the store.
{
	if (m == "sunscreen")
	{
		if (money >= sunscreen)
		{
			add("sunscreen");
			cout << "You have bought sunscreen.\n";
			money = money - sunscreen;
		}
		else {
			cout << "You do not have enough money to buy sunscreen.\n";
		}
	}
	else if (m == "water")
	{
		if (money >= water)
		{
			add("water");
			cout << "You have bought water.\n";
			money = money - water;
		}
		else {
			cout << "You do not have enough money to buy water.\n";
		}
	}
	else if (m == "food")
	{
		if (money >= food)
		{
			add("food");
			cout << "You have bought food.\n";
			money = money - food;
		}
		else {
			cout << "You do not have enough money to buy food.\n";
		}
	}
	
}

void Character::damage() // decrements health every certain amount of moves
{
	seti(1);

	if (i == 8) {
		health = health - sun;
	}
	else if (i == 10)
	{
		health = health - THIRST;
	}
	else if (i == 12)
	{
		health = health - HUNGER;
	}
	else if (i == 15)
	{
		health = health - 10;
	}

	
}
void Character::checkifdead() // checks if you are dead
{
	
	if (health == 0)
	{
		cout << "Your health is now 0, you have died.\n";
		cout << "Remember to type health to check how much health you have left throughout the game.\n\n";
		map.setplay(false);
	}
}



Character::Character()
{


}


Help::Help()
{


}

ostream& operator <<(ostream& out, const Help& h) // help strings
{
	out << "I see you need some help. Here are some key commands you can try using!\n";
	out << "You can type n or north to move north, s or south to move south, w or west to move west, and e or east to move east.\n";
	out << "You can type health to show how much health you have left.\n";
	out << "You can type points to show the amount of points youve accumalated so far.\n";
	out << "If you find something on the ground, you can type get or grab to obtain the object and place it in your backpack.\n";
	out << "You can also type backpack to show whats in your inventory.\n";
	out << "If you wish to use something you have picked up, type use to use something in your backpack.\n\n";

	return out;
}

