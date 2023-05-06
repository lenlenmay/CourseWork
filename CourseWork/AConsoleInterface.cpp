#pragma once
#include "AConsoleInterface.h"

AConsoleInterface::AConsoleInterface()
{
	AConsoleInterface::Init();
}

void AConsoleInterface::Init()
{
	StartPage();
	HWND hWnd = GetForegroundWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);

}

void AConsoleInterface::StartPage()
{
	cslTools.Clear();
	std::cout << "________��������� ��������________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) ������� ������������ ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) ������� ����� ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::string PathToFile{};

	std::string action{};
	std::cout << ">>> ";
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "����������� ������ ����� ��������!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		StartPage();
	}
	
	
		
	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		std::cout << "�������� ������������ ��" << std::endl 
			<< "������� ���� � �������� ����� � �������:" << std::endl 
			<< "<�������� �����>:\\<�������� �����>\\<�������� �����.txt>" << std::endl;
		std::cout << ">>> ";
		std::cin >> PathToFile;
		db.Open(PathToFile);
		break;

	case 2:
		cslTools.Clear();
		std::cout << "�������� ����� ��" << std::endl
			<< "������� ���� � �������� ����� � �������:" << std::endl
			<< "<�������� �����>:\\<�������� �����>\\<�������� �����.txt>" << std::endl;
		std::cout << ">>> ";
		std::cin >> PathToFile;
		db.Create(PathToFile);
		break;
	default:
		cslTools.Clear();
		std::cout << "������ ������ �������� ���!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		MainPage();
		break;
	}
	db.ReadFromFile();
	MainPage();
}

void AConsoleInterface::MainPage()
{
	cslTools.Clear();
	std::cout << "_________������� ��������_________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) ����� ��������� ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) ����� �������������� ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) �����" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::string action{};
	std::cout << ">>> ";
	std::cin >> action;



	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "����������� ������ ����� ��������!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		MainPage();
	}



	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewPage();
		break;

	case 2:
		cslTools.Clear();
		EditModePage();
		break;

	case 3:
		cslTools.Clear();
		StartPage();
		break;

	default:
		cslTools.Clear();
		std::cout << "������ ������ �������� ���!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		MainPage();
		break;
	}

}

void AConsoleInterface::ViewPage()
{
	cslTools.Clear();

	std::cout << "_________����� ���������__________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) ���������� ������ ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) ���������� ������ �� �������" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) �����" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "����������� ������ ����� ��������!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		ViewPage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewRecordsPage();
		break;

	case 2:
		cslTools.Clear();
		ViewSortedRecordsPage();
		break;
	case 3:
		cslTools.Clear();
		MainPage();
		break;
	default:
		cslTools.Clear();
		std::cout << "������ ������ �������� ���!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		ViewPage();
		break;
	}

}

void AConsoleInterface::ShowRecords()
{
	std::cout << "______________________________________________________________________���� ������_________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < db.DataList.Count(); i++) {// �������� �� ������
		Data data = db.DataList.GetElement(i);
		std::cout << "| " << i + 1 << " | " << std::left << std::setw(15) << data.GetSurname() << " | "
			<< std::left << std::setw(15) << data.GetName() << " | "
			<< std::left << std::setw(15) << data.GetPatrinymic() << " | "
			<< std::left << std::setw(10) << data.GetGender() << " | "
			<< std::left << std::setw(10) << data.GetDay() + "." + data.GetMonth() + "." + data.GetYear() << " | "
			<< std::left << std::setw(4) << data.GetYearAddtoUniversity() << " | "
			<< std::left << std::setw(15) << data.GetFaculty() << " | "
			<< std::left << std::setw(25) << data.GetDepartment() << " | "
			<< std::left << std::setw(5) << data.GetGroup() << " | "
			<< std::left << std::setw(5) << data.GetNumberRecordBook() << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}


