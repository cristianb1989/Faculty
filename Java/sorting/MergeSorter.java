package sorting;

/**
 * Created by cristian on 5/30/2015. Needs refinement
 */
public class MergeSorter<T extends Comparable> implements Sorter {
    private Comparable[] backUparray;

    @Override
    public void sort(Comparable[] array) {
        backUparray = new Comparable[array.length];

        mergeSort(array, 0, array.length, backUparray);
    }

    private void mergeSort(Comparable[] array, int begin, int end, Comparable[] backUparray) {
        if (end - begin >= 2) {
            int middle = (begin + end) / 2;
            mergeSort(array, begin, middle, backUparray);
            mergeSort(array, middle, begin, backUparray);
            merge(array, begin, middle, end, backUparray);
            copyArray(backUparray, begin, end, array);
        }
    }

    private void copyArray(Comparable[] backUparray, int begin, int end, Comparable[] array) {
        for (int k=begin; k< end; k++){
            array[k] = backUparray[k];
        }
    }

    private void merge(Comparable[] array, int begin, int middle, int end, Comparable[] backUparray) {
        int i0=begin; int i1=middle;

        for(int i=begin; i< end; i++){
            if (i0< middle && (i1 >= end || array[i0].compareTo(array[i1])<= 0 )){
                backUparray[i] = array[i0];
                i0++;
            }else{
                backUparray[i] = array[i1];
                i1++;
            }
        }
    }


}
