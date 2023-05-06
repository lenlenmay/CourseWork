#pragma once
#include "ADatabase.h"


void ADatabase::Open(std::string PathToFile)
{
	std::ifstream File(PathToFile);
	if (!File) {
		std::cout << "Ôàéë íå íàéäåí!" << std::endl;
	}
	else {
		std::cout << "Ôàéë íàéäåí!" << std::endl;
		this->PathToFile = PathToFile;
		//this->bisUTF8 = cslTool.is_utf8(this->PathToFile);
	}
}

void ADatabase::Create(std::string PathToFile)
{
	std::ofstream File(PathToFile);
	if (!File) {
		std::cout << "Ôàéë íå ñîçäàí!" << std::endl;
	}
	else {
		std::cout << "Ôàéë ñîçäàí!" << std::endl;
		this->PathToFile = PathToFile;
		//this->bisUTF8 = cslTool.is_utf8(this->PathToFile);
	}
}

void ADatabase::ReadFromFile()
{
	std::ifstream File(this->PathToFile);
	for (std::string line; std::getline(File, line); ) {
		//line = cslTools.utf8_to_string(line.c_str(), std::locale(".1251"));
		ParserFromFile(line);
	}
		
}

void ADatabase::ParserFromFile(std::string str)
{
	std::regex regular(
		"([{])([a-zA-Zà-ÿ¸À-ß¨]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨]{3,10})(;)"
		"([0-9]{1,2})(;)([0-9]{1,2})(;)([0-9]{4,4})(;)"
		"([0-9]{4})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨_]{2,32})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨_]{2,32})(;)"
		"([0-9]{1,6})(;)"
		"([0-9]{1,4})([}])");

	std::cmatch result;
	if (std::regex_match(str.c_str(), result, regular)) {
		Data tempData = Data(result[2], result[4], result[6], result[8], result[10], result[12], result[14], result[16], result[18], result[20], result[22], result[24]);
		DataList.AddEnd(tempData);
	}	
}

void ADatabase::DeleteContentFromFile(std::string str)
{
	std::ofstream ofs;
	ofs.open(str, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

std::string ADatabase::FormContentForFile(Data &data)
{
	std::string tempStr{};
	return std::string("{" + data.GetSurname() + ";" + data.GetName() + ";" + data.GetPatrinymic() + ";" + data.GetGender() + ";"
		+ data.GetDay() + ";" + data.GetMonth() + ";" + data.GetYear() + ";"
		+ data.GetYearAddtoUniversity() + ";" + data.GetFaculty() + ";" + data.GetDepartment() + ";" + data.GetGroup() + ";" + data.GetNumberRecordBook() + "}");
}

void ADatabase::InputInFile(std::string str)
{
	std::ofstream File(this->PathToFile, std::ios_base::app);
	File << str << std::endl;
}

void ADatabase::SaveFile()
{
	DeleteContentFromFile(this->PathToFile);
	for (int i = 0; i < DataList.Count(); i++) {
		Data data = DataList[i];
		InputInFile(FormContentForFile(data));
	}
}

void ADatabase::AddRecord(Data &data)
{
	DataList.AddEnd(data);
}



