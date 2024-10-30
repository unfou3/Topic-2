#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string studentID;        //MSSV
    string name;             //Tên
    vector<Student> friends; // Danh sách bạn bè (lưu các đối tượng Student)
    vector<string> hobbies;  // Danh sách sở thích
    vector<string> habits;   // Danh sách thói quen

public:
    // Constructor
    Student(string id, string n) {
        studentID = id;
        name = n;
    }

    // Getter cho name
    string getName() const {
        return name;
    }
    // Getter cho studentID
    string getStudentID() const {
        return studentID;
    }

    // Friends
    // Add friend by ID
    void addFriendByID(const string& friendID, const vector<Student>& studentList) {
        for (const Student& student : studentList) {
            if (student.getStudentID() == friendID) {
                friends.push_back(student);
                cout << "Added " << student.getName() << " as a friend of " << name << endl;
                return;
            }
        }
        cout << "Student with ID " << friendID << " not found." << endl;
    }
    // void addFriend(const Student& newFriend) {
    //     friends.push_back(newFriend);
    // }

    void removeFriend(string friendID) {
        for (auto it = friends.begin(); it != friends.end(); ++it) {
            if (it->getStudentID() == friendID) {
                friends.erase(it);
                break;
            }
        }
    }

    // Hiển thị thông tin bạn bè
    void displayFriends() const {
        cout << "Friends of " << name << ": ";
        if (friends.empty()) {
            cout << "No friends added yet." << endl;
        } else {
            for (const Student& friendStudent : friends) {
                cout << friendStudent.getName() << " (ID: " << friendStudent.getStudentID() << ") ";
            }
            cout << endl;
        }
    }

    // Add Hobby
    void addHobby(string hobby) {
        hobbies.push_back(hobby);
    }

    // Remove Hobby
    void removeHobby(string hobby) {
        for (auto it = hobbies.begin(); it != hobbies.end(); ++it) {
            if (*it == hobby) {
                hobbies.erase(it);
                break;
            }
        }
    }

    // Display Hobbies
    void displayHobbies() const {
        cout << "Hobbies of " << name << ": ";
        if (hobbies.empty()) {
            cout << "No hobbies added yet." << endl;
        } else {
            for (string hobby : hobbies) {
                cout << hobby << " ";
            }
            cout << endl;
        }
    }

    // Add Habit
    void addHabit(string habit) {
        habits.push_back(habit);
    }

    // Remove Habit
    void removeHabit(string habit) {
        for (auto it = habits.begin(); it != habits.end(); ++it) {
            if (*it == habit) {
                habits.erase(it);
                break;
            }
        }
    }

    // Display Habits
    void displayHabits() const {
        cout << "Habits of " << name << ": ";
        if (habits.empty()) {
            cout << "No habits added yet." << endl;
        } else {
            for (string habit : habits) {
                cout << habit << ", ";
            }
            cout << endl;
        }
    }

    // Display all
    void displayInfo() const {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        displayFriends();
        displayHobbies();
        displayHabits();
    }
    void displayStudent() const{
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
    }
};
// Hàm tạo sinh viên
Student createStudent() {
    string id, name;
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(); // Loại bỏ ký tự xuống dòng sau khi nhập ID
    cout << "Enter student name: ";
    getline(cin, name);

    Student newStudent(id, name);

    // Thêm sở thích
    int hobbyCount;
    cout << "Enter number of hobbies: ";
    cin >> hobbyCount;
    cin.ignore();
    for (int i = 0; i < hobbyCount; ++i) {
        string hobby;
        cout << "Enter hobby " << i + 1 << ": ";
        getline(cin, hobby);
        newStudent.addHobby(hobby);
    }

    // Thêm thói quen
    int habitCount;
    cout << "Enter number of habits: ";
    cin >> habitCount;
    cin.ignore();
    for (int i = 0; i < habitCount; ++i) {
        string habit;
        cout << "Enter habit " << i + 1 << ": ";
        getline(cin, habit);
        newStudent.addHabit(habit);
    }

    return newStudent;
}

int main() {
    // Tạo danh sách sinh viên
    vector<Student> studentList;

    // Tạo sinh viên mới bằng hàm createStudent
    cout << "Creating new student:" << endl;
    Student student1 = createStudent();
    studentList.push_back(student1);

    // Tạo thêm sinh viên nếu muốn
    char choice;
    cout << "Do you want to create another student? (y/n): ";
    cin >> choice;
    cin.ignore();

    while (choice == 'y' || choice == 'Y') {
        Student newStudent = createStudent();
        studentList.push_back(newStudent);
        cout << "Do you want to create another student? (y/n): ";
        cin >> choice;
        cin.ignore();
    }
    int temp = 1;
    cout << "\nList of student:" << endl;
    for (const Student& student : studentList) {
        cout << "Student number " << temp << ":" << endl;
        temp++;
        student.displayStudent();
        cout << "---------------------------" << endl;

    }
    // Add friends by ID
    int x,y;
    cout << " choose 2 students which u want them become friends" << endl;
    cin >> x;
    cin >> y;
    x--;
    y--;
    if ((x+1 > temp)||(y+1 > temp))
    {
        cout << "The student u want to add friends not in list. Try Again" << endl;
    }
    else {
        studentList[x].addFriendByID(studentList[y].getStudentID(), studentList);
        studentList[y].addFriendByID(studentList[x].getStudentID(), studentList);
    }
    // Hiển thị thông tin tất cả sinh viên
    cout << "\nAll students information:" << endl;
    for (const Student& student : studentList) {
        student.displayInfo();
        cout << "---------------------------" << endl;
    }

    return 0;
}

