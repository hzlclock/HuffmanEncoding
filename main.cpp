#include <iostream>
#include "Heap.h"
#include "TextReader.h"
#include "Char.h"
using namespace std;
Char Chars[256];
Heap<int> HeapMain;
TextReader TxtReader("Text.txt");
string Text;
bool min(int a, int b){
	if (a < b)return true;
	else return false;
}
void Init(){
	Text = TxtReader.GetString();
	for (int i = 0; i < 256; i++){
		Chars[i].SelfCh = i - 128;
		Chars[i].Freq = 0;
	}
}

void CountChars(){
	for (int i = 0; i < Text.length(); i++){
		Chars[Text[i] + 128].IncFreq();
	}
}
int main(){
	int t, a[10] = {87,31567,6148,64,36498,897,699,88,61,477};
	Init();
	
	cout << TxtReader.GetString();
	for (int i = 0; i < 10; i++){
		//heap.Insert(a[i], min);
	}

	for (int i = 0; i < 10; i++){
		//cout<<heap.Get(min)<<endl;
	}
	return 0;
}