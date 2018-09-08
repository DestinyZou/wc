#ifndef __File_H_
#define __File_H_

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "mystring.h"

using namespace std;

class File {
public:
    File(string name);
    ~File();
    File(File &&)=default;
    File& operator=(File &&)=default;
    void print();
    void AnalyseFile();
    size_t getWordNum();
    size_t getLineNum();
    size_t getCharacterNum();
    string getFilename();
private:
    File(const File&);
    File& operator=(const File&);
    bool isWord(const char c);
    void CountWord(string line);
private:
    string filename;
    size_t character_number = 0;
    size_t line_number = 0;
    size_t word_number = 0;
private:
    ifstream in;
};


#endif