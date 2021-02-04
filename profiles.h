#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class profiles{
private:
    struct command{
        string cmd;
        string description;
    };

    command list_of_commands[30];

public:
    profiles();


};