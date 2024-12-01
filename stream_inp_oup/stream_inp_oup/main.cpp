#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include "hobbycode.cpp"
#include "dataprocess.cpp"
#include "habitc.cpp"



int main() {
	vector<Student> list;
	//inputindex(5, list);

	//inputindex(2, list);
	//add_friend(20233391, 20233392, list);
	//add_friend(20233391, 20233393, list);
	//print_friend(20233391, list);
	//cout << "\n \n";
	//cml_input_hobby_tx();
	//cml_input_habit_tx();
	//print_list_vct(output_habit());
	//print_list_vct(outputhb());
	//print_vct(string_to_vector_int_pros("11 12 145 1112 19348527 10938470"));
	//Student a;
	//Student b;
	//Student c;
	//Student d;
	//a.full_ini(20233391, "hiep", { 20233948, 20221987 }, { 1,3,5 }, { 2,6,8,12 });
	//b.full_ini(20233351, "hip", { 20233748, 20223987 }, { 1,3,9 }, { 2,5,6,12 });
	//c.half_ini(20233347, "hai ac");
	//d.full_ini(20233391, "hiep", { 20233948, 20221987 }, { 1,3,5 }, { 2,6,8,12 });
	//for (int i = 0; i < list.size(); i++)
	//{
	//	student_save(list[i]);
	//}





	vector<string> Habit_list;
	vector<string> Hobby_list;
	Habit_list = output_habit();
	Hobby_list = outputhb();
	list = student_retrieve("student_info.txt");
	add_friend(20233330, 20233348, list);

	print_full(list, Hobby_list, Habit_list);
	cout << countLines("student_info.txt") << endl;
	print_vct(probToF(list, 20233341, 7));
	cout << "\n \n \n \n \n \n";
	DisplayGraph2D(list);
	cout << "\n \n \n \n \n \n";
	cout << "Top sinh vien co nhieu ban nhat la : ";
	print_vct(findLargestVector(list));
	cout << "    Voi so ban: " << list[getord(findLargestVector(list)[0], list)].friendcode.size();
	cout << "\n \n \n \n \n \n";
	print_list_vct(Habit_list);
	cout << "\n \n \n \n \n \n";
	print_list_vct(Hobby_list);
	return -1;
}