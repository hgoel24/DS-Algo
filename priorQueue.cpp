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
		Node(int val, int p, Node *ptr=0)
		{
			info=val;
			priority=p;
			next=ptr;
		}
		int info;
		int priority;
		Node *next;
};

class Queue
{
	public:
		Queue()
		{
			first=last=0;
		}
		void enqueue(int val);
		void dequeue();
		void display();
	private:
		Node *first,*last;
};

void Queue::enqueue(int val)
{
	int p;
	cout<<"Enter the priority of the element to be enqueued-\n";
	cin>>p;
	if(last==0)
	{
		last=new Node(val,p);
		first=last;
	}
	else
	{
		last=new Node(val,p,last);
	}
}

void Queue::dequeue()
{
	Node *tmp,*ptr;
	int a,b;
	for(tmp=last;tmp!=0;tmp=tmp->next)
	{
		for(ptr=tmp->next;ptr!=0;ptr=ptr->next)
		{
			if(ptr->priority<tmp->priority)
			{
				a=tmp->info;
				tmp->info=ptr->info;
				ptr->info=a;
				b=tmp->priority;
				tmp->priority=ptr->priority;
				ptr->priority=b;
			}
		}
	}
	int p;
	cout<<"Enter the priority of the element to be dequeued-\n";
	cin>>p;
	if(last==first && p==last->priority){
			delete last;
			last=first=0;
		}
	else if(p==last->priority){
			Node *tmp=last;
			last=last->next;
			delete tmp;
		}
	else{
		Node *pred,*tmp;
		for(pred=last, tmp=last->next; tmp!=0 && !(tmp->priority==p); pred=pred->next, tmp=tmp->next);
			if(tmp!=0 )
			{
				pred->next=tmp->next;
				if(tmp==first)
					first=pred;
				delete tmp;
			}
	}
}

void Queue::display()
{
	Node *tmp;
	if(last==0)
		cout<<"Empty Queue\n";
	else
	{
		for(tmp=last; tmp!=0; tmp=tmp->next)
			cout<<"Value::"<<tmp->info<<" Priority::"<<tmp->priority<<"\n";
	}
}

int main()
{
	int n;
	Queue q;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Enqueue\n";
		cout<<"2. Dequeue\n";
		cout<<"3. Display the Queue\n";
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
				q.enqueue(val);
				cout<<"Value enqueued\n";
				break;
			case 2:
				q.dequeue();
				cout<<"Value dequeued\n";
				break;
			case 3:
				q.display();
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

