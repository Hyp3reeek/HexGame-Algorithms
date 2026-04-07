#include "Hex.h"

Hex::Hex() : size(0), red(0), blue(0), board(nullptr), isVisited(nullptr) {}

Hex::~Hex() {
    clear();
}

void Hex::setSize(int s) {
    size = s;
}

void Hex::setRed(const std::vector<char>& pola) {
    for (char c : pola) {
        if (c == 'r') {
            red++;
        }
    }
}

void Hex::setBlue(const std::vector<char>& pola) {
    for (char c : pola) {
        if (c == 'b') {
            blue++;
        }
    }
}

void Hex::setBoard(std::vector<char> pola) {
    setSize(static_cast<int>(std::sqrt(pola.size())));
    setRed(pola);
    setBlue(pola);

    board = new char*[size];
    for (int i = 0; i < size; ++i) {
        board[i] = new char[size];
    }
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            board[i - j][j] = pola[k++];
        }
    }
    for (int i = size; i < size * 2 - 1; i++) {
        for (int j = i - size + 1; j < size; j++) {
            board[i - j][j] = pola[k++];
        }
    }
    createIsVisited();

}

void Hex::createIsVisited() {

    isVisited = new bool *[size];
    for (int i = 0; i < size; i++) {
        isVisited[i] = new bool[size];
    }
    setIsVisited();

}


void Hex::setIsVisited(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            isVisited[i][j] = false;
        }
    }
}


bool Hex::isBoardCorrect() const {
    return (red - 1 == blue || red == blue);
}

bool Hex::isGameOver(char color) {
    setIsVisited();
    if(color == 'b') {
        for (int i = 0; i < size; i++) {
            if (board[0][i] == 'b' && !isVisited[0][i]) {
                if (dfs(0, i, 'b')) {
                    return true;
                }
            }

        }
    }
    else if(color == 'r'){
        for (int i = 0; i < size; i++) {
            if (board[i][0] == 'r' && !isVisited[i][0]) {
                if (dfs(i, 0, 'r')) {
                    return true;
                }
            }

        }
    }
    return false;

}

bool Hex::dfs(int x, int y, char color) {
    if(x < 0 || x >= size || y < 0 || y >= size){
        return false;
    }
    if(board[x][y] != color || isVisited[x][y]){
        return false;
    }
    isVisited[x][y] = true;
    if ((color == 'r' && y == size - 1) || (color == 'b' && x == size - 1)) {
        return true;
    }
    int tab[6][2] = {{x,y-1},{x,y+1},{x-1,y},{x+1,y},{x-1,y-1},{x+1,y+1}};
    for(int i =0; i < 6;i++){
        if(dfs(tab[i][0],tab[i][1],color)){
            return true;

        }
    }
    return false;
}

bool Hex::doesAlwaysWin(char color) {
    for(int i =0; i<size;i++){
        for(int j =0; j<size;j++){
            if(board[i][j] == color){
                board[i][j] = '0';
                if(color=='r')
                    red--;
                else
                    blue--;
                if(!isGameOver(color)){
                    board[i][j] = color;
                    if(color=='r')
                        red++;
                    else
                        blue++;
                    return true;
                }
                board[i][j] = color;
                if(color=='r')
                    red++;
                else
                    blue++;
            }
        }
    }
    return false;

}

