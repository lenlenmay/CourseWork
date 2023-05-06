#pragma once
#include <iostream>
#include <string>
#include <regex>
class ValidationInput
{
public:
	bool isNSPatrinymic(std::string input);
	bool isGender(std::string input);
	bool isDayMonth(std::string input);
	bool isYAndYUniversity(std::string input);
	bool isFDepartment(std::string input);
	bool isGroup(std::string input);
	bool isNumberRecordBook(std::string input);
};

