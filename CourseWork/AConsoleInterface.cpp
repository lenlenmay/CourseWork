#pragma once
#include "AConsoleInterface.h"

AConsoleInterface::AConsoleInterface()
{
	AConsoleInterface::Init();
}

void AConsoleInterface::Init()
{
	StartPage();
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
	std::cout << "|" << std::left << std::setw(32) << "(3) ����� �� ���������" << "|" << std::endl;
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
		IncorrectInput();
		StartPage();
	}
	
	
		
	switch (std::atoi(action.c_str())) {
	case 1:
		
		do {
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
		} while (!db.Open(PathToFile));
		break;

	case 2:

		do {
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
		} while (!db.Create(PathToFile));
		break;

	case 3:

		cslTools.Clear();
		exit(0);
		break;

	default:
		IncorrectInput();
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
	std::cout << "|" << std::left << std::setw(32) << "(4) ����� �� ���������" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::string action{};
	std::cout << ">>> ";
	std::cin >> action;



	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		MainPage();
	}



	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewPage();
		break;

	case 2:
		cslTools.Clear();
		ChoiceEditPage();
		break;

	case 3:
		cslTools.Clear();
		StartPage();
		break;

	case 4:
		cslTools.Clear();
		exit(0);
		break;

	default:
		IncorrectInput();
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
	std::cout << "|" << std::left << std::setw(32) << "(2) ���������� ������ ��������" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) ���������� ������ �� �������" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(4) �����" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		ViewPage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewRecordsPage();
		break;

	case 2:
		cslTools.Clear();
		ViewSessionsPage();
		break;

	case 3:
		cslTools.Clear();
		ChoiceSessionViewSortedRecordsPage();
		break;

	case 4:
		cslTools.Clear();
		MainPage();
		break;

	default:
		IncorrectInput();
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
			<< std::left << std::setw(20) << "�������" << " | "
			<< std::left << std::setw(11) << "�����" << " | "
			<< std::left << std::setw(17) << "�����" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "� �����������" << " | "
			<< std::left << std::setw(15) << "(��������)" << " | "
			<< std::left << std::setw(20) << " " << " | "
			<< std::left << std::setw(11) << "������" << " | "
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
				<< std::left << std::setw(20) << data.GetDepartment() << " | "
				<< std::left << std::setw(11) << data.GetGroup() << " | "
				<< std::left << std::setw(17) << data.GetNumberRecordBook() << " |" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}

void AConsoleInterface::ShowRecords()
{
	std::cout << "________________________________________________________________________________���� ������_______________________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(174) << "������ �����������" << " |" << std::endl;
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
			<< std::left << std::setw(20) << "�������" << " | "
			<< std::left << std::setw(11) << "�����" << " | "
			<< std::left << std::setw(17) << "�����" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "� �����������" << " | "
			<< std::left << std::setw(15) << "(��������)" << " | "
			<< std::left << std::setw(20) << " " << " | "
			<< std::left << std::setw(11) << "������" << " | "
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
				<< std::left << std::setw(20) << data.GetDepartment() << " | "
				<< std::left << std::setw(11) << data.GetGroup() << " | "
				<< std::left << std::setw(17) << data.GetNumberRecordBook() << " |" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}
	}
	
	
}

std::string AConsoleInterface::IndexAddedSession(int NumberOfRecord)
{
	std::string Indexs{};
	for (int i = 0; i < 9; i++) {
		if (db.DataList[NumberOfRecord - 1].Sessions.isSession(i)) {
			Indexs += " " + std::to_string(i + 1);
		}
	}
	return Indexs;
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
		IncorrectInput();
		ViewRecordsPage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewPage();
		break;
	default:
		IncorrectInput();
		ViewRecordsPage();
		break;
	}
}

void AConsoleInterface::ViewSessionsPage()
{
	std::string Input{};
	int NumberOfRecord = 0;

	do {
		cslTools.Clear();
		ShowRecords();

		std::cout << "_____________����� �������� ��� ��������� ������___________" << std::endl;
		std::cout << "|" << std::left << std::setw(57) << "�������� ����� ������ ��������" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(57) << "(-back) �����" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ �������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ViewPage();
		}

	} while (!(valIn.isNumberOfRecord(Input, db.DataList.Count())));

	NumberOfRecord = std::atoi(Input.c_str());
	
	ChoiceViewSessionPage(NumberOfRecord);

}

