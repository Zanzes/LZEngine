#include <gtest\gtest.h>
#include <DataStructures/LZLinkedList.h>

using LZSoft::DataStructures::LZLinkedList;

TEST(LZLinkedList, Rotation)
{
	LZLinkedList<int> list;
	EXPECT_EQ(0, list.Count);
	EXPECT_TRUE(list.Head == nullptr);
	EXPECT_TRUE(list.Tail == nullptr);

	list.Add(2);
	EXPECT_EQ(1, list.Count);
	EXPECT_FALSE(list.Head == nullptr);
	EXPECT_FALSE(list.Tail == nullptr);

}

TEST(LZLinkedList, Add)
{
	LZLinkedList<int> list;

	list.Add(1);
	EXPECT_EQ(1, list.Count);

	list.Add(2);
	EXPECT_EQ(2, list.Count);

	list.Add(3);
	EXPECT_EQ(3, list.Count);

	EXPECT_EQ(1, list.Head->previous->previous->value);
	EXPECT_EQ(2, list.Head->previous->value);
	EXPECT_EQ(3, list.Head->value);

	EXPECT_EQ(1, list.Tail->value);
	EXPECT_EQ(2, list.Tail->next->value);
	EXPECT_EQ(3, list.Tail->next->next->value);
}

TEST(LZLinkedList, Remove)
{
	LZLinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);

	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(2, list.AtIndex(1)->value);
	EXPECT_EQ(3, list.AtIndex(2)->value);
	EXPECT_EQ(3, list.Count);

	list.Remove(list.Head->previous);

	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(3, list.AtIndex(1)->value);
	EXPECT_EQ(2, list.Count);
}
TEST(LZLinkedList, RemoveHead)
{
	LZLinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);

	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(2, list.AtIndex(1)->value);
	EXPECT_EQ(3, list.AtIndex(2)->value);
	EXPECT_EQ(3, list.Count);

	list.RemoveHead();

	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(2, list.AtIndex(1)->value);
	EXPECT_EQ(2, list.Count);

	list.RemoveHead();

	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(1, list.Count);

	list.RemoveHead();

	EXPECT_EQ(0, list.Count);
}
TEST(LZLinkedList, RemoveTail)
{
	LZLinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);

	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(2, list.AtIndex(1)->value);
	EXPECT_EQ(3, list.AtIndex(2)->value);
	EXPECT_EQ(3, list.Count);

	list.RemoveTail();

	EXPECT_EQ(2, list.AtIndex(0)->value);
	EXPECT_EQ(3, list.AtIndex(1)->value);
	EXPECT_EQ(2, list.Count);

	list.RemoveTail();

	EXPECT_EQ(3, list.AtIndex(0)->value);
	EXPECT_EQ(1, list.Count);

	list.RemoveTail();

	EXPECT_EQ(0, list.Count);
}
TEST(LZLinkedList, AtIndex)
{
	LZLinkedList<int> list;

	list.Add(1);
	EXPECT_EQ(1, list.AtIndex(0)->value);

	list.Add(2);
	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(2, list.AtIndex(1)->value);

	list.Add(3);
	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(2, list.AtIndex(1)->value);
	EXPECT_EQ(3, list.AtIndex(2)->value);

	list.RemoveAt(1);
	EXPECT_EQ(1, list.AtIndex(0)->value);
	EXPECT_EQ(3, list.AtIndex(1)->value);
}