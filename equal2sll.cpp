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
		void display();
		void sort();
		Node *head,*tail;
};

void List::addToHead(int val)
{
	head=new Node(val,head);
	if(tail==0)
		tail=head;
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

void List::sort()
{
	Node *tmp;
	int counter=0,val;
	if(head==0)
		cout<<"Empty linked list\n";
	else
	{
		tmp=head;
		while(tmp)
		{
			tmp=tmp->next;
			counter++;
		}
		for(int i=0;i<counter;i++)
		{
			tmp=head;
			for(int j=0;j<counter-i && tmp->next!=0;j++)
			{
				if(tmp->info>tmp->next->info)
				{
					val=tmp->next->info;
					tmp->next->info=tmp->info;
					tmp->info=val;
				}
				tmp=tmp->next;
			}
		}		
	}
}

int main()
{
	int n;
	List l1,l2;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Add to list 1\n";
		cout<<"2. Add to list 2\n";
		cout<<"3. Sort list 1\n";
		cout<<"4. Sort list 2\n";
		cout<<"5. Display first list\n";
		cout<<"6. Display second list\n";
		cout<<"7. Check for equality\n";
		cout<<"8. Exit";
		cout<<"\n";
		cout<<"Enter the number according to the menu-\n";
		cin>>n;
		cout<<"\n";
		switch(n)
		{
			case 1:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l1.addToHead(val);
				cout<<"Node inserted\n";
				break;
			case 2:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l2.addToHead(val);
				cout<<"Node inserted\n";
				break;
			case 3:
				l1.sort();
				cout<<"Sorted\n";
				break;
			case 4:
				l2.sort();
				cout<<"Sorted\n";
				break;
			case 5:
				l1.display();
				break;
			case 6:
				l2.display();
				break;
			case 7:{
				Node *tmp,*ptr;
				tmp=l1.head;
				ptr=l2.head;
				int flag=0;
				while(tmp->next!=NULL && ptr->next!=NULL)
				{
					if(tmp->info==ptr->info)
						flag=1;
					else 
						flag=0;
					tmp=tmp->next;
					ptr=ptr->next;
				}
				if(flag==1)
					cout<<"Lists are equal\n";
				else 
					cout<<"Lists are unequal\n";
				break;
			}
			case 8:
				exit(0);
			default:
				cout<<"Wrong Input\n";
				break;
		}
	}
	return 0;
}

