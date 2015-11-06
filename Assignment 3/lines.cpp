#include "graphlib.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <cassert>
#include <stdlib.h>
using namespace std;										//PART ONE BEGINS HERE - LINE FUNCTION DEFINING------------------------------

bool plotHorizontalLine(int r, int c, int length, char ch)		// fcn for horizontal lines
{							
	int n = c;
	int b;
	for (int a = 0; a <= length; a++)		//simple loop for determining length; THIS ALL IS REPEATED 8 TIMES FOLLOWING for each function horiz/vert, fg/bg, reverse/fwd
	{
		if (n > 30 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n++;
	}
	n = c;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			setChar(r, n, ch);
			n++;
		}
		return true;
	}
}

bool plotReverseHorizontalLine(int r, int c, int length, char ch)	// fcn for horizontal lines in reverse direction
{
	int n = c;
	int b;
	for (int a = 0; a <= length; a++)
	{
		if (n > 30 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n--;
	}
	n = c;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			setChar(r, n, ch);
			n--;
		}
		return true;
	}
}

bool plotVerticalLine(int r, int c, int length, char ch)	//fcn for vertical lines in the downward direction
{
	int n = r;
	int b;
	for (int a = 0; a <= length; a++)
	{
		if (n > 20 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n++;
	}
	n = r;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			setChar(n, c, ch);
			n++;
		}
		return true;
	}
}

bool plotReverseVerticalLine(int r, int c, int length, char ch)		//fcn for vertical lines in the upward direction
{
	int n = r;
	int b;
	for (int a = 0; a <= length; a++)
	{
		if (n > 20 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n--;
	}
	n = r;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			setChar(n, c, ch);
			n--;
		}
		return true;
	}
}


																//another four functions that plot the lines; this is for when fgbg = BG
bool plotBGHorizontalLine(int r, int c, int length, int ch)		//begins here ------------------------------------------
{
	{
		int n = c;
		int b;
		for (int a = 0; a <= length; a++)
		{
			if (n > 30 || n < 1)
			{
				b = 0;
				return false;
			}
			else
				b = 1;
			n++;
		}
		n = c;
		if (b)
		{
			for (int a = 0; a <= length; a++)
			{
				if (getChar(r, n) == ' ')
					setChar(r, n, ch);
				n++;
			}
			return true;
		}
	}
}

bool plotBGReverseHorizontalLine(int r, int c, int length, char ch)
{
	int n = c;
	int b;
	for (int a = 0; a <= length; a++)
	{
		if (n > 30 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n--;
	}
	n = c;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			if (getChar(r, n) == ' ')
				setChar(r, n, ch);
			n--;
		}
		return true;
	}
}

bool plotBGVerticalLine(int r, int c, int length, char ch)
{
	int n = r;
	int b;
	for (int a = 0; a <= length; a++)
	{
		if (n > 20 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n++;
	}
	n = r;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			if (getChar(n, c) == ' ')
				setChar(n, c, ch);
			n++;
		}
		return true;
	}
}

bool plotBGReverseVerticalLine(int r, int c, int length, char ch)
{
	int n = r;
	int b;
	for (int a = 0; a <= length; a++)
	{
		if (n > 20 || n < 1)
		{
			b = 0;
			return false;
		}
		else
			b = 1;
		n--;
	}
	n = r;
	if (b)
	{
		for (int a = 0; a <= length; a++)
		{
			if (getChar(n, c) == ' ')
				setChar(n, c, ch);
			n--;
		}
		return true;
	}												//4 fcns that plot lines for BG ends here--------------------------------------------
}


const int HORIZ = 0;
const int VERT = 1;
																	//PART 2 BEGINS HERE - withinBounds function determines if plots inbound
const int BG = 0;
const int FG = 1;

int random = 10;

bool withinBounds(int r, int c, int dir, int distance)		
{						
	int n;						//fcn that determines if the plot will be within bounds; returns true if it is, returns false if it doesnt
	if (dir == HORIZ)
	{
		if (distance >= 0)
		{
			n = c;
			for (int a = 0; a <= distance; a++)
			{
				if (r > 20 || r < 1 || n > 30 || n < 1)			// loop is identical to the plothoriz/verticalLine loop, except this just checks the conditions
				{
					return false;
				}
				n++;
			}
		}
		else if (distance < 0)
		for (int a = 0; a <= abs(distance); a++)
		{
			n = c;
			if (r > 20 || r < 1 || n > 30 || n < 1)
			{
				return false;
			}
			n--;
		}
		return true;
	}
	else if (dir == VERT)
	{
		if (distance >= 0)
		{
			n = r;
			for (int a = 0; a <= distance; a++)
			{
				if (n > 20 || n < 1 || c > 30 || c < 1)
				{
					return false;
				}
				n++;
			}
		}
		else if (distance < 0)
		{
			n = r;
			for (int a = 0; a <= abs(distance); a++)
			{
				if (n > 20 || n < 1 || c > 30 || c < 1)
				{
					return false;
				}
				n--;
			}
		}
		return true;
	}
}
																		//PART 3 BEGINS HERE	
																		//PLOTLINE FUNCTION

