#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // HC-06 modülü için RX ve TX pimleri

int in1 = 5; // OUT1
int in2 = 6; // OUT2
int in3 = 9; // OUT3
int in4 = 3; // OUT4

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600); // Seri haberleşme için başlangıç hızı
  BTSerial.begin(9600); // Bluetooth modülü için başlangıç hızı
}

void loop() {
  // Bluetooth modülünden veri alınıyor
  if (BTSerial.available()) {
    char c = BTSerial.read();   
    // Sağa dönüş
    if (c == 'R') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(in3, 100);
      analogWrite(in4, 100);
    }
    // Sola dönüş
    else if (c == 'L') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(in3, 100);
      analogWrite(in4, 100);
    }
    // İleri gitme
    else if (c == 'F') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    // Geri gitme
    else if (c == 'B') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }  // Durma
    else if (c == 'S') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
  }
}
