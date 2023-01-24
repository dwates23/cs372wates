#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
//STL Vector from vectest.cpp, the vector app used for problem 1
class VecTester {
private:
    const int PrintInterval = 10;
    std::vector<int> testVector =  std::vector<int>();
    std::vector<int> vecTest =  std::vector<int>();

    void fillVector(size_t cap) {
        for (int i = 0 ; i < cap; ++i) { testVector[i] = i; }
    }

    //Custom vector filling
    void fillMYVec(size_t cap) {
        for (int i = 0 ; i < cap; ++i) { vecTest[i] = i; }
    }

public:
    void tester() 
    {
        size_t currentCap = testVector.capacity();
	    fillVector(currentCap);
        std::cout << "Starting capacity: " << currentCap << std::endl;
        for (int i = 0; i <= 10000; i++) 
        {
            auto start = std::chrono::steady_clock::now();
            testVector.push_back(i);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elaspedSeconds = end - start;
            int updatedCap = testVector.capacity();
            if (updatedCap != currentCap) 
            {
                std::cout << "For increase capacity to "
                << currentCap
                << " took "
                << elaspedSeconds.count() << " seconds"
                << std::endl;
                currentCap = updatedCap;
            }
                
        }
    }

    void cusTest() 
    {
        size_t curCap = vecTest.capacity();
	    fillVector(curCap);
        std::cout << "Starting capacity: " << curCap << std::endl;
        for (int i = 0; i <= 10000; i++) 
        {
            auto start = std::chrono::steady_clock::now();
            vecTest.push_back(i);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elaspedSeconds = end - start;
            int upCap = vecTest.capacity();
            if (upCap != curCap) 
            {
                std::cout << "For increase capacity to "
                << curCap
                << " took "
                << elaspedSeconds.count() << " seconds"
                << std::endl;
                curCap = upCap;
            }
                
        }
    }

};

// Driver code
int main()
{
    VecTester testingObject;
    std::cout << "Starting STL test: " << std::endl;
    testingObject.tester();
    std::cout << "Starting the other test: " << std::endl;
    testingObject.cusTest();
	return 0;
}
