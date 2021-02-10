//
// Created by jake on 2/3/21.
//

#ifndef PA1_GAME_H
#define PA1_GAME_H
#include <iostream>
#include "profiles.h"

using namespace std;
class game:public profiles{

protected:
    string username;
    int question_count;
    int score;

public:
    game();

    static void display_rules();
    void play_game();
    void load_previous_game();
    void add_command();
    void remove_command();
    void set_score(int);
};

#endif //PA1_GAME_H
