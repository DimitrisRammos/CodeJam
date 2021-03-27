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

        int X;
        int Y;
        cin >> X >> Y;
        
        string mural;
        cin >> mural;
        int cost = 0;

        int size = mural.length();
        int previous;
        
        if( size < 1)
        {
            cout << "Case #" << (f+1) << ": "<< cost << "\n";
            continue;
        }
        int i = 0;
        while( i < size)
        {   
            
            if( mural[i] != '?')
            {
                if( i > 0)
                {
                    if( mural[i] == 'C' && mural[previous] == 'J')
                    {
                        cost = cost + Y;
                    }
                    else if( mural[i] == 'J' && mural[previous] == 'C')
                    {
                        cost = cost + X;
                    }
                }
                previous = i;
            }
            else
            {   
                bool stop1 = false;
                if( i == size - 1)
                {
                    break;
                }
                else if (i == 0)
                {
                    while( mural[i] == '?')
                    {
                        i++;
                        if( i == size)
                        {
                            stop1 = true;
                            break;
                        }
                    }
                    if( stop1 == true)break;
                    previous = i;
                }
                else
                {   
                    char previous_char = mural[previous];

                    while(mural[i] == '?')
                    {
                        i++;
                        if( i == size)
                        {
                            stop1 = true;
                            break;
                        }
                    }
                    if( stop1 == true)break;
                    
                    char next_char = mural[i];

                    if(previous_char != next_char)
                    {
                        if( previous_char == 'J' && next_char == 'C')
                        {
                            cost = cost + Y;
                        }
                        else
                        {
                            cost = cost + X;
                        }
                    }
                    previous = i;
                }
            }

            i++;
        }
    
        
   
        cout << "Case #" << (f+1) << ": "<< cost << "\n";
    }
}