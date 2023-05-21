#include "Session.h"

SubjGrades::SubjGrades()
{

}

SubjGrades::SubjGrades(std::string Subject, std::string Grade)
{
	this->Subject = Subject;
	this->Grade = Grade;
}

void SubjGrades::Clear()
{
	this->Subject = "";
	this->Grade = "";
}

std::string SubjGrades::GetSubject()
{
	return this->Subject;
}

std::string SubjGrades::GetGrade()
{
	return this->Grade;
}

void SubjGrades::SetSubject(std::string Subject)
{
	this->Subject = Subject;
}

void SubjGrades::SetGrade(std::string Grade)
{
	this->Grade = Grade;
}

SubjGrades::~SubjGrades()
{
}


Session::Session()
{
	this->countSubjects = 0;
	this->index = 0;
}

bool Session::GetisAdded()
{
	return this->bisAdded;
}

void Session::SetisAdded(bool bisAdded)
{
	this->bisAdded = bisAdded;
}

int Session::GetIndex()
{
	return this->index;
}

void Session::SetIndex(int index)
{
	this->index = index;
}

int Session::GetcountSubjects()
{
	return this->countSubjects;
}

void Session::SetcountSubjects(int countSubjects)
{
	this->countSubjects = countSubjects;
}

void Session::AddSubjGrades(std::string Subject, std::string Grade)
{
	if (0 <= countSubjects && countSubjects < 9) {

		SubjGrades tempsubjGrades(Subject, Grade);

		subjGrades[countSubjects] = tempsubjGrades;

		countSubjects++;
	}
}

void Session::ChangedSubjGrades(SubjGrades _subjGrades, int index)
{
	if (0 <= index && index < countSubjects) {

		subjGrades[index] = _subjGrades;
	}

}

void Session::DeleteSubjGrades(int index)
{
	if (0 <= index && index < countSubjects) {

		subjGrades[index].Clear();
		for (int i = index; i < countSubjects - 1; i++)
		{
			subjGrades[i] = subjGrades[i + 1];
		}
		subjGrades[countSubjects - 1].Clear();
		countSubjects--;
	}
}