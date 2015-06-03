#include <LiquidCrystal.h>
//#include <stdlib.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define C2_key 65
#define CU2_key 69
#define D2_key 73
#define DU2_key 78
#define E2_key 82
#define F2_key 87
#define FU2_key 93
#define G2_key 98
#define GU2_key 104
#define A2_key 110
#define AU2_key 117
#define B2_key 123

#define C3_key 131
#define CU3_key 139
#define D3_key 147
#define DU3_key 156
#define E3_key 165
#define F3_key 175
#define FU3_key 185
#define G3_key 196
#define GU3_key 208
#define A3_key 220
#define AU3_key 233
#define B3_key 247

#define C4_key 262
#define CU4_key 277
#define D4_key 294
#define DU4_key 311
#define E4_key 330
#define F4_key 349
#define FU4_key 370
#define G4_key 392
#define GU4_key 415
#define A4_key 440
#define AU4_key 466
#define B4_key 494

#define C5_key 523
#define CU5_key 554
#define D5_key 587
#define DU5_key 622
#define E5_key 659
#define F5_key 698
#define FU5_key 740
#define G5_key 784
#define GU5_key 831
#define A5_key 880
#define AU5_key 932
#define B5_key 988

#define C6_key 1047
#define CU6_key 1109
#define D6_key 1175
#define DU6_key 1245
#define E6_key 1319
#define F6_key 1397
#define FU6_key 1480
#define G6_key 1568
#define GU6_key 1661
#define A6_key 1760
#define AU6_key 1865
#define B6_key 1976

int notes2[] = {C2_key, CU2_key, D2_key, DU2_key, E2_key, F2_key, FU2_key, G2_key, GU2_key, A2_key, AU2_key, B2_key};
int notes3[] = {C3_key, CU3_key, D3_key, DU3_key, E3_key, F3_key, FU3_key, G3_key, GU3_key, A3_key, AU3_key, B3_key};
int notes4[] = {C4_key, CU4_key, D4_key, DU4_key, E4_key, F4_key, FU4_key, G4_key, GU4_key, A4_key, AU4_key, B4_key};
int notes5[] = {C5_key, CU5_key, D5_key, DU5_key, E5_key, F5_key, FU5_key, G5_key, GU5_key, A5_key, AU5_key, B5_key};
int notes6[] = {C6_key, CU6_key, D6_key, DU6_key, E6_key, F6_key, FU6_key, G6_key, GU6_key, A6_key, AU6_key, B6_key};
int* notesall[] = {notes2, notes3, notes4, notes5, notes6};


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Sound range is:");

  Serial.begin(9600);

}

void loop() {
  int FirKey = analogRead(A0);
  int SecKey = analogRead(A2);
  int ThrKey = analogRead(A4);
  int res = analogRead(A1);
  
  // What area is activated
  int notearea = 2;
  int freq = -1;
  char str[1];
  // C2
  
  if (res >= 0 && res < 204){
    notearea = 6;
  }
   
   // C3
  if (res >= 204 && res < 408){
    notearea = 5;
  }
  
  
  // C4
  if (res >= 408 && res < 612){
    notearea = 4;
  }
  
  // C5
  if (res >= 612 && res < 816){
    notearea = 3;
  }
  
  // C6
  if (res >= 816 && res < 1024){
    notearea = 2;
  }

  // Show the new notearea
  
  
 
  //sprintf(str, "%d", notearea);
  lcd.setCursor(0,1);
  lcd.print(notearea);
 
//  lcd.print("C");
//  lcd.setCursor(1,1);
//  lcd.print(notearea);
//  lcd.setCursor(2,1);
//  lcd.print(" - B");
//  lcd.setCursor(3,1);
//  lcd.print(notearea);
  
  notearea = notearea - 2;
  
  
  // Choose note
  for (int i = 0; i < 5; i++){
     if (FirKey == 1023)
    {
       freq = notesall[notearea][0];
    }
    else if (FirKey >= 990 && (FirKey <= 1010))
    {
       freq = notesall[notearea][1];
    }
    else if (FirKey >= 505 && (FirKey <= 515))
    {
       freq = notesall[notearea][2];
    }
    else if (FirKey >= 5 && (FirKey <= 10))
    {
       freq = notesall[notearea][3];
    }  
    else if (SecKey == 1023)
    {
       freq = notesall[notearea][4];
    }
    else if (SecKey >= 990 && (SecKey <= 1010))
    {
       freq = notesall[notearea][5];
    }
    else if (SecKey >= 500 && (SecKey <= 515))
    {
       freq = notesall[notearea][6];
    } 
    else if (SecKey >= 5 && SecKey <= 10)
    {
       freq = notesall[notearea][7];
    }
    else if (ThrKey == 1023)
    {
       freq = notesall[notearea][8];
    }
    else if (ThrKey >= 990 && (ThrKey <= 1010))
    {
       freq = notesall[notearea][9];
    }
    else if (ThrKey >= 500 && (ThrKey <= 515))
    {
       freq = notesall[notearea][10];
    } 
    else if (ThrKey >= 5 && ThrKey <= 10)
    {
       freq = notesall[notearea][11];
    }
    
  }
  
  
  Serial.print("1st key Value: ");
  Serial.print(FirKey);
  Serial.print("  2nd key Value: ");
  Serial.print(SecKey);
  Serial.print("  3nd key Value: ");
  Serial.print(ThrKey);
  Serial.print("  Resistor is: ");
  Serial.print(res);
  Serial.print("  Freq is: ");
  Serial.println(freq);
       
  // play note
  if (freq == -1)
  {
     noTone(13); 
  }
  else
  {
     tone(13, freq); 
  }

}
