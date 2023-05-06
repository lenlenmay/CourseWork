#pragma once
#include <iostream>
#include <string>

class Data {

std::string Surname{},
			Name{},
			Patrinymic{},
			Gender{};

std::string Day{},
			Month{},
			Year{};

std::string YearAddtoUniversity{},
			Faculty{},
			Department{},
			Group{},
			NumberRecordBook{};

	/*class Sessions {
		//?
	};*/

public:
	
	Data(std::string Surname, std::string Name, std::string Patrinymic, std::string Gender, std::string Day, std::string Month, std::string Year, std::string YearAddtoUniversity, std::string Faculty, std::string Department, std::string Group, std::string NumberRecordBook);
	Data();

	void SetSurname(std::string Surname);
	void SetName(std::string Name);
	void SetPatrinymic(std::string Patrinymic);
	void SetGender(std::string Gender);

	std::string GetSurname();
	std::string GetName();
	std::string GetPatrinymic();
	std::string GetGender();


	void SetDay(std::string Day);
	void SetMonth(std::string Month);
	void SetYear(std::string Year);

	std::string GetDay();
	std::string GetMonth();
	std::string GetYear();


	void SetYearAddtoUniversity(std::string YearAddtoUniversity);
	void SetFaculty(std::string Faculty);
	void SetDepartment(std::string Department);
	void SetGroup(std::string Group);
	void SetNumberRecordBook(std::string NumberRecordBook);

	std::string GetYearAddtoUniversity();
	std::string GetFaculty();
	std::string GetDepartment();
	std::string GetGroup();
	std::string GetNumberRecordBook();
};
