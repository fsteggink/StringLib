// FS, 22-06-2005
// StringLib.cpp

#define DLLAPI_STRINGLIB __declspec(dllexport)

#include "StringLib_intern.h"


BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpvReserved)
{
	switch(dwReason)
	{
	case DLL_PROCESS_ATTACH:
		break;

	case DLL_PROCESS_DETACH:
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;
	}

	return TRUE;
}


// Convert wide character string to multi byte string
std::string DLLAPI_STRINGLIB wcstomb(const std::wstring &xsValue)
{
	int iRetVal;
	std::string sRetVal;
	char *sBuf = new char[xsValue.length() + 1];

	iRetVal = WideCharToMultiByte(
		CP_ACP, 0, xsValue.c_str(), -1, 
		sBuf, static_cast<int>(xsValue.length() + 1), 0, 0);
	sRetVal = std::string(sBuf);
	delete[] sBuf;

	return sRetVal;
}


// Convert multibyte character string to wide character
std::wstring DLLAPI_STRINGLIB mbstowc(const std::string &sValue)
{
	int iRetVal;
	std::wstring xsRetVal;
	wchar_t *xsBuf = new wchar_t[sValue.length() + 1];

	iRetVal = MultiByteToWideChar(
		CP_ACP, MB_PRECOMPOSED, sValue.c_str(), -1, 
		xsBuf, static_cast<int>(sValue.length() + 1));
	xsRetVal = std::wstring(xsBuf);
	delete[] xsBuf;

	return xsRetVal;
}
