#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream file1;
    file1.open("turtle.in");
    ofstream file2;
    file2.open("turtle.out"); 
    int graph[1000][1000];
    int n, m;
    file1 >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            file1 >> graph[i][j];
        }
    }
    int m1, m2;
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<m; j++) {
            m1 = 0;
            m2 = 0;
            if (i<n-1) {
                m1 = graph[i+1][j];
            }
            if (j>0) {
                m2 = graph[i][j-1];
            }
            if (m1 <= m2) {
                graph[i][j] += m2;
            }
            else {
                graph[i][j] += m1;
            }
        }
    }
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<m; j++) {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    file2 << graph[0][m-1];
    return 0;
}