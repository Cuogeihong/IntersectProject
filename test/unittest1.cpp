#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Intersect/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addLine(0, 0, 1, 1);
			img->addLine(1, -1, 0, 0);
			Assert::AreEqual(img->getNum(), 1);
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addLine(0, 0, 1, 1);
			img->addLine(3, 4, 4, 5);
			Assert::AreEqual(img->getNum(), 0);
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addLine(0, 0, 1, 1);
			img->addLine(-1, 1, 1, -1);
			img->addLine(3, 4, -3, -4);
			Assert::AreEqual(img->getNum(), 1);
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addLine(0, 0, 1, 1);
			img->addLine(-1, 1, 1, -1);
			img->addLine(3, 4, -4, -3);
			Assert::AreEqual(img->getNum(), 2);
		}
		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 1);
			img->addLine(0, 0, 1, 1);
			Assert::AreEqual(img->getNum(), 2);
		}
		TEST_METHOD(TestMethod6)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 1);
			img->addLine(0, 1, 1, 1);
			Assert::AreEqual(img->getNum(), 1);
		}
		TEST_METHOD(TestMethod7)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 1);
			img->addLine(2, 2, 2, 0);
			Assert::AreEqual(img->getNum(), 0);
		}
		TEST_METHOD(TestMethod8)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 1);
			img->addCircle(2, 0, 1);
			Assert::AreEqual(img->getNum(), 1);
		}
		TEST_METHOD(TestMethod9)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 1);
			img->addCircle(1, 0, 1);
			Assert::AreEqual(img->getNum(), 2);
		}
		TEST_METHOD(TestMethod10)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 1);
			img->addCircle(3, 0, 1);
			cout << img->getNum() << endl;
			Assert::AreEqual(img->getNum(), 0);
		}
		TEST_METHOD(TestMethod11)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 4);
			img->addCircle(3, 0, 1);
			cout << img->getNum() << endl;
			Assert::AreEqual(img->getNum(), 1);
		}
		TEST_METHOD(TestMethod12)
		{
			// TODO: 在此输入测试代码
			Image *img = new Image();
			img->addCircle(0, 0, 4);
			img->addCircle(0, 1, 1);
			cout << img->getNum() << endl;
			Assert::AreEqual(img->getNum(), 0);
		}
	};
}