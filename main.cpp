#include<iostream>
#include<ctime>

void printIntroduction(int Difficulty){
    std::cout<<"Welcome to the game call : Guess the number "<<std::endl;
    std::cout<<"The rules are simple ; You will guess three number ; if you right you will advanced to the next the level "<<std::endl;
    std::cout<<"Let begin"<<std::endl;
    std::cout<<"Your level is "<<Difficulty<<std::endl;;
}

bool playGame(int Difficulty){

    printIntroduction(Difficulty);

   //init the number ;
        int RewardNum = 0 ;
        int Num1 = rand()%Difficulty + Difficulty  ;
        int Num2 = rand()%Difficulty + Difficulty  ;
        int Num3 = rand()%Difficulty + Difficulty  ;

    //the hints the player will guess 
    int Product = Num1 * Num2 * Num3;
    int Sum = Num1 + Num2 + Num3 ;

    //The game begin here 
    std::cout<<"You need to guess three number \n ";
    std::cout<<"First hints : The multiply of the three number is " << Product<<std::endl;
    std::cout<<"Second hints : The sum of the three number is : "<<Sum<<std::endl;
    std::cout<<"Your guess is "<<std::endl;

    // the number player will guess 
    int Guess1 ;
    int Guess2;
    int Guess3;
    std::cin>>Guess1>>Guess2>>Guess3;

    //Check if the number is correct 
    if((Guess1*Guess2*Guess3)== Product && (Guess1 + Guess2 + Guess3 == Sum)){
        std::cout<<"Your guess are right "<<std::endl;
        std::cout<<"You have been reward 1000$"<<std::endl;
        RewardNum += 1000;
        std::cout<<"Your total money are " << RewardNum<<std::endl;
        return true ; 
    }
    else {
        std::cout<<"You lose "<<std::endl;
        return false ;
    }



}
int main(){
    srand(time(NULL));
    int levelDifficulty = 1 ;
    int maxDifficulty = 10 ;
   
    
    while (levelDifficulty<=maxDifficulty  ) {
         bool isDone = playGame(levelDifficulty);
         std::cin.clear();
         std::cin.ignore();
    if(isDone == true){
        ++levelDifficulty;
    }
        }
    std::cout<<"Well done you have completed the game "<<std::endl;

     return 0;
}
