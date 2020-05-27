/* (20 points)
There is an array of transposition of numbers from 0 to N.
Count the Average amounts of BigLeftRotation, BigRightRotation, SmallLeftRotation, SmallRightRotation while inserting an array into AVLTree.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#include "AVLTree.h"

int main()
{
    srand(time(0));
    for (int i = 10; i <= 100; i += 10) {
        AverageAmount(i);
    }
    return 0;
}