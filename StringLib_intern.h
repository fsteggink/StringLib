// StringLib_intern.h
// FS, 22-06-2005

#ifndef STRINGLIB_INTERN_H
#define STRINGLIB_INTERN_H

#define DLLAPI_STRINGLIB __declspec(dllexport)
#define TEMPLATE_SPEC template

#include <string>
#include <vector>
#include <windows.h>
#include <iostream>


////////////////////////////////////////////////////////////
// Template definitions                                   //
////////////////////////////////////////////////////////////

// This function strips whitespace from both sides of a string value
template<typename charT>
std::basic_string<charT> trim(const std::basic_string<charT> &sSource, const std::basic_string<charT> &sWhiteSpace)
{
	return StringLib<charT>::trim(sSource, sWhiteSpace);
}


// This function splits a string, based on a separator, into a vector of 
// strings.
template<class charT>
std::vector< std::basic_string<charT> > split(const std::basic_string<charT> &sText, const std::basic_string<charT> &sSep)
{
	return StringLib<charT>::split(sText, sSep);
}


// This function concatenates the items in a vector to a string, with the given
// separator
template<typename charT>
std::basic_string<charT> join(const std::vector< std::basic_string<charT> > &vecWords, const std::basic_string<charT> &sSep)
{
	return StringLib<charT>::join(vecWords, sSep);
}


// This function replaces a substring in a string with a different substring
template<typename charT>
std::basic_string<charT> replace(const std::basic_string<charT> &sIn, const std::basic_string<charT> &sFind, const std::basic_string<charT> &sRep)
{
	return StringLib<charT>::replace(sIn, sFind, sRep);
}


// This function normalizes the whitespace in the given value
template<typename charT>
std::basic_string<charT> normalizeWS(const std::basic_string<charT> &sValue, const std::basic_string<charT> &sWhiteSpace)
{
	return StringLib<charT>::normalizeWS(sValue, sWhiteSpace);
}


// This function converts all characters in the string to their lowercase counterparts
template<typename charT>
std::basic_string<charT> toLower(const std::basic_string<charT> &sValue)
{
	return StringLib<charT>::toLower(sValue);
}


// This function converts all characters in the string to their uppercase counterparts
template<typename charT>
std::basic_string<charT> toUpper(const std::basic_string<charT> &sValue)
{
	return StringLib<charT>::toUpper(sValue);
}


template<typename charT>
class StringLib
{
	typedef typename std::basic_string<charT>::size_type size_type;

public:
	// This function strips whitespace from both sides of a string value
	static std::basic_string<charT> trim(const std::basic_string<charT> &sSource, const std::basic_string<charT> &sWhiteSpace)
	{
		std::basic_string<charT> sDest;

		// Find the first and last non-whitespace character
		size_type iPos = sSource.find_first_not_of(sWhiteSpace);
		size_type iPos2 = sSource.find_last_not_of(sWhiteSpace);
		
		if(iPos != std::basic_string<charT>::npos && iPos2 != std::basic_string<charT>::npos)
		{
			// Non-whitespace found, trim the source string
			sDest = sSource.substr(iPos, iPos2 - iPos + 1);
		}

		return sDest;
	}


	// This function splits a string, based on a separator, into a vector of 
	// strings.
	static std::vector< std::basic_string<charT> > split(const std::basic_string<charT> &sText, const std::basic_string<charT> &sSep)
	{
		std::vector< std::basic_string<charT> > vecWords;


		// Do not split anything when the text is empty
		if(sText.empty())
		{
			return vecWords;
		}

		size_type iOldPos = 0;
		size_type iPos = sText.find(sSep);

		// Cut substrings from the given string as long as the separator is found
		while(iPos != std::basic_string<charT>::npos)
		{
			vecWords.push_back(sText.substr(iOldPos, iPos - iOldPos));

			iOldPos = iPos + sSep.length();
			iPos = sText.find(sSep, iOldPos);
		}

		vecWords.push_back(sText.substr(iOldPos));

		return vecWords;
	}


	// This function concatenates the items in a vector to a string, with the given
	// separator
	static std::basic_string<charT> join(const std::vector< std::basic_string<charT> > &vecWords, const std::basic_string<charT> &sSep)
	{
		std::basic_string<charT> sResult;


		// Do not join anything when the vector is empty
		if(vecWords.empty())
		{
			return sResult;
		}

		typename std::vector< std::basic_string<charT> >::const_iterator iterWord = vecWords.begin();
		sResult = *iterWord;

		for(iterWord++; iterWord != vecWords.end(); iterWord++)
		{
			sResult += sSep + *iterWord;
		}

		return sResult;
	}


