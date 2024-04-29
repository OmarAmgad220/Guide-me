#include"Graph.h"

int main()
{
    Graph graph;

    graph.loadTheGraph();

    string source = "Cairo";
    string destination = "BeniSuef";
    transportations transport = { {30,"Uber"},{200,"Plane"} };
    graph.Add(source, destination, transport);

    graph.saveTheGraph();

    /*graph.AddToGraph("Cairo", "Giza", { {30,"Metro"}, {60,"Bus"} ,{230,"Uber"} });
    graph.AddToGraph("Dahab", "Giza", { {500,"Bus"}, {345,"Microbus"} });
    graph.AddToGraph("Cairo", "BeniSuef", { {20, "Microbus"}, {15,"Bus"} });
    graph.AddToGraph("Asyut", "Cairo", { {250, "Train"}, {450,"Bus"} });
    graph.AddToGraph("Dahab", "BeniSuef", { {200,"Microbus"}, {315,"Bus"} });

    string source = "Cairo";
    string destination = "BeniSuef";
    transportations transport = { {30,"Uber"},{200,"Plane"} };

    graph.Add(source, destination, transport);

    graph.Update(source, destination,{ 15,"Bus" });

      graph.Delete(source, destination);
    for (auto it : graph.findWeight(source, destination))
    {
        cout << source << " " << it.first << " " << it.second << endl;
    }

    for (auto it : graph.findWeight(destination, source))
    {
        cout << destination << " " << it.first << " " << it.second << endl;
    }*/

    /*graph.displayAllPathsBFS(source, destination);

    cout << endl;

    graph.displayAllPathsDFS(source, destination); */


    /*if (allPaths.empty()) {
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
    }*/


    return 0;
}