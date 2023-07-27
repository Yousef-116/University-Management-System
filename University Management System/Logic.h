#include <iostream>
#include <set>
#include <list>
#include <unordered_map>
#include <string>
#include <windows.h>
#include <fstream>
#define MENU(word) Sleep(500); system("cls"); cout << "<<<<<<<<<<<<<<< " << word << " >>>>>>>>>>>>>>>\n\n"
#define MESS(word) cout << "\n========== " << word << " ==========\n\n"; Sleep(300)
#define INVALID cout << "\aInvalid choice, please try again..\n"
using namespace std;

class Course {
public:
	string name;
	string code;
	bool is_required;
	int max_number_of_students;
	int currant_number_of_students;
	list<string> pre_required_courses;// course name
	list<string> students; //student name
	int hours;
	string instructor;

public:
	Course() ;
	static void write_file();
	static void read_file();
};

struct Account
{
	string email;
	string password;
};

struct Personal_Info
{
	string name;
	int SSN;
	string address;
	string phone_number;
	string pirsonal_email;
	Account account;
};

class Student 
{
public:
	Personal_Info personal_info;
	int id;
	short int max_hours_allowed;
	short int progress_hours;
	unordered_map<string, float>finished_courses; // (float for) grade of course for strudet;
	set<string>courses_in_progress;
	short int academic_year;
	double GPA;

public:
	Student() = default;
	Student(Personal_Info info, short int academic_year, short int max_hours_allowed);
	void menu();
	bool log_in();
	bool log_out();
	bool regist();
	void view_available_courses();
	void filter_courses(); //(or filter by hours,or by requiremnt "bool " cours);
	void view_course_details();
	void register_for_course();
	void view_all_courses();
	void view_my_courses();
	void view_finished_courses();
	void view_courses_grades();
	void edit_personal_info();
	static void write_file();
	static void read_file();
};


class Admin 
{
public:
	Admin() = default;
	void menu();
	bool log_in();
	bool log_out();
	void add_student();
	void confirm_add_request();
	void add_course();
	void edit_course();
	void view_course_students();
	void set_course_grade();
	void view_student_courses(); //(Finished - Progressed) of a specific student.
	static void write_file(); 
	static void read_file(); 
};


extern unordered_map<string, Student>the_Students; // {username, object}
extern unordered_map<string, Course> the_Courses; // {course name, object}
extern list<Personal_Info>wating_list;
extern int student_id;
extern Student* the_student;
