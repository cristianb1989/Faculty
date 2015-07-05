package sorting;

/**
 * Created by cristian on 5/30/2015.
 */
public interface Sorter<T extends Comparable> {
    void sort(T[] array);
}
