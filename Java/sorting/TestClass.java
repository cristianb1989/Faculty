package sorting;

/**
 * Created by cristian on 5/30/2015.
 */
public class TestClass {

    public static void main(String[] args){
        Integer[] array1 = {1,2,5,7,9,6,0};
        print(SortUtil.sort(array1, new InsertionSorter()));
        String[] array2 = {"g","d","b","c","e","f","a"};
        print(SortUtil.sort(array2, new InsertionSorter()));
        Integer[] array3 = {1,2,3,4,3,6,7,2,9,0};
        print(SortUtil.<Integer>sort(array3, new QuickSorter()));
        Integer[] array4 = {1,2,3,4,3,6,7,2,9,0};
        print(SortUtil.<Integer>sort(array4, new HeapSorter()));
        Integer[] array5 = {1,2,3,4,3,6,7,2,9,0};
        print(SortUtil.<Integer>sort(array5, new SelectionSorter()));
    }

    public static <T  extends Comparable> void print(T[] array){
     for (T t: array){
         System.out.printf(" %s",t);
     }
        System.out.println();
    }
}
