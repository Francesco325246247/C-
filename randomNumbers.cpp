#include <iostream>
#include <random>
#include <ctime>
 
using namespace std;
 
int rollDice1(int min, int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int rollDice2(int min, int max){
    srand(static_cast<unsigned int>((int)time(nullptr)));
    int number = rand()%(max-min)+1;
    return number;
}
int main() {
   int number1 = rollDice1(1,10);
   int number2 = rollDice2(1,10);
   cout << number1 << " "<<number2 << endl;
    return 0;
}
