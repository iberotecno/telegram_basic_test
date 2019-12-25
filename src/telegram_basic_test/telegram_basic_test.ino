/*******************************************************************
Iberotecno
Telegram send message basic test for ESP32
*******************************************************************/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#define CHAT_ID "Your chat ID"
int acu = 0;

// Initialize Wifi connection to the router
char ssid[] = "Your wifi name";     // your network SSID (name)
char password[] = "Your wifi pass"; // your network key

// Initialize Telegram BOT
#define BOTtoken "Your Bot Token here"  // your Bot Token (Get from Botfather)
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
int Bot_mtbs = 1000; //mean time between scan messages
long Bot_lasttime;   //last time messages' scan has been done

void setup() {
  Serial.begin(115200);
  }

void loop() {
    // Attempt to connect to Wifi network:
    Serial.print("Conectando a Wifi: ");
    Serial.println(ssid);
    // Set WiFi to station mode and disconnect from an AP if it was Previously
    // connected
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      acu++;
      if (acu == 10) { //restart board if connection to wifi is not successful and retry
       ESP.restart();
      }
      delay(500);
    }
    Serial.println("");
    Serial.println("Conectado a Wifi.");
    Serial.print("Direccion IP: ");
    Serial.println(WiFi.localIP());
    String mi_ip = WiFi.localIP().toString();
    delay(1000);
    String message = "Mensaje de pruebas";
    if (bot.sendMessage(CHAT_ID, message, "Markdown")) {
          }
    else {
      Serial.println("Fallo TELEGRAM");
    }
 delay(20000); //await for 20 seconds for no flooding messages
}
