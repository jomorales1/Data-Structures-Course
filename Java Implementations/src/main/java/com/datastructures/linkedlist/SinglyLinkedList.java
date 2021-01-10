package com.datastructures.linkedlist;

import com.datastructures.exception.ElementNotFoundException;
import com.datastructures.exception.EmptyStructureException;

public class SinglyLinkedList<T> {
    private int size;
    private Node<T> head;
    private Node<T> tail;

    static class Node<T> {
        T key;
        Node<T> next;

        Node() {
            key = null;
            next = null;
        }
    }

    public SinglyLinkedList() {
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public void pushFront(T key) {
        Node<T> newNode = new Node<>();
        newNode.key = key;
        newNode.next = this.head;
        this.head = newNode;
        if (isEmpty())
            this.tail = this.head;
        this.size++;
    }

    public T popFront() throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        T key = this.head.key;
        this.head = this.head.next;
        if (this.head == null)
            this.tail = null;
        this.size--;
        return key;
    }

    public T topFront() throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        return this.head.key;
    }

    public void pushBack(T key) {
        Node<T> newNode = new Node<>();
        newNode.key = key;
        newNode.next = null;
        if (isEmpty()) {
            this.head = newNode;
        } else {
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.size++;
    }

    public T popBack() throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        T key = this.tail.key;
        if (this.head == this.tail) {
            this.head = null;
            this.tail = null;
        } else {
            Node<T> current = this.head;
            while (current.next.next != null) {
                current = current.next;
            }
            current.next = null;
            this.tail = current;
        }
        this.size--;
        return key;
    }

    public T topBack() throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        return this.tail.key;
    }

    public boolean find(T key) throws EmptyStructureException {
        if (isEmpty())
            throw new EmptyStructureException();
        Node<T> current = this.head;
        while (current != null) {
            if (current.key == key)
                return true;
            current = current.next;
        }
        return false;
    }

    public void erase(T key) throws ElementNotFoundException, EmptyStructureException {
        if (!find(key))
            throw new ElementNotFoundException();
        if (this.head.key == key) {
            this.head = this.head.next;
            if (this.head == null)
                this.tail = null;
        } else {
            Node<T> current = this.head;
            while (current.next.key != key) {
                current = current.next;
            }
            current.next = current.next.next;
        }
        this.size--;
    }

    public int getSize() {
        return this.size;
    }

    public void makeEmpty() {
        this.size = 0;
        this.head = null;
        this.tail = null;
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
