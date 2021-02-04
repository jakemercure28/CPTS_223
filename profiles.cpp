//
// function implementations
//
// Created by jake on 2/3/21.
//
#include "profiles.h"

profiles::profiles(){    // initialization

    fstream input;

    input.open("/home/jake/CLionProjects/PA1/commands.csv", ios::in);

    if(input.fail())
        printf("Error opening file");

    int i = 0;
    string temp1, temp2;    //stores temp data from file input

    while(input){

        getline(input, temp1, ',');
        list_of_commands[i].cmd =  temp1;

        getline(input, temp2, ',');
        list_of_commands[i].description = temp2;

        i++;
    }
}