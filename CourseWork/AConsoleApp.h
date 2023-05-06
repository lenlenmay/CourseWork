#pragma once
#include <Windows.h>
#include "IConsoleApp.h"
#include "AConsoleInterface.h"

class AConsoleApp : IConsoleApp {
public:
	AConsoleApp();
private:
	void Init() override;
};