//
// Created by jake on 2/3/21.
//

#ifndef PA1_GAME_H
#define PA1_GAME_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct command{
    string cmd;
    string description;
};




class game{
    struct listNode{
        command command_data;
        listNode* next;
    };

    string username;
    int question_count;
    int score;

    listNode *head;

public:
    game();

    static void display_rules();
    void play_game();
    void load_previous_game();
    void add_command();
    void remove_command(int location);
    void set_score(int);
    command get_random_command();
};

#endif //PA1_GAME_H
