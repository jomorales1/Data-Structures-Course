package com.datastructures.stack;

import com.datastructures.dynamicarray.DynamicArray;
import com.datastructures.exception.EmptyStructureException;

public class StackA<T> {
    private int size;
    private final DynamicArray<T> elements;

    public StackA() {
        this.size = 0;
        this.elements = new DynamicArray<>(10);
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public void push(T value) {
        this.elements.pushBack(value);
        this.size++;
    }

    public T pop() throws EmptyStructureException {
        this.size--;
        return this.elements.popBack();
    }

    public T top() {
        return this.elements.get(this.size - 1);
    }

    public int getSize() {
        return this.size;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder res = new StringBuilder("[");
        for (int i = 0; i < this.size - 1; i++) {
            res.append(this.elements.get(i)).append(" ");
        }
        res.append(this.elements.get(this.size - 1)).append("]");
        return res.toString();
    }
}
