#include"MemoryManager.h"
MemoryManager::MemoryManager(size_t size){
    parent_memory=VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if(parent_memory==NULL){
        std::cout<<"Memory Allocation Failed"<<std::endl;
        exit(1);
    }
    total_byte=size;
    free_byte=size;
    Memory *m=new Memory(parent_memory,size,true);
    page_list=List(m);
}
void* MemoryManager::allocate(size_t size){
    if(size>free_byte){
        std::cout<<"Can't allocate memory sucessfully"<<std::endl;
        return nullptr;
    }
    for(int i=0;i<page_list.size();i++){
        Memory *m=page_list[i];
        if(m->isFree && m->size>=size){
            free_byte=free_byte-size;
            m->isFree=false;
            if(m->size>size){
                Memory *new_m=new Memory(reinterpret_cast<char*>(m->pointer)+size,m->size-size,true);
                m->size=size;
                page_list.add(m,new_m);
            }
            return m->pointer;
        }
    }
    std::cout<<"Can't allocate memory sucessfully"<<std::endl;
    return nullptr;
}
void MemoryManager::deallocate(void* pointer){
    if(pointer==nullptr){
        std::cout<<"Null Pointer can't be deallocated"<<std::endl;
        return;
    }
    for(int i=0;i<page_list.size();i++){
        Memory *m=page_list[i];
        if(m->pointer==pointer){
            m->isFree=true;
            free_byte=free_byte+m->size;
            page_list.merger(m);
            std::cout<<"Memory De-allocation Sucessful"<<std::endl;
            return;
        }
    }
    std::cout<<"Memory De-allocation Failed"<<std::endl;
}
bool MemoryManager::isMemoryLeak(){
    return total_byte!=free_byte;
}
void MemoryManager::deallocateAll(){
    free_byte=total_byte;
    Memory *m=new Memory(parent_memory,total_byte,true);
    page_list=List(m);
}
void MemoryManager::display(){
    page_list.display();
    std::cout<<std::endl;
}
MemoryManager::~MemoryManager(){
    if (!VirtualFree(parent_memory, 0, MEM_RELEASE)) {
        std::cerr << "VirtualFree failed with error: " << GetLastError() << std::endl;
    }
}

