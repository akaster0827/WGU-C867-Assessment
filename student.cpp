#include "student.h"
#include <iostream>

using namespace std;

/*DEFINITIONS*/

//default constructor
Student::Student()
	: student_id(), first_name(), last_name(), email_address(), age(), num_days_in_course(new int[num_days_in_course_ArraySz])
{
	for (int i = 0; i < num_days_in_course_ArraySz; ++i) {
		this->num_days_in_course[i] = 0;
	}

}


//overload constructor
Student::Student(string student_id, string first_name, string last_name, string email_address, int age, int num_days_in_course[], Degree degree)
	: student_id(student_id), first_name(first_name), last_name(last_name), email_address(email_address), age(age), num_days_in_course(new int[num_days_in_course_ArraySz])
{
	for (int i = 0; i < num_days_in_course_ArraySz; ++i) {
		this->num_days_in_course[i] = num_days_in_course[i];
	}

}


//destructor
Student::~Student() {}


//accessor(getter)
string Student::getStudent_id() const {
	return student_id;
}

string Student::getFirst_name() const {
	return first_name;
}

string Student::getLast_name() const {
	return last_name;
}

string Student::getEmail_address() const {
	return email_address;
}

int Student::getAge() const {
	return age;
}

int* Student::getNum_days_in_course() const {
	return num_days_in_course;
}

Degree Student::getDegree() {
	return degree;
}


//mutator(setter)
void Student::setStudent_id(string studentId) {
	this->student_id = student_id;
}

void Student::setFirst_name(string firstName) {
	this->first_name = first_name;
}

void Student::setLast_name(string lastName) {
	this->last_name = last_name;
}

void Student::setEmail_address(string email) {
	this->email_address = email_address;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setNum_days_in_course(int num_days_in_course[]) {
	this->num_days_in_course = new int[num_days_in_course_ArraySz];
	for (int i = 0; i < num_days_in_course_ArraySz; ++i) this->num_days_in_course[i] = num_days_in_course[i];
}

void Student::setDegree(Degree degree) {
	this->degree = degree;
}


//virtual print
void Student::print() {
	cout << getStudent_id();
	cout << "\tFirst name: " << getFirst_name();
	cout << "\tLast name: " << getLast_name();
	cout << "\tAge: " << getAge();

	int* days = getNum_days_in_course();
	cout << "\t  Days in course: " << days[0] << ", " << days[1] << ", " << days[2];

	string degree_Str = "";
	
	switch (getDegree()) {
	case NETWORKING:
		degree_Str = "NETWORKING";
		break;
	case SECURITY:
		degree_Str = "SECURITY";
		break;
	case SOFTWARE:
		degree_Str = "SOFTWARE";
		break;
	case COMPUTER_SCIENCE:
		degree_Str = "COMPUTER_SCIENCE";
		break;
	}
	cout << "\tDegree: " << degree_Str << endl;
}