bool plotLine(int r, int c, int dir, int distance, char plotChar, int fgbg)	
{
	
	int b = 2;															//i more or less used the b's for testing as i changed the fcn to a bool from a void
	if (dir == VERT || dir == HORIZ)
	{
		if (isprint(plotChar))
		{
			if (fgbg == FG || fgbg == BG)
			{
				if (withinBounds(r, c, dir, distance))			//checks each condition - if VERT/HORIZ, if isprint, if FG/BG, if within bounds - before plotting
				{
					if (b)													
					{
						if (fgbg == FG)
						{
							if (dir == VERT)
							{
								if (distance >= 0)								//if conditions are satisfied, plots from one of the eight functions
								{
									plotVerticalLine(r, c, distance, plotChar);
								}
								else if (distance < 0)
								{
									plotReverseVerticalLine(r, c, abs(distance), plotChar);
								}
							}
							else if (dir == HORIZ)
							{
								if (distance >= 0)
								{
									plotHorizontalLine(r, c, distance, plotChar);
								}
								else if (distance < 0)
								{
									plotReverseHorizontalLine(r, c, abs(distance), plotChar);
								}
							}
						}
						else if (fgbg == BG)
						{
							if (dir == VERT)
							{
								if (distance >= 0)
								{
									plotBGVerticalLine(r, c, distance, plotChar);
								}
								else if (distance < 0)
								{
									plotBGReverseVerticalLine(r, c, abs(distance), plotChar);
								}
							}
							else if (dir == HORIZ)
							{
								if (distance >= 0)
								{
									plotBGHorizontalLine(r, c, distance, plotChar);
								}
								else if (distance < 0)
								{
									plotBGReverseHorizontalLine(r, c, abs(distance), plotChar);
								}
							}
						}
					}
					b = 1;
					return b;
				}
			}
		}
	}
	else 
	{
		b = 0;
		return b;
	}

																				//PART 4 BEGINS HERE
}																				//executecommands function; sorry it doesnt really work.

