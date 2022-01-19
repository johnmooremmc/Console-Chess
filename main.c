#include <stdio.h>
#include <stdlib.h>

int Grid[9][9];
int dimension = 9;
int movefrom_x[64], movefrom_y[64];
int moveto_x[64], moveto_y[64];
int i, j, k, l, internal, black_pawn_moved[9], white_pawn_moved[9];
int white = 1;
int count;
int passthrough, Ychange, Xchange;

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
                printf("  BRook   |");
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
                printf("  WRook   |");
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
        printf("White's Turn,  4 Values: From(Column,Row) --> To(Column,Row),  Seperated by a spaces or lines:\n");
        scanf("%d %d %d %d", &movefrom_y[count], &movefrom_x[count], &moveto_y[count], &moveto_x[count]);
        verify();

    } else
    {
        printf("Black's Turn,  4 Values: From(Column,Row) --> To(Column,Row),  Seperated by a spaces or lines:\n");
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
    Ychange = abs(moveto_y[count]-movefrom_y[count]);
    Xchange = abs(moveto_x[count]-movefrom_x[count]);
    //Check in the negative direction required

    if (movefrom_y[count] == moveto_y[count] && movefrom_x[count] == moveto_x[count])
        {
            printf("\n||  Error!  ||\nnot moving\n");
        }

                           // Black
        else if(Grid[movefrom_y[count]][movefrom_x[count]] < 10 && white == 0)
        {
            if (Grid[moveto_y[count]][moveto_x[count]] > 10 || Grid[moveto_y[count]][moveto_x[count]] == 0)
            {
            if (Grid[movefrom_y[count]][movefrom_x[count]] == 1)
            {
                    //Rock
                if (moveto_x[count] == movefrom_x[count] || moveto_y[count] == movefrom_y[count])
                {
                    for (l=1; l<Ychange; l++)
                    {
                        if (moveto_y[count] - movefrom_y[count] > 0)
                        {
                            if (Grid[movefrom_y[count]+l][movefrom_x[count]] != 0)
                            {
                                passthrough = 1;
                            }
                        } else
                        {
                            if (Grid[movefrom_y[count]-l][movefrom_x[count]] != 0)
                            {
                                passthrough = 1;
                            }
                        }

                    }
                    for (l=1; l<Xchange; l++)
                    {
                        if (moveto_x[count] - movefrom_x[count] > 0)
                        {
                            if (Grid[movefrom_y[count]][movefrom_x[count]+l] != 0)
                            {
                                passthrough = 1;
                            }
                        } else
                        {
                            if (Grid[movefrom_y[count]][movefrom_x[count]-l] != 0)
                            {
                                passthrough = 1;
                            }
                        }
                    }
                    if (passthrough == 0)
                    {
                        move();
                    }
                    passthrough = 0;

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
                        for (l=1; l<=Ychange; l++)
                        {

                            if (Grid[movefrom_y[count]+l][movefrom_x[count]] != 0)
                            {
                                passthrough = 1;
                            }
                        }
                        if (passthrough == 0)
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
                        passthrough = 0;
                    }
                }
            }
        }
                        //White
        else if (Grid[movefrom_y[count]][movefrom_x[count]] > 10 && white == 1)
        {
            if (Grid[moveto_y[count]][moveto_x[count]] < 10 || Grid[moveto_y[count]][moveto_x[count]] == 0)
            {
               if (Grid[movefrom_y[count]][movefrom_x[count]] == 21)
                {
                    //Rock
                    for (l=1; l<Ychange; l++)
                    {
                        if (moveto_y[count] - movefrom_y[count] > 0)
                        {
                            if (Grid[movefrom_y[count]+l][movefrom_x[count]] != 0)
                            {
                                passthrough = 1;
                            }
                        } else
                        {
                            if (Grid[movefrom_y[count]-l][movefrom_x[count]] != 0)
                            {
                                passthrough = 1;
                            }
                        }

                    }
                    for (l=1; l<Xchange; l++)
                    {
                        if (moveto_x[count] - movefrom_x[count] > 0)
                        {
                            if (Grid[movefrom_y[count]][movefrom_x[count]+l] != 0)
                            {
                                passthrough = 1;
                            }
                        } else
                        {
                            if (Grid[movefrom_y[count]][movefrom_x[count]-l] != 0)
                            {
                                passthrough = 1;
                            }
                        }
                    }
                    if (passthrough == 0)
                    {
                        move();
                    }
                    passthrough = 0;

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
                            for (l=1; l<=Ychange; l++)
                            {
                                if (Grid[movefrom_y[count]-l][movefrom_x[count]] != 0)
                                {
                                    passthrough = 1;
                                }
                            }
                            if (passthrough == 0)
                            {
                                if (white_pawn_moved[movefrom_x[count]] == 0)
                                {
                                    if (moveto_y[count] == movefrom_y[count]-1 || moveto_y[count] == movefrom_y[count]-2)
                                    {
                                        white_pawn_moved[movefrom_x[count]] = 1;
                                        move();
                                    }
                                } else
                                {
                                    if (moveto_y[count] == movefrom_y[count]-1)
                                    {
                                        move();
                                    }
                                }
                            }
                            passthrough = 0;
                        }
                    }
                }
        } else
        {
            printf("\n\nSorry.. An unexpected Error Has Occurred\n\n");
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



// BUG!!! Names are wrong,  Rook spelt Rock in code
