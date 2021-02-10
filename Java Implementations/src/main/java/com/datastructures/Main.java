package com.datastructures;

import com.datastructures.disjointset.DisjointSet;
import com.datastructures.dynamicarray.DynamicArray;
import com.datastructures.exception.ElementNotFoundException;
import com.datastructures.exception.EmptyStructureException;
import com.datastructures.exception.StructureSpaceLimitExceeded;
import com.datastructures.linkedlist.DoublyLinkedList;
import com.datastructures.linkedlist.SinglyLinkedList;
import com.datastructures.priorityqueue.MaxPriorityQueue;
import com.datastructures.priorityqueue.MinPriorityQueue;
import com.datastructures.queue.QueueA;
import com.datastructures.queue.QueueLL;
import com.datastructures.stack.StackA;
import com.datastructures.stack.StackLL;

import java.util.ArrayList;
import java.util.Random;

public class Main {

    public static void main(String[] args) throws EmptyStructureException, ElementNotFoundException, StructureSpaceLimitExceeded {
        System.out.println("Hello World!");
        testSinglyLinkedList();
        testDoublyLinkedList();
        testDynamicArray();
        testStackA();
        testStackLL();
        testQueueA();
        testQueueLL();
        testMaxPriorityQueue();
        testMinPriorityQueue();
        testHeapSort();
        testDisjointSet();
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

    public static void testQueueLL() throws EmptyStructureException, StructureSpaceLimitExceeded {
        QueueLL<Integer> queue = new QueueLL<>();
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

    public static void testMaxPriorityQueue() throws StructureSpaceLimitExceeded, EmptyStructureException {
        MaxPriorityQueue<Integer> queue = new MaxPriorityQueue<>(20);
        for (int i = 10; i >= 5; i--) {
            queue.insert(i - 5);
            queue.insert(i);
        }
        System.out.print(queue.toString());
        queue.remove(3);
        System.out.print(queue.toString());
        System.out.println(queue.extractMax());
        System.out.print(queue.toString());
    }

    public static void testMinPriorityQueue() throws StructureSpaceLimitExceeded, EmptyStructureException {
        MinPriorityQueue<Integer> queue = new MinPriorityQueue<>(20);
        for (int i = 10; i >= 5; i--) {
            queue.insert(i - 5);
            queue.insert(i);
        }
        System.out.print(queue.toString());
        queue.remove(3);
        System.out.print(queue.toString());
        System.out.println(queue.extractMin());
        System.out.print(queue.toString());
    }

    public static void testHeapSort() {
        MaxPriorityQueue<Integer> queue = new MaxPriorityQueue<>(10);
        ArrayList<Integer> a = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 10; i++) {
            a.add(random.nextInt(10) + 1);
        }
        queue.heapSort(a, 10);
    }

    public static void testDisjointSet() {
        DisjointSet disjointSet = new DisjointSet(10);
        for (int i = 0; i < 10; i++) {
            disjointSet.makeSet(i);
        }
        disjointSet.union(1, 5);
        disjointSet.union(0, 9);
        disjointSet.union(5, 3);
        disjointSet.union(6, 0);
        disjointSet.union(9, 2);
        disjointSet.union(1, 7);
        for (int i = 0; i < 10; i++) {
            System.out.println(i + ": " + disjointSet.find(i));
        }
        System.out.println();
        System.out.println(disjointSet.toString());
    }
}
