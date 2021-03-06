#pragma once
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student
{

public:
	using Student::Student;
	Degree getDegree() override;

private:
	Degree degree = NETWORKING;
};