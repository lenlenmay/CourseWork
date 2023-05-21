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
	std::cout << "________Начальная страница________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) Открыть существующую БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) Создать новую БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) Выйти из программы" << "|" << std::endl;
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
			std::cout << "_________________Открытие существующей БД_________________" << std::endl;
			std::cout << "|" << std::left << std::setw(56) << "Введите путь и название файла в формате:" << "|" << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "|" << std::left << std::setw(56) << "<название диска>:\\<название папки>\\<название файла.txt>" << "|" << std::endl;
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
			std::cout << "____________________Создание новой БД_____________________" << std::endl;
			std::cout << "|" << std::left << std::setw(56) << "Введите путь и название файла в формате:" << "|" << std::endl;
			std::cout << "----------------------------------------------------------" << std::endl;
			std::cout << "|" << std::left << std::setw(56) << "<название диска>:\\<название папки>\\<название файла.txt>" << "|" << std::endl;
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
	std::cout << "_________Главная страница_________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) Режим просмотра БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) Режим редактирования БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) Назад" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(4) Выйти из программы" << "|" << std::endl;
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

	std::cout << "_________Режим просмотра__________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) Посмотреть записи БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) Посмотреть сессии студента" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) Сортировка группы по оценкам" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(4) Назад" << "|" << std::endl;
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
	std::cout << "________________________________________________________________________________База данных_______________________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(175) << "Записи отсутствуют" << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "| " << "№" << " | " << std::left << std::setw(15) << "Фамилия" << " | "
			<< std::left << std::setw(15) << "Имя" << " | "
			<< std::left << std::setw(15) << "Отчество" << " | "
			<< std::left << std::setw(7) << "Пол" << " | "
			<< std::left << std::setw(13) << "Дата рождения" << " | "
			<< std::left << std::setw(15) << "Год поступления" << " | "
			<< std::left << std::setw(15) << "Факультет" << " | "
			<< std::left << std::setw(20) << "Кафедра" << " | "
			<< std::left << std::setw(11) << "Номер" << " | "
			<< std::left << std::setw(17) << "Номер" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "в университет" << " | "
			<< std::left << std::setw(15) << "(институт)" << " | "
			<< std::left << std::setw(20) << " " << " | "
			<< std::left << std::setw(11) << "группы" << " | "
			<< std::left << std::setw(17) << "в зачётной книжке" << " |" << std::endl;
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
	std::cout << "________________________________________________________________________________База данных_______________________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(174) << "Записи отсутствуют" << " |" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "| " << "№" << " | " << std::left << std::setw(15) << "Фамилия" << " | "
			<< std::left << std::setw(15) << "Имя" << " | "
			<< std::left << std::setw(15) << "Отчество" << " | "
			<< std::left << std::setw(7) << "Пол" << " | "
			<< std::left << std::setw(13) << "Дата рождения" << " | "
			<< std::left << std::setw(15) << "Год поступления" << " | "
			<< std::left << std::setw(15) << "Факультет" << " | "
			<< std::left << std::setw(20) << "Кафедра" << " | "
			<< std::left << std::setw(11) << "Номер" << " | "
			<< std::left << std::setw(17) << "Номер" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "в университет" << " | "
			<< std::left << std::setw(15) << "(институт)" << " | "
			<< std::left << std::setw(20) << " " << " | "
			<< std::left << std::setw(11) << "группы" << " | "
			<< std::left << std::setw(17) << "в зачётной книжке" << " |" << std::endl;
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
	std::cout << "|" << std::left << std::setw(12) << "(1) Назад" << "|" << std::endl;
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

		std::cout << "_____________Выбор студента для просмотра сессии___________" << std::endl;
		std::cout << "|" << std::left << std::setw(57) << "Выберете номер записи студента" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(57) << "(-back) Назад" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "Введите номер записи студента >>> ";
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

		std::cout << "_______________________Выбор сессии_________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "Выберете номер сессии" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|Список добавленных сессий:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) Назад" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер сессии >>> ";
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
		std::cout << "__________________________Выбор сессии________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "Такой сессии нет. Добавьте её в режиме редактирования" << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Sleep(2000);
		ChoiceViewSessionPage(NumberOfRecord);
	}
	
}

