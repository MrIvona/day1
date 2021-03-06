// app.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "../lib/public.h"
#include "../dll2/public.h"
#include <Windows.h>



int main()
{
	std::cout<<"Static library:"<< get_value(4) << std::endl;
	std::cout <<"Dynamic library with implib:"<< get_value(4)<< std::endl;
	typedef  double(*LPGETVALUE)(int x);
	HMODULE dll = LoadLibraryA("dynamic_library.dll");
	if(dll != NULL)
	{
		LPGETVALUE func = (LPGETVALUE)GetProcAddress(dll, "get_value");
		if(func!=NULL)
		{
			double resultFunc = func(8);
			std::cout << "Dynamic_library:" << resultFunc << std::endl;

		}else
		{
			std::cout << "Function wasn't found";
		}
		bool FreeResult = FreeLibrary(dll);
		return FreeResult;
	}
	else
	{
		std::cout << "Dll wasn't found";
	}
    return 0;
}

