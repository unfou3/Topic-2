#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
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
				cout << "This friend have added before :))" << endl;
			}
			else {
				friendcode.push_back(code);
				cout << "Friend added" << endl;
			}
	}
	void deletefriendcode(int code) {
		auto it = find(friendcode.begin(), friendcode.end(), code);
		if (it != friendcode.end()) {
			friendcode.erase(it);
			cout << "Deleted" << endl;
		} else {
			cout << "Friend not found" << endl;
		}
	}
	int check_user2(int Sid, vector<Student> list) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i].Sid == Sid) {
				return 1;
			}
		}
		return 0;
	}
	void full_userin(vector<Student> list_stdu) {
		int i_Sid;
		string i_name;
		vector<int> i_friendcode; 
		vector<int> i_hobbies;
		vector<int> i_habits;
		int tempSid;
		cout << "Enter id student you want to add : ";
		cin >> tempSid;
		do
		{
			i_Sid = tempSid;
			if (check_user2(tempSid, list_stdu))
			{
				cout << "This student have added before, please enter another student id : ";
				cin >> tempSid;
			}
			
		} while (check_user2(tempSid, list_stdu));
		
		cout << endl << "Enter name of the student: ";
		cin >> i_name;
		cout << endl;
		int temp;
		cout << "Enter friends of the student, enter -1 to stop : " << endl;
		while (true) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			i_friendcode.push_back(temp);
		}
		cout << endl;
		cout << "Enter hobbies of the student, enter -1 to stop : " << endl;
		while (true) {
			cin >> temp;
			if (temp == -1) {
				break;
			}
			i_hobbies.push_back(temp);
		}
		cout << "Enter habits of the student, enter -1 to stop : " << endl;
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

