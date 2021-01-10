package com.datastructures.stack;

import com.datastructures.exception.EmptyStructureException;
import com.datastructures.linkedlist.DoublyLinkedList;

public class StackLL<T> {
    private int size;
    private final DoublyLinkedList<T> elements;

    public StackLL() {
        this.size = 0;
        this.elements = new DoublyLinkedList<>();
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public void push(T key) {
        this.elements.pushFront(key);
        this.size++;
    }

    public T pop() throws EmptyStructureException {
        T key = this.elements.topFront();
        this.elements.popFront();
        this.size--;
        return key;
    }

    public T top() throws EmptyStructureException {
        return this.elements.topFront();
    }

    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Top -> ");
        for (int i = 0; i < this.size - 1; i++) {
            stringBuilder.append("[").append(this.elements.get(i)).append("] ");
        }
        stringBuilder.append("[").append(this.elements.get(this.size - 1)).append("]");
        return stringBuilder.toString();
    }
}
