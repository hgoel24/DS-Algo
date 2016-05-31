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
		int deleteFromHead();
		int deleteFromTail();
		void deleteNode(int val);
		bool isInList(int val);
		void display();
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

int List::deleteFromHead()
{
	int val=head->info;
	Node *tmp=head;
	if(head==tail)
		head=tail=0;
	else
		head=head->next;
	delete tmp;
	return val;
}

int List::deleteFromTail()
{
	int val=tail->info;
	if(head==tail){
		delete head;
		head=tail=0;
	}
	else{
		Node *tmp;
		for(tmp=head;tmp->next!=tail;tmp=tmp->next);
		delete tail;
		tail=tmp;
		tail->next=0;
	}
	return val;
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

bool List::isInList(int val)
{
	Node *tmp;
	for(tmp=head; tmp!=0 &&!(tmp->info==val); tmp=tmp->next);
	return tmp!=0;
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
	int n;
	List l;
	int val;
	while(1)
	{
		cout<<"MENU\n";
		cout<<"1. Add to head\n";
		cout<<"2. Add to tail\n";
		cout<<"3. Delete from head\n";
		cout<<"4. Delete from tail\n";
		cout<<"5. Delete node by value\n";
		cout<<"6. Searching the value\n";
		cout<<"7. Display the linked list\n";
		cout<<"8. Exit\n";
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
				l.deleteFromHead();
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
				cout<<"Enter the value to be searched-\n";
				cin>>val;
				l.isInList(val);
				break;
			case 7:
				l.display();
				break;
			case 8:
				exit(0);
			default:
				cout<<"Wrong Input\n";
				break;
		}
	}
	return 0;
}
