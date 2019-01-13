/*
Daniel
PROG: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

/*void alterCombo(int *combo, int *alteredCombo, int i, int j, int k, int N)
{
	alteredCombo[0] = (combo[0] - 2 + i + N) % N ;
	alteredCombo[1] = (combo[1] - 2 + j + N) % N ;
	alteredCombo[2] = (combo[2] - 2 + k + N) % N ;
}*/

bool match(int x, int y, int N)
{
	if (abs(x-y) <= 2 || abs(x-y) >= N - 2)
		return true;
	else return false;
}

int main()
{
	int N, john[3], master[3], count = 0; 
	ifstream fin ("combo.in");
	ofstream fout ("combo.out");
	fin >> N;
	for (int i = 0; i < 3; i++)
		fin >> john[i];
	for (int i = 0; i < 3; i++)
		fin >> master[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
					if ((match(i, john[0], N) && match(j, john[1], N) && match(k, john[2], N)) || (match(i, master[0], N) && match(j, master[1], N) && match(k, master[2], N)))
						count++;
					
	cout << count << endl;	
	fout << count << endl;
	
	/*
	for (int i = 0; i < 3; i++)
		johnCopy[i] = john[i];
	for (int i = 0; i < 3; i++)
		masterCopy[i] = master[i];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				for (int q = 0; q < 5; q++)
					for(int p = 0; p < 5; p++)
						for (int m = 0; m < 5; m++)
						{
							alterCombo(johnCopy, alteredJohn, i, j, k, N);
							for (int u = 0; u < 3; u++)
								johnCopy[u] = john[u];
							alterCombo(masterCopy, alteredmastered, q, p, m, N);
							for (int u = 0; u < 3; u++)
								masterCopy[u] = master[u];
							if (alteredJohn[0] == alteredmastered[0] && alteredJohn[1] == alteredmastered[1] && alteredJohn[2] == alteredmastered[2])
							{
								//cout << alteredJohn[0] << alteredJohn[1] << alteredJohn[2] << "   " << alteredmastered[0] << alteredmastered[1] << alteredmastered[2];
								negative++;
							}

						}

	cout << 250 - negative << endl;
	fout << 250 - negative << endl;*/
}
