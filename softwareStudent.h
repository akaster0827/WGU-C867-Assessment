#pragma once
#include "student.h"
#include "degree.h"


class SoftwareStudent : public Student
{

public:
	using Student::Student;
	Degree getDegree() override;

private:
	Degree degree = SOFTWARE;
};