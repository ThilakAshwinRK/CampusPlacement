#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

//Function returning a  a new Node
struct node* newNode(int value)
{
	struct node* temp=new node;
	temp->data=value;
	temp->next=NULL;
	return temp;
}

void insertAtBegining(struct node* &head,int value)
{
	struct node* temp=newNode(value);
	temp->next=head;
	head=temp;
}
void insertAtEnd(struct node* &head,int value)
{
    struct node* temp=newNode(value);
	struct node* ptr=head;
	while(ptr->next!=NULL)
	{
     ptr=ptr->next;
	}
	ptr->next=temp;
}
void insertAtPos(struct node* &head,int value,int pos)
{
    struct node* temp=newNode(value);
	int t=0;
	struct node* ptr=head;
	while(ptr->next!=NULL && t<pos-2)
	{
     ptr=ptr->next;
     t++;
	}
	temp->next=ptr->next;
    ptr->next=temp;
}
void insertAfterVal(struct node* &head,int value,int value1)
{
    struct node* temp=newNode(value);
	struct node* ptr=head;
	while(ptr->next!=NULL && ptr->data!=value1)
	{
     ptr=ptr->next;
	}
	temp->next=ptr->next;
    ptr->next=temp;
}
void deleteAtPos(struct node* &head,int pos)
{
        struct node* temp;
	int t=0;
	struct node* ptr=head;
	while(ptr->next!=NULL && t<pos-2)
	{
         ptr=ptr->next;
         temp=ptr->next;t++;
	}
        struct node* str=ptr->next;
	ptr->next=temp->next;
        free(str);
}
void deleteAtEnd(struct node* &head)
{
 	struct node* ptr=head;
	struct node* temp;
     while(ptr->next->next!=NULL)
	{
     ptr=ptr->next;
	}
	temp=ptr->next;
        ptr->next=NULL;
       free(temp);  
}
void printLinkedList(struct node* head)
{
	struct node* ptr=head;
	while(ptr)
	{
		cout<<ptr->data<<" , ";
		ptr=ptr->next;
	}
}
void removeNthNodeFromEnd(struct node* &head,int pos)
{
	struct node *fast=head,*slow=head;
	int t=0;
	while(t<pos)
	{
      fast=fast->next;
      t++;
	}
     if(fast==NULL)
	{
		head=head->next;
		delete(slow);
		return;
	}
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
    struct node* temp=slow->next;
    slow->next=temp->next;//slow->next->next;
    delete(temp);
}
struct node* reverseIteratively(struct node* &head)
{
	struct node *current=head,*prev=NULL,*next=NULL;

	while(current)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	} 

        return prev;  
}
bool identical(struct node* a,struct node* b)
{
	if(a==NULL && b==NULL)
		return true;
	if(a && b)
			return ( (a->data==b->data) &&  identical(a->next,b->next) );
    else
    	return false;
}
void findMiddle(struct node* head)
{
  if(!head)
    cout<<"no middle element";
   struct node *slow=head,*fast=head;
   while(fast->next && fast->next->next)
  {
    slow=slow->next;
    fast=fast->next->next;
  } 
cout<<"middle ele is "<<slow->data;
}
struct node* reverseListInGroup(struct node* head,int k)
{
	struct node *current=head,*prev=NULL,*next=NULL;
        int i=0;
	    while(current && i<k)
	    {
	    	next=current->next;
	    	current->next=prev;
	    	prev=current;
	    	current=next;
	    	i++;
	    }
    
    if(next)
    	head->next=reverseListInGroup(next,k);

    return prev;
}
struct node* reverseAlternateGroup(struct node* &head,int k)
{
	if(!head)
		return NULL;
	struct node *current=head,*prev=NULL,*next=NULL;
    int i=0;
    while(current && i<k)
    {
    	next=current->next;
    	current->next=prev;
    	prev=current;
    	current=next;
    	i++;
    }
   
    if(head)
    	head->next=current;
    i=0;
    while(current && i<k-1)
    {
    	current=current->next;
    	i++;
    }
    if(current)
    	current->next=reverseAlternateGroup(current->next,k);
    
    return prev;
}
int main()
{
 struct node* head=newNode(1);
 printLinkedList(head) ;
cout<<endl;
 insertAtBegining(head,0);
 printLinkedList(head);
cout<<endl;
 insertAtEnd(head,2);
 insertAtEnd(head,4);
 insertAtEnd(head,6);
 printLinkedList(head);
cout<<endl;
 insertAtPos(head,3,4);
 printLinkedList(head);
 cout<<endl;
 insertAfterVal(head,5,4);
 insertAtEnd(head,7);
 insertAtEnd(head,8);
 insertAtEnd(head,9);
 printLinkedList(head);
 cout<<endl;
 //findMiddle(head);
 head=reverseAlternateGroup(head,3);
 printLinkedList(head);
 cout<<endl;
/* head=reverseIteratively(head);
 printLinkedList(head);
 cout<<endl;*/ 
/*removeNthNodeFromEnd(head,7);
 printLinkedList(head);
 cout<<endl;*/
 /*deleteAtEnd(head);
 printLinkedList(head);
 cout<<endl;
 deleteAtPos(head,4);
 printLinkedList(head);
 cout<<endl;*/

return 1;
}
