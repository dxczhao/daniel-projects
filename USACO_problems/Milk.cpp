/*
daniel_g1
PROG: milk
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

int Find_Minimum(int *cost, int *farmer);

void Swap_Data (int *number1, int *number2);

void Sort (int *cost, int *amount, int farmers);

int main ()
{
	int req, farmers, *cost, *amount, i, current_amount = 0, price = 0;
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");
	fin >> req;
	fin >> farmers;
	cost = (int*)malloc(farmers*sizeof(int));
	amount = (int*)malloc(farmers*sizeof(int));
	for (i = 0; i < farmers; i++)
	{
		fin >> cost[i];
		fin >> amount[i];
	}
	Sort (cost, amount, farmers);
	
	for (i = 0; i < farmers; i++)
		cout << cost[i] << setw(10) << amount[i] << endl;
	for (i = 0; ; i++)
	{
		if (current_amount+amount[i] < req)	
		{
			current_amount += amount[i];
			price += cost[i] * amount[i];
		}
		else
		{
			price += cost[i] * (req - current_amount);
			break;
		}
	}
	cout << price;
	fout << price << endl;
}

void Swap_Data (int *number1, int *number2)
{
	int temp;
	temp = *number1;
	*number1 = *number2;
	*number2 = temp;
} 

int Find_Minimum(int *cost, int farmer, int first)
{
	int min_index = first;
	for (int index = first + 1; index < farmer; ++index)
	if (cost[index] < cost[min_index])
	min_index = index;
	return min_index;
}

void Sort (int *cost, int *amount, int farmer)
{
	int min_index = 0;
	for (int index = 0; index < farmer - 1; ++index)
	{
		min_index = Find_Minimum (cost, farmer, index);
		if (min_index != index)
		{
			Swap_Data (&cost[index], &cost[min_index]);
			Swap_Data (&amount[index], &amount[min_index]);
		}
		
	}

}


