package sorting;

/**
 * Created by cristian on 5/30/2015.
 */
public class InsertionSorter implements Sorter {
    @Override
    public void sort(Comparable[] array) {
        doInsertionSort(array);
    }

    private void doInsertionSort(Comparable[] array) {
        for (int i=0; i< array.length; i++){
            Comparable key = array[i];
            int j = i-1;
            while(j >= 0 && key.compareTo(array[j]) <= 0){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
    }

}
