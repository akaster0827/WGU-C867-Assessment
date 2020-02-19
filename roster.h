#pragma once
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Alex,Kaster,akaster@wgu.edu,28,15,65,73,COMPUTER_SCIENCE"
};


static const unsigned int DATA_COLUMNS = 9;
static const unsigned int NUMBER_OF_STUDENTS = sizeof(studentData) / sizeof(studentData[0]);


class Roster
{
public:
	Student* classRosterArray[NUMBER_OF_STUDENTS] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	void add(
		string student_id,
		string first_name,
		string last_name,
		string email_address,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		Degree degree
	);


	void remove(string student_id);
	void printAll();
	void printAverageDaysInCourse(string student_id);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degree);

	//destructor
	~Roster();

};