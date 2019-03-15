#include <iostream>
#include <stdio.h>

using namespace std;

int prefix();

int main()
{
    cout << prefix();
    return 0;
}

int prefix(){
    char c;
    while( cin>>c && c != '0'){
        if( c == '+')
            return prefix() + prefix();
        else if( c == '-')
            return prefix() - prefix();
        else if(isdigit(c)){
            int num;
            ungetc(c, stdin);
            cin>>num;  // ·Ø©v¯uªºÁo©ú
            return num;
        }
    }
    return 0;
}
