package datastructures;

import java.util.Iterator;

/**
 * Created by cristian on 5/31/2015.
 */
public class StackArray<E> implements Stack<E> {
    private E[] elements;
    private int top=-1;

    public StackArray() {
        this.elements = (E[]) new Object[16];

    }

    @Override
    public void push(E e) {
        top++;
        elements[top] = e;
    }

    @Override
    public E pop() {
        return elements[top--];
    }



    @Override
    public Iterator<E> iterator() {
        return new StackIterator();
    }

    @Override
    public void display() {
        Iterator<E> eIterator = iterator();
        while (eIterator.hasNext()) {
            System.out.printf(" %s", eIterator.next());
        };
        System.out.println();
    }

    private class StackIterator implements Iterator{
        private int topElement;

        public StackIterator() {
            this.topElement = top;
        }

        @Override
        public boolean hasNext() {
            return topElement >= 0 ;
        }

        @Override
        public E next() {
           return elements[topElement--];
        }

        @Override
        public void remove() {

        }
    }
}
