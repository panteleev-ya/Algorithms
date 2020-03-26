#include<iostream>
#include<fstream>

using namespace std;

long long int n, a, t;
long long int m[10000];
int main() {
    ifstream file1;
    file1.open("smallsort.in");
    ofstream file2;
    file2.open("smallsort.out");
    file1 >> n;
    for (int i=0; i<n; i++) {
        file1 >> m[i];
    }
    for (int i=0; i<n; i++) {
        a = i;
        for (int j=i+1; j<n; j++) {
            if (m[j] <= m[a]) {
                a = j;
            }
        }
        t = m[i];
        m[i] = m[a];
        m[a] = t;
    }
    for (int i=0; i<n; i++) {
        file2 << m[i] << ' ';
    }
    return 0;
}