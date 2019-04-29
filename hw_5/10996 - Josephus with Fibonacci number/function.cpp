#include <iostream>
#include "function.h"
using namespace std;

Josephus::~Josephus(){
    delete head;
}
Josephus::Josephus(const int &num){
    this->generateFib(num);
    noOfPeople = num;
    int index = 1;
    head = new Node;
    head->next = nullptr;
    head->number = index++;
    Node *pre = head;
    while (index <= num){
        Node *cur = new Node;
        cur->number = index++;
        pre->next = cur;
        pre = cur;
    }
    pre->next = head;
}
int Josephus::kill(){ // return the survival's position
    int i = 0;
    Node *cur = head, *pre = head;
    while (pre->next != head) pre =pre->next;
    while ( noOfPeople > 1 ) {
        int m;
        if (sequence[i]%noOfPeople == 0) m = noOfPeople;
        else m = sequence[i]%noOfPeople;
        for (int j = 1; j < m; ++j) {
            pre = pre->next;
            cur = cur->next;
        }
        Node *temp = cur;
        pre->next = cur->next;
        cur = cur->next;
        i++;
        noOfPeople--;
        //delete temp; if add this will runtime error but i don't know why
    }
    return cur->number;
}
void Josephus::generateFib(const int &num){ // generate a Fibonacci sequence table
    sequence[0] = 1;
    sequence[1] = 1;
    for (int i = 2; i < num ; ++i)
        sequence[i] = sequence[i-1] + sequence[i-2];
}
