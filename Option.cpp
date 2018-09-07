#include "Option.h"

Option::Option(int argc, char const ** argv) {
    size_t not_option_number = 0;
    string filename;

    for (size_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            option.push_back(string(argv[i]));
        } else {
            not_option_number++;
            if (not_option_number == 1) {
                filename = string(argv[i]);
            } else {
                // usage()
                exit(-1);
            }
        }
    }

    file = new File(filename);
    
    setup();
}

void
Option::setup() {
    registerAction("-c", [&]() {
        file->PrintCharacterNum();
    });

    registerAction("-w", [&]() {
        file->PrintWordNum();
    });
    
    registerAction("-l", [&]() {
        file->PrintLineNum();
    });
}

void
Option::Handle() {
    for (auto s : option) {
        if (actions.find(s) == actions.end()) {
            // usage()
            exit(-1);
        } else {
            actions[s]();
        }
    }
}

void
Option::registerAction(string option, function<void(void)> f) {
    actions[option] = f;
}
