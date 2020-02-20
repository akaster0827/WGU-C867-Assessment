#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "securityStudent.h"
#include "student.h"
#include "roster.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "CSstudent.h"


int main() {
	std::cout << "SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << std::endl;
	std::cout << "Programming Language: C++ - Written by Alex Kaster, ID: #000783857\n" << std::endl;

	Roster classRoster;
	Degree degree;

	string output, col[DATA_COLUMNS];


	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i)
	{
		std::istringstream input(studentData[i]);
		for (int j = 0; j < DATA_COLUMNS; ++j) {
			std::getline(input, output, ',');
			col[j] = output;
		}

		switch (col[8][2]) {
		case 'T':
			degree = NETWORKING;
			break;
		case 'C':
			degree = SECURITY;
			break;
		case 'F':
			degree = SOFTWARE;
			break;
		case 'M':
			degree = COMPUTER_SCIENCE;
			break;
		}

		classRoster.add(col[0], col[1], col[2], col[3], std::stoi(col[4]), std::stoi(col[5]), std::stoi(col[6]), std::stoi(col[7]), degree);
	}

	//Beginning of Section F4.
	std::cout << "Roster:" << std::endl;
	classRoster.printAll();
	std::cout << std::endl;

	std::cout << "Invalid emails:" << std::endl;
	classRoster.printInvalidEmails();
	std::cout << std::endl;

	std::cout << "Average days in course by student ID:" << std::endl;
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudent_id());
	}
	std::cout << std::endl;

	std::cout << "Students in degree program SOFTWARE:" << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	std::cout << std::endl;


	classRoster.remove("A3");
	classRoster.remove("A3");
	std::cout << std::endl;

	std::cout << "Roster:" << std::endl;
	classRoster.printAll();
	std::cout << std::endl;

	classRoster.~Roster();
	//End of Section F4.

	system("PAUSE");
	return 0;

}

//3A. Define public void add()  that sets the instance variables from part D1 and updates the roster
void Roster::add(string student_id, string first_name, string last_name, string email_address, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
	int num_days_in_course[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = nullptr;

	switch (degree) {
	case NETWORKING:
		student = new NetworkStudent(student_id, first_name, last_name, email_address, age, num_days_in_course, degree);
		break;
	case SECURITY:
		student = new SecurityStudent(student_id, first_name, last_name, email_address, age, num_days_in_course, degree);
		break;
	case SOFTWARE:
		student = new SoftwareStudent(student_id, first_name, last_name, email_address, age, num_days_in_course, degree);
		break;
	case COMPUTER_SCIENCE:
		student = new CS_Student(student_id, first_name, last_name, email_address, age, num_days_in_course, degree);
		break;
	}

	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = student;
			break;
		}
	}
};

//3B. Define public void remove()  that removes students from the roster by studentID.  
// --> If the studentID does not exist the function prints an error message indicating that the student was not found
void Roster::remove(string student_id) {
	std::cout << "Removing student with ID " << student_id << "... " << std::flush;
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			std::cout << "ERROR: Student with this ID not found" << std::endl;
			break;
		}
		else if (student_id == classRosterArray[i]->getStudent_id()) {
			classRosterArray[i] = nullptr;
			std::cout << "Student removed" << std::endl;
		}
	}
};

//3C. Define public void printAll()  that prints a complete tab-separated list of sudent data using accessor functions with the provided format
// -->  The prinAll() function should loop through all the students in classRoserArray and call the print() function for each student
void Roster::printAll() {
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
};


//3D. public void printDaysInCourse  that correctly prints a student's avg # of days in the 3 courses.  The student is identified by the studentID parameter
void Roster::printAverageDaysInCourse(string student_id) {
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (student_id == classRosterArray[i]->getStudent_id()) {
			int* days = classRosterArray[i]->getNum_days_in_course();
			std::cout << student_id << "\t";		// Not sure how precise you want the average of days here, so I guessed
			std::cout << std::setprecision(3) << (((float)days[0] + (float)days[1] + (float)days[2]) / 3) << std::endl;
		}
	}
};


//3E. public void printInvalidEmails() that verifies student email address and displays all invalid email addresses to the user
void Roster::printInvalidEmails() {
	bool valid = false;
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		valid = false;
		string email_address = classRosterArray[i]->getEmail_address();
		size_t emailLength = email_address.size();
		size_t j = 0;
		while (email_address[j] != ' ' && email_address[j] != '@' && j < emailLength) {
			++j;
			if (email_address[j] == '@' && j < emailLength) {
				++j;
				while (email_address[j] != ' ' && email_address[j] != '@' && email_address[j] != '.' && j < emailLength) {
					++j;
					if (email_address[j] == '.' && j < emailLength) {
						++j;
						while (email_address[j] != ' ' && email_address[j] != '@' && email_address[j] != '.' && j < emailLength) {
							++j;
							if (j == emailLength) {
								valid = true;
							}
						}
					}
				}
			}
		}
		if (valid == false) {
			std::cout << email_address << std::endl;
		}
	}
};

//3F. public void printByDegreeProgram() that prints out student information for degree program specified by an enumerated type
void Roster::printByDegreeProgram(Degree degree) {
	for (int i = 0; i < NUMBER_OF_STUDENTS; ++i) {
		Student* student = classRosterArray[i];
		if (student->getDegree() == degree) {
			student->print();
		}
	}
};

//F5. call the destructor to release the Roster memory
Roster::~Roster() {

};