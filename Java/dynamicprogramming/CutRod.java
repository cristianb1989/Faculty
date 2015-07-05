package dynamicprogramming;

/**
 * Created by cristian on 5/31/2015.
 */
public interface  CutRod{
    int cutRod(int[] prices, int length);


    enum Type implements CutRod{
        RECURSIVE_CUT_ROD(){
            @Override
            public  int cutRod(int[] prices, int length) {
                if (length == 0 )
                    return 0;
                int maximumProfit = Integer.MIN_VALUE;
                for (int i=0; i< length; i++){
                    maximumProfit = maximum(maximumProfit, prices[i] + cutRod(prices, length - 1));
                }

                return maximumProfit;

            };
        },
        TOPDOWN_CUT_ROD(){
            @Override
            public int cutRod(int[] prices, int length) {
                return 0;
            }
        },
        BOTTOMUP_CUT_ROD(){
            @Override
            public int cutRod(int[] prices, int length) {
                return 0;
            }
        };




        private static int maximum(int value, int value2){
            return value > value2 ? value : value2;
        }
    }



}
