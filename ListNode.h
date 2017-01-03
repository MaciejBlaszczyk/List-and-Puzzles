#ifndef  LISTNODE
#define LISTNODE

#include<iostream>   //for cin, cout

using namespace std;

template <typename type>
class List;

template <typename type>
class ListNode
{
	friend class List<type>;

	ListNode (const type &data, ListNode *prior = nullptr, ListNode *next = nullptr) : data(data), prior(prior), next(next) { }

	type data;
	ListNode *prior, *next;
};

#endif // LISTNODE
