#pragma once

#ifndef __WorkWithFiles_HEADER__
#define __WorkWithFiles_HEADER__

#include <fstream>
using namespace std;


void write_Basket(const Basket& b)
{
	int sizeFileName = strlen(b.getBasketName()) + strlen(".dat") + 1;
	char *filename = new(nothrow) char[sizeFileName];
	strcpy_s(filename, sizeFileName, b.getBasketName());
	strcat_s(filename, sizeFileName, ".dat");


	ofstream basket_f(filename, ios::out | ios::app | ios::binary);
	if (!basket_f.is_open()) { return; }

	size_t size = b.getSize();
	size_t cap = b.getCap();
	char* bName = b.getBasketName();
	size_t basketNameLen = strlen(bName);

	basket_f.write((char*)&size, sizeof(size));
	basket_f.write((char*)&cap, sizeof(cap));
	basket_f.write((char*)&basketNameLen, sizeof(basketNameLen));
	basket_f.write(bName, basketNameLen);
	
	for (size_t i = 0; i < b.getSize(); ++i)
	{
		Egg e = b[i];
		char* eName = e.getName();
		size_t eNameLen = strlen(eName);
		int eSize = e.getSize();

		basket_f.write((char*)&eNameLen, sizeof(eNameLen));
		basket_f.write(eName, eNameLen);
		basket_f.write((char*)&eSize, sizeof(eSize));

	}

	basket_f.close();
	delete[] filename;
}

Basket read_Basket(char* basketName)
{
	int sizeFileName = strlen(basketName) + strlen(".dat") + 1;
	char *filename = new(nothrow) char[sizeFileName];
	strcpy_s(filename, sizeFileName, basketName);
	strcat_s(filename, sizeFileName, ".dat");

	ifstream basket_f(filename, ios::in | ios::binary); 
	if (!basket_f.is_open()) { throw std::exception("file didn't open"); }

	Basket b;
	size_t size, cap;

	char * bName;
	size_t basketNameLen = 0;
	basket_f.read((char*)&size, sizeof(size));
	basket_f.read((char*)&cap, sizeof(cap));
	basket_f.read((char*)&basketNameLen, sizeof(basketNameLen));
	bName = new(nothrow) char[basketNameLen];
	basket_f.read(bName, basketNameLen);
	bName[basketNameLen] = '\0';

	b.setBasketName(bName);

	for (size_t i = 0; i < size; ++i)
	{
		Egg e;
		char *eName;
		size_t eNameLen = 0;
		int eSize;

		basket_f.read((char*)&eNameLen, sizeof(eNameLen));
		//exeption
		eName = new(nothrow) char[eNameLen];
		basket_f.read(eName, eNameLen);
		eName[eNameLen] = '\0';
		basket_f.read((char*)&eSize, sizeof(eSize));
		
		e.setName(eName);
		e.setSize(eSize);
		b.addEgg(e);
	}

	basket_f.close();
	delete[] filename;
	return b;
}


void write_report(const Basket& b)
{

	int sizeFileName = strlen("report_") + strlen(b.getBasketName()) + strlen(".txt") + 1;
	char *filename = new(nothrow) char[sizeFileName];
	strcpy_s(filename, sizeFileName, "report_");
	strcat_s(filename, sizeFileName, b.getBasketName());
	strcat_s(filename, sizeFileName, ".txt");
	

	ofstream report_f(filename);
	if (!report_f.is_open()) { return; }


	for (size_t i = 0; i < b.getSize(); ++i)
	{
		Egg e = b[i];
		report_f << e.getName() << " " << e.getSize() << endl;
	}

	report_f.close();
	delete[] filename;
}
#endif //__WorkWithFiles_HEADER__