#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    string s;
    cin >> s;

    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int flag = 0;

    for (auto it : mp)
    {
        if (it.second % 2 != 0 && flag != 0)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        else if (it.second % 2 != 0)
        {
            flag = 1;
        }
    }
    string left = "";
    string middle = "";
    for (auto it : mp)
    {

        if (it.second % 2 != 0)
        {
            middle += it.first;
        }

        left += string(it.second / 2, it.first);
    }
    string right = ""; 
    right = left ;
    reverse(right.begin(), right.end());
    cout << left + middle + right << endl;

    return 0;
}

