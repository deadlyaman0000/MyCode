#include <iostream>
#include <vector> //header file for vector

using namespace std;

int main()
{
    // vector initaialisation

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    // printing values
    // using loop

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << endl
         << endl;
    // using iterator
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
    }
    cout << endl
         << endl;

    // using auto
    // element == first element of v
    // auto automatically decide data type of vector

    for (auto element : v)
    {
        cout << element << endl;
    }
    cout << endl;
    // pop_back is used to pop end element of vector

    v.pop_back();
    cout << "pop" << endl;
    for (auto element : v)
    {
        cout << element << endl;
    }

    cout << "vector2 " << endl;

    vector<int> v2(3, 50);
    for (auto element : v2)
    {
        cout << element << " ";
    }
    cout << endl;
    // swap
    cout << "swapping v and v2" << endl;

    swap(v, v2);

    for (auto element : v)
    {
        cout << element << " ";
    }

    for (auto element : v2)
    {
        cout << element << " ";
    }

    return 0;
}