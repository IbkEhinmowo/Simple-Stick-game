#include <iostream>
#include <ctime>  // time()
#include <cstdlib>  // srand(), rand()
#include <string>  // std::string
using namespace std;  // std::cout

 int choice;



 


int getComputerNumber(){
   return rand() % 3 + 1;
}

int UserInput(){
    int userNumber;
    while (true) {
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> userNumber;
        if (userNumber == 1 || userNumber == 2 || userNumber == 3) {
            return userNumber;
        } else {
            cout << "Please input a valid number." << endl;
        }
    }
}
void displayRules(){
    cout << "The game starts with 20 sticks." << endl;
    cout << "Each player can take 1, 2, or 3 sticks." << endl;
    cout << "The player who takes the last stick loses." << endl;
}

void displayMenu(){

    cout << "Welcome to the Game!" << endl;
    cout << "  1.Play Game" << endl;
    cout << "  2.Show Rules" << endl;
    cout << "  3.Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
}
void PLAYGAME(){

int whoStarts = rand() % 2;  // 0 or 1
 int sticks = 20;

while (sticks>0){

    if (whoStarts == 0 ){
        cout <<" Computers Turn" << endl;
        int number = getComputerNumber();
        while (number > sticks){
            number = getComputerNumber();
        }
        
        cout << "Computer takes " << number << " sticks." << endl;
        sticks -= number; 
        cout << "Sticks left: " << sticks << endl;
        whoStarts = 1;
        
    }
    else{
        cout << "Your turn " << endl;
        int number = UserInput();
        while (number > sticks){
            cout << "Invalid number. Please try again." << endl;
            number = UserInput();
        }

        cout << "You take " << number << " sticks." << endl;
        sticks -= number;
        whoStarts =0;
        cout << "Sticks left: " << sticks << endl;
    }
    if (sticks == 0 && whoStarts == 0){
        cout << "You lose!" << endl;
    }
    else if (sticks == 0 && whoStarts == 1){ 
        cout << "You win!" << endl;

    }

}

}

void switchs(){

  switch (choice){
    case 1:
        cout << "Starting the game..." << endl;
        PLAYGAME();

        break;
    case 2:
        displayRules();
        displayMenu();
        break;
    case 3:
        cout << "Exiting the game. Goodbye!" << endl;
        break;

    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }

}

int main() {
srand(time(0));
    
 displayMenu();
switchs();


char playAgain;
cout<< "Dou you want to play again? (y/n)" << endl;
cin >> playAgain;

if (playAgain == 'y'|| playAgain == 'Y'){
    displayMenu();
    switchs();
    
}
else{
    cout << "Exiting the game. Goodbye!" << endl;
    return 0;
}

    return 0;
}