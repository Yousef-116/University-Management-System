#include "Logic.h"

unordered_map<string, Student>the_Students;
unordered_map<string, Student>the_Coursese;
Student* the_student = NULL;

int main() 
{
	string ans;
	while(true)
	{
		MENU("MAIN MENU");
		cout << " 1- login as Admin\n 2- login as student\n 3- Register\n 4- Exit\n -> ";

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

		}
		else if(ans == "4")
		{
			break;
		}
		else 
		{
			INVALID;
		}
	}
	
	return 0;
}
