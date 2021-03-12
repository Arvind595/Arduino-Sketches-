#include<LiquidCrystal.h>
#include <SPI.h>
#include<Wire.h>
LiquidCrystal lcd(9);
#define lcdd 100
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

void setup() {
  lcd.begin(16, 2);
  lcd.home();
  lcd.createChar(0, customChar);
  lcd.createChar(1, virus);
  lcdloading();
  Serial.begin(115200);
  Wire.begin(0x3a);
  Wire.onReceive(r);
  for (int i = 0; i < 100; i++) {
    x[i] = -1;
  }

  //x[0]=99;
  //x[1]=54;
  //x[2]=54;
  //x[3]=53;
  //x[4]=116;
  //x[5]=56;
  //x[6]=100;
  //x[7]=49;
  //x[8]=51;
  //x[9]=114;
  //x[10]=52;
  //x[11]=51;
  //x[12]=101;
  //x[13]=50;
  //x[14]=54;
  //x[15]=109;
  //x[16]=49;
  //x[17]=51;
  //x[18]=52;
  //x[19]=-1;
}
void loop() { 
  convert();
  updatelcd();
  
  //  for (int i = 0; i < bytelength; i++) {
  //    Serial.print(x[i]);
  //  }
  //  Serial.println();
}

void updatelcd() {
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
void lcdloading() {
  lcd.clear();
  lcd.home();
  lcd.print("--");
  lcd.write(1);
  lcd.print("-COVID-19-");
  lcd.write(1);
  lcd.print("--");

  lcd.setCursor(0,1);
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

}

void convert() {

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
  len_cases = climit - 1;
  len_today = tclimit - climit - 1;
  len_death = dlimit - tclimit - 1;
  len_reco = rlimit - dlimit - 1;
  len_date = elimit - rlimit - 1;
  len_time = mlimit - elimit - 1;
  len_payload = mlimit;
  //
  Serial.println(climit);
  Serial.println(tclimit);
  Serial.println(dlimit);
  Serial.println(rlimit);
  Serial.println(elimit);
  Serial.println(mlimit);
  aschi();
  combine();
  //Serial.println(len_cases);
  //Serial.println(len_today);
  //Serial.println(len_death);
  //Serial.println(len_reco);
  //Serial.println(len_date);
  //Serial.println(len_time);
  //Serial.println(len_payload);

}
void aschi() {
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
}
void combine() {
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
  Serial.println(cases);
  Serial.println(todaycases);
  Serial.println(deaths);
  Serial.println(recovered);
  Serial.println(active);
  Serial.println(updated);
  Serial.println(uptime);
}
//data format from esp
//"India case 665 today 8 death 13 recov 43 update 03/26 13:50"
//c665t8d13r43e26m13
//99 54 54 53 116 56 100 49 51 114 52 51 101 50 54 109 49 51 -1 -1
//'c'+cases+'t'+todaycases+'d'+deaths+'r'+recovered+'e'+date+'m'+timie
