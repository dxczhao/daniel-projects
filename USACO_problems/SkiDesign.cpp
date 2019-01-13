/*
daniel_g1
PROG: skidesign
LANG: C++  
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include<malloc.h>

using namespace std;

void sortHeights(int *mountain_heights, int N)
{
	int i, key, j;
    for (i = 1; i < N; i++)
    {
       key = mountain_heights[i];
       j = i-1;
       while (j >= 0 && mountain_heights[j] > key)
       {
           mountain_heights[j+1] = mountain_heights[j];
           j = j-1;
       }
       mountain_heights[j+1] = key;
    }
	
}

int main()
{
	int N, *mountain_heights, total = 0, x, totals[100];
    ifstream fin ("skidesign.in");
    ofstream fout ("skidesign.out");
    fin >> N;
	mountain_heights = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
    	fin >> mountain_heights[i];
	sortHeights(mountain_heights, N);
	for (int i = 0; i < 100; i++)
	{
		total = 0;
		for (int j = 0; j < N; j++)
		{
			x = mountain_heights[j];
			if (x >= i && x <= 17 + i)
				total += 0;
			else if (abs(i - x) > abs(x - 17 - i))
				total += (x - 17 - i)*(x - 17 - i);
			else total += (i - x)*(i - x);
		}
		totals[i] = total;
	}
	sortHeights(totals, 100);	
	fout << totals[0] << endl;
	cout << totals[0];
}
