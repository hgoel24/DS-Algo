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
		void transfer();
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

void Stack::transfer()
{
	Node *tmp;
	Stack s2;
	int a;
	for(tmp=bottom;tmp!=0;tmp=tmp->next)
	{
		a=tmp->info;
		s2.push(a);
	}
	s2.display();
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
	Stack s1;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Push\n";
		cout<<"2. Pop\n";
		cout<<"3. Transfer the contents of stack s1 into stack s2 in the same order\n";
		cout<<"4. Display the Stack\n";
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
				s1.push(val);
				cout<<"Element inserted\n";
				break;
			case 2:
				s1.pop();
				cout<<"Element popped\n";
				break;
			case 3:
				s1.transfer();
				break;
			case 4:
				s1.display();
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
