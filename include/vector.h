#include <iostream>
using namespace std;
template <typename T>
class Vector {
  public:
    void put(T data, int index);
    void push_back(T data);
    T at (int index);
    int size();
    int capacity();
    void traverse();
  private:
  vector() {
    T *arr = new T[1];
    int vCapacity = 1;
    int length = 1;
  }
  vector() {
    delete [] arr;
    arr = nullptr;
  }
}

void push_back(T data)
{
    if (length == vCapacity) {
        expand(2 * vCapacity);
    }
    arr[length] = data;
    lenght++;
}

void expand(int newCapacity) {
    if (newCapacity > vCapacity) {
        T *temp = new T[newCapacity];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        vCapacity = newCapacity;
        arr = temp;
    }
    else {
        std::cerr << "vector::expand: new capacity is less than equal to current\n"
    }
}

void vector::put(T data, int pos) {
    if (index == vCapacity) {
        push_back(T data);
    }
    else {
        arr[index] = data;
    }
}

void traverse() {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
    cout << endl;
}

T &at(int index) {
    if (index < 0 || index > length) {
        cerr << "Vector: index out of bounds on access"
            << endl;
        exit(1);
    }
    else {
        return arr[index];
    }
}
int size() {
    return length;
}
int capacity()
{
    return vCapacity;
}