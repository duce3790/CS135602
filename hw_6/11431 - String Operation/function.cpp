#include"function.h"

Str::Str(char* s){
    head = new Char(s[0]);
    int index = 1;
    for (tail = head; s[index] != '\0'; index++){
        tail->next = new Char(s[index]);
        tail = tail->next;
    }
}
Str::Str(const Str &s){
    head = new Char(s.head->text);
    Char *cur = s.head->next;
    for(tail = head; cur != nullptr && cur->text != '\0'; cur = cur->next){
        tail->next = new Char(cur->text);
        tail = tail->next;
    }
}

bool Str::operator==( const Str &s) const{
    Char *a = this->head;
    Char *b = s.head;
    for (; a != nullptr && b!= nullptr; a = a->next, b = b->next){
        if (a->text != b->text) return false;
        if ((a->next == nullptr && b->next != nullptr) ||
            (a->next != nullptr && b->next == nullptr)) return false;
    }
    return true;
}
