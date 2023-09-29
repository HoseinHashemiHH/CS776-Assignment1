


#include <vector>
#include <math.h>
using namespace std;
double eval_h(vector<int>& solution) {
 int highsum = 0;
 for (int val : solution) {
 if (val == 1) {
 highsum++;
 }
 }
 int targetfactor = 7;
 double fit = 1.0 / abs(highsum - targetfactor);
 return fit;
}