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
			tail=0;
		}
		void addBeforeTail(int val);
		void addAfterTail(int val);
		int deleteFromBeg();
		int deleteFromTail();
		void deleteNode(int val);
		void display();
	private:
		Node *tail;
};

void List::addBeforeTail(int val)
{
	if(tail==0)
	{
		tail=new Node(val);
		tail->next=tail;
	}
	else
	{
		tail->next=new Node(val,tail->next);
	}
}

void List::addAfterTail(int val)
{
	if(tail!=0){
		tail->next=new Node(val,tail->next);
		tail=tail->next;
	}
	else{
	
		tail=new Node(val);
		tail->next=tail;
	}
}

int List::deleteFromBeg()
{
	int val=tail->next->info;
	Node *tmp=tail->next;
	if(tail==tail->next)
		tail=tail->next=0;
	else
		tail->next=tail->next->next;
	delete tmp;
	return val;
}

int List::deleteFromTail()
{
	int val=tail->info;
	if(tail==tail->next){
		delete tail;
		tail=tail->next=0;
	}
	else{
		Node *tmp;
		for(tmp=tail->next;tmp->next!=tail;tmp=tmp->next);
		tmp->next=tail->next;
		delete tail;
		tail=tmp;
	}
	return val;
}

void List::deleteNode(int val)
{
	if(tail!=0){
		if(tail==tail->next && val==tail->info){
			delete tail;
			tail=tail->next=0;
		}
		else if(val==tail->next->info){
			Node *tmp=tail->next;
			tail->next=tail->next->next;
			delete tmp;
		}
		else{
			Node *pred,*tmp;
			for(pred=tail->next, tmp=tail->next->next; tmp!=0 && !(tmp->info==val); pred=pred->next, tmp=tmp->next);
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
	if(tail==0)
		cout<<"Empty linked list\n";
	else
	{
		for(tmp=tail->next; tmp!=tail; tmp=tmp->next)
			cout<<"Value::"<<tmp->info<<"\n";
		cout<<"Value::"<<tmp->info<<"\n";
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
		cout<<"1. Add before tail\n";
		cout<<"2. Add after tail\n";
		cout<<"3. Delete from beginning\n";
		cout<<"4. Delete from tail\n";
		cout<<"5. Delete node by value\n";
		cout<<"6. Display the linked list\n";
		cout<<"7. Exit\n";
		cout<<"\n";
		cout<<"Enter the number according to the menu-\n";
		cin>>n;
		cout<<"\n";
		switch(n)
		{
			case 1:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l.addBeforeTail(val);
				cout<<"Node inserted\n";
				break;
			case 2:
				cout<<"Enter the value to be added-\n";
				cin>>val;
				l.addAfterTail(val);
				cout<<"Node inserted\n";
				break;
			case 3:
				l.deleteFromBeg();
				cout<<"Node deleted\n";
				break;
			case 4:
				l.deleteFromTail();
				cout<<"Node deleted\n";
				break;
			case 5:
				cout<<"Enter the value to be deleted-\n";
				cin>>val;
				l.deleteNode(val);
				cout<<"Node deleted\n";
				break;
			case 6:
				l.display();
				break;
			case 7:
				exit(0);
			default:
				cout<<"Wrong Input\n";
				break;
		}
	}
	return 0;
}

