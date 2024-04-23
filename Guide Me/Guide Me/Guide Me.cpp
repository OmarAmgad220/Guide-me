#include"Graph.h"

int main()
{

    Graph graph;

    graph.AddToGraph("Cairo", "Giza", { {30,"Metro"}, {60,"Bus"} ,{230,"Uber"} });

    graph.AddToGraph("Dahab", "Giza", { {500,"Bus"}, {345,"Microbus"} });

    graph.AddToGraph("Cairo", "BeniSuef", { {20, "Microbus"}, {15,"Bus"} });

    graph.AddToGraph("Asyut", "Cairo", { {250, "Train"}, {450,"Bus"} });

    graph.AddToGraph("Dahab", "BeniSuef", { {200,"Microbus"}, {315,"Bus"} });

    string source = "Dahab";
    string destination = "Cairo";

    vector<string> currentPath;
    vector<vector<string>> allPaths;

    graph.DFS(source, destination, currentPath, allPaths);

    if (allPaths.empty()) {
        cout << "No path found from " << source << " to " << destination << endl;
    }
    else {
        cout << "All possible paths from " << source << " to " << destination << ":" << endl;
        for (const auto& path : allPaths) {
            for (const string& city : path) {
                cout << city << " ";
            }
            cout << endl;
        }
    }

    return 0;  
}