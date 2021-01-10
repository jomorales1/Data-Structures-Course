package com.datastructures.dynamicarray;

import com.datastructures.exception.EmptyStructureException;

public class DynamicArray<T> {
    private int totalSize;
    private int capacity;
    private T[] elements;

    public DynamicArray(int size) {
        this.totalSize = size;
        this.capacity = 0;
        this.elements = (T[]) new Object[totalSize];
    }

    public T get(int index) {
        if (index < 0 || index >= this.capacity)
            throw new ArrayIndexOutOfBoundsException();
        return this.elements[index];
    }

    public void pushBack(T element) {
        if (this.capacity == this.totalSize - 1) {
            T[] newArray = (T[]) new Object[this.totalSize * 2];
            for (int i = 0; i < this.capacity; i++) {
                newArray[i] = this.elements[i];
            }
            newArray[this.capacity] = element;
            this.elements = newArray;
            this.totalSize = this.totalSize * 2;
        } else {
            this.elements[this.capacity] = element;
        }
        this.capacity++;
    }

    public T popBack() throws EmptyStructureException {
        if (this.capacity == 0)
            throw new EmptyStructureException();
        T value = this.elements[this.capacity - 1];
        this.elements[this.capacity - 1] = null;
        this.capacity--;
        return value;
    }

    public void makeEmpty() {
        this.elements = (T[]) new Object[this.totalSize];
    }

    public int getCapacity() {
        return this.capacity;
    }

    public int getTotalSize() {
        return this.totalSize;
    }

    @Override
    public String toString() {
        if (this.capacity == 0)
            return "[]";
        StringBuilder res = new StringBuilder("[");
        for (int i = 0; i < this.capacity - 1; i++) {
            res.append(this.elements[i]).append(", ");
        }
        res.append(this.elements[this.capacity - 1]).append("]");
        return res.toString();
    }
}
