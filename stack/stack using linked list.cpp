#include <bits/stdc++.h>

using namespace std;
template <typename T>

class Node{
public:
    T data;
    Node <T> *Next;
    Node(T data){
    this->data=data;
    Next=NULL;

    }


};

template <typename T>

class stackarray{
Node <T> *head;
int size;
public:

stackarray(){
head=NULL;
size=0;
}

int getsize(){
return size;
}
bool isempty(){
return size==0;
}
void push(T element){
Node <T> *newnode = new Node<T>(element);
newnode->Next=head;
head = newnode;
size++;

}
T pop(){
    if(size==0)
    {
        cout<<"stack is empty";
        return 0;
    }
T datap= head->data;

Node <T> *temp =head;

head=head->Next;
delete temp;
size--;
return datap;

}



};




int main(){

stackarray<int> s1;
s1.push(10);
s1.push(20);
s1.push(30);
s1.push(40);
s1.push(50);

cout<<s1.pop()<<endl;
cout<<s1.getsize()<<endl;
cout<<s1.isempty()<<endl;
return 0;
}
