#include <iostream>
#include <string>
#include "List.h"
#include "MyClasses.h"
#include <fstream>
class Saver {
public:
	void setFilePath(const std::string str) {
		filePath = str;
	}
	void setList(List<Computer>* list) {
		this->list = list;
	}
	std::string getPath() {
		return filePath;
	}
	List<Computer>* getList() {
		return list;
	}
	Saver(const std::string str, List<Computer>* list) {
		setFilePath(str);
		setList(list);
	}
	virtual void save() {
		
	}
	virtual void load() {

	}
private:
	std::string filePath;
	List<Computer>* list;

};
class SaverText : public Saver {
public:
	SaverText(const std::string str, List<Computer>* list) : Saver(str, list) {};
	void save() override{
		std::cout << "Succes(TXT)\n\n\n";
		std::ofstream outputFile(getPath());
		if (outputFile.is_open()) {
			for (int i = 0;i < getList()->getSize();i++) {
				outputFile << getList()->getNode(i)->date->getType() << '\n';
				outputFile << getList()->getNode(i)->date->createSaveString() << '\n';
			}
			outputFile.close();
		}
		else
		{
			throw 21;
		}
		outputFile.close();
	}
	void load() {
		std::cout << "Succes(TXT)\n\n\n";
		std::ifstream file(getPath());
		if (file.is_open()) {
			std::string temp;
			std::string fields[6];
			while (std::getline(file,temp))
			{
				if (temp == "1") {	
					setFields(file, new Computer());
				}
				if (temp == "2") {
					setFields(file, new Desktop());
				}
				if (temp == "3") {
					setFields(file, new Portable());
				}
				if (temp == "4") {
					setFields(file, new Monoblock());
				}
				if (temp == "5") {
					setFields(file, new Laptop());
				}
				if (temp == "6") {
					setFields(file, new Tablet());
				}
			}
		}
		else
		{
			file.close();
			throw 21;
		}
		file.close();
	}
	void setFields(std::ifstream& file,Computer* computer) {
		std::string fields[2];
		std::getline(file, fields[0]);
		std::getline(file, fields[1]);
		computer->setModel(fields[0].c_str());
		computer->setOwner(fields[1].c_str());
		getList()->addNode(new NodeOfList<Computer>(computer));
	}
	void setFields(std::ifstream& file, Desktop* computer) {
		std::string fields[3];
		std::getline(file, fields[0]);
		std::getline(file, fields[1]);
		std::getline(file, fields[2]);
		computer->setModel(fields[0].c_str());
		computer->setOwner(fields[1].c_str());
		computer->setBox(fields[2].c_str());
		getList()->addNode(new NodeOfList<Computer>(computer));
	}
	void setFields(std::ifstream& file, Portable* computer) {
		std::string fields[4];
		std::getline(file, fields[0]);
		std::getline(file, fields[1]);
		std::getline(file, fields[2]);
		std::getline(file, fields[3]);
		computer->setModel(fields[0].c_str());
		computer->setOwner(fields[1].c_str());
		computer->setPower(std::stoi(fields[2]));
		computer->setScreensize(std::stod(fields[3]));
		getList()->addNode(new NodeOfList<Computer>(computer));
	}
	void setFields(std::ifstream& file, Laptop* computer) {
		std::string fields[5];
		std::getline(file, fields[0]);
		std::getline(file, fields[1]);
		std::getline(file, fields[2]);
		std::getline(file, fields[3]);
		std::getline(file, fields[4]);
		computer->setModel(fields[0].c_str());
		computer->setOwner(fields[1].c_str());
		computer->setPower(std::stoi(fields[2]));
		computer->setScreensize(std::stod(fields[3]));
		computer->setCountOfKeys(std::stoi(fields[4]));
		getList()->addNode(new NodeOfList<Computer>(computer));
	}
	void setFields(std::ifstream& file, Monoblock* computer) {
		std::string fields[4];
		std::getline(file, fields[0]);
		std::getline(file, fields[1]);
		std::getline(file, fields[2]);
		std::getline(file, fields[3]);
		computer->setModel(fields[0].c_str());
		computer->setOwner(fields[1].c_str());
		computer->setBox(fields[2].c_str());
		computer->setScreensize(std::stod(fields[3]));
		getList()->addNode(new NodeOfList<Computer>(computer));
	}
	void setFields(std::ifstream& file, Tablet* computer) {
		std::string fields[5];
		std::getline(file, fields[0]);
		std::getline(file, fields[1]);
		std::getline(file, fields[2]);
		std::getline(file, fields[3]);
		std::getline(file, fields[4]);
		computer->setModel(fields[0].c_str());
		computer->setOwner(fields[1].c_str());
		computer->setPower(std::stoi(fields[2]));
		computer->setScreensize(std::stod(fields[3]));
		computer->setModem(fields[4].c_str());
		getList()->addNode(new NodeOfList<Computer>(computer));
	}
};


