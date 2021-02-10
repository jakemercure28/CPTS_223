
#include "game.h"
#include "cstdlib"

using namespace std;

int main() {

    srand(time(nullptr));

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
            cout << "Game over!" << "Score: " << g1.get_score();
            break;
            case 3: g1.load_previous_game();
            break;
            case 4: g1.add_command();
            break;
            case 5: g1.remove_command("ls");
            break;
            case 6: g1.exit();
        }

    }while(option != 6);


    return 0;
}
