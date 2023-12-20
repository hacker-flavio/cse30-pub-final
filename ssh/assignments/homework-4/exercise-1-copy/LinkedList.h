#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <ostream>
#include <stdexcept>
#include "ArrayList.h"
using namespace std;template <typename T>struct Link{T data;Link* next;Link(T data){this->data=data;next=0;}};
template<typename T>class LinkedList:public AL<T>{Link<T>*front,*back;int a;public:LinkedList(){front=back=0;a=0;}void append(T v){front?(back=
back->next=new Link<T>(v)):back=front=new Link<T>(v);a++;}void prepend(T v){front?(front=new Link<T>(v))->next=back?back=back->next:front:back=front=
new Link<T>(v);a++;}T removeFirst(){Link<T>*c=front?:throw logic_error(0);front=front->next;front?:back=front;return c->data;}T removeLast(){Link<T>*c=
front?:throw logic_error(0);for(;c->next;c=c->next);if(a==1)front=back=0;return c->data;}friend struct TestTemplates;friend struct TestRemoveMethods;};
#endif