bool Hex::isBoardPossible() {
    if (isBoardCorrect()) {
        if (isGameOver('r')) {
            if(red - 1 == blue){
                if(doesAlwaysWin('r')){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else if (isGameOver('b')) {
            if(red == blue){
                if(doesAlwaysWin('b')){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        else {
            return true;
        }
    }
    return false;

}

bool Hex::canColorWinInNmovesWithNaive(int n, char color) {
    if(isBoardPossible()){
        if(!isGameOver('r')&&!isGameOver('b')){
            int freeslots =0;
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(board[i][j] == '0'){
                        freeslots++;
                    }
                }
            }
            if(n == 1){
                if(color == 'r'){
                    if(red==blue){
                        if(freeslots >= 1){
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'r';
                                        red++;
                                        if(isGameOver('r')){
                                            board[i][j] = '0';
                                            red--;
                                            return true;
                                        }
                                        board[i][j] = '0';
                                        red--;
                                    }
                                }
                            }
                            return false;
                        }
                        else{
                            return false;
                        }
                    }
                    else if(red-1==blue) {
                        if (freeslots >= 2) {
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'r';
                                        red++;
                                        if(isGameOver('r')){
                                            board[i][j] = '0';
                                            red--;
                                            return true;
                                        }
                                        board[i][j] = '0';
                                        red--;
                                    }
                                }
                            }
                            return false;
                        }
                    }
                    else {
                        return false;
                    }
                }

                else if(color == 'b'){
                    if(red==blue){
                        if(freeslots >= 2){
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'b';
                                        blue++;
                                        if(isGameOver('b')){
                                            board[i][j] = '0';
                                            blue--;
                                            return true;
                                        }
                                        board[i][j] = '0';
                                        blue--;
                                    }
                                }
                            }
                            return false;
                        }
                        else{
                            return false;
                        }
                    }
                    else if(red-1==blue) {
                        if (freeslots >= 1) {
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'b';
                                        blue++;
                                        if(isGameOver('b')){
                                            board[i][j] = '0';
                                            blue--;
                                            return true;
                                        }
                                        board[i][j] = '0';
                                        blue--;
                                    }
                                }
                            }
                            return false;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
            else if(n == 2){
                if(color == 'r'){
                    if(red==blue){
                        if(freeslots >= 3){
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'r';
                                        red++;
                                        if(!isGameOver('r')){
                                            for (int k = 0; k < size; k++) {
                                                for (int l = 0; l < size; l++) {
                                                    if(board[k][l] == '0') {
                                                        board[k][l] = 'r';
                                                        red++;
                                                        if (isGameOver('r')) {
                                                            board[i][j] = '0';
                                                            board[k][l] = '0';
                                                            red -= 2;
                                                            return true;
                                                        }
                                                        board[k][l] = '0';
                                                        red--;
                                                    }
                                                }
                                            }
                                            board[i][j] = '0';
                                            red--;
                                        } else {
                                            board[i][j] = '0';
                                            red--;
                                        }
                                    }
                                }
                            }
                            return false;
                        }
                        else{
                            return false;
                        }
                    }
                    else if(red-1==blue) {
                        if (freeslots >= 4) {
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'r';
                                        red++;
                                        if(!isGameOver('r')) {
                                            for (int k = 0; k < size; k++) {
                                                for (int l = 0; l < size; l++) {
                                                    if (board[k][l] == '0') {
                                                        board[k][l] = 'r';
                                                        red++;
                                                        if (isGameOver('r')) {
                                                            board[i][j] = '0';
                                                            board[k][l] = '0';
                                                            red -= 2;
                                                            return true;
                                                        }
                                                        board[k][l] = '0';
                                                        red--;
                                                    }
                                                }
                                            }
                                            board[i][j] = '0';
                                            red--;
                                        }
                                        else {
                                            board[i][j] = '0';
                                            red--;
                                        }
                                    }
                                }
                            }
                            return false;
                        }
                        else {
                            return false;
                        }
                    }
                }
                else if(color == 'b'){
                    if(red==blue){
                        if(freeslots >= 4){
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++) {
                                    if (board[i][j] == '0') {
                                        board[i][j] = 'b';
                                        blue++;
                                        if (!isGameOver('b')) {
                                            for (int k = 0; k < size; k++) {
                                                for (int l = 0; l < size; l++) {
                                                    if (board[k][l] == '0') {
                                                        board[k][l] = 'b';
                                                        blue++;
                                                        if (isGameOver('b')) {
                                                            board[i][j] = '0';
                                                            board[k][l] = '0';
                                                            blue -= 2;
                                                            return true;
                                                        }
                                                        board[k][l] = '0';
                                                        blue--;
                                                    }
                                                }
                                            }
                                            board[i][j] = '0';
                                            blue--;
                                        }
                                        else {
                                            board[i][j] = '0';
                                            blue--;
                                        }
                                    }
                                }
                            }
                            return false;
                        }
                        else{
                            return false;
                        }
                    }
                    else if(red-1==blue) {
                        if (freeslots >= 3) {
                            for(int i =0; i<size;i++){
                                for(int j =0; j<size;j++){
                                    if(board[i][j] == '0'){
                                        board[i][j] = 'b';
                                        blue++;
                                        if(!isGameOver('b')) {
                                            for (int k = 0; k < size; k++) {
                                                for (int l = 0; l < size; l++) {
                                                    if (board[k][l] == '0') {
                                                        board[k][l] = 'b';
                                                        blue++;
                                                        if (isGameOver('b')) {
                                                            board[i][j] = '0';
                                                            board[k][l] = '0';
                                                            blue -= 2;
                                                            return true;
                                                        }
                                                        board[k][l] = '0';
                                                        blue--;
                                                    }
                                                }
                                            }
                                            board[i][j] = '0';
                                            blue--;
                                        }
                                        else{
                                            board[i][j] = '0';
                                            blue--;
                                        }

                                    }
                                }
                            }

                            return false;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        else{
            return false;
        }
    }
    return false;

}

int Hex::getRed() const {
    return red;
}

int Hex::getBlue() const {
    return blue;
}

int Hex::getSize() const {
    return size;
}

void Hex::clear() {
    if (board != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] board[i];
        }
        delete[] board;
        board = nullptr;
    }

    if (isVisited != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] isVisited[i];
        }
        delete[] isVisited;
        isVisited = nullptr;
    }

    size = 0;
    red = 0;
    blue = 0;
}



