#ifndef __File_H_
#define __File_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

class File {
public:
    File(string name);
    ~File();
    void print();
    void AnalyseFile();
    void PrintWordNum();
    void PrintLineNum();
    void PrintCharacterNum();
private:
    File(const File&);
    File& operator=(const File&);
    bool isWord(const char c);
    void CountWord(string line);
public:
    int character_number = 0;
    int line_number = 0;
    int word_number = 0;
private:
    ifstream in;
};


#endif