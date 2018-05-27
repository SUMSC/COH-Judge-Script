#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

// 需要判别的脚本位置，可修改：
#include "..\Source\Solution.cpp"

using namespace std;

// 数据文件所在位置，可修改：
char inFile[] = "../Data/in";
char outFile[] = "../Data/out";
char ansFile[] = "../Data/answer";

int dataCount() {
	// Count the number of data
	fstream dataIn;
	dataIn.open(inFile);
	string dataLine;
	int dataCount = 0;
	while(getline(dataIn, dataLine))
		++dataCount;
	dataIn.close();
	return dataCount;
}

void userRun(int dataCount) {
	// Redirect cin and cout
	freopen(inFile,"r",stdin);
	freopen(outFile,"w",stdout);

	// Run the user program
	Solution sol;
	for(int i = 0; i < dataCount; ++i)
		sol.solve();

	// Redirect cout back to the console
	freopen("CON", "w", stdout);
}

int judge() {
	// Open ans and out files
	fstream stdAns;
	stdAns.open(ansFile, ios::in);
	fstream usrAns;
	usrAns.open(outFile, ios::in);

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

	// Close all the files
	stdAns.close();
	usrAns.close();

	// Return the result
	return int(100 * corCount / (double)stdCount);
}

int main() {
	userRun(dataCount());
	cout << "Pass Rate : " << judge() << " % " << endl;
	return 0;
}