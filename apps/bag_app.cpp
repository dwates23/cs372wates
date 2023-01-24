//This is a simple program that pulls 20 numbers out of a bag and displays them.
#include<iostream>
using namespace std;

class Bag
{
	private:
		int numbers[20];
		int numCount;

	public:
		Bag();		
		void display();
};

Bag::Bag()
{
}

void Bag::display()
{
	int i;
	int size = sizeof(numbers)/sizeof(numbers[0]);
	for(i=0;i<size;i++)
	cout<<numbers[i]<<endl;
}

int main()
{
	Bag ob;
	ob.display();
	return 0;
}