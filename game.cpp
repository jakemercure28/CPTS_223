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
    int user_answer;
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

    do {
        switch (rand() % 3) {

            case 1:
                cout << c1.cmd << endl;
                cout << "\t\t\t\t1." << c1.description << endl;
                cout << "\t\t\t\t2." << c2.description << endl;
                cout << "\t\t\t\t3." << c3.description << endl;
                cin >> user_answer;

                if (user_answer == 1)
                    cout << "Correct answer! 5 points awarded." << endl;

                break;
            case 2:
                cout << c1.cmd << endl;
                cout << "\t\t\t\t1." << c2.description << endl;
                cout << "\t\t\t\t2." << c3.description << endl;
                cout << "\t\t\t\t3." << c1.description << endl;
                cin >> user_answer;

                if (user_answer == 3)
                    cout << "Correct answer! 5 points awarded." << endl;

                break;
            case 3:
                cout << c1.cmd << endl;
                cout << "\t\t\t\t1." << c3.description << endl;
                cout << "\t\t\t\t2." << c1.description << endl;
                cout << "\t\t\t\t3." << c2.description << endl;
                cin >> user_answer;

                if (user_answer == 2)
                    cout << "Correct answer! 5 points awarded." << endl;
        }
    }while(user_answer >=1 && user_answer <= 3);
}

void game::load_previous_game() {

}

void game::add_command() {
    command new_cmd;
    cout << "Enter command name: " << endl;
    cin >> new_cmd.cmd;

    cout << "Enter command description" << endl;
    cin >> new_cmd.description;

    insert_at_front(new_cmd);
}

void game::remove_command() {


}

void game:: set_score(int val){
    score = val;
}