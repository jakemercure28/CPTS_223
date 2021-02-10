//
// Created by jake on 2/3/21.
//
#include "game.h"


game::game(){

    fstream input;

    input.open("commands.csv", ios::in);

    if(input.fail())
        cout << "Error opening file";

    int i = 0;
    string line;    //stores temp data from file input
    string temp1, temp2;
    command current_command;

    while(input){
        getline(input, line);

        stringstream ss(line);

        getline(ss, temp1, ',');
        current_command.cmd = temp1;

        getline(ss, temp2, ',');
        current_command.description = temp2;

        insert_at_front(current_command);
        i++;
    }

    input.close();

    cout << "What is your name?" << endl;
    cin >> username;
    question_count = 0;
    score = 0;
}

game::~game(){
    delete head;
}

void game::display_rules(){
    cout << "Insert summary here.";
}

void game::play_game() {
    int user_answer, shuffle, count = 0;
    bool correct_answer = false;
    command c1, c2, c3;

    cout << "Great! Lets play the game." << endl;

    do { // check question count bounds
        cout << "How many questions do you want to answer? (5-30)" << endl;
        cin >> question_count;
    } while (question_count < 5 || question_count > 30);

    do{ // run game loop until out of questions

        do {
            // get different random commands for each answer
            c1 = get_random_command();
            c2 = get_random_command();
            c3 = get_random_command();
        }while (c1.cmd == c2.cmd || c2.cmd == c3.cmd || c1.cmd == c3.cmd);

        shuffle = (rand() % 3)+1;
        switch (shuffle) { // shuffles the answer between 3 formats
            case 1:
                cout << c1.cmd << endl;
                cout << "\t\t\t\t1." << c1.description << endl;
                cout << "\t\t\t\t2." << c2.description << endl;
                cout << "\t\t\t\t3." << c3.description << endl;
                cin >> user_answer;

                if (user_answer == 1) {
                    cout << "Correct answer! 5 points awarded." << endl;
                    correct_answer = true;
                    score+= 5;
                }
                break;
            case 2:
                cout << c1.cmd << endl;
                cout << "\t\t\t\t1." << c2.description << endl;
                cout << "\t\t\t\t2." << c3.description << endl;
                cout << "\t\t\t\t3." << c1.description << endl;
                cin >> user_answer;

                if (user_answer == 3) {
                    cout << "Correct answer! 5 points awarded." << endl;
                    correct_answer = true;
                    score+= 5;
                }
                break;
            case 3:
                cout << c1.cmd << endl;
                cout << "\t\t\t\t1." << c3.description << endl;
                cout << "\t\t\t\t2." << c1.description << endl;
                cout << "\t\t\t\t3." << c2.description << endl;
                cin >> user_answer;

                if (user_answer == 2) {
                    cout << "Correct answer! 5 points awarded." << endl;
                    correct_answer = true;
                    score+= 5;
                }
                break;
        }

        if (!correct_answer) {
        cout << "Incorrect answer! 5 points taken." << endl;
        score -= 5;
        }

    count++;
    }while(count < question_count);
}

void game::load_previous_game() {

    fstream input;

    input.open("profiles.csv", ios::in);

    if(input.fail())
        cout << "Error opening file";

    int i = 0;
    string line;    //stores temp data from file input
    string temp1, temp2;

    getline(input, line);

    input.close();

    stringstream ss(line);

    getline(ss, temp1, ',');
    getline(ss, temp2, ',');

    username = temp1;
    score = stoi(temp2);
    cout << "Game loaded for " << username << "!" << endl;
}

void game::add_command() {

    command new_cmd;
    cout << "Enter command name: " << endl;
    cin >> new_cmd.cmd;

    cout << "Enter command description" << endl;
    cin >> new_cmd.description;

    fstream file;
    file.open("commands.csv", ios::app);

    if(file.fail())
        cout << "Error opening file";

    file << endl << new_cmd.cmd << "," << new_cmd.description;

    file.close();
}

void game::insert_at_front(command new_cmd) {

    listNode* new_node = new listNode();

    new_node->command_data = new_cmd;
    new_node->next = head;

    head = new_node;
}

void game::remove_command(string cmd_name) {

    fstream input;

    input.open("commands.csv", ios::out);

    if(input.fail())
        cout << "Error opening file";

    int i = 0;
    string line;    //stores temp data from file input
    string temp1, temp2;

    do{
        getline(input, line);

        stringstream ss(line);

        getline(ss, temp1, ',');


        if(temp1 == cmd_name)
            input << endl;

        input << line;

        i++;
    }while(i < 35);
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

int game::get_score() {
    return score;
}

void game::exit(){

    fstream outfile;
    string line;

    outfile.open("profiles.csv", ios_base::app);
    outfile << username << "," << score << "," << endl;
    outfile.close();
}