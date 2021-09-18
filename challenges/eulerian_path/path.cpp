#include <iostream>
#include <vector>
#include <sstream>

class Graph{
    private:
        /* Total number of vertices in the graph and its adjacency list */
        int vertices;
        std::vector<int> *list;

    public:
        /* Constructor */
        Graph(int num){
            vertices = num;
            list = new std::vector<int>[num];
        }

        /* Adds an edge between vertices x and y */
        void addEdge(int x, int y){
            list[x].push_back(y);
            list[y].push_back(x);
        }

        /* Depth first search to check if graph is connected */
        void DFS(int node, bool visited[]){
            visited[node] = true;
            for(int i = 0; i < list[node].size(); i++){
                if(!visited[list[node][i]]){
                    DFS(list[node][i], visited);
                }
            }
        }

        /* Returns true if graph is connected */
        bool connected(){
            bool visited[vertices]{false};

            bool noEdges = true;
            for(int i = 0; i < vertices; i++){
                if(list[i].size() > 0){
                    noEdges = false;
                    DFS(i, visited);
                    break;
                }
            }

            if(noEdges){
                return true;
            }

            for(int i = 0; i < vertices; i++){
                if(list[i].size() > 0 && (!visited[i])){
                    return false;
                }
            }

            return true;
        }

        /* Returns 2 if Eulerian cycles exist, 1 if Eulerian paths exist, 0 if no Eulerian paths exist */
        int eulerian(){
            if(!connected()){
                return 0;
            }

            int odds = 0;
            for(int i = 0; i < vertices; i++){
                if(list[i].size() % 2 != 0){
                    odds++;
                }
            }
            if(odds == 0){
                return 2;
            }
            else if(odds == 2){
                return 1;
            }
            return 0;
        }
};

int main(){
    /* Print title */
    std::cout << "*** Eulerian Path ***" << std::endl << std::endl;

    /* Get user input */
    /* Initialize graph */
    int vertices;
    std::string input;
    std::cout << "Enter the number of vertices in the graph: " << std::endl;
    while (std::getline(std::cin, input)){
        std::stringstream ss(input);
        if (ss >> vertices){
            if(vertices > 0){
                if (ss.eof()){   
                    break;
                }
            }
        }
        std::cerr << "Invalid input, try again." << std::endl;
    }
    Graph g(vertices);

    /* Add edges to graph */
    int x;
    int y;
    std::cout << std::endl << "Vertices v1, v2 should be integers from 0 to " << vertices - 1 << "." << std::endl;
    std::cout << "Add an edge[v1 v2] or end[q]:" << std::endl;
    while (std::getline(std::cin, input)){
        std::stringstream ss(input);
        if (ss >> x && ss >> y){
            if(x >= 0 && y >= 0 && x < vertices && y < vertices){
                if (ss.eof()){
                    std::cout << "Added an edge between vertices: " << x << " and " << y << "." << std::endl;
                    g.addEdge(x, y);
                    continue;
                }
            }
        }
        else if(input == "q"){
            std::cout << "Finished building the graph." << std::endl << std::endl;
            break;
        }
        std::cerr << "Invalid input, try again." << std::endl;
    }

    /* Calculate Eulerian paths and print result */
    int result = g.eulerian();
    switch(result){
        case 0:
            std::cout << "This graph has no Eulerian paths." << std::endl;
            break;
        case 1:
            std::cout << "This graph has an Eulerian path." << std::endl;
            break;
        case 2:
            std::cout << "This graph has an Eulerian cycle." << std::endl;
            break;
        default:
            std::cerr << "Eulerian error." << std::endl;
    }

    return 0;
}
