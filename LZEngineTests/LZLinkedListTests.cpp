#include "stdafx.h"
#include <DataStructures\LZLinkedList.h>
#include <DataStructures\Node.h>

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace LZSoft::DataStructures;

namespace LZEngineTests
{
	[TestClass]
	public ref class LZLinkedListTests
	{
	public: 
		[TestMethod]
		void LZLinkedList_Constructor()
		{
			LZLinkedList<int> list;
			Assert::AreEqual(0, list.Count);
			Assert::IsTrue(list.Head == nullptr);
			Assert::IsTrue(list.Tail == nullptr);

			list.Add(2);
			Assert::AreEqual(1, list.Count);
			Assert::IsFalse(list.Head == nullptr);
			Assert::IsFalse(list.Tail == nullptr);
		}

		[TestMethod]
		void LZLinkedList_Add()
		{
			LZLinkedList<int> list;

			list.Add(1);
			Assert::AreEqual(1, list.Count);

			list.Add(2);
			Assert::AreEqual(2, list.Count);

			list.Add(3);
			Assert::AreEqual(3, list.Count);

			Assert::AreEqual(1, list.Head->previous->previous->value);
			Assert::AreEqual(2, list.Head->previous->value);
			Assert::AreEqual(3, list.Head->value);

			Assert::AreEqual(1, list.Tail->value);
			Assert::AreEqual(2, list.Tail->next->value);
			Assert::AreEqual(3, list.Tail->next->next->value);
		}

		[TestMethod]
		void LZLinkedList_Remove()
		{
			LZLinkedList<int> list;

			list.Add(1);
			list.Add(2);
			list.Add(3);

			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(2, list.AtIndex(1)->value);
			Assert::AreEqual(3, list.AtIndex(2)->value);
			Assert::AreEqual(3, list.Count);

			list.Remove(list.Head->previous);

			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(3, list.AtIndex(1)->value);
			Assert::AreEqual(2, list.Count);
		}

		[TestMethod]
		void LZLinkedList_RemoveHead()
		{
			LZLinkedList<int> list;

			list.Add(1);
			list.Add(2);
			list.Add(3);

			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(2, list.AtIndex(1)->value);
			Assert::AreEqual(3, list.AtIndex(2)->value);
			Assert::AreEqual(3, list.Count);

			list.RemoveHead();

			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(2, list.AtIndex(1)->value);
			Assert::AreEqual(2, list.Count);

			list.RemoveHead();

			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(1, list.Count);

			list.RemoveHead();

			Assert::AreEqual(0, list.Count);
		}

		[TestMethod]
		void LZLinkedList_RemoveTail()
		{
			LZLinkedList<int> list;

			list.Add(1);
			list.Add(2);
			list.Add(3);

			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(2, list.AtIndex(1)->value);
			Assert::AreEqual(3, list.AtIndex(2)->value);
			Assert::AreEqual(3, list.Count);

			list.RemoveTail();

			Assert::AreEqual(2, list.AtIndex(0)->value);
			Assert::AreEqual(3, list.AtIndex(1)->value);
			Assert::AreEqual(2, list.Count);

			list.RemoveTail();

			Assert::AreEqual(3, list.AtIndex(0)->value);
			Assert::AreEqual(1, list.Count);

			list.RemoveTail();

			Assert::AreEqual(0, list.Count);
		}

		[TestMethod]
		void LZLinkedList_AtIndex()
		{
			LZLinkedList<int> list;

			list.Add(1);
			Assert::AreEqual(1, list.AtIndex(0)->value);

			list.Add(2);
			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(2, list.AtIndex(1)->value);

			list.Add(3);
			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(2, list.AtIndex(1)->value);
			Assert::AreEqual(3, list.AtIndex(2)->value);

			list.RemoveAt(1);
			Assert::AreEqual(1, list.AtIndex(0)->value);
			Assert::AreEqual(3, list.AtIndex(1)->value);
		}
	};
}
