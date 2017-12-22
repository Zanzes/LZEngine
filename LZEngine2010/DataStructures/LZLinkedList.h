#pragma once
#include "Node.h"

namespace LZSoft
{
	namespace DataStructures
	{
		template <class T>
		class __declspec(dllexport) LZLinkedList
		{
		public:
			Node<T> *Head;
			Node<T> *Tail;
			int Count;
			void Add(const T value);
			void Remove(Node<T>* node);
			void RemoveHead();
			void RemoveTail();
			void RemoveAt(const int index);
			Node<T>* AtIndex(const int index);
			LZLinkedList();
			LZLinkedList(const LZLinkedList<T>& source);
			LZLinkedList<T>& operator=(const LZLinkedList<T>& right);
			
		};

		#include "LZLinkedList.inl"
	}
}
