package graphs;

/**
 * Created by cristian on 7/4/2015.
 */
public class Prim {

    static int N = 5;
    static int MAX_VALUE = 999;


    public static void main(String[] args) {
        int[][] matrix = buildMatrixGraph();
        primSpanningTree(matrix, 1);
    }

    private static void primSpanningTree(int[][] matrix, int startingPosition) {
        int[] visited = new int[N];
        int startNode = 0, endNode = 0;
        int minimum = MAX_VALUE;
        int total = 0;
        int noOfEdges = 1;
        visited[startingPosition] = 1;
        while (noOfEdges < N) {
            minimum = MAX_VALUE;
            for (int row = 0; row < N; row++) {
                if (visited[row] != 1) {
                    for (int column = 0; column < N; column++) {
                        if (visited[column] != 1 && minimum > matrix[row][column]) {
                            minimum = matrix[row][column];
                            startNode = row;
                            endNode = column;
                        }
                    }
                }
            }
            visited[endNode] = 1;
            System.out.println("Edge found: " + (startNode + 1) + "--> " + (endNode + 1) + " with the minimum the cost of: " + minimum);
            noOfEdges++;
            total += minimum;
        }
        System.out.println("Weight of the minimum spanning tree is : " + total);
    }


    private static int[][] buildMatrixGraph() {
        return new int[][]{
        /* first node*/ {MAX_VALUE, 100, 110, MAX_VALUE, 50},
        /* second node*/{100, MAX_VALUE, 15, 40, MAX_VALUE},
        /* third node*/ {110, 15, MAX_VALUE, 70, MAX_VALUE},
        /* fourth node*/{MAX_VALUE, 40, 70, MAX_VALUE, 16},
        /* fifth node*/ {50, MAX_VALUE, MAX_VALUE, 16, MAX_VALUE}
        };
    }
}
