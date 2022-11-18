#include <iostream>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i<n; i++) {
        long long t = 0;
        cin >> t;
        if (t%2) {
            cout << "GALT\n";
        } else {
            cout << "RIKTIG\n";
        }
    }
    return 0;
}
