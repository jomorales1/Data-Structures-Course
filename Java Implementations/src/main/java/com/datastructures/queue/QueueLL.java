package com.datastructures.queue;

import com.datastructures.exception.EmptyStructureException;
import com.datastructures.linkedlist.DoublyLinkedList;

public class QueueLL<T> {
    private int size;
    private DoublyLinkedList<T> elements;

    public QueueLL() {
        this.size = 0;
        this.elements = new DoublyLinkedList<>();
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public void enqueue(T value) {
        this.elements.pushBack(value);
        this.size++;
    }

    public T dequeue() throws EmptyStructureException {
        T value = this.elements.topFront();
        this.elements.popFront();
        this.size--;
        return value;
    }

    public T peek() throws EmptyStructureException {
        return this.elements.topFront();
    }

    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder stringBuilder = new StringBuilder("[");
        for (int i = 0; i < this.size - 1; i++) {
            stringBuilder.append(this.elements.get(i)).append(" <- ");
        }
        stringBuilder.append(this.elements.get(this.size - 1)).append("]");
        return stringBuilder.toString();
    }
}
