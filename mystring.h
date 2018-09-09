#ifndef __MYSTRING_H
#define __MYSTRING_H

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


static string& trim(string &s) {
    if (s.empty()) {
        return s;
    }
 
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s. find_last_not_of(" ") + 1);
    return s;
}

#endif // !__MYSTRING_H

