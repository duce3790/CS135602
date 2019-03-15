#include <stdio.h>

int coin[5];
int amount[5] = {0};
int cn;  //coin number

void show();
void change(int ,int);

int main(){
    int money,i;
    scanf("%d",&cn);
    for(i = 0; i < cn; i++) scanf("%d",&coin[i]);
    scanf("%d",&money);

    change(money,0);

    return 0;
}

void show(){
    int i;
    printf("(%d",amount[0]);
    for(i = 1; i < cn; i++) printf(",%d",amount[i]);
    printf(")\n");
}

void change(int money, int current){
    if(money == 0) show();
    else if(current < cn && money > 0){
        change(money,current+1);
        amount[current]++;
        change(money - coin[current],current);
        amount[current]--;
    }
}
