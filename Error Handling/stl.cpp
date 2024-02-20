#include <iostream>
#include<list>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

void display_list(list<int>::iterator& it, list<int>& l)
{
    it = l.begin();

    while (it != l.end())
    {
        cout << *it << " ";
        it++;
    }
}
int main()
{
    cout << "Hello World!\n";
    list<int> intlist;
    intlist.push_back(2);
    intlist.push_back(1);
    intlist.push_back(6);
    intlist.push_back(3);

    list<int>::iterator it;
    it = intlist.begin();
    cout << *it << endl;
    int i = 0;
    while (i < size(intlist))
    {
        cout << *it << " ";
        it++;
        i++;
    }
    intlist.emplace_back(10);
    i = 0;
    cout << endl;
    it = intlist.begin();
    while (i < size(intlist))
    {
        cout << *it << " ";
        it++;
        i++;
    }
    cout << "\ndisplay list\n";
    display_list(it, intlist);
    cout << "\n\n";

    cout << "Vectors\n";
    vector<string> vecs;
    vecs.push_back("first");
    vecs.push_back("second");
    vecs.push_back("third");
    vecs.push_back("fourth");
    vector<string>::iterator vs;
    vs = vecs.begin();
    while (vs != vecs.end())
    {
        cout << *vs << " ";
        vs++;
    }
    cout << endl;
    vecs.emplace_back("five");
    vs = vecs.begin() + 2;
    while (vs != vecs.end())
    {
        cout << *vs << " ";
        vs++;
    }
    return 0;
}