void AConsoleInterface::ChoiceViewSessionPage(int NumberOfRecord)
{
	std::string Input{};

	do {
		cslTools.Clear();
		ShowRecord(NumberOfRecord);

		std::cout << "_______________________����� ������_________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|������ ����������� ������:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) �����" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ViewSessionsPage();
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	if (db.DataList[NumberOfRecord - 1].Sessions.isSession(std::atoi(Input.c_str()) - 1)) {
		ViewSessionPage(NumberOfRecord, std::atoi(Input.c_str()));
	}
	else {
		cslTools.Clear();
		std::cout << "__________________________����� ������________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "����� ������ ���. �������� � � ������ ��������������" << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Sleep(2000);
		ChoiceViewSessionPage(NumberOfRecord);
	}
	
}

void AConsoleInterface::ViewSessionPage(int NumberOfRecord, int NumberOfSession)
{
	ShowSession(NumberOfRecord, NumberOfSession);

	std::cout << std::endl << "--------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(48) << "(1) �����" << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(48) << "(2) ��������� � �������� ������ ��������" << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(48) << "(3) ��������� � �������� ������ ���������" << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		ViewRecordsPage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ChoiceViewSessionPage(NumberOfRecord);
		break;

	case 2:
		cslTools.Clear();
		ViewSessionsPage();
		break;

	case 3:
		cslTools.Clear();
		ViewPage();
		break;
	default:
		IncorrectInput();
		ViewSessionPage(NumberOfRecord, NumberOfSession);
		break;
	}
}

void AConsoleInterface::ShowSession(int NumberOfRecord, int NumberOfSession)
{
	cslTools.Clear();
	Data tempData = db.DataList[NumberOfRecord - 1];
	std::cout << "__________________������ " << NumberOfSession << "_________________" << std::endl;
	if (tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() == 0) {
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(39) << "������ � ������ �����������" << " |" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	else {
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "| � | " << std::left << std::setw(26) << "�������" << " | " << std::left << std::setw(6) << "������" << " |" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;

		for (int i = 0; i < tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects(); i++) {
			std::cout << "| " << i + 1 << " | " << std::left << std::setw(26) << tempData.Sessions.sessions[NumberOfSession - 1].subjGrades[i].GetSubject() << " | " <<
				std::left << std::setw(6) << tempData.Sessions.sessions[NumberOfSession - 1].subjGrades[i].GetGrade() << " |" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
		}
	}
}

void AConsoleInterface::ChoiceSessionViewSortedRecordsPage()
{
	std::string Input{};

	do {
		cslTools.Clear();

		std::cout << "_______________________����� ������_________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) �����" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ViewPage();
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	ViewSortedRecordsPage(std::atoi(Input.c_str()));
}

void AConsoleInterface::ViewSortedRecordsPage(int NumberOfSession)
{
	cslTools.Clear();
	std::cout << "____________________________________________________________________________���� ������_______________________________________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(170) << "������ �����������" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "| " << std::left << std::setw(15) << "�������" << " | "
			<< std::left << std::setw(15) << "���" << " | "
			<< std::left << std::setw(15) << "��������" << " | "
			<< std::left << std::setw(7) << "���" << " | "
			<< std::left << std::setw(13) << "���� ��������" << " | "
			<< std::left << std::setw(15) << "��� �����������" << " | "
			<< std::left << std::setw(15) << "���������" << " | "
			<< std::left << std::setw(25) << "�������" << " | "
			<< std::left << std::setw(6) << "�����" << " | "
			<< std::left << std::setw(17) << "�����" << " |" << std::endl;
		std::cout << "| " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "� �����������" << " | "
			<< std::left << std::setw(15) << "(��������)" << " | "
			<< std::left << std::setw(25) << " " << " | "
			<< std::left << std::setw(6) << "������" << " | "
			<< std::left << std::setw(17) << "� �������� ������" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(51) << "���������" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

		bool bisEmpty = true;

		for (int i = 0; i < db.DataList.Count(); i++) {
			Data data = db.DataList[i];
			if (data.Sessions.sessions[NumberOfSession - 1].GetisAdded() && data.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() != 0) {
				if (data.Sessions.isGradeOfSession(NumberOfSession - 1) == "5") {
					ShowData(data);
					std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
					bisEmpty = false;
				}
			}
			
		}

		if (bisEmpty == true) {
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "| " << std::left << std::setw(51) << "���������� ���" << " |" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}

		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(51) << "���������" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

		bisEmpty = true;

		for (int i = 0; i < db.DataList.Count(); i++) {
			Data data = db.DataList[i];
			if (data.Sessions.sessions[NumberOfSession - 1].GetisAdded() && data.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() != 0) {
				if (data.Sessions.isGradeOfSession(NumberOfSession - 1) == "4") {
					ShowData(data);
					std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
					bisEmpty = false;
				}
			}

		}

		if (bisEmpty == true) {
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "| " << std::left << std::setw(51) << "���������� ���" << " |" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}


		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(51) << "���������" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

		bisEmpty = true;

		for (int i = 0; i < db.DataList.Count(); i++) {
			Data data = db.DataList[i];
			if (data.Sessions.sessions[NumberOfSession - 1].GetisAdded() && data.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() != 0) {
				if (data.Sessions.isGradeOfSession(NumberOfSession - 1) == "3") {
					ShowData(data);
					std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
					bisEmpty = false;
				}
			}

		}

		if (bisEmpty == true) {
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "| " << std::left << std::setw(51) << "���������� ���" << " |" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}

	}

	std::cout << std::endl << "--------------" << std::endl;
	std::cout << "|" << std::left << std::setw(12) << "(1) �����" << "|" << std::endl;
	std::cout << "--------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		ViewSortedRecordsPage(NumberOfSession);
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ViewPage();
		break;
	default:
		IncorrectInput();
		ViewSortedRecordsPage(NumberOfSession);
		break;
	}

}

