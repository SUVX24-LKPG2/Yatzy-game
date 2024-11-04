#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void printMainMenu()
{   
    //Opens the file in reading mode
    ifstream f("RULES.txt");

    //Checks if the file is opened correctly
    if (!f.is_open())
    {
        cerr << "Error message!: Couldnt open the file!";
        return;
    }

    //String variable to to store the read data
    string s;

    // Read each line of the file and print it to the
    // Standard output stream till the whole file is 
    // Completely read
    while (getline(f, s))
    {
        cout << s << endl;
    }

    //Close the file
    f.close();
    return;
    //I got help from Geeks4Geeks to solve this 
}  

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

void runGame(bool& gameIsRunning)
{
    gameIsRunning = false;
}

int main(){
    bool gameIsRunning = true;
    Yatzy game;
    printMainMenu();
    game.dicerolling();
    return 0;
}