#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <conio.h>
#include <cstdlib>

using std::cout;
using std::cin;


void clear(){
    system("cls");
}


int Martha(){
    clear();
    cout << "You are in the Martha Menu\n";
    getch();
    return 0;
    
}

int Joe(){
    clear();
    cout << "You are in the Joe Menu\n";
    getch();
    return 0;
}

int Pepe(){
    clear();
    cout << "You are in the Pepe Menu\n";
    getch();
    return 0;
}

class grid{
    public:
        int gridX;
        int gridY;
        int playerX;
        int playerY;
        std::vector<int> previousPosition = {0,0};
        std::vector<std::vector <std::string>> positionList;
        std::vector<std::string> realGridX;
        grid(int gridX,int gridY, std::vector<int> startingPoints){
            playerX = startingPoints[0];
            playerY = startingPoints[1];

            for (int i = 0; i < gridX; i++){
                realGridX.push_back(".");
            }
            for (int i = 0; i < gridY; i++){
                positionList.push_back(realGridX);
            }
        }

        void printGrid(){
            for (int i = 0; i < positionList.size(); i++){
                for (int b = 0; b < positionList[0].size(); b++){
                    cout << positionList[i][b];
                }
                cout << "\n";
            }
        }
        void placeWord(std::string word, std::vector<int> wordPos){
            std::vector<int> blank;
            for (int i = 0; i < word.size(); i++){
                positionList[wordPos[1]][wordPos[0] + i] = word[i];
            }
        }

        void placePlayer(int x,int y, int called = 0 ){
            positionList[previousPosition[1]][previousPosition[0]] = ".";
            previousPosition[0] = x;
            previousPosition[1] = y;
            positionList[y][x] = "0";
        }

        void changePos(char key, std::string word = "false"){
            switch(key){
                case 'w':
                  if (playerY > 0){
                    playerY = playerY - 1;
                    placePlayer(playerX, playerY, 2);
                    break;}
                  else{break;}
                case 's':
                  if (playerY < positionList.size() - 1){
                    playerY = playerY + 1;
                    placePlayer(playerX,playerY);
                    break;}
                  else{break;}
                
                case 'a':
                  if (playerX > 0){  
                    playerX = playerX - 1;
                    placePlayer(playerX, playerY);
                    break;}
                  else{break;}
                case 'd':
                  if (playerX < positionList[0].size() - 1){
                  playerX = playerX + 1;
                  placePlayer(playerX, playerY);
                  break;
                  }
                  else{break;}
                case 'q':
                  exit(0);

                case 'e':
                  if (word == "Martha"){
                    Martha();
                    };
                  if (word == "Joe"){Joe();};
                  if (word == "Pepe"){Pepe();};
                  
                default:
                  break;
            };
          };
        };



void printWordsAndCoords(std::vector<std::string> wordList, std::vector<std::vector<int>> wordCoords){
    for (int i = 0; i < wordList.size(); i++){
        cout << "\n" << wordList[i] << " : (" << wordCoords[i][0] << ", " << wordCoords[i][1] << ")\n";
    }
}

std::string checkIfTouching(std::vector<std::string> wordList, std::vector<std::vector<int>> wordCoords, std::vector<int> cursorPos){
    for (int i = 0; i < wordCoords.size(); i++){
        if (cursorPos[1] == wordCoords[i][1]){
            if (cursorPos[0] == wordCoords[i][0]){
                return wordList[i];
            }
            else if (cursorPos[0] > wordCoords[i][0]){
                if (cursorPos[0] > (wordList[i].size() + wordCoords[i][0])){
                    continue;
                }
            else{
                    return wordList[i];
                }
            }
        }
        else{
            continue;
        }
    }
    return "false";
}


int mainLoop(){
    int gridX = 50;
    int gridY = 25;
    std::vector<int> startingPoint;
    startingPoint.push_back(gridX/2);
    startingPoint.push_back(gridY/2);
    std::string blank;

    grid position(gridX,gridY, startingPoint);

    std::vector<int> wordPos;

    
    std::vector <std::string> words = {"Joe", "Martha", "Pepe"};
    std::vector <std::vector <int>> wordPositions = {{47, 10}, {12,11}, {3,15}};

    for (int i = 0; i < words.size(); i++){
        position.placeWord(words[i], wordPositions[i]);
    }
    std::vector<int> playerPos = {position.playerX, position.playerY};
    while(1){
    
    
    std::clock_t start;
    start = std::clock();
    std::string wordTouching = checkIfTouching(words, wordPositions, playerPos);
    
    clear();
    for (int i = 0; i < words.size(); i++){
        position.placeWord(words[i], wordPositions[i]);
    }
    playerPos = {position.playerX, position.playerY};
    position.printGrid();
    char movement = getch();
    position.changePos(movement, wordTouching);
    double duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    cout << "Player Position : " << position.playerX << ", " << position.playerY; 
    cout << "\nObject gridX = " << position.positionList[0].size() << "\nObject gridY = " << position.positionList.size();
    cout << "\nTPS - " << duration;
    printWordsAndCoords(words, wordPositions);
    if (wordTouching != "false"){
        cout << "\nTouching " << wordTouching;
    }
    else{cout << "\nNot touching anything.";}

    }
    return 0;
}

int main(){
    mainLoop();
    return 0;
}