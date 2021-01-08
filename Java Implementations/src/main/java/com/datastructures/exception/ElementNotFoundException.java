package com.datastructures.exception;

public class ElementNotFoundException extends Exception {
    private static final String ERROR_MESSAGE = "Element nof found";

    public ElementNotFoundException() {
        super(ERROR_MESSAGE);
    }
}
