/*
daniel_g1
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main ()
{
	int N, i, j, ic, ig, gap[500000];
	bool alreadycounted = false;
	int *start, *end;
	int max=0, min=999999, one_cow[500000];
	ifstream fin ("milk2.in");
	ofstream fout ("milk2.out");
	fin >> N;
	start = (int*)malloc(N*sizeof(int));
	end = (int*)malloc(N*sizeof(int));
	
	for (i = 0; i < N; i++)
	{
		fin >> start[i];
		fin >> end [i];
	}
	for (i = 0; i < N; i++)
	{
		if (end[i] > max)
			max = end[i];	
		if (start[i] < min)
			min = start[i];
	}
	ic = 0;
	ig = 0;
	gap [ig] = 0;
	one_cow[ic] = 0;
	for (i = min; i <= max; i++)
	
	{
		alreadycounted=false;
		for (j= 0; j < N; j++) 
		{
			if (i < end[j] && i>=start[j] && !alreadycounted) {
				one_cow[ic]++;
				alreadycounted = true;
				ig++;
				gap[ig]=0;	
				break;
			}

		}	
		if (!alreadycounted){
				gap[ig] ++;	
				ic++;
				one_cow[ic]=0;
				
		}
	}
	max=0;
	for (i = 0; i <= ic; i++)
		if (one_cow[i]>max) max=one_cow[i];
	min=0;
	for (i = 0; i < ig; i++)
		if (gap[i]>min) min=gap[i];
	fout <<max << " "<< min << endl;
}
