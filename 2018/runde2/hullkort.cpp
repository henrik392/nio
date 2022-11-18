#include <iostream>
#include <cmath>

using namespace std;

int main() {
    unsigned int n = 0;
    cin >> n;

    int s = 1<<((n+n%2)/2);

    int ans =  ((1<<n)+s)/2-1;

    cout << ans << "\n";

    return 0;
}