void AConsoleInterface::ViewRecordsPage()
{
	ShowRecords();

	std::cout << std::endl << "--------------" << std::endl;
	std::cout << "|" << std::left << std::setw(12) << "(1) �����" << "|" << std::endl;
	std::cout << "--------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "����������� ������ ����� ��������!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		ViewRecordsPage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewPage();
		break;
	default:
		cslTools.Clear();
		std::cout << "������ ������ �������� ���!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		ViewRecordsPage();
		break;
	}
}

void AConsoleInterface::ViewSortedRecordsPage()
{

}

void AConsoleInterface::EditModePage()
{
	cslTools.Clear();
	ShowRecords();

	std::cout << "_________����� ��������������_________" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(1) �������� ������" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(2) �������� ������" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(3) ������� ������" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(4) �����" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "����������� ������ ����� ��������!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		EditModePage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		AddRecordPage();
		break;

	case 2:
		cslTools.Clear();
		ChangedRecordPage();
		break;

	case 3:
		cslTools.Clear();
		DeleteRecordPage();
		break;

	case 4:
		cslTools.Clear();
		MainPage();
		break;

	default:
		cslTools.Clear();
		std::cout << "������ ������ �������� ���!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		EditModePage();
		break;
	}

}

void AConsoleInterface::AddRecordPage()
{
	cslTools.Clear();

	std::string Input{};
	Data tempData;
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (!valIn.isNSPatrinymic(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetSurname(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (!valIn.isNSPatrinymic(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetName(Input);
	
	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� �������� >>> ";
		std::cin >> Input;

		if (!valIn.isNSPatrinymic(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetPatrinymic(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (!valIn.isGender(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isGender(Input));

	tempData.SetGender(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� >>> ";
		std::cin >> Input;

		if (!valIn.isDayMonth(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isDayMonth(Input));

	tempData.SetDay(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� (�����) >>> ";
		std::cin >> Input;

		if (!valIn.isDayMonth(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isDayMonth(Input));

	tempData.SetMonth(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (!valIn.isYAndYUniversity(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYear(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� ����������� � �������� >>> ";
		std::cin >> Input;

		if (!valIn.isYAndYUniversity(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYearAddtoUniversity(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��������� (��������) >>> ";
		std::cin >> Input;

		if (!valIn.isFDepartment(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetFaculty(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (!valIn.isFDepartment(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetDepartment(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (!valIn.isGroup(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isGroup(Input));

	tempData.SetGroup(Input);

	cslTools.Clear();
	do {
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� �������� ������ >>> ";
		std::cin >> Input;

		if (!valIn.isNumberRecordBook(Input)) {
			cslTools.Clear();
		}

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNumberRecordBook(Input));

	tempData.SetNumberRecordBook(Input);

	//db.AddRecord();

	cslTools.Clear();
	std::cout << "____________________________���������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� ........" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________���������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� >>>......" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________���������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� >>>>>>..." << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________���������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� >>>>>>>>>" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	EditModePage();
}

void AConsoleInterface::ChangedRecordPage()
{
	cslTools.Clear();
	ShowRecords();

	std::cout << "_________��������� ������_________" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(1) �������� ����� ������" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(-back) �����" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (action == "-back")
	{
		cslTools.Clear();
		EditModePage();
	}

}

void AConsoleInterface::DeleteRecordPage()
{
	cslTools.Clear();
	ShowRecords();

	std::cout << "____________�������� ������___________" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "�������� ����� ������" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(-back) �����" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (action == "-back")
	{
		cslTools.Clear();
		EditModePage();
	}

	cslTools.Clear();
	std::cout << "____________________________�������� ������___________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� �������. ������� �� �������� �������������� ........" << "|" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________�������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� �������. ������� �� �������� �������������� >>>......" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________�������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� �������. ������� �� �������� �������������� >>>>>>..." << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________�������� ������___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� �������. ������� �� �������� �������������� >>>>>>>>>" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);
}


