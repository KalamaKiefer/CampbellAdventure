#pragma once
#include <iostream>


using namespace std;

class Help
{
protected:
	string helpkey = "";

public:

	string gethelp() { return helpkey; }

	void sethelp(string h) { helpkey = h; }

	// friend operator used to output help message every time its called
	friend ostream& operator <<(ostream& out, const Help& h);

	Help();


};