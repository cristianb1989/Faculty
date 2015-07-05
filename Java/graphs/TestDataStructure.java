package graphs;

/**
 * Created by cristianb on 24/06/15.
 */
public class TestDataStructure {

    public static void main(String[] args){
        ListGraph<String> city = new ListGraph<>();
        ListGraph.GraphNode<String> zorilorHood = ListGraph.newNode("Zorilor");
        ListGraph.GraphNode<String> manasturiHood = ListGraph.newNode("Manasturi");
        ListGraph.GraphNode<String> marastiHood = ListGraph.newNode("Marasti");
        ListGraph.GraphNode<String> iris = ListGraph.newNode("iris");
        ListGraph.GraphNode<String> intreLacuri = ListGraph.newNode("intreLacuri");
        ListGraph.GraphNode<String> floresti = ListGraph.newNode("floresti");
        ListGraph.GraphNode<String> centruHood = ListGraph.newNode("Centru");
        ListGraph.GraphNode<String> gheorgheni = ListGraph.newNode("gheorgheni");
        ListGraph.GraphNode<String> grigorescu = ListGraph.newNode("grigorescu");
        ListGraph.GraphNode<String> andreiMuresanu = ListGraph.newNode("andreiMuresanu");

        zorilorHood.addNeighbours(manasturiHood, centruHood, andreiMuresanu);
        manasturiHood.addNeighbours(zorilorHood, centruHood, grigorescu);
        marastiHood.addNeighbours(centruHood, intreLacuri, iris, gheorgheni);
        iris.addNeighbour(marastiHood);
        grigorescu.addNeighbours(floresti, manasturiHood);
        city.addNode(zorilorHood, manasturiHood, marastiHood, iris, intreLacuri, floresti, centruHood, gheorgheni, grigorescu, andreiMuresanu);
        System.out.println(city);
        //city.breadthFirstSearch(zorilorHood);
        System.out.println();


        //city.breadthFirstSearch();
        System.out.println();
        city.depthFirstSearch(zorilorHood);
        System.out.println();
        //city.depthFirstSearch();
    }
}
