#include "Logic.h"

Student::Student()
{
	this->GPA = this->academic_year = this->id = this->max_hours_allowed = 0;
}

Student::Student(Personal_Info info, short int academic_year, short int max_hours_allowed)
{
	this->personal_info = info;
	this->academic_year = academic_year;
	this->max_hours_allowed = max_hours_allowed;
}

void Student::menu()
{
	string ans;
	while (true)
	{
		MENU("STUDENT MENU");
		cout << " 1- View all available courses\n 2- Filter courses\n 3- View details of a specific course\n 4- Register for a course\n 5- View all courses\n 6- View my coureses\n 7- View my grades\n 8- Edit personal info\n 9- Log out\n -> ";
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
			the_student->register_for_course();
		}
		else if (ans == "5")
		{
			the_student->view_all_courses();
		}
		else if (ans == "6")
		{
			the_student->view_my_courses();
		}
		else if (ans == "7")
		{
			the_student->view_courses_grades();
		}
		else if (ans == "8")
		{
			the_student->edit_personal_info();
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
		if (the_student->finished_courses.find(it->first) != the_student->finished_courses.end()) // check if he alrady finshed course  	
		{
			Course co = it->second;
			for (auto check : co.pre_required_courses)
			{
				if (the_student->finished_courses.find(check) == the_student->finished_courses.end())
				{
					flag = false;
					break;
				}
			}
		}

		if (flag) {
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
	string ans;
	if (the_Courses.size() == 0) {
		MESS("There is no coureses yet");
		cout << "\nEnter any thing to exit -> "; getline(cin, ans);
	}

	auto it = the_Courses.begin();
	int i = 1;
	cout << "courses : \n";
	while (it != the_Courses.end())
	{
		cout << i << "- " << it->second.name << "\n";
		i++;
		it++;
	}

	while (true)
	{
		cout << "\n\n Select a course to veiw it's details or enter \'0\' to go back -> ";
		cin >> i; cin.ignore();
		if (i == 0) return;
		else if (i < 0 || i > the_Courses.size()) {
			INVALID;
			cout << "\n Try again? (Y/y) -> ";
			getline(cin, ans);
			if (ans != "Y" && ans != "y")
				return;
		}
		else break;
	}
	it = the_Courses.begin();
	advance(it, i - 1);

	//cout << "Enter course number : "; getline(cin, ans);
	//Course newone = the_Courses[ans];

	cout << "\n Course name : " << it->second.name;
	cout << "\n Course code : " << it->second.code;
	cout << "\n Is required : " << (it->second.is_required ? "Yes" : "No");
	cout << "\n Course maxmun number of students : " << it->second.max_number_of_students;
	cout << "\n Course hours : " << it->second.hours;
	cout << "\n Course instructor : " << it->second.instructor;
	i = 1;
	for (auto pre : it->second.pre_required_courses)
	{
		cout << i << "- " << pre << "\n";
	}
	cout << "\nEnter any thing to exit -> "; getline(cin, ans);
}

void Student::register_for_course()
{
	unordered_map<int, string>available_ones;
	MENU("available Courses");
	auto it = the_Courses.begin();
	int i = 1;
	bool flag = true;
	while (it != the_Courses.end())
	{
		if (the_student->finished_courses.find(it->first) == the_student->finished_courses.end() && the_student->courses_in_progress.find(it->first) == the_student->courses_in_progress.end()) // check if he alrady finshed course  	
		{
			Course co = it->second;
			for (auto check : co.pre_required_courses)
			{
				if (the_student->finished_courses.find(check) == the_student->finished_courses.end())
				{
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << i << "- " << it->second.name << "\n";
				available_ones[i] = it->second.name;
				i++;
			}
		}

		it++;
		flag = true;
	}
	
	string ans;
	while (true)
	{
		cout << "\n\n Select a course to register or enter \'0\' to go back -> ";
		cin >> i; cin.ignore();
		if (i == 0) return;
		else if (i < 0 || i > available_ones.size()) {
			INVALID;
			cout << "\n Try again? (Y/y) -> ";
			getline(cin, ans);
			if (ans != "Y" && ans != "y")
				return;
		}
		else break;
	}
	
	the_student->courses_in_progress.insert(available_ones[i]);
	the_Courses[available_ones[i]].students.push_back(the_student->personal_info.name);
	MESS("Added successfully");

	cout << "Enter any thing to exit -> "; getline(cin, ans);

}

void Student::view_all_courses()
{
	MENU("View All Courses");
	string ans;
	if (the_Courses.size() == 0) {
		MESS("There is no courses yet");
	}
	else {
		auto it = the_Courses.begin();
		int i = 1;
		while (it != the_Courses.end())
		{
			cout << "courses : \n";
			cout << i << "- " << it->second.name << "\n";
			i++;
			it++;
		}
	}
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::view_my_courses()
{
	MENU("View Your Courses");
	string ans;
	if (the_student->courses_in_progress.size() == 0) {
		MESS("There is no courses in progress yet");
	}
	else {
		int i = 1;
		for (string co : the_student->courses_in_progress)
		{
			cout << i << "- " << co << "\n";
			i++;
		}
	}
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::view_finished_courses() 
{
	MENU("Viewing Finished Courses");
	string ans;
	if (the_student->finished_courses.size() == 0) {
		MESS("There is no finished courses yet");
	}
	else {
		int i = 1;
		for (auto course : the_student->finished_courses)
		{
			cout << i << "- " << course.first << "\tGrade: " << course.second << "\n";
			i++;
		}
	}
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::view_courses_grades()
{
	MENU("All Courses grades");
	string ans;
	if (the_student->finished_courses.size() == 0) {
		MESS("There is no finished courses yet");
	}
	else 
	{
		auto it = the_student->finished_courses.begin();
		while (it != the_student->finished_courses.end())
		{
			cout << it->first << " : " << it->second << "\n";
		}
	}
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::edit_personal_info()
{
	MENU("Edit your personal info");
	cout << "your data : ";
	cout << "\n1- Name : " << the_student->personal_info.name;
	cout << "\n2- SSN : " << the_student->personal_info.SSN;
	cout << "\n3- Adress : " << the_student->personal_info.address;
	cout << "\n4- Pirsonal email : " << the_student->personal_info.pirsonal_email;
	cout << "\n5- Account email : " << the_student->personal_info.account.email;
	cout << "\n6- Accont password : " << the_student->personal_info.account.password;

	while (true)
	{
		cout << "\nEnter what you need to change enter \'0\' to go back ->: ";
		string ans;
		getline(cin, ans);
		if(ans=="0")
		{
			break;
		}
		else if (ans == "1")
		{
			cout << "Enter new Name : ";
			getline(cin, the_student->personal_info.name);
		}
		else if (ans == "2")
		{
			cout << "Enter new SSN : ";
			cin >> the_student->personal_info.SSN;
			cin.ignore();
		}
		else if (ans == "3")
		{
			cout << "Enter new Address : ";
			getline(cin, the_student->personal_info.address);
		}
		else if (ans == "4")
		{
			cout << "Enter new Pirsonal email : ";
			getline(cin, the_student->personal_info.pirsonal_email);
		}
		else if (ans == "5")
		{
			cout << "Enter new Account email : ";
			getline(cin, the_student->personal_info.account.email);
		}
		else if (ans == "6")
		{
			cout << "Enter new Account pssword : ";
			getline(cin, the_student->personal_info.account.password);
		}
		else
		{
			INVALID;
			cout << "Try again? (Y/y) -> "; getline(cin, ans);
			if (ans != "Y" && ans != "y")
				break;
		}
	}
	//cout << "\nProgress hours : " << the_student->progress_hours;
	//cout << "\nfinshd courses : \n";
	//int i = 1;
	//for (auto it = the_student->finished_courses.begin(); it != the_student->finished_courses.end(); it++)
	//{
	//	cout << i << "- " << it->first << "\t\t" << it->second << "\n";
	//	i++;
	//}
	//i = 1;
	//for (string co : the_student->courses_in_progress)
	//{
	//	cout << i << "- " << co << "\n";
	//	i++;
	//}
	string ans;
	cout << "Enter any thing to exit -> "; getline(cin, ans);
}

void Student::write_file()
{
}

void Student::read_file()
{
}
