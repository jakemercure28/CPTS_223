//
// Created by jake on 2/3/21.
//
#include "game.h"

game::game(){ //constructor

    fstream input;

    input.open("commands.csv", ios::in);

    if(input.fail())
        cout << "Error opening file";

    // data types used to parse csv
    int i = 0;
    string line;    //stores temp data from file input
    string temp1, temp2;
    command current_command;

    while(input){ // reading file
        getline(input, line);

        stringstream ss(line); //string stream splits the string to token each entity

        getline(ss, temp1, ','); // command
        current_command.cmd = temp1;

        getline(ss, temp2, ','); // description
        current_command.description = temp2;

        insert_at_front(current_command); // insert front of linked list
        i++;
    }

    input.close(); //close file object

    // initialize game object
    cout << "What is your name?" << endl;
    cin >> username;
    question_count = 0;
    score = 0;
}

game::~game(){
    delete head;
}

void game::display_rules(){
    cout << endl << "Match the linux command to the corresponding action on using the 1,2, and 3 keys" << endl;
    cout << "There are about 30 different commands available in the quiz. 5 points are awarded for correct" << endl;
    cout << "answers, 5 points are taken away for incorrect. You can also add/remove commands if needed. Good luck!" << endl;
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

        if (!correct_answer) { // incorect answer subtract points
        cout << "Incorrect answer! 5 points taken." << endl;
        score -= 5;
        }

    count++;
    }while(count < question_count); // loop until questions are done being answered
}

void game::load_previous_game() {

    fstream input;
    input.open("profiles.csv", ios::in);

    if (input.fail())
        cout << "Error opening file"; //error checking for file opening failures

    int i = 0;
    string line;    //stores temp data from file input
    string temp1, temp2;

    getline(input, line); //gets line from the profiles csv file

    input.close(); //closes file stream to profiles.csv

    stringstream ss(line); // string stream used to separate name and score

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

    file << new_cmd.cmd << "," << new_cmd.description << "," << endl;

    file.close();
}

void game::insert_at_front(command new_cmd) {

    listNode* new_node = new listNode();

    new_node->command_data = new_cmd;
    new_node->next = head;

    head = new_node;
}

void game::remove_command(string input) {

    fstream output;
    output.open("commands.csv", ios::out);

    if(output.fail())
        cout << "Error opening file";

    listNode* temp = head;

    while(temp->next->command_data.cmd != input) // search by name
        temp = temp->next;

        if(temp->next == nullptr)
            return; //if not found, then return

        listNode *next;
        next = temp->next->next; //move the node over 1

        next = temp->next; // move the node back over

    delete temp->next;

    temp->next = next;

    while(head != nullptr) { //print out list putting head back to the front
        output << head->command_data.cmd << "," << head->command_data.description << "," << endl;
        head = head->next;
    }
    output.close();
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