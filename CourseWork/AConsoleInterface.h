#pragma once
#include "IConsoleApp.h"
#include "AConsoleTools.h"
#include "Windows.h"
#include "ADatabase.h"
#include "Data.h"
#include <iomanip>
#include "AHandlerExceptions.h"

class AConsoleInterface : IConsoleApp {
public:
	AConsoleTools cslTools;
	AHandlerExceptions hExceptions;
	ADatabase db;
	ValidationInput valIn;
	AConsoleInterface();

private:
	void Init() override;
	void StartPage();
	void MainPage();
	void ViewPage();
	void ShowRecords();
	void ViewRecordsPage();
	void ViewSortedRecordsPage();
	void EditModePage();
	void AddRecordPage();
	void ChangedRecordPage();
	void DeleteRecordPage();
	
};