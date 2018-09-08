#ifndef __OPTION_H_
#define __OPTION_H_

#include "File.h"
#include <vector>
#include <iostream>
#include <map>
#include <functional>
#include <Windows.h>
#include <string>
#include "mystring.h"
#include "utils.h"

using namespace std;

class Option {
public:
    Option(int argc, char const ** argv);
    ~Option() {
    }
    void Print();
private:
    void usage();
    void Handle();
    void Setup();
    void RegisterAction(string option, function<void(void)> f);
private:
    vector<File> files;
    vector<string> option;
    map<string, function<void(void)>> actions;
    map<string, string> output_each_file;
};


#endif // !__OPTION_H_


