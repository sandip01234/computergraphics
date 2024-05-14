#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float a, t;

    printf("\nEnter the starting point of the line segment (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the ending point of the line segment (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the angle for rotation (degrees): ");
    scanf("%f", &a);

    // Convert angle to radians
    t = a * (3.14 / 180);

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setcolor(7);
    line(x1, y1, x2, y2);
    outtextxy(x2 + 5, y2, "Object");

    // Perform rotation
    x3 = (int)((x1 * cos(t)) - (y1 * sin(t)));
    y3 = (int)((x1 * sin(t)) + (y1 * cos(t)));
    x4 = (int)((x2 * cos(t)) - (y2 * sin(t)));
    y4 = (int)((x2 * sin(t)) + (y2 * cos(t)));

    setcolor(15);
    line(x3, y3, x4, y4);
    outtextxy(x4 + 5, y4, "Image");

    getch();
    closegraph();
    return 0;
}
//200 200
//250 200
//45