#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
     for (int i = 1; i < 6; i++)
     {
        int random_rumber =rand() % 6 + 1;
        
        cout << "Dice " << i << " " << " is " << random_rumber << " " << endl;
     }
     
   }
};
int main(){
    Yatzy game;
    printMainMenu();
    game.dicerolling();
    return 0;
}