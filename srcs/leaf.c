#include <stdio.h>
#include <math.h>
#include <graphics.h>

int a;

void drawfern(int x, int y, int l, int arg, int n)
{
	int x1, y1, i;
	int l1, xpt, ypt;

	if (n > 0 && !kbhit())
	{
		x1 = (int)(x - l * sin(arg * 3.14 / 180));
		y1 = (int)(y - l * cos(arg * 3.14 / 180));
		line(x, y, x1, y1);
		l1 = (int)(l / 5);
		for (i = 1; i < 6; i++)
		{
			xpt = (int)(x - i * l1 * sin(arg * 3.14 / 180));
			ypt = (int)(y - i * l1 * cos(arg * 3.14 / 180));
			drawfern(xpt, ypt, (int)(l / (i + 1)), arg + a, n - 1);
			drawfern(xpt, ypt, (int)(l / (i + 1)), arg - a, n - 1);
		}
	}
}

void main()
{
	int gd = DETECT, gm, x, y, l;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI\\");
	x = getmaxx() / 2;
	y = getmaxy() / 2;
	l = 150;
	a = 45;
	setcolor(YELLOW);
	drawfern(x, y, l, 0, 5);
	getch();
}