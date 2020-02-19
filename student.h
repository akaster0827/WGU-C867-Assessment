#pragma once

/*DECLARATIONS*/


#include "degree.h"
#include <string>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
	//default constructor
	Student();


	//overload constructor
	Student(
		  string student_id
		, string first_name
		, string last_name
		, string email_address
		, int age
		, int num_days_in_course[]
		, Degree degree);
	      

	//destructor
	~Student();

	//accessor(getter)
	string getStudent_id() const;
	string getFirst_name() const;
	string getLast_name() const;
	string getEmail_address() const;
	int getAge() const;
	int* getNum_days_in_course() const;
	virtual Degree getDegree() = 0;

	//mutator(setter)
	void setStudent_id(string studentId);
	void setFirst_name(string firstName);
	void setLast_name(string lastName);
	void setEmail_address(string email);
	void setAge(int age);
	void setNum_days_in_course(int num_days_in_course[]);
	void setDegree(Degree degree);

	//virtual
	virtual void print();
	virtual Degree getDegree() = 0;

private:
	//member variables
	string student_id;
	string first_name;
	string last_name;
	string email_address;
	int age;
	int* num_days_in_course;
	Degree degree;
	const static int num_days_in_course_ArraySz = 3;
};



#endif // !STUDENT_H
