#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "esp";
const char* password = "123456789";
const char* backendHost = "192.168.43.50";
const int backendPort = 5500;

ESP8266WebServer server(80);

struct Light {
  String id;
  int pin;
};

Light lights[] = {
  {"1", D1},
  {"2", D2},
  {"3", D3},
};
const int numLights = sizeof(lights) / sizeof(lights[0]);

void turnLightOn(String lightid) {
  for (int i = 0; i < numLights; i++) {
    if (lights[i].id == lightid) {
      digitalWrite(lights[i].pin, HIGH);
      Serial.printf("Lampu %s dinyalakan.\n", lightid.c_str());
    }
  }
}

void turnLightOff(String lightid) {
  for (int i = 0; i < numLights; i++) {
    if (lights[i].id == lightid) {
      digitalWrite(lights[i].pin, LOW);
      Serial.printf("Lampu %s dimatikan.\n", lightid.c_str());
    }
  }
}

void handleLightOn() {
  String lightid = server.arg("lightid");
  turnLightOn(lightid);
  server.send(200, "text/plain", "OK");
}

void handleLightOff() {
  String lightid = server.arg("lightid");
  turnLightOff(lightid);
  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < numLights; i++) {
    pinMode(lights[i].pin, OUTPUT);
    digitalWrite(lights[i].pin, LOW);
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menyambungkan ke WiFi...");
  }
  Serial.println("Terhubung ke WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (!MDNS.begin("esp8266")) {
    Serial.println("Gagal setup mDNS!");
    while (1) delay(1000);
  }
  Serial.println("mDNS aktif: http://esp8266.local");

  server.on("/lights/on", HTTP_POST, handleLightOn);
  server.on("/lights/off", HTTP_POST, handleLightOff);
  server.begin();
  Serial.println("HTTP server lokal aktif");
}

void loop() {
  server.handleClient();
  MDNS.update();

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient client;
    String url = "http://" + String(backendHost) + ":" + String(backendPort) + "/light/on";
    http.begin(client, url);
    int httpCode = http.GET();

    if (httpCode == 200) {
  String payload = http.getString();
  Serial.println("Respon dari backend:");
  Serial.println(payload);

  StaticJsonDocument<512> doc;
  DeserializationError error = deserializeJson(doc, payload);

  if (!error) {
    JsonArray arr = doc.as<JsonArray>();

    for (JsonObject obj : arr) {
      String lightid = String(obj["lightid"].as<int>());
      String status = obj["status"].as<String>();

      if (status == "on") {
        turnLightOn(lightid);
      } else {
        turnLightOff(lightid);
      }
    }
  } else {
    Serial.print("Gagal parsing JSON: ");
    Serial.println(error.c_str());
  }
} else {
  Serial.printf("HTTP GET gagal, kode: %d\n", httpCode);
}

    http.end();
  }

  delay(5000);
}
