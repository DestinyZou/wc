#ifndef __OPTION_H_
#define __OPTION_H_

#include "File.h"
#include <vector>
#include <iostream>
#include <map>
#include <functional>

using namespace std;

class Option {
public:
    Option(int argc, char const ** argv);
    ~Option() {
        delete file;
    }
    void Handle();
private:
    void setup();
    void registerAction(string option, function<void(void)> f);
private:
    File* file;
    vector<string> option;
    map<string, function<void(void)>> actions;
};


#endif // !__OPTION_H_


