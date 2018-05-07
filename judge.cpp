#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <time.h>

#include ".\user\example.cpp"

using namespace std;

int main() {
	// Count the number of data
	fstream dataIn;
	dataIn.open("data");
	string dataLine;
	int dataCount = 0;
	while(getline(dataIn, dataLine)) {
		++dataCount;
	}
	dataIn.close();

	// Redirect cin and cout
	freopen("data","r",stdin);
	freopen("out","w",stdout);

	// Run the user program
	Solution sol;
	for(int i = 0; i < dataCount; ++i)
		sol.solve();

	// Redirect cout back to the console
	freopen("CON", "w", stdout);

	// Open ans and out files
	fstream stdAns;
	stdAns.open("answer", ios::in);
	fstream usrAns;
	usrAns.open("out", ios::in);

	// Count the number of standard answer and user answer
	string stdAnsLine, usrAnsLine;
	int stdCount = 0, usrCount = 0;
	while(getline(stdAns, stdAnsLine)) {
		++stdCount;
	}
	while(getline(usrAns, usrAnsLine)) {
		++usrCount;
	}

	// Reposition the file pointer
	stdAns.clear();
	stdAns.seekg(0, ios::beg);
	usrAns.clear();
	usrAns.seekg(0, ios::beg);

	// Compare the answers
	int corCount = 0;
	for(int i = 0; i < min(stdCount, usrCount); ++i) {
		getline(stdAns, stdAnsLine);
		getline(usrAns, usrAnsLine);
		// cout << stdAnsLine << "   " << usrAnsLine << endl;
		if(stdAnsLine == usrAnsLine)
			++corCount;
		else
			break;
	}

	// Output the result
	cout << "Pass Rate : " << int(100 * corCount / (double)stdCount) << " % " << endl;

	// Close all the files
	stdAns.close();
	usrAns.close();
	// END
	return 0;
}
