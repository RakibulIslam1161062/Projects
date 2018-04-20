#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(BLUE);

    bool q1,q2,q3,q4,q5,q6,q7,q8,q9;
    //outtextxy(150,150,"this a test");
    line(200,200,410,200);
    line(200,300,410,300);
    line(270,100,270,400);
    line(340,100,340,400);
    setcolor(RED);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    line(200,100,410,100);
    line(200,400,410,400);
    line(200,100,200,400);
    line(410,100,410,400);

    char arr[9];

    int counter=0;
    POINT c;
    outtextxy(20,20," O for Player 1 ");
    outtextxy(20,40," X for Player 2 ");
     settextstyle(BOLD_FONT,HORIZ_DIR,5);
   while(1){

            if(GetAsyncKeyState(VK_LBUTTON))
            {
                GetCursorPos(&c);
                    int x,y;
                    x=c.x;
                    y=c.y;


                    if(x>=200 && x<=270 && y>=100 && y<=200 && q1!=true)
                    {
                        counter++;

                        if(counter%2==0)
                        {
                            outtextxy(220,125,"X");
                            arr[0]='x';
                        }
                        else{
                            outtextxy(220,125,"O");
                            arr[0]='o';
                        }

                        q1=1;
                    }

                      else if(x>270 && x<=340 && y>=100 && y<=200 && q2!=true)
                             {
                                 counter++;

                        if(counter%2==0)
                        {
                            outtextxy(290,125,"X");
                            arr[1]='x';
                        }
                        else{
                            outtextxy(290,125,"O");
                            arr[1]='o';
                        }
                                q2=1;

                         }
                      else if(x>340 && x<=410 && y>=100&& y<=200 && q3!=true)
                             {
                                 counter++;

                        if(counter%2==0)
                        {
                            outtextxy(360,125,"X");
                            arr[2]='x';
                        }
                        else{
                            outtextxy(360,125,"O");
                            arr[2]='o';
                        }
                                q3=1;
                         }

                     else if(x>=200 && x<=270 && y>=200 && y<=300 && q4!=true)
                         {
                             counter++;

                        if(counter%2==0)
                        {
                            outtextxy(220,225,"X");
                            arr[3]='x';
                        }
                        else{
                            outtextxy(220,225,"O");
                            arr[3]='o';
                        }
                                q4=1;
                         }
                      else if(x>270 && x<=340 && y>=200 && y<=300  && q5!=true)
                             {
                                 counter++;

                        if(counter%2==0)
                        {
                            outtextxy(290,225,"X");
                            arr[4]='x';
                        }
                        else{
                            outtextxy(290,225,"O");
                            arr[4]='o';
                        }
                                q5=1;
                         }
                      else if(x>340 && x<=410 && y>=200&& y<=300 && q6!=true)
                           {
                               counter++;
                               if(counter%2==0)
                        {
                            outtextxy(360,225,"X");
                            arr[5]='x';
                        }
                        else{
                            outtextxy(360,225,"O");
                            arr[5]='o';
                        }
                                q6=1;
                         }

                           else if(x>=200 && x<=270 && y>=300 && y<=400 && q7!=true)
                          {
                              counter++;
                                if(counter%2==0)
                        {
                            outtextxy(220,325,"X");
                            arr[6]='x';
                        }
                        else{
                            outtextxy(220,325,"O");
                            arr[6]='o';
                        }
                                q7=1;
                         }

                      else if(x>270 && x<=340 && y>=300 && y<=400 && q8!=true)
                            {
                                counter++;
                             if(counter%2==0)
                        {
                            outtextxy(290,325,"X");
                            arr[7]='x';
                        }
                        else{
                            outtextxy(290,325,"O");
                            arr[7]='o';
                        }
                                q8=1;
                         }
                      else if(x>340 && x<=410 && y>=300&& y<=400 && q9!=true)
                             {
                                 counter++;
                               if(counter%2==0)
                        {
                            outtextxy(360,325,"X");
                            arr[8]='x';
                        }
                        else{
                            outtextxy(360,325,"O");
                            arr[8]='o';
                        }
                                q9=1;
                         }



                         if((arr[0]=='x' && arr[1]=='x' && arr[2]=='x')
                             ||  (arr[3]=='x' && arr[4]=='x' && arr[5]=='x')
                             ||  (arr[6]=='x' && arr[7]=='x' && arr[8]=='x')

                             ||  (arr[0]=='x' && arr[3]=='x' && arr[6]=='x')
                             ||  (arr[1]=='x' && arr[4]=='x' && arr[7]=='x')
                             ||  (arr[2]=='x' && arr[5]=='x' && arr[8]=='x')

                             ||  (arr[0]=='x' && arr[4]=='x' && arr[8]=='x')
                             ||  (arr[2]=='x' && arr[4]=='x' && arr[6]=='x'))

                         {
                             outtextxy(150,200,"Player 2 win");
                             break;
                         }

                          if((arr[0]=='o' && arr[1]=='o' && arr[2]=='o')
                             ||  (arr[3]=='o' && arr[4]=='o' && arr[5]=='o')
                             ||  (arr[6]=='o' && arr[7]=='o' && arr[8]=='o')

                             ||  (arr[0]=='o' && arr[3]=='o' && arr[6]=='o')
                             ||  (arr[1]=='o' && arr[4]=='o' && arr[7]=='o')
                             ||  (arr[2]=='o'&& arr[5]=='o' && arr[8]=='o')

                             ||  (arr[0]=='o' && arr[4]=='o' && arr[8]=='o')
                             ||  (arr[2]=='o' && arr[4]=='o'&& arr[6]=='o'))

                         {
                             outtextxy(150,200,"Player 1 win");
                             break;
                         }

                            delay(500);


                }
   }
    getch();
    closegraph();
}
