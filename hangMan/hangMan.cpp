#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <ctime>


using std::cout;
using std::cin;



void clear(){
    system("cls");
}

void wait(){
    std::string something;
    cout << "\n>>> ";
    getline(cin,something);
    cout << "\n";
}

std::string input(){
    std::string something;
    cout << "\n>>> ";
    getline(cin,something);
    cout << "\n";
    return something;
}
int randomInt(int minimum, int maximum){
    srand ((unsigned) time(0));
    int choice = rand() % maximum;

    return choice;
}

std::string wordChooser(){
    std::string word;
    std::vector<std::string> words;

    std::fstream file;

    file.open("words/wordlist.txt", std::ios::in);

    while (getline(file, word)){
        words.push_back(word);
    }
    int maximum = words.size();
    int index = randomInt(0, maximum);
    return words[index];
}

std::string wordChooserCustom(std::vector<std::string> words){
    int maximum = words.size();
    int index = randomInt(0, maximum);

    return words[index];
}

void knownPrinter(std::string known, std::string word){
    for (int i = 0; i < word.size(); i++){
        for (int b = 0; b < known.size(); b++){
            if (known[b] == word[i]){
                cout << " " << known[b];
                break;
            }
            else if (known[b] != word[i] && b == known.size() - 1){
                cout << " _";
            }
        }
    }
}


bool winGame(std::string word, std::string known){
    int counter = 0;
    for (int b = 0; b < word.size(); b++){
        for (int i = 0; i < known.size(); i++){
            if (known[i] == word[b]){
                counter = counter + 1;
                break;
            }
            else{continue;
            }
        }
    }
    if (counter == word.size()){
        return true;
    }
    else{return false;}
}



bool letterFound(std::string guess, std::string word){
    for (int i = 0; i < word.size(); i++){
        if (guess[0] == word[i]){
            return true;
        }
    }
    return false;
}



int mainLoop(){
    std::vector<std::string> congratsWords = {"Oh! Nice guess! Or estimation. I know you're smarter than just guesses."
    , "Nice, nice. Do as good next time.", "Hey man, keep it up.", "Don't get cocky now.", "Don't let your ego hinder this progress",
    "If I was keeping score, you'd be off the charts.", "Ooh, nice one."};
    std::vector<std::string> lossWords = {"Better luck next time.", "Come on, try again. Spite me.",
    "Almost got it...", "Oh.. Quick tip, if you choose the right letter, it's easier to win the game.", "Careful sir/Ma'm (Since gender neutrality is a thing now... for some reason)."};  
    std::vector<std::string> deathWords = {"Oh. Sorry my guy.", "Really? A game where you can choose how many turns you get and you still loose? Unbelievable...",
    "Wow. Died playing hangman.", "Play again? Maybe?", "Work harder.", "Get a life dude."};
    std::vector<std::string> winWords = {"nice.", "Never get a life. Just stay here and play this game.", "Thanks. Play again?",
    "Hey. Get a job in literature for me.","Was it fun? I hope it was...", "Hope you liked it..."};

    std::string word = wordChooser();

    std::string missed = "";

    std::string known = "";

    int fullTurns;
    cout << "How many turns would you like to have?\n>>> ";
    int turns;
    cin >> turns;
    wait();
    clear();

    // starts loop

    while (turns > 0){
        clear();
        fullTurns = fullTurns + 1;

        // check if you have won - Where I screwed up last time.
        if (winGame(word, known)){
            clear();
            cout << "(You Won!)";
            cout << "The word was " << word;
            cout <<"\n" << wordChooserCustom(winWords);
            wait();
            return 0;
        }
        cout << turns << " turn/s left\n";
        cout << "\nKnown : \n";
        knownPrinter(known, word);
        cout << "\nMissed : \n" << missed << "\n";
        cout << "\nplease input your guess.";
        std::string guess = input();

        if (letterFound(guess, word)){
            clear();
            cout << "(You got it right!)\n";
            cout << wordChooserCustom(congratsWords);
            known = known + guess[0];
            wait();
        }
        else if (letterFound(guess, word) != true && turns - 1 != 0){
            clear();
            cout << "(You got it wrong...)\n";
            cout << wordChooserCustom(lossWords);
            wait();
            turns = turns - 1;
            missed = missed + guess[0];
            continue;
        }
        else{
            clear();
            cout << "The word was "<< word << "\n";cout << "Wow. you died.\n";
            cout << wordChooserCustom(deathWords);
            wait();
            return 0;
        }


    }
    return 0;
}

int main(){
    mainLoop();

}
