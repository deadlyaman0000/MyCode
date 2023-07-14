#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

    // str = my name is aman and i am aman

    unordered_map<string, int> m;

    // insertion
    // create pair then insert it in map
    pair<string, int> pair1 = make_pair("aman", 2);
    m.insert(pair1);

    // 2
    pair<string, int> pair2("name", 1);
    m.insert(pair2);
     

    // 3
    m["my"] = 1;

    // searching
    cout << m["name"] << endl;
    cout << m.at("aman") << endl;

    // access not created entry

    // cout<<m.at("unknown") <<endl ;
    cout << m["unknown"] << endl; // it create entry for unknown key i.e. 0 ;

    cout << m.at("unknown") << endl;

    cout << "size of  m : " << m.size() << endl;

    // element is present or not

    cout << "presence of bro :  " << m.count("bro") << endl;  // if absent print 0
    cout << "presence of name : " << m.count("name") << endl; // present print 1

    // erase
    cout << "check my before erase : " << m.count("my") << endl;
    m.erase("my");
    cout << "check my after erase : " << m.count("my") << endl; // erased
    cout << "size after erase " << m.size() << endl;

    // traverse map
    // using auto
    cout <<"traversing map through auto " <<endl ;
    
    for (auto i : m)
    {
        cout << i.first << i.second  <<endl ;
    }

    // using itreator
    cout <<"traversing map through itearator" <<endl ;

    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    //unorder print element according to bst property
    //map print element according to their insertion order

    return 0;
}