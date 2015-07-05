package sorting;

/**
 * Created by cristian on 5/30/2015.
 */
public class SortUtil {
    /**
     * Suppress instantiation.
     */
    private SortUtil(){}

    public static <T extends Comparable>  T[] sort(T[] array, Sorter sorter){
        sorter.sort(array);
        return array;
    }
}
