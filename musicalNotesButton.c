#define C_NOTE 262 
#define D_NOTE 294 
#define E_NOTE 330 
#define F_NOTE 349 

int buttonD = 3; 
int buttonC = 2; 
int buttonE = 4; 
int buttonF = 5; 
int buzzerPin = 8; 

void setup() {
  pinMode(buttonC, INPUT_PULLUP); 
  pinMode(buttonD, INPUT_PULLUP);
  pinMode(buttonE, INPUT_PULLUP);
  pinMode(buttonF, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  if (digitalRead(buttonC) == LOW) { 
    tone(buzzerPin, C_NOTE);
    delay(200); 
    noTone(buzzerPin); 
  }
  else if (digitalRead(buttonD) == LOW) { 
    tone(buzzerPin, D_NOTE); 
    delay(200);
    noTone(buzzerPin);
  }
  else if (digitalRead(buttonE) == LOW) { 
    tone(buzzerPin, E_NOTE); 
    delay(200);
    noTone(buzzerPin);
  }
  else if (digitalRead(buttonF) == LOW) { 
    tone(buzzerPin, F_NOTE); 
    delay(200);
    noTone(buzzerPin);
  }
  else { 
    digitalWrite(buzzerPin, LOW); 
  }
}
