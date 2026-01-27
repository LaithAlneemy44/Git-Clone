#include <iostream>
#include <string>

void init(int argc, char *argv[]);
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
        return 0;
    }
    
    const string command = argv[1];
    if (command == "-h") {
        printHelp();
    }
    
    else if (command == "init") {
        init(argc, argv);
    }
    
    else if (command == "add") {
        add(argc, argv);
    }
    
    else if (command == "commit") {
        commit(argc, argv);
    }
        
    else {
        printInvalidCommand();
    }
    
    return 0;
}

void init(int argc, char *argv[]) {
    
}

void add(int argc, char *argv[]) {
    
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