package com.datastructures.linkedlist;

import com.datastructures.exception.EmptyStructureException;

public class DoublyLinkedList<T> {
    private int size;
    private Node<T> head;
    private Node<T> tail;

    static class Node<T> {
        T key;
        Node<T> prev;
        Node<T> next;

        Node() {
            key = null;
            prev = null;
            next = null;
        }
    }

    public DoublyLinkedList() {
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public T get(int index) {
        if (index < 0 || index >= this.size)
            throw new ArrayIndexOutOfBoundsException();
        Node<T> current = this.head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current.key;
    }

    public void pushBack(T key) {
        Node<T> newNode = new Node<>();
        newNode.key = key;
        newNode.next = null;
        if (this.tail == null) {
            newNode.prev = null;
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }
        this.size++;
    }

    public T popBack() throws EmptyStructureException {
        if (isEmpty()) throw new EmptyStructureException();
        T key = this.tail.key;
        if (this.head == this.tail) {
            this.head = null;
            this.tail = null;
        } else {
            this.tail = this.tail.prev;
            this.tail.next = null;
        }
        this.size--;
        return key;
    }

    public T topBack() throws EmptyStructureException {
        if (isEmpty()) throw new EmptyStructureException();
        return this.tail.key;
    }

    public void pushFront(T key) {
        Node<T> newNode = new Node<>();
        newNode.key = key;
        newNode.prev = null;
        if (this.head == null) {
            newNode.next = null;
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.head.prev = newNode;
            newNode.next = this.head;
            this.head = newNode;
        }
        this.size++;
    }

    public T popFront() throws EmptyStructureException {
        if (isEmpty()) throw new EmptyStructureException();
        T key = this.head.key;
        if (this.head == this.tail) {
            this.head = null;
            this.tail = null;
        } else {
            this.head = this.head.next;
            this.head.prev = null;
        }
        this.size--;
        return key;
    }

    public T topFront() throws EmptyStructureException {
        if (isEmpty()) throw new EmptyStructureException();
        return this.head.key;
    }

    public boolean find(T key) throws EmptyStructureException {
        if (isEmpty()) return false;
        Node<T> current = this.head;
        while (current != null) {
            if (current.key == key)
                return true;
            current = current.next;
        }
        return false;
    }

    public void erase(T key) throws EmptyStructureException {
        if (!find(key)) throw new EmptyStructureException();
        if (this.head.key == key) {
            this.head = this.head.next;
            if (this.head == null) {
                this.tail = null;
                return;
            }
            this.head.prev = null;
        }
        Node<T> current = this.head;
        while (current.next.key != key) {
            current = current.next;
        }
        current.next = current.next.next;
        if (current.next != null)
            current.next.prev = current;
        this.size--;
    }

    public int getSize() {
        return this.size;
    }

    public void makeEmpty() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    @Override
    public String toString() {
        if (isEmpty()) return "[]";
        StringBuilder stringBuilder = new StringBuilder();
        Node<T> current = this.head;
        while (current.next != null) {
            stringBuilder.append("[").append(current.key).append("] -> ");
            current = current.next;
        }
        stringBuilder.append("[").append(this.tail.key).append("]");
        return stringBuilder.toString();
    }
}