void AConsoleInterface::ShowData(Data& data)
{
	std::cout << "| " << std::left << std::setw(15) << data.GetSurname() << " | "
		<< std::left << std::setw(15) << data.GetName() << " | "
		<< std::left << std::setw(15) << data.GetPatrinymic() << " | "
		<< std::left << std::setw(7) << data.GetGender() << " | "
		<< std::left << std::setw(13) << data.GetDay() + "." + data.GetMonth() + "." + data.GetYear() << " | "
		<< std::left << std::setw(15) << data.GetYearAddtoUniversity() << " | "
		<< std::left << std::setw(15) << data.GetFaculty() << " | "
		<< std::left << std::setw(25) << data.GetDepartment() << " | "
		<< std::left << std::setw(6) << data.GetGroup() << " | "
		<< std::left << std::setw(17) << data.GetNumberRecordBook() << " |" << std::endl;
}



void AConsoleInterface::ChoiceEditPage()
{
	cslTools.Clear();

	std::cout << "__________����� ��������������_________" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(1) ������������� ������ ��" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(2) ������������� ������ ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(3) �����" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		ViewPage();
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		EditRecordPage();
		break;

	case 2:
		cslTools.Clear();
		EditSessionsPage();
		break;

	case 3:
		cslTools.Clear();
		MainPage();
		break;

	default:
		IncorrectInput();
		ChoiceEditPage();
		break;
	}
}

void AConsoleInterface::EditRecordPage()
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
		IncorrectInput();
		EditRecordPage();
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
		IncorrectInput();
		ChoiceEditPage();
		break;
	}

}

void AConsoleInterface::EditSessionsPage()
{
	std::string Input{};
	int NumberOfRecord = 0;

	do {
		cslTools.Clear();
		ShowRecords();

		std::cout << "_____________����� �������� ��� �������������� ������___________" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�������� ����� ������ ��������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) �����" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ �������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ViewPage();
		}

	} while (!(valIn.isNumberOfRecord(Input, db.DataList.Count())));

	NumberOfRecord = std::atoi(Input.c_str());

	ChoiceEditActionSessionPage(NumberOfRecord);
}

