#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Hex.h"
using namespace std;



int main() {
    Hex hex;
    vector<char> tmp;
    string linia;
    while (getline(cin,linia)) {
        if (linia == "BOARD_SIZE") {
            hex.setBoard(tmp);
            cout << hex.getSize() << endl;
            tmp.clear();
            hex.clear();
        }
        else if (linia == "PAWNS_NUMBER") {
            hex.setBoard(tmp);
            cout << hex.getBlue() + hex.getRed() << endl;
            tmp.clear();
            hex.clear();
        }
        else if (linia == "IS_BOARD_CORRECT") {
            hex.setBoard(tmp);
            if (hex.isBoardCorrect()) {
                cout << "YES" << endl << endl;
            } else {
                cout << "NO" << endl << std::endl;
            }
            tmp.clear();
            hex.clear();
        }
        else if(linia == "IS_GAME_OVER") {
            hex.setBoard(tmp);
            if (hex.isBoardCorrect()) {
                if (hex.isGameOver('b')) {
                    cout << "YES BLUE" << endl << endl;
                } else if (hex.isGameOver('r')) {
                    cout << "YES RED" << endl << endl;
                } else {
                    cout << "NO" << endl << endl;
                }
            } else {
                cout << "NO" << endl << std::endl;
            }
            tmp.clear();
            hex.clear();
        }
        else if(linia == "IS_BOARD_POSSIBLE"){
            hex.setBoard(tmp);
            if(hex.isBoardPossible()){
                cout << "YES" << endl << endl;
            }
            else{
                cout << "NO" << endl<<endl;
            }
            tmp.clear();
            hex.clear();

        }
        else if(linia == "CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT"){
            hex.setBoard(tmp);
            if(hex.canColorWinInNmovesWithNaive(1,'r')){
                cout << "YES"<<endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if(linia == "CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT"){
            if(hex.canColorWinInNmovesWithNaive(1,'b')){
                cout << "YES"<<endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if(linia == "CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT"){
            if(hex.canColorWinInNmovesWithNaive(2,'r')){
                cout << "YES"<<endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else if(linia == "CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT") {
            if (hex.canColorWinInNmovesWithNaive(2, 'b')) {
                cout << "YES" << endl<<endl;
            }
            else{
                cout << "NO" << endl<<endl;
            }
            tmp.clear();
            hex.clear();
        }
        else {
            for(int i = 0; i<linia.size(); i++){
                if(linia[i] == '<') {
                    if(linia[i+2] == ' '){
                        tmp.push_back('0');
                    }
                    else
                        tmp.push_back(linia[i+2]);
                }


            }

        }


    }
    return 0;
}
