#include "Logic.h"

void Admin::menu()
{
	string ans;
	Admin admin;
	while (true)
	{
		MENU("ADMIN MENU");
		cout << " 1- Add new student\n 2- Add new course\n 3- View course students\n 4- Add course grade for student\n 5- View student courses\n 6- Edit course data\n 7- Log out\n -> ";
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
			if (admin.log_out())
				break;
		}
		else
		{
			INVALID;
			cout << "Try again? (Y/y) -> "; getline(cin, ans);
			if (ans != "Y" && ans != "y")
				break;
		}
	}
}

bool Admin::log_in()
{
	MENU("ADMIN LOG IN");
	string name, password, ans;
	while (true)
	{
		cout << " Name: "; getline(cin, name);
		cout << " Password: "; getline(cin, password);
		if (name == "admin" && password == "pass123") {
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
	string ans;
	cout << "Are you sure you want to log out? (Y/y) -> ";
	getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		MESS("You logged out successfully");
		return true;
	}
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
