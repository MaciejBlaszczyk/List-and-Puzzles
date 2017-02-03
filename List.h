#ifndef LIST
#define LIST

#include "ListNode.h"
#include <stdexcept>

template <typename T>
class List
{
public:
	List() : cursor(nullptr), head(nullptr) { }
	List(const List<T> &list2);
	~List();

	void insert(const T &newElement);
	void replace (const T &newElement);
	void remove();
	void clear();
	void gotoPrior();
	void gotoNext();
	void gotoBeginning();
	void gotoEnd();
	bool isEmpty() const;
	void showElement() const;   //use only for bult-in types
	void showEverything() const; //use only for bult-in types

	bool operator==(const List<T> &list2);
	List<T> operator=(const List<T> &list2);

private:
	ListNode<T> *cursor, *head;
};

template <typename T>
List<T>:: List(const List<T> &list2)
{

	if(isEmpty() == true)
	{
		throw logic_error("List is empty!");
		return;
	}
	ListNode<T> *temp = list2.head;
	do
	{
		this->insert(temp);
		temp = temp->next;
	}while(temp != head);
}

template <typename T>
List<T>:: ~List()
{
	clear();
}

template <typename T>
void List<T>:: insert(const T &newElement)
{
	ListNode<T> *temp;
	if(isEmpty() == true)
	{
		temp = new ListNode<T>(newElement);
		head = temp;
		cursor = temp;
		head->prior = temp;
		head->next = temp;
	}
	else
	{
		temp = new ListNode<T>(newElement, cursor, cursor->next);
		cursor->next = temp;
		cursor = temp;
		if(cursor->next == head)
			head->prior = temp;
	}
}

template <typename T>
void List<T>:: replace(const T &newElement)
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor->data = newElement;
}

template <typename T>
void List<T>:: remove()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else if(cursor->next == cursor)
	{
		delete cursor;
		cursor = NULL;
		head = NULL;
	}
	else
	{
		(cursor->next)->prior = cursor->prior;
		(cursor->prior)->next = cursor->next;
		delete cursor;
		cursor = cursor->next;
	}
}

template <typename T>
void List<T>:: clear()
{
	ListNode<T> *temp = head;
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else if(temp == temp->next)
		delete temp;
	else
	{
		do
		{
			temp = temp->next;
			delete temp->prior;
		}while(temp->next != head);
		delete temp;
	}
	head = NULL;
	cursor = NULL;
}

template <typename T>
void List<T>:: gotoPrior()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = cursor->prior;
}

template <typename T>
void List<T>:: gotoNext()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = cursor->next;
}

template <typename T>
void List<T>:: gotoBeginning()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = head;
}

template <typename T>
void List<T>:: gotoEnd()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = head->prior;
}

template <typename T>
bool List<T>:: isEmpty() const
{
	return head == NULL ? true : false;
}

template <typename T>
void List<T>:: showElement() const
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cout<<cursor->data;
}

template <typename T>
void List<T>:: showEverything() const
{
	if(isEmpty() == true)
	{
		throw logic_error("List is empty!");
		return;
	}
	ListNode<T> *temp = head;
	do
	{
		cout<<(*temp).data;
		temp = temp->next;
	}while(temp != head);
}

template <typename T>
bool List<T>:: operator==(const List<T> &list2)
{
	ListNode<T> *temp = head;
	ListNode<T> *temp2 = list2.head;
	if(head == nullptr || list2.head == nullptr)
		return false;
	if(head == nullptr && list2.head == nullptr)
		return true;
	do
	{
		if(temp->data != temp2->data)
			return false;
		temp = temp->next;
		temp2 = temp2->next;
	}while(temp != head);
	return true;
}

template <typename T>
List<T> List<T>:: operator=(const List<T> &list2)
{
	if(isEmpty())
	{
		throw logic_error("List is empty!");
		return;
	}
	ListNode<T> *temp = list2.head;
	do
	{
		this->insert(temp);
		temp = temp->next;
	}while(temp != head);

}

#endif // LIST
