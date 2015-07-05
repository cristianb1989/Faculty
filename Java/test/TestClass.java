package test;

/**
 * Created by cristian on 6/6/2015.
 */
public class TestClass {

    public static void main(String[] args){
        int x = 5;
        changeValue(x);
        System.out.println(x);
    }

    private static void changeValue(int x) {
        x = 7;
    }
}
