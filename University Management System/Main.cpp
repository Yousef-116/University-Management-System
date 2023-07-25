#include "Logic.h"

unordered_map<string, Student>the_Students;
unordered_map<string, Student>the_Coursese;
Student* the_student = NULL;
int student_id;

int main() 
{
	string ans;
	while(true)
	{
		MENU("MAIN MENU");
		cout << " 1- Login as Admin\n 2- Login as Student\n 3- Regist\n 4- Exit\n -> ";

		getline(cin, ans);
		if(ans == "1")
		{
			Admin theAdmin;
			if (theAdmin.log_in())
			{
				theAdmin.menu();
			}
		}
		else if(ans == "2")
		{
			Student newStudent;
			if (newStudent.log_in())
			{
				the_student->menu();
			}
		}
		else if(ans == "3")
		{
			Student newStudent;
			if (newStudent.regist())
			{
				the_student->menu();
			}
		}
		else if(ans == "4")
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
	
	return 0;
}
