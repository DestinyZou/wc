#ifndef __UTILS_H_
#define __UTILS_H_
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include "mystring.h"

using namespace std;

static vector<wstring>
SearchFilesByWildcard(wstring path) {
	string wildcardPath = Wstr2Str(path);
	HANDLE hFile = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATAW pNextInfo;
    vector<wstring> ret;

	hFile = FindFirstFileW(path.c_str(),&pNextInfo); 
	if(INVALID_HANDLE_VALUE == hFile) {  
		return ret;
	}  
 
	WCHAR infPath[MAX_PATH] = {0};

    do
    {
    	if(pNextInfo.cFileName[0] == '.') {
			continue;  
		}
         ret.push_back(wstring(pNextInfo.cFileName));

    } while(FindNextFileW(hFile,&pNextInfo));
 
	return ret;
}



/* log */
template<typename T>
ostream &log(const T &t) {
    return cout << t;
}
template <typename T, typename... Args>
ostream &log(const T &t, const Args&... rest) {
    cout << t << ", ";
    return log(rest...);
}

#endif // !__UTILS_H_
