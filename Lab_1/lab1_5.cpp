#include<iostream>
#include<fstream>

using namespace std;

long long int n, a;
float t;
float m[10000];
float m2[10000];
int main() {
    ifstream file1;
    file1.open("sortland.in");
    ofstream file2;
    file2.open("sortland.out");
    file1 >> n;
    for (int i=0; i<n; i++) {
        file1 >> m[i];
        m2[i] = m[i];
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
    float j1, j2, j3;
    j1 = m[0];
    j2 = m[(n+1)/2-1];
    j3 = m[n-1];
    int i1, i2, i3;
    for (int i=0; i<n; i++) {
        if (m2[i] == j1) {
            i1 = i;
        }
        else if (m2[i] == j2) {
            i2 = i;
        }
        else if (m2[i] == j3) {
            i3 = i;
        }
    }
    file2 << i1+1 << ' ' << i2+1 << ' ' << i3+1;
    return 0;
}