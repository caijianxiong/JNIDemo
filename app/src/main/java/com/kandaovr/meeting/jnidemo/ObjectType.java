package com.kandaovr.meeting.jnidemo;

import java.util.ArrayList;

public class ObjectType {
    private int size;
    private String name;
    private ArrayList<Integer> numbers;
    private String[] strings;
    private InnerClass innerClass;


    public InnerClass getInnerClass() {
        return innerClass;
    }

    public void setInnerClass(InnerClass innerClass) {
        this.innerClass = innerClass;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public ArrayList<Integer> getNumbers() {
        return numbers;
    }

    public void setNumbers(ArrayList<Integer> numbers) {
        this.numbers = numbers;
    }

    public String[] getStrings() {
        return strings;
    }

    public void setStrings(String[] strings) {
        this.strings = strings;
    }

    public static class InnerClass {

        private String innerName;

        public String getInnerName() {
            return innerName;
        }

        public void setInnerName(String innerName) {
            this.innerName = innerName;
        }
    }

}
