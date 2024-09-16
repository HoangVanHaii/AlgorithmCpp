#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <thread>
#define RESET   "\033[0m"
#define BOLD_RED "\033[1;31m"
#define RED     "\033[31m" 
#define YELLOW  "\033[33m" 
#define MAGENTA "\033[35m" 
#define CYAN "\033[36m"
#define LIGHT_GREEN "\033[92m"
#define DARK_GREEN "\033[32m"
#define LIGHT_YELLOW "\033[93m"
#define DARK_YELLOW "\033[33m"
#define LIGHT_CYAN "\033[96m"
#define LIGHT_BLUE "\033[94m"
#define LIGHT_GREEN "\033[92m"
#define ORANGE "\033[38;5;208m"

using namespace std;

class Board {
    private:
        vector<char> cells;
    public:
        Board() { // Khoi tao bang tro choi
            cells.resize(9,' ');
            for(int i=0;i<9;i++) cells[i] = (char)(i+49);
        }
        void clear(){ // Khoi tao lai gia tri cho lan choi tiep theo
            for(int i=0;i<9;i++) cells[i] = (char)(i+49);
        }
        void display() { // In bang tro choi ra man  hinh
            cout << "\t ";
            if (cells[0] == 'X') cout << LIGHT_BLUE << cells[0] << RESET;
            else if (cells[0] == 'O') cout << LIGHT_GREEN << cells[0] << RESET;
            else cout << cells[0];
            cout << MAGENTA << " | " << RESET;
            if (cells[1] == 'X') cout << LIGHT_BLUE << cells[1] << RESET;
            else if (cells[1] == 'O') cout << LIGHT_GREEN << cells[1] << RESET;
            else cout << cells[1];
            cout << MAGENTA << " | " << RESET;
            if (cells[2] == 'X') cout << LIGHT_BLUE << cells[2] << RESET;
            else if (cells[2] == 'O') cout << LIGHT_GREEN << cells[2] << RESET;
            else cout << cells[2];
        
            cout << MAGENTA << "\n\t-----------\n" << RESET;
        
            cout << "\t ";
            if (cells[3] == 'X') cout << LIGHT_BLUE << cells[3] << RESET;
            else if (cells[3] == 'O') cout << LIGHT_GREEN << cells[3] << RESET;
            else cout << cells[3];
            cout << MAGENTA << " | " << RESET;
            if (cells[4] == 'X') cout << LIGHT_BLUE << cells[4] << RESET;
            else if (cells[4] == 'O') cout << LIGHT_GREEN << cells[4] << RESET;
            else cout << cells[4];
            cout << MAGENTA << " | " << RESET;
            if (cells[5] == 'X') cout << LIGHT_BLUE << cells[5] << RESET;
            else if (cells[5] == 'O') cout << LIGHT_GREEN << cells[5] << RESET;
            else cout << cells[5] ;
        
            cout << MAGENTA << "\n\t-----------\n" << RESET;
        
            cout << "\t ";
            if (cells[6] == 'X') cout << LIGHT_BLUE << cells[6] << RESET;
            else if (cells[6] == 'O') cout << LIGHT_GREEN << cells[6] << RESET;
            else cout << cells[6];
            cout << MAGENTA << " | " << RESET;
            if (cells[7] == 'X') cout << LIGHT_BLUE << cells[7] << RESET;
            else if (cells[7] == 'O') cout << LIGHT_GREEN << cells[7] << RESET;
            else cout << cells[7];
            cout << MAGENTA << " | " << RESET;
            if (cells[8] == 'X') cout << LIGHT_BLUE << cells[8] << RESET;
            else if (cells[8] == 'O') cout << LIGHT_GREEN << cells[8] << RESET;
            else cout << cells[8] ;
            cout << "\n";
        }
        bool checkWin(char symbol) { // Kiem tra xem da co nguoi thang hay chua
            for (int i = 0; i < 3; ++i) {
                if (cells[i * 3] == symbol && cells[i * 3 + 1] == symbol && cells[i * 3 + 2] == symbol) return true;
                if (cells[i] == symbol && cells[i + 3] == symbol && cells[i + 6] == symbol) return true;
            }
            if ((cells[0] == symbol && cells[4] == symbol && cells[8] == symbol) ||
                (cells[2] == symbol && cells[4] == symbol && cells[6] == symbol)) return true;
            return false;
        }
        bool isFull() { // Kiem tra xem bang da duoc dien het chua
            for (char cell : cells) if (cell>='1' && cell <='9') return false;
            return true;
        }
        bool updateCell(int cell, char symbol) { // Danh dau vao bang  
            if (cell < 0 || cell >= 9 || (cell<='1' && cell >='9')) return false;
            cells[cell] = symbol;
            return true;
        }
        void makeMove(int cell, char symbol) { 
            cells[cell]=symbol;
        }
        vector<int> available () { // Kiem tra nhung o nao chua duoc danh dau
            vector<int> moves;
            for (int i=0;i<9;i++) if (cells[i]>='1' && cells[i] <='9') moves.push_back(i);
            return moves;
        }
        bool check(int cell){
            return !(cells[cell]>='1' && cells[cell]<='9');
        }
        bool max_o(int cell){
            return (cell > 8 || cell < 0);
        }
};

