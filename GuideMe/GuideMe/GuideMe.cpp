#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "Graph.h"
using namespace std;
using namespace chrono;

enum Color {
    defualt = 0x000f,
    GREENb_WHITEf = 0x002f,
    CYANb_WHITEf = 0x003f,
    WHITEb_BLACKf = 0x00f0,
    WHITEb_REDf = 0x00f4,
    REDb_WHITEf = 0x004f,
    PURPLEb_WHITEf = 0x005f,
    DARKYELLOWb_WHITEf = 0x006f,
    PINKb_WHITEf = 0x00cf,
};


void drawTitle(string title, Color TitleColor, Color MainColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TitleColor | 0x0700);

    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
    // Extract console width in characters
    int consoleWidth = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;

    int massegeSize = title.length();
    massegeSize += 2 * 8;
    string borders(8, ' ');
    string spaces(massegeSize, ' ');
    int negativeSpaceSize = consoleWidth / 2 - massegeSize / 2;
    string negativeSpace(negativeSpaceSize / 8, '\t');

    cout << negativeSpace + spaces << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TitleColor);

    cout << negativeSpace + borders + title + borders + "" << endl;
    cout << negativeSpace + spaces + "\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MainColor | 0x0700);
    cout << negativeSpace + spaces + "\n";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MainColor);


}

void drawBorder(string massege, int bordersSize, Color MsgColor, Color MainColor) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MsgColor);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);
    // Extract console width in characters
    int consoleWidth = bufferInfo.srWindow.Right - bufferInfo.srWindow.Left + 1;

    int massegeSize = massege.length();
    massegeSize += 2 * bordersSize;
    string borders(bordersSize, ' ');
    string spaces(massegeSize, ' ');
    int negativeSpaceSize = consoleWidth / 2 - massegeSize / 2;
    string negativeSpace(negativeSpaceSize / 8, '\t');

    cout << "\n";
    cout << negativeSpace + spaces << endl;
    cout << negativeSpace + borders + massege + borders + "" << endl;
    cout << negativeSpace + spaces + "\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MainColor);

}

void wait(int second) {
    seconds sec(second);
    this_thread::sleep_for(sec);
}

void invalidError() {
    //system("color 4f");
    cin.clear();
    cin.ignore(256, '\n');
    drawBorder("Invalid Input, Try Again", 4, REDb_WHITEf, WHITEb_BLACKf);
}
void invalidError(string msg) {
    //system("color 4f");
    cin.clear();
    cin.ignore(256, '\n');
    drawBorder(msg, 4, REDb_WHITEf, WHITEb_BLACKf);
}
// Main menu for the application

