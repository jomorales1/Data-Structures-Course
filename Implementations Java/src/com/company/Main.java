package com.company;

import com.dynamic_array.DynamicArray;

public class Main {

    public static void main(String[] args) {
	// write your code here
        DynamicArray array = new DynamicArray(5);
        System.out.println(array.toString());
        for (int i = 0; i < 10; i++) {
            array.pushBack(i + 1);
        }
        System.out.println(array.getSize());
        System.out.println(array.getCapacity());
        System.out.println(array.toString());
        for (int i = 0; i < 10; i++) {
            System.out.println(array.popBack());
        }
        System.out.println(array.toString());
    }
}
