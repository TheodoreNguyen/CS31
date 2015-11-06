#include <iostream>			// Theodore Nguyen
#include <string>
#include <cmath>			// please read from bottom up! Sorry, it was more convinient to have the fcns ordered backwards
#include <cassert>
using namespace std;

int tally(const string a[], int n, string target);
int findLast(const string a[], int n, string target);
bool findFirstSequence(const string a[], int n, string target, int& begin, int& end);
int positionOfMin(const string a[], int n);
int getIndexOfSmallestElement(int arr[], int size);
int moveToEnd(string a[], int n, int pos);
int moveToBeginning(string a[], int n, int pos);
int disagree(const string a1[], int n1, const string a2[], int n2);
int removeDups(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int mingle(const string a1[], int n1, const string a2[], int n2,
	string result[], int max);
int divide(string a[], int n, string divider);

int main()
{
	string h[7] = { "peter", "lois", "meg", "chris", "", "meg", "stewie" };
	assert(tally(h, 7, "meg") == 2);
	assert(tally(h, 7, "") == 1);
	assert(tally(h, 7, "quagmire") == 0);
	assert(tally(h, 0, "meg") == 0);
	assert(findLast(h, 7, "meg") == 5);
	assert(findLast(h, 2, "meg") == -1);
	int bg;
	int en;
	assert(findFirstSequence(h, 7, "chris", bg, en) && bg == 3 && en == 3);

	string g[4] = { "peter", "lois", "chris", "stewie" };
	assert(positionOfMin(g, 4) == 2);
	assert(disagree(h, 4, g, 4) == 2);
	assert(subsequence(h, 7, g, 4));
	assert(moveToEnd(g, 4, 1) == 1 && g[1] == "chris" && g[3] == "lois");

	string f[4] = { "chris", "stewie", "meg", "lois" };
	assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "meg" && f[2] == "stewie");

	string e[5] = { "chris", "chris", "chris", "meg", "meg" };
	assert(removeDups(e, 5) == 2 && e[1] == "meg");

	string x[4] = { "brian", "lois", "lois", "quagmire" };
	string y[4] = { "chris", "lois", "meg", "stewie" };
	string z[10];
	assert(mingle(x, 4, y, 4, z, 10) == 8 && z[5] == "meg");

	assert(divide(h, 7, "meg") == 3);

	cout << "All tests succeeded" << endl;
}


int divide(string a[], int n, string divider)
{
	if (n < 0)
		return -1;
	for (int k = 0; k < n; k++)
	{
		string minimum = a[k];
		int position = k;
		int z = k;
		while (z < n - 1)
		{
			if (minimum > a[z + 1])		//does the rearrangement for the function
			{
				minimum = a[z + 1];
				position = z + 1;
			}
			z++;
		}
		string random = a[k];
		a[k] = a[position];
		a[position] = random;
	}
	for (int k = 0; k < n; k++)
	{
		if (a[k] >= divider)	//satisfies the returning to the function
			return k;
	}
	return n;
}


int mingle(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
	if (n1 + n2 > max)
		return -1;
	if (n1 < 0 || n2 < 0)
		return -1;
	int z1 = 0, z2 = 0;
	for (int k = 0; k < n1 + n2 - 1; k++)
	{
		if (a1[z1] <= a2[z2])	//assigns string values to the result array if they are declared smaller
		{
			result[k] = a1[z1];
			z1++;
		}
		else
		{						//will be rewritten in the next iteration of loop if the sequentialness isnt satisfied
			result[k] = a2[z2];
			z2++;
		}
	}
	if (z2 == n2 - 1)
		result[n1 + n2 - 1] = a2[n2 - 1];
	else
		result[n1 + n2 - 1] = a1[n1 - 1];
	return n1 + n2;
}

bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
	string z1[10000];
	string z2[10000];
	for (int k = 0; k != n1; k++)	//creates alternate and identical arrays since the givens are not modifiable
		z1[k] = a1[k];
	for (int k = 0; k != n2; k++)
		z2[k] = a2[k];
	int N1 = removeDups(z1, n1);	//removes duplicates 
	int N2 = removeDups(z2, n2);
	int numberOfLittlesInBig = 0;
	for (int k = 0; k != N1; k++)
	{
		for (int z = numberOfLittlesInBig; z != N2; z++)	
		{
			if (z1[k] == z2[z])
			{
				numberOfLittlesInBig++;			//counts the number of times the small loop element appears in the big loop
			}
		}
	}
	if (numberOfLittlesInBig == N2)
		return true;
	else
		return false;
}

int removeDups(string a[], int n)
{
	if (n < 0)
		return -1;
	int numberRemoved = 0;
	for (int k = 0; k != n - numberRemoved -1; ) 
	{
		if (a[k] == a[k + 1])
		{
			numberRemoved++;
			moveToEnd(a, n, k);	//moving to the end "removes" duplicates from the "applicable" array
		}
		else
			k++;				// will only increment when there is no duplicate to remove
	}
	return n - numberRemoved;
}

int disagree(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)
		return -1;
	for (int k = 0; k != n1 && k != n2; k++)
	{
		if (a1[k] != a2[k])	// returns position if and when they disagree
			return k;
		if (k == n1 - 1)	// returns position number if they don't disagree; the smaller array will enter the if statement first
			return n1;
		if (k == n2 - 1)
			return n2;
	}
	return 0; 
}


int moveToBeginning(string a[], int n, int pos)
{
	if (n < 0)
		return -1;
	string store = a[pos];
	for (int k = n - 1; k != -1; k--)		//nearly identical to moveToEnd, except opposite
	{
		if (k <= pos && k != 0)
			a[k] = a[k - 1];
	}
	a[0] = store;
	return pos;
}


int moveToEnd(string a[], int n, int pos)		
{
	if (n < 0)
		return -1;
	string store = a[pos];				// store the pos to be moved 
	for (int k = 0; k != n; k++)
	{
		if (k >= pos && k != (n - 1))	// write over the pos
			a[k] = a[k + 1];
	}
	a[n - 1] = store;				//tack on the stored pos at the end
	return pos;
}

int positionOfMin(const string a[], int n)
{
	if (n <= 0)
		return -1;
	int k = 0;
	for (int z = k; z < n; z++)
	{
		if (a[k]> a[z])
			k = z;		//sets k = z each time a[k] > a[z], so k will only take on z, which has smallest a[z] value
	}					
	return k;
}

bool findFirstSequence(const string a[], int n, string target, int& begin, int& end)
{
	if (n < 0)
		return false;
	int first = -1;
	for (int k = 0; k != n; k++)
	{
		if (a[k] == target)
		{
			if (first == -1)		//first defines the first time target string is found. 
			{						//first will remain -1 unless target string is found
				first = k;
				begin = k;	// sets end to k in case the sequence of target string is only one in length
				end = k;
			}
			else if (first != -1)
			{
				end = k;
				if (a[k + 1] != target)	//leave for loop after end of first sequence
					break;
			}
		}
	}
	if (first != -1)
		return true;
	else
		return false;
}

int findLast(const string a[], int n, string target)
{
	if (n < 0)
		return -1;
	int runningPosition = -1;
	for (int k = 0; k != n; k++)
	{
		if (a[k] == target)
		{
			runningPosition = k;		//nearly identical code to tally function; sets the position every time finding the target string
		}
	}
	return runningPosition;
}


int tally(const string a[], int n, string target)
{
	if (n < 0)
		return -1;
	int runningTotal = 0;
	for (int k = 0; k != n; k++)
	{
		if (a[k] == target)
		{
			runningTotal++;			//increments each time the target string is found to give the tally
		}
	}
	return runningTotal;
}