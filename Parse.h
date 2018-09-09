#ifndef __OPTION_H_
#define __OPTION_H_

#include "Counter.h"
#include <vector>
#include <iostream>
#include <map>
#include <functional>
#include <Windows.h>
#include <string>
#include "mystring.h"
#include "utils.h"

using namespace std;

class Parse {
public:
    Parse(int argc, char const ** argv);
    ~Parse() {
    }
    void print();
private:
    void usage();
    void handleOption();
    void setup();
    void registerAction(string option, function<void(void)> f);
private:
    vector<Counter> counters;
    vector<string> options;
    map<string, function<void(void)>> actions;
    map<string, string> output_per_file;
};


#endif // !__OPTION_H_


