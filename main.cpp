#include "profiles.h"
#include "game.h"

using namespace std;

int main() {

    profiles profile1;

    game g1;
    int option;
    do{
        cout << "1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n";
        cout << "5. Remove Command\n6. Exit\n\n";

        cin >> option;

        switch(option)
        {
            case 1: g1.display_rules();
            break;
            case 2: g1.play_game();
            break;
            case 3: g1.load_previous_game();
            break;
            case 4: g1.add_command();
            break;
            case 5: g1.remove_command();
            break;
            default: break;
        }

    }while(option != 6);


    return 0;
}
