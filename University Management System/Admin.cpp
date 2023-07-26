#include "Logic.h"

void Admin::menu()
{
	string ans;
	Admin admin;
	while (true)
	{
		MENU("ADMIN MENU");
		cout << " 1- Add new student\n 2- Add new course\n3- Confirm add request\n 4- View course students\n 5- Add course grade for student\n 6- View student courses\n 7- Edit course data\n 8- Log out\n -> ";
		getline(cin, ans);
		if (ans == "1")
		{
			admin.add_student();
		}
		else if (ans == "2")
		{
			admin.add_course();
		}
		else if (ans == "3")
		{
			admin.confirm_add_request();
		}
		else if (ans == "4")
		{
			admin.view_course_students();
		}
		else if (ans == "5")
		{
			admin.set_course_grade();
		}
		else if (ans == "6")
		{
			admin.view_student_courses();
		}
		else if (ans == "7")
		{
			admin.edit_course();
		}
		else if (ans == "8")
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

void student_autoGenerate(Student& newStudent)
{
	newStudent.id = ++student_id;
	newStudent.personal_info.account.email = to_string(newStudent.id) + "@cis.com";
}

void Admin::add_student()
{
	MENU("ADD STUDENT");
	Student newStudent;
	cout << "Enter \n";
	cout << "\n\tName: ";
	getline(cin, newStudent.personal_info.name);
	cout << "\tSSN: ";
	cin >> newStudent.personal_info.SSN;
	cin.ignore();
	cout << "\tPassword: ";
	getline(cin, newStudent.personal_info.account.password);
	cout << "\tAcadimic year: ";
	cin >> newStudent.academic_year;
	cout << "\tMax hours allowed: ";
	cin >> newStudent.max_hours_allowed;
	cin.ignore();

	//Automatic
	student_autoGenerate(newStudent);

	string ans;
	cout << "\nConfirm adding student? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		the_Students.insert({ newStudent.personal_info.account.email, newStudent });
		MESS("Request sent successfully");
	}
	else
		MESS("Request canceled successfully");

	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void Admin::confirm_add_request()
{
	MENU("CONFIRM ADD REQUESTS");
	string ans;
	if (wating_list.size() == 0) {
		MESS("There is no adding requests");
		cout << " Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	cout << "Add Requests: \n";
	short int ctr = 0;
	for (const auto& req : wating_list)
	{
		cout << ++ctr << "- \tName: " << req.name;
		cout << "\n\tSSN: " << req.SSN;
		cout << "\n\tAddress: " << req.address;
		cout << "\n\tPhone number: " << req.phone_number;
		cout << "\n\tPirsonal email: " << req.pirsonal_email;
		cout << "\n\tpassword: " << req.account.password;
	}

	int i;
	while (true)
	{
		cout << "\n\n Select a request to confirm or enter \'0\' to go back -> ";
		cin >> i; cin.ignore();
		if (i == 0) return;
		else if (i < 0 || i > wating_list.size()) {
			INVALID;
			cout << "\n Try again? (Y/y) -> ";
			getline(cin, ans);
			if (ans != "Y" && ans != "y")
				return;
		}
		else break;
	}

	auto it = wating_list.begin();
	advance(it, i - 1);
	cout << " Confirm adding request? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		Student newStudent(*it, 1, 15);
		student_autoGenerate(newStudent);
		cout << "the email: " << newStudent.personal_info.account.email << endl;
		cout << "the password: " << newStudent.personal_info.account.password << endl;
		the_Students.insert({ newStudent.personal_info.account.email, newStudent });
		MESS("The student added successfully");
	}
	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void Admin::add_course()
{
	MENU("ADD COURSE");
	string ans;
	Course newCourse;
	cout << "Enter Course: ";
	cout << "\n\tName: "; getline(cin, newCourse.name);
	cout << "\tCode: "; cin >> newCourse.code;
	cout << "\tMax number of students: "; cin >> newCourse.max_number_of_students;
	cout << "\tHours: "; cin >> newCourse.hours;
	cin.ignore();
	cout << "\tInstructor: "; getline(cin, newCourse.instructor);
	cout << "\tIs it required? (Y/y) -> ";  getline(cin, ans);
	if (ans == "Y" || ans == "y")
		newCourse.is_required = true;

	cout << "\nConfirm adding course? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		the_Courses.insert({ newCourse.name, newCourse });
		MESS("Course added successfully");
	}
	else
		MESS("Action canceled successfully");

	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void Admin::edit_course()
{
}

void Admin::view_course_students()
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
