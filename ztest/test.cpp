#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string> &bank)
{
    map<int, int> mp;
    int count;
    for (int i = 0; i < bank.size(); i++)
    {
        count = 0;
        for (int j = 0; j < bank[i].size(); j++)
        {
            if (bank[i][j] == '1')
            {
                count++;
            }
        }
        mp[i] = count;
    }
    for(auto x:mp){
        cout <<x.first<<"->"<< x.second << " ";
    }
    cout << endl << endl;
    count = 0;
    int i = 0, j = 0;
    while (i < bank.size() - 1)
    {
        if (mp[i] <= 0){
            i++;
            continue;
        }
        else
        {
            j = i + 1;
            while (mp[j] <= 0 && j < bank.size())
                j++;
            if (j == bank.size())
                break;
            count += (mp[i] * mp[j]);
            cout << count << " " << i << endl;
            i = j - 1;
        }
        i++;
    }
    return count;
}

int main()
{

    vector<string> travel = {"00000","00101","10100","11110","11100","01001","00100","11010"};

    cout << numberOfBeams(travel);
    return 0;
}