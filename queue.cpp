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

class Queue
{
	public:
		Queue()
		{
			first=last=0;
		}
		void enqueue(int val);
		int dequeue();
		bool isEmpty();
		void firstVal();
		void display();
	private:
		Node *first,*last;
};

void Queue::enqueue(int val)
{
	last=new Node(val,last);
	if(first==0)
		first=last;
}

int Queue::dequeue()
{
	int val=first->info;
	if(last==first){
		delete last;
		last=first=0;
	}
	else{
		Node *tmp;
		for(tmp=last;tmp->next!=first;tmp=tmp->next);
		delete first;
		first=tmp;
		first->next=0;
	}
	return val;
}

bool Queue::isEmpty()
{
	if(last==0)
		return 1;
	else
		return 0;
}

void Queue::firstVal()
{
	if(first==0)
	{
		cout<<"Queue empty\n";
	}
	else
		cout<<first->info<<endl;
}


void Queue::display()
{
	Node *tmp;
	if(last==0)
		cout<<"Empty Queue\n";
	else
	{
		for(tmp=last; tmp!=0; tmp=tmp->next)
			cout<<"Value::"<<tmp->info<<"\n";
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
		cout<<"3. Return first value\n";
		cout<<"4. Clear the queue\n";
		cout<<"5. Display the Queue\n";
		cout<<"6. Exit\n";
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
				q.firstVal();
				break;
			case 4:
				while(!q.isEmpty())
				{
					q.dequeue();
				}
				cout<<"Queue cleared\n";
				break;
			case 5:
				q.display();
				break;
			case 6:
				exit(0);
			default:
				cout<<"Wrong Input\n";
				break;
		}
	}
	return 0;
}