	// This function replaces a substring in a string with a different substring
	static std::basic_string<charT> replace(const std::basic_string<charT> &sIn, const std::basic_string<charT> &sFind, const std::basic_string<charT> &sRep)
	{
		std::basic_string<charT> sResult(sIn);
		size_type pos = sResult.find(sFind);
		while(pos != std::basic_string<charT>::npos)
		{
			sResult = sResult.replace(pos, sFind.length(), sRep);
			pos = sResult.find(sFind, pos + sRep.length());
		}

		return sResult;
	}


	// This function normalizes the whitespace in the given value
	static std::basic_string<charT> normalizeWS(const std::basic_string<charT> &sValue, const std::basic_string<charT> &sWhiteSpace)
	{
		std::basic_string<charT> sCopy(trim(sValue, sWhiteSpace));

		const std::basic_string<charT> csSingleSpace(1, static_cast<charT>(0x20));


		// Replace subsequent occurrences of characters in the whitespace string with single spaces
		size_type pos = sCopy.find_first_of(sWhiteSpace);
		size_type pos2;
		while(pos != std::basic_string<charT>::npos)
		{
			pos2 = sCopy.find_first_not_of(sWhiteSpace, pos);
			
			sCopy = sCopy.replace(pos, pos2 - pos, csSingleSpace);
			pos = sCopy.find_first_of(sWhiteSpace, pos + 1);
		}

		return sCopy;
	}


	// This function converts all characters in the string to their lowercase counterparts
	static std::basic_string<charT> toLower(const std::basic_string<charT> &sValue)
	{
		typename std::basic_string<charT>::size_type idx;
		std::basic_string<charT> sResult = sValue;

		static const unsigned int ciLOWERCASE_MASK[] = {
			0x00000000, 0x00000000, 0x07FFFFFE, 0x00000000,
			0x00000000, 0x00000000, 0x7F7FFFFF, 0x00000000 };


		// Convert every character to lowercase
		for(idx = 0; idx < sResult.length(); ++idx)
		{
			int iCharValue = sResult[idx] & 0xFF;
			if(ciLOWERCASE_MASK[iCharValue / 32] & (1 << (iCharValue % 32)))
				sResult[idx] += 0x20;
		}

		return sResult;
	}


	// This function converts all characters in the string to their uppercase counterparts
	static std::basic_string<charT> toUpper(const std::basic_string<charT> &sValue)
	{
		typename std::basic_string<charT>::size_type idx;
		std::basic_string<charT> sResult = sValue;

		static const unsigned int ciUPPERCASE_MASK[] = {
			0x00000000, 0x00000000, 0x00000000, 0x07FFFFFE,
			0x00000000, 0x00000000, 0x00000000, 0x7F7FFFFF };


		// Convert every character to upper case
		for(idx = 0; idx < sResult.length(); ++idx)
		{
			int iCharValue = sResult[idx] & 0xFF;
			if(ciUPPERCASE_MASK[iCharValue / 32] & (1 << (iCharValue % 32)))
				sResult[idx] -= 0x20;
		}

		return sResult;
	}
};


////////////////////////////////////////////////////////////
// Exported template specializations                      //
////////////////////////////////////////////////////////////

// Make sure that these match the imported function declarations!

TEMPLATE_SPEC DLLAPI_STRINGLIB std::string trim<char>(const std::string &, const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::wstring trim<wchar_t>(const std::wstring &, const std::wstring &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::vector<std::string> split<char>(const std::string &, const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::vector<std::wstring> split<wchar_t>(const std::wstring &, const std::wstring &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::string join<char>(const std::vector<std::string> &, const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::wstring join<wchar_t>(const std::vector<std::wstring> &, const std::wstring &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::string replace<char>(const std::string &, const std::string &, const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::wstring replace<wchar_t>(const std::wstring &, const std::wstring &, const std::wstring &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::string normalizeWS<char>(const std::string &, const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::wstring normalizeWS<wchar_t>(const std::wstring &, const std::wstring &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::string toLower<char>(const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::wstring toLower<wchar_t>(const std::wstring &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::string toUpper<char>(const std::string &);
TEMPLATE_SPEC DLLAPI_STRINGLIB std::wstring toUpper<wchar_t>(const std::wstring &);

TEMPLATE_SPEC class DLLAPI_STRINGLIB StringLib<char>;
TEMPLATE_SPEC class DLLAPI_STRINGLIB StringLib<wchar_t>;

std::string DLLAPI_STRINGLIB wcstomb(const std::wstring &xsValue);
std::wstring DLLAPI_STRINGLIB mbstowc(const std::string &sValue);


////////////////////////////////////////////////////////////
// Exported function declarations                         //
////////////////////////////////////////////////////////////


#endif // STRINGLIB_INTERN_H
