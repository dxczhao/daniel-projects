/*
daniel_g1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int Ninty (char **os, char **cs2, char **cs1, int N);

int OneEighty (char **os, char **cs1, char **cs2, int N);

int TwoSeventy (char **os, char **cs2, char **cs1, int N);

int Reflection (char **os, char **cs1, char **cs2, int N);

int Compare (char **os, char **is, int N);

int Rec (char **os, char **is, int N);

int main ()
{
	int N, P, L;
	char **is, **os;
	ifstream fin ("transform.in");
	ofstream fout ("transform.out");
	fin >> N;	
	is=(char **)malloc(sizeof(size_t)*N);
	os=(char **)malloc(sizeof(size_t)*N);

	for (int i=0; i<N; i++)
	{
		is[i]=(char *)malloc(4);
		os[i] =(char *)malloc(4);
	}
	for (int k = 0; k < 2; k++)
	{
 		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (k == 0)
				{
					fin >> is[i][j];
					cout << is[i][j] << " ";
				}
					
				else
				{
					fin >> os[i][j];
					cout << os[i][j] << " ";
				}
			}
			cout << endl;
		}
		
	}	
	
//-----------------------------------------------------------------
	L=Compare(os, is, N);
	P = Rec (os, is, N);
	if (L==1) {
		if (P>6)
			P = 6;
	}

	cout << P;
	fout << P;
	fout << endl;
	cout << endl;
	
	for (int i=0; i<N; i++)
	{
		free (is[i]);
		free (os[i]);
	}	
	free(is);
	free(os);	
}

//-----------------------------------------------------------------

int OneEighty (char **os, char **is, char **cs, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cs[i][j] = is[N-1-i][N-1-j];
			cout << cs[i][j] << " ";
		}
		cout << endl;
	}
	return Compare(os, cs, N);
}

//-----------------------------------------------------------------

int Reflection (char **os, char **is, char **cs, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cs[i][j] = is[i][N-1-j];
			cout << cs[i][j] << " ";
		}
		cout << endl;
	}
	return Compare(os, cs, N);
}

//-----------------------------------------------------------------

int TwoSeventy (char **os, char **is, char **cs, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cs[i][j] = is[j][N-1-i];
			cout << cs[i][j] << " ";
		}
		cout << endl;
	}
	return Compare(os, cs, N);
}

//-----------------------------------------------------------------

int Ninty (char **os, char **is, char **cs, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cs[i][j] = is[N-1-j][i];
			cout << cs[i][j] << " ";
		}
		cout << endl;
	}
	return Compare(os, cs, N);
}

//-----------------------------------------------------------------

int Compare (char **os, char **cs, int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (cs[i][j] != os[i][j])
			return 0;
		}
		return 1;
}


int Rec (char **os, char **is, int N)
{
	int final1=0, final2=0, final3=0, final4 = 0;
	int match = 0;
	char **cs1, **cs2, **cs3, **cs4;
	cs1=(char **)malloc(sizeof(size_t)*N);
	cs2=(char **)malloc(sizeof(size_t)*N);
	cs3=(char **)malloc(sizeof(size_t)*N);
	cs4=(char **)malloc(sizeof(size_t)*N);
	for (int i=0; i<N; i++)
	{
		cs1[i] =(char *)malloc(4);
		cs2[i] =(char *)malloc(4);
		cs3[i] =(char *)malloc(4);
		cs4[i] =(char *)malloc(4);
	}
	
	
	for (int i = 0; final1==0 && i < 4; i++)
	{
	
		if (i == 0)
			match = Ninty(os, is, cs1, N);
		else if (i == 1)
			match = OneEighty(os, is, cs1, N);
		else if (i == 2)
			match = TwoSeventy(os, is, cs1, N);
		else if (i == 3)
			match = Reflection(os, is, cs1, N);
	
		if (match == 1) 
			final1 = i+1;
			for (int j = 0; final2==0 && j < 4; j++)
			{
				if (j == 0)
					match = Ninty(os, cs1, cs2, N);
				else if (j == 1)
					match = OneEighty(os, cs1, cs2, N);
				else if (j == 2)
					match = TwoSeventy(os, cs1, cs2, N);
				else if (j == 3)
					match = Reflection(os, cs1, cs2, N);
				if (match == 1) 
					final2 = 5;
				
					for (int k = 0; final3==0 && k < 4; k++)
					{
					if (k == 0)
						match = Ninty(os, cs2, cs3, N);
					else if (k == 1)
						match = OneEighty(os, cs2, cs3, N);
					else if (k == 2)
						match = TwoSeventy(os, cs2, cs3, N);
					else if (k == 3)
						match = Reflection(os, cs2, cs3, N);
					if (match == 1)
						final3 = 5;
						for (int l = 0; final4=0 && l < 4; l++)
						{
							if (l == 0)
								match = Ninty(os, cs3, cs4, N);
							else if (l == 1)
								match = OneEighty(os, cs3, cs4, N);
							else if (l == 2)
								match = TwoSeventy(os, cs3, cs4, N);
							else if (l == 3)
								match = Reflection(os, cs3, cs4, N);
							if (match == 1)
								final4 = 5;
						}
					}		
			}
	}
	for (int i=0; i<N; i++)
	{
		free (cs1[i]);
		free (cs2[i]);
		free (cs3[i]);
		free (cs4[i]);
	}	
	free(cs1);
	free(cs2);
	free(cs3);
	free(cs4);
	if (final1) return final1;
	else if (final2 || final3 || final4) return 5;
	else return 7;
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
