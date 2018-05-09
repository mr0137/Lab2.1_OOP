#pragma once

#include "Iterator.h"
#include <iostream>

using namespace std;

template <class T>
class List 
{
    struct ListNode
    {
        T data;
        ListNode *next;
        ListNode() 
		{
            next = NULL;
        }
        ListNode( T dat ) 
		{
            data = dat;
        }
        void Print() 
		{
            cout << data << endl;
        }
    };
    
public:
   typedef ListNode node_type;
	typedef _iterator<node_type> iterator;
	List();
	~List();
	
	//methods
	bool load(const char *filename);
	iterator begin();
	iterator end();

	void clear();
	bool empty();

	iterator find(const node_type &val);


	void pop_front();

	void push_front(const node_type val);
	void remove(const node_type val);

	iterator remove(iterator _where);


	int size();

	void splice( iterator _Where, List<T>& _Right);

	void Print();
	void Print_route_number(iterator iter,const char *route);
	bool rename(iterator it, string name);

private:
	node_type *head;
	iterator *first, *last;

};

template <class T>
List<T>::List() 
{
	head = NULL;
	first = new iterator(NULL);
	last = new iterator(NULL);
}

template <class T>
List<T>::~List() 
{
	clear();
}

template <class T>
typename List<T>::iterator List<T>::begin() 
{
	return *first;
}

template <class T>
typename List<T>::iterator List<T>::end() 
{
	return *last;
}

template<class T>
bool List<T>::load(const char * filename)
{
	T data;
	ifstream stream(filename);
	if (!stream)
	{
		cout << "Couldn't open file\n";
		exit(1);
	}
	while (!stream.eof())
	{
		stream >> data;
		push_front(node_type(data));
	}
	stream >> data;
	stream.close();
}

template<class T>
void List<T>::clear()
{
	node_type *temp = head;
	while (head)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
	delete first;
	first = new iterator(NULL);
}

template<class T>
bool List<T>::empty() 
{
	return _size == 0;
}

template <class T>
typename List<T>::iterator List<T>::find(const node_type& val)
{
	node_type *temp = head;
	while (temp && temp->data != val.data)
	{
		temp = temp->next;
	}
	return *new iterator(temp);
}

template <class T>
void List<T>::pop_front()
{
	node_type *temp;
	if (head)
	{
		++(*first);
		temp = head;
		head = head->next;
		delete temp;
		delete first;
		first = new iterator(head);
	}
}

template<class T>
void List<T>::push_front(const node_type val)
{
	node_type *temp = new node_type(val);
	temp->next = head;
	head = temp;
	delete first;
	first = new iterator(head);
}

template<class T>
void List<T>::remove(const node_type val)
{
	node_type *temp = head, *Temp;
	if (!head) return;
	if (val.data == head->data)
	{
		pop_front();
		return;
	}
	while (temp->next && val.data != temp->next->data) {
		temp = temp->next;
	}
	if (temp->next)
	{
		Temp = temp->next;
		temp->next = temp->next->next;
		delete Temp;
	}
}

template<class T>
typename List<T>::iterator List<T>::remove(iterator _where)
{
	this->remove(*_where);
	return nullptr;
}

template<class T>
int List<T>::size()
{
	return _size;
}

template<class T>
void List<T>::splice(iterator _Where, List<T>& _Right)
{
	_Right.push_front(*_Where);
	this->remove(*_Where);
}

template <class T>
void List<T>::Print()
{
	node_type *temp = head;
	int i = 1;
	if (temp == nullptr)
	{
		cout << " All drivers in park";
	}
	while (temp)
	{
		cout << " " << i << ". ";
		temp->Print();
		temp = temp->next;
		i++;
	}
	cout << endl;
}

template<class T>
void List<T>::Print_route_number(iterator iter, const char * route)
{
	int i = 1;
	while (iter != nullptr)
	{
		if ((*iter).data.Print_route_number(route))
		{
			cout << " " << i << ". ";
			(*iter).Print();
			i++;
		}
		iter++;
	}
}

template<class T>
bool List<T>::rename(iterator it, string name)
{
	if (!name.empty())
	{
		(*it).data.rename(name);
		return true;
	}
	return false;
}