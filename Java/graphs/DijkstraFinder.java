package graphs;

/**
 * Created by cristian on 7/3/2015.
 */
public class DijkstraFinder {

    static int N = 5;
    static int MAX_VALUE = 999;


    public static void main(String[] args) {
        int[][] matrix = buildMatrixGraph();
        int startingPosition = 0;
        dijkstraUsingMatrix(matrix, startingPosition);
    }

    private static void dijkstraUsingMatrix(int[][] matrix, int startingPosition) {
        int[] visited = new int[N];
        int[] pathOfNode = new int[N];

        //we start from startingPosition
        int[] distance = matrix[startingPosition];
        distance[startingPosition] = 0; //this is the row with the number of starting position e.g given startingPosition = 3, then we have fourth row of matrix
        visited[startingPosition] = 1;

        int min = MAX_VALUE;
        int nextNode = 0;

        for (int row = 0; row < N; row++) {
            // finds the minimum next node
            for (int column = 0; column < N; column++) {
                if (min > distance[column] && wasVisited(visited[column])) {
                    min = distance[column];
                    nextNode = column;
                }
            }
            visited[nextNode] = 1;
            //update distances
            for (int column = 0; column < N; column++) {
                if (wasVisited(visited[column])) {
                    int currentDistanceFromNextNode = min + matrix[nextNode][column];
                    if (currentDistanceFromNextNode < distance[column]) {
                        distance[column] = currentDistanceFromNextNode;
                        pathOfNode[column] = nextNode;
                    }
                }
            }
        }
        System.out.println("Distances are: ");
        for (int node = 0; node < N; node++) {
            System.out.println("Distance from " + startingPosition + " to " + node + " is:" + distance[node]);
        }

        System.out.println("Shorthest path: ");
        for (int node = 0; node < N; node++) {
            System.out.print("Path for node: " + node);
            int thePreviousNode = node;
            do {
                thePreviousNode = pathOfNode[thePreviousNode];
                if (thePreviousNode == 0 && startingPosition != 0) {
                    //the starting node wasn't zero
                    System.out.print(" <- " + startingPosition);
                } else {
                    System.out.print(" <- " + thePreviousNode);
                }

            } while (thePreviousNode != 0);
            System.out.println();
        }
    }

    private static boolean wasVisited(int i) {
        return i != 1;
    }

    private static int[][] buildMatrixGraph() {
        return new int[][]
                {
        /* first node*/ {MAX_VALUE, 20, 70, MAX_VALUE, 50},
        /* second node*/{20, MAX_VALUE, 15, 40, MAX_VALUE},
        /* third node*/ {10, 15, MAX_VALUE, 70, MAX_VALUE},
        /* fourth node*/{MAX_VALUE, 40, 70, MAX_VALUE, 16},
        /* fifth node*/ {50, MAX_VALUE, MAX_VALUE, 16, MAX_VALUE}
                };
    }
}
