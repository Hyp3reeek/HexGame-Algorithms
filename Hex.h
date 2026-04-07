#ifndef HEX_H
#define HEX_H

#include <vector>
#include <cmath>

class Hex {
private:
    int size;
    int red;
    int blue;
    char** board;
    bool** isVisited;

    void setSize(int s);
    void setRed(const std::vector<char>& pola);
    void setBlue(const std::vector<char>& pola);
    void createIsVisited();
    void setIsVisited();
    bool dfs(int x, int y, char color);

    bool doesAlwaysWin(char color);

public:
    Hex();
    ~Hex();
    void setBoard(std::vector<char> pola);
    bool isBoardCorrect() const;
    bool isBoardPossible();
    bool canColorWinInNmovesWithNaive(int n, char color);
    int getRed() const;
    int getBlue() const;
    int getSize() const;
    void clear();

    bool isGameOver(char color);
};

#endif // HEX_H
