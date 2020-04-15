#include "TestFile.h"
#include <assert.h> 
#include <iostream>


TestRepositoryFile::TestRepositoryFile()
{

	assert(repo.getSize() == 0);
}

void TestRepositoryFile::testLoadFromFile()
{
	repo.loadFromFile("TestProj.txt");
	//assert(repo.getSize() == 4);
}

void TestRepositoryFile::testAddElem()
{
	repo.loadFromFile("TestProj.txt");
	repo.addElem(Masina("Ciprian", "afsd", "liber"));
	assert(repo.getSize() == 5);
	repo.saveToFile();
}

void TestRepositoryFile::testFindElem()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.findElem(Masina("Ciprian", "fdghg", "liber")) == 4);
	assert(repo.findElem(Masina("abc", "rtuyjh", "liber")) == -1);
	repo.saveToFile();
}

void TestRepositoryFile::testDelElem()
{
	repo.loadFromFile("TestProj.txt");
	repo.deleteElem(Masina("Ciprian", "rethfg", "liber"));
	assert(repo.getSize() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testGetAll()
{
	repo.loadFromFile("TestProj.txt");
	list<Masina> rez = repo.getAll();
	assert(rez.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testUpdateElem()
{
	repo.loadFromFile("TestProj.txt");
	repo.updateElem(Masina("BogdanPop", "Ciprian", "liber"), Masina("abc", "Ciprian", "liber"));
	assert(repo.findElem(Masina("abc", "Ciprian", "liber")) == 0);
	repo.saveToFile();
}

void TestRepositoryFile::testElemAtPos()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.getItemFromPos(0) == Masina("abc", "Ciprian", "liber"));
	repo.saveToFile();
}

void TestRepositoryFile::testSize()
{
	repo.loadFromFile("TestProj.txt");
	assert(repo.getSize() == 4);
}

void TestRepositoryFile::testSaveToFile()
{
	repo.loadFromFile("TestProj.txt");
	int n = repo.getSize();
	repo.addElem(Masina("Ciprian", "Ciprian", "liber"));
	repo.saveToFile();
	repo.loadFromFile("TestProj.txt");
	assert(repo.getAll().size() == (n + 1));

}


TestRepositoryFile::~TestRepositoryFile()
{
}