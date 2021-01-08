package com.datastructures.exception;

public class EmptyStructureException extends Exception {
    private static final String ERROR_MESSAGE = "The structure is empty";

    public EmptyStructureException() {
        super(ERROR_MESSAGE);
    }
}