void AConsoleInterface::ChoiceEditActionSessionPage(int NumberOfRecord)
{
	cslTools.Clear();
	std::cout << "_________�������������� ������_________" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(1) ������������� ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(2) �������� ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(3) ������� ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(4) �����" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(5) ��������� � ������ ��������������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		ChoiceEditActionSessionPage(NumberOfRecord);
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ChoiceEditSessionPage(NumberOfRecord);
		break;

	case 2:
		cslTools.Clear();
		AddSessionPage(NumberOfRecord);
		break;

	case 3:
		cslTools.Clear();
		DeleteSessionPage(NumberOfRecord);
		break;

	case 4:
		cslTools.Clear();
		EditSessionsPage();
		break;

	case 5:
		cslTools.Clear();
		ChoiceEditPage();
		break;

	default:
		IncorrectInput();
		ChoiceEditActionSessionPage(NumberOfRecord);
		break;
	}
}

void AConsoleInterface::ChoiceEditSessionPage(int NumberOfRecord)
{
	std::string Input{};

	do {
		cslTools.Clear();

		std::cout << "_______________________����� ������_________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|������ ����������� ������:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) �����" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceEditActionSessionPage(NumberOfRecord);
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	if (db.DataList[NumberOfRecord - 1].Sessions.isSession(std::atoi(Input.c_str()) - 1)) {
		EditSessionPage(NumberOfRecord, std::atoi(Input.c_str()));
	}
	else {
		cslTools.Clear();
		std::cout << "__________________________����� ������________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "����� ������ ���. �������� �." << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Sleep(2000);
		ChoiceEditSessionPage(NumberOfRecord);
	}
}

void AConsoleInterface::EditSessionPage(int NumberOfRecord, int NumberOfSession)
{
	cslTools.Clear();
	ShowSession(NumberOfRecord, NumberOfSession);
	std::cout << "________�������������� ������ "<< NumberOfSession <<"________" << std::endl;
	if (db.DataList[NumberOfRecord - 1].Sessions.sessions[NumberOfSession - 1].GetcountSubjects() >= 9) {
		std::cout << "|" << std::left << std::setw(37) << "(X) ������ ���������" << "|" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
	}
	else {
		std::cout << "|" << std::left << std::setw(37) << "(1) �������� ������" << "|" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
	}
	
	std::cout << "|" << std::left << std::setw(37) << "(2) �������� ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(3) ������� ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(4) �����" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(5) ��������� � �������������� ������" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		EditSessionPage(NumberOfRecord, NumberOfSession);
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		if (db.DataList[NumberOfRecord - 1].Sessions.sessions[NumberOfSession - 1].GetcountSubjects() < 10) {
			AddRecordSessionPage(NumberOfRecord, NumberOfSession);
		}
		else {
			EditSessionPage(NumberOfRecord, NumberOfSession);
		}
		
		break;

	case 2:
		cslTools.Clear();
		ChangeRecordSessionPage(NumberOfRecord, NumberOfSession);
		break;

	case 3:
		cslTools.Clear();
		DeleteRecordSessionPage(NumberOfRecord, NumberOfSession);
		break;

	case 4:
		cslTools.Clear();
		ChoiceEditSessionPage(NumberOfRecord);
		break;

	case 5:
		cslTools.Clear();
		ChoiceEditActionSessionPage(NumberOfRecord);
		break;

	default:
		IncorrectInput();
		EditSessionPage(NumberOfRecord, NumberOfSession);
		break;
	}
}

void AConsoleInterface::AddRecordSessionPage(int NumberOfRecord, int NumberOfSession)
{
	std::string InputSubject{};
	std::string InputGrade{};
	Data tempData = db.DataList[NumberOfRecord - 1];
	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);
		std::cout << "___________________���������� ������ � ������ " << NumberOfSession << "_________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> InputSubject;

		if (InputSubject == "-back") {
			EditSessionPage(NumberOfRecord, NumberOfSession);
		}
	} while (!valIn.isSubject(InputSubject));

	

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);
		std::cout << "___________________���������� ������ � ������ " << NumberOfSession << "_________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������ >>> ";
		std::cin >> InputGrade;

		if (InputGrade == "-back") {
			EditSessionPage(NumberOfRecord, NumberOfSession);
		}
	} while (!valIn.isGrade(InputGrade));

	tempData.Sessions.sessions[NumberOfSession - 1].AddSubjGrades(InputSubject, InputGrade);

	db.ChangedData(tempData, NumberOfRecord);

	cslTools.Clear();
	std::cout << "________________________���������� ������ � ������______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� ........" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "________________________���������� ������ � ������______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� >>>......" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "________________________���������� ������ � ������______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� >>>>>>..." << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "________________________���������� ������ � ������______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "������ ������� ���������. ������� �� �������� �������������� >>>>>>>>>" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	db.SaveFile();

	EditSessionPage(NumberOfRecord, NumberOfSession);
}

