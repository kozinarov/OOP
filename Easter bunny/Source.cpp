#include "Basket.h"
#include "WorkWithFiles.h"

using namespace std;

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

void Test1()
{
	//read one object make a report and read it
	cout << "Test read one object make a report and read it" << endl;
	Basket b;
	b = initializeObject1();
	cout << b.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
	{
		cout << b[i].getName() << " " << b[i].getSize() << endl;
	}
	cout << endl;
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
	cout << newB.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
	{
		cout << newB[i].getName() << " " << newB[i].getSize() << endl;
	}
}
void Test2()
{
	//operator[int]
	Basket b;
	b = initializeObject1();
	Egg e;
	cout << endl << "Test operator[int]" << endl;
	e = b[0];
	cout << e.getName() << " " << e.getSize() << endl;
}
void Test3()
{
	//operator[char*]
	Basket b;
	b = initializeObject1();
	Egg e;
	cout << endl << "Test operator[char*]" << endl;
	e = b["a"];
	cout << e.getName() << " " << e.getSize() << endl;
}
void Test4()
{
	//operator+=(const Basket&)
	Basket b, newB;
	cout << endl << "Test operator+=(cosnt Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	b += newB;
	cout << b.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
		cout << b[i].getName() << " " << b[i].getSize() << endl;

}
void Test5()
{
	//operator+(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator+(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	Basket newNewB;
	newNewB = b + newB;
	cout << newNewB.getBasketName() << endl;
	for (size_t i = 0; i < newNewB.getSize(); i++)
		cout << newNewB[i].getName() << " " << newNewB[i].getSize() << endl;
}
void Test6()
{
	//operator+=(const char*)
	Basket b;
	cout << endl << "Test operator+=(cosnt char*)" << endl;
	b = initializeObject1();
	char *suf = "sssss";
	b += suf;
	cout << b.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
		cout << b[i].getName() << " " << b[i].getSize() << endl;
}
void Test7()
{
	//operator+(cosnt Basket&, const char*)
	Basket b;
	cout << endl << "Test operator+(cosnt Basket&, const char*)" << endl;
	b = initializeObject1();
	Basket newB;
	char *suf = "sssss";
	newB = b + suf;
	cout << newB.getBasketName() << endl;
	for (size_t i = 0; i < newB.getSize(); i++)
		cout << newB[i].getName() << " " << newB[i].getSize() << endl;
}
void Test8()
{
	//operator*=(const int)
	Basket b;
	cout << endl << "Test operator*=(cosnt int)" << endl;
	b = initializeObject1();
	int num = 5;
	b *= num;
	cout << b.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
		cout << b[i].getName() << " " << b[i].getSize() << endl;
}
void Test9()
{

	//operator*(cosnt Basket&, const int)
	Basket b;
	cout << endl << "Test operator*(cosnt Basket&, const int)" << endl;
	b = initializeObject1();
	int num = 5;
	Basket newB;
	newB = b * num;
	cout << newB.getBasketName() << endl;
	for (size_t i = 0; i < newB.getSize(); i++)
		cout << newB[i].getName() << " " << newB[i].getSize() << endl;
}
void Test10()
{
	//operator/=(const int)
	Basket b;
	cout << endl << "Test operator/=(cosnt int)" << endl;
	b = initializeObject1();
	int num = 2;
	//size is int not double therefor  0 1 1
	b /= num;
	cout << b.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
		cout << b[i].getName() << " " << b[i].getSize() << endl;
}
void Test11()
{
	//operator/(cosnt Basket&, const int)
	Basket b;
	cout << endl << "Test operator/(cosnt Basket&, const int)" << endl;
	b = initializeObject1();
	Basket newB;
	int num = 2;
	//size is int not double therefor  0 1 1
	newB = b / num;
	cout << newB.getBasketName() << endl;
	for (size_t i = 0; i < newB.getSize(); i++)
		cout << newB[i].getName() << " " << newB[i].getSize() << endl;
}
void Test12()
{
	//operator%=(cosnt Basket&, const int)
	cout << endl << "Test operator%=(cosnt Basket&, const int)" << endl;
	Basket b, newB;
	b = initializeObject1();
	newB = initializeObject2();
	//example is with completely different baskets therefor the % is empty basket
	b %= newB;
	cout << b.getBasketName() << endl;
	for (size_t i = 0; i < b.getSize(); i++)
		cout << b[i].getName() << " " << b[i].getSize() << endl;
}
void Test13()
{
	//operator%(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator%(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	Basket new6B;
	//example is with completely different baskets therefor the % is empty basket
	new6B = b % newB;
	cout << new6B.getBasketName() << endl;
	for (size_t i = 0; i < new6B.getSize(); i++)
		cout << new6B[i].getName() << " " << new6B[i].getSize() << endl;
}
void Test14()
{
	//operator==(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator==(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject1();
	if (newB == b)
		cout << "They are equal" << endl;
	else
		cout << "They are Not equal" << endl;
}
void Test15()
{
	//operator!=(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator!=(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	if (newB != b)
		cout << "They are Not equal" << endl;
	else
		cout << "They are equal" << endl;
}
void Test16()
{
	//operator<(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator<(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	if (b < newB)
		cout << "The left is lower" << endl;
	else
		cout << "The left is Not lower" << endl;
}
void Test17()
{
	//operator<=(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator<=(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	if (b <= newB)
		cout << "The left is lower or they are equal" << endl;
	else
		cout << "The left is Not lower and they are Not equal" << endl;
}
void Test18()
{
	//operator>=(cosnt Basket&, const Basket&)
	Basket b, newB;
	cout << endl << "Test operator>=(cosnt Basket&, const Basket&)" << endl;
	b = initializeObject1();
	newB = initializeObject2();
	if (b >= newB)
		cout << "The left is bigger or they are equal" << endl;
	else
		cout << "The left is Not biger and they are Not equal" << endl;
}


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();
	Test10();
	Test11();
	Test12();
	Test13();
	Test14();
	Test15();
	Test16();
	Test17();
	Test18();

	return 0;
}
