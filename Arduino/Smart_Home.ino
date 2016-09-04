//Created on: 24-Mar-2016
//Author: Roshan Prakash, Project MANAS
//This code cannot be shared, modified, distributed without prior written permission from its authors.
int L3 = A0;
int L1 = A1;
int F2 = A2;
int F3 = A3;
int L2 = A4;
int F1 = A5;
int L4 = 2;
int L5 = 3;
int L6 = 4;
int L7 = 5;
int L8 = 6;
int L9 = 7;
int buzz = 8;
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;

// Init array that will store new NUID
byte nuidPICC[3];
void setup() {
  pinMode(F1, OUTPUT);
  pinMode(F2, OUTPUT);
  pinMode(F3, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  pinMode(L8, OUTPUT);
  pinMode(L9, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    char incoming = Serial.read();
    incoming = int (incoming);
    if (incoming == '1')
    {
      // Look for new cards
      if ( ! rfid.PICC_IsNewCardPresent())
        return;

      // Verify if the NUID has been readed
      if ( ! rfid.PICC_ReadCardSerial())
        return;
      if (rfid.uid.uidByte[0] != nuidPICC[0] ||
          rfid.uid.uidByte[1] != nuidPICC[1] ||
          rfid.uid.uidByte[2] != nuidPICC[2] ||
          rfid.uid.uidByte[3] != nuidPICC[3] ) {
        // Store NUID into nuidPICC array
        for (byte i = 0; i < 4; i++) {
          nuidPICC[i] = rfid.uid.uidByte[i];
        }
      }
      printDec(rfid.uid.uidByte, rfid.uid.size);
      Serial.println();
    }

    if (incoming == 'a')
    {
      digitalWrite(F1, LOW);
    }
    if (incoming == 'b')
    {
      digitalWrite(F1, HIGH);
    }
    if (incoming == 'c')
    {
      digitalWrite(F2, LOW);
    }
    if (incoming == 'd')
    {
      digitalWrite(F2, HIGH);
    }
    if (incoming == 'e')
    {
      digitalWrite(F3, LOW);
    }
    if (incoming == 'f')
    {
      digitalWrite(F3, HIGH);
    }
    if (incoming == 'g')
    {
      digitalWrite(L1, LOW);
    }
    if (incoming == 'h')
    {
      digitalWrite(L1, HIGH);
    }
    if (incoming == 'i')
    {
      digitalWrite(L2, LOW);
    }
    if (incoming == 'j')
    {
      digitalWrite(L2, HIGH);
    }
    if (incoming == 'k')
    {
      digitalWrite(L3, LOW);
    }
    if (incoming == 'l')
    {
      digitalWrite(L3, HIGH);
    }
    if (incoming == 'm')
    {
      digitalWrite(L4, LOW);
    }
    if (incoming == 'n')
    {
      digitalWrite(L4, HIGH);
    }
    if (incoming == 'o')
    {
      digitalWrite(L5, LOW);
    }
    if (incoming == 'p')
    {
      digitalWrite(L5, HIGH);
    }
    if (incoming == 'q')
    {
      digitalWrite(L6, LOW);
    }
    if (incoming == 'r')
    {
      digitalWrite(L6, HIGH);
    }
    if (incoming == 's')
    {
      digitalWrite(L7, LOW);
    }
    if (incoming == 't')
    {
      digitalWrite(L7, HIGH);
    }
    if (incoming == 'u')
    {
      digitalWrite(L8, LOW);
    }
    if (incoming == 'v')
    {
      digitalWrite(L8, HIGH);
    }
    if (incoming == 'w')
    {
      digitalWrite(L9, LOW);
    }
    if (incoming == 'x')
    {
      digitalWrite(L9, HIGH);
    }
    if (incoming == 'z')
    {
      digitalWrite(buzz, HIGH);
      delay(500);
      digitalWrite(buzz, LOW);
    }
    if (incoming == 'y')
    {
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
      delay(100);
      digitalWrite(buzz, HIGH);
      delay(100);
      digitalWrite(buzz, LOW);
    }
  }
}
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? "" : "");
    Serial.print(buffer[i], DEC);
  }
}

