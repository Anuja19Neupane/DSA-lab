#include <iostream>
#include <vector>
using namespace std;

#define INF 999999  

int n; // Number of cities
vector<vector<int> > distancee; // Adjacency matrix

int VISITED_ALL;

// Traveling Salesman Problem function
int travelling_salesman_problem(int mask, int pos) { 
    if (mask == VISITED_ALL) {
        return distancee[pos][0]; // Return to the origin
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = distancee[pos][city] + travelling_salesman_problem(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    // Resize the distance matrix based on user input
    distancee.resize(n, vector<int>(n));

    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distancee[i][j];
        }
    }

    VISITED_ALL = (1 << n) - 1; // Update VISITED_ALL based on user input

    cout << "Minimum travel cost: " << travelling_salesman_problem(1, 0) << endl;
    return 0;
}
