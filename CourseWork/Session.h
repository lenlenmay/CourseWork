#pragma once
#include <string>


class SubjGrades {

	std::string Subject{};
	std::string Grade{};

public:

	SubjGrades();
	SubjGrades(std::string Subject, std::string Grade);
	void Clear();
	std::string GetSubject();
	std::string GetGrade();
	void SetSubject(std::string Subject);
	void SetGrade(std::string Grade);
	~SubjGrades();
};

class Session
{
	int index{};
	int countSubjects{};
	bool bisAdded = false;
	
public:

	SubjGrades subjGrades[10];

	Session();
	bool GetisAdded();
	void SetisAdded(bool bisAdded);
	int GetIndex();
	void SetIndex(int index);
	int GetcountSubjects();
	void SetcountSubjects(int countSubjects);
	void AddSubjGrades(std::string _Subject, std::string _Grade);
	void ChangedSubjGrades(SubjGrades _subjGrades, int index);
	void DeleteSubjGrades(int index);
};

