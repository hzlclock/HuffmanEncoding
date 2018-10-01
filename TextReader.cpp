#include "TextReader.h"



TextReader::TextReader(string fileName)
{
	data = "";
	string line;
	ifstream fileStream;
	fileStream.open(fileName);
	if (fileStream.is_open()){
		while (getline(fileStream, line)){
			data += line+'\n';
		}
	}
	fileStream.close();
}

TextReader::~TextReader()
{
	
}

std::string TextReader::GetString()
{
	return data;
}
