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
		void addToTail(int val);
		void deleteNode(int val);
		void display();

		Node *head,*tail;
};

void List::addToTail(int val)
{
	if(tail!=0){
		tail->next=new Node(val);
		tail=tail->next;
	}
	else
		head=tail=new Node(val);
}

void List::deleteNode(int val)
{
	if(head!=0){
		if(head==tail && val==head->info){
			delete head;
			head=tail=0;
		}
		else if(val==head->info){
			Node *tmp=head;
			head=head->next;
			delete tmp;
		}
		else{
			Node *pred,*tmp;
			for(pred=head, tmp=head->next; tmp!=0 && !(tmp->info==val); pred=pred->next, tmp=tmp->next);
				if(tmp!=0){
					pred->next=tmp->next;
					if(tmp==tail)
						tail=pred;
					delete tmp;
				}
		}
	}
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

int main()
{
	int n,j=0,m=0,k=0,i=0;
	List l1,l2;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Add to list1\n";
		cout<<"2. Add to list2\n";
		cout<<"3. Delete nodes from list 1 according to indexes given in list 2\n";
		cout<<"4. Display the linked list 1\n";
		cout<<"5. Exit\n";
		cout<<"\n";
		cout<<"Enter the number according to the menu-\n";
		cin>>n;
		cout<<"\n";
		switch(n)
		{
			case 1:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l1.addToTail(val);
				cout<<"Node inserted\n";
				break;
			case 2:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l2.addToTail(val);
				cout<<"Node inserted\n";
				break;
			case 3:{
				Node *tmp;
				Node *tmp2;
				for(tmp=l2.head; tmp!=0; tmp=tmp->next)
				{
	 				j=tmp->info;
         			j=j-m;
         			i=0;
	 				for(tmp2=l1.head; tmp2!=0; tmp2=tmp2->next)
	 				{
	  					i++;
	  					if(i==j)
	  					{
	   						k=tmp2->info;
	   						l1.deleteNode(k);
          					m++;
	   						break;
	   					}
	   				}
	   			}
				break;
			}
			case 4:
				l1.display();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Wrong Input\n";
				break;
		}
	}
	return 0;
}
