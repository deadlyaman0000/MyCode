#include <iostream>
#include <stack>
using namespace std;


class queue
{


    stack<int> s1;
    stack<int> s2;

    // push
public:
    void push(int x)
    {
        s1.push(x); //stl stack   
    }
    // pop
    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "No element to pop " << endl;
            return -1;
        }
        else 
        {
            if(s2.empty()) {       //check if s2 is also empty or not
            while (!s1.empty())
            {
                s2.push(s1.top()); // pushing stack 1 value in stack 2
                s1.pop();
            }
            }
            int topVal  = s2.top(); //store top value before pop
            s2.pop(); // popping element
            return topVal;
        
        }
    }

    // empty
    bool empty()
    {
        if (s1.empty() && s2.empty())
        {

            return true;
        }
        return false;
    }
    //no need to write peek because we have 2 stacks 

};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty())
    {
       cout <<  q.pop() <<endl ;
    }

    cout << endl;
    q.pop();
    cout << q.empty();

    return 0;
}