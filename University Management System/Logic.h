#include <iostream>
#include <set>
#include <list>
#include <unordered_map>
#include <string>
#include <windows.h>
#define MENU(word) Sleep(500); system("cls"); cout << "<<<<<<<<<<<<<<< " << word << " >>>>>>>>>>>>>>>\n\n"
#define MESS(word) cout << "\n========== " << word << " ==========\n\n"; Sleep(300)
#define INVALID cout << "\aInvalid choice, please try again..\n"
using namespace std;


struct Course {
public:
	string name;
	string code;
	bool is_requiremed;
	int max_number_of_students;
	list<string> pre_required_courses;
	int hours;
	string instructor;

public:
	static void write_file();
	static void read_file();
};


struct Account
{
	string email;
	string password;
};


class Student 
{
	string name;
	int SSN;
	string address;
	string phone_number;
	string pirsonal_email;

public:
	int id;
	Account account;
	short int max_hours_allowed;
	unordered_map<string, float>finished_courses; // (float for) grade of course for strudet;
	set<string>courses_in_progress;
	short int academic_year;
	double GPA;

public:
	void menu();
	bool log_in();
	bool log_out();
	void view_available_courses();
	void filter_courses(); //(or filter by hours,or by requiremnt "bool " cours);
	void view_course_details();
	void register_for_a_course();
	void view_all_courses();
	void view_courses_grades_cumulative_GPA();
	void edit_data();
	static void write_file();
	static void read_file();
};


class Admin 
{
public:
	Account account;

public:
	void menu();
	bool log_in();
	bool log_out();
	void add_strudent();
	void add_course();
	void edit_course();
	void view_course_strudets();
	void set_course_grade();
	void view_student_courses(); //(Finished - Progressed) of a specific student.
	static void write_file(); 
	static void read_file(); 
};


extern unordered_map<string, Student>the_Students; // {username, object}
extern unordered_map<string, Student>the_Coursese; // {code, object}
extern unordered_map<string, Student>wating_list;
extern int student_id;
extern Student* the_student;