#include "Logic.h"

Student::Student()
{
}

Student::Student(Personal_Info info, int id, short int academic_year, short int max_hours_allowed)
{
	this->personal_info = personal_info;
	this->id = id;
	this->academic_year = academic_year;
	this->max_hours_allowed = max_hours_allowed;
}

void Student::menu()
{
	string ans;
	while (true)
	{
		MENU("STUDENT MENU");
		cout << " 1- View all available courses\n 2- Filter courses\n 3- View details of a specific course\n 4- Register for a course\n 5- View all courses\n 6- View my coureses\n 7- View my grades\n 8- Edit my data\n 9- Log out\n -> ";
		getline(cin, ans);
		if (ans == "1")
		{
			the_student->view_available_courses();
		}
		else if (ans == "2")
		{
			the_student->filter_courses();
		}
		else if (ans == "3")
		{
			the_student->view_course_details();
		}
		else if (ans == "4")
		{
			the_student->register_for_a_course();
		}
		else if (ans == "5")
		{
			the_student->view_all_courses();
		}
		else if (ans == "6")
		{
			the_student->view_my_courese();
		}
		else if (ans == "7")
		{
			the_student->view_courses_grades();
		}
		else if (ans == "8")
		{
			the_student->edit_data();
		}
		else if (ans == "9")
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
		cout << " Email: "; getline(cin, this->personal_info.account.email);
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
	cout << "\tAddress : ";
	getline(cin, info.address);
	cout << "\tPhone number : ";
	getline(cin, info.phone_number);
	cout << "\tPirsonal email : ";
	getline(cin, info.pirsonal_email);
	cout << "\tPassword : ";
	getline(cin, info.account.password);
	cout << "\tConfirme Password : ";
	getline(cin, info.account.password);

	string ans;
	cout << "\nConfirm adding request? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		wating_list.push_back(info);
		MESS("Request sent successfully");
		cout << "Enter any thing to exit -> "; getline(cin, ans);
		return true;
	}

	MESS("Request canceled successfully");
	return false;
}

void Student::view_available_courses()
{
	MENU("view available Courses");
	auto it = the_Courses.begin();
	int i = 1;
	bool flag = true;
	while (it != the_Courses.end())
	{
		if(the_student->finished_courses.find(it->first) != the_student->finished_courses.end()) // check if he alrady finshed course  	
		{
			Course co= it->second;
			for(auto check: co.pre_required_courses)
			{
				if(the_student->finished_courses.find(check)== the_student->finished_courses.end())
				{
					flag=false;
					break;
				}
			}
		}

		if(flag){
			cout << i << "- " << it->second.name << "\n";
			i++;
		}

		it++;
		flag = true;
	}
	string ans;
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::filter_courses()
{
}

void Student::view_course_details()
{
	MENU("Courses Details");
	auto it = the_Courses.begin();
	int i = 1;
	while (it != the_Courses.end())
	{
		cout << "courses : \n";
		cout << i << "- " << it->second.name << "\n";
		i++;
		it++;
	}
	string ans;
	cout << "Enter course name : "; getline(cin, ans);
	Course newone = the_Courses[ans];
	cout << "\n Course name : " << newone.name;
	cout << "\n Course code : " << newone.code;
	cout << "\n Course requirment : " << newone.is_required;
	cout << "\n Course maxmun number of students : " << newone.max_number_of_students;
	cout << "\n Course hours : " << newone.hours;
	cout << "\n Course instructor : " << newone.instructor;
	i = 1;
	for(auto pre : newone.pre_required_courses)
	{
		cout << i << "- " << pre<< "\n" ;
	}
	string out;
	cout << "Enter any thing to exit -> "; getline(cin, out);
}

void Student::register_for_a_course()
{
	

}

void Student::view_all_courses()
{
	MENU("View All Courses");
	auto it = the_Courses.begin();
	int i = 1;
	while (it != the_Courses.end())
	{
		cout << "courses : \n";
		cout << i << "- " << it->second.name << "\n";
		i++;
		it++;
	}
	string ans;
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::view_my_courese()
{
}

void Student::view_courses_grades()
{
	MENU("All Courses grades");
	auto it = the_student->finished_courses.begin();
	while(it!= the_student->finished_courses.end())
	{
		cout << it->first << " : " << it->second<<"\n";
	}
	string ans;
	cout << "Enter any thing to exit -> "; getline(cin, ans);
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
