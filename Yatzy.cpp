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

// Class representing the Yatzy game
class Yatzy
{
   public:
   void dicerolling(){  // Function to roll the dice and handle re-rolls

        srand(static_cast<unsigned int>(time(0)));// Initialize random number generator
        vector<int> dice(5); // Vector to store results of 5 dice
        char reroll = 'y'; // Variable to check if re-rolls are requested

         // Roll all dice and display the results
        rollAllDice(dice);
        displayDice(dice);

         // Ask the user if they want to re-roll specific dice
        while(reroll == 'y' || reroll == 'Y'){  
            cout << "Do u want to reroll specific dice? (y/n): " << endl;
            cin >> reroll;
            if (reroll == 'y' || reroll == 'Y'){
                rerollSelectedDice(dice); // Re-roll chosen dice
                displayDice(dice);   // Display updated results
            }
        }
   }

    // Rolls all dice and stores the results in the dice vector
   void rollAllDice (vector<int> & dice){
        for (int i = 0; i < 5; i++)
                {
                    dice[i] =rand() % 6 + 1; // Assign each die a random value between 1 and 6
                }
   }

    // Displays the current results of all dice
   void displayDice(const vector<int> & dice){
        for (int i = 0; i < 5; i++){
        cout << "Roll " << i + 1 << " is " << dice[i] << endl;
        }
        cout << endl;
   }

    // Re-rolls specific dice chosen by the user
   void rerollSelectedDice(vector<int> & dice){
        int rollNumber;
        cout << "Enter the dice number (1-5) you want to reroll, separated by spaces (0 to finish): ";
        // Continue until the user enters 0, which stops re-rolling
        while (true)
        {
            cin >> rollNumber;
            if (rollNumber == 0) break;  // Stop if user enters 0
            if (rollNumber >= 1 && rollNumber <= 5){
                    dice[rollNumber - 1] = rand() % 6 + 1; // Re-roll specified die
            }else {
                    cout << "Invalid dice number. Please enter a number between 1 and 5" << endl;
            }
        }
    

   }
};
int main(){
    int choosemenu;
    do{ /// Display the menu and let the user make a selection
    cout << "Play Yatzy, menu: " << endl;
    cout << "1: Game rules." << endl;
    cout << "2: Start game!" << endl;
    cout << "3: Quit game." << endl;
    cout << "Enter you choice: " << endl;
    ;
    cin >> choosemenu;
        // Handle the user's choice
        switch (choosemenu)
        {
        case 1:
            printMainMenu();  // Display game rules from the file
            break;
        case 2:
            Yatzy game;
            game.dicerolling();  // Start the game with dice rolling
            break;
        case 3:
            cout << "Game quit. Byebye!" << endl;
            break;
        
        default:
            cout << "Invalid input, Please try again." << endl;
            break;
        }
        
    }while(choosemenu != 3); // Continue until the user chooses to quit
   
    return 0;
}