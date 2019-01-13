/*
daniel_g1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	int N, i, n, j;
	bool first_time = true;
	bool last_time = false;
	char current_seg_letter, prev_seg_letter;
	int prev_seg = 1;
	int current_seg = 1;
	int seg = 0;
	int max_seg = 0;
	string input;
	char wv;
	const char *letter;
	ifstream fin ("beads.in");
	ofstream fout ("beads.out");
	fin >> N;
	fin >> input;
	letter = input.c_str();
	for (int i = 0; i <= N; i++)
	{
		cout << letter[i];
	}
	cout << endl;
	i=0;
	for (i=0; i <= N; i++)
	{
		first_time = true;
		if (max_seg == N)
			break;
		current_seg = 0;
		prev_seg = 0;
		if (last_time)
			break;
		j = i;
		//right seg
		while (current_seg<N && prev_seg < N && (current_seg + prev_seg)<N)
		{
			if (first_time)
			{
				if (letter[(j+N) % N] == 'r')
				{
					current_seg_letter = 'r';
					first_time = false;
				}
					
				else if (letter[(j+N) % N] == 'b')
				{
					current_seg_letter = 'b';
					first_time = false;
				}
				current_seg ++;
			}
			else
			{
				if (current_seg_letter == letter[(j+N) % N] || letter[(j+N) % N] == 'w')
				{
					current_seg ++;
				}
				else
				{
					if (j >= N)
					{
						last_time = true;
					}
					break;
				}
			}
			j++;
		}
		
		//left seg
		j = i - 1;
		first_time = true;
		while (current_seg<N && prev_seg < N && (current_seg + prev_seg)<N)
		{
			if (first_time)
			{
				if (letter[(j+N) % N] == 'r') {
						prev_seg_letter = 'r';
						first_time = false;
					}
				else if (letter[(j+N) % N] == 'b') {
					prev_seg_letter = 'b';
					first_time = false;
				}	
				prev_seg ++;
			}
			else
			{
				if (prev_seg_letter == letter[(j+N) % N] || letter[(j+N) % N] == 'w')
				{
					prev_seg ++;
				}
				else break;
			}
			j--;
		}
		if (current_seg + prev_seg > max_seg)
			max_seg = current_seg + prev_seg;
	} // for
	fout << max_seg << endl;
}
