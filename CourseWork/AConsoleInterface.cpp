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

	db.DataList.Clear();

	cslTools.Clear();
	std::cout << "________��������� ��������________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) ������� ������������ ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) ������� ����� ��" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	/*std::string str{"ABOBAOFOF"};
	std::cout << str << std::endl;
	str = cryptoTools.EncryptionOfString(str);
	std::cout << str << std::endl;
	str = cryptoTools.DecryptionOfString(str);
	std::cout << str << std::endl;*/

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
		std::cout << "_________________�������� ������������ ��_________________" << std::endl;
		std::cout << "|" << std::left << std::setw(56) << "������� ���� � �������� ����� � �������:" << "|" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(56) << "<�������� �����>:\\<�������� �����>\\<�������� �����.txt>" << "|" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(56) << "C:\\Projects_C++\\Files\\new.txt" << "|" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << ">>> ";
		std::cin >> PathToFile;
		db.Open(PathToFile);
		break;

	case 2:
		cslTools.Clear();
		std::cout << "____________________�������� ����� ��_____________________" << std::endl;
		std::cout << "|" << std::left << std::setw(56) << "������� ���� � �������� ����� � �������:" << "|" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(56) << "<�������� �����>:\\<�������� �����>\\<�������� �����.txt>" << "|" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(56) << "C:\\Projects_C++\\Files\\new.txt" << "|" << std::endl;
		std::cout << "----------------------------------------------------------" << std::endl;
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

void AConsoleInterface::ShowRecord(int index)
{
	std::cout << "________________________________________________________________________________���� ������_______________________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(175) << "������ �����������" << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "| " << "�" << " | " << std::left << std::setw(15) << "�������" << " | "
			<< std::left << std::setw(15) << "���" << " | "
			<< std::left << std::setw(15) << "��������" << " | "
			<< std::left << std::setw(7) << "���" << " | "
			<< std::left << std::setw(13) << "���� ��������" << " | "
			<< std::left << std::setw(15) << "��� �����������" << " | "
			<< std::left << std::setw(15) << "���������" << " | "
			<< std::left << std::setw(25) << "�������" << " | "
			<< std::left << std::setw(6) << "�����" << " | "
			<< std::left << std::setw(17) << "�����" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "� �����������" << " | "
			<< std::left << std::setw(15) << "(��������)" << " | "
			<< std::left << std::setw(25) << " " << " | "
			<< std::left << std::setw(6) << "������" << " | "
			<< std::left << std::setw(17) << "� �������� ������" << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

			Data data = db.DataList[index - 1];
			std::cout << "| " << index << " | " << std::left << std::setw(15) << data.GetSurname() << " | "
				<< std::left << std::setw(15) << data.GetName() << " | "
				<< std::left << std::setw(15) << data.GetPatrinymic() << " | "
				<< std::left << std::setw(7) << data.GetGender() << " | "
				<< std::left << std::setw(13) << data.GetDay() + "." + data.GetMonth() + "." + data.GetYear() << " | "
				<< std::left << std::setw(15) << data.GetYearAddtoUniversity() << " | "
				<< std::left << std::setw(15) << data.GetFaculty() << " | "
				<< std::left << std::setw(25) << data.GetDepartment() << " | "
				<< std::left << std::setw(6) << data.GetGroup() << " | "
				<< std::left << std::setw(17) << data.GetNumberRecordBook() << " |" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}

void AConsoleInterface::ShowRecords()
{
	std::cout << "________________________________________________________________________________���� ������_______________________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(175) << "������ �����������" << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "| " << "�" << " | " << std::left << std::setw(15) << "�������" << " | "
			<< std::left << std::setw(15) << "���" << " | "
			<< std::left << std::setw(15) << "��������" << " | "
			<< std::left << std::setw(7) << "���" << " | "
			<< std::left << std::setw(13) << "���� ��������" << " | "
			<< std::left << std::setw(15) << "��� �����������" << " | "
			<< std::left << std::setw(15) << "���������" << " | "
			<< std::left << std::setw(25) << "�������" << " | "
			<< std::left << std::setw(6) << "�����" << " | "
			<< std::left << std::setw(17) << "�����" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "� �����������" << " | "
			<< std::left << std::setw(15) << "(��������)" << " | "
			<< std::left << std::setw(25) << " " << " | "
			<< std::left << std::setw(6) << "������" << " | "
			<< std::left << std::setw(17) << "� �������� ������" << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

		for (int i = 0; i < db.DataList.Count(); i++) {
			Data data = db.DataList[i];
			std::cout << "| " << i + 1 << " | " << std::left << std::setw(15) << data.GetSurname() << " | "
				<< std::left << std::setw(15) << data.GetName() << " | "
				<< std::left << std::setw(15) << data.GetPatrinymic() << " | "
				<< std::left << std::setw(7) << data.GetGender() << " | "
				<< std::left << std::setw(13) << data.GetDay() + "." + data.GetMonth() + "." + data.GetYear() << " | "
				<< std::left << std::setw(15) << data.GetYearAddtoUniversity() << " | "
				<< std::left << std::setw(15) << data.GetFaculty() << " | "
				<< std::left << std::setw(25) << data.GetDepartment() << " | "
				<< std::left << std::setw(6) << data.GetGroup() << " | "
				<< std::left << std::setw(17) << data.GetNumberRecordBook() << " |" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}
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
	std::string Input{};
	Data tempData;
	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetSurname(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetName(Input);
	
	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� �������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetPatrinymic(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isGender(Input));

	tempData.SetGender(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}

		if (Input.size() == 1)
		{
			Input = '0' + Input;
		}

	} while (!valIn.isDay(Input));

	tempData.SetDay(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� (�����) >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}

		if (Input.size() == 1)
		{
			Input = '0' + Input;
		}

	} while (!valIn.isMonth(Input));

	tempData.SetMonth(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYear(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� ����������� � �������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYearAddtoUniversity(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��������� (��������) >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetFaculty(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetDepartment(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isGroup(Input));

	tempData.SetGroup(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________���������� ������________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� �������� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}
	} while (!valIn.isNumberRecordBook(Input));

	tempData.SetNumberRecordBook(Input);

	db.AddRecord(tempData);

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

	db.SaveFile();
	EditModePage();
}

void AConsoleInterface::ChangedRecordPage()
{
	std::string Input{};

	do {
		cslTools.Clear();
		ShowRecords();

		std::cout << "____________��������� ������__________" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) �����" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}

	} while (!(valIn.isNumberOfRecord(Input, db.DataList.Count())));

	ChoiceChangedElement(std::atoi(Input.c_str()));
}

void AConsoleInterface::ChoiceChangedElement(int index)
{
	cslTools.Clear();
	ShowRecord(index);

	std::cout << "_______________��������� ������_______________" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(1) �������� �.�.�" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(2) �������� ���" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(3) �������� ���� ��������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(4) �������� ��� ����������� � ��������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(5) �������� �������� (���������)" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(6) �������� �������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(7) �������� ������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(8) �������� ����� �������� ������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(9) �����" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

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
		ChangedSNPPage(index);
		break;

	case 2:
		cslTools.Clear();
		ChangedGenderPage(index);
		break;

	case 3:
		cslTools.Clear();
		ChangedDateofBirthPage(index);
		break;

	case 4:
		cslTools.Clear();
		ChangedYearAddtoUniversity(index);
		break;

	case 5:
		cslTools.Clear();
		ChangedFaculty(index);
		break;

	case 6:
		cslTools.Clear();
		ChangedDepartment(index);
		break;

	case 7:
		cslTools.Clear();
		ChangedGroup(index);
		break;

	case 8:
		cslTools.Clear();
		ChangedNumberRecordBook(index);
		break;

	case 9:
		cslTools.Clear();
		ChangedRecordPage();
		break;

	default:
		cslTools.Clear();
		std::cout << "������ ������ �������� ���!" << std::endl;
		std::cout << "���������� ��� ���..." << std::endl;
		Sleep(3000);
		ChoiceChangedElement(index);
		break;
	}
}

