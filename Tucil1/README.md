IF 2211 Strategi Algoritma

Penyelesaian Word Search Puzzle dengan Algoritma Brute Force

Deskripsi Singkat Source Code
Source Code terdiri dari satu file yaitu Main.cpp. Pada Main.cpp terdapat main program dan juga beberapa fungsi dan prosedur dan sebuah Struc.
Struc tediri dari char Alphabet untuk menampung huruf dan const char* color untuk menampung warna yang akan diberikan nantinya dengan nama Struct Alpha.
Terdapat beberapa fungsi dan prosedur, yaitu :
1. void displayPuzzle(vector<vector<Alpha>> puzzle, int row, int col), untuk menampilkan puzzle ke layar.
2. const char* generateColor(), untuk memilih warna yang ada.
3. bool check2Right(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memerika kata ke kanan dan mengembalikan boolean true, jika kata ditemukan.
4. bool check2Left(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memeriksa kata ke kiri dan mengembalikan boolean true, jika kata ditemukan.
5. bool check2Down(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memerika kata ke bawah dan mengembalikan boolean true, jika kata ditemukan.
6. bool check2Up(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memerika kata ke atas dan mengembalikan boolean true, jika kata ditemukan.
7. bool check2RightUp(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memerika kata ke kanan-atas dan mengembalikan boolean true, jika kata ditemukan.
8. bool check2RightDown(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memerika kata ke kanan-bawah dan mengembalikan boolean true, jika kata ditemukan.
9. bool check2LeftDown(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp), memerika kata ke kiri-bawah dan mengembalikan boolean true, jika kata ditemukan.
10. bool check2LeftUp(vector<vector<Alpha>> &puzzle, string word, bool flag, int idxX, int idxY, int row, int col, int &comp),  memerika kata ke kiri-atas dan mengembalikan boolean true, jika kata ditemukan.
Serta ada main program yang melakukan pembacaan file dan menge-assign puzzle ke matrix yang berupa vector 2D dari Alpha.

Program Telah di-Complie dan ada di Folder bin, cara menjalankan:
  1. Open Folder Tucil dengan VSCode.
  2. Buka CMD pada VSCode (untuk mendukung pewarnaan puzzle).
  3. Jalankan program dengan Command "bin\Main" ==> ..\Tucil1>bin\Main
  4. Masukkan nama file dengan extension .txt
  
Jika ingin melakukan Complie ulang :
  1. Open Folder Tucil dengan VSCode.
  2. Buka CMD pada VSCode (untuk mendukung pewarnaan puzzle).
  3. Jalankan Command "g++ -std=c++17 .\src\Main.cpp -o .\bin\Main.exe" ==> ..Tucil1>g++ -std=c++17 .\src\Main.cpp -o .\bin\Main.exe
  4. Lalu dapat dilanjutkan seperti langkah diatas "Program Telah di-Complie dan ada di Folder bin"
  
  
Afrizal Sebastian
13520120
Strategi Algoritma - KO3
  
