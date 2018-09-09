#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

/*
 * a test file
 */
int main(void)
{
    string s = "/*    */";
    for (char c : s) {
        if(isgraph(c))
            cout << c << endl;
    }//hahaha
    return 0;
}