#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


#define ll long long

int Reversort( int N, vector<int> table)
{
    int cost = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int j = i;
        for (int k = (i + 1); k < N; k++)
        {
            if (table.at(k) < table.at(j))
            {
                j = k;
            }
        }

        int start = i;
        int end = j;
        while (start < end)
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

    return cost;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int f=0; f<T; f++)
    {

        int N;
        int C; 
        cin >> N >> C;

        if( N == 1)
        {
            cout << "Case #" << (f+1) << ": "<< N << "\n";
            continue;
        }
        else if( N == 2)
        {
            if( C == 2)
            {
                cout << "Case #" << (f+1) << ": "<< 2 << " " << 1 << "\n";
            }
            else if( C == 1)
            {
                cout << "Case #" << (f+1) << ": "<< 1 << " " << 2 << "\n";
            }
            else
            {
                cout << "Case #" << (f+1) << ": "<< "IMPOSSIBLE" << "\n";
            }
            continue;

        }

        if( C == (N-1))
        {   
            cout << "Case #" << (f+1) << ": ";
            for( int i = 0; i < N; i++)
            {
                cout << (i+1) << " ";
            }
            cout << endl;
            continue;
        }


        int Big_Cost = 0;
        int k = 0;
        div_t result_div = div(N, 2);
        
        if( result_div.rem == 0)
        {
            for( int j = 1; j <= result_div.quot; j++)
            {
                Big_Cost += (N-k);
                k += 2;
            }
            Big_Cost += result_div.quot - 1;
        }
        else
        {
            for(int j = 1; j <= result_div.quot; j++)
            {
                Big_Cost += (N-k);
                k += 2;   
            }
            Big_Cost += result_div.quot;
        }

        int Low_Cost = N - 1;
        
        int center = (Big_Cost - Low_Cost)/2;
        bool find = false;

        vector<int> table;
        if( C <= center)
        {
            for(int i = 0; i < N; i++)
            {
                table.push_back( i + 1);
            }
            
            do {
                int cost = Reversort( N, table);
                if( cost == C)
                {
                    find = true;
                    break;
                }

            } while ( next_permutation(table.begin(),table.end()) );
        }
        else
        {
            for( int i = N - 1; i >= 0; i--)
            {
                table.push_back( i + 1);
            }

            do{
                int cost = Reversort( N, table);
                if( cost == C)
                {   
                    find = true;
                    break;
                }
            } while ( prev_permutation(table.begin(),table.end()) );
        }

        if(find == false)
        {
            cout << "Case #" << (f+1) << ": "<< "IMPOSSIBLE" << "\n";
            continue;
        }
        cout << "Case #" << (f+1) << ": ";
        for( int k = 0; k < N; k++)
        {
            cout << table[k] << " ";
        }

        cout << "\n";

        


    }

}
