#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include "students.cpp"
#include <sstream>
#include <fstream>
using namespace std;

static int getord(int SSID, vector<Student> list) {
	for (auto a = 0; a < list.size(); a++) {
		if (list[a].Sid == SSID) {
			// cout << "phan tu o vi tri : " << a + 1 << endl;
			return a;
		}
	}
}
static void add_friend(int SSID1, int SSID2, vector<Student>& list) { // thêm SSID2 là bạn của SSID1
	list[getord(SSID1, list)].addfriendcode(SSID2);
	list[getord(SSID2, list)].addfriendcode(SSID1);

}
static void print_friend(int SSID, vector<Student> list) { // in tên bạn bè
	for (auto i = 0; i < list[getord(SSID, list)].friendcode.size(); i++) {
		for (auto k = 0; k < list.size(); k++) {
			if (list[getord(SSID, list)].friendcode[i] == list[k].Sid) {
				cout << "ban thu " << i + 1 << " ten la: " << list[k].name << endl;
			}
		}
	}
}
static void printfcode(int SSID, vector<Student>list) { // in code bạn bè
	for (auto i = 0; i < list[getord(SSID, list)].friendcode.size(); i++) {
		cout << list[getord(SSID, list)].friendcode[i] << endl;
	}
}

static void inputindex(int n, vector<Student>& list) { // thêm n phần tử
	for (int t = 0; t < n; t++) {
		Student temp;
		temp.full_userin();
		list.push_back(temp);
	}
}

static vector<int> string_to_vector_int_pros(string a) {
	vector<int> nums;
	stringstream ss(a); // tưởng tượng đang nhập a từ bàn phím, dùng để tách dấu trắng
	int pt;

	while (ss >> pt) {
		nums.push_back(pt);
	}
	return nums;
}

static void print_vct(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}

static void print_list_vct(vector<string> b) {
	for (int i = 0; i < b.size(); i++) {
		cout << i+1 << ". " << b[i] << "\n";
	}
}

static string vectorToString(vector<int> vec) {
	stringstream ss;
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i != 0) {
			ss << " "; // them dau cách
		}
		ss << vec[i];
	}
	return ss.str();
}

static void student_save(Student a) { // lưu data vào file student_info.txt
	vector<string> inpl = {
		to_string(a.Sid),
		a.name,
		vectorToString(a.friendcode),
		vectorToString(a.hobbies),
		vectorToString(a.habits)
	};

	ofstream outF("student_info.txt", ios::app);
	if (outF.is_open()) {
		for (int i = 0; i < 5; i++) {
			outF << inpl[i] << "\n";
		}
	}
	else {
		cerr << "loi file luu thong tin student" << endl;
	}
}
static int countLines(const string& filename) {
	ifstream file(filename);
	int lineCount = 0;
	string line;

	if (file.is_open()) {
		while (getline(file, line)) {
			lineCount++;
		}
		file.close();
	}
	else {
		cerr << "khong the mo file" << endl;
	}

	return lineCount;
}

static string read_Specific_Line(const string& filename, int targetLine) {
	ifstream file(filename);
	string line;
	int currentLine = 1;

	if (file.is_open()) {
		while (getline(file, line)) {
			if (currentLine == targetLine) {
				file.close();
				return line;
			}
			currentLine++;
		}
		file.close();
		cerr << "The file has less than " << targetLine << " lines." << endl;
	}
	else {
		cerr << "Unable to open file." << endl;
	}

	return "";
}


static vector<Student> student_retrieve(const string& filename) {
	static vector<Student> temp_list;
	int records = countLines(filename) / 5;
	int targetpt = 0;
	for (int i = 0; i < records; i++) {
		Student temp;
		targetpt++;
		temp.Sid = stoi(read_Specific_Line("student_info.txt", targetpt));
		targetpt++;
		temp.name = read_Specific_Line("student_info.txt", targetpt);
		targetpt++;
		temp.friendcode = string_to_vector_int_pros(read_Specific_Line("student_info.txt", targetpt));
		targetpt++;
		temp.hobbies = string_to_vector_int_pros(read_Specific_Line("student_info.txt", targetpt));
		targetpt++;
		temp.habits = string_to_vector_int_pros(read_Specific_Line("student_info.txt", targetpt));
		temp_list.push_back(temp);
	}
	return temp_list;
}


static void print_full(const vector<Student> stdu) {
	for ( int i = 0; i < stdu.size(); i++)
	{
		cout << "Sinh vien thu " << i + 1 << " : " << endl;
		cout << "Ten : " << stdu[i].name << endl;
		cout << "Mssv : " << stdu[i].Sid << endl;
		cout << "Danh sach ban be : ";
		cout << "\n";
		print_friend(stdu[i].Sid, stdu);
		cout << "\n";
		cout << "So thich : ";
		print_vct(stdu[i].hobbies);
		cout << "\n";
		cout << "thoi quen : ";
		print_vct(stdu[i].habits);
		cout << "\n";
		cout << "------------------------------------";
		cout << endl;
	}
}