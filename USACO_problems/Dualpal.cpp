/*
daniel_g1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>  
#include <string.h>
#include <assert.h>
#include <ctype.h>

using namespace std;

void numbconv(char *s, int n, int b, int *input_len)
{
	int len;
    if(n == 0) {
		strcpy(s, "");
		return;
    }

    /* figure out first n-1 digits */
    numbconv(s, n/b, b, &len);

    /* add last digit */
    len = strlen(s);
    s[len] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n%b];
    s[len+1] = '\0';
  	*input_len=strlen(s);  
}

int Compare (char *s, int len)
{
	for (int i = 0; i < len/2; i++)
	{
		if (s[i] != s[len-i-1])
			return 0;
	}
	return 1;
}

int main()
{
    char s[40];
    char t[40];
    int N, inS, base = 2, len, number, counter = 0;
    bool first_matched = false, second_matched = false;
	ifstream fin ("dualpal.in");
	ofstream fout ("dualpal.out");
	fin >> N;
	fin >> inS;
	for (int i = inS+1; true; i++)  //number loop
	{
		first_matched = false;
		second_matched = false;
		number = 0;
		base = 2;
		while (base <=10 && !second_matched)  //base loop
		{
			numbconv(s, i, base, &len);
			if (Compare(s, len))
			{
				if (first_matched && number == i)
				{
					cout << number << endl;
					fout << number << endl;
					second_matched = true;
				}
				else 
				{
					number = i;
					first_matched = true;
				}
				if (second_matched)
				{
					counter++;
					break;
				}
			}
			base++;
		}
		if (counter == N)
			break;
	}
	
}

