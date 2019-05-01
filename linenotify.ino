void Line_Notify(String message) ;

#include <ESP8266WiFi.h>
#include <WiFiClientSecureAxTLS.h> // กรณีขึ้น Error ให้เอาบรรทัดนี้ออก
#include <SoftwareSerial.h>
// Config connect WiFi
#define WIFI_SSID "iPhone ของ Pimwaree"
#define WIFI_PASSWORD "sspimmmm"

// Line config
#define LINE_TOKEN "y7RgtjbzOo1JfJRWHRzch3NxAOhMQSsKmBXErTmv25r"

#define SW D2
SoftwareSerial NodeSerial(D0, D1); // RX | TX

String message = "โจรเข้าบ้านแล้ว!!1"; // ArduinoIDE เวอร์ชั่นใหม่ ๆ ใส่ภาษาไทยลงไปได้เลย

void setup() {
  pinMode(D0, INPUT);
  pinMode(D2, INPUT);
  pinMode(D1  , OUTPUT);
  Serial.begin(115200);
  NodeSerial.begin(4800);

  Serial.begin(9600);

  WiFi.mode(WIFI_STA);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
}

void loop() {
    if (digitalRead(D2)==1){
    Serial.println("Enter !");
    Line_Notify(message);
    // Serial.println();
    delay(10);
  }
}
  

void Line_Notify(String message) {
  axTLS::WiFiClientSecure client; // กรณีขึ้น Error ให้ลบ axTLS:: ข้างหน้าทิ้ง

  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;   
  }

    String req = "";
    req += "POST /api/notify HTTP/1.1\r\n";
    req += "Host: notify-api.line.me\r\n";
    req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
    req += "Cache-Control: no-cache\r\n";
    req += "User-Agent: ESP8266\r\n";
    req += "Connection: close\r\n";
    req += "Content-Type: application/x-www-form-urlencoded\r\n";
    req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
    req += "\r\n";
    req += "message=" + message;
    // Serial.println(req);
    client.print(req);
      
    delay(20);
  
    // Serial.println("-------------");
    while(client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        break;
      }
      //Serial.println(line);
    }
    // Serial.println("-------------");
  }
