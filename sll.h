#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

template <class T> 
struct Node{
  T* data;
  Node* next;
};
template <class T> 
struct List{
Node <T> *head;
int size;
List(){
  head=nullptr;
  size=0;
}
};
template <class T> 
void push_back( List<T> &list,T* data=new T()){
Node<T> *new_node=new  Node<T>();
new_node->data = data;      
Node<T> *last=list.head;
if(list.head==nullptr)     {         
        list.head = new_node;}
        else{
          while(last->next!=nullptr){
            last=last->next;
          }
          last->next=new_node;
        }
        
list.size++;
}
#endif