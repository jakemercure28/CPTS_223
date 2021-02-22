// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

/* Poor attributes of original code.
 * 1. The first poor attribute of the code is the dependency of the functions on
 * other functions. For example, testing the enqueue function also indirectly required
 * testing of the isEmpty() function. Narrowing down the bug got more difficult
 * since it was more challenging to pin point the test to result in a specific bug.
 *
 * 2. I think the data stucture used for the queue wasnt the best. An array isnt
 * dynamically allocated during runtime. A linked list would have been more effective
 * at storing the data in the queue. The queue doesnt need to have a limit at how
 * many values it can take on. A linked list can grow as much as the program needs.
 *
 * 3. Another attribute that needed work was the file structure. The queue.h file
 * should have a source file attached to the header.
 * Creating functions in the header file works, but the better practice is to separate
 * the function definitions from the function declarations.
 *
 * 4. The delete function is incorrect for this application. The array used in
 * the queue class is a pointer to an array. The deconstructor only deletes the
 * pointer to the array, but the array still utilizes memory.
 *
 * 5. While arrays have faster execution time when retrieving elements
 * in the middle of the array, queues are accessed from the front and
 * dont require extra speed to access any element. A fixed memory structure takes
 * more time for insertion and deletion while linked lists are very time efficiency.
 * The algorithm efficiency is important to save compuatational time and computer
 * resources when running the program.
 *
 */
#include "testQueue.h"

int main()
{
    // call your test functions here!
    testSize();
    testIsEmpty();
    testIsFull();

    testSingleItemEnqueue();
    testFiveItemEnqueue();

    testSingleItemDequeue();
    testFiveItemDequeue();

    testSingleItemPeek();
    testFiveItemPeek();

    return 0;
}

