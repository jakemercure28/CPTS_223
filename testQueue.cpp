//
// Created by jake on 2/21/21.
//
#include "testQueue.h"
#include "queue.h"

/* TEST ID: Size queue check queue.h
 * Unit: queue::size()
 * Description: test to determine if queue::size() returns count + 1 = n
 * Test steps:
 *  1. Construct a queue object of size 5
 *  2. Invoke queue::size()
 *  3. Conditionally evaluate the value returned by queue::size()
 * Test data: size = 5
 * Precondition queue object is size 5
 * Postcondition queue object is still size 5
 * Expected result: queue is size 5; 5 is returned
 *  Actual result: 1
 *  Status: failed
 */
void testSize(){

    queue q1(5);

    cout << "Checking size... precondition size = 5\n";

    if(q1.size() == 5)
        cout << "Result: " << q1.size() << "\nTest passed.\n";
    else
        cout << "Result: " << q1.size() << "\nTest failed.\n";
}

void testIsEmpty(){

}