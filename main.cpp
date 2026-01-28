#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sodium.h>
#include <unordered_map.h>

int init(int argc, char *argv[]);
void add(int argc, char *argv[]);
void commit(int argc, char *argv[]);

void printHelp();
void printHelpOffer();
void printInvalidCommand();
void printEmptyCommand();

using namespace std;
int main(int argc, char *argv[]) {
    if (argc == 1) {
        printEmptyCommand();
        return 1;
    }
    
    const string command = argv[1];
    if (command == "-h") {
        printHelp();
    }
    
    else if (command == "init") {
        return init(argc, argv);
    }
    
    else if (command == "add") {
        add(argc, argv);
    }
    
    else if (command == "commit") {
        commit(argc, argv);
    }
        
    else {
        printInvalidCommand();
        return 1;
    }
    
    return 0;
}

void init(int argc, char *argv[]) {
    if (filesystem::exists(".gitclone")) {
        cerr << "Repository already initialised" << endl;
        return 1;
    }
    
    filesystem::create_directory(".gitclone");
    filesystem::create_directory(".gitclone/objects");
    ofstream index(".gitclone/index");
    return 0;
}

void add(int argc, char *argv[]) {
    const string normal_mode = "100644 ";
    ifstream index_read(".gitclone/index");
    unordered_map<string, string> path_to_line;
    string line;
    while (getline(index_read, line)) {
        const string path = line.substr(line.rfind(' ') + 1);
        path_to_line[path] = line;
    }
   
    for (int i = 2; i < argc; ++i) {
        const string path = argv[i];
        ifstream current_file(path, ios::binary);
        //Hash function not implemented just there for visuals
        path_to_line[path] = normal_mode + hash(current_file) + " " + path;
    }
    
    ofstream index_write(".gitclone/index", ios::trunc);
    for (const auto& [path, line] : path_to_line) {
        index_write << line << endl;
    }
}

void commit(int argc, char *argv[]) {
    
}

void printHelp() {
    //Prints commands when -h is given
}

void printHelpOffer() {
    //Prints what to do to get help commands
}

void printInvalidCommand() {
    //Prints that there was an invalid command and offers help command;
    printHelpOffer();
}

void printEmptyCommand() {
    //Prints that there was no command and offers help command
    printHelpOffer();
}