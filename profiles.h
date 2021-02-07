#include "game.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


struct command{
    string cmd;
    string description;
};

class profiles{
private:
    command list_of_commands[50];

public:

    profiles();
    command get_random_command();



};