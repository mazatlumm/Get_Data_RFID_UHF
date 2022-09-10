void getmethod(){
  if ((WiFi.status() == WL_CONNECTED)) { 
    HTTPClient http;
    String urlgo = "http://localhost/smart-warehouse/my_api/main.php?device_id=RFID001&kode_scan=";
    urlgo += RFIDTAG;
    urlgo.remove(80,1);
    urlgo.remove(100,3);

    const char* sendurl = urlgo.c_str();
    Serial.println(sendurl);
    
    http.begin(sendurl); 
    int httpCode = http.GET();                                      
 
    if (httpCode > 0) { 
 
        payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        Serial.println();
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
    http.end(); 
  }
}
