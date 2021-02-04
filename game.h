//
// Created by jake on 2/3/21.
//

#ifndef PA1_GAME_H
#define PA1_GAME_H
#include <iostream>

using namespace std;
class game
{
private:
    string username;
    int score;

public:
    game();

    void display_rules();
    void play_game();
    void load_previous_game();
    void add_command();
    void remove_command();
};

#endif //PA1_GAME_H