void AConsoleInterface::ViewSessionPage(int NumberOfRecord, int NumberOfSession)
{
	ShowSession(NumberOfRecord, NumberOfSession);

	std::cout << std::endl << "--------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(48) << "(1) Назад" << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(48) << "(2) Вернуться к странице выбора студента" << "|" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(48) << "(3) Вернуться к странице выбора просмотра" << "|" << std::endl;
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
	std::cout << "__________________Сессия " << NumberOfSession << "_________________" << std::endl;
	if (tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects() == 0) {
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(39) << "Записи в сессии отсутствуют" << " |" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;
	}
	else {
		std::cout << "-------------------------------------------" << std::endl;
		std::cout << "| № | " << std::left << std::setw(26) << "Предмет" << " | " << std::left << std::setw(6) << "Оценка" << " |" << std::endl;
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

		std::cout << "_______________________Выбор сессии_________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "Выберете номер сессии" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) Назад" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер сессии >>> ";
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
	std::cout << "____________________________________________________________________________База данных_______________________________________________________________________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	if (db.DataList.Count() == 0) {
		std::cout << "| " << std::left << std::setw(170) << "Записи отсутствуют" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
	else {
		std::cout << "| " << std::left << std::setw(15) << "Фамилия" << " | "
			<< std::left << std::setw(15) << "Имя" << " | "
			<< std::left << std::setw(15) << "Отчество" << " | "
			<< std::left << std::setw(7) << "Пол" << " | "
			<< std::left << std::setw(13) << "Дата рождения" << " | "
			<< std::left << std::setw(15) << "Год поступления" << " | "
			<< std::left << std::setw(15) << "Факультет" << " | "
			<< std::left << std::setw(25) << "Кафедра" << " | "
			<< std::left << std::setw(6) << "Номер" << " | "
			<< std::left << std::setw(17) << "Номер" << " |" << std::endl;
		std::cout << "| " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "в университет" << " | "
			<< std::left << std::setw(15) << "(институт)" << " | "
			<< std::left << std::setw(25) << " " << " | "
			<< std::left << std::setw(6) << "группы" << " | "
			<< std::left << std::setw(17) << "в зачётной книжке" << " |" << std::endl;
		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(51) << "Отличники" << " |" << std::endl;
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
			std::cout << "| " << std::left << std::setw(51) << "Отличников нет" << " |" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}

		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(51) << "Хорошисты" << " |" << std::endl;
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
			std::cout << "| " << std::left << std::setw(51) << "Хорошистов нет" << " |" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}


		std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(51) << "Троечники" << " |" << std::endl;
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
			std::cout << "| " << std::left << std::setw(51) << "Троечников нет" << " |" << std::endl;
			std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
		}

	}

	std::cout << std::endl << "--------------" << std::endl;
	std::cout << "|" << std::left << std::setw(12) << "(1) Назад" << "|" << std::endl;
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

	std::cout << "__________Выбор редактирования_________" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(1) Редактировать записи БД" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(2) Редактировать данные сессий" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(3) Назад" << "|" << std::endl;
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

	std::cout << "_________Режим редактирования_________" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(1) Добавить запись" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(2) Изменить запись" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(3) Удалить запись" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(4) Назад" << "|" << std::endl;
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

		std::cout << "_____________Выбор студента для редактирования сессий___________" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Выберете номер записи студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) Назад" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер записи студента >>> ";
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
	std::cout << "_________Редактирование сессий_________" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(1) Редактировать сессию" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(2) Добавить сессию" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(3) Удалить сессию" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(4) Назад" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(5) Вернуться к выбору редактирования" << "|" << std::endl;
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

		std::cout << "_______________________Выбор сессии_________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "Выберете номер сессии" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|Список добавленных сессий:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) Назад" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер сессии >>> ";
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
		std::cout << "__________________________Выбор сессии________________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "Такой сессии нет. Добавьте её." << "|" << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		Sleep(2000);
		ChoiceEditSessionPage(NumberOfRecord);
	}
}

