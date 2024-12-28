﻿#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

static void cml_input_habit_tx() {  // thêm thói quen nhập tay
	ofstream Filei("habitc.txt", ios::app);
	if ((Filei.is_open())) {
		cout << "Enter a habit you want to add in database : ";
		string a;
		cin.ignore();
		getline(cin,a);
		Filei << a << "\n";
		Filei.close();
	}
	else
	{
		cerr << "Error: habit file" << endl;
	}
}

static vector<string> output_habit() { // lên list habit vào vector
	vector<string> oup;
	ifstream file("habitc.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			oup.push_back(line);
		}
		file.close();
	}
	else
	{
		cerr << "Error: habit file" << endl;
	}

	//for (int i = 0; i < oup.size(); i++) {
	//	std::cout << oup[i] << " ";
	//}

	return oup;
}