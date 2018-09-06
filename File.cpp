#include "File.h"

File::File(string name) {
    in.open(name);
    if (!in) {
        cout << "cannot open the file" << endl;
        exit(-1);
    }
}

File::~File() {
    in.close();
}

void
File::print() {
    string line;
    while (getline(in, line)) {
        cout << line << endl;
    }
}

/*如果c是一个合法单词的组成部分，返回true*/
bool
File::isWord(const char c) {
    return isalpha(c);
}

void
File::CountWord(string line) {
    istringstream iss(line);
    char c;
    for (size_t i = 0; i < line.length(); i++) {
        c = iss.get();
        if(isWord(c)) {
            word_number++;
        }
        for (; c != EOF; c = iss.get()) {
            if (!isWord(c)) {
                break;
            }
        }
    }
}

void
File::AnalyseFile() {
    string line;
    string word;
    while (getline(in, line)) {
        // 统计行数
        line_number++;
        // 统计字符数
        character_number += line.length();
        // 统计单词
        CountWord(line);
    }

    cout << "Character: " << character_number << endl;
    cout << "Word: " << word_number << endl;
    cout << "line: " << line_number << endl;
}
