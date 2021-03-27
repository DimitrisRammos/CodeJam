#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


#define ll long long

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;


    for(int f=0; f<T; f++)
    {

        int N; 
        cin >> N;

        vector<int> table;
        for( int i = 0; i < N; i++)
        {   
            int num;
            cin >> num;
            table.push_back(num);
        }

        int cost = 0;
        
        for( int i = 0; i < N-1; i++)
        {
            int j = i;
            for( int k = (i + 1); k < N; k++)
            {
                if( table.at(k) < table.at(j) )
                {   
                    j = k;
                }
            }

            int start = i;
            int end = j;
            while( start < end)
            {    

                int v1 = table.at(start);
                int v2 = table.at(end);

                table[start] = v2;
                table[end] = v1;
                start++;
                end--; 
            }

            cost = cost + j - i + 1;

        }
        
   
        cout << "Case #" << (f+1) << ": "<< cost << "\n";
    }
}