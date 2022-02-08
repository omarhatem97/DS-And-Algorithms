# <u>Heaps</u>

is a <mark>**complete binary tree**</mark> *(tree that is full of nodes from left to right except the last level)*, which satisfies <mark>**heap property**</mark> *(the value of every node should be >= to value of its children)*

![](C:\Users\omar_\AppData\Roaming\marktext\images\2022-02-08-06-38-32-image.png)



Heaps can be implemented using binary trees or arrays , but since it's a complete binary tree, it's more efficient to store it using arrays. To access the parent node or the children nodes use the below formulas

![](C:\Users\omar_\AppData\Roaming\marktext\images\2022-02-08-07-14-14-image.png)

### 

### Implementing Heap

Java

```java
package com.codewithmosh;

public class Heap {
  private int[] items = new int[10];
  private int size;

  public void insert(int value) {
    if (isFull())
      throw new IllegalStateException();

    items[size++] = value;

    bubbleUp();
  }

  public int remove() {
    if (isEmpty())
      throw new IllegalStateException();

    var root = items[0];
    items[0] = items[--size];

    bubbleDown();

    return root;
  }

  private void bubbleDown() {
    var index = 0;
    while (index <= size && !isValidParent(index)) {
      var largerChildIndex = largerChildIndex(index);
      swap(index, largerChildIndex);
      index = largerChildIndex;
    }
  }

  public boolean isEmpty() {
    return size == 0;
  }

  private int largerChildIndex(int index) {
    if (!hasLeftChild(index))
      return index;

    if (!hasRightChild(index))
      return leftChildIndex(index);

    return (leftChild(index) > rightChild(index)) ?
            leftChildIndex(index) :
            rightChildIndex(index);
  }

  private boolean hasLeftChild(int index) {
    return leftChildIndex(index) <= size;
  }

  private boolean hasRightChild(int index) {
    return rightChildIndex(index) <= size;
  }

  private boolean isValidParent(int index) {
    if (!hasLeftChild(index))
      return true;

    var isValid = items[index] >= leftChild(index);

    if (hasRightChild(index))
      isValid &= items[index] >= rightChild(index);

    return isValid;
  }

  private int rightChild(int index) {
    return items[rightChildIndex(index)];
  }

  private int leftChild(int index) {
    return items[leftChildIndex(index)];
  }

  private int leftChildIndex(int index) {
    return index * 2 + 1;
  }

  private int rightChildIndex(int index) {
    return index * 2 + 2;
  }

  public boolean isFull() {
    return size == items.length;
  }

  private void bubbleUp() {
    var index = size - 1;
    while (index > 0 && items[index] > items[parent(index)]) {
      swap(index, parent(index));
      index = parent(index);
    }
  }

  private int parent(int index) {
    return (index - 1) / 2;
  }

  private void swap(int first, int second) {
    var temp = items[first];
    items[first] = items[second];
    items[second] = temp;
  }

  public int max() {
    if (isEmpty())
      throw new IllegalStateException();

    return items[0];
  }

  public static boolean isMaxHeap(int[] array) {
    return isMaxHeap(array, 0);
  }

  private static boolean isMaxHeap(int[] array, int index) {
    // All leaf nodes are valid
    var lastParentIndex = (array.length - 2) / 2;
    if (index > lastParentIndex)
      return true;

    var leftChildIndex = index * 2 + 1;
    var rightChildIndex = index * 2 + 2;

    var isValidParent =
        array[index] >= array[leftChildIndex] &&
        array[index] >= array[rightChildIndex];

    return isValidParent &&
            isMaxHeap(array, leftChildIndex) &&
            isMaxHeap(array, rightChildIndex);
  }
}

```

CPP

```cpp
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
}15);
	heap.insert(6);

	cout << "Done!" << endl;

	return 0;
}
```
