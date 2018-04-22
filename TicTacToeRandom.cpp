#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void coordinate(int n,int &X,int &Y)
{
    if(n==0) { X=220;Y=125;}
    else if(n==1) { X=290;Y=125;}
    else if(n==2) { X=360;Y=125;}
    else if(n==3) { X=220;Y=225;}
    else if(n==4) { X=290;Y=225;}
   else  if(n==5) { X=360;Y=225;}
   else  if(n==6) { X=220;Y=325;}
   else if(n==7) { X=290;Y=325;}
    else if(n==8) { X=360;Y=325;}
   //else if(n==9) { X=220;Y=125;}
}

int main()

{

   int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setcolor(BLUE);

    bool q1=false,q2=false,q3=false,q4=false,q5=false,q6=false,q7=false,q8=false,q9=false;
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
    bool  b[9];
    for(int i=0;i<9;i++) b[i]=0;

    int counter=0;
    POINT c;
  //  outtextxy(20,20," O for Player 1 ");
    //outtextxy(20,40," X for Player 2 ");
     settextstyle(BOLD_FONT,HORIZ_DIR,5);

     int v;
     while(1)
     {

        if(counter%2==1)
     {
            if(GetAsyncKeyState(VK_LBUTTON))
            {
                GetCursorPos(&c);
                    int x,y;
                    x=c.x;
                    y=c.y;

            if(x>=200 && x<=270 && y>=100 && y<=200 && b[0]!=true) { arr[0]='x'; b[0]=true; counter++;outtextxy(220,125,"X");}
             else  if(x>=270 && x<=340 && y>=100 && y<=200 && b[1]!=true) { arr[1]='x'; b[1]=true; counter++; outtextxy(290,125,"X");}
             else  if(x>=340 && x<=410 && y>=100 && y<=200 && b[2]!=true) { arr[2]='x'; b[2]=true; counter++;outtextxy(360,125,"X");}
             else  if(x>=200 && x<=270 && y>=200 && y<=300 && b[3]!=true) { arr[3]='x'; b[3]=true; counter++;outtextxy(220,225,"X");}
             else  if(x>=270 && x<=340 && y>=200 && y<=300 && b[4]!=true) { arr[4]='x'; b[4]=true; counter++;outtextxy(290,225,"X");}
             else  if(x>=340 && x<=410 && y>=200 && y<=300 && b[5]!=true) { arr[5]='x'; b[5]=true; counter++;outtextxy(360,225,"X");}
             else  if(x>=200 && x<=270 && y>=300 && y<=400 && b[6]!=true) { arr[6]='x'; b[6]=true; counter++;outtextxy(220,325,"X");}
             else  if(x>=270 && x<=340 && y>=300 && y<=400 && b[7]!=true) { arr[7]='x'; b[7]=true; counter++;outtextxy(290,325,"X");}
             else  if(x>=340 && x<=410 && y>=300 && y<=400 && b[8]!=true) { arr[8]='x'; b[8]=true; counter++;outtextxy(360,325,"X");}


     }
     }
     else if (counter%2==0)
     {
         while(1){
             v=rand()%9;
             if(b[v]==false)
             {
                 arr[v]='o';
                 b[v]=true;
                 int X,Y;
                 counter++;
                 coordinate(v,X,Y);
                 outtextxy(X,Y,"O");
                break;
             }
     }
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
                             outtextxy(150,200,"You Beat Computer");
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
                             outtextxy(150,200,"Computer Beats You");
                             break;
                         }
                         if(b[0]==true && b[1]==true && b[2]==true && b[3]==true && b[4]==true && b[5]==true && b[6]==true  && b[7]==true && b[8]==true)
                            {
                             outtextxy(150,200,"Match Draw");
                             break;
                         }
                           // delay(500);


     delay(500);
    }
     getch();
     closegraph();
}
