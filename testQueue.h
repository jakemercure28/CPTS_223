//
// Created by jake on 2/21/21.
//

#ifndef CPTS_223_TESTQUEUE_H
#define CPTS_223_TESTQUEUE_H

#include <iostream>
using namespace std;

void testSize();
void testIsEmpty();
void testIsFull();

/* TEST ID: Size queue check - SQC
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

/* TEST ID: Empty queue check - EQC
 * Unit: queue::isEmpty()
 * Description: test to determine if queue::isEmpty() returns 1
 * if a queue object is empty
 * Test steps:
 *  1. Construct an empty queue object
 *  2. Invoke queue::isEmpty()
 *  3. Conditionally evaluate the value returned by queue::isEmpty()
 * Test data: size = 0
 * Precondition queue object is empty
 * Postcondition queue object is still empty
 * Expected result: queue is empty; 1 is returned
 *  Actual result: queue is not empty; 0 is returned
 *  Status: failed
 */
void testIsEmpty(){

    queue q1(0);

    cout << "Checking size... precondition size = 0\n";

    if(q1.isEmpty())
        cout << "Result: " << q1.isEmpty() << "\nTest passed.\n";
    else
        cout << "Result: " << q1.isEmpty() << "\nTest failed.\n";
}

/* TEST ID: Full queue check - FQC
 * Unit: queue::isFull()
 * Description: test to determine if queue::isFull() returns 1
 * if a queue object is full
 * Test steps:
 *  1. Construct a queue object of size 5
 *  2. add 5 nodes to the queue
 *  3. Invoke queue::isFull()
 *  4. Conditionally evaluate the value returned by queue::isFull()
 * Test data: size = 5
 * Precondition queue object is empty
 * Postcondition queue object is still full
 * Expected result: queue is full; 1 is returned
 *  Actual result: queue is full; 1 is returned
 *  Status: passed
 */

void testIsFull(){

    queue q1(5);

    cout << "Checking ifFull()... precondition size = 5\n";

    cout << "Enqueuing 5 test values...\n";
    q1.enqueue(1);
    q1.enqueue(6);
    q1.enqueue(3);
    q1.enqueue(8);
    q1.enqueue(2);

    if(q1.isFull())
        cout << "Result: " << q1.isFull() << "\nTest passed.\n";
    else
        cout << "Result: " << q1.isFull() << "\nTest failed.\n";
}

#endif //CPTS_223_TESTQUEUE_H
