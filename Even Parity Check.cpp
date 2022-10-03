#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long array[4][8];
    for(long long i = 0; i < 4; i ++) {
        for(long long j = 0; j < 8; j ++) {
            cin>> array[i][j];
        }
    }
    cout<<endl;

    for(long long i = 0; i < 4; i ++) {
        long long count = 0;
        for(long long j = 0; j < 8; j ++) {
            count += array[i][j];
            cout<< array[i][j] << ' ';
        }
        cout<< "| " << count % 2 << endl;
    }
    for(long long i = 0; i < 15; i ++) cout<< '-'; cout<< endl;
    for(long long i = 0; i < 8; i ++) {
        long long count = 0;
        for(long long j = 0; j < 4; j ++) {
            count += array[j][i];
        }
        cout<< count % 2 << ' ';
    }
    cout<< endl;

}

