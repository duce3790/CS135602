#include <bits/stdc++.h>
#include "function.h"
using namespace std;
int main(){
    #ifndef ONLINE_JUDEGE
    //freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDEGE
	int numofpeople;

	while(cin>>numofpeople){
        //cout << "cin " << numofpeople <<endl;
		Josephus Jose(numofpeople);
		int survival = Jose.kill();
		cout<<survival<<endl;
    }
}
