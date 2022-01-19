#include <stdio.h>
#include <stdlib.h>

int Grid[9][9];
int dimension = 9;
int movefrom_x[64], movefrom_y[64];
int moveto_x[64], moveto_y[64];
int i, j, k, internal, black_pawn_moved[9], white_pawn_moved[9];
int white = 1;
int count;

void setup()
{
    for (k=1; k<dimension;k++)
    {
        Grid[0][k] = k+10;
        Grid[k][0] = k+10;
    }

        // black
    Grid[1][1] = 1;
    Grid[1][8] = 1;

    Grid[1][2] = 2;
    Grid[1][7] = 2;

    Grid[1][3] = 3;
    Grid[1][6] = 3;

    Grid[1][4] = 4;

    Grid[1][5] = 5;

    for (k=1; k<dimension; k++)
    {
        Grid[2][k] = 6;
    }

        //white
    Grid[8][1] = 21;
    Grid[8][8] = 21;

    Grid[8][2] = 22;
    Grid[8][7] = 22;

    Grid[8][3] = 23;
    Grid[8][6] = 23;

    Grid[8][4] = 24;

    Grid[8][5] = 25;

    for (k=1; k<dimension; k++)
    {
        Grid[7][k] = 77;
    }
}

render()
{
    for (i=0; i<dimension; i++)
    {
        for (j=0; j<dimension; j++)
        {
            if (Grid[i][j] == 1)
            {
                printf("  BRock   |");
            } else if (Grid[i][j] == 2)
            {
                printf("  BHorse  |");
            } else if (Grid[i][j] == 3)
            {
                printf(" BBishop  |");
            } else if (Grid[i][j] == 4)
            {
                printf("  BQueen  |");
            } else if (Grid[i][j] == 5)
            {
                printf("   BKing  |");
            } else if (Grid[i][j] == 6)
            {
                printf("  BPawn   |");
            } else if (Grid[i][j] == 77)
            {
                printf("  WPawn   |");
            } else if (Grid[i][j] == 11)
            {
                printf("    1     |");
            } else if (Grid[i][j] == 12)
            {
                printf("    2     |");
            } else if (Grid[i][j] == 13)
            {
                printf("    3     |");
            } else if (Grid[i][j] == 14)
            {
                printf("    4     |");
            } else if (Grid[i][j] == 15)
            {
                printf("    5     |");
            } else if (Grid[i][j] == 16)
            {
                printf("    6     |");
            } else if (Grid[i][j] == 17)
            {
                printf("    7     |");
            } else if (Grid[i][j] == 18)
            {
                printf("    8     |");
            }

            else if (Grid[i][j] == 21)
            {
                printf("  WRock   |");
            } else if (Grid[i][j] == 22)
            {
                printf("  WHorse  |");
            } else if (Grid[i][j] == 23)
            {
                printf("  WBisop  |");
            } else if (Grid[i][j] == 24)
            {
                printf("  WQueen  |");
            } else if (Grid[i][j] == 25)
            {
                printf("   WKing  |");
            } else
            {
                printf("          |");
            }
        }
        printf("\n");
        for (k=0; k<dimension; k++)
        {
            printf(" --------- ");
        }
        printf("\n");
    }
}

turn()
{
    if (white)
    {
        printf("White's Turn,  Four Values, (Column,Row), seperated by a spaces:\n");
        scanf("%d %d %d %d", &movefrom_y[count], &movefrom_x[count], &moveto_y[count], &moveto_x[count]);
        verify();

    } else
    {
        printf("Black's Turn,  Four Values, (Column,Row), seperated by a spaces:\n");
        scanf("%d %d %d %d", &movefrom_y[count], &movefrom_x[count], &moveto_y[count], &moveto_x[count]);
        verify();
    }
}

move()
{
    Grid[moveto_y[count]][moveto_x[count]] = Grid[movefrom_y[count]][movefrom_x[count]];
    Grid[movefrom_y[count]][movefrom_x[count]] = 0;

    count++;

    if (white)
    {
        white = 0;
    } else
    {
        white = 1;
    }

    render();
}

