#include <bits/stdc++.h>
using namespace std;

// class Trie
class Trie
{
public:
    // class Node
    class Node
    {
    public:
        Node *next[26];
        bool end;
        Node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };

    Node *trie;

    Trie()
    {
        trie = new Node(); // root
    }

    // insert in Trie
    void insert(string word)
    {

        Node *it = trie; // root pointer for itration
        for (int i = 0; i < word.size(); i++)
        {
            if (it->next[word[i] - 'a'] == NULL) // word not exist then create new refrence
            {
                it->next[word[i] - 'a'] = new Node();
            }
            it = it->next[word[i] - 'a'];
        }
        it->end = true;
    }

    // searching in Trie
    bool search(string word)
    {
        Node *it = trie;
        for (int i = 0; i < word.size(); i++)
        {
            if (it->next[word[i] - 'a'] == NULL) // word not exist then create new refrence
            {
                return false;
            }
            it = it->next[word[i] - 'a'];
        }

        return it->end; // if it->end is true then word exist and return true if not then return false
    }

    // start with
    bool startWith(string word)
    {
        Node *it = trie;
        for (int i = 0; i < word.size(); i++)
        {
            if (it->next[word[i] - 'a'] == NULL) // if  refrence is null then return false
            {
                return false;
            }
            it = it->next[word[i] - 'a'];
        }

        return true;
    }
};

int main()
{

    Trie *myTrie = new Trie();
    myTrie->insert("apple");
    cout << endl;
    myTrie->insert("ape");

    cout << endl;
    myTrie->insert("aman");
    cout << endl;
    cout << "search aman  " << myTrie->search("aman");
    cout << endl;
    cout << "search eman  " << myTrie->search("eman");
    cout << endl;

    cout << "start with am " << myTrie->startWith("aman");
    cout << endl;
    cout << "start with o " << myTrie->startWith("o");
    cout << endl;

    return 0;
}