void AConsoleInterface::EditSessionPage(int NumberOfRecord, int NumberOfSession)
{
	cslTools.Clear();
	ShowSession(NumberOfRecord, NumberOfSession);
	std::cout << "________Редактирование сессии "<< NumberOfSession <<"________" << std::endl;
	if (db.DataList[NumberOfRecord - 1].Sessions.sessions[NumberOfSession - 1].GetcountSubjects() >= 9) {
		std::cout << "|" << std::left << std::setw(37) << "(X) Сессия заполнена" << "|" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
	}
	else {
		std::cout << "|" << std::left << std::setw(37) << "(1) Добавить запись" << "|" << std::endl;
		std::cout << "---------------------------------------" << std::endl;
	}
	
	std::cout << "|" << std::left << std::setw(37) << "(2) Изменить запись" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(3) Удалить запись" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(4) Назад" << "|" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(37) << "(5) Вернуться к редактированию сессий" << "|" << std::endl;
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
		std::cout << "___________________Добавление записи в сессию " << NumberOfSession << "_________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Предмет" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите предмет >>> ";
		std::cin >> InputSubject;

		if (InputSubject == "-back") {
			EditSessionPage(NumberOfRecord, NumberOfSession);
		}
	} while (!valIn.isSubject(InputSubject));

	

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);
		std::cout << "___________________Добавление записи в сессию " << NumberOfSession << "_________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Оценка" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите оценку >>> ";
		std::cin >> InputGrade;

		if (InputGrade == "-back") {
			EditSessionPage(NumberOfRecord, NumberOfSession);
		}
	} while (!valIn.isGrade(InputGrade));

	tempData.Sessions.sessions[NumberOfSession - 1].AddSubjGrades(InputSubject, InputGrade);

	db.ChangedData(tempData, NumberOfRecord);

	cslTools.Clear();
	std::cout << "________________________Добавление записи в сессию______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования ........" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "________________________Добавление записи в сессию______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования >>>......" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "________________________Добавление записи в сессию______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования >>>>>>..." << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "________________________Добавление записи в сессию______________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования >>>>>>>>>" << "|" << std::endl;
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
		std::cout << "________________________Изменение записи сессии " << NumberOfSession << "______________________" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(69) << "Записи сессии отсутствуют. Возврат на страницу редактирования" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		Sleep(2000);
		EditSessionPage(NumberOfRecord, NumberOfSession);
	}

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);

		std::cout << "________Изменение записи сессии " << NumberOfSession << "_____" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "Выберете номер записи" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Введите номер записи >>> ";
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

	std::cout << "____________Изменение записи сессии___________" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(1) Изменить предмет" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(2) Изменить оценку" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(3) Назад" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(4) Вернуться к редактированию сессии" << "|" << std::endl;
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
		std::cout << "___________________Изменение записи в сессии " << NumberOfSession << "__________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Предмет" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите предмет >>> ";
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
		std::cout << "___________________Изменение записи в сессии " << NumberOfSession << "__________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Оценка" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите оценку >>> ";
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
		std::cout << "_________________________Удаление записи сессии " << NumberOfSession << "______________________" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(69) << "Записи сессии отсутствуют. Возврат на страницу редактирования" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		Sleep(2000);
		EditRecordPage();
	}

	do {
		cslTools.Clear();
		ShowSession(NumberOfRecord, NumberOfSession);

		std::cout << "_________Удаление записи сессии " << NumberOfSession << "_______" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "Выберете номер записи" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Введите номер записи >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}

	} while (!(valIn.isNumberOfRecordSession(Input, tempData.Sessions.sessions[NumberOfSession - 1].GetcountSubjects()) && AgreeActionPage(Input)));

	tempData.Sessions.sessions[NumberOfSession - 1].DeleteSubjGrades(std::atoi(Input.c_str()) - 1);

	db.ChangedData(tempData, NumberOfRecord);

	cslTools.Clear();
	std::cout << "_________________________Удаление записи сессии________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования ........." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_________________________Удаление записи сессии________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования >>>......" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_________________________Удаление записи сессии________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования >>>>>>..." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_________________________Удаление записи сессии________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования >>>>>>>>>" << "|" << std::endl;
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

		std::cout << "_____________________Добавление сессии______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "Выберете номер сессии" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|Список добавленных сессий:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) Назад" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер сессии >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceEditActionSessionPage(NumberOfRecord);
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	if (!db.DataList[NumberOfRecord - 1].Sessions.isSession(std::atoi(Input.c_str()) - 1)) {
		cslTools.Clear();
		std::cout << "_______________________Добавление сессии______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "Сессия успешно добавлена." << "|" << std::endl;
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
		std::cout << "_______________________Добавление сессии______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "Сессия уже добавлена. Введите другой номер." << "|" << std::endl;
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

		std::cout << "______________________Удаление сессии_______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "Выберете номер сессии" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|Список добавленных сессий:" << std::left << std::setw(31) << IndexAddedSession(NumberOfRecord) << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(58) << "(-back) Назад" << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер сессии >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceEditActionSessionPage(NumberOfRecord);
		}

	} while (!(cslTools.ValidationOfInput(Input)));

	if (db.DataList[NumberOfRecord - 1].Sessions.isSession(std::atoi(Input.c_str()) - 1)) {
		cslTools.Clear();
		std::cout << "________________________Удаление сессии_______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "Сессия успешно удалена." << "|" << std::endl;
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
		std::cout << "________________________Удаление сессии_______________________" << std::endl;
		std::cout << "|" << std::left << std::setw(60) << "Сессия уже удалена. Введите другой номер." << "|" << std::endl;
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите фамилию >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetSurname(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите имя >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetName(Input);
	
	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите отчество >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetPatrinymic(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Пол" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите пол >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isGender(Input));

	tempData.SetGender(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите число >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите месяц (номер) >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYear(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год поступления в институт >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isYAndYUniversity(Input));

	tempData.SetYearAddtoUniversity(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите факультет (институт) >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetFaculty(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите кафедру >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isFDepartment(Input));

	tempData.SetDepartment(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер группы >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isGroup(Input));

	tempData.SetGroup(Input);

	do {
		cslTools.Clear();
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер зачётной книжки >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}
	} while (!valIn.isNumberRecordBook(Input));

	tempData.SetNumberRecordBook(Input);

	db.AddRecord(tempData);

	cslTools.Clear();
	std::cout << "____________________________Добавление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования ........" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Добавление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования >>>......" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Добавление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования >>>>>>..." << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Добавление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно добавлена. Возврат на страницу редактирования >>>>>>>>>" << "|" << std::endl;
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

		std::cout << "____________Изменение записи__________" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "Выберете номер записи" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Введите номер записи >>> ";
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

	std::cout << "_______________Изменение записи_______________" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(1) Изменить Ф.И.О" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(2) Изменить пол" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(3) Изменить дату рождения" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(4) Изменить год поступления в институт" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(5) Изменить институт (факультет)" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(6) Изменить кафедру" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(7) Изменить группу" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(8) Изменить номер зачётной книжки" << "|" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(44) << "(9) Назад" << "|" << std::endl;
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите фамилию >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetSurname(Input);

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите имя >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			ChoiceChangedElement(index);;
		}
	} while (!valIn.isNSPatrinymic(Input));

	tempData.SetName(Input);

	do {
		cslTools.Clear();
		ShowRecord(index);
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите отчество >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Пол" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите пол >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите число >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите месяц (номер) >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год поступления в институт >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите факультет (институт) >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите кафедру >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер группы >>> ";
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
		std::cout << "_______________________Изменение записи_________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер зачётной книжки >>> ";
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
	std::cout << "____________________________Изменение записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно изменена. Возврат на страницу редактирования ........" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Изменение записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно изменена. Возврат на страницу редактирования >>>......" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Изменение записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно изменена. Возврат на страницу редактирования >>>>>>..." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Изменение записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно изменена. Возврат на страницу редактирования >>>>>>>>>" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);
}




void AConsoleInterface::DeleteRecordPage()
{
	std::string Input{};

	if (db.DataList.Count() == 0) {
		cslTools.Clear();
		std::cout << "_____________________________Удаление записи___________________________" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(69) << "Записи отсутствуют. Возврат на страницу редактирования" << "|" << std::endl;
		std::cout << "-----------------------------------------------------------------------" << std::endl;
		Sleep(2000);
		EditRecordPage();
	}

	do {
		cslTools.Clear();
		ShowRecords();

		std::cout << "____________Удаление записи___________" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "Выберете номер записи" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад" << "|" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Введите номер записи >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditRecordPage();
		}

	} while (!(valIn.isNumberOfRecord(Input, db.DataList.Count()) && AgreeActionPage(Input)));


	db.DeleteRecord(std::atoi(Input.c_str()) - 1);

	cslTools.Clear();
	std::cout << "_____________________________Удаление записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования ........." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_____________________________Удаление записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования >>>......" << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_____________________________Удаление записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования >>>>>>..." << "|" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "_____________________________Удаление записи___________________________" << std::endl;
	std::cout << "-----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(69) << "Запись успешно удалена. Возврат на страницу редактирования >>>>>>>>>" << "|" << std::endl;
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
		std::cout << "| " << std::left << std::setw(56) << "Вы уверены, что хотите удалить запись ? " << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "Ответ в формате: Y - да / N - нет" << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите ответ >>> ";
		std::cin >> Input;

	} while (!(Input == "Y" || Input == "N"));

	return valIn.isAgree(Input);
}

void AConsoleInterface::IncorrectInput()
{
	cslTools.Clear();
	std::cout << "_________________________Выбор действия_________________________" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Некорректно введен номер действия!" << "|" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Попробуйте ещё раз..." << "|" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	Sleep(3000);
}

