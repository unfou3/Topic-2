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

	list = student_retrieve("student_info.txt");
	//for (int i = 0; i < list.size(); i++)
	//{
	//	student_save(list[i]);
	//}
	print_full(list);
	cout << countLines("student_info.txt");
	return -1;
}