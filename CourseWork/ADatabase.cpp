#pragma once
#include "ADatabase.h"


bool ADatabase::Open(std::string PathToFile)
{
	std::ifstream File(PathToFile);
	if (!File) {
		std::cout << "----------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(32) << "Ôàéë íå íàéäåí!" << "|" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		Sleep(1500);
		return false;
	}
	else {
		std::cout << "----------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(32) << "Ôàéë íàéäåí!" << "|" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		Sleep(1500);
		this->PathToFile = PathToFile;
		return true;
		//this->bisUTF8 = cslTool.is_utf8(this->PathToFile);
	}
}

bool ADatabase::Create(std::string PathToFile)
{
	std::ofstream File(PathToFile);
	if (!File) {
		std::cout << "----------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(32) << "Ôàéë íå ñîçäàí!" << "|" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		Sleep(1500);
		return false;
	}
	else {
		std::cout << "----------------------------------" << std::endl;
		std::cout << "|" << std::left << std::setw(32) << "Ôàéë ñîçäàí!" << "|" << std::endl;
		std::cout << "----------------------------------" << std::endl;
		Sleep(1500);
		this->PathToFile = PathToFile;
		return true;
		//this->bisUTF8 = cslTool.is_utf8(this->PathToFile);
	}
}

void ADatabase::ReadFromFile()
{
	std::ifstream File(this->PathToFile);
	for (std::string line; std::getline(File, line); ) {
		//line = cslTools.utf8_to_string(line.c_str(), std::locale(".1251"));
		ParserFromFile(line); //ParserFromFile(crtTools.DecryptionOfString(line));
	}
		
}

void ADatabase::ParserFromFile(std::string str)
{
	if (str == "") {
		return;
	}
	Data tempData;
	std::string strData = std::string(str, str.find('{'), str.find('}') + 1);
	std::regex regular(
		"([{])([a-zA-Zà-ÿ¸À-ß¨]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨]{3,7})(;)"
		"([0-9]{1,2})(;)([0-9]{1,2})(;)([0-9]{4,4})(;)"
		"([0-9]{4})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨_]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨_]{2,20})(;)"
		"([a-zA-Zà-ÿ¸À-ß¨0-9]{1,6})(;)"
		"([0-9]{1,4})([}])");

	std::regex regularforSubjGrades("([a-zA-Zà-ÿ¸À-ß¨_]{2,20})([:])([2-5]{1})");

	std::cmatch result;
	if (std::regex_match(strData.c_str(), result, regular)) {
		tempData = Data(result[2], result[4], result[6], result[8], result[10], result[12], result[14], result[16], result[18], result[20], result[22], result[24]);

		std::string strDataSessions(str, str.find('|'), str.rfind('|'));
		strDataSessions = string(strDataSessions, 1, strDataSessions.length() - 2);

		int index{};
		int countSessions{};
		int countSubjGrades{};

		if (strDataSessions != "-") {
			countSessions = std::count(strDataSessions.begin(), strDataSessions.end(), '{');
			std::istringstream strSessions(strDataSessions);


			for (std::string strDataSession; std::getline(strSessions, strDataSession, '@');) {

				index = std::atoi(std::string(1, strDataSession[0]).c_str());
				tempData.Sessions.AddSession(index);

				if (strDataSession.at(strDataSession.length() - 1) != '^') {
					countSubjGrades = std::count(strDataSession.begin(), strDataSession.end(), ':');
					strDataSession = std::string(strDataSession, 2, strDataSession.length() - 1);

					std::istringstream strSession(strDataSession);

					for (std::string strDataSubjGrades; std::getline(strSession, strDataSubjGrades, ';');) {
						std::cmatch resultSubjGrades;
						if (std::regex_match(strDataSubjGrades.c_str(), resultSubjGrades, regularforSubjGrades)) {
							tempData.Sessions.sessions[index].AddSubjGrades(resultSubjGrades[1], resultSubjGrades[3]);
						}
					}
				}
			}
		}
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
	std::string Sessions = FormSessions(data);
	return std::string("{" + data.GetSurname() + ";" + data.GetName() + ";" + data.GetPatrinymic() + ";" + data.GetGender() + ";"
		+ data.GetDay() + ";" + data.GetMonth() + ";" + data.GetYear() + ";"
		+ data.GetYearAddtoUniversity() + ";" + data.GetFaculty() + ";" + data.GetDepartment() + ";" + data.GetGroup() + ";" + data.GetNumberRecordBook() + "}"
		+ "|" + Sessions + "|");
}

std::string ADatabase::FormSessions(Data& data)
{
	std::string resultSessions{};
	std::string Sessions[9];
	if (data.Sessions.GetcountSessions() != 0) {
		for (int i = 0; i < 9; i++) {
			if (data.Sessions.sessions[i].GetisAdded()) {
				Sessions[i] += std::to_string(i) + "#" + FormSubjGrades(data, i) + "@";
				resultSessions += Sessions[i];
			}	
		}
		
		return std::string(resultSessions, 0, resultSessions.rfind('@'));
	}
	else {
		resultSessions = "-";
	}
	return resultSessions;
}

std::string ADatabase::FormSubjGrades(Data& data, int index)
{
	std::string resultsubjGrades{};
	std::string subjGrades[9];
	if (data.Sessions.sessions[index].GetcountSubjects() != 0) {
		for (int i = 0; i < data.Sessions.sessions[index].GetcountSubjects(); i++)
		{
			subjGrades[i] = data.Sessions.sessions[index].subjGrades[i].GetSubject() + ":" + data.Sessions.sessions[index].subjGrades[i].GetGrade() + ";";
			resultsubjGrades += subjGrades[i];
		}
		resultsubjGrades = std::string(resultsubjGrades, 0, resultsubjGrades.rfind(';'));
	}
	else
	{
		resultsubjGrades = "^";
	}
	return resultsubjGrades;
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
		InputInFile(FormContentForFile(data)); //InputInFile(crtTools.EncryptionOfString(FormContentForFile(data)));
	}
}

void ADatabase::AddRecord(Data &data)
{
	DataList.AddEnd(data);
}

void ADatabase::DeleteRecord(int index)
{
	DataList.Del(index);
}

void ADatabase::ChangedData(Data& data, int index)
{
	DataList.UpdateData(data, index - 1);
}



