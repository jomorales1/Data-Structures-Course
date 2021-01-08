package com.datastructures;

import com.datastructures.exception.ElementNotFoundException;
import com.datastructures.exception.EmptyStructureException;
import com.datastructures.linkedlist.SinglyLinkedList;

public class Main {

    public static void main(String[] args) throws EmptyStructureException, ElementNotFoundException {
        System.out.println("Hello World!");
        testSinglyLinkedList();
    }

    public static void testSinglyLinkedList() throws EmptyStructureException, ElementNotFoundException {
        SinglyLinkedList<Integer> list = new SinglyLinkedList<>();
        System.out.println(list.toString());
        for (int i = 0; i < 11; i++) {
            list.pushBack(i + 1);
            System.out.println(list.toString());
        }
        System.out.println("Erasing 5...");
        list.erase(5);
        System.out.println("Result: " + list.toString());
        System.out.println("Last element: " + list.topBack());
        System.out.println("Deleting last element...");
        list.popBack();
        System.out.println("Result: " + list.toString());
        list.makeEmpty();
        System.out.println(list.toString());
        for (int i = 0; i < 11; i++) {
            list.pushFront(i + 1);
            System.out.println(list.toString());
        }
        System.out.println("First element: " + list.topFront());
        System.out.println("Deleting first element...");
        list.popFront();
        System.out.println("Result: " + list.toString());
        System.out.println("Size: " + list.getSize());
        list.makeEmpty();
    }
}
