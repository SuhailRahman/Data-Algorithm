#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>

struct Move{
    int row,col;
};

int max(int a, int b)
{
    return(a>b)?a:b;
}

int min(int a, int b)
{
    return(a<b)?a:b;
}

int MovesLeft(char board[3][3]) 
{ 
    for (int i = 0; i<3; i++) 
        for (int j = 0; j<3; j++) 
            if (board[i][j]=='_') 
                return 1; 
    return 0; 
} 

  int evaluate(char b[3][3]) 
{ 
    for (int row = 0; row<3; row++) 
    { 
        if (b[row][0]==b[row][1] && 
            b[row][1]==b[row][2]) 
        { 
            if (b[row][0]=='x') 
                return +10; 
            else if (b[row][0]=='o') 
                return -10; 
        } 
    } 
  
    for (int col = 0; col<3; col++) 
    { 
        if (b[0][col]==b[1][col] && 
            b[1][col]==b[2][col]) 
        { 
            if (b[0][col]=='x') 
                return +10; 
  
            else if (b[0][col]=='o') 
                return -10; 
        } 
    } 
  
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2]) 
    { 
        if (b[0][0]=='x') 
            return +10; 
        else if (b[0][0]=='o') 
            return -10; 
    } 
  
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0]) 
    { 
        if (b[0][2]=='x') 
            return +10; 
        else if (b[0][2]=='o') 
            return -10; 
    } 
  
    return 0; 
} 
  

int minimax(char board[3][3], int depth, int Max) 
{ 
    int score = evaluate(board); 
  

    if (score == 10) 
        return score; 
   
    if (score == -10) 
        return score; 
  
    if (MovesLeft(board)==0) 
        return 0; 
  
    // If this maximizer's move 
    if (Max) 
    { 
        int best = -1000;  
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                if (board[i][j]=='_') 
                { 
                    board[i][j] = 'x'; 
                    best = max( best, minimax(board, depth+1, !Max) ); 
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
  
    // minimizer's move 
    else
    { 
        int best = 1000; 
        for (int i = 0; i<3; i++) 
        { 
            for (int j = 0; j<3; j++) 
            { 
                if (board[i][j]=='_') 
                { 
                    board[i][j] = 'o'; 
                    best = min(best,  minimax(board, depth+1, !Max));
                    board[i][j] = '_'; 
                } 
            } 
        } 
        return best; 
    } 
} 

 struct Move findBestMove(char board[3][3])
{
    int bestVal=-1000;
    struct Move bestMove;
    bestMove.row=-1;
    bestMove.col=-1;
    for(int i=0;i<3;i++)
    { 
        for (int j = 0; j<3; j++) 
        {  
            if (board[i][j]=='_') 
            { 
                board[i][j] = 'x';
                int moveVal = minimax(board, 0,0); 
                board[i][j] = '_'; 
                  if (moveVal > bestVal) 
                { 
                    bestMove.row = i; 
                    bestMove.col = j; 
                    bestVal = moveVal; 
                } 
            } 
        } 
    } 
    printf("The value of the best Move is : %d\n", bestVal); 
    printf("The best Move is: %d %d\n", bestMove.row,bestMove.col); 
  
    return bestMove;  
}

void showInstructions() 
{ 
    printf("\t\t\t  Tic-Tac-Toe\n\n"); 
    printf("Choose a cell numbered from 1 to 9 as below"
            " and play\n\n"); 
      
    printf("\t\t\t  1 | 2  | 3  \n"); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  4 | 5  | 6  \n"); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  7 | 8  | 9  \n\n"); 
      
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n"); 
  
    return; 
} 

void showBoard(char board[3][3]) 
{ 
    printf("\n\n"); 
      
    printf("\t\t\t  %c | %c  | %c  \n", board[0][0], 
                             board[0][1], board[0][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n", board[1][0], 
                             board[1][1], board[1][2]); 
    printf("\t\t\t--------------\n"); 
    printf("\t\t\t  %c | %c  | %c  \n\n", board[2][0], 
                             board[2][1], board[2][2]); 
   
    return; 
} 

int main() 
{ 
    showInstructions();
    char board1[3][3] = 
    { 
        { '1', '2', '3' }, 
        { '4', '5', '6' }, 
        { '7', '8', '9' } 
    };
    showBoard(board1);
    char board[3][3] = 
    { 
        { '_', '_', '_' }, 
        { '_', '_', '_' }, 
        { '_', '_', '_' } 
    };
    int choice;
    int flag=1;
    while(flag==1)
    {
    scanf("%d",&choice);
    switch(choice){
    case 1: if(board[0][0] !='_')
                {
                    printf("Wrong input\n");
                    continue;
                }
                board[0][0]='o';
                break;
    case 2: if(board[0][1] !='_')
                {
                    printf("Wrong input\n");
                    continue;
                }
            board[0][1]='o';
            break;
    case 3: if(board[0][2] !='_')
            {
                    printf("Wrong input\n");
                    continue;
                }
        board[0][2]='o';
        break;      
    case 4: if(board[1][0] !='_')
                {
                    printf("Wrong input\n");
                    continue;
                }
            board[1][0]='o';
            break;
    case 5: if(board[1][1] !='_')
            {
                    printf("Wrong input\n");
                    continue;
                }
        board[1][1]='o';
        break;      
    case 6: if(board[1][2] !='_')
                {
                    printf("Wrong input\n");
                    continue;
                }
            board[1][2]='o';
            break;
    case 7: if(board[2][0] !='_')
            {
                    printf("Wrong input\n");
                    continue;
                }
        board[2][0]='o';
        break;      
    case 8: if(board[2][1] !='_')
                {
                    printf("Wrong input\n");
                    continue;
                }
            board[2][1]='o';
            break;
    case 9: if(board[2][2] !='_')
            {
                    printf("Wrong input\n");
                    continue;
                }
        board[2][2]='o';
        break;      
                }       
    showBoard(board);
   struct Move next;
   next=findBestMove(board); 
   board[next.row][next.col]='x';
   showBoard(board);
   int xy=evaluate(board);
   if(xy==10 || xy==-10)
       break;
   int x=MovesLeft(board);
    if(x==0)
    {
        flag=0;
    }
    }
    
    
    int x=evaluate(board);
    if (x == 10) 
        printf("COMPUTER has won\n"); 
    else if (x==-10)
        printf("HUMAN has won\n"); 
    else
        printf("DRAW");
   
    return 0; 
}