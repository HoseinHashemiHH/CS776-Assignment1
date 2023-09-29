

#include <vector>
using namespace std;
double eval_e(vector<int>& solution) {
 int high_count = 0;
 for (int val : solution) {
 if (val == 1) {
 high_count++;
 }
 }
 return static_cast<double>(high_count);
}

