#include"Memory.h"
class List{
    private:
        Memory *head;
        int total_size;
    public:
    List();
    List(Memory *m);
    void add(Memory *m1,Memory *m2);
    void merger(Memory *m);
    Memory* operator[](int i);
    void display();
    int size();
    ~List();
};
