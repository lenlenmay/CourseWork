#pragma once
#pragma comment(lib, "crypt32.lib")
#include <windows.h>
#include <Wincrypt.h>
  
#define ENCRYPT_ALGORITHM (CALG_RC4)
#define KEY_LENGTH 512

class ACryptoTools {
private:
	HCRYPTPROV hCryptProv {};
	HCRYPTKEY hKey {};
	HCRYPTHASH hHash {};
	CHAR szPassword[KEY_LENGTH] {};
	DWORD dwLength {};

public:
	ACryptoTools();
	~ACryptoTools();
};