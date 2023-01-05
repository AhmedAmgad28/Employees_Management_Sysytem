#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void addEmployee();
void showEmployee();
void DeleteEmployee();
void searchEmployee();
void startMenu();
void quit();


int main()
{
	startMenu();

	return 0;
}

void quit()
{
	cout << "Thank you :) " << endl;
	system("pause");
}
void addEmployee() {
	fstream file("Employee.txt", ios::out | ios::app);


	int n, salary, id;
	string name, department;
	cout << "Enter numbers of employee ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Please fill this data for Employee No." << i << endl;
		cout << "Enter id" << endl;
		cin >> id;
		cout << "Enter name" << endl;
		cin >> name;
		cout << "Enter department" << endl;
		cin >> department;
		cout << "Enter salary" << endl;
		cin >> salary;
		file << name << " " << id << " " << department << " " << salary << "\n";
		if (i < n) { cout << "Another Employee" << " \n"; }
	}
	file.close();
	cout << "*************************\n";
	startMenu();
}


void showEmployee() {

	ifstream file2("Employee.txt");

	int n, salary, id;
	string name, department;
	while (file2 >> name >> id >> department >> salary) {
		cout << "Name : " << name << "\n";
		cout << "ID : " << id << "\n";
		cout << "Department : " << department << "\n";
		cout << "Salary : " << salary << "\n";
		cout << "*************************\n";
	}
	file2.close();
	startMenu();
}


void DeleteEmployee() {

	ifstream file("Employee.txt");
	ofstream file2("Section.txt");
	string name;
	string line;
	cout << "Enter name you want to delete : ";
	cin >> name;
	while (getline(file, line)) { // بتقرا الفايل سطر سطر 

		if (line.substr(0, name.size()) != name) { // Comparison
			file2 << line << endl;
		}
	}
	cout << " the name : " << name << " has been deleted" << endl;
	file.close();
	file2.close();
	remove("Employee.txt");
	rename("Section.txt", "Employee.txt");
	cout << "*************************\n";
	startMenu();
}


void searchEmployee() {
	ifstream file("Employee.txt");
	string search, line;
	bool check=true;
	cout << "Please Enter The EmployeeName You Want To Search About : ";
	cin >> search;
	for (int curline = 1; getline(file, line); curline++) {
		if (line.find(search) != string::npos) {
			cout << "Found : " << search << " on line: " << curline << endl;
			check = true;
		}
		else {
			continue;
		}
	}
	if (check == false) {
		cout << "Name is not found\n";
	}
	cout << "*************************\n";
	startMenu();
}


void startMenu() {
	cout << "1.Add Employee" << endl;
	cout << "2.Delete Employee" << endl;
	cout << "3.Show All Employee" << endl;
	cout << "4.Search for Employee" << endl;
	cout << "5.Exit" << endl;
	int option;
	cout << "Enter your choice : " << endl;
	cin >> option;
	switch (option) {
	case 1:
		addEmployee();
		break;
	case 2:
		DeleteEmployee();
		break;
	case 3:
		showEmployee();
		break;
	case 4:
		searchEmployee();
		break;
	case 5:
		quit();
		break;
	defult:
		cout << "Wrong number!!\n";
		break;
	}
}
