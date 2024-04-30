#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>
#include "FS.h"
#include "SPIFFS.h"

#define MAX_RAWBUF_SIZE 100

decode_results results;
uint16_t* rawcode;

int rawDataLen;
IRrecv irrecv(IRRECV);

void setupReceiver() {
  DISP.fillScreen(BGCOLOR);
  DISP.setTextSize(BIG_TEXT);
  DISP.setCursor(0, 0);
  DISP.println("IR Replay");
  irrecv.enableIRIn();
  delay(500);
}

void receiveSignal() {
  DISP.fillScreen(BGCOLOR);
  DISP.setTextSize(BIG_TEXT);
  DISP.setCursor(0, 0);
  DISP.println("Receiver");
  DISP.setTextSize(MEDIUM_TEXT);
  DISP.println("Waiting...");
  pinMode(IRRECV, INPUT);
  while(true){
    if (irrecv.decode(&results)) {
      rawcode = new uint16_t[MAX_RAWBUF_SIZE];
      memset(rawcode, 0, MAX_RAWBUF_SIZE * sizeof(uint16_t));
      rawDataLen = results.rawlen;
      DISP.fillScreen(BGCOLOR);
      DISP.setTextSize(BIG_TEXT);
      DISP.setCursor(0, 0);
      DISP.println("Receiver");
      DISP.setTextSize(MEDIUM_TEXT);
      DISP.println("Recorded!");
      DISP.print(results.value, HEX);
      Serial.print("Raw Data ");
      Serial.print(rawDataLen);
      Serial.print(" : ");
      //String RawString = "";
      for (int i = 1; i < results.rawlen; i++) {
        //RawString += String(results.rawbuf[i]);
        Serial.print(results.rawbuf[i], DEC);
        if (i < results.rawlen - 1){
          Serial.print(", "); 
          //RawString += ", ";
        } 
        rawcode[i - 1] = results.rawbuf[i] * 2;
      }
      //saveToSpiffs(RawString);
      Serial.println();
      Serial.print("Hex: ");
      Serial.println(results.value, HEX);
      irrecv.resume();
      pinMode(IRRECV, OUTPUT);
      delay(1000);
      break;
    }
  }
}

void sendSignal() {
  irsend.begin();
  DISP.fillScreen(BGCOLOR);
  DISP.setTextSize(BIG_TEXT);
  DISP.setCursor(0, 0);
  DISP.println("IR Sender");
  DISP.setTextSize(MEDIUM_TEXT);
  DISP.println("Sending...");
  Serial.println("Sending Custom");
  irsend.sendRaw(rawcode, rawDataLen, 38); // 38Khz
  delay(1000);
}

void saveToSpiffs(String rawData){
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }
  Serial.println("SPIFFS successfully mounted");

  File file = SPIFFS.open("/FNemoIR.txt", FILE_WRITE);
  if (!file) {
    Serial.println("Error opening the file");
    return;
  }

  if (file.println(rawData)) {
    Serial.println("IR saved successfully");
  } else {
    Serial.println("Error saving IR");
  }

  file.close();
}