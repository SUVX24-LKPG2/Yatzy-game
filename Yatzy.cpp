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

class Category
{
    public:
    string name; 
    int score;
    bool used;
};

// Class representing the Yatzy game
class Yatzy
{
   public:
   int diceroll = 0;
   vector<Category> categories = {{"Ones"}, {"Twos"}, {"Threes"}, {"Fours"}, {"Fives"}, {"Sixes"}, {"Three of a kind"}, {"Four of a kind"}, {"Full house"}, {"Small straight"}, {"Large straight"}, {"Chance"}, {"Yatzy"}};;
   void dicerolling(){  // Function to roll the dice and handle re-rolls

        srand(static_cast<unsigned int>(time(0)));// Initialize random number generator
        vector<int> dice(5); // Vector to store results of 5 dice
        char reroll = 'y'; // Variable to check if re-rolls are requested
        diceroll = 0;
    // Roll all dice and display the results
        rollAllDice(dice);
        displayDice(dice);
        //if(diceroll <3)
        //{
            // Ask the user if they want to re-roll specific dice
            while((reroll == 'y' || reroll == 'Y') && diceroll < 3){  
                cout << "Do u want to reroll specific dice? (y/n): " << endl;
                cin >> reroll;
                if (reroll == 'y' || reroll == 'Y'){
                    rerollSelectedDice(dice); // Re-roll chosen dice
                    displayDice(dice);   // Display updated results
                    diceroll++;
                }
            }  
        registerScore(dice); // Register the score for the current round
   }

    // Rolls all dice and stores the results in the dice vector
   void rollAllDice (vector<int> & dice){
        for (int i = 0; i < 5; i++)
                {
                    dice[i] =rand() % 6 + 1; // Assign each die a random value between 1 and 6
                }
                diceroll++;
   }

    // Displays the current results of all dice
   void displayDice(const vector<int> & dice){
        for (int i = 0; i < 5; i++){
        cout << "Roll " << i + 1 << " is " << dice[i] << endl;
        }
        cout << endl;
   }

    // Re-rolls specific dice chosen by the user
   void rerollSelectedDice(vector<int> & dice)
   {
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

    int calculateScore(const vector<int>& dice, const string& category) 
    {
        int score = 0;
        if(category == "Ones") {
            for (int d : dice) if (d == 1) score += 1;
        } else if (category == "Twos") {
            for (int d : dice) if (d == 2) score += 2;
        } else if (category == "Threes") {
            for (int d : dice) if (d == 3) score += 3;
        } else if (category == "Fours") {
            for (int d : dice) if (d == 4) score += 4;
        } else if (category == "Fives") {
            for (int d : dice) if (d == 5) score += 5;
        } else if (category == "Sixes") {
            for (int d : dice) if (d == 6) score += 6;
        } else if (category == "Three of a kind") {
            vector<int> counts(7, 0);
            for (int d : dice) counts[d]++;
            for (int count : counts) if (count >= 3) score = 3 * (count >= 3 ? 1 : 0); // Simple check
        } else if (category == "Four of a kind") {
            vector<int> counts(7, 0);
            for (int d : dice) counts[d]++;
            for (int count : counts) if (count >= 4) score = 4 * (count >= 4 ? 1 : 0); // Simple check
        } else if (category == "Full house") {
            vector<int> counts(7, 0);
            for (int d : dice) counts[d]++;
            bool has2 = false, has3 = false;
            for (int count : counts) {
                if (count == 2) has2 = true;
                if (count == 3) has3 = true;
            }
            if (has2 && has3) score = 25;
        } else if (category == "Small straight") {
            vector<int> counts(7, 0);
            for (int d : dice) counts[d]++;
            if (counts[1] && counts[2] && counts[3] && counts[4] && counts[5]) score = 30;
        } else if (category == "Large straight") {
            vector<int> counts(7, 0);
            for (int d : dice) counts[d]++;
            if (counts[2] && counts[3] && counts[4] && counts[5] && counts[6]) score = 40;
        } else if (category == "Chance") {
            for (int d : dice) score += d;
        } else if (category == "Yatzy") {
            vector<int> counts(7, 0);
            for (int d : dice) counts[d]++;
            for (int count : counts) if (count >= 5) score = 50;

        }
        // Implementera fler kategorier...

        return score;
    }

    void registerScore(const vector<int> &dice)
    {
        cout << "Available categories:\n";
            for (size_t i = 0; i < categories.size(); i++) 
            {
                cout << i + 1 << ". " << categories[i].name;
                if (categories[i].used) 
                {
                    cout << " (Used: " << categories[i].score << ")";
                }
                cout << endl;
            }
            int choice;
            cout << "Choose a category to register your score (1-" << categories.size() << "): ";
            cin >> choice;

            if (choice >= 1 && choice <= categories.size() && !categories[choice - 1].used) {
                categories[choice - 1].score = calculateScore(dice, categories[choice - 1].name);
                categories[choice - 1].used = true;
                cout << "Score for " << categories[choice - 1].name << ": " << categories[choice - 1].score << endl;
            } else {
                cout << "Invalid choice or category already used." << endl;
            }

    }
};

void runGame(bool& gameIsRunning)
{
    gameIsRunning = false;
}

int main(){

    int choosemenu;
    do{ /// Display the menu and let the user make a selection
    cout << "Play Yatzy, menu: " << endl;
    cout << "1: Game rules." << endl;
    cout << "2: Start game!" << endl;
    cout << "3: Quit game." << endl;
    cout << "Enter you choice: " << endl;
    cin.clear();
    cin >> choosemenu;
        // Handle the user's choice
            switch (choosemenu)
            {
                case 1:
                {
                    printMainMenu();  // Display game rules from the file
                    break;
                }
                case 2:
                {
                    Yatzy game;
                    int rounds = 0;
                    while(rounds < 13) {
                        game.dicerolling();  // Start the game with dice rolling
                       
                    rounds++;
                    }
                    break;
                }
                case 3:
                {
                    cout << "Game quit. Byebye!" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid input, Please try again." << endl;
                    break;
                }
            }
    } while (choosemenu != 3);
        
        
    

    return 0;
}