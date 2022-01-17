#include <stdio.h>
#include <stdlib.h>

int Grid[9][9];
int dimension = 9;
int movefrom_x[64], movefrom_y[64];
int moveto_x[64], moveto_y[64];
int i, j, k, internal;
int white = 1;
int count;

void setup()
{
    for (k=1; k<dimension;k++)
    {
        Grid[0][k] = k;
        Grid[k][0] = k;
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
    Grid[8][1] = 1;
    Grid[8][8] = 1;

    Grid[8][2] = 2;
    Grid[8][7] = 2;

    Grid[8][3] = 3;
    Grid[8][6] = 3;

    Grid[8][4] = 4;

    Grid[8][5] = 5;

    for (k=1; k<dimension; k++)
    {
        Grid[7][k] = 7;
    }
}

render()
{
    for (i=0; i<dimension; i++)
    {
        for (j=0; j<dimension; j++)
        {
            printf("  %d  |", Grid[i][j]);
        }
        printf("\n");
        for (k=0; k<dimension; k++)
        {
            printf(" ---- ");
        }
        printf("\n");
    }
}

turn()
{
    if (white)
    {
        //bug running scanf twice for movefrom
        // bug Also, scanf line moveto_y  runs beforeactivating piece
        printf("White's Turn,  Pick (Column,Row), seperated by a spaces / lines:\n");
        scanf("%d\n", &movefrom_y[count]);
        scanf("%d\n", &movefrom_x[count]);

        //printf("Activating Piece: (%d,%d)\n", movefrom_y[count], movefrom_x[count]);
        scanf("%d\n", &moveto_y[count]);
        scanf("%d\n", &moveto_x[count]);
        //printf("Moving Piece To: (%d,%d)\n", moveto_y[count], moveto_x[count]);

        verify();

    } else
    {
        printf("Black's Turn,  Pick (Column,Row), seperated by a spaces / lines:\n");
        scanf("%d\n", &movefrom_y[count]);
        scanf("%d\n", &movefrom_x[count]);

        scanf("%d\n", &moveto_x[count]);
        scanf("%d\n", &moveto_y[count]);

        verify();
    }
}

move()
{
//    printf("(%d,%d)", movefrom_y[count], movefrom_x[count]);
//    printf("(%d,%d)", moveto_y[count], moveto_x[count]);

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
        } else
        {
            if (Grid[movefrom_y[count]][movefrom_x[count]] == 6)
            {
                if (movefrom_x[count] == moveto_x[count])
                {
                    if (moveto_y[count] == movefrom_y[count]+1 || moveto_y[count] == movefrom_y[count]+2)
                    {
                        move();
                    }
                }
            } else
            {
                if (Grid[movefrom_y[count]][movefrom_x[count]] == 7)
                {
                    if (moveto_y[count] == movefrom_y[count]-1 || moveto_y[count] == movefrom_y[count]-2)
                    {
                        move();
                    }
                } else
                {
                    move();
                }
            }
        }

}

int main()
{
    setup();
    render();

    //white to move
    for (internal=0; internal<4; internal++)
    {
        //Should +1 to count
        printf("\nTurn: %d\n", count);
        turn();
    }

    return 0;
}
