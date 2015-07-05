package graphs;

import java.util.LinkedList;
import java.util.Stack;

/**
 * Created by cristian on 7/4/2015.
 */
public class MatrixGraph {


    static int N = 5;
    static int MAX_VALUE = 999;

    public static void main(String[] args) {
        int[][] matrix = buildMatrixGraph();
        int startingPosition = 0;
        //depthFirstSearchWithStack(matrix, startingPosition);
        depthFirstSearch(matrix, startingPosition);
        System.out.println();
        System.out.println();

        breadthFirstSearchWithQueue(matrix, startingPosition);
    }

    private static void depthFirstSearchWithStack(int[][] matrix, int startingPosition) {
        int[] visited = new int[N];
        Stack<Integer> stack = new Stack<>();
        stack.push(startingPosition);
        while (!stack.isEmpty()){
            int startingNode = stack.pop();
            if (visited[startingNode] != 1){
                System.out.println("Node discovered: " + (startingNode + 1));
                visited[startingPosition] = 1;
            }
            for (int column=0; column < N; column++){
                if (matrix[startingNode][column] == 1 && visited[column] != 1){
                    stack.push(column);
                    startingPosition = column;
                }
            }


        }
        //while(topOfStack)


    }

    private static void breadthFirstSearchWithQueue(int[][] matrix, int startingPosition) {
        int[] visited = new int[N];
        LinkedList<Integer> nodesQueue = new LinkedList<>();
        nodesQueue.offer(startingPosition);
        System.out.println("Node discovered: " + (startingPosition + 1));
        visited[startingPosition] = 1;
        while (!nodesQueue.isEmpty()){
            int startingNode = nodesQueue.poll();
            for (int column=0; column < N; column++){
                if (matrix[startingNode][column] == 1 && visited[column] != 1 ){
                    nodesQueue.offer(column);
                    System.out.println("Node discovered: " + (column + 1));
                    visited[column] = 1;
                }
            }


        }


    }

    private static void breadthFirstSearch(int[][] matrix, int startingPosition) {
        int[] visited = new int[N];
        int[] queue = new int[N];
        int tail = 1;
        int lastNode = 0;

        queue[lastNode] = startingPosition;
        while (tail >=0 ){
            int startingNode = queue[0];

            for (int column=0; column < N; column++){
                if (matrix[startingNode][column] == 1 && visited[column] != 1 ){
                    queue[++tail] = column;
                    System.out.println("Node discovered: " + (startingNode + 1));
                    visited[startingNode] = 1;
                }
            }


        }


    }

    private static void shiftArray(int[] queue, int tail) {
        for (int i=0; i < tail; i++){
            queue[i] = queue[i+1];
        }
    }

    private static void depthFirstSearch(int[][] matrix, int startingPosition) {
        int[] visited = new int[N];
        int[] stack = new int[N];
        int topOfStack = 0;
        stack[topOfStack] = startingPosition;
        while (topOfStack >= 0){
            int startingNode = stack[topOfStack--];
            if (visited[startingNode] != 1){
                System.out.println("Node discovered: " + (startingNode + 1));
                visited[startingNode] = 1;
            }
            for (int column=0; column < N; column++){
             if (matrix[startingNode][column] == 1 && visited[column] != 1){
                 stack[++topOfStack] = column;
             }
            }


        }


    }

    private static int[][] buildMatrixGraph() {
        return new int[][]
                {
        /* first node*/ {0, 0, 1, 1, 1},
        /* second node*/{0, 0, 1, 0, 0},
        /* third node*/ {1, 1, 0, 1, 1},
        /* fourth node*/{1, 0, 1, 0, 1},
        /* fifth node*/ {1, 0, 1, 1, 0}
                };
    }
}
