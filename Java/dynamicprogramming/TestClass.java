package dynamicprogramming;

import java.util.Scanner;

/**
 * Created by cristian on 5/31/2015.
 */
public class TestClass {

    public static void main(String[] args) {
        int[] array1 = {1, 2, 5, 7, 9, 6, 0};
        System.out.println(CutRod.Type.RECURSIVE_CUT_ROD.cutRod(array1, array1.length));
    }

    ;
}
