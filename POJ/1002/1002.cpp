#include "iostream"
#include "string.h"
#include "stdlib.h"
using namespace std;

char  getNum(char c) {

    if(c <='9' && c>='0')
        return c;

    if(c == 'R' || c == 'S')
        return 7 + '0';
    else if(c == 'T' || c == 'U' || c == 'V')
        return 8 + '0';
    else if (c == 'X' || c == 'Y' || c == 'W')
        return 9 + '0';
    else
        return (c - ';') / 3 + '0';
}


int main() {
    int n;

    cin >>n;
    int N = n;
    char ** num = new char*[n];
    //string * num = new string [n];
    while(n--) {
        num[n] = new char [8];
        char * str = new char [255];
        cin >> str;
        int count = 0;
        for(int i=0; i<strlen(str); i++) {
            if(count == 3)
                num[n][count++] = '-';
            if(str[i] == '-')
                continue;
            else
                num[n][count++] = getNum(str[i]);
        }
    }

    n = N;
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++) {
            if(strcmp(num[j], num[j+1]) >0) {
                char * tmp;
                tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
    }

    int count = 1;
    bool flag = false;
    for(int i=1; i<n; i++) {
        if( strcmp(num[i], num[i-1])==0)
            count ++;
        else {
            if(count > 1 ) {
                cout << num[i-1] << " " << count << endl;
                flag = true;
                count = 1;
            }
        }
    }

    if(count > 1) {
        cout  << num[n-1] << " "  << count << endl;
        flag = true;
    }
    if(!flag)
        cout << "No duplicates." <<endl;
}

