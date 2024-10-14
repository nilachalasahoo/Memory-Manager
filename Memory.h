#include<iostream>
class Memory{
    public:
        void *pointer;
        size_t size;
        bool isFree;
        Memory *prev;
        Memory *next;
        Memory(void *pointer,size_t size,bool isFree);
        ~Memory();
};
