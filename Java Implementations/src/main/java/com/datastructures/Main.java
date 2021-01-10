package com.datastructures;

import com.datastructures.dynamicarray.DynamicArray;
import com.datastructures.exception.ElementNotFoundException;
import com.datastructures.exception.EmptyStructureException;
import com.datastructures.exception.StructureSpaceLimitExceeded;
import com.datastructures.linkedlist.DoublyLinkedList;
import com.datastructures.linkedlist.SinglyLinkedList;
import com.datastructures.queue.QueueA;
import com.datastructures.stack.StackA;
import com.datastructures.stack.StackLL;

public class Main {

    public static void main(String[] args) throws EmptyStructureException, ElementNotFoundException, StructureSpaceLimitExceeded {
        System.out.println("Hello World!");
        testQueueA();
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

    public static void testDoublyLinkedList() throws EmptyStructureException, ElementNotFoundException {
        DoublyLinkedList<Integer> list = new DoublyLinkedList<>();
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

    public static void testDynamicArray() throws EmptyStructureException {
        DynamicArray<Integer> dynamicArray = new DynamicArray<>(10);
        System.out.println(dynamicArray);
        for (int i = 0; i < 10; i++) {
            dynamicArray.pushBack(i);
            System.out.println(dynamicArray);
        }
        System.out.println(dynamicArray.get(3));
        for (int i = 0; i < 10; i++) {
            dynamicArray.popBack();
            System.out.println(dynamicArray);
        }
        dynamicArray.makeEmpty();
    }

    public static void testStackA() throws EmptyStructureException {
        StackA<Integer> stack = new StackA<>();
        System.out.println(stack);
        for (int i = 0; i < 10; i++) {
            stack.push(i);
            System.out.println(stack);
        }
        System.out.println(stack.top());
        for (int i = 0; i < 10; i++) {
            stack.pop();
            System.out.println(stack);
        }
    }

    public static void testStackLL() throws EmptyStructureException {
        StackLL<Integer> stack = new StackLL<>();
        System.out.println(stack);
        for (int i = 0; i < 10; i++) {
            stack.push(i);
            System.out.println(stack);
        }
        System.out.println(stack.top());
        for (int i = 0; i < 10; i++) {
            stack.pop();
            System.out.println(stack);
        }
    }

    public static void testQueueA() throws EmptyStructureException, StructureSpaceLimitExceeded {
        QueueA<Integer> queue = new QueueA<>(10);
        System.out.println(queue);
        for (int i = 0; i < 10; i++) {
            queue.enqueue(i);
            System.out.println(queue);
        }
        System.out.println(queue.peek());
        for (int i = 0; i < 10; i++) {
            queue.dequeue();
            System.out.println(queue);
        }
    }
}
