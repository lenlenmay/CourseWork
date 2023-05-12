#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <windows.h>
#include <iomanip>
class ValidationInput
{
public:
	bool isNSPatrinymic(std::string input);
	bool isGender(std::string input);
	bool isDay(std::string input);
	bool isMonth(std::string input);
	bool isYAndYUniversity(std::string input);
	bool isFDepartment(std::string input);
	bool isGroup(std::string input);
	bool isNumberRecordBook(std::string input);
	bool isNumberOfRecord(std::string input, int count);
	bool isAgree(std::string input);
	bool isGrade(std::string input);
	bool isSubject(std::string input);
	bool isNumberOfRecordSession(std::string input, int count);
};

