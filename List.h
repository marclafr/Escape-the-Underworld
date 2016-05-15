#include <assert.h>

#ifndef __LINKEDLISTS__
#define __LINKEDLISTS__

template<class TYPE>
class LinkList
{
public:
	struct node
	{
		TYPE data;
		node* next = nullptr;
		node(const TYPE &data) :data(data){}
	};
	node* first_node = nullptr;
public:
	LinkList(){}
	~LinkList(){}

	bool Empty()const
	{
		return first_node == nullptr;
	}

	unsigned int size()const
	{
		int num_elements = 0;
		node* temp = first_node;
		while (temp != nullptr)
		{
			num_elements++;
			temp = temp->next;
		}
		return num_elements;
	}

	node* end()const
	{
		node* temp = first_node;
		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void push_back(const TYPE& data)
	{
		node* temp = first_node;
		node* new_node = new node(data);
		if (temp == nullptr)
		{
			first_node = new_node;
		}
		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	void push_front(const TYPE& data)
	{
		//node<TYPE>* new_node = new node<TYPE>(data);
		//new_node->next = first;
		//first = new_node;
		node* temp = first_node;
		node* new_node = new node(data);
		if (temp == nullptr)
		{
			first_node = new_node;
		}
		else
		{
			new_node->next = first_node;
			first_node = new_node;
		}
	}

	bool pop_back()
	{
		if (first_node != nullptr){
			if (first_node->next != nullptr){
				node* copy = first_node;
				node*popback = first_node;
				while (copy->next != nullptr) {
					copy = copy->next;
				}
				while (popback->next != copy){
					popback = popback->next;
				}
				popback->next = nullptr;
				delete copy;
				return true;
			}
			else{
				//popfront;
				node* popback = first_node;
				first_node = nullptr;
				delete popback;
				return true;
			}
		}
		return false;
	}

	bool pop_front()
	{
		if (first_node != nullptr)
		{
			node* temp = first_node;
			first_node = first_node->next;
			delete temp;
			return true;
		}
		return false;
	}

	void insert(const TYPE &data, unsigned int position)
	{
		node* new_node = new node(data);
		node* temp = first_node;
		node* temp2 = first_node;
		if (position <= size())
		{
			if (position != 0)
			{
				for (int i = 0; i < position - 1; i++)
				{
					temp = temp->next;
					temp2 = temp2->next;
				}
				temp2 = temp2->next;
				temp->next = new_node;
				new_node->next = temp2;
			}
			else
			{
				new_node->next = first_node;
				first_node = new_node;
			}
		}
		else
		{
			assert(position <= size());
		}
	}

	void clear()
	{
		node* temp = first_node;
		node* next;
		while (temp != NULL)
		{
			next = temp->next;
			delete temp;
			temp = next;
		}
		first_node = nullptr;
	}

	/*
	node type ref, data{´}
	if(ref!=nullptr)
	node<TYPE>* new_node = new node<TYPE>(data);
	node<TYPE>* temp=first
	if(first!=ref
	whiletemp->next!=ref		temp=temp->next
	temp->next newnode
	newnode next =ref
	else
	new node next=ref;
	first=newnode;
	else first=newnode;
	*/


	void erase(node* del)
	{
		node* temp = first_node;
		if (temp != nullptr)
		{
			if (first_node == del)
			{
				first_node = temp->next;
			}
			else
			{
				while (temp->next != del)
				{
					temp = temp->next;
				}
				temp->next = del->next;
			}
			delete del;
		}
	}
};

#endif //__LINKEDLISTS__