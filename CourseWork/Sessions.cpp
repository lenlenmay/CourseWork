#include "Sessions.h"

Sessions::Sessions()
{
}

void Sessions::SetcountSessions(int countSessions)
{
	this->countSessions = countSessions;
}

int Sessions::GetcountSessions()
{
	return this->countSessions;
}

bool Sessions::isSession(int index)
{
	return sessions[index].GetisAdded();
}


void Sessions::AddSession(int index)
{
	if ((0 <= index && index < 9) && sessions[index].GetisAdded() == false) {
		Session tempData;
		tempData.SetIndex(index);
		tempData.SetcountSubjects(0);
		sessions[index] = tempData;
		countSessions++;
		sessions[index].SetisAdded(true);
	}
}

void Sessions::DeleteSession(int index)
{
	if ((0 <= index && index < 9) && sessions[index].GetisAdded() == true) {
		sessions[index].SetisAdded(false);
		countSessions--;
		for (int i = 0; i < sessions[index].GetcountSubjects(); i++) {
			sessions[index].DeleteSubjGrades(i);
		}
		sessions[index].SetisAdded(false);
	}
}

Sessions::~Sessions()
{
}
