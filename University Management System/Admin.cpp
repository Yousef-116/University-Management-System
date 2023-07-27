#include "Logic.h"

void Admin::menu()
{
	string ans;
	Admin admin;
	while (true)
	{
		MENU("ADMIN MENU");
		cout << " 1- Add new student\n 2- Add new course\n 3- Confirm add request\n 4- View course students\n 5- Add course grade for student\n 6- View student courses\n 7- Edit course data\n 8- Log out\n -> ";
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
		the_Students.insert({ newStudent.personal_info.account.email, newStudent });
		wating_list.erase(it);
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
	newCourse.is_required = (ans == "Y" || ans == "y" ? true : false);

	cout << "\nConfirm adding course? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		the_Courses.insert({ newCourse.name, newCourse });
		MESS("Course added successfully");
	}
	else
		MESS("Action canceled successfully");

	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void add_pre_required_course(Course* course)
{
	MENU("Add \'" + course->name + "\' Pre-courses");
	string ans;
	short int i, course_num;
	list<string>available_courses;
	cout << "The available courses: \n";
	for (const auto& crs : the_Courses) {
		if (crs.second.name != course->name && crs.second.pre_required_courses.find(course->name) == crs.second.pre_required_courses.end()) {
			available_courses.push_back(crs.second.name);
		}
	}

	if (available_courses.size() == 0)
	{
		MESS("There is no available courses to add to pre-required courses");
		cout << " Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	i = 0;
	for (const string& ava_crs : available_courses)
		cout << "\n " << ++i << "- " << ava_crs;

	while (true)
	{
		cout << "\n\n Select a course to add to pre-required courses or enter \'0\' to go back -> ";
		cin >> i; cin.ignore();
		if (i == 0) return;
		else if (i < 0 || i > available_courses.size()) {
			INVALID;
			cout << "\n Try again? (Y/y) -> ";
			getline(cin, ans);
			if (ans != "Y" && ans != "y")
				return;
		}
		else break;
	}
	auto it = available_courses.begin();
	advance(it, i - 1);
	
	cout << "Confirm adding \'" << *it << "\' to pre-required courses? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		MESS("Adding process completed successfully");
		course->pre_required_courses.insert(*it);
	}
	else
		MESS("Adding process canceled successfully");

	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void edit_pre_required_course(Course* course)
{
	MENU("Edit \'" + course->name + "\' Pre-courses");
	string ans;
	if (course->pre_required_courses.size() == 0) {
		MESS("There is no Pre-courses to edit");
		cout << "Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	short int i = 0;
	set<string>::iterator pre = course->pre_required_courses.begin();
	cout << " The Pre-courses: \n";
	for (const string& pre_crs : course->pre_required_courses)
		cout << "\n\t" << ++i << "- " << pre_crs;

	while (true)
	{
		cout << "\n\n Select a pre-required course to edit or enter \'0\' to go back -> "; 
		cin >> i; cin.ignore();
		if (i == 0) break;
		else if (i < 0 || i > course->pre_required_courses.size())
		{
			INVALID;
			cout << " Try again? (Y/y) -> "; getline(cin, ans);
			if (ans != "Y" || ans != "y")
				return;
		}
		else break;
	}

	string new_pre_required;
	cout << " Change \'" << *pre << "\' to: "; getline(cin, new_pre_required);
	cout << " Confirm changing \'" << *pre << "\' to \'" << new_pre_required << "\'? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		course->pre_required_courses.erase(pre);
		course->pre_required_courses.insert(new_pre_required);
		MESS("Editing process completed successfully");
	}
	else
		MESS("Editing process canceled successfully");
	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void remove_pre_required_course(Course* course)
{
	MENU("Remove \'" + course->name + "\' Pre-courses");
	string ans;
	if (course->pre_required_courses.size() == 0) {
		MESS("There is no Pre-courses to remove");
		cout << "Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	short int i = 0;
	set<string>::iterator pre = course->pre_required_courses.begin();
	cout << " The Pre-courses: \n";
	for (const string& pre_crs : course->pre_required_courses)
		cout << "\n\t" << ++i << "- " << pre_crs;

	while (true)
	{
		cout << "\n\n Select a pre-required course to remove or enter \'0\' to go back -> ";
		cin >> i; cin.ignore();
		if (i == 0) break;
		else if (i < 0 || i > course->pre_required_courses.size())
		{
			INVALID;
			cout << " Try again? (Y/y) -> "; getline(cin, ans);
			if (ans != "Y" || ans != "y")
				return;
		}
		else break;
	}

	cout << " Confirm removing \'" << *pre << "\' from pre-required courses? (Y/y) -> "; getline(cin, ans);
	if (ans == "Y" || ans == "y") {
		MESS("Removing process completed successfully");
		course->pre_required_courses.erase(pre);
	}
	else
		MESS("Removing process canceled successfully");
	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void Admin::edit_course()
{
	MENU("EDIT COURSE");
	string ans;
	if (the_Courses.size() == 0) {
		MESS("There is no courses yet");
		cout << " Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	int i = 0;
	cout << " The Coureses: ";
	for (const auto& course : the_Courses)
		cout << "\n\t" << ++i << "- " << course.second.name;

	while (true)
	{
		cout << "\n\n Select a courese to edit or enter \'0\' to go back -> ";
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

	auto it = the_Courses.begin();
	advance(it, i - 1);
	Course* course = &it->second;

	while (true)
	{
		MENU("EDIT COURSE");
		cout << " Edit Course:"
			"\n\t1- Name: " << course->name <<
			"\n\t2- Code: " << course->code <<
			"\n\t3- Is required: " << (course->is_required ? "Yes" : "NO") <<
			"\n\t4- Max number of students: " << course->max_number_of_students <<
			"\n\t5- Pre-required Courses: ( ";
		for (const auto& req : course->pre_required_courses)
			cout << req << ", ";

		cout << "\b\b )\n\t6- Hours: " << course->hours <<
			"\n\t7- Instructor: " << course->instructor <<
			"\n\t8- Go back";

		string word;
		while (true)
		{
			cout << "\n\t-> ";
			getline(cin, ans);
			if (ans == "1")
			{
				cout << "Enter the new Name: "; getline(cin, course->name);
			}
			else if (ans == "2")
			{
				cout << "Enter the new Code: "; getline(cin, course->code);
			}
			else if (ans == "3")
			{
				cout << "Is it required? (Y/y) -> "; getline(cin, ans);
				course->is_required = (ans == "Y" || ans == "y" ? true : false);
			}
			else if (ans == "4")
			{
				cout << "Enter the new max number of students: ";
				cin >> course->max_number_of_students; cin.ignore();
			}
			else if (ans == "5")
			{
				//MESS("Not available yet :)");
				MENU("Edit Pre-required courses");
				cout << "\n 1- Add pre-required course\n 2- Edit pre-required course\n 3- Remove pre-required course\n 4- Go back";
				while (true)
				{
					cout << "\n\n -> "; getline(cin, ans);
					if (ans == "1")
						add_pre_required_course(course);
					else if (ans == "2")
						edit_pre_required_course(course);
					else if (ans == "3")
						remove_pre_required_course(course);
					else if (ans == "4")
						break;
					else {
						INVALID;
						cout << " Try again? (Y/y) -> "; getline(cin, ans);
						if (ans != "Y" || ans != "y")
							break;
					}
					break;
				}
			}
			else if (ans == "6")
			{
				cout << "Enter the new Hours: ";
				cin >> course->max_number_of_students; cin.ignore();
			}
			else if (ans == "7")
			{
				cout << "Enter the new Instructor: "; getline(cin, course->instructor);
			}
			else if (ans == "8")
			{
				break;
			}
			else {
				INVALID;
				cout << " Try again? (Y/y) -> "; getline(cin, ans);
				if (ans == "Y" || ans == "y")
					continue;
			}
			break;
		}
		if (ans == "8")break;
	}
}

void Admin::view_course_students()
{
	MENU("List of all students in a specific course");
	string ans;
	if (the_Courses.size() == 0) {
		MESS("There is no courses yet");
		cout << " Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	int i = 0;
	cout << " The Courses: ";
	for (const auto& course : the_Courses)
		cout << "\n\t" << ++i << "- " << course.second.name;

	while (true)
	{
		cout << "\n\n Select a course to view students in it or enter \'0\' to go back -> ";
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

	auto it = the_Courses.begin();
	advance(it, i - 1);

	MENU("List of all students in a specific course");
	int n = 1;
	for (auto student : it->second.students) {
		cout << n << " - " << student << endl;
		n++;
	}
}

void Admin::set_course_grade()
{
}

void Admin::view_student_courses()
{
	MENU("List of all courses (Finished - Progressed) of a specific student");
	string ans;
	if (the_Students.size() == 0) {
		MESS("There is no students yet");
		cout << " Enter any thing to exit -> "; getline(cin, ans);
		return;
	}

	int i = 0;
	cout << " The Students: ";
	for (const auto& student : the_Students)
		cout << "\n\t" << ++i << "- " << student.second.personal_info.name;

	while (true)
	{
		cout << "\n\n Select a student to view student's courses or enter \'0\' to go back -> ";
		cin >> i; cin.ignore();
		if (i == 0) return;
		else if (i < 0 || i > the_Students.size()) {
			INVALID;
			cout << "\n Try again? (Y/y) -> ";
			getline(cin, ans);
			if (ans != "Y" && ans != "y")
				return;
		}
		else break;
	}

	auto it = the_Students.begin();
	advance(it, i - 1);

	MENU("List of all courses (Finished - Progressed) of a specific student");
	cout << "Current progressed courses";
	it->second.view_my_courses();
	cout << "Finished courese with grades";
	it->second.view_finished_courses();
	cout << " Enter any thing to exit -> "; getline(cin, ans);
}

void Admin::write_file()
{
}

void Admin::read_file()
{
}
