#include "stdafx.h"
#include "CppUnitTest.h"
#include "../MethodsFinalProj/Label.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
				
		TEST_METHOD(TestConstructor)
		{
			Label label(10);
			Assert::AreEqual(label.getWidth(), 10);
		}

		TEST_METHOD(TestSetText)
		{
			Label label(10);
			string str = "Test";
			label.setText(str);
			Assert::AreEqual(str, label.getText());
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetWidth)
		{
			Label label(10);
			label.setWidth(12);
			Assert::AreEqual(12, label.getWidth());
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetHeight)
		{
			Label label(10);
			label.setHeight(12);
			Assert::AreEqual(12, label.getHeight());
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetForeground)
		{
			Label label(10);
			label.setForeground(Color::Blue);
			Assert::AreEqual((int)label.getForeground(), (int)Color::Blue);
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetBackground)
		{
			Label label(10);
			label.setBackground(Color::Red);
			Assert::AreEqual((int)label.getBackground(), (int)Color::Red);
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetTop)
		{
			Label label(10);
			label.setTop(2);
			Assert::AreEqual(label.getTop(), 2);
			// TODO: Your test code here
		}


		TEST_METHOD(TestSetLeft)
		{
			Label label(10);
			label.setLeft(2);
			Assert::AreEqual(label.getLeft(), 2);
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetBorder)
		{
			Label label(10);
			label.setBorder(BorderType::SINGEL);
			Assert::AreEqual((int)label.getBorder(), (int)BorderType::SINGEL);
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetLayer)
		{
			Label label(10);
			label.setLayer(1);
			Assert::AreEqual((int)label.getLayer(), 1);
			// TODO: Your test code here
		}

		TEST_METHOD(TestShow)
		{
			Label label(10);
			label.show();
			Assert::AreEqual(label.isVisible(), true);
			// TODO: Your test code here
		}

		TEST_METHOD(TestHide)
		{
			Label label(10);
			label.hide();
			Assert::AreEqual(label.isVisible(), false);
			// TODO: Your test code here
		}

		TEST_METHOD(TestSetCanGetFocus)
		{
			Label label(10);
			label.setCanGetFocus(false);
			Assert::AreEqual(label.canGetFocus(), false);
			// TODO: Your test code here
		}

	};
}