verify()
{
    if (movefrom_y[count] == moveto_y[count] && movefrom_x[count] == moveto_x[count])
        {
            printf("\n||  Error!  ||\nnot moving\n");
        } else if(Grid[movefrom_y[count]][movefrom_x[count]] < 10 && white == 0)
        {

                // Black
            if (Grid[movefrom_y[count]][movefrom_x[count]] == 1)
            {
                    //Rock
                if (moveto_x[count] == movefrom_x[count] || moveto_y[count] == movefrom_y[count])
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 2)
            {
                    //Knight
                if (moveto_x[count] == movefrom_x[count]+1 && moveto_y[count] == movefrom_y[count]+2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-1 && moveto_y[count] == movefrom_y[count]+2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]+1 && moveto_y[count] == movefrom_y[count]-2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-1 && moveto_y[count] == movefrom_y[count]-2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]+2 && moveto_y[count] == movefrom_y[count]+1)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]+2 && moveto_y[count] == movefrom_y[count]-1)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-2 && moveto_y[count] == movefrom_y[count]+1)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-2 && moveto_y[count] == movefrom_y[count]-1)
                    {
                        move();
                    }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 3)
            {
                    //Bishop
                    if (moveto_y[count] == (movefrom_y[count]+moveto_x[count]-movefrom_x[count]) || moveto_y[count] == (movefrom_y[count]+abs(moveto_x[count]-movefrom_x[count])) || moveto_y[count] == (movefrom_y[count]+movefrom_x[count] - moveto_x[count]))
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 4)
            {
                    //Queen
                if (moveto_x[count] == movefrom_x[count] || moveto_y[count] == movefrom_y[count] || moveto_y[count] == (movefrom_y[count]+moveto_x[count]-movefrom_x[count]) || moveto_y[count] == (movefrom_y[count]+abs(moveto_x[count]-movefrom_x[count])) || moveto_y[count] == (movefrom_y[count]+movefrom_x[count] - moveto_x[count]))
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 5)
            {
                    //King
                if (moveto_y[count] == movefrom_y[count]-1 || moveto_x[count] == movefrom_x[count]-1 || moveto_y[count] == movefrom_y[count]+1
                    || moveto_x[count] == movefrom_x[count]+1)
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 6)
            {
                    // Pawn
                if (movefrom_x[count] == moveto_x[count])
                {
                    if (black_pawn_moved[movefrom_x[count]] == 0)
                    {
                        if (moveto_y[count] == movefrom_y[count]+1 || moveto_y[count] == movefrom_y[count]+2)
                        {
                            black_pawn_moved[movefrom_x[count]] = 1;
                            move();
                        }
                    } else
                    {
                        if (moveto_y[count] == movefrom_y[count]+1)
                        {
                            move();
                        }
                    }
                }
            }

            //White
        } else if (Grid[movefrom_y[count]][movefrom_x[count]] > 10 && white == 1)
        {
            if (Grid[movefrom_y[count]][movefrom_x[count]] == 21)
            {
                    //Rock
                if (moveto_x[count] == movefrom_x[count] || moveto_y[count] == movefrom_y[count])
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 22)
            {
                    //Knight
                if (moveto_x[count] == movefrom_x[count]+1 && moveto_y[count] == movefrom_y[count]+2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-1 && moveto_y[count] == movefrom_y[count]+2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]+1 && moveto_y[count] == movefrom_y[count]-2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-1 && moveto_y[count] == movefrom_y[count]-2)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]+2 && moveto_y[count] == movefrom_y[count]+1)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]+2 && moveto_y[count] == movefrom_y[count]-1)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-2 && moveto_y[count] == movefrom_y[count]+1)
                    {
                        move();
                    } else if (moveto_x[count] == movefrom_x[count]-2 && moveto_y[count] == movefrom_y[count]-1)
                    {
                        move();
                    }

            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 23)
            {
                    //Bishop
                if (moveto_y[count] == (movefrom_y[count]+moveto_x[count]-movefrom_x[count]) || moveto_y[count] == (movefrom_y[count]+abs(moveto_x[count]-movefrom_x[count])) || moveto_y[count] == (movefrom_y[count]+movefrom_x[count] - moveto_x[count]))
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 24)
            {
                    //Queen
                if (moveto_x[count] == movefrom_x[count] || moveto_y[count] == movefrom_y[count] || moveto_y[count] == (movefrom_y[count]+moveto_x[count]-movefrom_x[count]) || moveto_y[count] == (movefrom_y[count]+abs(moveto_x[count]-movefrom_x[count])) || moveto_y[count] == (movefrom_y[count]+movefrom_x[count] - moveto_x[count]))
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 25)
            {
                    //King
                if (moveto_y[count] == movefrom_y[count]-1 || moveto_x[count] == movefrom_x[count]-1 || moveto_y[count] == movefrom_y[count]+1
                    || moveto_x[count] == movefrom_x[count]+1)
                {
                    move();
                }
            } else if (Grid[movefrom_y[count]][movefrom_x[count]] == 77)
            {
                    // Pawn
                if (movefrom_x[count] == moveto_x[count])
                {
                    if (white_pawn_moved[movefrom_x[count]] == 0)
                    if (moveto_y[count] == movefrom_y[count]-1 || moveto_y[count] == movefrom_y[count]-2)
                    {
                        white_pawn_moved[movefrom_x[count]] = 1;
                        move();
                    } else if (moveto_y[count] == movefrom_y[count]-1)
                    {
                        move();
                    }
                }
            }
        }
}

int main()
{
    setup();
    render();

    //white to move
    for (internal=0; internal<100; internal++)
    {
        // Should have count only realise change after each player has played
        printf("\nTurn: %d\n", count+1);
        turn();
    }

    return 0;
}



// BUG!!! Names are wrong, WPawn is black, and BPawn is white
