#pragma once
template <class T>
void LZLinkedList<T>::Add(const T value)
{
	Node<T> *n = new Node<T>;
	n->value = value;
	if (Count == 0)
	{
		Head = n;
		Tail = n;
		n = nullptr;
	}
	else
	{
		n->previous = Head;
		Head->next = n;
		Head = n;
	}
	Count++;
}

template <class T>
void LZLinkedList<T>::Remove(Node<T>* node)
{
	Node<T>* n = Head;
	for (int i = 0; i < Count; i++)
		if (n == node)
		{
			Node<T>* p = n->previous;
			p->next = n->next;
			n->next->previous = p;
		}
		else
			n = n->previous;
	Count--;
}

template <class T>
void LZLinkedList<T>::RemoveHead()
{
	if (Count == 1)
	{
		Head = nullptr;
		Tail = nullptr;
		Count--;
		return;
	}
	Head = Head->previous;
	Head->next = nullptr;
	Count--;
}

template <class T>
void LZLinkedList<T>::RemoveTail()
{
	if (Count == 1)
	{
		Head = nullptr;
		Tail = nullptr;
		Count--;
		return;
	}
	Tail = Tail->next;
	Tail->previous = nullptr;
	Count--;
}

template <class T>
void LZLinkedList<T>::RemoveAt(const int index)
{
	Node<T>* n = Tail;
	for (int i = 0; i <= index; i++)
	{
		if (i == index)
		{
			Node<T>* p = n->previous;
			p->next = n->next;
			p->next->previous = p;
		}
		else
			n = n->next;
	}
	Count--;
}

template <class T>
Node<T>* LZLinkedList<T>::AtIndex(const int index)
{
	Node<T>* n = Tail;
	for (int i = 0; i <= index; i++)
	{
		if (i == index)
			return n;
		n = n->next;
	}
	return nullptr;
}

template <class T>
LZLinkedList<T>::LZLinkedList(): Head(nullptr),  Tail(nullptr),  Count(0)
{
}

template <class T>
LZLinkedList<T>::LZLinkedList(const LZLinkedList& source): Count(source.Count)
{
	Head = source.Head;
	Tail = source.Tail;
}

template <class T>
LZLinkedList<T>& LZLinkedList<T>::operator=(const LZLinkedList<T>& right)
{
	Head = right.Head;
	Tail = right.Tail;
	return *this;
}
