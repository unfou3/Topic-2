#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include "students.cpp"
#include <sstream>
#include <fstream>
#include <algorithm>
#include <unordered_set>
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

static vector<int> string_to_vector_int_pros(string a) { // call hàm chuyển string to vector, dùng trong việc dịch lại file txt
	vector<int> nums;
	stringstream ss(a); // tưởng tượng đang nhập a từ bàn phím, dùng để tách dấu trắng
	int pt;

	while (ss >> pt) {
		nums.push_back(pt);
	}
	return nums;
}

static void print_vct(vector<int> a) { // in các phần tử dạng int của vector, cách nhau bởi dấu cách
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}
static void print_list_vct(vector<string> b) { // in các phần tử dạng string, cách nhau dấu cách và được đánh số
	for (int i = 0; i < b.size(); i++) {
		cout << i+1 << ". " << b[i] << "\n";
	}
}

static string vectorToString(vector<int> vec) { // chuyển vector sang string, các phần tử cách nhau bởi dấu cách
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
static int countLines(const string& filename) { // trả về số dòng của 1 file, lưu ý file phải cùng directory với code và .exe
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

static string read_Specific_Line(const string& filename, int targetLine) { // đọc line nào đó của 1 file
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
		cerr << "File nay it hon " << targetLine << " dong" << endl;
	}
	else {
		cerr << "File loi" << endl;
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




// đếm số phần tử chung của 2 vector
static int countCommonElements(const vector<int>& vec1, const vector<int>& vec2) {
	unordered_set<int> elementsSet(vec1.begin(), vec1.end()); // lấy các phần tử ko trùng lặp của vector 1
	int count = 0;

	for (const int& element : vec2) {
		if (elementsSet.find(element) != elementsSet.end()) {
			count++;
		}
	}

	return count;
}


static int linked_l(const Student a, const Student b) { // tính số sở thích/thói quen/bạn chung giữa 2 student
	int temp = 0;
	temp +=  countCommonElements(a.hobbies, b.hobbies) + countCommonElements(a.habits , b.habits) + countCommonElements(a.friendcode, b.friendcode)/2 ;
	return temp;
}
static vector<int> findTopNPositions(const vector<int>& vec, int n) {   // 1/2 code chôm từ document của vector :))
	// Create a vector of pairs to store values and their original positions
	vector<pair<int, int>> indexedVec(vec.size());
	for (int i = 0; i < vec.size(); ++i) {
		indexedVec[i] = { vec[i], i };
	}

	// Sort based on the values in descending order
	sort(indexedVec.begin(), indexedVec.end(), greater<pair<int, int>>());

	// Extract the positions of the top n elements
	vector<int> topPositions;
	for (int i = 0; i < n && i < indexedVec.size(); ++i) {
		topPositions.push_back(indexedVec[i].second);
	}

	return topPositions;
}


static vector<int> probToF(vector<Student>& list, int SSID, int n) { // hàm lấy list f tượng trưung cho độ gần giữa 2 node
	int length = list.size();
	int order = getord(SSID, list);
	vector<int> probality;
	vector<int> SID_compare;
	for (int i = 0; i < length; i++)
	{
		if (i == order) {
			probality.push_back(0);
			SID_compare.push_back(SSID);
		}
		else
		{
			probality.push_back(linked_l(list[getord(SSID, list)], list[i]));
			SID_compare.push_back(list[i].Sid);
		}
	}
	vector<int> topn = findTopNPositions(probality, n);
	vector<int> SID_output;
	for (int k = 0; k < n; k++)
	{
		SID_output.push_back(SID_compare[topn[k]]);
	}
	return SID_output;
}

static int isFriend(const Student a, const Student b) { // hàm check bạn bè
	if ((count(a.friendcode.begin(), a.friendcode.end(), b.Sid)) > 0) {
		return 1;
	}
	else
	{
		return 0;
	}
}

static void DisplayGraph2D(const vector<Student> list) { //hàm hiển thị vector bạn bè
	for (int i = 0; i < list.size(); i++)
	{
		for (int k = 0;k < list.size(); k++) {
			cout << (isFriend(list[i], list[k])) << " ";
		}
		cout << endl;
	}
}


static int findLargestVectorIndex(const vector<Student>& list_St) { // tìm node nhiều bạn nhất
	size_t maxSize = 0;
	int largestIndex = -1;

	for (size_t i = 0; i < list_St.size(); ++i) {
		if (list_St[i].friendcode.size() > maxSize) {
			maxSize = list_St[i].friendcode.size();
			largestIndex = i;
		}
	}

	return list_St[largestIndex].Sid;
}

static vector<int> findLargestVector(const vector<Student>& list_St) { // tìm vector lớn nhất (nhiều phần tử)
	size_t maxSize = 0;
	vector<int> largestVectors;

	for (size_t i = 0; i < list_St.size(); ++i) {
		if (list_St[i].friendcode.size() > maxSize) {
			maxSize = list_St[i].friendcode.size();
			largestVectors.clear();
			largestVectors.push_back(list_St[i].Sid);
		} // tương tự code trên
		else if (list_St[i].friendcode.size() == maxSize) {
			largestVectors.push_back(list_St[i].Sid); // thêm các phần tử khác cùng size, trả lại kq là mssv
		}
	}
	return largestVectors;
}
static vector<string> codeToOutput(vector<int> a, vector<string> b) {  // dịch code sang chữ từ 1 vector từ điển
	vector<string> temp;
	for (int i = 0; i < a.size(); i++)
	{
		temp.push_back(b[a[i] -1]);
	}
	return temp;
}
static void print_full(vector<Student> stdu, vector<string> hbby, vector<string> hbit) { //in full thông tin suc vat
	for (int i = 0; i < stdu.size(); i++)
	{
		cout << "Sinh vien thu " << i + 1 << " : " << endl;
		cout << "Ten : " << stdu[i].name << endl;
		cout << "Mssv : " << stdu[i].Sid << endl;
		cout << "Danh sach ban be : ";
		cout << "\n";
		print_friend(stdu[i].Sid, stdu);
		cout << "\n";
		cout << "So thich (code) : ";
		print_vct(stdu[i].hobbies);
		cout << "\n";
		cout << "So thich (real) : " << "\n";
		print_list_vct(codeToOutput(stdu[i].hobbies, hbby));
		cout << "thoi quen (code): ";
		print_vct(stdu[i].habits);
		cout << "\n";
		cout << "Thoi quen (real) : " << "\n";
		print_list_vct(codeToOutput(stdu[i].habits, hbit));
		cout << "\n";
		cout << "Goi y tim ban :)) : ";
		print_vct(probToF(stdu, stdu[i].Sid, 7));
		cout << "\n";
		cout << "------------------------------------";
		cout << endl;
	}
}
