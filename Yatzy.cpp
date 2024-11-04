#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Yatzy
{
   public:
   void dicerolling(){
     srand(static_cast<unsigned int>(time(0)));
     for (int i = 0; i < 5; i++)
     {
        int random_rumber =rand() % 6 + 1;
        
        cout << "Roll " << i << " " << " is" << random_rumber << " " << endl;
     }
     
   }
};
int main(){
    Yatzy game;
    game.dicerolling();
    return 0;
}