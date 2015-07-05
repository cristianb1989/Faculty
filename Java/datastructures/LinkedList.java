package datastructures;

import java.util.Iterator;

/**
 * Created by cristian on 5/31/2015.
 */
public class LinkedList<E> implements List<E> {
    private Node<E> tail;
    private Node<E> first;
    private int size;

    @Override
    public E get(int index) {
        return null;
    }

    @Override
    public E search(E value) {
        Iterator<E> eIterator = iterator();
        E elementToBefound = null;
        while (eIterator.hasNext() &&  elementToBefound == null){
            E nextElement = eIterator.next();
            elementToBefound = nextElement.equals(value) ? nextElement : elementToBefound;
        };
        return elementToBefound;
    }
    private Node<E> searchNode(E value){
      Node<E> firstElement = first;
        while (firstElement != null){
            if (firstElement.t.equals(value)){
                return firstElement;
            };
            firstElement = firstElement.next;
        };
        return null;
    };
    @Override
    public boolean remove(E o) {
        Node<E> foundElement = searchNode(o);
        if (foundElement == null){
            return false;
        }
        Node<E> previousElement = foundElement.prev;
        Node<E> nextElement = foundElement.next;
        if (previousElement == null && nextElement != null){
            //first element unlinkit
            foundElement.next = null;
            nextElement.prev = null;
            first = nextElement;
        }else
        //last element
        if (nextElement == null && previousElement != null){
            foundElement.prev = null;
            previousElement.next = null;
            tail = previousElement;
        }else {
            previousElement.next = nextElement;
            nextElement.prev =  previousElement;

        }
        return true;
    };

    @Override
    public void add(E t) {
        Node<E> last = new Node(t, null, null);
        //first element;
        if (size == 0 ){
            first = last;
            first.prev = null;
            size++;
        //second element
        }else if (size == 1){
            first.next = last;
            last.prev = first;
        }else{
            tail.next = last;
            last.prev= tail;
        };
        tail = last;
        size++;
    }

    @Override
    public boolean isEmpty() {
        return size ==0;
    }

    @Override
    public Iterator<E> iterator() {
        return new LinkedListIterator();
    }

    @Override
    public void display() {
            Iterator<E> eIterator = iterator();
            while(eIterator.hasNext()){
                System.out.printf("  %s", eIterator.next());
            };
        System.out.println();
    }

    @Override
    public void clear() {

    }

    @Override
    public int size() {
        return size;
    }

    private static class Node<E> {
        private E t;
        private Node prev;
        private Node next;

        public Node(E t, Node previous, Node next) {
            this.t = t;
            this.prev= previous;
            this.next = next;
        }

    };

    private class LinkedListIterator implements Iterator<E>{
        private Node<E> firstElement;


        public LinkedListIterator() {
            this.firstElement= first;
        }

        @Override
        public boolean hasNext() {
            return firstElement != null;
        }

        @Override
        public E next() {
            Node<E> lastReturned = firstElement;
            firstElement = firstElement.next;
            return lastReturned.t;
        };

        @Override
        public void remove() {

        }
    }
}
