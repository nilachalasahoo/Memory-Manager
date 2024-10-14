#include"List.h"
List::List(){
    head=nullptr;
    total_size=0;
}
List::List(Memory *m){
    head=m;
    total_size=1;
}
void List::add(Memory *m1,Memory *m2){
    m2->next=m1->next;
    m1->next=m2;
    m2->prev=m1;
    if(m2->next)
        m2->next->prev=m2;
    total_size++;
}
void List::merger(Memory *m){
    if(m->next && m->next->isFree){
        m->size+=m->next->size;
        m->next=m->next->next;
        if(m->next)
            m->next->prev=m;
        total_size--;
    }
    if(m->prev && m->prev->isFree){
        m->prev->size+=m->size;
        m->prev->next=m->next;
        if(m->next)
            m->next->prev=m->prev;
        total_size--;
    }
}
Memory* List::operator[](int i){
    Memory *curr=head;
    while(i>0){
        curr=curr->next;
        i--;
    }
    return curr;
}
void List::display(){
    std::cout<<std::endl<<"Location\tSize\tIsFree"<<std::endl;
    Memory *curr=head;
    while(curr){
        std::cout<<curr->pointer<<"\t"<<curr->size<<"\t"<<curr->isFree<<std::endl;
        curr=curr->next;
    }
}
int List::size(){
    return total_size;
}
List::~List(){
    delete head;
}