#include <iostream>
#include <sstream>
#include <cstdlib>


class Board
{
    public:
        Board();
        std::string toString();
        bool makeMove(int player, int place);
        bool checkWin();
        void twoPlayerGame();
        void onePlayerGame();
        void newGame();

    private:
        std::string bd;
};

Board::Board()
{
    this->bd = "M         ";
}

std::string Board::toString()
{
    std::stringstream out;

    out << "\r" << "|" << bd[7] << "|" << bd[8] << "|" << bd[9] << "|" <<  "\n" << "|" << bd[4] << "|" << bd[5] << "|" << bd[6] << "|" <<  "\n" "|" << bd[1] << "|" << bd[2] << "|" << bd[3] << "|" <<  "\n";
    return out.str();
}

bool Board::makeMove(int player, int place)
{
    if(player == 1 && bd[place] == ' ')
        bd[place] = 'X';
    else if(player == 2 && bd[place] == ' ')
        bd[place] = 'O';
    else
        return false;

    std::cout << toString();

    return true;
}

bool Board::checkWin()
{
    if((bd[1] == 'X' && bd[2] == 'X' && bd[3] == 'X') ||
       (bd[4] == 'X' && bd[5] == 'X' && bd[6] == 'X') ||
       (bd[7] == 'X' && bd[8] == 'X' && bd[9] == 'X') ||
       (bd[7] == 'X' && bd[4] == 'X' && bd[1] == 'X') ||
       (bd[8] == 'X' && bd[5] == 'X' && bd[2] == 'X') ||
       (bd[9] == 'X' && bd[6] == 'X' && bd[3] == 'X') ||
       (bd[7] == 'X' && bd[5] == 'X' && bd[3] == 'X') ||
       (bd[9] == 'X' && bd[5] == 'X' && bd[1] == 'X'))
    {
        std::cout << "Player 1 wins. PLAY AGAIN (y/n) ?" << std::endl;
        std::string input;
        std::cin >> input;
        if(input == "y" || input == "Y")
            newGame();
        return true;
    }
    if((bd[1] == 'O' && bd[2] == 'O' && bd[3] == 'O') ||
       (bd[4] == 'O' && bd[5] == 'O' && bd[6] == 'O') ||
       (bd[7] == 'O' && bd[8] == 'O' && bd[9] == 'O') ||
       (bd[7] == 'O' && bd[4] == 'O' && bd[1] == 'O') ||
       (bd[8] == 'O' && bd[5] == 'O' && bd[2] == 'O') ||
       (bd[9] == 'O' && bd[6] == 'O' && bd[3] == 'O') ||
       (bd[7] == 'O' && bd[5] == 'O' && bd[3] == 'O') ||
       (bd[9] == 'O' && bd[5] == 'O' && bd[1] == 'O'))
    {
        std::cout << "Player 2 wins. PLAY AGAIN (y/n) ?" << std::endl;
        std::string input;
        std::cin >> input;
        if(input == "y" || input == "Y")
            newGame();
        return true;
    }
    return false;
}

void Board::onePlayerGame()
{
    for(int i = 1; i < 10; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            std::cout << "Player 1 (X), please type a move:";
            int input;
            if(!(std::cin >> input))
            {
                std::cout << "ERROR" << std::endl;
                return;
            }
            if(!makeMove(1,input))
                i--;
        }
        else
        {

            if(!makeMove(2, rand() % 9 + 1))
                i--;
        }

        if(checkWin())
            return;
    }
    std::cout << "Nobody won, PLAY AGAIN(y/n)?" << std::endl;
    std::string input;
    std::cin >> input;
    std::cout << input << std::endl;
    if(input == "y" || input == "Y")
        newGame();
    return;
}

void Board::twoPlayerGame()
{
    for(int i = 1; i < 10; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            std::cout << "Player 1 (X), please type a move:";
            int input;
            if(!(std::cin >> input))
            {
                std::cout << "ERROR" << std::endl;
                return;
            }
            if(!makeMove(1,input))
                i--;
        }
        else
        {
            std::cout << "Player 2 (O), please type a move:";
            int input;
            if(!(std::cin >> input))
            {
                std::cout << "ERROR" << std::endl;
                return;
            }
            if(!makeMove(2,input))
                i--;
        }

        if(checkWin())
            return;
    }
    std::cout << "Nobody won, PLAY AGAIN (y/n) ?" << std::endl;
    int input;
    if(!(std::cin >> input) && (input == 'y' || input == 'Y'))
        newGame();
    return;
}

void Board::newGame()
{
    this->bd = "M         ";
    std::cout << toString();

    std::cout << "1 or 2 players?" << std::endl;
    int playNum;
    std::cin >> playNum;

    if(playNum == 2)
        twoPlayerGame();
    else
        onePlayerGame();
    return;
}

int main(int argc, const char* argv[])
{
    Board * b = new Board();
    std::cout << b->toString();

    std::cout << "1 or 2 players?" << std::endl;
    int playNum;
    std::cin >> playNum;

    if(playNum == 2)
        b->twoPlayerGame();
    else
        b->onePlayerGame();
    return 0;
}
