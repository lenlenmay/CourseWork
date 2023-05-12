#pragma once
#include "AConsoleTools.h"


void AConsoleTools::Clear() {
	std::cout << "\x1B[2J\x1B[H";
}

bool AConsoleTools::ValidationOfInput(std::string str)
{
	std::regex regular("[1-9]");
	if (std::regex_match(str.c_str(), regular) && str.size() == 1)
		return true;
	else
		return false;	
}

std::string AConsoleTools::utf8_to_string(const char* utf8str, const std::locale& loc)
{
	// UTF-8 to wstring
	std::wstring_convert<std::codecvt_utf8<wchar_t>> wconv;
	std::wstring wstr = wconv.from_bytes(utf8str);

	// wstring to string
	std::vector<char> buf(wstr.size());
	std::use_facet<std::ctype<wchar_t>>(loc).narrow(wstr.data(), wstr.data() + wstr.size(), '?', buf.data());
	return std::string(buf.data(), buf.size());
}

std::string AConsoleTools::ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;
	return converterX.to_bytes(wstr);
	return std::string();
}

/*bool AConsoleTools::is_utf8(std::string PathToFile)
{

    std::ifstream File(PathToFile, std::ios::binary); 

    if (!File) {
        return false;
    }
	else{
		unsigned char buffer[4];
		File.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
		if (File.gcount() < 2) {
			return false;
		}
		if (buffer[0] == 0xEF && buffer[1] == 0xBB && buffer[2] == 0xBF) {
			return true;
		}
		else {
			return false;
		}
	}
}*/

