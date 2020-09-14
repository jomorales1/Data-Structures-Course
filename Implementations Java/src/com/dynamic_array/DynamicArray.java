package com.dynamic_array;

public class DynamicArray<T> {
    private int size;
    private int capacity;
    private T[] elements;

    public DynamicArray(int size) {
        this.size = size;
        this.capacity++;
        this.elements = (T[]) new Object[size];
    }

    public void pushBack(T element) {
        this.capacity++;
        if (this.capacity == this.size - 1) {
            T[] newArray = (T[]) new Object[this.size * 2];
            for (int i = 0; i < capacity - 1; i++) {
                newArray[i] = this.elements[i];
            }
            newArray[capacity - 1] = element;
            this.elements = newArray;
            this.size = this.size * 2;
        } else {
            elements[this.capacity - 1] = element;
        }
    }

    public T popBack() {
        if (capacity == 0) {
            return null;
        }
        capacity--;
        return elements[this.capacity];
    }

    public int getCapacity() {
        return this.capacity - 1;
    }

    public int getSize() {
        return this.size;
    }

    @Override
    public String toString() {
        if (this.capacity == 1)
            return "";
        String res = "[";
        for (int i = 0; i < this.capacity - 1; i++) {
            if (this.elements[i] != null)
                res += this.elements[i] + ", ";
        }
        res += this.elements[this.capacity - 1] + "]";
        return res;
    }
}
