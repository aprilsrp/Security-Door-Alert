
//#include <EEPROM.h>
#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>
//#include <WiFiClientSecureAxTLS.h> // กรณีขึ้น Error ให้เอาบรรทัดนี้ออก

#define WIFI_SSID "iPhone ของ Pimwaree"
#define WIFI_PASSWORD "sspimmmm"
#define LINE_TOKEN "y7RgtjbzOo1JfJRWHRzch3NxAOhMQSsKmBXErTmv25r"

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(9,8, 5, 4, 3, 2);
Servo myservo;

String real_password = "1234";
String message = "You fail to unlock 3 times. If it isn't you call the cop.";
char input_password[4];
int inputpassCount = 0;
int wrongCount = 0;

int buzzer = 11;

//String LINE_TOKEN = "FYci58hhEplaMRtGZmao2XTdDGggDbnKnc1Fr3v1glN";

void setup(){
  // set up the LCD's number of columns and rows:
//  pinMode(D2, INPUT);
//  pinMode(D3, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("He");
  lcd.print("llo");
  lcd.print('9');
  lcd.print("1");
  myservo.attach(10);
  myservo.write(0);
  pinMode(buzzer, OUTPUT);
//  lcd.setCursor(0,1);
//  WiFi.begin(WIFI_SSID, WIFI_PASS);
//  while (WiFi.status() != WL_CONNECTED) {
//  Serial.print(".");
//  delay(500);
//}
//Serial.println();
//Serial.print("connected: ");
//Serial.println(WiFi.localIP());
  pinMode(A0, OUTPUT);
}
void loop(){
  Serial.println(analogRead(A0));
  char key = keypad.getKey();
  if (key != NO_KEY){
    lcd.print(key);
    if (key == '*' && inputpassCount >= 4) {
      // When User Enter
      Serial.println();
      if (real_password.equals(get_password_string())) {
        lcd.clear();
        lcd.println("Password Correct");
        wrongCount = 0;
        unlock();
      } else {
        Serial.println("Password Wrong");
        wrongCount++;
        if (wrongCount >= 3) {
          // Alert Here
          analogWrite(A0, 1023);
          Serial.println(analogRead(A0));
          delay(1000);
          analogWrite(A0, 0);
          alert();
          wrongCount = 0;
        }
      }
      Serial.print("INSERT Password : ");
      inputpassCount = 0;
    } else if (key == '#' && inputpassCount > 0) {
      inputpassCount--;
      Serial.println();
      Serial.print("INSERT Password : ");
      Serial.print(get_password_string());
    } else if (key == 'D') {
      inputpassCount = 0;
      Serial.println();
      Serial.print("INSERT Password : ");
    } else if (inputpassCount < 4 && key != 'A' && key != 'B' && key != 'C' && key != '#' && key != '*') {
      Serial.print(key);
      input_password[inputpassCount] = key;
      inputpassCount++;
    }
  }
}

String get_password_string() {
  String merged = "";
  for(int i=0; i<inputpassCount; i++) {
    merged += input_password[i];
  }
  return merged;
}

void unlock() {
  myservo.write(90);
  delay(4000);
  myservo.write(0);
}

//void Line_Notify(String message) {
//  axTLS::WiFiClientSecure client; // กรณีขึ้น Error ให้ลบ axTLS:: ข้างหน้าทิ้ง
//
//  if (!client.connect("notify-api.line.me", 443)) {
//    Serial.println("connection failed");
//    return;   
//  }
//  String req = "";
//  req += "POST /api/notify HTTP/1.1\r\n";
//  req += "Host: notify-api.line.me\r\n";
//  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
//  req += "Cache-Control: no-cache\r\n";
//  req += "User-Agent: ESP8266\r\n";
//  req += "Connection: close\r\n";
//  req += "Content-Type: application/x-www-form-urlencoded\r\n";
//  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
//  req += "\r\n";
//  req += "message=" + message;
//  // Serial.println(req);
//  client.print(req);
//    
//  delay(20);
//
//  // Serial.println("-------------");
//  while(client.connected()) {
//    String line = client.readStringUntil('\n');
//    if (line == "\r") {
//      break;
//    }
//    //Serial.println(line);
//  }
//  // Serial.println("-------------");
//}

void alert() {
  tone(buzzer, 100);
  delay(100);
  tone(buzzer, 400);
  delay(100);
  tone(buzzer, 700);
  delay(100);
  tone(buzzer, 1000);
  delay(3000);
  noTone(buzzer);
}


// initialize the library with the numbers of the interface pins

 

 
