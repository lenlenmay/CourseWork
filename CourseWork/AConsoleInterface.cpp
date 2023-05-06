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
	std::cout << "________Начальная страница________" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(1) Открыть существующую БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(32) << "(2) Создать новую БД" << "|" << std::endl;
	std::cout << "----------------------------------" << std::endl;

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
		std::cout << "Открытие существующей БД" << std::endl 
			<< "Введите путь и название файла в формате:" << std::endl 
			<< "<название диска>:\\<название папки>\\<название файла.txt>" << std::endl;
		std::cout << ">>> ";
		std::cin >> PathToFile;
		db.Open(PathToFile);
		break;

	case 2:
		cslTools.Clear();
		std::cout << "Создание новой БД" << std::endl
			<< "Введите путь и название файла в формате:" << std::endl
			<< "<название диска>:\\<название папки>\\<название файла.txt>" << std::endl;
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

void AConsoleInterface::ShowRecords()
{
	std::cout << "______________________________________________________________________База данных_________________________________________________________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < db.DataList.Count(); i++) {// поменять на список
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
	cslTools.Clear();

	std::string Input{};
	Data tempData;
	do {
		ShowRecords();
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите фамилию >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите имя >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Ф.И.О" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите отчество >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Пол" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите пол >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите число >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите месяц (номер) >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Дата рождения" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите год поступления в институт >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите факультет (институт) >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите кафедру >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер группы >>> ";
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
		std::cout << "_______________________Добавление записи________________________" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(36) << "(-back) Назад (в случае выхода введённые данные не сохранятся)" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(62) << "Данные студента" << "|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "Введите номер зачётной книжки >>> ";
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

	EditModePage();
}

void AConsoleInterface::ChangedRecordPage()
{
	cslTools.Clear();
	ShowRecords();

	std::cout << "_________Изменение записи_________" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(1) Выберете номер записи" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(-back) Назад" << "|" << std::endl;
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

	std::cout << "____________Удаление записи___________" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "Выберете номер записи" << "|" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(36) << "(-back) Назад" << "|" << std::endl;
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
	std::cout << "____________________________Удаление записи___________________________" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно удалена. Возврат на страницу редактирования ........" << "|" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Удаление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно удалена. Возврат на страницу редактирования >>>......" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Удаление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно удалена. Возврат на страницу редактирования >>>>>>..." << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);

	cslTools.Clear();
	std::cout << "____________________________Удаление записи___________________________" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	std::cout << "|" << std::left << std::setw(62) << "Запись успешно удалена. Возврат на страницу редактирования >>>>>>>>>" << "|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;
	Sleep(500);
}


