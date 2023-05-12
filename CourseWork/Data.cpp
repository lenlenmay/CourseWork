#include "Data.h"


void Data::SetSurname(std::string Surname)
{
	this->Surname = Surname;
}

void Data::SetName(std::string Name)
{
	this->Name = Name;
}

void Data::SetPatrinymic(std::string Patrinymic)
{
	this->Patrinymic = Patrinymic;
}

void Data::SetGender(std::string Gender)
{
	this->Gender = Gender;
}

std::string Data::GetSurname()
{
	return this->Surname;
}

std::string Data::GetName()
{
	return this->Name;
}

std::string Data::GetPatrinymic()
{
	return this->Patrinymic;
}

std::string Data::GetGender()
{
	return this->Gender;
}

void Data::SetDay(std::string Day)
{
	this->Day = Day;
}

void Data::SetMonth(std::string Month)
{
	this->Month = Month;
}

void Data::SetYear(std::string Year)
{
	this->Year = Year;
}

std::string Data::GetDay()
{
	return this->Day;
}

std::string Data::GetMonth()
{
	return this->Month;
}

std::string Data::GetYear()
{
	return this->Year;
}

void Data::SetYearAddtoUniversity(std::string YearAddtoUniversity)
{
	this->YearAddtoUniversity = YearAddtoUniversity;
}

void Data::SetFaculty(std::string Faculty)
{
	this->Faculty = Faculty;
}

void Data::SetDepartment(std::string Department)
{
	this->Department = Department;
}

void Data::SetGroup(std::string Group)
{
	this->Group = Group;
}

void Data::SetNumberRecordBook(std::string NumberRecordBook)
{
	this->NumberRecordBook = NumberRecordBook;
}

std::string Data::GetYearAddtoUniversity()
{
	return this->YearAddtoUniversity;
}

std::string Data::GetFaculty()
{
	return this->Faculty;
}

std::string Data::GetDepartment()
{
	return this->Department;
}

std::string Data::GetGroup()
{
	return this->Group;
}

std::string Data::GetNumberRecordBook()
{
	return this->NumberRecordBook;
}

Data::~Data()
{
}

Data::Data(std::string Surname, std::string Name, std::string Patrinymic, std::string Gender, std::string Day, std::string Month, std::string Year, std::string YearAddtoUniversity, std::string Faculty, std::string Department, std::string Group, std::string NumberRecordBook)
{
	this->Surname = Surname;
	this->Name = Name;
	this->Patrinymic = Patrinymic;
	this->Gender = Gender;

	this->Day = Day;
	this->Month = Month;
	this->Year = Year;

	this->YearAddtoUniversity = YearAddtoUniversity;
	this->Faculty = Faculty;
	this->Department = Department;
	this->Group = Group;
	this->NumberRecordBook = NumberRecordBook;
}

Data::Data()
{

}

