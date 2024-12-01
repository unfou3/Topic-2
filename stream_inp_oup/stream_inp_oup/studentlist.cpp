//#include <iostream>
//#include <math.h>
//#include <string>
//#include <sstream>
//#include <vector>
//#pragma once
//#include "students.cpp"
//using namespace std;
//
//class Studentlist {
//public:
//	vector<Student> student_list;
//
//	void input(Student std) {
//		student_list.push_back(std);
//	}
//
//	int getord(int SSID) {
//		for (auto a = 0; a < student_list.size(); a++) {
//			if (student_list[a].Sid == SSID) {
//				return a;
//			}
//			else
//			{
//				cout << "Không tìm thấy người có mssv là : " << SSID;
//				return -1;
//			}
//		}
//	}
//	int add_friend(int SSID1, int SSID2) {
//		student_list[getord(SSID1)].addfriendcode(SSID2);
//	}
//	void print_friend(int SSID,Studentlist& a) {
//		student_list[getord(SSID)].friendnameoutput(a);
//	}
//};