#pragma once
#include "student.h"
#include "degree.h"


class SecurityStudent : public Student
{

public:
	using Student::Student;
	Degree getDegree() override;

private:
	Degree degree = SECURITY;
};