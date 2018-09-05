#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "File.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string filename(argv[1]);
    File file(filename);
    file.AnalyseFile();
    return 0;
}