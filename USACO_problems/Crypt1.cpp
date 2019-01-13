/*
daniel_g1
PROG: crypt1
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

int check_set (int digit, int *choices, int N)
{
	for (int i = 0; i < N; i++)
		if (digit == choices[i])
			return true;
	return false;
}

int check_partial (int N, int *choices, int p, bool partial)
{
	int n;
	int correct=0;
	if (!partial) n=4;
	else n=3;
	for(int i = 0; i<n; i++){
		if (check_set(p%10, choices, N))
			correct++;
		p/=10;
	}
	if (correct!=n) return 0;
	else return 1;
}
int check_correct(int N, int *choices, int a, int b, int c, int d, int e)
{
	cout<< choices[a];
		cout<< choices[b];
			cout<< choices[c];
				cout<< choices[d];
					cout<< choices[e];
					cout<<endl;
}
int number_of_solutions (int N, int choices[])
{
	int a, b, c, d, e, partial1, partial2, product, number_of_correct=0;
	bool solution1, solution2, solution3;
	for (a = 0; a < N; a++)
	{
		if (choices[a]==0)
			continue;
		for (b = 0; b < N; b++)
		{
			for (c = 0; c < N; c++)
			{
				for (d = 0; d < N; d++)
				{
					if (choices[d]==0)
						continue;
					for (e = 0; e < N; e++)
					{
						partial1 = (100*choices[a]+10*choices[b]+choices[c])*choices[e];
						if (partial1>=1000) continue;
						solution1 = check_partial(N,choices,partial1, 1);
						partial2 = (100*choices[a]+10*choices[b]+choices[c])*choices[d];
						if (partial2>=1000) continue;
						solution2 = check_partial(N,choices,partial2, 1);
						product = partial1+(partial2*10);
						if (product<1000) continue;
						solution3 = check_partial(N,choices,product, 0);
						if (solution1 && solution2 && solution3) {
							//check_correct(N, choices, a,b,c,d,e);
							number_of_correct++;
						}
					}
			
				}
			}
		}
	}
	return number_of_correct;
}

int main()
{
	int N, *choices=(int*)malloc(10*sizeof(int)), n=0;
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> choices[i];
	}
		
	n = number_of_solutions(N, choices);
	cout << n;
	fout << n << endl;
}
