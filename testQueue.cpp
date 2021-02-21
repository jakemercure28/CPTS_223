//
// Created by jake on 2/21/21.
//
#include "testQueue.h"
#include "queue.h"



/* TEST ID: Size queue check - SQC
 * Unit: queue::size()
 * Description: test to determine if queue::size() returns count of enqueued values
 * Test steps:
 *  1. Construct a queue object of size 5
 *  2. enqueue 5 values
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

    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(1);

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

    cout << "Checking if empty... precondition size = 0\n";

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

    cout << "Checking if full... precondition size = 5\n";

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

/* TEST ID: Single item enqueue - SIE
 * Unit: queue::enqueue()
 * Description: test to determine if queue::size() returns 1 after adding 1 item
 *  test to determine if queue.isEmpty() returns false after adding 1 item.
 * Test steps:
 *  1. Construct a queue object of size 5
 *  2. enqueue 1 item to the queue
 *  3. Invoke queue::size(), queue::isEmpty
 *  4. Conditionally evaluate the value returned by queue::size() and queue::isEmpty()
 * Test data: size = 5
 * Precondition queue object is empty
 * Postcondition queue object contains 1 item
 * Expected result: queue size is 1; 1 is returned. queue is not empty; 0 is returned
 *  Actual result: size is 0, 0 is returned. queue is not empty; 0 is returned
 *  Status: failed
 */

void testSingleItemEnqueue(){

    queue q1(5);

    cout << "Checking single item enqueue()... precondition size = 5\n";

    cout << "Enqueuing 1 test value...\n";
    q1.enqueue(2);

    if(q1.size() == 1)
        cout << "Size result: " << q1.size() << "\nTest passed.\n";
    else
        cout << "Size result: " << q1.size() << "\nTest failed.\n";

    if(!q1.isEmpty())
        cout << "isEmpty() result: " << q1.isEmpty() << "\nTest passed.\n";
    else
        cout << "isEmpty() result: " << q1.isEmpty() << "\nTest failed.\n";

}

/* TEST ID: five item enqueue - FIE
 * Unit: queue::enqueue()
 * Description: test to determine if queue::size() returns 5 after adding 5 items
 *  test to determine if queue.isEmpty() returns false after adding 5 item.
 * Test steps:
 *  1. Construct a queue object of size 5
 *  2. enqueue 5 item to the queue
 *  3. Invoke queue::size(), queue::isEmpty
 *  4. Conditionally evaluate the value returned by queue::size() and queue::isEmpty()
 * Test data: size = 5
 * Precondition queue object is empty
 * Postcondition queue object contains 5 items
 * Expected result: queue size is 5; 5 is returned. queue is not empty; 0 is returned
 *  Actual result: size is 5, 5 is returned. queue is not empty; 0 is returned
 *  Status: failed
 */

void testFiveItemEnqueue(){

    queue q1(5);

    cout << "Checking single item enqueue()... precondition size = 5\n";

    cout << "Enqueuing 5 test values...\n";
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);

    if(q1.size() == 5)
        cout << "Size result: " << q1.size() << "\nTest passed.\n";
    else
        cout << "Size result: " << q1.size() << "\nTest failed.\n";

    if(!q1.isEmpty())
        cout << "isEmpty() result: " << q1.isEmpty() << "\nTest passed.\n";
    else
        cout << "isEmpty() result: " << q1.isEmpty() << "\nTest failed.\n";

}

/* TEST ID: single item dequeue - SID
 * Unit: queue::dequeue()
 * Description: test to determine if queue::
 *  test to determine if queue.isEmpty() returns true after enqueuing then dequeuing 1 item.
 * Test steps:
 *  1. Construct a queue object of size 5
 *  2. enqueue 1 item to the queue
 *  3. dequeue 1 item from the queue
 *  4. Conditionally evaluate the value returned by queue::size() and queue::isEmpty()
 * Test data: size = 5
 * Precondition queue object is empty
 * Postcondition queue object is empty
 * Expected result: queue is empty; 1 is returned
 *  Actual result: queue is not empty; 0 is returned
 *  Status: failed
 */
void testSingleItemDequeue(){
    queue q1(1);

    cout << "Checking single item dequeue()... precondition size = 5\n";

    cout << "Enqueuing single test value...\n";
    q1.enqueue(2);
    q1.dequeue();

    if(q1.isEmpty())
        cout << "isEmpty() result: " << q1.isEmpty() << "\nTest passed.\n";
    else
        cout << "isEmpty() result: " << q1.isEmpty() << "\nTest failed.\n";

}

/* TEST ID: five item dequeue - FID
* Unit: queue::dequeue()
* Description: test to determine if queue::size() < 5 after
 * adding 5 items to the queue and removing 3 items from the queue.
* Test steps:
*  1. Construct a queue object of size 5
*  2. enqueue 5 items to the queue
*  3. dequeue 3 items from the queue
*  4. Invoke queue::size()
*  5. Conditionally evaluate the value returned by queue::size()
* Test data: size = 5
* Precondition queue object is empty
* Postcondition queue object contains < 5 items
* Expected result: queue size is < 5
* Actual result: size is 3; 3 is returned
* Status: passed
*/

void testFiveItemDequeue(){

    queue q1(5);

    cout << "Checking single item enqueue()... precondition size = 5\n";

    cout << "Enqueuing 5 test values...\n";
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    if(q1.size() < 5)
        cout << "Size result: " << q1.size() << "\nTest passed.\n";
    else
        cout << "Size result: " << q1.size() << "\nTest failed.\n";

}

/* TEST ID: peek single item test - PSIT
* Unit: queue::peek()
* Description: test to determine if queue::peek()
* returns 8 after enqueuing 8 to the queue.
* Test steps:
*  1. Construct a queue object of size 5
*  2. Enqueue 1 item to the queue
*  3. Invoke queue::peek()
*  4. Conditionally evaluate the value returned by queue::peek()
* Test data: size = 5, value is 8
* Precondition queue object is empty
* Postcondition queue object contains 1 item of value 8
* Expected result: peek returns 8
* Actual result: peek returns 1
* Status: failed
*/

void testSingleItemPeek(){

    queue q1(5);
    cout << "Checking peek()... precondition size = 5, value is 8\n";

    cout << "Enqueuing test value...\n";
    q1.enqueue(8);

    if(q1.peek() == 8)
        cout << "Peek result: " << q1.peek() << "\nTest passed.\n";
    else
        cout << "Peek result: " << q1.peek() << "\nTest failed.\n";

}

/* TEST ID: peek five item test - PFIT
* Unit: queue::peek()
* Description: test to determine if queue::peek()
* returns 1 after enqueuing 1,2,3,4,5 to the queue.
* Test steps:
*  1. Construct a queue object of size 5
*  2. Enqueue 5 items to the queue
*  3. Invoke queue::peek()
*  4. Conditionally evaluate the value returned by queue::peek()
* Test data: size = 5, values are 1,2,3,4,5
* Precondition queue object is empty
* Postcondition queue object contains 1,2,3,4,5
* Expected result: peek returns 1
* Actual result: peek returns 5
* Status: failed
*/

void testFiveItemPeek(){

    queue q1(5);
    cout << "Checking peek()... precondition size = 5, values are 1,2,3,4,5\n";

    cout << "Enqueuing test values...\n";
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);


    if(q1.peek() == 1)
        cout << "Peek result: " << q1.peek() << "\nTest passed.\n";
    else
        cout << "Peek result: " << q1.peek() << "\nTest failed.\n";

}
