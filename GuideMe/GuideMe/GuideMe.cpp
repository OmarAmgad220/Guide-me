#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <conio.h>
#include<windows.h>
#include <stdlib.h> 

#include "Graph.h"
using namespace std;



void handleGraphModification(Graph& graph) {
    cout << "[1]. Update edge" << endl;
    cout << "[2]. Add edge" << endl;
    cout << "[3]. Delete edge" << endl;
    cout << "[4]. Back to Main Menu" << endl;
    int sub_choice;
    cout << " Enter your choice: ";
    cin >> sub_choice;
    while (cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f4);
        cout << " Invalid choice !\n" << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);
        cout << "[1]. Update edge" << endl;
        cout << "[2]. Add edge" << endl;
        cout << "[3]. Delete edge" << endl;
        cout << "[4]. Back to Main Menu" << endl;
        cin >> sub_choice;
    }

    string src, dst;
    int cost;


    switch (sub_choice) {
    case 1: { // Update edge
        string transportation;
        cout << " Enter source city: ";
        cin >> src;
        cout << " Enter destination city: ";
        cin >> dst;

        cout << " Trasnportation available are: " << endl;
        transportations setOfTransportations= graph.findWeight(src, dst);
        int i = 0;
        for (auto it : setOfTransportations)
        {
            cout <<" "<<i+1<<" . " << it.second << " " << it.first << endl;
            i++;
        }

        cout << " Enter old transportation and its old cost: ";
        cin >> transportation >> cost;
        while (cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f4);
            cout << " Invalid choice !\n" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);
            cout << " Enter old cost : ";
            cin >> cost;
        }
        graph.Update(src, dst, { cost, transportation });
        cout << " Edge updated." << endl;
        break;
    }
    case 2: { // Add edge
        transportations t;
        cout << " Enter source city: ";
        cin >> src;
        cout << " Enter destination city: ";
        cin >> dst;
        char add_more = 'y';
        while (add_more == 'y' || add_more == 'Y') {
            string tr;
            cout << " Enter Transportation Name: ";
            cin >> tr;
            cout << " Enter Transportation Cost: ";
            int c;
            cin >> c;
            while (cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f4);
                cout << " Invalid choice !\n" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);
                cout << "Enter Transportation Cost: ";
                cin >> c;
            }
            t.insert({ c, tr });
            cout << " Enter 'y' to add another transportation, 'n' to stop: ";
            cin >> add_more;
        }
        graph.Add(src, dst, t);
        cout << " Edge added." << endl;
        break;
    }
    case 3: { // Delete edge
        cout << " Enter source city: ";
        cin >> src;
        cout << " Enter destination city: ";
        cin >> dst;
        graph.Delete(src, dst);
        cout << " Transportation deleted." << endl;
        break;
    }
    case 4: { // Delete edge
        return;
        break;
    }
    default:
        cout << " Invalid choice." << endl;
        break;
    }
}

// Main menu for the application
void mainMenu(Graph& graph) {
    bool running = true;

    while (running) {
        system("cls");
        system("color 2");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x003f);
        cout << "\t\t\t\t\t____________Main Menu______________\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x000f);

        cout << "[1]. Traverse graph (BFS/DFS)" << endl;
        cout << "[2]. Modify Graph \"Update/Add/Delete\" edges" << endl;
        cout << "[3]. Check if graph is complete" << endl;
        cout << "[4]. Find routes within a budget" << endl;
        cout << "[5]. Exit\n" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        while (cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0004);
            cout << " Invalid choice !\n" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x000f);
            cout << "[1]. Traverse graph (BFS/DFS)" << endl;
            cout << "[2]. Modify Graph \"Update/Add/Delete\" edges" << endl;
            cout << "[3]. Check if graph is complete" << endl;
            cout << "[4]. Find routes within a budget" << endl;
            cout << "[5]. Exit\n" << endl;
            cin >> choice;
        }
        system("cls");
        switch (choice) {
        case 1: { // Traversal
            system("color f0");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x004f);
            cout <<"\t\t\t\t\t____________Traversal____________\n\n"  ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);

            string source, destination;
            cout << " Enter starting city:  ";
            cin >> source;

            int algorithm;
            cout << " Choose algorithm (1. BFS, 2. DFS): ";
            cin >> algorithm;
            while (cin.fail()) {
                system("color 4f");
                std::cin.clear();
                std::cin.ignore(256, '\n');
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f4);
                cout << " Invalid choice !\n" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);
                cout << " Choose algorithm (1. BFS, 2. DFS): ";
                cin >> algorithm;
                system("color f0");
            }
          
            cout << "\n";
            if (algorithm == 1) {
                graph.BFS_Traverse(source);
            }
            else if (algorithm == 2) {
                graph.DFS_Traverse(source);
            }
            else {
                cout << " Invalid choice." << endl;
            }

            cout << "\n";
            system("pause");

            break;
        }
        case 2: { // Modify graph
            system("color f0");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x006f);
            cout << "\t\t\t\t\t____________Modify The Graph____________\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);

            handleGraphModification(graph);
            break;
        }
        case 3: { // Check completeness
            system("color f0");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x009f);
            cout << "\t\t\t\t\t___________Check completeness___________\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);

            graph.checkCompleteness();
            cout << "\n";

            system("pause");
            break;
        }
        case 4: { // Find routes within a budget

            system("color f0");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x002f);
            cout << "\t\t\t\t___________Find routes within a budget___________\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);

            string src, dst;
            int budget;
            cout << " Enter source city: ";
            cin >> src;
            cout << " Enter destination city: ";
            cin >> dst;
            cout << " Enter budget: ";
            cin >> budget;
            while (cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f4);
                cout << " Invalid Input !\n" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);

                cout << " Enter budget: ";
                cin >> budget;
            }

            int algorithm;
            cout << " Choose algorithm (1. BFS, 2. DFS): ";
            cin >> algorithm;
            while (cin.fail()) {
                system("color 4f");
                std::cin.clear();
                std::cin.ignore(256, '\n');
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f4);
                cout << " Invalid choice !\n" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);
                cout << " Choose algorithm (1. BFS, 2. DFS): ";
                cin >> algorithm;
            }
            system("color f0");


            if (algorithm == 1) {
                graph.displayAllPathsBFS(src, dst, budget);
            }
            else if (algorithm == 2) {
                graph.displayAllPathsDFS(src, dst, budget);
            }
            else {
                cout << " Invalid choice." << endl;
                continue;
            }
            system("pause");

            break;
        }
        case 5: { // Exit
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x00f0);
            cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t                                "<< endl;
            cout << "\t\t\t\t\t            Good Bye            " << endl;
            cout << "\t\t\t\t\t                                \n\n\n\n\n\n\n\n\n\n" << endl;

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
