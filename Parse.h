#ifndef __PARSE_H_
#define __PARSE_H_

#include "Counter.h"
#include <vector>
#include <iostream>
#include <map>
#include <functional>
#include <Windows.h>
#include <string>
#include <algorithm>
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
    void registerOption(string option, function<void(void)> f);
private:
    vector<Counter> counters;
    vector<string> options;
    map<string, function<void(void)>> actions;
    map<string, string> output_per_file;
};


#endif // !__PARSE_H_


