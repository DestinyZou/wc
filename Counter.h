#ifndef __Counter_H_
#define __Counter_H_

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "mystring.h"

using namespace std;

class Counter {
public:
    Counter(string name);
    ~Counter();
    Counter(Counter &&)=default;
    Counter& operator=(Counter &&)=default;
    void work();
    size_t getWordNum();
    size_t getLineNum();
    size_t getCharacterNum();
    size_t getCommentLineNum();
    size_t getBlankLineNum();
    size_t getCodeLineNum();
    string getFilename();
private:
    Counter(const Counter&);
    Counter& operator=(const Counter&);
    bool judgePartOfWord(const char c);
    bool judgeAndUpdateCommentLine(string line, bool& flag);
    size_t countWordInOneLine(string line);
    bool judgeBlankLine(string line);
private:
    string file_name;
    size_t character_number     = 0;
    size_t line_number          = 0;
    size_t word_number          = 0;
    size_t code_line_number     = 0;
    size_t blank_line_number    = 0;
    size_t comment_line_number  = 0;
private:
    ifstream in;
};


#endif