void handleGraphModification(Graph& graph, int& choice) {
    cout << "[1]. Update edge" << endl;
    cout << "[2]. Add edge" << endl;
    cout << "[3]. Delete edge" << endl;
    cout << "[4]. Back to Main Menu" << endl;
    int sub_choice;
    cout << " Enter your choice: ";
    cin >> sub_choice;
    if (cin.fail() || sub_choice > 4 || sub_choice < 1) {
        invalidError();
        wait(2);
        return;
    }

    string src, dst;
    int cost;


    switch (sub_choice) {
    case 1: {
        // Update edge
        string transportation;
        cout << " Enter source city: ";
        cin >> src;
        src[0] = toupper(src[0]);
        graph.displayNeighborCities(src);
        cout << " Enter destination city: ";
        cin >> dst;
        dst[0] = toupper(dst[0]);
        cout << " Trasnportation available are: " << endl;
        transportations setOfTransportations = graph.findWeight(src, dst);
        int i = 0;
        for (auto it : setOfTransportations)
        {
            cout << " " << i + 1 << " . " << it.second << " " << it.first << endl;
            i++;
        }
        i = 0;

        cout << " Enter old transportation and its old cost: ";
        cin >> transportation >> cost;
        while (cin.fail()) {
            invalidError();
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
        src[0] = toupper(src[0]);
        graph.displayAllCities(src);
        cout << " Enter destination city: ";
        cin >> dst;
        dst[0] = toupper(dst[0]);
        char add_more = 'y';
        while (add_more == 'y' || add_more == 'Y') {
            string tr;
            cout << " Enter Transportation Name: ";
            cin >> tr;
            cout << " Enter Transportation Cost: ";
            int c;
            cin >> c;
            while (cin.fail()) {
                invalidError();
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
        src[0] = toupper(src[0]);
        graph.displayNeighborCities(src);
        cout << " Enter destination city: ";
        cin >> dst;
        dst[0] = toupper(dst[0]);
        graph.Delete(src, dst);
        cout << " Transportation deleted." << endl;
        break;
    }
    case 4: { // Back to Main Menu edge
        choice = 0;
        return;
        break;
    }
    default:
        cout << " Invalid choice." << endl;
        break;
    }
    choice = 0;
}

void mainMenu(Graph& graph) {
    bool running = true;
    int choice = 0;
    while (running) {
        system("cls");

        switch (choice) {
        case 0: {
            /*  Main Menu  */
            system("cls");
            system("color 1");
            drawTitle("Main Menu", CYANb_WHITEf, defualt);
            cout << "[1]. Traverse graph (BFS/DFS)" << endl;
            cout << "[2]. Modify Graph \"Update/Add/Delete\" edges" << endl;
            cout << "[3]. Check if graph is complete" << endl;
            cout << "[4]. Find routes within a budget" << endl;
            cout << "[5]. Exit\n" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice > 5 || choice < 1)
            {
                cin.clear();
                cin.ignore(256, '\n');
                system("color 4f");
                drawBorder("invalid Input", 5, WHITEb_BLACKf, defualt);
                wait(2);
                choice = 0;
            }

            system("cls");
            break;
        }
        case 1: {
            // Traversal
            system("color f0");
            drawTitle("Traversal", PURPLEb_WHITEf, WHITEb_BLACKf);
            string source, destination;
            cout << " Enter starting city:  ";
            cin >> source;
            source[0] = toupper(source[0]);

            if (graph.graph.find(source) == graph.graph.end())
            {
                invalidError("This city doesn't exist, try again");
                wait(2);
                continue;
            }

            int algorithm = 0;
            cout << " Choose algorithm (1. BFS, 2. DFS): ";
            cin >> algorithm;
            while (cin.fail() || algorithm > 2 || algorithm < 1) {
                invalidError();
                wait(2);
                cout << " Choose algorithm (1. BFS, 2. DFS): ";
                cin >> algorithm;
            }
            system("color f0");
            cout << "\n";
            if (algorithm == 1) {
                graph.BFS_Traverse(source);
            }
            else if (algorithm == 2) {
                graph.DFS_Traverse(source);
            }
            cout << "\n";

            system("pause");
            choice = 0;
            break;
        }
        case 2: { // Modify graph
            system("color f0");
            drawTitle("Modify Graph", DARKYELLOWb_WHITEf, WHITEb_BLACKf);
            handleGraphModification(graph, choice);
            //choice = 0;
            break;
        }
        case 3: { // Check completeness
            system("color f0");
            drawTitle("Check Completeness", PINKb_WHITEf, WHITEb_BLACKf);
            graph.checkCompleteness();
            cout << "\n";
            system("pause");
            choice = 0;
            break;
        }
        case 4: { // Find routes within a budget

            system("color f0");
            drawTitle("Find Routes", GREENb_WHITEf, WHITEb_BLACKf);
            string src, dst;
            int budget;
            cout << " Enter source city: ";
            cin >> src;
            src[0] = toupper(src[0]);
            if (graph.graph.find(src) == graph.graph.end())
            {
                //drawBorder("This city doesn't exist, try again",4,WHITEb_REDf,WHITEb_BLACKf);
                invalidError("This city doesn't exist, try again");
                wait(2);
                continue;
            }
            graph.displayAllCities(src);
            cout << " Enter destination city: ";
            cin >> dst;
            dst[0] = toupper(dst[0]);
            if (graph.graph.find(dst) == graph.graph.end())
            {
                invalidError("This city doesn't exist, try again");
                wait(2);
                continue;
            }
            cout << " Enter budget: ";
            cin >> budget;
            while (cin.fail()) {
                invalidError();
                cout << " Enter budget: ";
                cin >> budget;
            }

            int algorithm = 0;
            cout << " Choose algorithm (1. BFS, 2. DFS): ";
            cin >> algorithm;
            while (cin.fail() || algorithm > 2 || algorithm < 1) {
                invalidError();
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

            system("pause");
            choice = 0;

            break;
        }
        case 5: { // Exit
            cout << "\n\n\n\n\n\n\n\n\n\n";
            drawBorder("Good Bye  ^^", 16, PINKb_WHITEf, defualt);
            cout << "\n\n\n\n\n\n\n\n\n";
            running = false;
            break;
        }
        default: {
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