class Player {
    private:
        char symbol;
    public:
        Player(char symbol) : symbol(symbol) {}
        char getSymbol() { return symbol; }
        virtual void getMove(Board& board) = 0;
};

class HumanPlayer : public Player {
    public:
        HumanPlayer(char _symbol) : Player(_symbol) {}
        void getMove(Board& board) {
            string move;
            int cnt=0,k=0;
            do {
                if (cnt!=0 && board.max_o(k)) cout << RED << "O khong hop le, vui long nhap lai: " << RESET << LIGHT_CYAN ;
                else if (cnt!=0) cout << RED << "O da duoc chon, vui long nhap lai: " << RESET << LIGHT_CYAN;
                if (cnt==0) cout << LIGHT_CYAN << "\nNhap Vi tri  (1 - 9): ";
                cnt++;
                cin >> move;
                cout << RESET;
                stringstream ss(move);
                ss >> k;k--;
            } while (k < 0 || k > 8 || board.check(k)); // Kiểm tra ô có hợp lệ và trống không
            board.updateCell(k, getSymbol());
        }
};

class ComputerPlayer : public Player {
    private:
        char opponentSymbol;
    public:
        ComputerPlayer(char _symbol) : Player(_symbol) {}
        void setSymbol(char c) { opponentSymbol = c; }
        int minimax(Board &board, bool maximizingPlayer, char selfSymbol, char opponentSymbol) { // Thuat toan minimax nham giup may tinh co the lua chon ra nuoc di hop ly nhat
            if (board.checkWin(selfSymbol)) return 1;
            else if (board.checkWin(opponentSymbol)) return -1;
            else if (board.isFull()) return 0;
            if (maximizingPlayer) {
                int bestScore = -2;
                vector<int> moves = board.available();
                for (int move:moves) {
                    board.makeMove(move, selfSymbol);
                    int score = minimax(board, false, selfSymbol, opponentSymbol);
                    board.makeMove(move, (char)(move+49));
                    bestScore = max(bestScore,score);
                }
                return bestScore;
            }
            else {
                int bestScore = 2;
                vector<int> moves = board.available();
                for (int move:moves) {
                    board.makeMove(move, opponentSymbol);
                    int score = minimax(board, true, selfSymbol, opponentSymbol);
                    board.makeMove(move, (char)(move+49));
                    bestScore = min(bestScore,score);
                }
                return bestScore;
            }
        }
        int getBestMove(Board& board, char selfsymbol, char opponentSymbol) { // Ra soat tat ca cac o de tim ra o uu nhat
            int bestMove, bestScore = INT_MIN;
            vector<int> moves = board.available();
            for (int move: moves) {
                board.makeMove(move, selfsymbol);
                int score = minimax(board, false, selfsymbol, opponentSymbol);
                board.makeMove(move, (char)(move+49));
                if (score > bestScore) bestScore = score, bestMove = move;
            }
            cout << LIGHT_CYAN << "Vi tri: "<< bestMove + 1 << endl << RESET;
            return bestMove;
        }
        void getMove(Board& board) { // Danh dau nuoc di da chon vao bang
            cout << endl;
            board.updateCell(getBestMove(board, getSymbol(), opponentSymbol), getSymbol());
        }
};

