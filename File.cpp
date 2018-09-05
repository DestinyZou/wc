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

bool
File::isWord(const string word) {
    if (0 == isalpha(word[0])) {
        return false;
    } else {
        return true;
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

        // 把一行中所有不是字母、数字、下划线、"-"、"."的字符替换成空格
        for(char &c : line) {
            if (c != '_' && !isalnum(c) && c != '-' && c != '.') {
                c = ' ';
            }
        }

        // 统计单词
        istringstream iss(line);
        while (iss >> word) {
            if(isWord(word)){
                word_number++;
            }
        }
    }

    cout << "Character: " << character_number << endl;
    cout << "Word: " << word_number << endl;
    cout << "line: " << line_number << endl;
}
