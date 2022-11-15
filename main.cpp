/*
	Script by Sahil - 1DT21CS126
*/

// Headers
#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdio>

using namespace std;

// prototype funs
void addStudent();
void searchStudent();
void deleteStudent();
void displayAll();
void selfExit();

// global vars
string usn, fname, lname, branch, cls;
bool login = false;

int main()
{
	system("cls");
	if (login != true)
	{
		string username, password;
		cout << "\n\n\t\t *** Student Management System *** \t\t \n\n";
		cout << "\t\tUsername: ";
		cin >> username;
		cout << "\t\tPassword: ";
		cin >> password;

		if (username == "admin" && password == "admin")
		{
			login = true;
		}
		else {
			cout << "\n\n \t\t Invalid Credentials!\n\n \t\t";
			main();
		}
	}

	if (login == true)
	{
		short int choice;
		system("cls");
		cout << "\n\n\t *** Student Management System *** \t \n\n";
		cout << "\n\n \t\t 1. Add Student \n \t\t 2. Search Student \n \t\t 3. Delete Student \n \t\t 4. Display All \n \t\t 5. Exit \t\t\n\n\t\t>>> ";

		cin >> choice;

		switch(choice){
			case 1:
				addStudent();
				break;
			case 2:
				searchStudent();
				break;
			case 3:
				deleteStudent();
				break;
			case 4:
				displayAll();
				break;
			case 5:
				selfExit();
				break;
			default:
				cout << "\n\n \t\t Invalid Choice!";
				main();
		}
	}
	return 0;
}


void addStudent(){
	ofstream student("students.txt", ios::app);
	system("cls");

	cout << "\n\n \t\t Enter student details: \t\t \n\n";
	cout << "\n\t\t USN : ";
	cin >>  usn;
	cout << "\n\t\t First Name : ";
	cin >>  fname;
	cout << "\n\t\t Last Name : ";
	cin >>  lname;
	cout << "\n\t\t Branch : ";
	cin >> branch;
	cout << "\n\t\t Class : ";
	cin >> cls;

	if (student.is_open())
	{
		student << usn << " " << fname << " " << lname << " " << branch << " " << cls << endl;
		cout << "\n\n \t\t Data Saved Successfully! \t\t\n\n";
		// usn = "";
		main();
	}
	else{
		cout << "\n\n\t\t Error opening file! \t\t\n\n";
	}

	student.close();
}

void searchStudent(){
    bool found = false;
    ifstream myfile("students.txt");

    string keyword;
    cout << "\n\n \t\t Enter Keyword: USN or Last Name \t\t\n\n \t\t >>> ";
    cin >> keyword;

    while(myfile >> usn >> fname >> lname >> branch >> cls){
    	if (keyword == usn || keyword == lname)
    	{
    		system("cls");
    		cout << "\n\n \t\t Student Details \t\t\n\n";
    		cout << "\n\n \t\t USN: " << usn ;
    		cout << "\n\n \t\t First Name: " << fname;
    		cout << "\n\n \t\t Last Name: " << lname;
    		cout << "\n\n \t\t Branch : " << branch;
    		cout << "\n\n \t\t Class : " << cls;
    		cout << "\n\n";
    		found = true;
    		break;
    	}
    }
}

void displayAll(){
    ifstream myfile("students.txt");

	while(myfile >> usn >> fname >> lname >> branch >> cls){
		system("cls");
		cout << "\n\n \t\t Student Details \t\t\n\n";
		cout << "\n\n \t\t USN: " << usn ;
		cout << "\n\n \t\t First Name: " << fname;
		cout << "\n\n \t\t Last Name: " << lname;
		cout << "\n\n \t\t Branch : " << branch;
		cout << "\n\n \t\t Class : " << cls;
		cout << "\n\n\n \t\t *** Press enter to display next. *** \t\t\n";
		getch();
    }
}

void deleteStudent(){
	system("cls");
	cout << "\n\n \t\t Enter the USN of student To Be Deleted:\t\t\n\n \t\t >>>";
	cin >> usn;

    ifstream read("students.txt");
	ofstream write("temp.txt");

	if (read.is_open()){
		string line;
		while(getline(read, line)){
			if (line.find(usn) == string::npos)
			{
				write << line << endl;
			}
		}
	}
	else{
		cerr << "\n\n \t\t Couldnt read file";
	}

	read.close();
	write.close();
	remove("students.txt");
	rename("temp.txt", "students.txt");

	cout << "\n\n\t\t Deleted! \t\t\n\n";
	main();
}

void selfExit(){
	exit(1);
}
















