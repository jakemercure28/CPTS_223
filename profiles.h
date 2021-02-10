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
    struct listNode{
        command command_data;
        listNode* next;
    };

    listNode *head;
public:

    profiles();
    void insert_at_front(command cmd_data);
    void remove_node(int location);

    command get_random_command();



};