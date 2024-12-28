#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

static void cml_input_hobby_tx() {
	ofstream Filei("hobbyc.txt", ios::app);
	if ((Filei.is_open())) {
		cout << "Enter hobby you want to add in database: ";
		string a;
		cin.ignore();
		getline(cin,a);
		Filei << a << "\n";
		Filei.close();
	}
	else
	{
		cerr << "Error: hobby file" << endl;
	}
}

static vector<string> outputhb() {
	vector<string> oup;
	ifstream file("hobbyc.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			oup.push_back(line);
		}
		file.close();
	}
	else
	{
		cerr << "Error: hobby file" << endl;
	}

	//for (int i =0; i < oup.size(); i++) {
	//	std::cout << oup[i] << " ";
	//}

	return oup;
}