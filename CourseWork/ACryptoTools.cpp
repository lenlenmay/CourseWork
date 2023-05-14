#include "ACryptoTools.h"
#pragma once

ACryptoTools::ACryptoTools()
{
	if (!CryptAcquireContext(&hProv, NULL, NULL,
		PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
	{
		std::cout << "CryptAcquireContext" << std::endl;
	}
	else
	{
		std::cout << "Cryptographic provider initialized" << std::endl;
	}

	if (!CryptGenKey(hProv, CALG_RC4, CRYPT_EXPORTABLE, &hSessionKey)) {
		std::cout << "CryptGenKey" << std::endl;
		return;
	}
	else
	{
	std::cout << "Session key generated" << std::endl;
	}
}

std::string ACryptoTools::EncryptionOfString(const std::string& str)
{
	char* encryptstr = const_cast<char*>(str.c_str());
	DWORD count = strlen(encryptstr);

	if (!CryptEncrypt(this->hSessionKey, 0, true, 0, (BYTE*)encryptstr, &count, strlen(encryptstr)))
	{
		return std::string("");
	}
	else
	{
		return std::string(encryptstr);
	}
}

std::string ACryptoTools::DecryptionOfString(const std::string& str)
{
	char* decryptstr = const_cast<char*>(str.c_str());
	DWORD count = strlen(decryptstr);

	if (!CryptDecrypt(this->hSessionKey, 0, true, 0, (BYTE*)decryptstr, &count))
	{
		return std::string("");
	}
	else
	{
		return std::string(decryptstr);
	}
}

ACryptoTools::~ACryptoTools()
{

}


