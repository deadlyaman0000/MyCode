#include <iostream>
#include <deque>
using namespace std;

int main()
{

    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(5); // pushed in front

    for (auto ele : dq)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "size of dq :" << dq.size(); cout << endl;
    dq.pop_back();
    dq.pop_front();
    for (auto ele : dq)
    {
        cout << ele << " ";
    }
    cout << endl;
    cout << "size of dq :" << dq.size();
    return 0;
}