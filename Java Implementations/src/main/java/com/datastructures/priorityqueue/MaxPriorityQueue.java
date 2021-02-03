package com.datastructures.priorityqueue;

import com.datastructures.exception.EmptyStructureException;
import com.datastructures.exception.StructureSpaceLimitExceeded;

import java.util.Collections;
import java.util.List;
import java.util.Vector;

public class MaxPriorityQueue<T extends Comparable<?super T>> {
    private int size;
    private int maxSize;
    private Vector<T> elements;
    
    public MaxPriorityQueue(int maxSize) {
        this.size = 0;
        this.maxSize = maxSize;
        this.elements = new Vector<>(this.maxSize + 1);
        this.elements.add(null);
    }

    public MaxPriorityQueue(Iterable<T> a, int size) {
        this.size = size;
        this.maxSize = size;
        this.elements = new Vector<>(this.maxSize + 1);
        this.elements.add(null);
        List<T> b = (List<T>) a;
        for (int i = 0; i < size; i++) {
            this.elements.add(b.get(i));
        }
    }

    private int parent(int index) {
        return index / 2;
    }

    private int leftChild(int index) {
        return 2 * index;
    }

    private int rightChild(int index) {
        return 2 * index + 1;
    }

    private void siftUp(int index) {
        while (index > 1 && this.elements.get(parent(index)).compareTo(this.elements.get(index)) < 0) {
            Collections.swap(this.elements, parent(index), index);
            index = parent(index);
        }
    }

    private void siftDown(int index) {
        int maxIndex = index;
        int left = leftChild(index);
        if (left <= this.size && this.elements.get(left).compareTo(this.elements.get(maxIndex)) > 0) {
            maxIndex = left;
        }
        int right = rightChild(index);
        if (right <= this.size && this.elements.get(right).compareTo(this.elements.get(maxIndex)) > 0) {
            maxIndex = right;
        }
        if (index != maxIndex) {
            Collections.swap(this.elements, index, maxIndex);
            siftDown(maxIndex);
        }
    }

    public void insert(T value) throws StructureSpaceLimitExceeded {
        if (this.size == this.maxSize) {
            throw new StructureSpaceLimitExceeded();
        }
        this.size++;
        this.elements.add(value);
        siftUp(this.size);
    }

    public T extractMax() throws EmptyStructureException {
        if (this.size == 0) {
            throw new EmptyStructureException();
        }
        T result = this.elements.get(1);
        this.elements.set(1, this.elements.get(this.size));
        this.size--;
        siftDown(1);
        return (T) result;
    }

    public void remove(int index) throws EmptyStructureException {
        if (index <= 0 || index > this.size) {
            throw new ArrayIndexOutOfBoundsException();
        }
        this.elements.set(index, this.elements.get(1));
        siftUp(index);
        extractMax();
    }

    public void changePriority(int index, T priority) throws EmptyStructureException {
        if (this.size == 0) {
            throw new EmptyStructureException();
        }
        if (index <= 0 || index > this.size) {
            throw new ArrayIndexOutOfBoundsException();
        }
        T oldPriority = this.elements.get(index);
        this.elements.set(index, priority);
        if (priority.compareTo(oldPriority) > 0) {
            siftUp(index);
        } else {
            siftDown(index);
        }
    }

    private void buildHeap(Iterable<T> a, int size) {
        this.maxSize = size;
        this.size = size;
        this.elements = new Vector<>(size + 1);
        this.elements.add(null);
        List<T> b = (List<T>) a;
        for (int i = 0; i < size; i++) {
            this.elements.add(b.get(i));
        }
        for (int i = size / 2; i >= 1; i--) {
            siftDown(i);
        }
    }

    public void heapSort(Iterable<T> a, int size) {
        buildHeap(a, size);
        for (int i = 0; i < size - 1; i++) {
            Collections.swap(this.elements, 1, this.size);
            this.size--;
            siftDown(1);
        }
        for (int i = 1; i <= this.maxSize; i++) {
            System.out.print(this.elements.get(i) + " ");
        }
        System.out.println();
    }

    public int getSize() {
        return this.size;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("[");
        for (int i = 1; i <= this.size; i++) {
            stringBuilder.append(this.elements.get(i));
            if (i != this.size) {
                stringBuilder.append(", ");
            }
        }
        stringBuilder.append("]\n");
        return stringBuilder.toString();
    }
}