void AConsoleInterface::ChangeRecordSessionPage(int NumberOfRecord, int NumberOfSession)
{
	std::string Input{};
	Data tempData = db.DataList[NumberOfRecord - 1];

	if (tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() == 0) {
		cslTools.Clear();
		std::cout << "________________________��������� ������ ������ " << NumberOfSession << "______________________" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(69) << "������ ������ �����������. ������� �� �������� ��������������" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		Sleep(2000);
		EditSessionPage(NumberOfRecord, NumberOfSession);
	}

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);

		std::cout << "________��������� ������ ������ " << NumberOfSession << "_____" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) �����" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditSessionPage(NumberOfRecord, NumberOfSession);
		}

	} while (!(valIn.isNumberOfRecordSession(Input, tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects())));

	ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, std::atoi(Input.c_str()));
}

void AConsoleInterface::ChoiceChangeRecordSessionPage(int NumberOfRecord, int NumberOfSession, int NumberOfRecordSession)
{
	cslTools.Clear();
	ShowSession(NumberOfRecord, NumberOfSession);

	std::cout << "____________��������� ������ ������___________" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(1) �������� �������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(2) �������� ������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(3) �����" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(4) ��������� � �������������� ������" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		IncorrectInput();
		ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
	}

	switch (std::atoi(action.c_str())) {
	case 1:
		cslTools.Clear();
		ChangeSubjectRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
		break;

	case 2:
		cslTools.Clear();
		ChangeGradeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
		break;

	case 3:
		cslTools.Clear();
		ChangeRecordSessionPage(NumberOfRecord, NumberOfSession);
		break;

	case 4:
		cslTools.Clear();
		EditSessionPage(NumberOfRecord, NumberOfSession);
		break;

	default:
		IncorrectInput();
		ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
		break;
	}
}

void AConsoleInterface::ChangeSubjectRecordSessionPage(int NumberOfRecord, int NumberOfSession, int NumberOfRecordSession)
{
	std::string Input{};
	Data tempData = db.DataList[NumberOfRecord - 1];

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);
		std::cout << "___________________��������� ������ � ������ " << NumberOfSession << "__________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "�������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������� >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
		}
	} while (!valIn.isSubject(Input));

	tempData.Sessions.sessions[NumberOfSession - 1].subjGrades[NumberOfRecordSession - 1].SetSubject(Input);

	db.ChangedData(tempData, NumberOfRecord);

	db.SaveFile();

	ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
}

void AConsoleInterface::ChangeGradeRecordSessionPage(int NumberOfRecord, int NumberOfSession, int NumberOfRecordSession)
{
	std::string Input{};
	Data tempData = db.DataList[NumberOfRecord - 1];

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);
		std::cout << "___________________��������� ������ � ������ " << NumberOfSession << "__________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) ����� (� ������ ������ �������� ������ �� ����������)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "������" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "������� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
		}
	} while (!valIn.isGrade(Input));

	tempData.Sessions.sessions[NumberOfSession - 1].subjGrades[NumberOfRecordSession - 1].SetGrade(Input);

	db.ChangedData(tempData, NumberOfRecord);

	db.SaveFile();

	ChoiceChangeRecordSessionPage(NumberOfRecord, NumberOfSession, NumberOfRecordSession);
}

