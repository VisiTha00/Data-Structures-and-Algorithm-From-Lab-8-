#include<iostream>
#include<climits>

using namespace std;

void minimumCost(int costArray[6][6],int vertices,int source)
{
    int predecessor[vertices];
    int keyWeight[vertices];
    bool visited[vertices];

    for(int i = 0; i< vertices; i++) {
        if(i != source){
            keyWeight[i] = INT_MAX;
            predecessor[i] = NULL;
        }
        else{
            keyWeight[i] = 0;
            predecessor[i] = -1;
        }
        visited[i] = false;
    }

    for(int i = 0; i < vertices - 1; i++){
        int minimum = INT_MAX;
        int minimumIndex = -1;
        for(int vertex = 0; vertex < vertices; vertex++) {
            if(visited[vertex] == false && keyWeight[vertex] < minimum) {
                minimum = keyWeight[vertex];
                minimumIndex = vertex;
            }
        }
        visited[minimumIndex] = true;

        for(int vertex = 0; vertex < vertices; vertex++)  {
            if (costArray[minimumIndex][vertex] !=0 && visited[vertex] == false){
                if(costArray[minimumIndex][vertex] < keyWeight[vertex]){
                    predecessor[vertex] = minimumIndex;
                    keyWeight[vertex] = costArray[minimumIndex][vertex];
                }
            }
        }
    }

    int minCost = 0;
	cout << "Edge \t      Weight" << endl;
    for(int i = 1; i< vertices; i++) {
        minCost = minCost + costArray[i][predecessor[i]];
        if(predecessor[i] != -1){
            cout << predecessor[i]<<" - "<< i << "\t\t" << costArray[i][predecessor[i]]<< endl;
        }
        else{
            cout << source <<" - "<< i << "\t\t" << costArray[i][predecessor[i]]<< endl;
        }
    }
	cout <<"Total cost is :- "<< minCost;
}

int main()
{
    int vertices = 6;
    int source = 0;
    int costArray[6][6] = {{0,3,0,0,0,1},{3,0,2,1,10,0},{0,2,0,3,0,5},{0,1,3,0,5,0},{0,10,0,5,0,4},{1,0,5,0,4,0}};
	minimumCost(costArray,vertices,source);
    return 0;
}
