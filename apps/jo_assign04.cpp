#include <iostream>
#include <list>
using namespace std;

class le_rond_point
{
    public:
        int key;
        le_rond_point *next;
        le_rond_point* prev;
};

void jo()
{
    int N;
    int M;

    cout<<"Enter the value of N: ";
    cin>>N;

    cout<<"Enter the value of M: ";
    cin>>M;

    list<le_rond_point> c;
    for (int i = 1; i <= N; i++)
    {
        le_rond_point new_circle;
        new_circle.key = i;
        c.push_back(new_circle);
    }
    

    list<le_rond_point>::iterator current = c.begin();
    cout<<"Order of elimination are: ";
    for(int i = 1; i < N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            ++current;
            if (current == c.end()) current = c.begin();
        }

        cout<<current -> key<<" ";
        list<le_rond_point>::iterator temp = current;
        ++current;
        if (current == c.end()) current = c.begin();
        c.erase(temp);
    }
    
    cout<<endl<<"Winner is: "<<current->key<<endl;
}

int main()
{
    jo();
    return 0;
}