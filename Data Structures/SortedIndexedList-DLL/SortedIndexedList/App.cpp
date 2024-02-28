#include <iostream>
#include "SortedIndexedList.h"
#include "ShortTest.h"
#include "ExtendedTest.h"

int main(){
    test_remove();
    testAll();
    testAllExtended();
    std::cout<<"Finished IL Tests!"<<std::endl;


	system("pause");
}