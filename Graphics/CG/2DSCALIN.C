#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float sx, sy;

    printf("\nEnter the starting point of the line segment (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the ending point of the line segment (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter scaling factors (sx, sy): ");
    scanf("%f %f", &sx, &sy);

    // Initialize graphics
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw original line
    setcolor(7);
    line(x1, y1, x2, y2);
    outtextxy(x2 + 5, y2, "Object");

    // Perform scaling
    x3 = (int)(x1 * sx);
    y3 = (int)(y1 * sy);
    x4 = (int)(x2 * sx);
    y4 = (int)(y2 * sy);

    // Draw scaled line
    setcolor(15);
    line(x3, y3, x4, y4);
    outtextxy(x4 + 5, y4, "Image");

    getch();
    closegraph();
    return 0;
}
//100 200
//200 200
//2 2