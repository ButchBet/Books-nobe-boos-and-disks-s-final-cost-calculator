#include<stdio.h>

#include<conio.h>

#include <graphics.h>

#include<string.h>

#include<dos.h>

int main() {

 /* request auto detection */

 int gdriver = DETECT, gmode, err;

 int i, j, k, x, y, color;

 char str[64];



 /* initialize graphic mode */

 initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");

  err = graphresult();



    if (err != grOk) {

    /* error occurred */

  printf("Graphics Error: %s\n",

                            grapherrormsg(err));

      return 0;

    }



    for (i = 0; i < 3; i++) {

    /* clears graphic screen */

      cleardevice();



       /* draw the signal post */

        setcolor(DARKGRAY);

        setfillstyle(SOLID_FILL, DARKGRAY);

        rectangle(50, 45, 150, 300);

        rectangle(90, 300, 110, getmaxy());

        floodfill(55, 55, DARKGRAY);

        floodfill(91, 301, DARKGRAY);



      /* make place for signals */

       setcolor(BLACK);

       setfillstyle(SOLID_FILL, BLACK);

       circle(100, 90, 30);

       floodfill(100, 90, BLACK);

       circle(100, 170, 30);

       floodfill(100, 170, BLACK);

       circle(100, 250, 30);

       floodfill(100, 250, BLACK);

       x = 150 + (getmaxx() - 150) / 2;

       y = 125;

         moveto(x, y);

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);

      settextjustify(CENTER_TEXT, CENTER_TEXT);



            /* signal for stop */

            if (i == 0) {

                    setcolor(LIGHTRED);

                    outtext("STOP");

                    color = LIGHTRED;

                    y = 90;

            }
             else if (i == 1) {

           /* yellow signal - to get ready */

                setcolor(YELLOW);

                outtext("READY");

                color = YELLOW;

                y = 170;

            } 
             else {

          /* green signal - to start */

                setcolor(GREEN);

                outtext("START");

                color = GREEN;

                 y = 250;

            }



            x = 100;



  /* for red & green timer is 10 seconds */

            if (color != YELLOW) {

                    k = 10;

            } else {

  /* timer is 5 sec for yellow signal */

                    k = 5;

            }



            for (j = k; j > 0; j--) {
    /* clear the signal-to rewrite timer */

            setcolor(BLACK);

            setfillstyle(SOLID_FILL, BLACK);

            circle(x, y, 30);

            floodfill(x, y + 25, BLACK);



   /* turn on the given signal(color) */

             setcolor(color);

             setfillstyle(SOLID_FILL, color);

             circle(x, y, 30);

             floodfill(x, y + 25, color);



      /* print the counter inside signal */

      setcolor(BLACK);

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);

      sprintf(str, "%d", j);

      moveto(x, y);

      outtext(str);

        sleep(1);

            }

    }



    cleardevice();

    getch();



    /* deallocate memory allocated for graphic screen */

    closegraph();

    return 0;
}