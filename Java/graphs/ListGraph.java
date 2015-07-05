package graphs;

import java.util.*;

/**
 * Created by cristian on 7/4/2015.
 */
public class ListGraph<T> {
    private List<GraphNode<T>> nodes;

    public ListGraph() {
        this.nodes = new LinkedList<GraphNode<T>>();
    }

    public ListGraph(List<GraphNode<T>> graphNodes) {
        this.nodes = graphNodes;
    }

    public void addNode(GraphNode<T> node) {
        this.nodes.add(node);
    }

    public void addNode(GraphNode<T>... node) {
        this.nodes.addAll(Arrays.asList(node));
    }

    public static <T> GraphNode<T> newNode(T value) {
        return new GraphNode<>(value);
    }

    public void breadthFirstSearch() {
        breadthFirstSearch(nodes.get(0));
    }

    public void breadthFirstSearch(GraphNode<T> tGraphNode) {
        StringBuilder sb = new StringBuilder();
        LinkedList<GraphNode<T>> nodesQueue = new LinkedList<>();
        tGraphNode.setVisited(true);
        nodesQueue.offer(tGraphNode);
        sb.append(tGraphNode.toString());
        while (!nodesQueue.isEmpty()) {
            GraphNode<T> current = nodesQueue.poll();
            Iterator<GraphNode<T>> neighboursIterator = current.getNeighbours().iterator();
            while (neighboursIterator.hasNext()) {
                GraphNode<T> neighbour = neighboursIterator.next();
                if (!neighbour.isVisited()) {
                    neighbour.setVisited(true);
                    nodesQueue.offer(neighbour);
                    sb.append(neighbour.toString());
                }
            }
        }

        System.out.println(sb.toString());
    }



    public void depthFirstSearch() {
        breadthFirstSearch(nodes.get(0));
    }

    public void depthFirstSearch(GraphNode<T> tGraphNode) {
        StringBuilder sb = new StringBuilder();
        Stack<GraphNode<T>> nodesQueue = new Stack<>();
        tGraphNode.setVisited(true);
        nodesQueue.push(tGraphNode);
        sb.append(tGraphNode.toString());
        while (!nodesQueue.isEmpty()) {
            GraphNode<T> current = nodesQueue.pop();
            if (!current.isVisited()) {
                current.setVisited(true);
                sb.append(current.toString());
            }
            Iterator<GraphNode<T>> neighboursIterator = current.getNeighbours().iterator();
            while (neighboursIterator.hasNext()) {
                GraphNode<T> neighbour = neighboursIterator.next();
                if (!neighbour.isVisited()) {
                    nodesQueue.push(neighbour);
                }
            }
        }

        System.out.println(sb.toString());
    }

    public static class GraphNode<T> {
        private ColorType color;
        private final T value;
        private final List<GraphNode<T>> neighbours;
        private boolean visited;
        private int startTime;
        private int endTime;

        public GraphNode(T value) {
            this.value = value;
            this.neighbours = new LinkedList<>();
        }

        public List<GraphNode<T>> getNeighbours() {
            return neighbours;
        }

        public boolean addNeighbour(GraphNode<T> node) {
            return neighbours.add(node);
        }

        public boolean addNeighbours(GraphNode<T>... nodes) {
            return neighbours.addAll(Arrays.asList(nodes));
        }

        public T getValue() {
            return value;
        }

        @Override
        public String toString() {
            return "GraphNode{" + "visited=" + visited + ", value=" + value + '}';
        }

        public int getStartTime() {
            return startTime;
        }

        public void setStartTime(int startTime) {
            this.startTime = startTime;
        }

        public int getEndTime() {
            return endTime;
        }

        public void setEndTime(int endTime) {
            this.endTime = endTime;
        }

        public boolean isVisited() {
            return visited;
        }

        public void setVisited(boolean visited) {
            this.visited = visited;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o)
                return true;
            if (o == null || getClass() != o.getClass())
                return false;

            GraphNode<?> graphNode = (GraphNode<?>) o;

            return !(value != null ? !value.equals(graphNode.value) : graphNode.value != null);

        }

        @Override
        public int hashCode() {
            return value != null ? value.hashCode() : 0;
        }
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Graph{" + "nodes=");
        for (GraphNode<T> graphNode: nodes){
            stringBuilder.append(graphNode);
        }
        stringBuilder.append('}');
        return stringBuilder.toString();
    }

    private enum ColorType {
        WHITE, GREY, BLACK
    }
}
