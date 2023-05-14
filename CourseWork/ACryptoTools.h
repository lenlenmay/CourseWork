#pragma once
#include <iostream> 
#include <windows.h> 
#include <wincrypt.h> 
#include <stdio.h> 

class ACryptoTools {
private:
	DWORD dwIndex = 0;
	DWORD dwType;
	DWORD cbName ;
	LPTSTR pszName, x;
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey = 0;

public:
	ACryptoTools();
	
	std::string EncryptionOfString(const std::string &str);
	std::string DecryptionOfString(const std::string& str);

	~ACryptoTools();
};