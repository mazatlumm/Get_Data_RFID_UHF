#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid     = "RFID";
const char* password = "uhfreader";
const char* host = "192.168.43.88";
const int port = 8088;

//Alarm
int alert = 19;

String device_id = "ERK32";
String dataIn, RFIDTAG;
String dt[10];
String rfidtag = "";
const char* sendtag = "";
int i;
boolean parsing=false;

String payload, payload2, payload3, id_device, record, rilis;
const char* data_record ="";
const char* data_rilis = "";

String dt1[10];

void setup() 
{
    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1);
    pinMode(alert, OUTPUT);
    digitalWrite(alert, LOW);
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected with IP address: ");
    Serial.println(WiFi.localIP());
    
    dataIn="";
}
 
void loop() 
{
     if(Serial2.available()>0)
     {
           char inChar = (char)Serial2.read();
           dataIn += inChar;
           if (inChar == '\n') {parsing = true;}
     }
     if(parsing)
     {
           rfidData();
           getmethod();
           parsing=false;
           dataIn="";
     }
}
