#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <codecvt>
#include <locale>

class AConsoleTools {

public:
	void Clear();
	bool ValidationOfInput(std::string str);
	std::string utf8_to_string(const char* utf8str, const std::locale& loc);
	std::string ws2s(const std::wstring& wstr);
	//bool is_utf8(std::string PathToFile);
};