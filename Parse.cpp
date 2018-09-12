#include "Parse.h"

Parse::Parse(int argc, char const ** argv) {
    size_t option_number = 0;
    size_t file_number = 0;
    for (size_t i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            options.push_back(string(argv[i]));
            option_number++;
        } else {
            // 把参数中不是选项的视为文件路径，并从文件路径中解析出文件名
            wstring path = Str2Wstr(string(argv[i]));
            vector<wstring> files_from_path = SearchFilesByWildcard(path);
            for (auto s : files_from_path) {
                string file_name = Wstr2Str(s);
                output_per_file[file_name] = "";
                Counter f(file_name);
                counters.push_back(move(f));
                file_number++;
            }            
        }
    }
    if (0 == option_number || 0 == file_number) {
        usage();
        exit(-1);
    }
    setup();
}

void
Parse::setup() {
    registerOption("-c", [&]() {
        for (auto &f : counters) {
            string append = " Character: " + to_string(f.getCharacterNum());
            output_per_file[f.getFilename()] += append;
        }
    });
    registerOption("-w", [&]() {
        for (auto &f : counters) {
            string append = " Word: " + to_string(f.getWordNum());
            output_per_file[f.getFilename()] += append;
        }
    });   
    registerOption("-l", [&]() {
        for (auto &f : counters) {
            string append = " Line: " + to_string(f.getLineNum());
            output_per_file[f.getFilename()] += append;
        }
    });
    registerOption("-a", [&]() {
        for (auto &f : counters) {
            string append = " Blank line: " + to_string(f.getBlankLineNum());
            append += " Code line: " + to_string(f.getCodeLineNum());
            append += " Comment line: " + to_string(f.getCommentLineNum());
            output_per_file[f.getFilename()] += append;
        }
    });

    handleOption();
}

void
Parse::handleOption() {
    for (auto s : options) {
        if (actions.find(s) == actions.end()) {
            usage();
            exit(-1);
        } else {
            actions[s]();
        }
    }
}

void
Parse::registerOption(string option, function<void(void)> f) {
    actions[option] = f;
}

void
Parse::print() {
    for (auto &o : output_per_file) {
        cout << o.first << "    " << o.second << endl;
    }
}

void
Parse::usage() {
    string usage = string("wc.exe [OPTION]... [file]...\n"
                   "The options below may be used to select which counts are printed."
                   "The order is depended on the order of options.\n"
                   "  -c    print the character counts\n"
                   "  -w    print the word counts\n"
                   "  -l    print the newline counts\n"
                   "  -a    print more information(comment/code/blank line counts)");
    cout << usage;
}