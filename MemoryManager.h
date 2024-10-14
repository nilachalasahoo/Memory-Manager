#include"List.h"
#include<windows.h>
#include<vector>
class MemoryManager{
    private:
        void *parent_memory;
        size_t total_byte;
        size_t free_byte;
        List page_list;
    public:
        MemoryManager(size_t size);
        void* allocate(size_t size);
        void deallocate(void* pointer);
        bool isMemoryLeak();
        void deallocateAll();
        void display();
        ~MemoryManager();
};
