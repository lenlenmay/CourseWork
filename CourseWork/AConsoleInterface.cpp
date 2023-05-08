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
	std::cout << "________Начальная страница________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) Открыть существующую БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) Создать новую БД" << "|" << std::endl;
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
		std::cout << "Некорректно введен номер действия!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
		Sleep(3000);
		StartPage();
	}
	
	
		
	switch (std::atoi(action.c_str())) {
	case 1:
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
		db.Open(PathToFile);
		break;

	case 2:
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
		db.Create(PathToFile);
		break;
	default:
		cslTools.Clear();
		std::cout << "Такого номера действия нет!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
	std::cout << "_________Главная страница_________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) Режим просмотра БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) Режим редактирования БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) Назад" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::string action{};
	std::cout << ">>> ";
	std::cin >> action;



	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "Некорректно введен номер действия!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		std::cout << "Такого номера действия нет!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
		Sleep(3000);
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
	std::cout << "|" << std::left << std::setw(32) << "(2) Сортировка группы по оценкам" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(3) Назад" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "Некорректно введен номер действия!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		std::cout << "Такого номера действия нет!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
		Sleep(3000);
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
			<< std::left << std::setw(25) << "Кафедра" << " | "
			<< std::left << std::setw(6) << "Номер" << " | "
			<< std::left << std::setw(17) << "Номер" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "в университет" << " | "
			<< std::left << std::setw(15) << "(институт)" << " | "
			<< std::left << std::setw(25) << " " << " | "
			<< std::left << std::setw(6) << "группы" << " | "
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
				<< std::left << std::setw(25) << data.GetDepartment() << " | "
				<< std::left << std::setw(6) << data.GetGroup() << " | "
				<< std::left << std::setw(17) << data.GetNumberRecordBook() << " |" << std::endl;
			std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	}
}

void AConsoleInterface::ShowRecords()
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
			<< std::left << std::setw(25) << "Кафедра" << " | "
			<< std::left << std::setw(6) << "Номер" << " | "
			<< std::left << std::setw(17) << "Номер" << " |" << std::endl;
		std::cout << "| " << " " << " | " << std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(15) << " " << " | "
			<< std::left << std::setw(7) << " " << " | "
			<< std::left << std::setw(13) << " " << " | "
			<< std::left << std::setw(15) << "в университет" << " | "
			<< std::left << std::setw(15) << "(институт)" << " | "
			<< std::left << std::setw(25) << " " << " | "
			<< std::left << std::setw(6) << "группы" << " | "
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
	std::cout << "|" << std::left << std::setw(12) << "(1) Назад" << "|" << std::endl;
	std::cout << "--------------" << std::endl;

	std::cout << ">>> ";
	std::string action{};
	std::cin >> action;

	if (!cslTools.ValidationOfInput(action))
	{
		cslTools.Clear();
		std::cout << "Некорректно введен номер действия!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		std::cout << "Такого номера действия нет!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		cslTools.Clear();
		std::cout << "Некорректно введен номер действия!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		std::cout << "Такого номера действия нет!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите фамилию >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
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
			EditModePage();
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
			EditModePage();
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
			EditModePage();
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите месяц (номер) >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год >>> ";
		std::cin >> Input;

		if (Input == "-back") {
			EditModePage();
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
			EditModePage();
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
			EditModePage();
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
			EditModePage();
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
			EditModePage();
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
			EditModePage();
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
	EditModePage();
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
			EditModePage();
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
		cslTools.Clear();
		std::cout << "Некорректно введен номер действия!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		std::cout << "Такого номера действия нет!" << std::endl;
		std::cout << "Попробуйте ещё раз..." << std::endl;
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
		Sleep(2);
		EditModePage();
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
			EditModePage();
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
	EditModePage();
}

bool AConsoleInterface::AgreeActionPage(std::string Input)
{
	std::string Answer{};
	do {
		cslTools.Clear();
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "Вы уверены, что хотите удалить запись под номером ? " << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "| " << std::left << std::setw(56) << "Ответ в формате: Y - да / N - нет" << " |" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Введите ответ >>> ";
		std::cin >> Input;

	} while (!(Input == "Y" || Input == "N"));

	return valIn.isAgree(Input);
}

