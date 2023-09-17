#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int count = 0;
int row_check(int array[3][3])
{
    int i, j, a, b, c;
    int flag = 0;
    for (i = 0; i < 3; i++)
    {
        j = 0;
        a = array[i][j];
        b = array[i][j + 1];
        c = array[i][j + 2];
        if (a == b && b == c && c == a && a == 1)
        {
            flag = 1;
            break;
        }
        else if (a == b && b == c && c == a && a == 2)
        {
            flag = 2;
            break;
        }
    }
    if (flag == 1)
    {
        return 1;
    }
    else if (flag == 2)
    {
        return 2;
    }
    else if (flag == 0)
    {
        return 0;
    }
}
int col_check(int array[3][3])
{
    int i, j, a, b, c;
    int flag = 0;
    for (i = 0; i < 3; i++)
    {
        j = 0;
        a = array[j][i];
        b = array[j + 1][i];
        c = array[j + 2][i];
        if (a == b && b == c && c == a && a == 1)
        {
            flag = 1;
            break;
        }
        else if (a == b && b == c && c == a && a == 2)
        {
            flag = 2;
            break;
        }

    }
    if (flag == 1)
    {
        return 1;
    }
    else if (flag == 2)
    {
        return 2;
    }
    else if (flag == 0)
    {
        return 0;
    }
}
int dia_check(int array[3][3])
{
    int a, b, c,d,e,f;
    int flag = 0;
    a = array[0][0];
    b = array[1][1];
    c = array[2][2];
    d=  array[0][2];
    e=  array[1][1];
    f=  array[2][0];


    if ((a == b && b == c && c == a && a == 1) ||(d == e && d == f && e == f && f == 1) )
    {
        flag = 1;
        return 1;
    }
    else if ((a == b && b == c && c == a && a == 2) ||(d == e && d == f && e == f && f == 2))
    {
        flag = 2;
        return 2;
    }
    else
    {
        return 0;
    }
}
void print_board(int array[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] == 0)
                cout << " ";
            else if (array[i][j] == 1)
                cout << "X";
            else
                cout << "O";

            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2)
            cout << "-----" << endl;
    }
}
int search_player1(int x, int player1[])
{
    int count = 0;
    for (int i = 1; i < 5; i++)
    {
        if (player1[i] == x)
            count++;
    }
    return count;
}
int search_player2(int x, int player2[])
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        if (player2[i] == x)
            count++;
    }
    return count;
}
void option(int player1[], int player2[])
{
    int total_option[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, k;
    for (k = 0; k < 9; k++)
    {
        int q = search_player1(total_option[k], player1);
        int p = search_player2(total_option[k], player2);
        if (p == 0 && q == 0)
            cout << " " << total_option[k];
    }
}
void insert_2d(int insert_board[3][3], int position, int value)
{
    int a = position;
    switch (a)
    {
    case 1:
        insert_board[0][0] = value;
        break;
    case 2:
        insert_board[0][1] = value;
        break;
    case 3:
        insert_board[0][2] = value;
        break;
    case 4:
        insert_board[1][0] = value;
        break;
    case 5:
        insert_board[1][1] = value;
        break;
    case 6:
        insert_board[1][2] = value;
        break;
    case 7:
        insert_board[2][0] = value;
        break;
    case 8:
        insert_board[2][1] = value;
        break;
    case 9:
        insert_board[2][2] = value;
        break;
    }
}
int computer_input(int player1[], int player2[]) {
  int total_option[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int possible[9] = {0};
  int i = 0,v=0;

  for (int k = 0; k < 9; k++) {
    int q = search_player1(total_option[k], player1);
    int p = search_player2(total_option[k], player2);
    if (p == 0 && q == 0) {
      possible[i] = total_option[k];
      i++;
    }
  }
  int x = 0;
  srand(time(0));
  x = ((rand() % i)); // Generate a random index within the range of populated elements

  if (x >= 0 && x < i) {
    int y = possible[x];
    // printf(" computer input may be %d", y);
    v=y;
  } else {
    printf("no input\n");
  }
  return v;
}
void rules()
{
    cout<<"Rule :"<<endl;
    cout<<"board is numbered in the following manner"<<endl;
     int count=1;
    for (int i = 0; i < 3; i++)
    {
        
        for (int j = 0; j < 3; j++)
        {
            cout<< count;
            if (j < 2)
            cout << "|";
            count++;
        }
        cout << endl;
        if (i < 2)
        cout << "-----" << endl;
        
    }

}
int main()
{
    int pos_1, pos_2, i, j, e = 0, board[3][3];
    int input;
    rules();
    cout<<"*****"<<endl;
    cout<<"1. player vs player"<<endl <<"2. player vs pc"<<endl;
    cout<<"enter option: "<<endl;
    cin>>input;

    for (int k = 0; k < 3; k++)
    {
        for (int s = 0; s < 3; s++)
        {
            board[k][s] = 0;
        }
    }
    int player1_option[] = {0, 0, 0, 0, 0};
    int player2_option[] = {0, 0, 0, 0};
    cout << "player-1" << endl;
    cout << "enter position:";
    cin >> pos_1;
    player1_option[0] = pos_1;
    insert_2d(board, pos_1, 1);
    print_board(board);
    if(input==2)
    {
      
       for (i = 1, j = 0; i < 5, j < 4; i++, j++)
    {
        cout << "player-2" << endl;
        cout << "available options are: \n";
        option(player1_option, player2_option);
        cout << "pc turn:" << endl;
        pos_2=computer_input(player1_option,player2_option);
        player2_option[j] = pos_2;
        insert_2d(board, pos_2, 2);

        print_board(board);
        if (row_check(board) == 2 || col_check(board) == 2 || dia_check(board) == 2)
        {
            cout << "Player 2 Wins" << endl;
            e++;
            break;
        }

        cout << "player-1" << endl;
        cout << "available options are:";
        option(player1_option, player2_option);
        cout << endl
             << "enter position:";
        cin >> pos_1;
        player1_option[i] = pos_1;
        insert_2d(board, pos_1, 1);

        print_board(board);
        if (row_check(board) == 1 || col_check(board) == 1 || dia_check(board) == 1)
        {
            cout << "Player 1 Wins" << endl;
            e++;
            break;
        }
    }
    if(e==0)
    cout<<"Draw!"<<endl;
    }
    else
    {
            for (i = 1, j = 0; i < 5, j < 4; i++, j++)
    {
        cout << "player-2" << endl;
        cout << "available options are: \n";
        option(player1_option, player2_option);
        cout << endl
             << "enter position:" << endl;
        cin >> pos_2;
        player2_option[j] = pos_2;
        insert_2d(board, pos_2, 2);

        print_board(board);
        if (row_check(board) == 2 || col_check(board) == 2 || dia_check(board) == 2)
        {
            cout << "Player 2 Wins" << endl;
            e++;
            break;
        }

        cout << "player-1" << endl;
        cout << "available options are:";
        option(player1_option, player2_option);
        cout << endl
             << "enter position:";
        cin >> pos_1;
        player1_option[i] = pos_1;
        insert_2d(board, pos_1, 1);

        print_board(board);
        if (row_check(board) == 1 || col_check(board) == 1 || dia_check(board) == 1)
        {
            cout << "Player 1 Wins" << endl;
            e++;
            break;
        }
    }
    if(e==0)
    cout<<"Draw!"<<endl;
    }

   
}
