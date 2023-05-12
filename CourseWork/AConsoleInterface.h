#pragma once
#include "IConsoleApp.h"
#include "AConsoleTools.h"
#include "Windows.h"
#include "ADatabase.h"
#include "Data.h"
#include "ACryptoTools.h"
#include <iomanip>

class AConsoleInterface : IConsoleApp {
public:
	AConsoleTools cslTools;
	ACryptoTools cryptoTools;
	ADatabase db;
	ValidationInput valIn;
	AConsoleInterface();

private:
	void Init() override;
	void StartPage();
	void MainPage();
	void ViewPage();
	void ShowRecord(int index);
	void ShowRecords();
	std::string IndexAddedSession(int NumberOfRecord);

	void ViewRecordsPage();
	void ViewSessionsPage();
	void ChoiceViewSessionPage(int NumberOfRecord);
	void ViewSessionPage(int NumberOfRecord, int NumberOfSession);
	void ShowSession(int NumberOfRecord, int NumberOfSession);

	void ViewSortedRecordsPage();

	void ChoiceEditPage();
	void EditRecordPage();

	void EditSessionsPage();
	void ChoiceEditActionSessionPage(int NumberOfRecord);

	void ChoiceEditSessionPage(int NumberOfRecord);

	void EditSessionPage(int NumberOfRecord, int NumberOfSession);

	void AddRecordSessionPage(int NumberOfRecord, int NumberOfSession);
	void ChangeRecordSessionPage(int NumberOfRecord, int NumberOfSession);
	void ChoiceChangeRecordSessionPage(int NumberOfRecord, int NumberOfSession, int NumberOfRecordSession);
	void ChangeSubjectRecordSessionPage(int NumberOfRecord, int NumberOfSession, int NumberOfRecordSession);
	void ChangeGradeRecordSessionPage(int NumberOfRecord, int NumberOfSession, int NumberOfRecordSession);
	void DeleteRecordSessionPage(int NumberOfRecord, int NumberOfSession);

	void AddSessionPage(int NumberOfRecord);
	void DeleteSessionPage(int NumberOfRecord);

	void AddRecordPage();

	void ChangedRecordPage();
	void ChoiceChangedElement(int choice);
	void ChangedSNPPage(int index);
	void ChangedGenderPage(int index);
	void ChangedDateofBirthPage(int index);
	void ChangedYearAddtoUniversity(int index);
	void ChangedFaculty(int index);
	void ChangedDepartment(int index);
	void ChangedGroup(int index);
	void ChangedNumberRecordBook(int index);

	void AnimationOfLoad();
	void DeleteRecordPage();
	bool AgreeActionPage(std::string Input);
	
	void IncorrectInput();
};

