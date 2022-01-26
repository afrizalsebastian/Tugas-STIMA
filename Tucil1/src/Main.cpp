#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>


#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define BLACK "\x1B[0m"

struct Alpha{ // To assign the color to letter
    char Alphabet;
    const char* color;
};

using namespace std;
using namespace std::chrono;

void displayPuzzle(vector<vector<Alpha>> puzzle, int row, int col){
    for(int i = 1; i<row+1; i++){
        for(int j = 0; j <  col; j++){
            cout << puzzle[i][j].color << puzzle[i][j].Alphabet << ' ';
        }
        cout << "\n";
    }
}

const char* generateColor(){
    const char* color[6] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN}; 
    int idx = rand()%6;
    return color[idx];
}

bool check2Right(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxY  + (int) word.size()) <= col){
        int y = idxY;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[idxX+1][y].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            y++;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int idx = idxY;
            for(int i = 0; i < wordSize; i++){
                puzzle[idxX+1][idx].color = color;
                idx++;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    }
}

bool check2Left(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxY + 1  - (int) word.size()) >= 0){
        int y = idxY;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[idxX+1][y].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            y--;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int idx = idxY;
            for(int i = 0; i < wordSize; i++){
                puzzle[idxX+1][idx].color = color;
                idx--;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

bool check2Down(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxX + (int) word.size()) <= row){
        int x = idxX+1;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[x][idxY].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            x++;
            idxWord++;
            if(idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int idx = idxX+1;
            for(int i = 0; i < wordSize; i++){
                puzzle[idx][idxY].color = color;
                idx++;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

bool check2Up(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxX + 1 - (int) word.size()) >= 0){
        int x = idxX+1;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[x][idxY].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            x--;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int idx = idxX+1;
            for(int i = 0; i < wordSize; i++){
                puzzle[idx][idxY].color = color;
                idx--;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

bool check2RightUp(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxX + 1 - (int) word.size()) >= 0 && (idxY  + (int) word.size()) <= col){
        int x = idxX+1;
        int y = idxY;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[x][y].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            x--;
            y++;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int tempx = idxX+1;
            int tempy = idxY;
            for(int i = 0; i < wordSize; i++){
                puzzle[tempx][tempy].color = color;
                tempx--;
                tempy++;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

bool check2RightDown(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxX + (int) word.size()) <= row && (idxY  + (int) word.size()) <= col){
        int x = idxX+1;
        int y = idxY;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[x][y].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            x++;
            y++;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int x = idxX+1;
            int y = idxY;
            for(int i = 0; i < wordSize; i++){
                puzzle[x][y].color = color;
                x++;
                y++;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

bool check2LeftDown(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxX + (int) word.size()) <= row && (idxY + 1  - (int) word.size()) >= 0){
        int x = idxX+1;
        int y = idxY;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[x][y].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            x++;
            y--;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int x = idxX+1;
            int y = idxY;
            for(int i = 0; i < wordSize; i++){
                puzzle[x][y].color = color;
                x++;
                y--;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

bool check2LeftUp(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp){
    if(!flag && (idxX + 1 - (int) word.size()) >= 0 && (idxY + 1  - (int) word.size()) >= 0){
        int x = idxX+1;
        int y = idxY;
        int idxWord = 0;
        int wordSize = word.size();
        bool found = false;
        while(puzzle[x][y].Alphabet == word[idxWord] && idxWord < wordSize && !found){
            comp++;
            x--;
            y--;
            idxWord++;
            if (idxWord == wordSize){
                found = true;
            }
        }
        const char* color = generateColor();
        if (found == true){
            int x = idxX+1;
            int y = idxY;
            for(int i = 0; i < wordSize; i++){
                puzzle[x][y].color = color;
                x--;
                y--;
            }
        }
        return found;
    }else if (flag == true){
        return true;
    }else{
        return false;
    } 
}

int main(int argc, char const *argv[])
{
    //To count the Row and Column of the puzzle
    string myText;
    string filename;

    cout << "Filename (in test Folder) : ";
    cin >> filename;
    ifstream MyReadFile("test\\" + filename);

    int row = 0;
    int col = 0;
    int word2Find = 0;
    cout << "\n***************** WORD SEARCH PUZZLE **********************\n\n";
    while (getline(MyReadFile, myText)){
        cout << myText << endl;
        if (myText[1] == ' '){
            row ++;
            int tempCol = 0;
            for (int j = 0; j < myText.length(); j++){
                if (myText[j] != ' '){
                tempCol++;  
                }
            }
            if (tempCol > col){
                col = tempCol;
            }
        }else{
            word2Find++;
        }
    }
    MyReadFile.close();

    //Initialization Matrtix
    vector<vector<Alpha>> puzzle (row+2, vector<Alpha>(col));
    std::vector<std::string> wordAcco {};

    string newText;
    ifstream newReadText("test\\" + filename);
    int idxRow = 1;
    int idxCol = 0;
    while(getline(newReadText, newText)){
        if(newText[1] == ' '){ //assign Puzzle to matriks 
            for(int i = 0; i < newText.length(); i++){
                if(newText[i] != ' '){
                    puzzle[idxRow][idxCol].Alphabet = newText[i];
                    puzzle[idxRow][idxCol].color = BLACK;
                    idxCol++;
                    if(idxCol == col){
                        idxCol = 0;
                        idxRow++;
                    }
                }
            }
        }else{ //assign Word to Array
            wordAcco.push_back(newText);
        }
    }

    //Upper-Bottom Padding
    for(int i = 0; i < col; i++){
        puzzle[0][i].Alphabet = '-';
        puzzle[row+1][i].Alphabet = '-';
    }
    newReadText.close();
    //Start Comparison
    auto start = high_resolution_clock::now();
    int countComp = 0; //Count comparison
    //Check the puzzle
    for(int k = 0; k < word2Find; k++){
        int i = 0;
        int j = 0;
        bool found = false;
        while(i < row && !found){
            while(j < col && !found){
                found = check2Right(puzzle, wordAcco[k], false, i, j, row,col, countComp);
                found = check2Left(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                found = check2Down(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                found = check2Up(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                found = check2RightUp(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                found = check2RightDown(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                found = check2LeftDown(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                found = check2LeftUp(puzzle, wordAcco[k], found, i, j, row, col, countComp);
                j++;
                if (j == col){
                    j = 0;
                    i++;
                }
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nTime taken: " << duration.count() << " microseconds" << endl;
    cout << "Number of letter Comparison : " << countComp << " times" << endl;
    cout << "\n===== RESULT : =====\n" << endl;
    displayPuzzle(puzzle, row, col);
    return 0;
}
