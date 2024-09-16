#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};
Node *makeNode(int x){
    Node *newNode = new Node();
    newNode -> data = x;
    newNode -> next = nullptr;
    return newNode;
}
void PushB(Node * &head, int x){
    Node *newNode = makeNode(x);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp -> next != nullptr){
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}
void output(Node *&head){
    while(head != nullptr){
        cout << head -> data << " ";
        head = head -> next; 
    }
}
int main(){
    Node *head = nullptr;
    int x;
    do{
        cin >> x;
        if(x != -1)PushB(head, x);
    }while(x!=-1);
    output(head);
}