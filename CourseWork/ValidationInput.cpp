#include "ValidationInput.h"

bool ValidationInput::isNSPatrinymic(std::string input)
{
	std::regex regular("[a-zA-Zа-яёА-ЯЁ]{2,20}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isGender(std::string input)
{
	std::regex regular("[a-zA-Zа-яёА-ЯЁ]{3,7}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isDay(std::string input)
{
	std::regex regular("[0-9]{1,2}");

	if (std::regex_match(input.c_str(), regular)) {
		int index = std::atoi(input.c_str());
		if (1 <= index && index <= 31) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool ValidationInput::isMonth(std::string input)
{
	std::regex regular("[0-9]{1,2}");

	if (std::regex_match(input.c_str(), regular)) {
		int index = std::atoi(input.c_str());
		if (1 <= index && index <= 12) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool ValidationInput::isYAndYUniversity(std::string input)
{
	std::regex regular("[0-9]{4}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isFDepartment(std::string input)
{
	std::regex regular("[a-zA-Zа-яёА-ЯЁ0-9\-]{2,20}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isGroup(std::string input)
{
	std::regex regular("[a-zA-Zа-яёА-ЯЁ0-9\-]{1,10}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isNumberRecordBook(std::string input)
{
	std::regex regular("[a-zA-Zа-яёА-ЯЁ0-9]{1,7}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isNumberOfRecord(std::string input, int count)
{
	std::regex regular("[1-9]{1,4}");
	if (std::regex_match(input.c_str(), regular)) {
		int index = std::atoi(input.c_str());
		if (0 < index && index <= count) {

			return true;
		}
		else {
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "| " << std::left << std::setw(36) << "Записи под таким номером не существует" << " |" << std::endl;
			std::cout << "------------------------------------------" << std::endl;
			Sleep(1500);
			return false;
		}
	}
	else {
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(36) << "Записи под таким номером не существует" << " |" << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		Sleep(1500);
		return false;
	}
}

bool ValidationInput::isAgree(std::string input)
{
	if (input == "Y")
	{
		return true;
	}
	else {
		return false;
	}
}

bool ValidationInput::isGrade(std::string input)
{
	std::regex regular("[2-5]{1}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isSubject(std::string input)
{
	std::regex regular("[a-zA-Zа-яёА-ЯЁ_]{2,20}");
	return std::regex_match(input.c_str(), regular);
}

bool ValidationInput::isNumberOfRecordSession(std::string input, int count)
{
	std::regex regular("[0-9]{1,2}");
	if (std::regex_match(input.c_str(), regular)) {
		int index = std::atoi(input.c_str());
		if (0 < index && index <= count) {

			return true;
		}
		else {
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "| " << std::left << std::setw(36) << "Записи под таким номером не существует" << " |" << std::endl;
			std::cout << "------------------------------------------" << std::endl;
			Sleep(1500);
			return false;
		}
	}
	else {
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(36) << "Записи под таким номером не существует" << " |" << std::endl;
		std::cout << "------------------------------------------" << std::endl;
		Sleep(1500);
		return false;
	}
}

