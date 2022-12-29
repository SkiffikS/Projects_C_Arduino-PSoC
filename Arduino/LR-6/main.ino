#include <LiquidCrystal.h>   
#include <Keypad.h>
#include <Servo.h>

int servostate;
int posOpen = 90;
int posClose = 0;
int a=0, b=0, c=0, d=0; //кількість цифр у паролі
int var=0; 
int C1=1,C2=2,C3=3,C4=4;
char f='*';  
const byte filas = 4; 
const byte columnas = 4;
char tecla[filas][columnas] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}//панель для введення паролю
};
byte pinFilas[filas] = {0, 6, 5, 4}; 
byte pinColumnas[columnas] = {3, 2, 1};

Servo myservo;
Keypad keypad = Keypad( makeKeymap(tecla), pinFilas, pinColumnas, filas, columnas );
LiquidCrystal lcd(8,9,10,11,12,13);
void setup(){
  lcd.begin(16,2); 
  pinMode(A0,OUTPUT); 
  pinMode(A1,OUTPUT); 
  myservo.attach(7); 
  myservo.write(posOpen);
  servostate = 1;
}
  
void loop(){  
  char key = keypad.getKey();
  if (key){
   lcd.setCursor(6+var,1);
   lcd.print(key),lcd.setCursor(6+var,1),lcd.print(f);
   key=key-48;
   var++; 
   switch(var){
    case 1:
    a=key; 
    break;
    case 2:
    b=key; 
    break;
    case 3:
    c=key; 
    break;
    case 4:
    d=key; 
   delay(50);
  if(a==C1 && b==C2 && c==C3 && d==C4){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Password");
    lcd.setCursor(1,1);
    if(servostate == 0){
    	lcd.print("Aberta");
      myservo.write(posOpen);
      servostate = 1;      
    }
    else{
      lcd.print("true");//якщо правильний пароль
      myservo.write(posClose);
      servostate = 0;      
    }
    
    digitalWrite(A0,HIGH);
    delay(1000); 
    lcd.clear();
    digitalWrite(A0,LOW);
    }
  else{
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Password");
    lcd.setCursor(1,1);
    lcd.print("not suitable");//якщо пароль не вірний
    digitalWrite(A1,HIGH); 
    delay(1000); 
    lcd.clear();
    digitalWrite(A1,LOW); 
    }

   var=0;
   lcd.clear();

  break;
  }

 }
 if(!key){lcd.setCursor(0,0),lcd.print("Enter password");}//Шрифт на екрані"Введіть пароль"

  delay(2);
}