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

class Stack
{
	public:
		Stack()
		{
			top=bottom=0;
		}
		void push(int val);
		int pop();
		void topVal();
		bool isEmpty();
		void display();
	private:
		Node *top,*bottom;
};

void Stack::push(int val)
{
	if(top==0){
		top=bottom=new Node(val,NULL);
		top->next=NULL;
	}
	else
	{
		top->next=new Node(val,NULL);
		top=top->next;
		top->next=NULL;
	}
}

int Stack::pop()
{
	int val=top->info;
	if(top==bottom){
		delete top;
		top=bottom=0;
	}
	else{
		Node *tmp;
		for(tmp=bottom;tmp->next!=top;tmp=tmp->next);
		delete top;
		top=tmp;
		top->next=0;
	}
	return val;
}

bool Stack::isEmpty()
{
	if(top==0)
		return 1;
	else
		return 0;
}

void Stack::topVal()
{
	if(top==0)
	{
		cout<<"Stack empty\n";
	}
	else
		cout<<top->info<<endl;
}

void Stack::display()
{
	Node *tmp;
	if(top==0)
		cout<<"Empty Stack\n";
	else
	{
		for(tmp=bottom; tmp!=0; tmp=tmp->next)
			cout<<"Value::"<<tmp->info<<"\n";
	}
}

int main()
{
	int n;
	Stack s;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Return top element\n";
		cout<<"4. Clear the stack\n";
		cout<<"5. Display the Stack\n";
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
				s.push(val);
				cout<<"Element inserted\n";
				break;
			case 2:
				s.pop();
				cout<<"Element popped\n";
				break;
			case 3:
				s.topVal();
				cout<<"Element returned\n";
				break;
			case 4:
				while(!s.isEmpty())
				{
					s.pop();
				}
				cout<<"Stack cleared\n";
				break;
			case 5:
				s.display();
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
