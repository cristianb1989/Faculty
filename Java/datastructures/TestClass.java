package datastructures;

/**
 * Created by cristian on 5/31/2015.
 */
public class TestClass {

    public static void main(String[] args){
        int[] array = {1,3,4,2,5,6,7};
        List<Integer> integers = new LinkedList<>();
        for (int value:array){
            integers.add(value);
        }
        integers.display();
        System.out.println(integers.search(0));
        integers.remove(1);
        integers.remove(2);
        integers.remove(7);
        integers.remove(3);
        integers.remove(0);
        integers.display();
        int[] array2 = {1,3,4,2,5,6,7};
        Stack<Integer> integer = new StackArray<>();
        for (int value:array2){
            integer.push(value);
        }
        integer.display();
        integer.pop();
        integer.pop();
        integer.display();
    }
}
