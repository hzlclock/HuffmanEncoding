#pragma once
#include<string>
#include<fstream>
using namespace std;

class TextReader
{
	string data;

public:
	TextReader(string fileName);
	~TextReader();

	string GetString();
};

