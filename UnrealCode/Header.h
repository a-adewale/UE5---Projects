#pragma once
#include<string>

int MyInteger;
float x;
std::string MyString = "Test String";

class student
{
private:
	std::string Name;
	int Marks;
public:
	std::string GetName();
	int GetMarks();
	void SetMarks(int marks)
	{
		Marks = marks;
	}

};