void AConsoleInterface::ChangedSNPPage(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetSurname(Input);

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetName(Input);

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�.�.�" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� �������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetPatrinymic(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);;
}

void AConsoleInterface::ChangedGenderPage(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}
	} while (!valIn.isGender(Input));

	tempData.SetGender(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index + 1);;
}

void AConsoleInterface::ChangedDateofBirthPage(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}

		if (Input.size() == 1)
		{
			Input = '0' + Input;
		}

	} while (!valIn.isDay(Input));

	tempData.SetDay(Input);

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� (�����) >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}

		if (Input.size() == 1)
		{
			Input = '0' + Input;
		}

	} while (!valIn.isMonth(Input));

	tempData.SetMonth(Input);

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "���� ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYear(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);
}

void AConsoleInterface::ChangedYearAddtoUniversity(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��� ����������� � �������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYearAddtoUniversity(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);;
}

void AConsoleInterface::ChangedFaculty(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ��������� (��������) >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetFaculty(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);
}

void AConsoleInterface::ChangedDepartment(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetDepartment(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);
}

void AConsoleInterface::ChangedGroup(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);
		}
	} while (!valIn.isGroup(Input));

	tempData.SetGroup(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);
}

void AConsoleInterface::ChangedNumberRecordBook(int index)
{
	std::string Input{};

	Data tempData = db.DataList[index - 1];

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________��������� ������_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� �������� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);
		}
	} while (!valIn.isNumberRecordBook(Input));

	tempData.SetNumberRecordBook(Input);

	db.ChangedData(tempData, index);

	db.SaveFile();

	AnimationOfLoad();

	ChoiceChangedElement(index);
}

void AConsoleInterface::AnimationOfLoad()
{
	cslTools.Clear();
	std::cout << "____________________________��������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� ��������. ������� �� �������� �������������� ........" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________��������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� ��������. ������� �� �������� �������������� >>>......" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________��������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� ��������. ������� �� �������� �������������� >>>>>>..." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________��������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� ��������. ������� �� �������� �������������� >>>>>>>>>" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);
}




void AConsoleInterface::DeleteRecordPage()
{
	std::string Input{};

	if (db.DataList.Count() == 0) {
		cslTools.Clear();
		std::cout << "_____________________________�������� ������___________________________" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(69) << "������ �����������. ������� �� �������� ��������������" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		Sleep(2);
		EditModePage();
	}

	do {
		cslTools.Clear();
		ShowRecords();

		std::cout << "____________�������� ������___________" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) �����" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
		}

	} while (!(valIn.isNumberOfRecord(Input, db.DataList.Count()) && AgreeActionPage(Input)));


	db.DeleteRecord(std::atoi(Input.c_str()) - 1);

	cslTools.Clear();
	std::cout << "_____________________________�������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� ........." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_____________________________�������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� >>>......" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_____________________________�������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� >>>>>>..." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_____________________________�������� ������___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� >>>>>>>>>" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	db.SaveFile();
	EditModePage();
}

bool AConsoleInterface::AgreeActionPage(std::string Input)
{
	std::string Answer{};
	do {
		cslTools.Clear();
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "�� �������, ��� ������ ������� ������ ��� ������� ? " << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "����� � �������: Y - �� / N - ���" << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� >>> ";
		std::cin >> Input;

	} while (!(Input == "Y" || Input == "N"));

	return valIn.isAgree(Input);
}

