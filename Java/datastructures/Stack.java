package datastructures;

/**
 * Created by cristian on 5/31/2015.
 */
public interface Stack<E> extends Iterable<E>{
    void push(E element);
    E pop();

    void display();

}
