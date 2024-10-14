#include"Memory.h"
Memory::Memory(void *pointer,size_t size,bool isFree){
    this->pointer=pointer;
    this->size=size;
    this->isFree=isFree;
    prev=nullptr;
    next=nullptr;
}
Memory::~Memory(){
    delete pointer;
}