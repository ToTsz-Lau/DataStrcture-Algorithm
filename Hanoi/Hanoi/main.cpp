#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
 
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {

        return;
    }
 
 
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
 
// Driver code
int main()
{
  auto start = high_resolution_clock::now();
    int N = 3;
 
    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Duration is: " << duration.count() << "microseconds" <<endl;
    return 0;
}
