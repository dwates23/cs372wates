#include <iostream>
using namespace std;
template <typename T>
class Vector {
  public:
  
    typedef T* iterator;
    Vector() : arr(new T[1]), vCapacity(1), length(0) {}
    Vector() {
    delete [] arr;
    arr = nullptr;
    }

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

template <typename T>
void Vector <T>::push_back(T data)
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

template <typename T>
void Vector<T>::put(T data, int pos) {
    if (index == vCapacity) {
        push_back(T data);
    }
    else {
        arr[index] = data;
    }
}

template <typename T>
void Vector<T>::traverse() {
    for (int iterator it = begin(); it != end(); ++i) {
        cout << *it << endl;
    }
    cout << endl;
}

template <typename T>
T& Vector<T>::at(int index) {
    if (index < 0 || index >= length) {
        cerr << "Vector: index out of bounds on access"
            << endl;
        exit(1);
    }
    else {
        return arr[index];
    }
}

template <typename T>
int Vector<T>::size() {
    return length;
}

template <typename T>
int Vector<T>::capacity()
{
    return vCapacity;
}