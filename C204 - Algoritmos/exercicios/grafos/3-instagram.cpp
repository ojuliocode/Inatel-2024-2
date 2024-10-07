#include <iostream>
#include <list>
#include <string>

using namespace std;

struct user
{
    int following;
};

int main()
{
    int usersLen;
    string name;

    list<user> adj[1000];

    cin >> usersLen;

    string users[usersLen];

    for (int i = 0; i < usersLen; i++)
    {
        cout << "name" << endl;
        cin.ignore();
        getline(cin, name);
        users[i] = name;
    }

    int a;
    for (int i = 0; i < usersLen; i++)
    {
        a = 0;

        cin >> a;
        while (a != -1)
        {
            adj[i].push_back({a});
            cout << "Follow ?" << endl;
            cin >> a;
        }
    }

    int personToknow;

    cout << "ptonknow" << endl;
    cin >> personToknow;

    list<user>::iterator it;

    for (int i = 0; i < usersLen; i++)
    {
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            if(it->following == personToknow){
                cout << users[i] << endl;
            }
        }
    }
    return 0;
}