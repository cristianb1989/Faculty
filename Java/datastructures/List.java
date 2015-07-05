package datastructures;

/**
 * Created by cristian on 5/31/2015.
 */
public interface List<T> extends Collection<T> {

    T get(int index);

    T search(T value);
}
