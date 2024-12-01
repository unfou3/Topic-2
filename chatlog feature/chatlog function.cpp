#include <iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<cctype>
using namespace std;
struct chatmessage { //mot tin nhan
	string sender; //nguoi gui
	string content; //noi dung
	string time; //thoi gian
};
string getcurrenttime() {
	time_t now = time(NULL); //thoi gian duoi dang giay tu 1/1/1970
	string str = ctime(&now); //dinh dang lai ve dang string 
	str.erase(str.find('\n')); //xoa ki tu xuong dong cua ham ctime()
	return str;
}
//gui mot tin nhan len chatlog
void sendmessage(const string& sender, const string& content, vector<chatmessage>& chatlog) {
	chatmessage message;
	message.sender = sender;
	message.content = content;
	message.time = getcurrenttime();
	chatlog.push_back(message);
}
//ham hien thi message
void readmessage(chatmessage a) {
	cout << "[" << a.time << "] " << a.sender << ": " << a.content << endl;
}
//hien thi n message gan nhat trong chatlog
void displaychatlog(const vector<chatmessage>& chatlog, int n) {
	if (n <= 0 || n > chatlog.size()) { 
		cout << "n must in range 1 to " << chatlog.size() << endl;
		return;
	}
	if (chatlog.empty()) {
		cout << "No messages yet"; return;
	}
	for (int i = n; i >=1; i--) {
		readmessage(chatlog[chatlog.size()-i]);//hien thi tin nhan thu i gan nhat
	}
}
//xoa, thu hoi tin nhan thu n gan nhat
void deletemessage(vector<chatmessage>& chatlog, int n) {
	if (n <= 0 || n > chatlog.size()) {
		cout << "n must in range 1 to " << chatlog.size() << endl;
		return;
	}
	chatlog.erase(chatlog.begin() + chatlog.size() - n);//xoa, thu hoi tin nhan thu n gan nhat
	cout << "Message deleted successfully.\n";
}
//sua tin nhan thu n gan nhat
void editmessage(vector<chatmessage>& chatlog, int n,const string& newcontent) {
	if(n <= 0 || n > chatlog.size()) {
		cout << "n must in range 1 to " << chatlog.size() << endl;
		return;
	}
	chatlog[chatlog.size() - n].content = newcontent;
}
///chuc nang tim kiem tim kiem
void findMessages(const std::vector<chatmessage>& chatLog, const string& keyword) {
	if (chatLog.empty()) {
		cout << "Chat log is empty. Nothing to search.\n";
		return;
	}
	//lower keyword de tim kiem khong phu thuoc vao chu in hoa hay in thuong
	string keywordLower = keyword;
	transform(keywordLower.begin(), keywordLower.end(), keywordLower.begin(), ::tolower); 

	bool found = false; //thong bao ket qua tim kiem
	for (int i = 0; i < chatLog.size(); i++) {
		//lower de tim kiem khong phu thuoc vao chu in hoa hay in thuong
		string senderLower = chatLog[i].sender;
		string contentLower = chatLog[i].content;

		transform(senderLower.begin(), senderLower.end(), senderLower.begin(), ::tolower); // Chuyển sender sang chữ thường
		transform(contentLower.begin(), contentLower.end(), contentLower.begin(), ::tolower); // Chuyển content sang chữ thường
		
		//sd ham find() de tim kiem keyword co trong chuoi tin nhan hay khong
		//neu ko tim thay thi ham find() tra ve hang so npos
		if (senderLower.find(keywordLower) != string::npos || contentLower.find(keywordLower) != string::npos) {
			cout << "\nSearch result: \n";
			readmessage(chatLog[i]);
			found = true;
		}
	}
	if (!found) {
		cout << "No messages found containing the keyword: \"" << keyword << "\"\n";
	}
}
//test
int main() {
	vector<chatmessage> chatLog = {
		{"Nam", "Hello!", "Thu Nov 30 10:05:42 2024"},
		{"Hoa", "Hi, Nam!", "Thu Nov 30 10:07:02 2024"},
		{"Linh", "How are you?", "Thu Nov 30 10:09:42 2024"},
		{"Trang", "I'm good. Thanks!", "Thu Nov 30 11:05:49 2024"}
	};
	int n = chatLog.size();
	// Hiển thị danh sách tin nhắn trước khi chỉnh sửa
	displaychatlog(chatLog, chatLog.size());

	// Chỉnh sửa tin nhắn gần nhất thứ 2
	string newContent = "I'm feeling great today!";
	editmessage(chatLog, 2, newContent);

	//Hiển thị danh sách tin nhắn sau khi chỉnh sửa
	cout << "\nDanh sách tin nhắn sau khi chỉnh sửa:\n";
	displaychatlog(chatLog, chatLog.size());
	findMessages(chatLog, "E");
	cout << "send mesage\n";
	sendmessage("You", "lol", chatLog);
	displaychatlog(chatLog, chatLog.size());

	return 0;
}
