#include <assert.h>

#ifndef __DOUBLELINKEDLISTS__
#define __DOUBLELINKEDLISTS__

template<class TYPE>
class DoubleLinkList
{
public:
	struct nodeD
	{
		TYPE data;
		nodeD* next = nullptr;
		nodeD* previous = nullptr;
		nodeD(const TYPE &data) : data(data){}
	};
	nodeD* first_node = nullptr;
public:
	DoubleLinkList(){}
	~DoubleLinkList(){}
	bool Empty()const
	{
		return first_node == nullptr;
	}

	unsigned int size()const
	{
		int num_elements = 0;
		nodeD* temp = first_node;
		while (temp != nullptr)
		{
			num_elements++;
			temp = temp->next;
		}
		return num_elements;
	}

	nodeD* end()const
	{
		nodeD* temp = first_node;
		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void push_back(const TYPE &data)
	{
		nodeD* temp = first_node;
		nodeD* new_node = new nodeD(data);
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
			new_node->previous = temp;
			temp->next = new_node;
		}
	}

	void push_front(const TYPE &data)
	{
		nodeD* new_node = new nodeD(data);
		nodeD* temp = first_node;
		first_node = new_node;
		if (temp != nullptr)
		{
			first_node->next = temp;
			temp->previous = new_node;
		}
	}

	bool pop_back()
	{
		if (first_node != nullptr)
		{
			if (first_node->next != nullptr)
			{
				nodeD* copy = first_node;
				nodeD*popback = first_node;
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
			else
			{
				//popfront;
				nodeD* popback = first_node;
				first_node = nullptr;
				delete popback;
				return true;
			}
		}
		else return false;
	}

	bool pop_front()
	{
		if (first_node != nullptr)
		{
			nodeD* temp = first_node;
			first_node = first_node->next;
			first_node->previous = nullptr;
			delete temp;
			return true;
		}
		return false;
	}
	void insert(const TYPE &data, unsigned int position)
	{
		nodeD* new_node = new nodeD(data);
		nodeD* temp = first_node;
		nodeD* temp2 = first_node;
		if (position <= size())
		{
			if (position != 0 && position != size())
			{
				for (int i = 0; i < position - 1; i++)
				{
					temp = temp->next;
					temp2 = temp2->next;
				}
				temp2 = temp2->next;
				temp->next = new_node;
				new_node->next = temp2;
				temp2->previous = new_node;
				new_node->previous = temp;
			}
			else if (position == size())
			{
				for (int i = 0; i < position - 1; i++)
				{
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->previous = temp;
			}
			else
			{
				new_node->next = first_node;
				first_node->previous = new_node;
				first_node = new_node;
			}
		}
		else
		{
			assert(position <= size());
		}
	}

	void erase(nodeD* del)
	{
		nodeD* temp = first_node;
		if (temp != nullptr)
		{
			if (del->previous == nullptr)
			{
				first_node = temp->next;
				first_node->previous = nullptr;
			}
			else if (del->next == nullptr)
			{
				temp = del->previous;
				temp->next = nullptr;
			}
			else
			{
				temp = del->previous;
				temp->next = del->next;
				//temp = temp->next;
				temp->next->previous = del->previous;
			}
			delete del;
		}
	}
};

#endif //__DOUBLELINKEDLISTS__