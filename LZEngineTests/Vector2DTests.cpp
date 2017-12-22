#include <gtest\gtest.h>
#include <Math\Vector2D.h>
using LZSoft::Math::Vector2D;

TEST(Vector2D, Constructor)
{
	Vector2D first(1, 2);
	EXPECT_FLOAT_EQ(1, first.x);
	EXPECT_FLOAT_EQ(2, first.y);

	Vector2D a(1, 2);
	EXPECT_EQ(1.f, a.x);
	EXPECT_EQ(2.f, a.y);
	Vector2D b(-1, -2);
	EXPECT_EQ(-1.f, b.x);
	EXPECT_EQ(-2.f, b.y);
	Vector2D c;
	EXPECT_EQ(0.f, c.x);
	EXPECT_EQ(0.f, c.y);
}

TEST(Vector2D, VectorAddition)
{
	Vector2D first(1, 2);
	Vector2D second(3, 4);

	Vector2D result1 = first + second;
	Vector2D result2 = second + first;
	EXPECT_FLOAT_EQ(4, result1.x);
	EXPECT_FLOAT_EQ(6, result1.y);

	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);

	Vector2D a(1, 2);
	Vector2D b(2, 1);
	Vector2D c(-1, -2);
	auto res1 = a + b;
	auto res2 = a + c;
	EXPECT_EQ(3.0f, res1.x);
	EXPECT_EQ(3.0f, res1.y);
	EXPECT_EQ(0.0f, res2.x);
	EXPECT_EQ(0.0f, res2.y);
}

TEST(Vector2D, ScalarMultiplication)
{
	Vector2D vec(-7, 3);
	Vector2D result1 = 8 * vec;
	Vector2D result2 = vec * 8;

	EXPECT_FLOAT_EQ(result1.x, -56);
	EXPECT_FLOAT_EQ(result1.y, 24);
	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);

	Vector2D a(1, 2);
	Vector2D b(-1, -2);
	auto res1 = a * 0;
	auto res2 = a * 1;
	auto res3 = a * 2;
	EXPECT_EQ(0.0f, res1.x);
	EXPECT_EQ(0.0f, res1.y);
	EXPECT_EQ(1.0f, res2.x);
	EXPECT_EQ(2.0f, res2.y);
	EXPECT_EQ(2.0f, res3.x);
	EXPECT_EQ(4.0f, res3.y);
	res1 = b * 0;
	res2 = b * 1;
	res3 = b * 2;
	EXPECT_EQ(0.0f, res1.x);
	EXPECT_EQ(0.0f, res1.y);
	EXPECT_EQ(-1.0f, res2.x);
	EXPECT_EQ(-2.0f, res2.y);
	EXPECT_EQ(-2.0f, res3.x);
	EXPECT_EQ(-4.0f, res3.y);

	res1 = 0 * a;
	res2 = 1 * a;
	res3 = 2 * a;
	EXPECT_EQ(0.0f, res1.x);
	EXPECT_EQ(0.0f, res1.y);
	EXPECT_EQ(1.0f, res2.x);
	EXPECT_EQ(2.0f, res2.y);
	EXPECT_EQ(2.0f, res3.x);
	EXPECT_EQ(4.0f, res3.y);
	res1 = 0 * b;
	res2 = 1 * b;
	res3 = 2 * b;
	EXPECT_EQ(0.0f, res1.x);
	EXPECT_EQ(0.0f, res1.y);
	EXPECT_EQ(-1.0f, res2.x);
	EXPECT_EQ(-2.0f, res2.y);
	EXPECT_EQ(-2.0f, res3.x);
	EXPECT_EQ(-4.0f, res3.y);
}

TEST(Vector2D, AssignmentPlusEquals)
{
	Vector2D source(5, -1234.5678f);
	Vector2D another(1, 1);
	another += source;
	EXPECT_FLOAT_EQ(another.x, 6);
	EXPECT_FLOAT_EQ(another.y, -1233.5678f);
}

TEST(Vector2D, AssignmentMinusEquals)
{
	Vector2D source(5, -1234.5678f);
	Vector2D another(1, 1);
	another -= source;
	EXPECT_FLOAT_EQ(another.x, -4);
	EXPECT_FLOAT_EQ(another.y, 1235.5678f);
}


TEST(Vector2D, Subtraction)
{
	Vector2D a(5, 4);
	Vector2D b(2, 1);
	Vector2D c(5, 4);
	auto res1 = a - b;
	auto res2 = a - c;
	EXPECT_EQ(3.0f, res1.x);
	EXPECT_EQ(3.0f, res1.y);
	EXPECT_EQ(0.0f, res2.x);
	EXPECT_EQ(0.0f, res2.y);
	res1 = b - a;
	res2 = c - a;
	EXPECT_EQ(-3.0f, res1.x);
	EXPECT_EQ(-3.0f, res1.y);
	EXPECT_EQ(0.0f, res2.x);
	EXPECT_EQ(0.0f, res2.y);
};