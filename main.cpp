#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Counter.h"
#include "Parse.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Parse parse(argc, argv);
    parse.print();
    return 0;
}