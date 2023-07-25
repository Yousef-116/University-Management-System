#include "Logic.h"

void Admin::menu()
{
	string ans;
	Admin admin;
	while (true)
	{
		MENU("ADMIN MENU");
		cout << " 1- Add new student\n 2- Add new course\n 3- View course students\n 4- Add course grade for student\n 5- View student courses\n 6- Edit course data\n 7- Logout\n -> ";
		getline(cin, ans);
		if (ans == "1")
		{
			admin.add_strudent();
		}
		else if (ans == "2")
		{
			admin.add_course();
		}
		else if (ans == "3")
		{
			admin.view_course_strudets();
		}
		else if (ans == "4")
		{
			admin.set_course_grade();
		}
		else if (ans == "5")
		{
			admin.view_student_courses();
		}
		else if (ans == "6")
		{
			admin.edit_course();
		}
		else if (ans == "7")
		{
			admin.log_out();
		}
		else
		{
			INVALID;
		}
	}
}

bool Admin::log_in()
{
	MENU("ADMIN LOG IN");
	string name, password, ans;
	while (true)
	{
		cout << "\tName: ";
		getline(cin, name);
		cout << "\tPassword: ";
		getline(cin, password);
		if (name == "admin123" && password == "pass123") {
			MESS("You logged in successfully");
			return true;
		}
		MESS("Wrong name or password");
		cout << "Try agian? (Y/y) -> ";
		getline(cin, ans);
		if (ans != "Y" || ans != "y")
			return false;
	}
}

bool Admin::log_out()
{
	return false;
}
void Admin::add_strudent()
{
}
void Admin::add_course()
{
}
void Admin::edit_course()
{
}
void Admin::view_course_strudets()
{
}
void Admin::set_course_grade()
{
}
void Admin::view_student_courses()
{
}
void Admin::write_file()
{
}
void Admin::read_file()
{
}
