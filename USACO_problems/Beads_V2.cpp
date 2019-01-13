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
	int prev_seg = 1, first_seg, last_seg;
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
	prev_seg=0;
	wv=0;
	while (i < N-1 && (wv == letter[i+1] || letter[i] == letter[i+1] || letter[i+1] == 'w')){
		if (letter[i+1]=='w') wv=letter[i];
		else wv=0;
		i++;
	}
	i++;
	
	j=i;
	// i is index to boundary
	wv=0;
	while (j <N-1 && (wv=letter[j+1] || letter[j] == letter [j+1] || letter[j+1] == 'w')) {
		if (letter[j+1]=='w') wv=letter[j];
		else wv=0;
		j++;
	}
	first_seg = j-i+1;
	n=0;
	while (n<N)
	{
		current_seg = 1;
		wv=0;
		while (letter[i%N] == letter[(i+1)%N] ||letter[(i+1)%N] == 'w' || wv==letter[i+1])
		{
			if (letter[(i+1)%N]=='w') wv=letter[i%N];
			else wv=0;
			current_seg++;
			i++;
			n++;
		}
		cout << "i="<< i << "  cs=" << current_seg << "  n="<<n<< endl;
		i++;
		n++;
		
		
		//cout << "second i="<< i << "cs=" << current_seg << endl;
		seg = prev_seg + current_seg;
		if (seg > max_seg)
			max_seg = seg;
		prev_seg = current_seg;
		
	}
	
	if (current_seg + first_seg > max_seg)
		max_seg = current_seg + first_seg;
	cout << endl;
	cout << max_seg << endl;
	return 0;
	
}
