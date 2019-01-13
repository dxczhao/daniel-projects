/*
daniel_g1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	int glen, clen;
	const char *s;
	int i;
	int gp=1, cp=1;
	ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	string groupname, cometname;
	fin >> groupname >> cometname;
	//cout << groupname << cometname << endl << endl;
	glen=groupname.length();
	clen=cometname.length();

	s=groupname.c_str();
	for (i=0; i<glen; i++) 
		gp=gp*(s[i]-'A'+1);
	gp=gp%47;
	s=cometname.c_str();
	for (i=0; i<clen; i++) 
		cp=cp*(s[i]-'A'+1);	
	cp=cp%47;
		
	if (gp==cp)
	fout << "GO" << endl;
	else
	fout << "STAY" << endl;
}
