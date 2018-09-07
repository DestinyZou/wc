#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "File.h"
#include "Option.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Option opt(argc, argv);
    opt.Handle();
    return 0;
}