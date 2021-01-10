package com.datastructures.queue;

import com.datastructures.exception.EmptyStructureException;
import com.datastructures.exception.StructureSpaceLimitExceeded;

public class QueueA<T> {
    private int read;
    private int write;
    private int totalCapacity;
    private int currentSize;
    private T[] elements;

    public QueueA(int capacity) {
        this.read = 0;
        this.write = 0;
        this.totalCapacity = capacity;
        this.currentSize = 0;
        this.elements = (T[]) new Object[this.totalCapacity];
    }

    public boolean isEmpty() {
        return this.currentSize == 0;
    }

    private int mod(int a, int b) {
        int c = a % b;
        return (c < 0) ? c + b : c;
    }

    public void enqueue(T value) throws StructureSpaceLimitExceeded {
        if (this.currentSize == this.totalCapacity)
            throw new StructureSpaceLimitExceeded();
        this.elements[this.write] = value;
        this.write = mod(this.write + 1, this.totalCapacity);
        this.currentSize++;
    }

    public T dequeue() throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        T value = this.elements[this.read];
        this.read = mod(this.read + 1, this.totalCapacity);
        this.currentSize--;
        return value;
    }

    public T peek() throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        return this.elements[this.read];
    }

    public int getTotalCapacity() {
        return totalCapacity;
    }

    public int getCurrentSize() {
        return currentSize;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        int index = this.read;
        StringBuilder stringBuilder = new StringBuilder("[");
        for (int i = 0; i < this.currentSize - 1; i++) {
            stringBuilder.append(this.elements[index]).append(" <- ");
            index = mod(index + 1, this.totalCapacity);
        }
        stringBuilder.append(this.elements[index]).append("]");
        return stringBuilder.toString();
    }
}
