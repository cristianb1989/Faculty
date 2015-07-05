package sorting;

/**
 * Created by cristian on 5/31/2015.
 */
public class SelectionSorter implements Sorter {
    @Override
    public void sort(Comparable[] array) {
        for (int i=0; i< array.length; i++){
            int minimum = getMinimumPosition(array, i);
            swap(array, minimum, i);
        }
    }

    private void swap(Comparable[] array, int minimum, int i) {
        Comparable aux = array[minimum];
        array[minimum] = array[i];
        array[i] = aux;
    }

    private int getMinimumPosition(Comparable[] array, int i) {
        int minimum = i;
        for (int start=i+1; start <array.length; start++){
            if (array[minimum].compareTo(array[start]) >=0){
                minimum = start;
            }
        }
        return minimum;
    }
}
