#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Yatzy
{
   public:
   void dicerolling(){
        srand(static_cast<unsigned int>(time(0)));
        vector<int> dice(5);
        char reroll = 'y';

        rollAllDice(dice);
        displayDice(dice);
        while(reroll == 'y' || reroll == 'Y'){  
            cout << "Do u want to reroll specific dice? (y/n): " << endl;
            cin >> reroll;
            if (reroll == 'y' || reroll == 'Y'){
                rerollSelectedDice(dice);
                displayDice(dice);
            }
        }
   }
   void rollAllDice (vector<int> & dice){
        for (int i = 0; i < 5; i++)
                {
                    dice[i] =rand() % 6 + 1;
                }
   }
   void displayDice(const vector<int> & dice){
        for (int i = 0; i < 5; i++){
        cout << "Roll " << i + 1 << " is " << dice[i] << endl;
        }
        cout << endl;
   }
   void rerollSelectedDice(vector<int> & dice){
        int rollNumber;
        cout << "Enter the dice number (1-5) you want to reroll, separated by spaces (0 to finnish): ";
        while (true)
        {
            cin >> rollNumber;
            if (rollNumber == 0) break;
            if (rollNumber >= 1 && rollNumber <= 5){
                    dice[rollNumber - 1] = rand() % 6 + 1;
            }else {
                    cout << "Invalid dice number. Please enter a number between 1 and 5" << endl;
            }
        }
    
   }
};
int main(){
    Yatzy game;
    game.dicerolling();
    return 0;
}