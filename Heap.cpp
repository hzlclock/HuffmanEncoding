#include "Heap.h"

template<typename T>
Heap<T>::Heap()
{
	Data = 0;
	Length = 0;
	Capacity = 0;
}

template<typename T>
Heap<T>::~Heap()
{
	delete(Data);
}

template<typename T>
T Heap<T>::Get(bool(*compare)(T, T))
{
	T result;
	result = Data[1];
	Data[1] = Data[Length];
	Length--;

	int curPos = 1, leftPos = 2, rightPos = 3, swapPos = curPos, temp;
	while (leftPos <= Length){
		if (compare(Data[swapPos], Data[leftPos]) == 0)
			swapPos = leftPos;
		if (compare(Data[swapPos], Data[rightPos]) == 0 && rightPos<=Length)
			swapPos = rightPos;
		if (swapPos == curPos)break;

		temp = Data[swapPos];
		Data[swapPos] = Data[curPos];
		Data[curPos] = temp;

		curPos = swapPos;
		leftPos = 2 * curPos;
		rightPos = leftPos + 1;
	}
	return result;
}

template<typename T>
void Heap<T>::Insert(T num, bool(*compare)(T, T))
{
	if (Length >= Capacity-1){
		Capacity += 100;
		int *newData = new T[Capacity];
		for (int i = 1; i <=Length; i++){
			newData[i] = Data[i];
		}
		delete(Data);
		Data = newData;
	}
	Length++;
	Data[Length] = num;
	
	int curPos=Length, upPos=Length/2, temp;
	while (compare(Data[upPos],Data[curPos])==0 && upPos>0){
		temp = Data[curPos];
		Data[curPos] = Data[upPos];
		Data[upPos] = temp;
		upPos /= 2;
		curPos /= 2;
	}

}

template class Heap<int>;

