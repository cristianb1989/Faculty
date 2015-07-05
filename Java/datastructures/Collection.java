package datastructures;

import java.util.Iterator;

/**
 * Created by cristian on 5/31/2015.
 */
public interface Collection<T> extends Iterable<T>{
    void add(T t);

    boolean remove(T t);

    boolean isEmpty();

    Iterator<T> iterator();

    void display();

    void clear();

    int size();

}
