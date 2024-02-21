#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //distructor
    ~Node()
    {
        int value=this->data;
        //memory free

        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};

void insertAthead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp -> next = head;
    head = temp;
}
void inserattail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}

void print(Node* &head)
{
    Node* temp=head;

    while(temp != NULL)
    {
        cout<< temp -> data<<" ";
        //cout<< temp -> next;
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtposition(Node* &tail,Node* & head,int positon,int d)
{
    //insert at start;
    if(positon==1)
    {
        insertAthead(head,d);
        return;
    }
    Node* temp=head;

    int ctn=1;

    while(ctn < positon-1)
    {
        temp = temp->next;
        ctn++;
    }

    if(temp->next==NULL)
    {
        inserattail(tail,d);
        return;
    }
    Node* nodeToinsert = new Node(d);

    nodeToinsert->next=temp->next;

    temp->next = nodeToinsert;
}

void deletenode(int position,Node* &head)
{
    //deletiong first or start node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        //memory free start node
        temp->next=NULL;

        delete temp;
    }
    else{
        //deletiong any middle node or last node
        Node* cur=head;
        Node* prev=NULL;

        int cnt=1;

        while(cnt < position)
        {
            prev=cur;
            cur=cur->next;
            cnt++;

        }
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
    }
}

int main()
{
    //create a new node
    Node* node1=new Node(10);
    //cout<<node1 -> data <<endl;
    //cout << node1 -> next <<endl;

    //head pointed to node1
    //before insert;
    Node* head=node1;
    Node* tail=node1;
    print(head);

    //after insert at head;
    // insertAthead(head,12);
    // print(head);

    // insertAthead(head,15);
    // print(head);
    inserattail(tail,12);
    print(head);

    inserattail(tail,15);
    print(head);
    
    insertAtposition(tail,head,4,22);
    print(head);

    cout<<"head "<<head->data <<endl;
    cout<<"tail "<<tail->data <<endl;

    
    deletenode(4,head);
    print(head);
    cout<<"head "<<head->data <<endl;
    cout<<"tail "<<tail->data <<endl;


    return 0;
}