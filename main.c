#include <stdio.h>
#include <stdlib.h>

int Grid[8][8];
int movefrom_x[64], movefrom_y[64];
int moveto_x[64], moveto_y[64];
int i, j, k;
int white = 1;
int count;

void setup()
{
        // black
    Grid[0][0] = 1;
    Grid[0][7] = 1;

    Grid[0][1] = 2;
    Grid[0][6] = 2;

    Grid[0][2] = 3;
    Grid[0][5] = 3;

    Grid[0][3] = 4;

    Grid[0][4] = 5;

    for (k=0; k<8; k++)
    {
        Grid[1][k] = 6;
    }

        //white
    Grid[7][0] = 1;
    Grid[7][7] = 1;

    Grid[7][1] = 2;
    Grid[7][6] = 2;

    Grid[7][2] = 3;
    Grid[7][5] = 3;

    Grid[7][3] = 4;

    Grid[7][4] = 5;

    for (k=0; k<8; k++)
    {
        Grid[6][k] = 6;
    }
}

render()
{
    for (i=0; i<8; i++)
    {
        for (j=0; j<8; j++)
        {
            printf("  %d  |", Grid[i][j]);
        }
        printf("\n");
        for (k=0; k<8; k++)
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
        printf("Whites Turn,  Pick (Column,Row), seperated by a line:\n");
        scanf("%d\n", &movefrom_y[count]);
        scanf("%d\n", &movefrom_x[count]);

        //printf("Activating Piece: (%d,%d)\n", movefrom_y[count], movefrom_x[count]);

        //printf("Moving To: ");
        scanf("%d\n", &moveto_y[count]);
        scanf("%d\n", &moveto_x[count]);
        //printf("Moving Piece To: (%d,%d)\n", moveto_y[count], moveto_x[count]);

        if (movefrom_y[count] == moveto_y[count] && movefrom_x[count] == moveto_x[count])
        {
            printf("\n||  Error!  ||\nnot moving\n");
        } else
        {
            move();
        }


        white = 0;
    } else
    {

        white = 1;
    }
    count++;
}

move()
{
//    printf("(%d,%d)", movefrom_y[count], movefrom_x[count]);
//    printf("(%d,%d)", moveto_y[count], moveto_x[count]);

    Grid[moveto_y[count]-1][moveto_x[count]-1] = Grid[movefrom_y[count]-1][movefrom_x[count]-1];
    Grid[movefrom_y[count]-1][movefrom_x[count]-1] = 0;

    render();
}

int main()
{
    setup();
    render();

    //white to move
    turn();
    printf("\nTurn: %d\n", count);


    return 0;
}


