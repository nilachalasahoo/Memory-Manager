#include"MemoryManager.h"
int main() {
    MemoryManager m(1);
    std::cout<<m.isMemoryLeak()<<std::endl;
    m.display();
    int* v1=reinterpret_cast<int*>(m.allocate(100));
    m.deallocate(v1);
    void* v4;
    m.deallocate(v4);
    m.display();
    int* v2=reinterpret_cast<int*>(m.allocate(200));
    m.display();
    void* v3=m.allocate(300);
    m.display();
    m.allocate(500);
    m.display();
    m.deallocate(v2);
    m.display();
    m.deallocate(v3);
    m.display();
    m.allocate(500);
    m.display();
    std::cout<<m.isMemoryLeak()<<std::endl;
    m.deallocateAll();
    m.display();
    std::cout<<m.isMemoryLeak()<<std::endl;    
    return 0;
}