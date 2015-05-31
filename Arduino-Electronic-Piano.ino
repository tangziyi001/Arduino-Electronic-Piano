#define C_key 262
#define D_key 294
#define E_key 330
#define F_key 349
#define G_key 392
#define A_key 440
#define B_key 494

int notes[] = {C_key, D_key, E_key, F_key, G_key, A_key, B_key};

void setup() {
  Serial.begin(9600);

}

void loop() {
  int keyVal = analogRead(A0);
  int SecKey = analogRead(A1);
  int freq = -1;
  Serial.println("1st key Value: ");
  Serial.print(keyVal);
  Serial.print("   2nd key Value: ");
  Serial.print(SecKey);
  
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
  else if (keyVal >= 5 && (keyVal <= 10))
  {
     freq = notes[3];
  }
  
  // read from A1
  else if (SecKey == 1023)
  {
     freq = notes[4];
  }
  else if (SecKey >= 990 && (SecKey <= 1010))
  {
     freq = notes[5];
  }
  else if (SecKey >= 500 && (SecKey <= 515))
  {
     freq = notes[6];
  }
  
  
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
