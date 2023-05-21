#include "ACryptoTools.h"
#pragma once

ACryptoTools::ACryptoTools()
{
	this->szPassword = "Rusakov is the best";
	dwLength = (DWORD)this->szPassword.size();



	if (!CryptAcquireContext(&hProv, NULL, NULL,
		PROV_RSA_FULL, 0))
	{
		std::cout << "CryptAcquireContext" << std::endl;
	}
	else
	{
		std::cout << "Cryptographic provider initialized" << std::endl;
	}

	if (CryptCreateHash(
		hProv,
		CALG_MD5,
		0,
		0,
		&hHash))
	{
		std::cout << "Hash is created" << std::endl;
	}

	if (CryptHashData(
		hHash,
		(BYTE*)this->szPassword.c_str(),
		dwLength,
		0))
	{
		std::cout << "Password is created" << std::endl;
	}

	if (CryptDeriveKey(
		hProv,
		CALG_RC4,
		hHash,
		CRYPT_EXPORTABLE,
		&hSessionKey))
	{
		std::cout << "KeySession is created" << std::endl;
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
	CryptDestroyKey(hSessionKey);
	CryptDestroyHash(hHash);
	CryptReleaseContext(hProv, 0);

}


