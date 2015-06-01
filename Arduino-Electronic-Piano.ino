#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define C2_key 65
#define D2_key 73
#define E2_key 82
#define F2_key 87
#define G2_key 98
#define A2_key 110
#define B2_key 123

int notes[] = {262, 294, 330, 349,392, 440, 494};

void setup() {
  lcd.begin(16, 2);
  lcd.print("Note Area is:");

  Serial.begin(9600);

}

void loop() {
  int keyVal = analogRead(A0);
  int freq = -1;
  Serial.println(keyVal);
  if (keyVal == 1023)
  {
     freq = notes[0];
  }
  else if (keyVal >= 990 && (keyVal <= 1010))
  {
     freq = notes[1];
  }
  else if (keyVal >= 505 && (keyVal <= 515))
  {
     freq = notes[2];
  }

  lcd.setCursor(0,1);
  lcd.print("C");
  lcd.print(notearea);
  lcd.print(" - B");
  lcd.print(notearea);
  
  notearea = notearea - 2;
  
  
  // Choose note
  for (int i = 0; i < 5; i++){
     if (keyVal == 1023)
    {
       freq = notesall[notearea][3];
    }
    else if (keyVal >= 990 && (keyVal <= 1010))
    {
       freq = notesall[notearea][2];
    }
    else if (keyVal >= 505 && (keyVal <= 515))
    {
       freq = notesall[notearea][1];
    }
    else if (keyVal >= 5 && (keyVal <= 10))
    {
       freq = notesall[notearea][0];
    }  
    else if (SecKey == 1023)
    {
       freq = notesall[notearea][6];
    }
    else if (SecKey >= 990 && (SecKey <= 1010))
    {
       freq = notesall[notearea][5];
    }
    else if (SecKey >= 500 && (SecKey <= 515))
    {
       freq = notesall[notearea][4];
    }

  }
  
  if (freq == -1)
  {
     noTone(8); 
  }
  else
  {
     tone(8, freq); 
  }

}