class SaverBin : public Saver {
public:
	SaverBin(const std::string str, List<Computer>* list) : Saver(str, list) {};

	void save() override {
		std::cout << "Succes(BIN)\n\n\n";
		std::ofstream outputFile(getPath(), std::ios::binary);
		if (outputFile.is_open()) {
			for (int i = 0;i < getList()->getSize();i++) {
				int temp = getList()->getNode(i)->date->getType();
				outputFile.write((char*)&temp, sizeof(int));
				if (temp == 1) {
					outputFile.write((char*)getList()->getNode(i)->date, sizeof(Computer));
				}
				if (temp == 2) {
					outputFile.write((char*)getList()->getNode(i)->date, sizeof(Desktop));
				}
				if (temp == 3) {
					outputFile.write((char*)getList()->getNode(i)->date, sizeof(Portable));
				}
				if (temp == 4) {
					outputFile.write((char*)getList()->getNode(i)->date, sizeof(Monoblock));
				}
				if (temp == 5) {
					outputFile.write((char*)getList()->getNode(i)->date, sizeof(Laptop));
				}
				if (temp == 6) {
					outputFile.write((char*)getList()->getNode(i)->date, sizeof(Tablet));
				}
		}
				
			
			outputFile.close();
		}
		else {
			throw 21;
			outputFile.close();
		}
	}

	void load() override {
		std::cout << "Succes(BIN)\n\n\n";
		std::ifstream inputFile(getPath(), std::ios::binary);
		if (inputFile.is_open()) {
			while (!inputFile.eof())
			{
				int temp = 0;
				inputFile.read((char*)&temp, sizeof(int));
				if (temp == 1) {
					Computer* computer = new Computer();
					inputFile.read((char*)computer, sizeof(Computer));
					getList()->addNode(new NodeOfList<Computer>(computer));
				}
				if (temp == 2) {
					Desktop* computer = new Desktop();
					inputFile.read((char*)computer, sizeof(Desktop));
					getList()->addNode(new NodeOfList<Computer>(computer));
				}
				if (temp == 3) {
					Portable* computer = new Portable();
					inputFile.read((char*)computer, sizeof(Portable));
					getList()->addNode(new NodeOfList<Computer>(computer));
				}
				if (temp == 4) {
					Monoblock* computer = new Monoblock();
					inputFile.read((char*)computer, sizeof(Monoblock));
					getList()->addNode(new NodeOfList<Computer>(computer));
				}
				if (temp == 5) {
					Laptop* computer = new Laptop();
					inputFile.read((char*)computer, sizeof(Laptop));
					getList()->addNode(new NodeOfList<Computer>(computer));
				}
				if (temp == 6) {
					Tablet* computer = new Tablet();
					inputFile.read((char*)computer, sizeof(Tablet));
					getList()->addNode(new NodeOfList<Computer>(computer));
				}
			}
		}
		else {
			throw 21;
			inputFile.close();
		}
		inputFile.close();
	}
};

