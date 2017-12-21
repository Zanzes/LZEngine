#include "stdafx.h"
#include <Math\Vector2D.h>

// using namespace System;
//using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using LZSoft::Math::Vector2D;

namespace LZEngineTests
{
	[TestClass]
	public ref class Vector2DTests
	{
	private:
		TestContext ^ testContextInstance;

	public:
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		[TestMethod]
		void Vector2D_Constructor()
		{
			Vector2D a(1, 2);
			Assert::AreEqual(1.f, a.x);
			Assert::AreEqual(2.f, a.y);
			Vector2D b(-1, -2);
			Assert::AreEqual(-1.f, b.x);
			Assert::AreEqual(-2.f, b.y);
			Vector2D c;
			Assert::AreEqual(0.f, c.x);
			Assert::AreEqual(0.f, c.y);
		};

		[TestMethod]
		void Vector2D_Addition()
		{
			Vector2D a(1, 2);
			Vector2D b(2, 1);
			Vector2D c(-1, -2);
			auto res1 = a + b;
			auto res2 = a + c;
			Assert::AreEqual(3.0f, res1.x);
			Assert::AreEqual(3.0f, res1.y);
			Assert::AreEqual(0.0f, res2.x);
			Assert::AreEqual(0.0f, res2.y);
		};

		[TestMethod]
		void Vector2D_Subtraction()
		{
			Vector2D a(5, 4);
			Vector2D b(2, 1);
			Vector2D c(5, 4);
			auto res1 = a - b;
			auto res2 = a - c;
			Assert::AreEqual(3.0f, res1.x);
			Assert::AreEqual(3.0f, res1.y);
			Assert::AreEqual(0.0f, res2.x);
			Assert::AreEqual(0.0f, res2.y);
			res1 = b - a;
			res2 = c - a;
			Assert::AreEqual(-3.0f, res1.x);
			Assert::AreEqual(-3.0f, res1.y);
			Assert::AreEqual(0.0f, res2.x);
			Assert::AreEqual(0.0f, res2.y);
		};

		[TestMethod]
		void Vector2D_ScalorMultiplication()
		{
			Vector2D a(1, 2);
			Vector2D b(-1, -2);
			auto res1 = a * 0;
			auto res2 = a * 1;
			auto res3 = a * 2;
			Assert::AreEqual(0.0f, res1.x);
			Assert::AreEqual(0.0f, res1.y);
			Assert::AreEqual(1.0f, res2.x);
			Assert::AreEqual(2.0f, res2.y);
			Assert::AreEqual(2.0f, res3.x);
			Assert::AreEqual(4.0f, res3.y);
			res1 = b * 0;
			res2 = b * 1;
			res3 = b * 2;
			Assert::AreEqual(0.0f, res1.x);
			Assert::AreEqual(0.0f, res1.y);
			Assert::AreEqual(-1.0f, res2.x);
			Assert::AreEqual(-2.0f, res2.y);
			Assert::AreEqual(-2.0f, res3.x);
			Assert::AreEqual(-4.0f, res3.y);

			res1 = 0 * a;
			res2 = 1 * a;
			res3 = 2 * a;
			Assert::AreEqual(0.0f, res1.x);
			Assert::AreEqual(0.0f, res1.y);
			Assert::AreEqual(1.0f, res2.x);
			Assert::AreEqual(2.0f, res2.y);
			Assert::AreEqual(2.0f, res3.x);
			Assert::AreEqual(4.0f, res3.y);
			res1 = 0 * b;
			res2 = 1 * b;
			res3 = 2 * b;
			Assert::AreEqual(0.0f, res1.x);
			Assert::AreEqual(0.0f, res1.y);
			Assert::AreEqual(-1.0f, res2.x);
			Assert::AreEqual(-2.0f, res2.y);
			Assert::AreEqual(-2.0f, res3.x);
			Assert::AreEqual(-4.0f, res3.y);

		};
	};
}

#pragma region Additional test attributes
//
//You can use the following additional attributes as you write your tests:
//
//Use ClassInitialize to run code before running the first test in the class
//[ClassInitialize()]
//static void MyClassInitialize(TestContext^ testContext) {};
//
//Use ClassCleanup to run code after all tests in a class have run
//[ClassCleanup()]
//static void MyClassCleanup() {};
//
//Use TestInitialize to run code before running each test
//[TestInitialize()]
//void MyTestInitialize() {};
//
//Use TestCleanup to run code after each test has run
//[TestCleanup()]
//void MyTestCleanup() {};
//
#pragma endregion 