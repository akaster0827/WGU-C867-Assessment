#pragma once
#include "student.h"
#include "degree.h"


class CS_Student : public Student
{

public:
	using Student::Student;
	Degree getDegree() override;

private:
	Degree degree = COMPUTER_SCIENCE;
};