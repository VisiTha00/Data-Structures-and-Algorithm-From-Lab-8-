#include <iostream>
#include <vector>

using namespace std;

vector<int> DijkstraShortestTime(int graph[6][6],int source){
    vector<int> timeTaken(6,INT_MAX);
    vector<bool> visited(6,false);
    for(int i=0; i<6; i++){
        timeTaken[i] = INT_MAX;
        visited[i] = false;
    }

    timeTaken[source] = 0;

    for(int j=0; j<6; j++){
        int node;
        int minTime = INT_MAX;
        for(int i=0; i<(int)timeTaken.size(); i++){
            if(visited[i] == false && timeTaken[i]<=minTime){
                minTime = timeTaken[i];
                node = i;
            }
        }
        visited[node] = true;
        for(int m = 0; m<6; m++)
        {
            if(visited[m] == false && graph[node][m] && timeTaken[node]!=INT_MAX){
                if(timeTaken[node]+graph[node][m]<timeTaken[m]){
                    timeTaken[m]=timeTaken[node]+graph[node][m];
                }
            }
        }
    }

    return timeTaken;
}

int main()
{
    int graph[6][6] = {{0,10,0,0,15,5},
                       {10,0,10,30,0,0},
                       {0,10,0,12,5,0},
                       {0,30,12,0,0,20},
                       {15,0,5,0,0,0},
                       {5,0,0,20,0,0}
                      };
    for(int i = 0; i < 6; i++){
        cout << ".....Distance from City " << i << "....." << endl;
        vector<int> minimumTime = DijkstraShortestTime(graph,i);
        double totalTime = 0;
        for(int j = 0; j < 6; j++){
            if(i != j){
                cout << "Distance from city " << i << " to city " << j << " :- " << minimumTime[j] << endl;
                totalTime = totalTime + minimumTime[j];
            }
        }
        cout << "Average time taken to reach a city from city " << i << " :- " << totalTime/5 << endl;
        cout << "\n" << endl;
    }



    return 0;
}
