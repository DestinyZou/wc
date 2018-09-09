#include "Counter.h"

Counter::Counter(string s) {
    file_name = s;
    in.open(file_name);
    if (!in) {
        cout << "cannot open the file: " << file_name << endl;
        exit(-1);
    }
    work();
}

Counter::~Counter() {
    in.close();
}

bool
Counter::judgePartOfWord(const char c) {
    return isalpha(c);
}

bool
Counter::judgeBlankLine(string line) {
    if (0 == line.length()) return true;
    size_t graph = 0;
    for (auto c : line) {
        if (isgraph(c)) graph++;
        if (graph > 1) return false;
    }
    return true;
}

bool
Counter::judgeAndUpdateCommentLine(string line, bool& flag) {
    if(line[0] == '/' && line[1] == '/') return true;// "//"
	if(line[0] == '*' && line[1] == '/' && line.length()==2) {flag = false; return true;} // "*/"
	if(line[0] == '/' && line[1] == '*' && line.length()==2) return flag = true;// "/*"
	if(line[0] == '/' && line[1] == '*' && line.find("*/")==string::npos) return flag = true; // "/* ... */"

    string::size_type i = 0;
    while (isblank(line[i])) {
        i++;
    }
    if (line[i] == '}' && line[i+1] == '/' && line[i+2] == '/') return true;// "}//"
    
	string::size_type index = line.find("/*");
	if(index != string::npos) {
		flag = true;
	}
	if(flag) {
		index = line.find("*/");
		if(index != string::npos)
		{
			flag = false;
			line[index] = line[index+1] = ' ';
			string sub = line.substr(index+2, line.length()-index-2);
			trim(sub);
			if (judgeAndUpdateCommentLine(sub, flag)) return true;
		}
	}
	return false;
}

size_t
Counter::countWordInOneLine(string line) {
    istringstream iss(line);
    size_t word = 0;
    char c;
    for (size_t i = 0; i < line.length(); i++) {
        c = iss.get();
        if(judgePartOfWord(c)) {
            word++;
        }
        for (; c != EOF; c = iss.get()) {
            if (!judgePartOfWord(c)) {
                break;
            }
        }
    }
    return word;
}

void
Counter::work() {
    string line;
    string word;
    bool comment_flag = false;

    while (getline(in, line)) {
        if (judgeBlankLine(line)) {
            blank_line_number++;
        } else if (comment_flag) {//当前是否是注释行
            comment_line_number++;
            judgeAndUpdateCommentLine(line, comment_flag);//更新flag
        } else if (judgeAndUpdateCommentLine(line, comment_flag)) {
            comment_line_number++;
        } else {
            code_line_number++;
        }
        character_number += line.length();
        word_number += countWordInOneLine(line);
    }
    line_number = blank_line_number + comment_line_number + code_line_number;
}

size_t
Counter::getWordNum() {
    return word_number;
}

size_t
Counter::getLineNum() {
    return line_number;
}

size_t
Counter::getCharacterNum() {
    return character_number;
}

size_t
Counter::getBlankLineNum() {
    return blank_line_number;
}

size_t
Counter::getCommentLineNum() {
    return comment_line_number;
}

size_t
Counter::getCodeLineNum() {
    return code_line_number;
}

string
Counter::getFilename() {
    return file_name;
}


