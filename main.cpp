#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include <iomanip>

using namespace std;
//universal
void intro();

struct registration {

	int numero =0;
	string title;
	string date;
	string object;
	string content;

};
string fileName(int number);
//Show
void read(string path);
void show(string path);
//Writing
string odata(registration content);
int identifyNumber(string IndexPath);
registration contenuto();
void writeFile(string Path);
//Index
void registerIndex(string IndexPath, registration reg);
//
void command(bool& isOpen, string path, string cmand);

int main()
{
	string spath = "C:\\Users\\yahya\\Desktop\\savings";
	string path = spath + "\\";
	intro();
	bool open = true;
	string input = "";
	while (open)
	{
		cout << "\n" << spath << ">";
		cin >> input;
		command(open, path,input);
	}
	return 0;
}
//Universal
void intro()
{
	cout << "*********************************************" << "\n\n\n* Brain. industries. \n* Welcome to Brain's Field Terminal.\n* feel free to express your thoughts in here!" << "\n\n\n*********************************************\n\n" << endl;
}
void command(bool& isOpen, string path,string cmand)
{
	if (cmand == "quit")
	{
		isOpen = false;
	}
	else if (cmand == "write")
	{
		writeFile(path);
	}
	else if (cmand == "show")
	{
		show(path);
	}
	else
		cout << "\ncommand not defined";
}
string fileName(int number)
{
	return "File" + to_string(number) + ".txt";
}
//write
void writeFile(string Path)
{
	string indexPath = Path + "Index.config";
	
	registration content = contenuto();
	content.numero = identifyNumber(indexPath);
	string filePath = Path+ "Data\\" + fileName(content.numero);
	ofstream File(filePath);
	File << odata(content);
	File.close();
	registerIndex(indexPath, content);

}
registration contenuto()
{
	registration file;
	cout << "\n------------------------------------------------";
	cout << "\n\nDate: ";
	cin >> file.date;
	cout << "\nTitle: ";
	cin.ignore();
	getline(std::cin, file.title);
	cout << "\n>>";
	getline(std::cin, file.content);
	cout << "\n\n------------------------------------------------";

	return file;

}
int identifyNumber(string IndexPath)
{
	int a = 0;
	string line;
	ifstream Index(IndexPath, ifstream::in);

	while (getline(Index, line))
	{
		a++;
	}
	Index.close();
	return a;
}
string odata(registration content)
{
	return "Date: " + content.date + "\nNumber: " + to_string(content.numero) + "\nTitle: " + content.title + "\n" + content.object + "\n \n>>" + content.content;
}
void registerIndex(string IndexPath, registration reg)
{
	ofstream Index(IndexPath, ofstream::out | ofstream::app);

	string Line = to_string(reg.numero) + "-" + reg.title + "-" + reg.date + ".\n";
	Index << Line;

	Index.close();
}
//show
void show(string path)
{
	string indexPath = path + "Index.config";
	read(indexPath);
	int fileNumber;
	cout << "\ninsert file number: ";
	cin >> fileNumber;
	string filePath = path + "Data\\" + fileName(fileNumber);
	read(filePath);

}
void read(string path)
{
	ifstream fileRead(path, ifstream::in);
	string line;
	while (getline(fileRead, line))
	{

		cout<<"\n" << line;
	}
	fileRead.close();
}
