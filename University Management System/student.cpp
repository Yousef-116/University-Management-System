#include "Logic.h"

void Student::menu()
{
	string ans;
	while (true)
	{
		MENU("STUDENT MENU");
		cout << " 1- View all available courses\n 2- Filter courses\n 3- View details of a specific course\n 4- Register for a course\n 5- View my courses\n 6- View my grades\n 7- Edit my data\n 8- Log out\n -> ";
		getline(cin,ans);
		if(ans == "1")
		{
			the_student->view_available_courses();
		}
		else if(ans == "2")
		{
			the_student->filter_courses();
			
		}
		else if(ans == "3")
		{
			the_student->view_course_details();
		}
		else if(ans == "4")
		{
			the_student->register_for_a_course();
		}
		else if(ans == "5")
		{
			the_student->view_all_courses();
		}
		else if(ans == "6")
		{
			the_student->view_courses_grades_cumulative_GPA();
		}
		else if(ans == "7")
		{
			the_student->edit_data();
		}
		else if (ans == "8")
		{
			the_student->log_out();
		}
		else
		{
			INVALID;
		}
	}

}

bool Student::log_in()
{
	MENU("Student Logging In");
	string ch;
	while (true)
	{
		cout << "\tUsername : "; getline(cin, this->account.email);
		cout << "\tPasswrod : "; getline(cin, this->account.password);
		auto it = the_Students.find(this->account.email);
		if (it != the_Students.end() && it->second.account.password == this->account.password)
		{
			the_student = &it->second;
			MESS("You logged in successfully");
			return true;
		}
		else 
		{
			return true;
			MESS("Wrong username or password");
			cout << "Try again? (Y/y) -> ";
			getline(cin, ch);
			if (ch != "Y" && ch != "y")
				return false;
		}
	}


}

bool Student::log_out()
{
	return false;
}

void Student::view_available_courses()
{
}

void Student::filter_courses()
{
}

void Student::view_course_details()
{
}

void Student::register_for_a_course()
{
}

void Student::view_all_courses()
{
}

void Student::view_courses_grades_cumulative_GPA()
{
}

void Student::edit_data()
{
}

void Student::write_file()
{
}

void Student::read_file()
{
}
