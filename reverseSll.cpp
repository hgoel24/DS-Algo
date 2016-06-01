#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;

class Node
{
	public:
		Node()
		{
			next=0;
		}
		Node(int val, Node *ptr=0)
		{
			info=val;
			next=ptr;
		}
		int info;
		Node *next;
};

class List
{
	public:
		List()
		{
			head=tail=0;
		}
		void addToHead(int val);
		void addToTail(int val);
		void display();
		void reverse();
	private:
		Node *head,*tail;
};

void List::addToHead(int val)
{
	head=new Node(val,head);
	if(tail==0)
		tail=head;
}

void List::addToTail(int val)
{
	if(tail!=0){
		tail->next=new Node(val);
		tail=tail->next;
	}
	else
		head=tail=new Node(val);	
}

void List::display()
{
	Node *tmp;
	if(head==0)
		cout<<"Empty linked list\n";
	else
	{
		for(tmp=head; tmp!=0; tmp=tmp->next)
			cout<<"Value::"<<tmp->info<<"\n";
	}
}

void List::reverse()
{
	Node *tmp=head;
	Node *ptr=head->next;
	while(tmp->next!=NULL)
	{
		ptr=tmp->next;
		tmp->next=tmp->next->next;
		ptr->next=head;
		head=ptr;
	}
}

int main()
{
	int n;
	List l;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Add to head\n";
		cout<<"2. Add to tail\n";
		cout<<"3. Reverse and dislpay the linked list\n";
		cout<<"4. Exit\n";
		cout<<"\n";
		cout<<"Enter the number according to the menu-\n";
		cin>>n;
		cout<<"\n";
		switch(n)
		{
			case 1:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l.addToHead(val);
				cout<<"Node inserted\n";
				break;
			case 2:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l.addToTail(val);
				cout<<"Node inserted\n";
				break;
			case 3:
				cout<<"List before reversing-\n";
				l.display();
				cout<<"List after reversing-\n";
				l.reverse();
				l.display();
				break;
			case 4:
				exit(0);
			default:
				cout<<"Wrong Input\n";
				break;
		}
	}
	return 0;
}

