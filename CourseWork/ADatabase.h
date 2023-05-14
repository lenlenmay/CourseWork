#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "AList.h"
#include "AConsoleTools.h"
#include "Data.h"
#include <regex>
#include <locale>
#include <iomanip>
#include "AList.h"
#include <algorithm>
#include "ValidationInput.h"
#include <sstream>
#include "ACryptoTools.h"

class ADatabase {

	std::string PathToFile;
	//bool bisUTF8;
	AConsoleTools cslTools;
	ACryptoTools crtTools;
public:

	List<Data>DataList;

	bool Open(std::string PathToFile);
	bool Create(std::string PathToFile);
	void ReadFromFile();
	void ParserFromFile(std::string str);
	void DeleteContentFromFile(std::string str);
	std::string FormContentForFile(Data &data);
	std::string FormSessions(Data &data);
	std::string FormSubjGrades(Data& data, int index);
	void InputInFile(std::string str);
	void SaveFile();
	void AddRecord(Data& data);
	void DeleteRecord(int index);
	void ChangedData(Data& data, int index);
};