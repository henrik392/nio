#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<pair<int, int> > getNeighbours(pair<int, int> rock, map<pair<int, int>, int> &rocks) {
    vector<pair<int, int> > positionsToCheck {
        {rock.first + 1, rock.second},
        {rock.first - 1, rock.second},
        {rock.first, rock.second + 1},
        {rock.first, rock.second - 1}
    };
    
    for (int i = 3; i>=0; i--) {
        // Remove position if it does not exist or if it is already checked
        if (rocks.find(positionsToCheck[i]) == rocks.end() || rocks[positionsToCheck[i]] != 0) {
            positionsToCheck.erase(positionsToCheck.begin() + i);
        }
    }

    return positionsToCheck;
}

int main() {
    int B, L, S;
    cin >> B >> L >> S;

    // Position and distance
    map<pair<int, int>, int> rocks;

    // for (auto i : position) {
    //     for (auto n : i) {
    //         cout << n << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i<S; i++) {
        int b, l;
        cin >> b >> l;
        rocks[{b, l}] = 0;
    }

    queue<pair<int, int>> queue;

    // Find position from the first row and set it to distance to 1
    for (int l = 0; l<=L; l++) {
        if (rocks.find({0, l}) != rocks.end()) {
            queue.push({0, l});
            rocks[{0, l}] = 1;
        }
    }

    // Loop through the que till it is empty
    while (!queue.empty()) {
        pair<int, int> currentRock = queue.front();
        queue.pop();

        // Check if path is complete, the first to reach l=L-1 will be the shortest
        if (currentRock.first == B-1) {
            cout << rocks[currentRock]+1 << "\n";
            return 0;
        }

        // vector<pair<int, int>> neighbours = getNeighbours(currentRock, rocks);

        vector<pair<int, int> > positionsToCheck {
            {currentRock.first + 1, currentRock.second},
            {currentRock.first - 1, currentRock.second},
            {currentRock.first, currentRock.second + 1},
            {currentRock.first, currentRock.second - 1}
        };
    
        for (int i = 0; i<4; i++) {
            // Remove position if it does not exist or if it is already checked
            if (rocks.find(positionsToCheck[i]) != rocks.end() && rocks[positionsToCheck[i]] == 0) {
                rocks[positionsToCheck[i]] = rocks[currentRock] + 1;
                queue.push(positionsToCheck[i]);
            }
        }

        // for (size_t i = 0; i<neighbours.size(); i++) {
        //     rocks[neighbours[i]] = rocks[currentRock] + 1;
        //     queue.push(neighbours[i]);
        // }
    }

    // Path is not complete
    return 1;
}

// input:
// 6 5 16
// 0 1
// 0 4
// 1 1
// 1 4
// 2 1
// 2 2
// 2 3
// 2 4
// 3 0
// 3 3
// 4 0
// 4 1
// 4 2
// 4 3
// 5 0
// 5 2

// Output:
// 9