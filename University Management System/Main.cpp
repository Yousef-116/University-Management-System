#include "Logic.h"

unordered_map<string, Student>the_Students;
unordered_map<string, Course>the_Courses;
list<Personal_Info>wating_list;
Student* the_student = NULL;
int student_id;

void def()
{

	/*Student s1;
	s1.personal_info.name = "yousef1";
	s1.personal_info.SSN = 44;
	s1.personal_info.account.email = "@1";
	s1.personal_info.account.password = "pass1";
	s1.academic_year = 1;
	s1.id = 1;
	s1.max_hours_allowed = 5;

	Student s2;
	s2.personal_info.name = "yousef2";
	s2.personal_info.SSN = 44;
	s2.personal_info.account.email = "@2";
	s2.personal_info.account.password = "pass2";
	s2.id = 2;
	s2.academic_year = 1;
	s2.max_hours_allowed = 5;

	Student s3;
	s3.personal_info.name = "yousef3";
	s3.personal_info.SSN = 44;
	s3.personal_info.account.email = "@3";
	s3.personal_info.account.password = "pass3";
	s3.id = 3;
	s3.academic_year = 1;
	s3.max_hours_allowed = 5;

	the_Students[s3.personal_info.account.email] = s3;
	the_Students[s2.personal_info.account.email] = s2;
	the_Students[s1.personal_info.account.email] = s1;*/

	//=====================================================================

	Course newCourse;
	newCourse.name = "electronics";
	newCourse.code = "abc1";
	newCourse.hours = 3;
	newCourse.max_number_of_students = 500;
	newCourse.is_required = false;
	newCourse.currant_number_of_students = 0;
	newCourse.pre_required_courses = {};
	newCourse.instructor = "hamada";
	the_Courses.insert({ newCourse.name, newCourse });
	//-----------------------------------------------------------------------
	newCourse.name = "logic";
	newCourse.code = "abc2";
	newCourse.hours = 3;
	newCourse.max_number_of_students = 200;
	newCourse.is_required = true;
	newCourse.currant_number_of_students = 0;
	newCourse.pre_required_courses = { "electronics" };
	newCourse.instructor = "yousama";
	the_Courses.insert({ newCourse.name, newCourse });
	//-----------------------------------------------------------------------
	newCourse.name = "Archi";
	newCourse.code = "abc3";
	newCourse.hours = 3;
	newCourse.max_number_of_students = 300;
	newCourse.is_required = true;
	newCourse.currant_number_of_students = 0;
	newCourse.pre_required_courses = { "logic", "electronics" };
	newCourse.instructor = "Hanan";
	the_Courses.insert({ newCourse.name, newCourse });
	//-----------------------------------------------------------------------
	newCourse.name = "algebra";
	newCourse.code = "abc4";
	newCourse.hours = 2;
	newCourse.max_number_of_students = 400;
	newCourse.is_required = false;
	newCourse.currant_number_of_students = 0;
	newCourse.pre_required_courses = {};
	newCourse.instructor = "Gus";
	the_Courses.insert({ newCourse.name, newCourse });
}

void write_waiting_list()
{

}

void read_waiting_list()
{

}

void Read()
{
	Student::read_file();
	Course::read_file();
	read_waiting_list();
}

void Write()
{
	Student::write_file();
	Course::write_file();
	write_waiting_list();
}

int main()
{
	def();
	Read();
	string ans;
	while (true)
	{
		MENU("MAIN MENU");
		cout << " 1- Login as Admin\n 2- Login as Student\n 3- Regist\n 4- Exit\n -> ";

		getline(cin, ans);
		if (ans == "1")
		{
			Admin theAdmin;
			if (theAdmin.log_in())
			{
				theAdmin.menu();
			}
		}
		else if (ans == "2")
		{
			Student newStudent;
			if (newStudent.log_in())
			{
				the_student->menu();
			}
		}
		else if (ans == "3")
		{
			Student newStudent;
			newStudent.regist();
		}
		else if (ans == "4")
		{
			cout << "\n Are you sure you want to exit? (Y/y) -> ";
			getline(cin, ans);
			if (ans == "Y" || ans == "y")
				break;
		}
		else
		{
			INVALID;
		}
	}

	Write();
	return 0;
}
