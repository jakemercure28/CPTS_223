//
// Created by jake on 2/3/21.
//
#include "game.h"

game::game(){

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
    game p1;

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

}
void game::insert_at_front(command new_cmd) {

    listNode* new_node = new listNode();

    new_node->command_data = new_cmd;
    new_node->next = head;

    head = new_node;
}
void game::remove_command(int location) {
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

void game:: set_score(int val){
    score = val;
}

command game::get_random_command() {

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