template<typename T>class Heap
{
	int *Data;
	int Length, Capacity;
public:
	Heap();
	~Heap();

	//compare(a,b):a is more suitable to be at top
	void Insert(T num, bool (*compare)(T, T));
	T Get(bool (*compare)(T, T));
};

