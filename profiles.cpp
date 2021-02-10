//
// function implementations
//
// Created by jake on 2/3/21.
//
#include "profiles.h"

void profiles::insert_at_front(command cmd_data){

    listNode* new_node = new listNode();

    new_node->command_data = cmd_data;
    new_node->next = head;

    head = new_node;
}


profiles::profiles(){    // initialization

    fstream input;

    input.open("/home/jake/CLionProjects/PA1/commands.csv", ios::in);

    if(input.fail())
        cout << "Error opening file";

    int i = 0;
    string temp1, temp2;    //stores temp data from file input
    command current_command;

    while(input){
        getline(input, temp1, ',');
        current_command.cmd = temp1;

        getline(input, temp2, ',');
        current_command.description = temp2;

        insert_at_front(current_command);
        i++;
    }
}

void profiles::remove_node(int location) {

    command current;
    listNode* temp = head;

    if (location == 0) {
        current = head->command_data;
        delete temp;
    }

    for(int i = 0; temp != nullptr && i < location-1; i++)
        temp = temp->next;

    listNode* next = temp->next->next;
    delete (temp->next);

    temp->next = next;
}

command profiles::get_random_command() {

    int location = rand() % 35;
    int i = 0;
    listNode* current = head;

    while(current != nullptr){
        if(i == location){
            return current->command_data;
        }
        current = current->next;
        i++;
    }
}