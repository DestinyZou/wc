#include "Option.h"

Option::Option(int argc, char const ** argv) {
    size_t option_number = 0;
    for (size_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            option.push_back(string(argv[i]));
            option_number++;
        } else {
            // 把参数中不是选项的视为文件路径，并从文件路径中解析出文件名
            wstring path = Str2Wstr(string(argv[i]));
            vector<wstring> files_from_path = SearchFilesByWildcard(path);
            for (auto s : files_from_path) {
                string filename = Wstr2Str(s);
                output_each_file[filename] = "";
                File f(filename);
                files.push_back(move(f));
            }            
        }
    }
    if (option_number == 0) {
        usage();
        exit(-1);
    }
    Setup();
}

void
Option::Setup() {
    RegisterAction("-c", [&]() {
        for (auto &f : files) {
            string append = " Character: " + to_string(f.getCharacterNum());
            output_each_file[f.getFilename()] += append;
        }
    });

    RegisterAction("-w", [&]() {
        for (auto &f : files) {
            string append = " Word: " + to_string(f.getWordNum());
            output_each_file[f.getFilename()] += append;
        }
    });
    
    RegisterAction("-l", [&]() {
        for (auto &f : files) {
            string append = " Line: " + to_string(f.getLineNum());
            output_each_file[f.getFilename()] += append;
        }
    });

    Handle();
}

void
Option::Handle() {
    for (auto s : option) {
        if (actions.find(s) == actions.end()) {
            usage();
            exit(-1);
        } else {
            actions[s]();
        }
    }
}

void
Option::RegisterAction(string option, function<void(void)> f) {
    actions[option] = f;
}

void
Option::Print() {
    for (auto &o : output_each_file) {
        cout << o.first << "    " << o.second << endl;
    }
}

void
Option::usage() {
    string usage = string("wc.exe [OPTION]... [file]...\n"
                   "The options below may be used to select which counts are printed."
                   "The order is depended on the order of options.\n"
                   "  -c    print the character counts\n"
                   "  -w    print the word counts\n"
                   "  -l    print the newline counts\n");
    cout << usage;
}