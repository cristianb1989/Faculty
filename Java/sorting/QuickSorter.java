package sorting;

/**
 * Created by cristian on 5/30/2015.
 */
public class QuickSorter implements Sorter {
    @Override
    public void sort(Comparable[] array) {
        quickSort(array, 0, array.length);
    }

    private void quickSort(Comparable[] array, int i, int length) {
        if (i < length) {
            int partition = extractPivotWhenFirst(array, i, length);
            quickSort(array, i, partition - 1);
            quickSort(array, partition + 1, length);
        }
    }

    /**
     * Supposes that the pivot it's on the leftmost position.
     * The left elements have to be lower than the pivot, whereas the right eleements have to be greater than the pivot.
     * When it finds a element lover than the pivot it swaps with the first element that was greater than the pivot.
     * @param array
     * @param pivot
     * @param max
     * @return
     */
    private int extractPivotWhenFirst(Comparable[] array, int pivot, int max) {
        int maximum = max == array.length ? max - 1 : max;
        Comparable piv = array[pivot];
        int start = pivot;
        for (int j = pivot + 1; j <= maximum; j++) {
            if (array[j].compareTo(piv) < 0) {
                start++;
                /** swap the lower with the previously remained intact**/
                exchange(array, start, j);
/*                Comparable cup = array[start];
                array[start] = array[j];
                array[j] = cup;*/
            }
        }
        /** change the pivot with the final position of the slowest element start**/
        exchange(array, start, pivot);
/*        Comparable cup = array[start];
        array[start] = array[pivot];
        array[pivot] = cup;*/
        return start++;
    }

    private void exchange(Comparable[] array, int i, int j) {
        Comparable cup = array[i];
        array[i] = array[j];
        array[j] = cup;
    }
}
