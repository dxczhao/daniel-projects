/*
daniel_g1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>  

using namespace std;

int  convert (int sqaure_number, int B, char *number_in_B)
{
	int i;  // index to numbers in base B system;
	int j; //temporal index
	int number_index=0; // of a number in a B base;
	int number_digits=0;
	int number_power;
	int multipler; 
	int pow_result;
	
		for (j = 0; j < 17; j++)
			number_in_B[j] = '0';
		number_index = 0;
		number_digits = 0;
		while (sqaure_number > 0)
		{
			multipler = 0;
			number_power = 0;
			if (sqaure_number != 0)
			{
				while (sqaure_number > 0)
				{
					if (pow(B, number_power) <= sqaure_number) 
						number_power++;
					else break;
				}
				number_power--;
				pow_result=pow(B, number_power);
				while (sqaure_number > 0)
				{
					if (multipler * pow_result <= sqaure_number) 
						multipler++;
					else break;
				}
				multipler--;
				sqaure_number = sqaure_number - multipler * pow_result;
			}
			
			if (number_digits==0) number_digits=number_power+1;
			number_index=number_power;
	
			number_in_B[number_index] = multipler;
			if (number_in_B[number_index] > 9)
				number_in_B[number_index]=number_in_B[number_index] + 'A' - 10;
			else number_in_B[number_index]=number_in_B[number_index] + '0';
		}
		return number_digits;
}

int main ()
{
	int B; // input base system
	int i;  // index to numbers in base B system;
	int j; //temporal index
	int number_index=0; // of a number in a B base;
	int number_digits=0;
	int sqaure_number ; // n*n where n is a number in B base
	int number_power;
	int multipler; 
	int pow_result;
	int failed=0;
	char number[17];
	ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");
	fin >> B;
	for (i = 1; i<=300; i++)
	{
		number_digits=convert(i*i, B, number);
		failed=0;
		for (j = 0; j < number_digits/2; j++)
			{
				if (number[j] != number[number_digits-j-1]) {
					failed=1;
					break;
				}
				
			}
		if (!failed)
		{
			char base_number[17];
			int base_number_digits=convert(i, B, base_number);
			for (j=base_number_digits-1; j>=0; j--) {
				cout << base_number[j];
				fout << base_number[j];
			}
			cout <<  " ";
			fout <<  " ";
			for (j = number_digits-1; j>=0 ; j--) {
				cout << number[j];
				fout << number[j];
			}
			cout << endl;
			fout << endl;
		}
	}
}
