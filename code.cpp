#include<iostream>
using namespace std;

int currentPlayer;
char currentMarker;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" \n";
    cout<<"---|---|---\n";
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" \n";
    cout<<"---|---|---\n";
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" \n";
   

}
bool pleacemarker(int slot)
{
    int row=(slot-1)/3;
    int col=(slot-1)%3;

    if (board[row][col]!='X' && board[row][col]!='O')
    {
        board[row][col]=currentMarker;
        return true ;
    }
    else 
    {
        return false;
    }
}

int winner()
{
    // row
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1] == board[i][2])
        {
             return currentPlayer;
        }
    }
    //column
    for(int i=0;i<3;i++)
    {
        
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i])
        {
            return currentPlayer;
        }
    }
    // digonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return currentPlayer;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerandmarker()
{
    if(currentMarker=='X')
    {
        currentMarker='O';
    }
    else
    {
        currentMarker='X';
    }
    if(currentPlayer==1)
    {
        currentPlayer=2;
    }
    else
    {
        currentPlayer=1;
    }
}
void game ()
{
    cout<<"Player1 Choose your marker : X or O";
    char markerP1;
    cin>>markerP1;

    currentPlayer=1;
    currentMarker=markerP1;

    drawBoard();

    int Playerwon;

    for(int i=0;i<9;i++)
    {
        cout<<"its player"<<currentPlayer<<"'s turn Enter your slot:";
        int slot;
        cin>>slot;

        if(slot<1 || slot>9){
            cout<<"its in not valid slot , you try again";
            i--;
            continue ;
        }
        if(!pleacemarker(slot)){
            cout<<"slot accupied! try again\n";
            i--;
            continue;
        }

        drawBoard();

        Playerwon=winner();

        if(Playerwon==1)
        {
            cout<<"player 1 win";
            break;
        }
        if(Playerwon==2)
        {
            cout<<"player 2 win";
            break;
        }

        swapPlayerandmarker();

        if(Playerwon==0)
            cout<<"its a tie";
        
    }
}

int main()
{
    game();
    return 0;
}