void AConsoleInterface::DeleteRecordSessionPage(int NumberOfRecord, int NumberOfSession)
{
	std::string Input{};
	Data tempData = db.DataList[NumberOfRecord - 1];

	if (tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() == 0) {
		cslTools.Clear();
		std::cout << "_________________________�������� ������ ������ " << NumberOfSession << "______________________" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(69) << "������ ������ �����������. ������� �� �������� ��������������" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		Sleep(2000);
		EditRecordPage();
	}

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);

		std::cout << "_________�������� ������ ������ " << NumberOfSession << "_______" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) �����" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}

	} while (!(valIn.isNumberOfRecordSession(Input, tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects()) && AgreeActionPage(Input)));

	tempData.Sessions.sessions[NumberOfSession - 1].DeleteSubjGrades(std::atoi(Input.c_str()) - 1);

	db.ChangedData(tempData, NumberOfRecord);

	cslTools.Clear();
	std::cout << "_________________________�������� ������ ������________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� ........." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_________________________�������� ������ ������________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� >>>......" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_________________________�������� ������ ������________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� >>>>>>..." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_________________________�������� ������ ������________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "������ ������� �������. ������� �� �������� �������������� >>>>>>>>>" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	db.SaveFile();

	EditSessionPage(NumberOfRecord, NumberOfSession);
}



void AConsoleInterface::AddSessionPage(int NumberOfRecord)
{
	std::string Input{};

	do {
		cslTools.Clear();

		std::cout << "_____________________���������� ������______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|������ ����������� ������:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) �����" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceEditActionSessionPage(NumberOfRecord);
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	if (!db.DataList[NumberOfRecord - 1].Sessions.isSession(std::atoi(Input.c_str()) - 1)) {
		cslTools.Clear();
		std::cout << "_______________________���������� ������______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "������ ������� ���������." << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;

		Sleep(2000);

		

		Data tempData = db.DataList[NumberOfRecord - 1];
		tempData.Sessions.AddSession(std::atoi(Input.c_str()) - 1);
		db.ChangedData(tempData, NumberOfRecord);

		db.SaveFile();

		ChoiceEditActionSessionPage(NumberOfRecord);
	}
	else {
		cslTools.Clear();
		std::cout << "_______________________���������� ������______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "������ ��� ���������. ������� ������ �����." << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Sleep(2000);

		db.SaveFile();

		AddSessionPage(NumberOfRecord);
	}
}

void AConsoleInterface::DeleteSessionPage(int NumberOfRecord)
{
	std::string Input{};

	do {
		cslTools.Clear();

		std::cout << "______________________�������� ������_______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "�������� ����� ������" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|������ ����������� ������:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) �����" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� ������ >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceEditActionSessionPage(NumberOfRecord);
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	if (db.DataList[NumberOfRecord - 1].Sessions.isSession(std::atoi(Input.c_str()) - 1)) {
		cslTools.Clear();
		std::cout << "________________________�������� ������_______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "������ ������� �������." << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;

		Sleep(2000);

		Data tempData = db.DataList[NumberOfRecord - 1];
		tempData.Sessions.DeleteSession(std::atoi(Input.c_str()) - 1);
		db.ChangedData(tempData, NumberOfRecord);

		db.SaveFile();

		ChoiceEditActionSessionPage(NumberOfRecord);
	}
	else {
		cslTools.Clear();
		std::cout << "________________________�������� ������_______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "������ ��� �������. ������� ������ �����." << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Sleep(2000);

		db.SaveFile();

		DeleteSessionPage(NumberOfRecord);
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
			EditRecordPage();
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
	EditRecordPage();
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
			EditRecordPage();
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
		IncorrectInput();
		EditRecordPage();
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
		IncorrectInput();
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
		Sleep(2000);
		EditRecordPage();
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
			EditRecordPage();
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
	EditRecordPage();
}

bool AConsoleInterface::AgreeActionPage(std::string Input)
{
	std::string Answer{};
	do {
		cslTools.Clear();
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "�� �������, ��� ������ ������� ������ ? " << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "����� � �������: Y - �� / N - ���" << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "������� ����� >>> ";
		std::cin >> Input;

	} while (!(Input == "Y" || Input == "N"));

	return valIn.isAgree(Input);
}

void AConsoleInterface::IncorrectInput()
{
	cslTools.Clear();
	std::cout << "_________________________����� ��������_________________________" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "����������� ������ ����� ��������!" << "|" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "���������� ��� ���..." << "|" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Sleep(3000);
}

