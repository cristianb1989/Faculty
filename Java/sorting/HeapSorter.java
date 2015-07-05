package sorting;

/**
 * Created by cristian on 5/31/2015.
 */
public class HeapSorter implements Sorter {
    private int heapSize;

    @Override
    public void sort(Comparable[] array) {
        buildMaxHeap(array, array.length);
        for (int i = array.length - 1; i >= 0; i--) {
            swap(array, i, 0);
            heapSize--;
            maxHeapify(array, 0);
        }
    }

    private void swap(Comparable[] array, int first, int second) {
        Comparable aux = array[second];
        array[second] = array[first];
        array[first] = aux;
    }

    /**
     * Builds the heap based on the given array. This should be called usually when the array is first created.
     *
     * @param array
     * @param length
     */
    private void buildMaxHeap(Comparable[] array, int length) {
        heapSize = length - 1;
        for (int i = length / 2; i >= 0; i--) {
            maxHeapify(array, i);
        }
    }

    /**
     * Compares if the node <code>i</code> is a root. A root is a node if the left&Right are smaller. Otherwise
     *
     * @param array
     * @param i
     */
    private void maxHeapify(Comparable[] array, int i) {
        int largest;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left <= heapSize && array[left].compareTo(array[i]) > 0) {
            largest = left;
        } else {
            largest = i;
        }
        if (right <= heapSize && array[right].compareTo(array[largest]) > 0) {
            largest = right;
        }
        if (largest != i) {
            swap(array, i, largest);
            maxHeapify(array, largest);
        }
    }
}
