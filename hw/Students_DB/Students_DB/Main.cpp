#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Student
{
private:
	string FIO = "Ivanov Ivan Petrovich";
	string Group = "A101";
	unsigned short int Age = 16;

public:
	void SetFIO(string);
	void SetGroup(string);
	void SetAge(unsigned short int);

	string GetFIO();
	string GetGroup();
	unsigned short int GetAge();

	void ReadStudent();
};

//const unsigned int maxCount = 64;

class StudentData
{
private:
	/*Student data[maxCount];*/
	vector<Student> data=vector<Student>(0);
	//unsigned int count = 0;

public:
	unsigned int GetCount() { return data.size(); }

	void CreateStudents();
	void AddStudent();
	void SaveStudentsToFile();
	void ReadStudentsFromFile();
	void ShowStudents();
};

void StudentData::CreateStudents()
{
	

	unsigned int studentCount;
	cout << "Input number of students : ";
	cin >> studentCount;
	cin.ignore();


	//if (studentCount > maxCount)
	//{
	//	cout << "Invalid number of students (< " << maxCount << ")" << endl;
	//	return;
	//}

	for (unsigned int i = 0; i < studentCount; i++)
	{
		Student stud;
		stud.ReadStudent();
		data.push_back(stud);
	}

	//count = studentCount;
}

void StudentData::AddStudent()
{
	//if (count == maxCount)
	//{
	//	cout << "Student data array full! Can not add another student..." << endl;
	//	return;
	//}
	//
	//data[count].ReadStudent();

	Student stud;
	stud.ReadStudent();
	data.push_back(stud);
	//count++;
}

void StudentData::SaveStudentsToFile()
{
	string fileName;
	cout << "Please input file name : ";
	cin >> fileName;

	ofstream studentFile;
	studentFile.open(fileName + ".txt");

	if (studentFile.is_open())
	{
		studentFile << data.size() << endl;

		for (unsigned int i = 0; i < data.size(); i++)
		{
			studentFile << data[i].GetFIO() << endl;
			studentFile << data[i].GetGroup() << endl;
			studentFile << data[i].GetAge() << endl;
		}
	}
	else
	{
		cout << "Unable to open file : " << fileName;
	}
}

void StudentData::ReadStudentsFromFile()
{
	string line;
	string fileName;
	cout << "Please input file name : ";
	cin >> fileName;

	ifstream studentFile;
	studentFile.open(fileName + ".txt");

	if (studentFile.is_open())
	{
		getline(studentFile, line);
		int count = atoi(line.c_str());
		data.resize(count);

		for (int i = 0; i < count; i++)
		{
			string FIO;
			string Group;
			string age;
			unsigned int Age;

			getline(studentFile, FIO);
			getline(studentFile, Group);
			getline(studentFile, age);
			Age = atoi(age.c_str());

			data[i].SetFIO(FIO);
			data[i].SetGroup(Group);
			data[i].SetAge(Age);
		}
	}
	else
	{
		cout << "Unable to open file : " << fileName;
	}
	
}

void StudentData::ShowStudents()
{
	cout << "Student Count: " << data.size() << endl;

	for (unsigned int i = 0; i < data.size(); i++)
	{
		cout << "Student " << i + 1 << " :" << endl;
		cout << "FIO : " << data[i].GetFIO() << endl;
		cout << "Group :" << data[i].GetGroup() << endl;
		cout << "Age: " << data[i].GetAge() << endl;
	}
}

void ShowHelp()
{
	cout << "\n\n";
	cout << "Press 'C' to Create Students" << endl;
	cout << "Press 'A' to Add Student" << endl;
	cout << "Press 'S' to Save Students to file" << endl;
	cout << "Press 'R' to Read Students from file" << endl;
	cout << "Press 'V' to Show Students DB" << endl;
	cout << "Press 'E' to Exit" << "\n\n";
}

int main()
{
	StudentData studentData;
	char Menu;

	while (true)
	{
		ShowHelp();
		cout << "Please choose your action : ";
		cin >> Menu;
		cin.ignore();

		toupper(Menu);

		switch (Menu)
		{
		case 'c':
		case 'C':
			studentData.CreateStudents();
			break;

		case 'a':
		case 'A':
			studentData.AddStudent();
			break;

		case 's':
		case 'S':
			studentData.SaveStudentsToFile();
			break;

		case 'r':
		case 'R':
			studentData.ReadStudentsFromFile();
			break;

		case 'v':
		case 'V':
			studentData.ShowStudents();
			break;

		case 'e':
		case 'E':
			exit(0);
			break;

		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void Student::SetFIO(string fio)
{
	FIO = fio;
}

void Student::SetGroup(string group)
{
	Group = group;
}

void Student::SetAge(unsigned short int age)
{
	Age = age;
}

string Student::GetFIO()
{
	return FIO;
}

string Student::GetGroup()
{
	return Group;
}

unsigned short int Student::GetAge()
{
	return Age;
}

void Student::ReadStudent()
{
	cout << "Input student FIO : ";
	getline(cin, FIO);

	cout << "Input student Group : ";
	getline(cin, Group);

	cout << "Input student Age : ";
	cin >> Age;

	cin.ignore();
}