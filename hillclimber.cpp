

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/*this is done according to the fact from class that :
s0=initial guessed solution
F0=evaluate(s0)
while(solution is not obtained):
s1=generate a new solution
F1=evaluate(s1)
if (F1>F0);
s0=s1
F0=F1
return s0
*/ 

// Predefined evaluation function
double eval_h(int *pj);
// double eval_e(int *p);
// double eval(int *j);
// Generate a random initial solution "first step in the algorithm of hill climber"
vector<int> generateRandomSolution(int length) {   //using module vector to easily define vector in cpp
    vector<int> solution(length);  // define a vector with length of length (array corresponding to the problem face)
    for (int i = 0; i < length; ++i) { 
        solution[i] = rand() % 101; // defined array with random values between 0 and 100 as initial guess of algorithm
    }
    return solution;
}

// Hill climbing algorithm to maximize the evaluation function
vector<int> hillClimbing(int length, int maxIterations) { 
    vector<int> currentSolution = generateRandomSolution(length); //initial guess
    double currentScore = eval_h(currentSolution.data());     // .data obtain a pointer to the vector(array)

    for (int i = 0; i < maxIterations; ++i) { // if you put iteration on 30000 it is the treshold you can get 100 as output
     //but under this threshold you will get between 60-100
        vector<int> neighborSolution = currentSolution;   //define the neighbor as the moddified state which the eval of initial guess
        int indexToChange = rand() % length;
        neighborSolution[indexToChange] = rand() % 101; // Change one random element

        double neighborScore = eval_h(neighborSolution.data()); // if eval exp new guess like input[70]=a, make its evaluation

        if (neighborScore > currentScore) {    // if eval new guess> initial guess :fitness
            currentSolution = neighborSolution;   // curent cromosom=new chromosom
            currentScore = neighborScore;         //change fitness
        }
    }

    return currentSolution;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int arrayLength = 100;
    int maxIterations = 60000;

    vector<int> result = hillClimbing(arrayLength, maxIterations);

    cout << "Maximized Array: ";
    for (int i = 0; i < arrayLength; ++i) {
        cout << result[i] << " ";
    }
    cout << std::endl;



    double maxScore = eval_h(result.data());
    std::cout << "Maximized Score: " << maxScore << std::endl;
    return 0;
}
