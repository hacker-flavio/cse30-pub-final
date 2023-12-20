#include <cstdint>
#include <iostream>
#include <string>
#include "HashTable.h"
#include "Vertex.h"
#include "Graph.h"
#include "Stack.h"

using namespace std;

template <class T>
void display(Waypoint<T>* end){
    Stack<Waypoint<T>*> stack;
    Waypoint<T>* temp = end;
    while (temp != nullptr){
        stack.push(temp);
        temp = temp->parent;
    }
    while (stack.length() > 0){
        Waypoint<T>* curr = stack.pop();
        cout << curr->vertex->data << ", " << curr->weight << ", " << curr->partialCost << endl;
    }
}

int main(){


    auto sfo = new Vertex<string>("San Francisco");
    auto nyc = new Vertex<string>("New York");
    auto rio = new Vertex<string>("Rio De Janeiro");
    auto paris = new Vertex<string>("Paris");
    auto joburg = new Vertex<string>("Johannesburg");
    auto moscow = new Vertex<string>("Moscow");
    auto sydney = new Vertex<string>("Sydney");
    auto tokyo = new Vertex<string>("Tokyo");
    auto beijing = new Vertex<string>("Beijing");

    Graph<string> g;
    g.addVertex(sfo);
    g.addVertex(nyc);
    g.addVertex(rio);
    g.addVertex(paris);
    g.addVertex(joburg);
    g.addVertex(moscow);
    g.addVertex(sydney);
    g.addVertex(tokyo);
    g.addVertex(beijing);

    g.addEdge(sfo, nyc, 6);
    g.addEdge(nyc, rio, 13);
    g.addEdge(nyc, joburg, 14);
    g.addEdge(nyc, paris, 7);
    g.addEdge(nyc, moscow, 15);
    g.addEdge(rio, paris, 11);
    g.addEdge(rio, beijing, 18);
    g.addEdge(paris, sydney, 17);
    g.addEdge(joburg, tokyo, 16);
    g.addEdge(joburg, sydney, 11);
    g.addEdge(sydney, tokyo, 10);
    g.addEdge(tokyo, beijing, 3);
    g.addEdge(beijing, moscow, 8);
    g.addEdge(nyc, sydney, 40);
    

    // Waypoint<string>* result = g.shortestPath(sfo, sydney);
    // cout << result->parent->parent->parent->vertex->data << endl;


    Waypoint<string>* result = g.shortestPath(sfo, sydney);
    Waypoint<string>* temp = result; 
    Stack<string> s;
    while (temp != nullptr){
        // cout << temp->vertex->data << endl;
        s.push(temp->vertex->data);
        temp = temp->parent;
    }
    cout << "Flight path: ";
    while(!s.isEmpty()){
       
       cout << s.pop(); 
      
       if(s.length() > 0){ 
           cout << " -> ";
        }else{
            cout << ";";
        }

       
    }
    cout << endl;

    cout << "Will take: " << result->partialCost << " to fly to sydney" << endl;

    

    delete sfo;
    delete nyc;
    delete rio;
    delete paris;
    delete joburg;
    delete moscow;
    delete sydney;
    delete tokyo; 
    delete beijing;

    return 0;
}