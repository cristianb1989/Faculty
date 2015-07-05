package graphs;

/**
 * Created by cristian on 7/4/2015.
 */
public class Kruskal {



    static int N = 5;
    static int MAX_VALUE = 999;


    public static void main(String[] args) {
        int[][] matrix = buildMatrixGraph();
        kruskalSpanningTree(matrix);
    }

    private static void kruskalSpanningTree(int[][] matrix) {
        int[] visited = new int[N];
        int startNode = 0, endNode = 0;
        int min;
        int total=0;
        int  noOfEdges = 1;
        while (noOfEdges < 5){
            min = MAX_VALUE;

            for (int row = 0; row < N; row++){
                for(int column =0; column < N; column++){
                    if (matrix[row][column]< min){
                        startNode = row;
                        endNode = column;
                        min = matrix[row][column];
                    }
                }
            }

            int temp1 = startNode;
            int temp2 = endNode;
            while (visited[startNode] != 0){
                startNode = visited[startNode];
            }

            while (visited[endNode] != 0){
                endNode = visited[endNode];
            }

            if (startNode != endNode){
                noOfEdges++;
                visited[endNode] = startNode;
                total+=min;
                System.out.println("Edge found: " + (startNode + 1) + "--> " + (endNode + 1) + " with the minimum the cost of: " + min);
                matrix[startNode][endNode] = matrix[endNode][startNode] = MAX_VALUE;
            }else{
                matrix[temp1][temp2] = matrix[temp2][temp1] = MAX_VALUE;
            }

            //mark nodes as removed from equation by setting the MAX_VALUE
        }
        System.out.println("Weight of the minimum spanning tree is : " + total);
    }


    private static int[][] buildMatrixGraph() {
        return new int[][]
                {
        /* first node*/ {MAX_VALUE, 100, 110, MAX_VALUE, 50},
        /* second node*/{20, MAX_VALUE, 15, 40, MAX_VALUE},
        /* third node*/ {10, 15, MAX_VALUE, 70, MAX_VALUE},
        /* fourth node*/{MAX_VALUE, 40, 70, MAX_VALUE, 16},
        /* fifth node*/ {50, MAX_VALUE, MAX_VALUE, 16, MAX_VALUE}
                };
    }
}
