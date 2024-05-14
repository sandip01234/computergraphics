#include <stdio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int n, i, j, k, gd = DETECT, gm, dy, dx;
    int x, y, temp;
    int a[20][2], xi[20];
    float inslope[20];

    clrscr();
    printf("\n\n\t Enter the no. of edges of polygon : ");
    scanf("%d", &n);
    printf("\n\n\t Enter the co-ordinates of polygon :\n\n\n ");
    for (i = 0; i < n; i++)
    {
	printf("\t X%d Y%d : ", i, i);
	scanf("%d %d", &a[i][0], &a[i][1]);
    }
    a[n][0] = a[0][0];
    a[n][1] = a[0][1];

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    for (i = 0; i < n; i++)
    {
	line(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1]);
    }
    getch();

    for (i = 0; i < n; i++)
    {
	dy = a[i + 1][1] - a[i][1];
	dx = a[i + 1][0] - a[i][0];
	if (dy == 0)
	    inslope[i] = 1.0;
	else if (dx == 0)
	    inslope[i] = 0.0;
	else
	{
	    inslope[i] = (float)dx / dy;
	}
    }

    for (y = 0; y < 480; y++)
    {
	k = 0;
	for (i = 0; i < n; i++)
	{
	    if (((a[i][1] <= y) && (a[i + 1][1] > y)) || ((a[i][1] > y) && (a[i + 1][1] <= y)))
	    {
		xi[k] = (int)(a[i][0] + inslope[i] * (y - a[i][1]));
		k++;
	    }
	}
	for (j = 0; j < k - 1; j++)
	    for (i = 0; i < k - 1; i++)
	    {
		if (xi[i] > xi[i + 1])
		{
		    temp = xi[i];
		    xi[i] = xi[i + 1];
		    xi[i + 1] = temp;
		}
	    }
	setcolor(7);
	for (i = 0; i < k; i += 2)
	{
	    line(xi[i], y, xi[i + 1] + 1, y);
	    getch();
	}
    }
    closegraph();
}
//100 100
//200 100
//500 300
//300 400
//100 200