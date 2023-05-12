#pragma once
#include "AList.h"
#include "Session.h"

class Sessions: public Session
{
	int countSessions = 0;
public:

	Session sessions[9];

	Sessions();
	void SetcountSessions(int countSessions);
	int GetcountSessions();
	bool isSession(int index);
	void AddSession(int index);
	void DeleteSession(int index);
	~Sessions();
};

