#pragma once
#include "AConsoleApp.h"

AConsoleApp::AConsoleApp()
{
	AConsoleApp::Init();
}

void AConsoleApp::Init()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	AConsoleInterface();
}
