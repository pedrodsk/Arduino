
#include <UTFT.h>
#include <UTouch.h>
#include <SoftwareSerial.h>  
int bluetoothTx = 10;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 11;  // RX-I pin of bluetooth mate, Arduino D3
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


UTFT    myGLCD(ITDB28,19,18,17,16);


UTouch  myTouch(15,10,14, 8, 9);

// Declare which fonts we will be using
extern uint8_t BigFont[];

int x, y;
char stCurrent[20]="";
int stCurrentLen=0;
char stLast[20]="";


void drawButtons()
{
// Draw the upper row of buttons
  for (x=0; x<10; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (5+(x*30), 10, 30+(x*30), 50);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (5+(x*30), 10, 30+(x*30), 50);
    switch(x) {
      case 0:
    myGLCD.print("0", 13.5+(x*30), 27);
    break;
    case 1:
    myGLCD.print("1", 13.5+(x*30), 27);
    break;
    case 2:
    myGLCD.print("2", 13.5+(x*30), 27);
    break;
    case 3:
    myGLCD.print("3", 13.5+(x*30), 27);
    break;
    case 4:
    myGLCD.print("4", 13.5+(x*30), 27);
    break;
    case 5:
    myGLCD.print("5", 13.5+(x*30), 27);
    break;
    case 6:
    myGLCD.print("6", 13.5+(x*30), 27);
    break;
    case 7:
    myGLCD.print("7", 13.5+(x*30), 27);
    break;
    case 8:
    myGLCD.print("8", 13.5+(x*30), 27);
    break;
    case 9:
    myGLCD.print("9", 13.5+(x*30), 27);
    break;
    } 

    
  }
// Draw the center row of buttons
  for (x=0; x<10; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (5+(x*30), 60, 30+(x*30), 100);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (5+(x*30), 60, 30+(x*30), 100);
    switch(x) {
      case 0:
    myGLCD.print("q", 13.5+(x*30), 77);
    break;
    case 1:
    myGLCD.print("w", 13.5+(x*30), 77);
    break;
    case 2:
    myGLCD.print("e", 13.5+(x*30), 77);
    break;
    case 3:
    myGLCD.print("r", 13.5+(x*30), 77);
    break;
    case 4:
    myGLCD.print("t", 13.5+(x*30), 77);
    break;
    case 5:
    myGLCD.print("y", 13.5+(x*30), 77);
    break;
    case 6:
    myGLCD.print("u", 13.5+(x*30), 77);
    break;
    case 7:
    myGLCD.print("i", 13.5+(x*30), 77);
    break;
    case 8:
    myGLCD.print("o", 13.5+(x*30), 77);
    break;
    case 9:
    myGLCD.print("p", 13.5+(x*30), 77);
    break;
    }
  }
  for (x=0; x<10; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (5+(x*30), 110, 30+(x*30), 150);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (5+(x*30), 110, 30+(x*30), 150);
   switch(x) {
      case 0:
    myGLCD.print("", 13.5+(x*30), 127);
    break;
    case 1:
    myGLCD.print("a", 13.5+(x*30), 127);
    break;
    case 2:
    myGLCD.print("s", 13.5+(x*30), 127);
    break;
    case 3:
    myGLCD.print("d", 13.5+(x*30), 127);
    break;
    case 4:
    myGLCD.print("f", 13.5+(x*30), 127);
    break;
    case 5:
    myGLCD.print("g", 13.5+(x*30), 127);
    break;
    case 6:
    myGLCD.print("h", 13.5+(x*30), 127);
    break;
    case 7:
    myGLCD.print("j", 13.5+(x*30), 127);
    break;
    case 8:
    myGLCD.print("k", 13.5+(x*30), 127);
    break;
    case 9:
    myGLCD.print("l", 13.5+(x*30), 127);
    break;
    }
  }
  
  for (x=0; x<10; x++)
  {
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRoundRect (5+(x*30), 160, 30+(x*30), 200);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (5+(x*30), 160, 30+(x*30), 200);
    switch(x) {
      case 0:
    myGLCD.print("", 13.5+(x*30), 177);
    break;
    case 1:
    myGLCD.print("z", 13.5+(x*30), 177);
    break;
    case 2:
    myGLCD.print("x", 13.5+(x*30), 177);
    break;
    case 3:
    myGLCD.print("c", 13.5+(x*30), 177);
    break;
    case 4:
    myGLCD.print("v", 13.5+(x*30), 177);
    break;
    case 5:
    myGLCD.print("b", 13.5+(x*30), 177);
    break;
    case 6:
    myGLCD.print("n", 13.5+(x*30), 177);
    break;
    case 7:
    myGLCD.print("m", 13.5+(x*30), 177);
    break;
    case 8:
    myGLCD.print(",", 13.5+(x*30), 177);
    break;
    case 9:
    myGLCD.print(".", 13.5+(x*30), 177);
    break;
    
  }
}

  /*
  myGLCD.print("0", 267, 87);
// Draw the lower row of buttons
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 130, 150, 180);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 130, 150, 180);
  myGLCD.print("Clear", 40, 147);
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (160, 130, 300, 180);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (160, 130, 300, 180);
  myGLCD.print("Enter", 190, 147);
  myGLCD.setBackColor (0, 0, 0);
*/
}