class Game {
    private:
        Board board;
        Player *player1;
        Player *player2;
        Player *currentPlayer;
    public:
        
        void play() {
            bool test = true;
            int k = 0;
            string n;
            char player1Symbol, player2Symbol, playerType1, playerType2; 
            if(test) {
                cout  << BOLD_RED << "\n CHAO MUNG DEN VOI TIC-TAC-TOE\n" << RESET;
                cout << DARK_YELLOW << " Chon loai tran dau : \n" << RESET;
                cout << LIGHT_YELLOW <<"\t[1] Nguoi VS Nguoi.\n\t[2] Nguoi VS May.\n\t[3] May VS May.\n" << RESET;
                cout << DARK_YELLOW<< " Nhap lua chon cua ban: "  << RESET;
                cout << LIGHT_YELLOW ;
            }
            do {
                try {
                    getline(cin, n);
                    for (int i=0;i<n.length();i++) if (n[i]==' ') n.erase(i,1),i--;
                    if ((n.size() != 1) || !(n[0]>='1' && n[0]<='3')) {
                        test = false;
                        throw invalid_argument(" Lua chon tran dau khong hop le!");
                    }
                    else k=(int)n[0]-48;
                } 
                catch (const exception& e) {
                    cerr << RED << " Loi: " << e.what() << endl << RESET;
                    cerr << DARK_YELLOW << " Vui long chon dung che do : " << RESET;
                    cerr << LIGHT_YELLOW ;
                    continue;
                }
                break; // Kết thúc vòng lặp khi đã chọn được giá trị hợp lệ
            } while (true);

            try {
                cout << DARK_YELLOW << " Chon bieu tuong cho Nguoi choi 1 (X hoac O): " << RESET;
                cout << LIGHT_YELLOW ;
                string a;
                while(getline(cin, a)){
                    for (int i=0;i<a.length();i++) if (a[i]==' ') a.erase(i,1),i--;
                    a[0] = toupper(a[0]);
                    player1Symbol = a[0];
                    cout << LIGHT_YELLOW ;
                    if (a == "X") {
                        cout << DARK_YELLOW << " Bieu tuong cua nguoi choi 2 se la "<< LIGHT_YELLOW << "O\n"<< RESET ;
                        player2Symbol = 'O';
                        break;
                    }
                    else if (a == "O"){
                        player2Symbol = 'X';
                        cout << DARK_YELLOW << " Bieu tuong cua nguoi choi 2 se la " << LIGHT_YELLOW << "X\n"<< RESET;
                        break; 
                    }
                    else {
                        cout << RED << " Bieu tuong nguoi choi 1 khong hop le!\n" << RESET;
                        cout << DARK_YELLOW<< " Vui long chon lai bieu tuong cho Nguoi choi 1 (X hoac O): " << RESET;
                        cout << LIGHT_YELLOW ;
                    }
                }
            } 
            catch (const exception& e) {
                cerr << RED << e.what() << endl;
                return;
            }
            bool vs=false;
            try {
                if (k == 1) {
                    HumanPlayer* hm1 = new HumanPlayer(player1Symbol);
                    HumanPlayer* hm2 = new HumanPlayer(player2Symbol);
                    player1 = hm1;
                    player2 = hm2;
                } 
                else if (k == 2) {
                    cout << DARK_YELLOW << " Chon loai nguoi choi cho Nguoi choi 1 (h: human, c: computer): " << RESET << LIGHT_YELLOW;
                    string b;
                    while(getline(cin , b)) {
                        for (int i=0;i<b.length();i++) if (b[i] == ' ') b.erase(i,1),i--;
                        b[0] = tolower(b[0]);
                        playerType1 = b[0];
                        if (b != "h" && b != "c") {
                            cout << RED << " Lua chon nguoi choi 1 khong hop le!" << RESET;
                            cout << DARK_YELLOW << "\n Vui long chon lai loai nguoi choi 1 (h: human, c: computer): " << RESET << LIGHT_YELLOW;
                        }
                        if (b == "h") {
                            HumanPlayer* hm = new HumanPlayer(player1Symbol);
                            ComputerPlayer* cp = new ComputerPlayer(player2Symbol);
                            cp -> setSymbol(player1Symbol);
                            player1 = hm;
                            player2 = cp;
                            break;
                        } 
                        else if (b == "c") {
                            HumanPlayer* hm = new HumanPlayer(player2Symbol);
                            ComputerPlayer* cp = new ComputerPlayer(player1Symbol);
                            cp -> setSymbol(player2Symbol);
                            player1 = cp;
                            player2 = hm;
                            break;
                        }
                    }
                    cout << RESET;
                } 
                else if (k == 3) {
                    ComputerPlayer* cp1 = new ComputerPlayer(player1Symbol);
                    ComputerPlayer* cp2 = new ComputerPlayer(player2Symbol);
                    cp1 -> setSymbol(player2Symbol);
                    cp2 -> setSymbol(player1Symbol);
                    player1 = cp1;
                    player2 = cp2;
                    vs=true;
                }
            } 
            catch (const exception& e) {
                cerr << RED << " Loi: " << e.what() << endl;
            }

            currentPlayer = player1;
            board.display();
            srand((int)time(0));
            if (k == 3) {
                int res = rand() % 9;
                board.updateCell(res, player1Symbol);
                cout << LIGHT_CYAN << " Nguoi choi " << currentPlayer->getSymbol() << ":";
                cout << "\n vi tri: " << res + 1 << endl << RESET;
                if (vs) this_thread::sleep_for(chrono::milliseconds(800));
                board.display();
                currentPlayer = player2;
            }
            while (!board.isFull()) {
                cout << LIGHT_CYAN << " Nguoi choi " << currentPlayer->getSymbol() << ": ";
                currentPlayer->getMove(board);
                if (vs) this_thread::sleep_for(chrono::milliseconds(800));
                board.display();
                if (board.checkWin(currentPlayer->getSymbol())) {
                    cout << RESET << BOLD_RED << " Chuc Mung! Nguoi choi " << currentPlayer->getSymbol() << " thang!\n" << RESET;
                    break;
                } 
                else if (board.isFull()) {
                    cout << BOLD_RED << " Hoa!\n" << RESET;
                    break;
                } 
                else switchPlayer();
            }
        }
        void start() {
            while (0==0)
            {
                system("cls");
                play();
                cout <<DARK_GREEN<< " Ban co muon choi lai khong (Y/N)? Nhap Y de choi lai hoac N de ket thuc: ";
                string c;
                cout << LIGHT_GREEN;
                while(getline(cin,c)) {
                    for (int i=0;i<c.length();i++) if (c[i] == ' ') c.erase(i,1),i--;
                    c[0] = toupper(c[0]);
                    cout << RESET;
                    if(c == "Y"){
                        board.clear();
                        cin.ignore();
                        break;
                    }
                    else if(c == "N"){
                        cout << ORANGE << "\n TRO CHOI DA KET THUC!\n" << RESET;
                        return;
                    }
                    else {
                        cout << RED<< " Vui long chon dung (Y/N): " << RESET;
                        cout << LIGHT_GREEN ;
                    }
                }
                
            }
        }
        void switchPlayer() {
            if (currentPlayer == player1) currentPlayer = player2;
            else currentPlayer = player1;
        }
};
int main()
{
    Game play;
    play.start();
}

