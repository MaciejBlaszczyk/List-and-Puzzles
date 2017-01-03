#ifndef LIST
#define LIST

#include "ListNode.h"
#include <stdexcept>
#include <exception>

template <typename type>
class List
{
public:
	List() : cursor(nullptr), head(nullptr) { }
	~List() { clear(); }

	void insert(const type &newElement);
	void replace (const type &newElement);
	void remove();
	void clear();
	void gotoPrior();
	void gotoNext();
	void gotoBeginning();
	void gotoEnd();
	bool isEmpty() const { return head == NULL ? true : false; }
	void showElement() const;   //use only for bult-in types
	void showEverything() const; //use only for bult-in types

	bool operator==(const List<type> &list2);


private:
	ListNode<type> *cursor, *head;
};

template <typename type>
void List<type>:: insert(const type &newElement)
{
	ListNode<type> *temp;
	if(isEmpty() == true)
	{
		temp = new ListNode<type>(newElement);
		head = temp;
		cursor = temp;
		head->prior = temp;
		head->next = temp;
	}
	else
	{
		temp = new ListNode<type>(newElement, cursor, cursor->next);
		cursor->next = temp;
		cursor = temp;
		if(cursor->next == head)
			head->prior = temp;
	}
}

template <typename type>
void List<type>:: replace (const type &newElement)
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor->data = newElement;
}

template <typename type>
void List<type>:: remove()
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

template <typename type>
void List<type>:: clear()
{
	ListNode<type> *temp = head;
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

template <typename type>
void List<type>:: gotoPrior()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = cursor->prior;
}

template <typename type>
void List<type>:: gotoNext()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = cursor->next;
}

template <typename type>
void List<type>:: gotoBeginning()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = head;
}

template <typename type>
void List<type>:: gotoEnd()
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cursor = head->prior;
}

template <typename type>
void List<type>:: showElement() const
{
	if(isEmpty() == true)
		throw logic_error("List is empty!");
	else
		cout<<cursor->data;
}

template <typename type>
void List<type>:: showEverything() const
{
	if(isEmpty() == true)
	{
		throw logic_error("List is empty!");
		return;
	}
	ListNode<type> *temp = head;
	do
	{
		cout<<(*temp).data;
		temp = temp->next;
	}while(temp != head);
}

template <typename type>
bool List<type>:: operator==(const List<type> &list2)
{
	ListNode<type> *temp = head;
	ListNode<type> *temp2 = list2.head;
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

#endif // LIST
