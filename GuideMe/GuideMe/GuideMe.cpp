#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "Graph.h"
using namespace std;

// Helper function for sub-choice operations in case 2
void handleGraphModification(Graph& graph) {
    cout << "1. Update edge" << endl;
    cout << "2. Add edge" << endl;
    cout << "3. Delete edge" << endl;
    int sub_choice;
    cout << "Enter your choice: ";
    cin >> sub_choice;

    string src, dst;
    int cost;

    switch (sub_choice) {
    case 1: { // Update edge
        string transportation;
        cout << "Enter source city: ";
        cin >> src;
        cout << "Enter destination city: ";
        cin >> dst;

        cout << "Trasnportation available are: " << endl;

        for (auto it : graph.findWeight(src, dst))
        {
            cout << it.second << " " << it.first << endl;
        }

        cout << "Enter old transportation and its old cost: ";
        cin >> transportation >> cost;
        graph.Update(src, dst, { cost, transportation });
        cout << "Edge updated." << endl;
        break;
    }
    case 2: { // Add edge
        transportations t;
        cout << "Enter source city: ";
        cin >> src;
        cout << "Enter destination city: ";
        cin >> dst;
        char add_more = 'y';
        while (add_more == 'y' || add_more == 'Y') {
            string tr;
            cout << "Enter Transportation Name: ";
            cin >> tr;
            cout << "Enter Transportation Cost: ";
            int c;
            cin >> c;
            t.insert({ c, tr });
            cout << "Enter 'y' to add another transportation, 'n' to stop: ";
            cin >> add_more;
        }
        graph.Add(src, dst, t);
        cout << "Edge added." << endl;
        break;
    }
    case 3: { // Delete edge
        cout << "Enter source city: ";
        cin >> src;
        cout << "Enter destination city: ";
        cin >> dst;
        graph.Delete(src, dst);
        cout << "Transportation deleted." << endl;
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

// Main menu for the application
void mainMenu(Graph& graph) {
    bool running = true;

    while (running) {
        cout << endl;
        cout << "1. Traverse graph (BFS/DFS)" << endl;
        cout << "2. Modify Graph \"Update/Add/Delete\" edges" << endl;
        cout << "3. Check if graph is complete" << endl;
        cout << "4. Find routes within a budget" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Traversal
            string source, destination;
            cout << "Enter starting city: ";
            cin >> source;

            int algorithm;
            cout << "Choose algorithm (1. BFS, 2. DFS): ";
            cin >> algorithm;

            if (algorithm == 1) {
                graph.BFS_Traverse(source);
            }
            else if (algorithm == 2) {
                graph.DFS_Traverse(source);
            }
            else {
                cout << "Invalid choice." << endl;
            }
            break;
        }
        case 2: { // Modify graph
            handleGraphModification(graph);
            break;
        }
        case 3: { // Check completeness
            graph.checkCompleteness();
            break;
        }
        case 4: { // Find routes within a budget
            string src, dst;
            int budget;
            cout << "Enter source city: ";
            cin >> src;
            cout << "Enter destination city: ";
            cin >> dst;
            cout << "Enter budget: ";
            cin >> budget;

            int algorithm;
            cout << "Choose algorithm (1. BFS, 2. DFS): ";
            cin >> algorithm;

            if (algorithm == 1) {
                graph.displayAllPathsBFS(src, dst, budget);
            }
            else if (algorithm == 2) {
                graph.displayAllPathsDFS(src, dst, budget);
            }
            else {
                cout << "Invalid choice." << endl;
            }
            break;
        }
        case 5: { // Exit
            running = false;
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    }
}

int main() {
    Graph graph;
    graph.loadTheGraph();

    mainMenu(graph);

    graph.saveTheGraph();
    return 0;
}