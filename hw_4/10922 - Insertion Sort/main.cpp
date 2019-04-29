#include<iostream>

using namespace std;
int InsertionSort(int num, int a[]){
    int cnt = 0;
    for (int i = 1; i < num; ++i){
        for (int j = 0; j < i; ++j){
            if (a[j] > a[i]) {
                cnt++;
                swap(a[j],a[i]);
            }
        }
    }
    return cnt;
}

int main(){
    int n, cnt = 0;
    cin >> n;
    while (--n >= 0){
        int m,i;
        cin >> m;
        int seq[m];
        for (i = 0; i < m; ++i) cin >>seq[i];
        cnt += InsertionSort(m,seq);
    }
    cout << cnt <<endl;
}
