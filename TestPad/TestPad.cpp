#include <iostream>
#include <DataStructures/LZLinkedList.h>
#include <cassert>

using LZSoft::DataStructures::LZLinkedList;

LZLinkedList<int> createList()
{
	LZLinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);

	return list;
}

void printList(const LZLinkedList<int> list)
{
	LZSoft::DataStructures::Node<int>* n = list.Head;
	for (int i = 0; i < list.Count; i++)
	{
		std::cout << n->value;
		if (i == list.Count - 1)
			std::cout << std::endl;
		else
			std::cout << ", ";
		n = n->previous;
	}
	std::cout << std::endl;
}

void NewLine()
{
	
}

int main()
{
	LZLinkedList<int> list;

	/*list.Add(1);
	list.Add(2);
	list.Add(3);

	assert(1 == list.AtIndex(0)->value);
	assert(2 ==  list.AtIndex(1)->value);
	assert(3 == list.AtIndex(2)->value);
	assert(3 == list.Count);

	list.Remove(list.Head->previous);

	assert(1 == list.AtIndex(0)->value);
	assert(3 == list.AtIndex(1)->value);
	assert(2 == list.Count);*/

	std::cout << (1 << 0) << std::endl;
	std::cout << (1 << 1) << std::endl;
	std::cout << (1 << 2) << std::endl;
	std::cout << (1 << 3) << std::endl;
	std::cout << (1 << 4) << std::endl;

	std::cin.ignore();

    return 0;
}

