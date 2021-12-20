// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "8jUTCcAJhJBmVVje-u-YI0wTvNMW5Uja";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Pesma SDM IPTEK";
char pass[] = "benTen10";

#define ledPin D4
#define PinPIR D2
int nilaiPIR;

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(10);
  Blynk.begin(auth, ssid, pass);
  pinMode(ledPin, OUTPUT);
  pinMode(PinPIR, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  getPirValue();
  Blynk.run(); 
}

void getPirValue(void) {
  nilaiPIR = digitalRead(PinPIR);
  Serial.println(nilaiPIR);
  if(nilaiPIR){
    Serial.println("Ada Gerakan Objek");
    Blynk.notify("Ada Gerakan Objek");
  }
  digitalWrite(ledPin, nilaiPIR);
}
