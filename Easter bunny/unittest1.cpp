#include "stdafx.h"
#include "CppUnitTest.h"
#include "../dom3/Basket.h"
#include "../dom3/Egg.h"
#include "../dom3/WorkWithFiles.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BasketTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFiles)
		{
			Basket b;
			b = initializeObject1();
			write_Basket(b);
			write_report(b);
			Basket newB;
			try
			{
				newB = read_Basket("Stavri");
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
			}
			for (size_t i = 0; i < b.getSize(); i++)
			{
				Assert::AreEqual(strcmp(newB[i].getName(), b[i].getName()), 0);
				Assert::AreEqual(newB[i].getSize(), b[i].getSize());
			}
			

		}

		TEST_METHOD(TestOperators1)
		{
			Basket b;
			b = initializeObject1();
			Egg e;
			e = b[0];
			Assert::AreEqual(e.getName(), "a");
			Assert::AreEqual(e.getSize(), 1);
		}

		TEST_METHOD(TestOperators2)
		{
			Basket b;
			b = initializeObject1();
			Egg e;
			e = b["a"];
			Assert::AreEqual(e.getName(), "a");
			Assert::AreEqual(e.getSize(), 1);
		}

		TEST_METHOD(TestOperators3)
		{
			//operator+=(const Basket&)
			Basket b, newB, tmpB;
			b = initializeObject1();
			//tmpB and newB dont change only b is changing
			tmpB = initializeObject1();
			newB = initializeObject2();
			b += newB;

			Assert::AreEqual(strcmp(b.getBasketName(), "StavriGosho"), 0);
			int cnt = 0;
			for (size_t i = 0; i < tmpB.getSize(); i++)
			{
				Assert::AreEqual(strcmp(b[cnt].getName(), tmpB[i].getName()), 0);
				Assert::AreEqual(b[cnt].getSize(), tmpB[i].getSize());
				cnt++;
			}

			for (size_t i = 0; i < newB.getSize(); i++)
			{
				Assert::AreEqual(strcmp(b[cnt].getName(), newB[i].getName()), 0);
				Assert::AreEqual(b[cnt].getSize(), newB[i].getSize());
				cnt++;
			}
		}

		TEST_METHOD(TestOperators4)
		{
			//operator+(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Basket newNewB;
			newNewB = b + newB;

			Assert::AreEqual(strcmp(newNewB.getBasketName(), "StavriGosho"), 0);
			int cnt = 0;
			for (size_t i = 0; i < b.getSize(); i++)
			{
				Assert::AreEqual(strcmp(newNewB[cnt].getName(), b[i].getName()), 0);
				Assert::AreEqual(newNewB[cnt].getSize(), b[i].getSize());
				cnt++;
			}

			for (size_t i = 0; i < newB.getSize(); i++)
			{
				Assert::AreEqual(strcmp(newNewB[cnt].getName(), newB[i].getName()), 0);
				Assert::AreEqual(newNewB[cnt].getSize(), newB[i].getSize());
				cnt++;
			}
		
		}
		
		TEST_METHOD(TestOperators5)
		{
			//operator+=(const char*)
			Basket b;
			b = initializeObject1();
			char *suf = "sssss";
			b += suf;
			Assert::AreEqual(strcmp(b[0].getName(), "asssss"), 0);
			Assert::AreEqual(strcmp(b[1].getName(), "bsssss"), 0);
			Assert::AreEqual(strcmp(b[2].getName(), "csssss"), 0);
		}

		TEST_METHOD(TestOperators6)
		{
			//operator+(cosnt Basket&, const char*)
			Basket b, newB;
			b = initializeObject1();

			char *suf = "sssss";
			newB = b + suf;
			Assert::AreEqual(strcmp(newB[0].getName(), "asssss"), 0);
			Assert::AreEqual(strcmp(newB[1].getName(), "bsssss"), 0);
			Assert::AreEqual(strcmp(newB[2].getName(), "csssss"), 0);
	
		}

		TEST_METHOD(TestOperators7)
		{
			//operator*=(const int)
			Basket b;
			b = initializeObject1();
			int num = 5;
			b *= num;
			Assert::AreEqual(b[0].getSize(), 5);
			Assert::AreEqual(b[1].getSize(), 10);
			Assert::AreEqual(b[2].getSize(), 15);

		}

		TEST_METHOD(TestOperators8)
		{
			//operator*(cosnt Basket&, const int)
			Basket b;
			b = initializeObject1();
			int num = 5;
			Basket newB;
			newB = b * num;
			Assert::AreEqual(newB[0].getSize(), 5);
			Assert::AreEqual(newB[1].getSize(), 10);
			Assert::AreEqual(newB[2].getSize(), 15);
		}

		TEST_METHOD(TestOperators9)
		{
			//operator/=(const int)
			Basket b;
			cout << endl << "Test operator/=(cosnt int)" << endl;
			b = initializeObject1();
			int num = 2;
			//size is int not double therefor  0 1 1
			b /= num;
			Assert::AreEqual(b[0].getSize(), 0);
			Assert::AreEqual(b[1].getSize(), 1);
			Assert::AreEqual(b[2].getSize(), 1);
		}

		TEST_METHOD(TestOperators10)
		{
			//operator/(cosnt Basket&, const int)
			Basket b;
			b = initializeObject1();
			Basket newB;
			int num = 2;
			//size is int not double therefor  0 1 1
			newB = b / num;
			Assert::AreEqual(newB[0].getSize(), 0);
			Assert::AreEqual(newB[1].getSize(), 1);
			Assert::AreEqual(newB[2].getSize(), 1);
			
		}

		TEST_METHOD(TestOperators11)
		{
			//operator%=(cosnt Basket&, const int)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Egg e;
			e.setName("sss");
			e.setSize(555);
			b.addEgg(e);
			newB.addEgg(e);
			//now the two baskets have only one the same egg and it's with name ss and size 555 after the % only this egg have to stay
			b %= newB;
			for (size_t i = 0; i < b.getSize(); i++)
			{
				Assert::AreEqual(strcmp(b[i].getName(), "sss"), 0);
				Assert::AreEqual(b[i].getSize(), 555);
			}
			
			
		}

		TEST_METHOD(TestOperators12)
		{

			//operator%(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Egg e;
			e.setName("sss");
			e.setSize(555);
			b.addEgg(e);
			newB.addEgg(e);

			Basket new6B;
			new6B = b % newB;
			for (size_t i = 0; i < new6B.getSize(); i++)
			{
				Assert::AreEqual(strcmp(new6B[i].getName(), "sss"), 0);
				Assert::AreEqual(new6B[i].getSize(), 555);
			}

		}

		TEST_METHOD(TestOperators13)
		{
			//operator==(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject1();
			Assert::IsTrue(b == newB);
		}

		TEST_METHOD(TestOperators14)
		{
			//operator!=(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Assert::IsTrue(b != newB);
		}

		TEST_METHOD(TestOperators15)
		{
			//operator<(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Assert::IsTrue(b < newB);
		}
		TEST_METHOD(TestOperators16)
		{
			//operator<=(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Assert::IsTrue(b <= newB);
		}
		TEST_METHOD(TestOperators17)
		{
			//operator>=(cosnt Basket&, const Basket&)
			Basket b, newB;
			b = initializeObject1();
			newB = initializeObject2();
			Assert::IsFalse(b >= newB);
		}

		Basket initializeObject1()
		{
			Egg e;
			Basket b;
			b.setBasketName("Stavri");

			e.setName("a");
			e.setSize(1);
			b.addEgg(e);

			e.setName("b");
			e.setSize(2);
			b.addEgg(e);

			e.setName("c");
			e.setSize(3);
			b.addEgg(e);

			return b;
		}

		Basket initializeObject2()
		{
			Egg e;
			Basket b;
			b.setBasketName("Gosho");

			e.setName("d");
			e.setSize(4);
			b.addEgg(e);

			e.setName("e");
			e.setSize(5);
			b.addEgg(e);

			e.setName("f");
			e.setSize(6);
			b.addEgg(e);

			return b;
		}

	};
}