int executeCommands(string commandString, char& plotChar, int& mode, int& badPos)
{

	
	
	int length;
	int r = 1;
	int c = 1;
	int returner = 3;
		for (int k = 0; k != commandString.size(); k++)				
		{
			if (commandString[k] == 'H' || commandString[k] == 'h')				//if the character is H or h
			{
				if (commandString[k + 1] == '-')			//checks second digit if its -; if not, goes to the digit below marked as XXXXXX in comments
				{
					if (isdigit(commandString[k + 2]))		//checks digit after if it is a digit
					{
						if (isdigit(commandString[k + 3]))	//checks digit after that if it is a digit (for two digit numbers and one digit numbers with a zero in the tens)
						{
							length = strtol(commandString.substr(k + 2, k + 3).c_str(), NULL, 0);	// takes the digit values and puts them into length for the plotting
							if (withinBounds(r, c, HORIZ, -length))
							{
								plotLine(r, c, HORIZ, -length, plotChar, mode);				//^^^^^ this all is repeated for vertical
								c = c - length;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 0;
							}
							else
							{
								badPos = k;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 2;
							}
						}
						else
						{
							length = commandString[k + 2];
							if (withinBounds(r, c, HORIZ, -length))
							{
								plotLine(r, c, HORIZ, -length, plotChar, mode);
								c = c - length;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 0;
							}
							else
							{
								badPos = k;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 2;
							}
						}
					}
					else
					{
						badPos = k + 2;
						if (returner != 0 && returner != 1 && returner != 2)
							returner = 1;
					}

				}																		//XXXXXXXXXXXXXXxXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
				else if (isdigit(commandString[k + 1]))
				{
					if (isdigit(commandString[k + 2]))
					{
						length = strtol(commandString.substr(k + 1, k + 2).c_str(), NULL, 0);
						if (withinBounds(r, c, HORIZ, length))
						{
							plotLine(r, c, HORIZ, length, plotChar, mode);
							c = c + length;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 0;
						}
						else
						{
							badPos = k;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 2;
						}
					}
					else
					{
						length = commandString[k + 1];
						if (withinBounds(r, c, HORIZ, length))
						{
							plotLine(r, c, HORIZ, length, plotChar, mode);
							c = c + length;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 0;
						}
						else
						{
							badPos = k;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 2;
						}
					}
				}
				else
				{
					badPos = k;
					if (returner != 0 && returner != 1 && returner != 2)
						returner = 1;
				}
			}


			else if (commandString[k] == 'V' || commandString[k] == 'v')		//if the character is V or v
			{
				if (commandString[k + 1] == '-')
				{
					if (isdigit(commandString[k + 2]))
					{
						if (isdigit(commandString[k + 3]))									//analogous code repeated from Horizontal section, adapted to veritcal
						{
							length = strtol(commandString.substr(k + 2, k + 3).c_str(), NULL, 0);
							if (withinBounds(r, c, VERT, -length))
							{
								plotLine(r, c, VERT, -length, plotChar, mode);
								r = r - length;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 0;
							}
							else
							{
								badPos = k;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 2;
							}
						}
						else
						{
							length = commandString[k + 2];
							if (withinBounds(r, c, VERT, -length))
							{
								plotLine(r, c, VERT, -length, plotChar, mode);
								r = r - length;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 0;
							}
							else
							{
								badPos = k;
								if (returner != 0 && returner != 1 && returner != 2)
									returner = 2;
							}
						}
					}
					else
					{
						badPos = k + 2;
						if (returner != 0 && returner != 1 && returner != 2)
							returner = 1;
					}

				}
				else if (isdigit(commandString[k + 1]))
				{
					if (isdigit(commandString[k + 2]))
					{
						length = strtol(commandString.substr(k + 1, k + 2).c_str(), NULL, 0);
						if (withinBounds(r, c, VERT, length))
						{
							plotLine(r, c, VERT, length, plotChar, mode);
							r = r + length;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 0;
						}
						else
						{
							badPos = k;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 2;
						}
					}
					else
					{
						length = commandString[k + 1];
						if (withinBounds(r, c, VERT, length))
						{
							plotLine(r, c, VERT, length, plotChar, mode);
							r = r + length;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 0;
						}
						else
						{
							badPos = k;
							if (returner != 0 && returner != 1 && returner != 2)
								returner = 2;
						}
					}
				}
				else
				{
					badPos = k;
					if (returner != 0 && returner != 1 && returner != 2)
						returner = 1;
				}
			}


			else if (commandString[k] == 'F' || commandString[k] == 'f')	//if the character is F or f for changing mode to FG
			{
				mode = FG;
				if (isprint(commandString[k + 1]))						//if F is the character, changes the mode to FG, then checks isprint for next character
				{														// and changes the character if isprint is true
					plotChar = commandString[k + 1];
					if (returner != 0 && returner != 1 && returner != 2)
						returner = 0;
					k++;												// to avoid checking the k+1 on the next iteration of the loop, because it may be a valid commandstarter
				}
				else
				{
					badPos = k;
					if (returner != 0 && returner != 1 && returner != 2)
						returner = 1;
				}

			}
			else if (commandString[k] == 'B' || commandString[k] == 'b')	//if the character is B or b for changing mode to BG
			{
				mode = BG;
				if (isprint(commandString[k + 1]))
				{
					plotChar = commandString[k + 1];						//code for 'f' repeated here
					if (returner != 0 && returner != 1 && returner != 2)
						returner = 0;
					k++;
				}
				else
				{
					badPos = k;
					if (returner != 0 && returner != 1 && returner != 2)
						returner = 1;
				}
			}
			else if (commandString[k] == 'C' || commandString[k] == 'c')	//if the character is c or C for cleargrid
			{
				clearGrid();
				if (returner != 0 && returner != 1 && returner != 2)
					returner = 0;
			}
			else
			{															// if the character is not valid (none of the above cases)
				badPos = k;
				if (returner != 0 && returner != 1 && returner != 2)
					returner = 1;
			}
			if (returner == 0 || returner == 1 || returner == 2)
				return returner;
		}
		
					

	
}																//PART 5
																// main function
int main()
{
	clearGrid();
	char currentChar = '*';
	int currentMode = FG;
	for (;;)
	{
		cout << "Enter a command string: ";
		string cmd;
		getline(cin, cmd);
		if (cmd == "")
			break;
		int position;
		int status = executeCommands(cmd, currentChar, currentMode, position);
		switch (status)
		{
		case 0:
			draw();
			break;
		case 1:
			cout << "Syntax error at position " << position + 1 << endl;
			break;
		case 2:
			cout << "Cannot execute command at position " << position + 1 << endl;
			break;
		default:
			// It should be impossible to get here.
			cerr << "executeCommands returned " << status << "!" << endl;
		}
	}
}