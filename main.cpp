/*
 * ADVANTAGES/DISADVANTAGES LINKED LIST:
 *      Advantage:    manual memory management, ablity to dynamically allocate memory as needed.
 *                    Allows for more or less commands to be entered into the game in this situation.
 *      Disadvantage: More control can lead to more errors, like memory leaks where unused memory is being
 *                    allocated for no good use. There could be a linked list of 1000 nodes for a csv of only 30 entities.
 *
 * ADVANTAGES/DISADVANTAGES ARRAY:
 *      Advantage:    The profiles can be stored in a set length amount of memory space. Each profile will only
 *                    take up a specified amount of memory depending on the data type the array is.
 *      Disadvantage: The array must convert the score of the user to a char to fit in a string datatype array.
 *                    The name of the user is a string and thus one or the other must convert. Arrays cant store more
 *                    than 1 data type per array.
 *
 *
 */
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
