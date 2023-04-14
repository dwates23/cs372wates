#include <iostream>
using namespace std;

bool bears(int initial, int fin, int n, int a = 5, int b = 2) 
{
    if (initial == fin) 
    {
        return true;
    }
    else if (n == 0) 
    {
        return false;
    }
    else 
    {
        if (initial % 2 == 0) 
        {
            return bears(initial/2, fin, n-1, a, b) || bears(initial-a, fin, n-1, a, b);
        }
        else 
        {
            return bears(initial-1, fin, n-1, a, b) && bears(initial*b, fin, n-1, a, b);
        }
    }
}

int main() 
{
    cout << bears(42, 42, 0) << std::endl;
    cout << bears(10, 42, 3) << std::endl;
    cout << bears(10, 42, 2) << std::endl;
    cout << bears(99, 100, 2) << std::endl;
    cout << bears(250, 125, 5) << std::endl; 
    return 0;
}
