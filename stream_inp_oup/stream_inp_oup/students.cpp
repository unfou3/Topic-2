#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Student {
private:
	void ini(int i_Sid, string i_name) {
		Sid = i_Sid;
		name = i_name;
	}
	
public:
	vector<Student> friends;
	vector<int> hobbies;  // Danh sách sở thích
	vector<int> habits;   // Danh sách thói quen
	int Sid;
	string name;
	vector<int> friendcode;
	void addfriendcode(int code) {
		int temp = 0;
			if ((count(friendcode.begin(), friendcode.end(), code)) > 0) {
				cout << "da ket ban roi :))" << endl;
			}
			else {
				friendcode.push_back(code);
				cout << "ok da them" << endl;
			}
	}
	void full_userin() {
		int i_Sid;
		string i_name;
		vector<int> i_friendcode; 
		vector<int> i_hobbies;
		vector<int> i_habits;
		cout << "nhap mssv : ";
		cin >> i_Sid;
		cout << endl << "nhap ten : ";
		cin >> i_name;
		cout << endl;
		int temp;
		cout << "nhap mssv cua cac ban be, go -1 de dung : " << endl;
		while (true) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			i_friendcode.push_back(temp);
		}
		cout << endl;
		cout << "nhap code cua cac so thich, go -1 de dung : " << endl;
		while (true) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			i_hobbies.push_back(temp);
		}
		cout << "nhap code cac thoi quen, go -1 de dung : " << endl;
		while (true) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			i_habits.push_back(temp);
		}
		full_ini(i_Sid, i_name, i_friendcode, i_hobbies, i_habits);
	}
	void userin() {
		int i_Sid;
		string i_name;
		cout << "nhap mssv : ";
		cin >> i_Sid;
		cout << endl << "nhap ten : ";
		cin >> i_name;
		cout << endl;
		ini(i_Sid, i_name);
	}
	void half_ini(int ssid, string name) {
		ini(ssid, name);
	}
	void full_ini (int i_Sid, string i_name, vector<int> i_friendcode, vector<int> i_hobbies, vector<int> i_habits) {
		Sid = i_Sid;
		friendcode = i_friendcode;
		name = i_name;
		hobbies = i_hobbies;
		habits = i_habits;
	}
};

