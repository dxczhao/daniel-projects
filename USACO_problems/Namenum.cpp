/*
daniel_g1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void Convert (string *names, string *namenum, int ls);

int Compare (string *namenum, int ls, string number, int *match);

int main ()
{
	int ls, match[5000], N;
	string names[5000], namenum [5000], number;
	ifstream fin1 ("dict.txt");
	ifstream fin2 ("namenum.in");
	ofstream fout ("namenum.out");
	fin2 >> number;
	for (int i = 0; i < 5000; i++)
	{
		fin1 >> names[i];
		if (names[i] == "")
		{
			ls = i;
			break;
		}
		//cout << names[i] << endl;
	}	
	for (int i = 0; i < ls; i++)
		namenum[i] = names[i];
	cout << ls << endl;
	cout << number;
	Convert (names, namenum, ls);
	N = Compare (namenum, ls, number, match);
	cout << endl;
	cout << N << endl;
	for (int i = 0; i < N; i++)
	{
		cout << names[match[i]] << endl;
		fout << names[match[i]] << endl;
	}
	if (!N)
		fout << "NONE" << endl;
}

void Convert (string *names, string *namenum, int ls)
{
	for (int i = 0; i < ls; i++)
	{
		for (int j = 0; j < names[i].length(); j++)
		{
			if (names[i][j] == 'A' || names[i][j] == 'B' || names[i][j] == 'C')
				namenum[i][j] = '2';
			else if (names[i][j] == 'D' || names[i][j] == 'E' || names[i][j] == 'F')
				namenum[i][j] = '3';
			else if (names[i][j] == 'G' || names[i][j] == 'H' || names[i][j] == 'I')
				namenum[i][j] = '4';
			else if (names[i][j] == 'J' || names[i][j] == 'K' || names[i][j] == 'L')
				namenum[i][j] = '5';
			else if (names[i][j] == 'M' || names[i][j] == 'N' || names[i][j] == 'O')
				namenum[i][j] = '6';
			else if (names[i][j] == 'P' || names[i][j] == 'R' || names[i][j] == 'S')
				namenum[i][j] = '7';
			else if (names[i][j] == 'T' || names[i][j] == 'U' || names[i][j] == 'V')
				namenum[i][j] = '8';
			else if (names[i][j] == 'W' || names[i][j] == 'X' || names[i][j] == 'Y')
				namenum[i][j] = '9';
		}
	}
}

int Compare (string *namenum, int ls, string number, int *match)
{
	int N = 0;
	for (int i = 0; i < ls; i++)
	{
		if (namenum[i].compare(number) == 0)
			match[N++] = i;
	}
	return N;
}
