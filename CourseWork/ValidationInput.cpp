#include "ValidationInput.h"

bool ValidationInput::isNSPatrinymic(std::string input)
{
	std::regex regular("[a-zA-Zà-ÿ¸À-ß¨]{2,20}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isGender(std::string input)
{
	std::regex regular("[a-zA-Zà-ÿ¸À-ß¨]{3,10}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isDayMonth(std::string input)
{
	std::regex regular("[0-9]{1,2}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isYAndYUniversity(std::string input)
{
	std::regex regular("[0-9]{4}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isFDepartment(std::string input)
{
	std::regex regular("[a-zA-Zà-ÿ¸À-ß¨_]{2,20}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isGroup(std::string input)
{
	std::regex regular("[0-9]{1,6}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isNumberRecordBook(std::string input)
{
	std::regex regular("[0-9]{1,4}");
	return std::regex_match(input.c_str(), regular);
}
