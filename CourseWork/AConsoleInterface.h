#pragma once
#include "IConsoleApp.h"
#include "AConsoleTools.h"
#include "Windows.h"
#include "ADatabase.h"
#include "Data.h"
#include "ACryptoTools.h"
#include <iomanip>
#include "AHandlerExceptions.h"

class AConsoleInterface : IConsoleApp {
public:
	AConsoleTools cslTools;
	ACryptoTools cryptoTools;
	AHandlerExceptions hExceptions;
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
	void ViewRecordsPage();
	void ViewSortedRecordsPage();
	void EditModePage();
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
	
};

