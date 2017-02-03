#ifndef  LISTNODE
#define LISTNODE

#include<iostream>

using namespace std;

template <typename T>
class List;

template <typename T>
class ListNode
{
	friend class List<T>;

	ListNode (const T &data, ListNode *prior = nullptr, ListNode *next = nullptr) : data(data), prior(prior), next(next) { }

	T data;
	ListNode *prior, *next;
};

#endif // LISTNODE
