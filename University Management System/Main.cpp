#include "Logic.h"

unordered_map<string, Student>the_Students;
unordered_map<string, Student>the_Coursese;
Student* the_student = NULL;

#define MENU(word) system("cls"); cout << ">>>>>>>>>>>>> " << word  << " <<<<<<<<<<<<<<<\n"

int main() 
{
	//MENU("MAIN MENU");
	string ans;
	while(true)
	{
		cout << " 1- login as Admin\n 2- login as studet\n 3- Register\n 4- Exit \n";

		getline(cin, ans);
		if(ans == "1")
		{
			Student newStudent;
			if(newStudent.log_in())
			{

			}
		}
		else if(ans == "2")
		{
			Admin theAdmin;
			if(theAdmin.log_in())
			{
				
			}
		}
		else if(ans == "3")
		{

		}
		else if(ans == "4")
		{
			break;
		}

	}
	
	return 0;
}
