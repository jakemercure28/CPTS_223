//
// Created by jake on 2/3/21.
//

#ifndef PA1_GAME_H
#define PA1_GAME_H
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

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
    ~game();

    static void display_rules();
    void play_game();
    void load_previous_game();
    void add_command();
    void exit();
    void insert_at_front(command new_cmd);
    void remove_command(string input);

    void set_score(int);

    command get_random_command();
    int get_score();
};

#endif //PA1_GAME_H
