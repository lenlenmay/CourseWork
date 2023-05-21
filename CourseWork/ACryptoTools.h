#pragma once
#include <iostream> 
#include <windows.h> 
#include <wincrypt.h> 
#include <stdio.h> 


class ACryptoTools {
private:
	DWORD dwLength;
	HCRYPTHASH hHash;
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;
	std::string szPassword;
	

public:
	ACryptoTools();
	
	std::string EncryptionOfString(const std::string &str);
	std::string DecryptionOfString(const std::string& str);

	~ACryptoTools();
};