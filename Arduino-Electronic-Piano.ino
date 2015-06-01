#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define C2_key 65
#define D2_key 73
#define E2_key 82
#define F2_key 87
#define G2_key 98
#define A2_key 110
#define B2_key 123

#define C3_key 131
#define D3_key 147
#define E3_key 165
#define F3_key 175
#define G3_key 196
#define A3_key 220
#define B3_key 247

#define C4_key 262
#define D4_key 294
#define E4_key 330
#define F4_key 349
#define G4_key 392
#define A4_key 440
#define B4_key 494

#define C5_key 523
#define D5_key 587
#define E5_key 659
#define F5_key 698
#define G5_key 784
#define A5_key 880
#define B5_key 988

#define C6_key 1047
#define D6_key 1175
#define E6_key 1319
#define F6_key 1397
#define G6_key 1568
#define A6_key 1760
#define B6_key 1976

int notes2[] = {C2_key, D2_key, E2_key, F2_key, G2_key, A2_key, B2_key};
int notes3[] = {C3_key, D3_key, E3_key, F3_key, G3_key, A3_key, B3_key};
int notes4[] = {C4_key, D4_key, E4_key, F4_key, G4_key, A4_key, B4_key};
int notes5[] = {C5_key, D5_key, E5_key, F5_key, G5_key, A5_key, B5_key};
int notes6[] = {C6_key, D6_key, E6_key, F6_key, G6_key, A6_key, B6_key};
int* notesall[] = {notes2, notes3, notes4, notes5, notes6};

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);

}

void loop() {
  int keyVal = analogRead(A2);
  int SecKey = analogRead(A1);
  int res = analogRead(A0);
  
  // What area is activated
  int notearea = 2;
  int freq = -1;
  // C2
  
  if (res >= 0 && res < 204){
    notearea = 2;
  }
   
   // C3
  if (res >= 204 && res < 408){
    notearea = 3;
  }
  
  
  // C4
  if (res >= 408 && res < 612){
    notearea = 4;
  }
  
  // C5
  if (res >= 612 && res < 816){
    notearea = 5;
  }
  
  // C6
  if (res >= 816 && res < 1024){
    notearea = 6;
  }
  
  lcd.print("Note area is:");
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
  
  
  Serial.print("1st key Value: ");
  Serial.print(keyVal);
  Serial.print("  2nd key Value: ");
  Serial.print(SecKey);
  Serial.print("  Resistor is: ");
  Serial.println(res);
       
  // play note
  if (freq == -1)
  {
     noTone(8); 
  }
  else
  {
     tone(8, freq); 
  }

}
