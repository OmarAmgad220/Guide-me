#include"Graph.h"

int main()
{
    Graph graph;
   /* graph.AddToGraph("Cairo", "Giza", {{30,"Metro"}, {60,"Bus"} ,{230,"Uber"}});
    graph.AddToGraph("Dahab", "Giza", { {500,"Bus"}, {345,"Microbus"} });
    graph.AddToGraph("Cairo", "BeniSuef", { {20, "Microbus"}, {15,"Bus"} });
    graph.AddToGraph("Asyut", "Cairo", { {250, "Train"}, {450,"Bus"} });
    graph.AddToGraph("Dahab", "BeniSuef", { {200,"Microbus"}, {315,"Bus"} });*/

    graph.loadTheGraph();
    string source = "Cairo";
    string destination = "Dahab";


    graph.displayAllPathsBFS(source, destination,550);
    cout << endl;
    
    graph.checkCompleteness();

    graph.saveTheGraph();


    //graph.displayAllPathsDFS(source, destination);
   
    return 0;
}
 