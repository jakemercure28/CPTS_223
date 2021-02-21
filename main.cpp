// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

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

