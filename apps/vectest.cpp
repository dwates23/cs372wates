#include <vector>
#include <chrono>
#include <iostream>


class VecTester {
private:
    const int PrintInterval = 10;
    std::vector<int> testVector =  std::vector<int>();
    
    void fillVector(size_t cap) {
        for (int i = 0 ; i < cap; ++i) { testVector[i] = i; }
    }
public:
    void tester() {
        size_t currentCap = testVector.capacity();
	    fillVector(currentCap);
        std::cout << "Starting capacity: " << currentCap << std::endl;
        for (int i = 0; i <= 10000; i++) {
            auto start = std::chrono::steady_clock::now();
            testVector.push_back(i);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elaspedSeconds = end - start;
            int updatedCap = testVector.capacity();
            if (updatedCap != currentCap) {
                std::cout << "For increase capacity to "
                << currentCap
                << " took "
                << elaspedSeconds.count() << " seconds"
                << std::endl;
                currentCap = updatedCap;
            }
                
        }
    }
};

int main() {
    VecTester testingObject;
    std::cout << "Starting test: " << std::endl;
    testingObject.tester();
    return 0;
}