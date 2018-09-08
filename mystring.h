#ifndef __MYSTRING_H_
#define __MYSTRING_H_

#include <string>
using namespace std;

static wstring Str2Wstr (string str) {
    if (str.length() == 0)
        return L"";

    std::wstring wstr;
    wstr.assign(str.begin(), str.end());
    return wstr;
}

static string Wstr2Str(wstring wstr) {
    if (wstr.length() == 0)
        return "";

    std::string str;
    str.assign(wstr.begin(), wstr.end());
    return str;
}

#endif // !__MYSTRING_H_