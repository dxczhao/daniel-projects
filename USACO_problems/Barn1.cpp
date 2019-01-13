/*
daniel_g1
PROG: barn1
LANG: C++  
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include<malloc.h>

using namespace std;

void stallDifferences(int *stall_numbers, int *stall_differences, int C)
{
	for (int i = 0; i < C - 1; i++)
		stall_differences[i] = stall_numbers[i + 1] - stall_numbers[i] - 1;
}

void sortDifferences(int *stall_differences, int C)
{
	int i, key, j;
    for (i = 1; i < C - 1; i++)
    {
       key = stall_differences[i];
       j = i-1;
       while (j >= 0 && stall_differences[j] > key)
       {
           stall_differences[j+1] = stall_differences[j];
           j = j-1;
       }
       stall_differences[j+1] = key;
    }
	
}

int reduceStalls(int *stall_differences, int C, int M)
{
	int no_of_boards = C;
	int n = 0, i = 0;
	while (i < C-1 && no_of_boards > M)
	{
		n += stall_differences[i];
		no_of_boards--;
		i++;
	};
	return n;
}

int main()
{
	int M, S, C, n = 0, *stall_numbers, *stall_differences;
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");
	fin >> M >> S >> C;
	stall_numbers = (int*)malloc(C*sizeof(int));
	stall_differences = (int*)malloc((C-1)*sizeof(int));
	for (int i=0; i<C; i++) 
	{
		fin >> stall_numbers[i];
	}
	if (M >= C)
	{
		fout << C << endl;
	}
	else
	{
		sortDifferences(stall_numbers, C+1);
		stallDifferences(stall_numbers, stall_differences, C);
		sortDifferences(stall_differences, C);
		n = reduceStalls(stall_differences, C, M);
		cout << n + C;
		fout << n + C << endl;
	}
	fout.close();
	fin.close();
}
