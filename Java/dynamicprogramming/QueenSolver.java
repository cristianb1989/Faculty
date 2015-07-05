package dynamicprogramming;

/**
 * Created by cristian on 7/3/2015.
 */
public class QueenSolver {

    static int numberOfRows = 12;
    static int numarulSolutiei = 0;

    static void boardSolver(int[][] board, int column) {
        if (column >= numberOfRows) {
            numarulSolutiei++;
            printSolution(board);
        }
        ;
        for (int row = 0; row < numberOfRows; row++) {
            if (isQueenSafe(board, row, column)) {
                board[row][column] = 1;
                boardSolver(board, column + 1);
                board[row][column] = 0;
            }
        }
    }

    private static void printSolution(int[][] board) {
        System.out.println("Solutia cu numarul: " + numarulSolutiei);
        for (int row = 0; row < numberOfRows; row++) {
            for (int column = 0; column < numberOfRows; column++) {
                if (board[row][column] == 1) {
                    System.out.print(" QQ");
                    continue;
                }
                System.out.print(" " +  board[row][column]);
            }
            System.out.println();
        }
    }

    private static boolean isQueenSafe(int[][] board, int row, int column) {
        return isLeftSafe(board, row, column) && isTopLeftSafe(board, row, column) && isBottomLeftSafe(board, row, column);

    }

    private static boolean isBottomLeftSafe(int[][] board, int row, int column) {
        int rowLeft;
        int columnLeft;
        for (rowLeft = row, columnLeft = column; rowLeft < numberOfRows && columnLeft >= 0; rowLeft++, columnLeft--) {
            if (board[rowLeft][columnLeft] == 1) {
                return false;
            }
        }
        return true;
    }

    ;

    private static boolean isTopLeftSafe(int[][] board, int row, int column) {
        int rowLeft, columnLeft;
        for (rowLeft = row, columnLeft = column; rowLeft >= 0 && columnLeft >= 0; rowLeft--, columnLeft--) {
            if (board[rowLeft][columnLeft] == 1) {
                return false;
            }
        }
        return true;
    }

    private static boolean isLeftSafe(int[][] board, int row, int column) {
        for (int columnsLeft = 0; columnsLeft < column; columnsLeft++) {
            if (board[row][columnsLeft] == 1) {
                return false;
            }
        }

        return true;
    }


    public static void main(String[] args) {
        int[][] board = new int[numberOfRows][numberOfRows];
        boardSolver(board, 0);


    }


}
