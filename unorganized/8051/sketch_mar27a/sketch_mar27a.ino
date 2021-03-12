#include <Wire.h>
#include<LiquidCrystal.h>
#include <SPI.h>
#define lcdd 1000
LiquidCrystal lcd(9);
int x[30];
byte customChar[] = {
  0x04,
  0x04,
  0x04,
  0x04,
  0x1F,
  0x0E,
  0x04,
  0x1F
};
byte virus[] = {
  0x04,
  0x15,
  0x0E,
  0x1F,
  0x0E,
  0x15,
  0x04,
  0x00
};
byte climit = 0;
byte tclimit = 0;
byte dlimit = 0;
byte rlimit = 0;
byte elimit = 0;
byte mlimit = 0;

int cases = 0 ;
int todaycases = 0;
int deaths = 0;
int recovered = 0;
int active = 0;
int updated = 0;
int uptime = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin(0x3a);
  Wire.onReceive(r);
  lcd.begin(16, 2);
  lcd.createChar(0, customChar);
  lcd.createChar(1, virus);
  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("India Status:");
  delay(lcdd);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.write(0);
  lcd.print(" fetching data");
  delay(lcdd);
  lcd.clear();
}

void loop() {
  if (x[0] == 99) {
    for (climit = 1; x[climit] != 116; climit++) {
    }
    if (x[climit] == 116) {
      for (tclimit = climit + 1; x[tclimit] != 100; tclimit++) {
      }
      if (x[tclimit] == 100) {
        for (dlimit = tclimit + 1 ; x[dlimit] != 114;    dlimit++) {
        }
        if (x[dlimit] == 114) {
          for (rlimit = dlimit + 1; x[rlimit] != 101; rlimit++) {
          }
          if (x[rlimit] == 101) {
            for (elimit = rlimit + 1; x[elimit] != 109; elimit++) {
            }
            if (x[elimit] == 109) {
              for (mlimit = elimit + 1; x[mlimit] != -1; mlimit++) {
              }
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < mlimit; i++) {
    int num = x[i];
    switch (num) {
      case 48: x[i] = 0;
        break;
      case 49: x[i] = 1;
        break;
      case 50: x[i] = 2;
        break;
      case 51: x[i] = 3;
        break;
      case 52: x[i] = 4;
        break;
      case 53: x[i] = 5;
        break;
      case 54: x[i] = 6;
        break;
      case 55: x[i] = 7;
        break;
      case 56: x[i] = 8;
        break;
      case 57: x[i] = 9;
        break;

    }
  }

  cases = 0;
  todaycases = 0;
  deaths = 0;
  recovered = 0;
  updated = 0;
  uptime = 0;
  for (int i = 1; i < climit; i++) {
    cases *= pow(10, 1);
    cases += x[i];
  }
  for (int i = climit + 1; i < tclimit; i++) {
    todaycases *= pow(10, 1);
    todaycases += x[i];
  }
  for (int i = tclimit + 1; i < dlimit; i++) {
    deaths *= pow(10, 1);
    deaths += x[i];
  }
  for (int i = dlimit + 1; i < rlimit; i++) {
    recovered *= pow(10, 1);
    recovered += x[i];
  }
  for (int i = rlimit + 1; i < elimit; i++) {
    updated *= pow(10, 1);
    updated += x[i];
  }
  for (int i = elimit + 1; i < mlimit; i++) {
    uptime *= pow(10, 1);
    uptime += x[i];
  }
  active = cases - deaths - recovered;
  //  Serial.println(cases);
  //  Serial.println(todaycases);
  //  Serial.println(deaths);
  //  Serial.println(recovered);
  //  Serial.println(active);
  //  Serial.println(updated);
  //  Serial.println(uptime);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("Total cases:");
  lcd.print(cases);
  delay(lcdd);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("Active: ");
  lcd.print(active);
  delay(lcdd);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("New cases: ");
  lcd.print(todaycases);
  delay(lcdd);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("Deaths: ");
  lcd.print(deaths);
  delay(lcdd);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("Recovered: ");
  lcd.print(recovered);
  delay(lcdd);

  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0, 1);
  lcd.print("updated:");
  lcd.print(updated);
  lcd.print("-");
  lcd.print(uptime);
  lcd.print("Hr");
  delay(lcdd);
}
void r() {
  if (Wire.available() <= 20) {
    x[0] = Wire.read();
    x[1] = Wire.read();
    x[2] = Wire.read();
    x[3] = Wire.read();
    x[4] = Wire.read();
    x[5] = Wire.read();
    x[6] = Wire.read();
    x[7] = Wire.read();
    x[8] = Wire.read();
    x[9] = Wire.read();
    x[10] = Wire.read();
    x[11] = Wire.read();
    x[12] = Wire.read();
    x[13] = Wire.read();
    x[14] = Wire.read();
    x[15] = Wire.read();
    x[16] = Wire.read();
    x[17] = Wire.read();
    x[18] = Wire.read();
    x[19] = Wire.read();
    x[20] = Wire.read();
    x[21] = Wire.read();
    x[22] = Wire.read();
    x[23] = Wire.read();
    x[24] = Wire.read();
  }
}
