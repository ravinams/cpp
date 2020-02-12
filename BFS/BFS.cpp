#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

//bfs_traversal function which takes adjacency adj_matrix and start vertex as input
void bfs_traversal(std::vector<std::vector<int> > &adj_matrix, int start)
 { 
    //boolean vector to track visited vertices
    std::vector<bool> visited(adj_matrix.size(), false);
    std::queue<int> que; //queue

    que.push(start); //push starting vertex into queue
    visited[start] = true; //visit it
    cout << start; //printing the path

    while (!que.empty()) {

        int top = que.front();
        que.pop(); //remove front of queue

        //visit adjacent nodes of top vertex of queue
        for (int i = 0; i < adj_matrix.size(); ++i) {
            //if adjacent and not vistied before
            if (adj_matrix[top][i] != 0 && (!visited[i])) {
                que.push(i); //push into queue
                visited[i] = true;
                cout << "->" << i; //print path

            }

        }
       

    } //end of while
 cout<<endl;
}//end of bfs_traversal

int main(int argc, char const *argv[])
 {

    /* code */

    string filename; //filename
    cout << "Enter filename: ";
    cin>>filename; //input filename

    ifstream myfile(filename.c_str()); //open file
    int i, n, start;
    myfile>>n; //read the order of adj_matrix

    int a[n][n];

    for (i = 0; i < n; i++)
 {

        for (int j = 0; j < n; j++)

            myfile >> a[i][j]; //read the values from file

    }

    std::vector<std::vector<int> > adj_matrix;

    //store in 2-d vector, 2-d array can also be used

    for (i = 0; i < n; i++)
 {
        std::vector<int> v; //temp vector

        for (int j = 0; j < n; j++)

            v.push_back(a[i][j]);

        adj_matrix.push_back(v); //push in 2-d vector

    }

    cout << "Enter a start vertex: ";

    cin>>start; //starting vertex

    bfs_traversal(adj_matrix, start); //call bfs_traversal function

    return 0;

}