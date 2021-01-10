package com.datastructures.exception;

public class StructureSpaceLimitExceeded extends Exception{
    private static final String ERROR_MESSAGE = "Could not find available space for new entries";

    public StructureSpaceLimitExceeded() {
        super(ERROR_MESSAGE);
    }
}
