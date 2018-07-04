char ctrlesquerdo = KEY_LEFT_CTRL;
char shiftesquerdo = KEY_LEFT_SHIFT;
char altesquerdo = KEY_LEFT_ALT;	
char guiesquerdo = KEY_LEFT_GUI;	
char ctrldireito = KEY_RIGHT_CTRL;	
char shiftdireito = KEY_RIGHT_SHIFT;
char altdireito = KEY_RIGHT_ALT;	
char guidireito = KEY_RIGHT_GUI;
char setacima = KEY_UP_ARROW;	
char setabaixo = KEY_DOWN_ARROW;	
char setaesquerda = KEY_LEFT_ARROW;	
char setadireita = KEY_RIGHT_ARROW;	
char apagar = KEY_BACKSPACE;	
char tab = KEY_TAB;	
char retornar = KEY_RETURN;	
char esc = KEY_ESC;	
char isert = KEY_INSERT;	
char del =KEY_DELETE;	
char pageup = KEY_PAGE_UP;	
char pagedown = KEY_PAGE_DOWN;	
char HOME = KEY_HOME;	
char END = KEY_END;		
char caps = KEY_CAPS_LOCK;	
char f1 = KEY_F1;		
char f2 = KEY_F2;		
char f3 = KEY_F3;		
char f4 = KEY_F4;		
char f5 = KEY_F5;		
char f6 = KEY_F6;		
char f7 = KEY_F7;		
char f8 = KEY_F8;		
char f9 = KEY_F9;		
char f10 = KEY_F10;		
char f11 = KEY_F11;		
char f12 = KEY_F12;		
boolean x=HIGH;
byte debounce = 0;
void setup()
{
  pinMode(13, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  Mouse.begin();
}

void loop()
{
  
  if(digitalRead(2) == LOW || digitalRead(3) == LOW || digitalRead(4) == LOW ||   digitalRead(5) == LOW || digitalRead(5) == LOW || digitalRead(5) == LOW || 
  digitalRead(5) == LOW || digitalRead(5) == LOW || digitalRead(10) == LOW ||   digitalRead(11) == LOW ||  digitalRead(12) == LOW){
     unsigned long tempo = millis(); 
     while(tempo + 500 > millis());    
     if(digitalRead(2) == LOW || digitalRead(3) == LOW || digitalRead(4) == LOW ||   digitalRead(5) == LOW || digitalRead(5) == LOW || digitalRead(5) == LOW || 
  digitalRead(5) == LOW || digitalRead(5) == LOW || digitalRead(10) == LOW ||   digitalRead(11) == LOW ||  digitalRead(12) == LOW) debounce = 1;
  }
  
  if (digitalRead(12) == 0 && debounce == 1)
  {
    debounce=!debounce;
    Keyboard.write('z');  
    delay(1000);  
  }

if (digitalRead(10) == 0 && debounce == 1)  // if the button goes low
  {
    debounce=!debounce;
    x=!x;
    if(x==0){
  Keyboard.press(f5);
  delay(100);
  Keyboard.releaseAll();
  while(digitalRead(10) == 0);
    }
  else{
Keyboard.press(esc);
  delay(100);
  Keyboard.releaseAll();
  while(digitalRead(10) == 0);
}  
}

if (digitalRead(2) == 0 && debounce == 1)  
  {
    debounce=!debounce;
  Keyboard.press(ctrlesquerdo);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
  while(digitalRead(2) == 0);
  }
if (digitalRead(3) == 0 && debounce == 1)  
  {
    debounce=!debounce;
     Keyboard.press(ctrlesquerdo);
     Keyboard.press('h');
     delay(100);
     Keyboard.releaseAll();
     while(digitalRead(3) == 0);
  }
if (digitalRead(4) == 0 && debounce == 1)  
  {
    debounce=!debounce;
     Keyboard.press(pagedown);
     delay(100);
     Keyboard.releaseAll();
     while(digitalRead(4) == 0);
  }
if (digitalRead(5) == 0 && debounce == 1)  
  {
    debounce=!debounce;
     Keyboard.press(pageup);
     delay(100);
     Keyboard.releaseAll();
     while(digitalRead(5) == 0);
  }

if (digitalRead(6) == 0)  
  {
     Mouse.move(4, 0, 0);
     delay(15);
     //Keyboard.releaseAll();
     //while(digitalRead(6) == 0);
  }
if (digitalRead(7) == 0)  
  {
     Mouse.move(-4, 0, 0);
     delay(15);
     //Keyboard.releaseAll();
     //while(digitalRead(6) == 0);
  }
  if (digitalRead(8) == 0)  
  {
     Mouse.move(0, 4, 0);
     delay(15);
     //Keyboard.releaseAll();
     //while(digitalRead(6) == 0);
  }
if (digitalRead(9) == 0)  
  {
     Mouse.move(0, -4, 0);
     delay(15);
     //Keyboard.releaseAll();
     //while(digitalRead(6) == 0);
  }





 
}