void updateStr(int val)
{
  if (stCurrentLen<20)
  {
    stCurrent[stCurrentLen]=val;
    stCurrent[stCurrentLen+1]='\0';
    stCurrentLen++;
    myGLCD.setColor(0, 255, 0);
    myGLCD.print(stCurrent, LEFT, 224);
  }
  else
  {
    myGLCD.setColor(255, 0, 0);
    myGLCD.print("BUFFER FULL!", CENTER, 200);
    delay(500);
    myGLCD.print("            ", CENTER, 200);
    delay(500);
    myGLCD.print("BUFFER FULL!", CENTER, 200);
    delay(500);
    myGLCD.print("            ", CENTER, 200);
    myGLCD.setColor(0, 255, 0);
  }
}


void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
    myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}


void setup()
{

  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);
  drawButtons();  
}

void loop()
{
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
 //0-9     
      if ((y>=10) && (y<=50))  
      {
        if ((x>=5) && (x<=30))  
        {
          waitForIt(5, 10, 30, 50);
          updateStr('0');
        }
        if ((x>=35) && (x<=60))  
        {
          waitForIt(35, 10, 60, 50);
          updateStr('1');
        }
        if ((x>=65) && (x<=90))  
        {
          waitForIt(65, 10, 90, 50);
          updateStr('2');
        }
        if ((x>=95) && (x<=120))  
        {
          waitForIt(95, 10, 120, 50);
          updateStr('3');
        }
        if ((x>=125) && (x<=150))  
        {
          waitForIt(125, 10, 150, 50);
          updateStr('4');
        }
        if ((x>=155) && (x<=180))  
        {
          waitForIt(155, 10, 180, 50);
          updateStr('5');
        }
        if ((x>=185) && (x<=210))  
        {
          waitForIt(185, 10, 210, 50);
          updateStr('6');
        }
        if ((x>=215) && (x<=240))  
        {
          waitForIt(215, 10, 240, 50);
          updateStr('7');
        }
        if ((x>=245) && (x<=270)) 
        {
          waitForIt(245, 10, 270, 50);
          updateStr('8');
        }
        if ((x>=275) && (x<=300)) 
        {
          waitForIt(275, 10, 300, 50);
          updateStr('9');
        }
      }
//Q - P
      if ((y>=60) && (y<=100))  
      {
        if ((x>=5) && (x<=30))  
        {
          waitForIt(5, 60, 30, 100);
          updateStr('q');
        }
        if ((x>=35) && (x<=60))  
        {
          waitForIt(35, 60, 60, 100);
          updateStr('w');
        }
        if ((x>=65) && (x<=90))  
        {
          waitForIt(65, 60, 90, 100);
          updateStr('e');
        }
        if ((x>=95) && (x<=120))  
        {
          waitForIt(95, 60, 120, 100);
          updateStr('r');
        }
        if ((x>=125) && (x<=150))  
        {
          waitForIt(125, 60, 150, 100);
          updateStr('t');
        }
        if ((x>=155) && (x<=180))  
        {
          waitForIt(155, 60, 180, 100);
          updateStr('y');
        }
        if ((x>=185) && (x<=210))  
        {
          waitForIt(185, 60, 210, 100);
          updateStr('u');
        }
        if ((x>=215) && (x<=240))  
        {
          waitForIt(215, 60, 240, 100);
          updateStr('i');
        }
        if ((x>=245) && (x<=270)) 
        {
          waitForIt(245, 60, 270, 100);
          updateStr('o');
        }
        if ((x>=275) && (x<=300)) 
        {
          waitForIt(275, 60, 300, 100);
          updateStr('p');
        }
      }

//A - L
      if ((y>=110) && (y<=150))  
      {
        //if ((x>=5) && (x<=30))  
        //{
         // waitForIt(5, 110, 30, 150);
         // updateStr('0');
        //}
        if ((x>=5) && (x<=30))  // Button: Clear
        {
          waitForIt(5, 110, 30, 150);
          stCurrent[0]='\0';
          stCurrentLen=0;
          myGLCD.setColor(0, 0, 0);
          myGLCD.fillRect(0, 224, 319, 239);
        }
        if ((x>=35) && (x<=60))  
        {
          waitForIt(35, 110, 60, 150);
          updateStr('a');
        }
        if ((x>=65) && (x<=90))  
        {
          waitForIt(65, 110, 90, 150);
          updateStr('s');
        }
        if ((x>=95) && (x<=120))  
        {
          waitForIt(95, 110, 120, 150);
          updateStr('d');
        }
        if ((x>=125) && (x<=150))  
        {
          waitForIt(125, 110, 150, 150);
          updateStr('f');
        }
        if ((x>=155) && (x<=180))  
        {
          waitForIt(155, 110, 180, 150);
          updateStr('g');
        }
        if ((x>=185) && (x<=210))  
        {
          waitForIt(185, 110, 210, 150);
          updateStr('h');
        }
        if ((x>=215) && (x<=240))  
        {
          waitForIt(215, 110, 240, 150);
          updateStr('j');
        }
        if ((x>=245) && (x<=270)) 
        {
          waitForIt(245, 110, 270, 150);
          updateStr('k');
        }
        if ((x>=275) && (x<=300)) 
        {
          waitForIt(275, 110, 300, 150);
          updateStr('l');
        }
      }

//Z - .
      if ((y>=160) && (y<=200))  
      {
        //if ((x>=5) && (x<=30))  
        //{
        //  waitForIt(5, 160, 30, 200);
        //  updateStr('0');
        //}
        if ((x>=5) && (x<=30))  // Button: Enter
        {
          waitForIt(5, 160, 30, 200);
          if (stCurrentLen>0)
          {
            for (x=0; x<stCurrentLen+1; x++)
            {
              stLast[x]=stCurrent[x];
            }
            stCurrent[0]='\0';
            stCurrentLen=0;
            myGLCD.setColor(0, 0, 0);
            myGLCD.fillRect(0, 208, 319, 239);
            myGLCD.setColor(0, 255, 0);
            myGLCD.print(stLast, LEFT, 208);
          }
          else
          {
            myGLCD.setColor(255, 0, 0);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            delay(500);
            myGLCD.print("BUFFER EMPTY", CENTER, 192);
            delay(500);
            myGLCD.print("            ", CENTER, 192);
            myGLCD.setColor(0, 255, 0);
          }
        }
        if ((x>=35) && (x<=60))  
        {
          waitForIt(35, 160, 60, 200);
          updateStr('z');
        }
        if ((x>=65) && (x<=90))  
        {
          waitForIt(65, 160, 90, 200);
          updateStr('x');
        }
        if ((x>=95) && (x<=120))  
        {
          waitForIt(95, 160, 120, 200);
          updateStr('c');
        }
        if ((x>=125) && (x<=150))  
        {
          waitForIt(125, 160, 150, 200);
          updateStr('v');
        }
        if ((x>=155) && (x<=180))  
        {
          waitForIt(155, 160, 180, 200);
          updateStr('b');
        }
        if ((x>=185) && (x<=210))  
        {
          waitForIt(185, 160, 210, 200);
          updateStr('n');
        }
        if ((x>=215) && (x<=240))  
        {
          waitForIt(215, 160, 240, 200);
          updateStr('m');
        }
        if ((x>=245) && (x<=270)) 
        {
          waitForIt(245, 160, 270, 200);
          updateStr(',');
        }
        if ((x>=275) && (x<=300)) 
        {
          waitForIt(275, 160, 300, 200);
          updateStr('.');
        }
      }

      //}
    }
  }
}

