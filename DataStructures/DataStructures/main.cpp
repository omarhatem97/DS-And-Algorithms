#include <iostream>
#include <vector>

using namespace std;


class Heap {
public:
	Heap() {
		size = 0;
		v.resize(100);
	}
	
	void insert(int value) {
		v[size++] = value;
		int index = size - 1;
		while (v[index] > v[parentIndex(index)] && index > 0)
		{
			swap(v[index], v[parentIndex(index)]);
			index = parentIndex(index);
		}

	}

	void remove() {
		v[0] = v[--size];

		int index = 0;
		while (v[index] > leftChild(index) && v[index] > rightChild(index) && index <= size)
		{
			swap(v[index], v[largerChildIndex(index)]);
			index = largerChildIndex(index);
		}
	}

	int largerChildIndex(int index) {
		if (!hasLeftChild(index))
			return index;

		if (!hasRightChild(index))
			return leftChild(index);

		return leftChild(index) > v[index] ? leftChild(index) : rightChild(index);
	}

	bool hasRightChild(int index) {
		return rightChild(index) <= size;
	}

	bool hasLeftChild(int index) {
		return leftChild(index) <= size;
	}

	int leftChild(int parent) {
		return parent * 2 + 1;
	}

	int rightChild(int parent) {
		return parent * 2 + 2;
	}

	int parentIndex(int index) {
		return (index - 1) / 2;
	}

private:
	vector<int> v;
	int size;
};


int main()
{
	Heap heap;
	heap.insert(20);
	heap.insert(10);
	heap.insert(15);
	heap.insert(6);

	heap.remove();

	cout << "Done!" << endl;

	return 0;
}