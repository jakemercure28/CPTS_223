//
// Created by jake on 2/3/21.
//
#include "game.h"
#include "profiles.h"

game::game(){

    question_count = 0;
    username = "";
    score = 0;
}

void game::display_rules(){
    cout << "Insert summary here.";
}

void game::play_game() {
    command c1, c2, c3;
    profiles p1;

    cout << "What is your name?" << endl;
    cin >> username;
    cout << "Great! Lets play the game." << endl;

    do {
        cout << "How many questions do you want to answer? (5-30)" << endl;
        cin >> question_count;
    }while(question_count < 5 || question_count > 30);

    do {
        c1 = p1.get_random_command();
        c2 = p1.get_random_command();
        c3 = p1.get_random_command();
    }while(c1.cmd == c2.cmd || c2.cmd == c3.cmd || c1.cmd == c3.cmd);


    cout << c1.cmd << "\t\t\t\t1." << c1.description << endl;

    cout << "\t\t\t\t2." << c2.description << endl;

    cout << "\t\t\t\t3." << c3.description << endl;

    /*string answer_array[3];

    answer_array[rand() % 3] = c1.description;

    int i = 0;

    do{
        if(answer_array[i] != c1.description){
            answer_array[i] = c2.description;
        }
        else if(answer_array[i] != c1.description && answer_array[i] != c2.description){
            answer_array[i] = c3.description;
        }
    }while()


    int answer_printed = 0, num = 0;
    do {
        num = rand() % 3;

        if(num != 1) {
            switch (num) {
                case 1:
                    cout << c1.description; // prints out answer
                    answer_printed = 1;
                    break;
                case 2:
                    cout << c2.description;
                    break;
                case 3:

            }
        }
    }while(!answer_printed);*/
}

void game::load_previous_game() {

}

void game::add_command() {

}

void game::remove_command() {

}

void game:: set_score(int val){
    score = val;
}