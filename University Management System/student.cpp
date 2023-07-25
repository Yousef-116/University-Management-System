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
			the_student->view_courses_grades();
		}
		else if(ans == "7")
		{
			the_student->edit_data();
		}
		else if (ans == "8")
		{
			if (the_student->log_out())
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

bool Student::log_in()
{
	MENU("Student Logging In");
	string ch;
	while (true)
	{
		cout << " Username: "; getline(cin, this->personal_info.account.email);
		cout << " Passwrod: "; getline(cin, this->personal_info.account.password);
		auto it = the_Students.find(this->personal_info.account.email);
		if (it != the_Students.end() && it->second.personal_info.account.password == this->personal_info.account.password)
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
	string ans;
	cout << "Are you sure you want to log out? (Y/y) -> ";
	getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		MESS("You logged out successfully");
		return true;
	}
	return false;
}

bool Student::regist()
{
	MENU("Student Regist");
	Personal_Info info;
	cout << "Enter \n";
	cout << "\n\tName : ";
	getline(cin, info.name);
	cout << "\tSSN : ";
	cin >> info.SSN;
	cin.ignore();
	//getline(cin, newstudent.SSN);
	cout << "\n\tAddress : "; 
	getline(cin, info.address);
	cout << "\n\tPhone number : ";
	getline(cin, info.phone_number);
	cout << "\n\tPirsonal email : ";
	getline(cin, info.pirsonal_email);
	cout << "\n\tPassword : ";
	getline(cin, info.account.password);
	cout << "\n\tConfirme Password : ";
	getline(cin, info.account.password);

	string ans;
	cout << "\nConfirm adding request? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		wating_list.push_back(info);
		MESS("Request sent successfully");
		cout << "Enter any thing to exit -> "; getline(cin, ans) ;
		return true;
	}

	MESS("Request canceled successfully");
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

void Student::view_courses_grades()
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
