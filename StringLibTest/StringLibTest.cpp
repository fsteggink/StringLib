// StringLibTest.cpp
// FS, 22-06-2005

#include "../../Inc/StringLib.h"
#include <iostream>
//#include <vector>
//#include <string>

#include <windows.h>


int main()
{
	/*
	std::vector<std::string> vecWords;
	std::vector<std::string>::iterator iterWord;
	std::vector<std::wstring> vecWords2;
	std::vector<std::wstring>::iterator iterWord2;

	//std::basic_string<int> testje, testje2;
	//testje2 = toUpper(testje);

	const std::string csWHITESPACE = " \t\r\n\f";
	const std::wstring cxsWHITESPACE = L" \t\r\n\f";


	//const std::string csTEST = " \tTekst  met \r\n  veel\t\twhite\nspace H\t ";
	const std::string csTEST = "Tekst bestaande uit een aantal woorden";
	//const std::string csTEST = "A                                                                                                                                A";
	/ *const std::string csFIND = "st";
	const std::string csREP = "s";* /
	//std::cout << "NWS 1: [" << StringLib<char>::normalizeWS(csTEST, csWHITESPACE) << "]" << std::endl;
	//std::cout << "NWS 2: [" << StringLib<char>::normalizeWS_new(csTEST, csWHITESPACE) << "]" << std::endl;

	const int ciCOUNT = 100000;
	std::string sTemp;
	LARGE_INTEGER llStart, llMid, llEnd, llFreq;


	QueryPerformanceCounter(&llStart);

	for(int i = 0; i < ciCOUNT; ++i)
	{
		//sTemp = StringLib<char>::normalizeWS(csTEST, csWHITESPACE);
		StringLib<char>::split(csTEST, " ");
	}

	QueryPerformanceCounter(&llMid);

	for(int i = 0; i < ciCOUNT; ++i)
	{
		//sTemp = StringLib<char>::normalizeWS_new(csTEST, csWHITESPACE);
		StringLib<char>::split(csTEST, " ");
	}

	QueryPerformanceCounter(&llEnd);
	QueryPerformanceFrequency(&llFreq);

	std::cout << "Duration 1: " << static_cast<double>(llMid.QuadPart - llStart.QuadPart) / static_cast<double>(llFreq.QuadPart) << std::endl;
	std::cout << "Duration 2: " << static_cast<double>(llEnd.QuadPart - llMid.QuadPart) / static_cast<double>(llFreq.QuadPart) << std::endl;

	std::string sTest = "Dit is een teststring met ümläuts";
	std::cout << sTest << std::endl;
	std::wstring xsTest = mbstowc(sTest);
	std::wcout << xsTest << std::endl;
	std::string sTest2 = wcstomb(xsTest);
	std::cout << sTest2 << std::endl;
	*/

	std::vector<std::string> vecWords;
	std::vector<std::string>::iterator iterWord;
	std::vector<std::wstring> vecWords2;
	std::vector<std::wstring>::iterator iterWord2;

	const std::string csWHITESPACE = " \t\r\n\f";
	const std::wstring cxsWHITESPACE = L" \t\r\n\f";

	vecWords.push_back("Tekst A");
	vecWords.push_back("\t Tekst B");
	vecWords.push_back("Tekst C \t");
	vecWords.push_back(" \tTekst D\t ");
	vecWords.push_back(" \n\t");
	vecWords.push_back("");
	vecWords.push_back("TekstG");
	//vecWords2.push_back(L"Tekst E");
	//vecWords2.push_back(L"\t Tekst F");
	//vecWords2.push_back(L"Tekst G \t");
	//vecWords2.push_back(L" \tTekst met \r\n veel\t\twhitespace H\t ");

	for(iterWord = vecWords.begin(); iterWord != vecWords.end(); ++iterWord)
	{
		//std::cout << "Trim [" << (*iterWord) << "]: [" << 
		//	trim(*iterWord, csWHITESPACE) << "]" << std::endl;
		//std::cout << "Norm [" << (*iterWord) << "]: [" << 
		//	normalizeWS(*iterWord, csWHITESPACE) << "]" << std::endl;
		//std::cout << "Uppr [" << (*iterWord) << "]: [" << 
		//	toUpper(*iterWord) << "]" << std::endl;
		std::cout << "Trim [" << (*iterWord) << "]: [" << 
			StringLib<char>::trim(*iterWord, csWHITESPACE) << "]" << std::endl;
		std::cout << "Split/Join [" << (*iterWord) << "]: [" << 
			StringLib<char>::join(StringLib<char>::split(*iterWord, " "), "@") << "]" << std::endl;
		std::cout << "Replace [" << (*iterWord) << "]: [" << 
			StringLib<char>::replace(StringLib<char>::replace(*iterWord, " ", "@"), "\t", "->") << "]" << std::endl;
		std::cout << "Norm [" << (*iterWord) << "]: [" << 
			StringLib<char>::normalizeWS(*iterWord, csWHITESPACE) << "]" << std::endl;
		std::cout << "Lowr [" << (*iterWord) << "]: [" << 
			StringLib<char>::toLower(*iterWord) << "]" << std::endl;
		std::cout << "Uppr [" << (*iterWord) << "]: [" << 
			StringLib<char>::toUpper(*iterWord) << "]" << std::endl;
	}

	for(iterWord2 = vecWords2.begin(); iterWord2 != vecWords2.end(); ++iterWord2)
	{
		//std::wcout << L"Trim [" << (*iterWord2) << L"]: [" << 
		//	trim(*iterWord2, cxsWHITESPACE) << L"]" << std::endl;
		//std::wcout << L"Norm [" << (*iterWord2) << L"]: [" << 
		//	normalizeWS(*iterWord2, cxsWHITESPACE) << L"]" << std::endl;
		//std::wcout << L"Uppr [" << (*iterWord2) << L"]: [" << 
		//	toUpper(*iterWord2) << L"]" << std::endl;
		//std::wstring temp = toUpper(*iterWord2);
		//std::wcout << L"Uppr [" << (*iterWord2) << L"]: [" << 
		//	temp << L"]" << std::endl;
		//int i = 1;
		std::wcout << "Trim [" << (*iterWord2) << "]: [" << 
			StringLib<wchar_t>::trim(*iterWord2, cxsWHITESPACE) << "]" << std::endl;
		std::wcout << "Norm [" << (*iterWord2) << "]: [" << 
			StringLib<wchar_t>::normalizeWS(*iterWord2, cxsWHITESPACE) << "]" << std::endl;
		std::wcout << "Uppr [" << (*iterWord2) << "]: [" << 
			StringLib<wchar_t>::toUpper(*iterWord2) << "]" << std::endl;
	}

	//test();

	/*
	LARGE_INTEGER llStart, llEnd, llFreq;

	const std::string csALLCHARS = 
		"\x20\x21\x22\x23\x24\x25\x26\x27\x28\x29\x2A\x2B\x2C\x2D\x2E\x2F"
		"\x30\x31\x32\x33\x34\x35\x36\x37\x38\x39\x3A\x3B\x3C\x3D\x3E\x3F"
		"\x40\x41\x42\x43\x44\x45\x46\x47\x48\x49\x4A\x4B\x4C\x4D\x4E\x4F"
		"\x50\x51\x52\x53\x54\x55\x56\x57\x58\x59\x5A\x5B\x5C\x5D\x5E\x5F"
		"\x60\x61\x62\x63\x64\x65\x66\x67\x68\x69\x6A\x6B\x6C\x6D\x6E\x6F"
		"\x70\x71\x72\x73\x74\x75\x76\x77\x78\x79\x7A\x7B\x7C\x7D\x7E\x7F"
		"\x80\x81\x82\x83\x84\x85\x86\x87\x88\x89\x8A\x8B\x8C\x8D\x8E\x8F"
		"\x90\x91\x92\x93\x94\x95\x96\x97\x98\x99\x9A\x9B\x9C\x9D\x9E\x9F"
		"\xA0\xA1\xA2\xA3\xA4\xA5\xA6\xA7\xA8\xA9\xAA\xAB\xAC\xAD\xAE\xAF"
		"\xB0\xB1\xB2\xB3\xB4\xB5\xB6\xB7\xB8\xB9\xBA\xBB\xBC\xBD\xBE\xBF"
		"\xC0\xC1\xC2\xC3\xC4\xC5\xC6\xC7\xC8\xC9\xCA\xCB\xCC\xCD\xCE\xCF"
		"\xD0\xD1\xD2\xD3\xD4\xD5\xD6\xD7\xD8\xD9\xDA\xDB\xDC\xDD\xDE\xDF"
		"\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF"
		"\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF7\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

	std::string sHugeString = csALLCHARS;
	for(int i = 0; i < 19; ++i)
	{
		sHugeString += sHugeString;
	}


	QueryPerformanceCounter(&llStart);
	std::string sResult = StringLib<char>::toUpper(sHugeString);
	QueryPerformanceCounter(&llEnd);
	QueryPerformanceFrequency(&llFreq);

	std::cout << "Num chars: " << sHugeString.length() << std::endl;
	std::cout << "Duration: " << static_cast<double>(llEnd.QuadPart - llStart.QuadPart) / static_cast<double>(llFreq.QuadPart) << std::endl;
	std::cout << "Result: " << sResult.substr(0, csALLCHARS.length()) << std::endl;
	*/

	int x;
	std::cin >> x;

	return 0;
}
