#include <stdio.h>
#include <stdlib.h>

int Grid[8][8];
int i, j, k;

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
    Grid[7][0] = 1;

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

int main()
{
    setup();
    render();


    return 0;
}


