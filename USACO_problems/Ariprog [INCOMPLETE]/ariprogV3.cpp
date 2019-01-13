/*
daniel_g1
PROG: ariprog
LANG: C++  
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <malloc.h>

using namespace std;

/*struct difference_number
{
	int x;
	int y;
};*/

void sortBisquares(vector <int> &bisquares, int length)
{
	int i, key, j;
    for (i = 1; i < length; i++)
    {
       key = bisquares[i];
       j = i-1;
       while (j >= 0 && bisquares[j] > key)
       {
           bisquares[j+1] = bisquares[j];
           j = j-1;
       }
       bisquares[j+1] = key;
    }
	
}

/*void sortPair(difference_number *coordinates, int count)
{
	int i, key_x, key_y, j;
    for (i = 1; i < count; i++)
    {
       key_y = coordinates[i].y;
       key_x = coordinates[i].x;
       j = i-1;
       while (j >= 0 && coordinates[j].y > key_y)
       {
           coordinates[j+1].y = coordinates[j].y;
           coordinates[j+1].x = coordinates[j].x;
           j = j-1;
       }
       coordinates[j+1].y = key_y;
       coordinates[j+1].x = key_x;
    }
	
}*/

/*int search(vector <int> bisquares, int x)
{
   for (int i = 0; i < bisquares.size(); i++)
		if (bisquares[i] == x)
			return true;
	return false;
}*/

bool Binary_Search(int target, const vector<int> &list, int first, int last)
{
	if (first > last)
		return false;
	else
	{
		int midpoint = (first + last) / 2;
		if (list[midpoint] == target)
			return true;
		else if (list[midpoint] > target)
			return Binary_Search(target, list, first, midpoint - 1);
		else
			return Binary_Search(target, list, midpoint + 1, last);
	}
}


/*bool validProg(vector <int> bisquares, int starting_number, int common_difference, int N)
{
	bool found = false;
	for (int i = 1; i < N; i++)
	{
		found = Binary_Search(starting_number + i*common_difference, bisquares, 0, bisquares.size() - 1);
		if (!found)
			return false;
	}
	return true;
}*/

int main()
{
	int N, M, *common_difference, starting_number;
	int count = 0, length = 0, i = 0;
	bool found = false;
	
	
	ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    fin >> N >> M;
	vector <int> bisquares;
	for (int i = 0; i <= M; i++)
		for(int j = i; j <= M; j++)
		{
			bisquares.push_back(1);
			bisquares[(2*M + 3 - i)*i/2 + j - i] = i*i + j*j;
		}
	
//	for (int i = 0; i < bisquares.size(); i++)      why are there 1's at the end?
//		cout << bisquares[i] << endl;
		
	length = bisquares.size();
	sortBisquares(bisquares, length);

	while (i < length - 1)
	{
		if (bisquares[i] == bisquares[i+1])
			bisquares.erase(bisquares.begin() + i + 1);
		else i++;
		length = bisquares.size();
	};
	common_difference = (int*)malloc(bisquares.size()*sizeof(int));
	
//	for (int i = 0; i < bisquares.size(); i++)
//		cout << bisquares[i] << endl;
	for (int i = 0; i < length - 1; i++)
		common_difference[i] = bisquares[i+1] - bisquares[i];
		 
	i = 0;
	
	for (int j = 1; j < length - 1; j++)
	{	
		for (int i = 0; i < length - N + 1; i++)		
		{
			starting_number = bisquares[i];
			found = true;
			for (int k = 1; k < N; k++)
			{
				if (!Binary_Search(bisquares[i] + k*common_difference[j], bisquares, 0, bisquares.size()))
				{
					found = false;
					break;
				}
			}
			if (found)
				cout << starting_number << " " << common_difference[j] << endl;
		}
	}

//	cout << count;
//		else fout << "NONE" << endl;
//	sortPair(&coordinates[0], count);

	if (count == 0)
		fout << "NONE" << endl;
}
