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
#include <vector>
#include "AList.h"
#include "ValidationInput.h"

class ADatabase {

	std::string PathToFile;
	//bool bisUTF8;
	AConsoleTools cslTools;
public:

	//List<Data>DataList;
	List<Data>DataList;
	//std::vector<Data>DataList;// поменять на список

	void Open(std::string PathToFile);
	void Create(std::string PathToFile);
	void ReadFromFile();
	void ParserFromFile(std::string str);
	void DeleteContentFromFile(std::string str);
	std::string FormContentForFile(Data data);
	void InputInFile(std::string str);
	void SaveFile();
	void AddRecord();
};