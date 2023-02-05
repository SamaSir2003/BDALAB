#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node *next;
};

struct Graph {
    int vertices;
    Node *list[100];
};

void display(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        Node *temp = graph->list[i];
        while (temp->next != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << temp->vertex << " ";
        cout << endl;
    }
    cout << endl;
}

void addVertex(Graph *graph, int vertex) {
    Node *node = new Node;
    node->next = NULL;
    node->vertex = vertex;

    graph->list[vertex] = node;
    graph->vertices++;
}

void addEdge(Graph *graph, int v1, int v2) {
    Node *tempV1 = graph->list[v1];
    Node *tempV2 = graph->list[v2];

    while (tempV1->next != NULL) {
        tempV1 = tempV1->next;
    }

    Node *newV1Node = new Node;
    newV1Node->next = NULL;
    newV1Node->vertex = v2;
    tempV1->next = newV1Node;

    while (tempV2->next != NULL) {
        tempV2 = tempV2->next;
    }

    Node *newV2Node = new Node;
    newV2Node->next = NULL;
    newV2Node->vertex = v1;
    tempV2->next = newV2Node;
}

int main() {
    int choice;

    Graph *graph = new Graph;
    graph->vertices = 0;


    cout << "Enter choice\n";
    cout << "1) Insert vertex\n";
    cout << "2) Insert edge\n";
    cout << "3) Display\n";

    while (true) {
        cout << "Enter choice\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int vertex;
                cout << "Enter vertex\n";
                cin >> vertex;

                addVertex(graph, vertex);
                break;
            }
            case 2: {
                int v1, v2;
                cout << "Enter 2 vertices\n";
                cin >> v1;
                cin >> v2;

                addEdge(graph, v1, v2);
                break;
            }
            case 3: {
                display(graph);
                break;
            }
            default: {
                exit(0);
            }
        }
    }
}
