void status_get(){
  //URL Response=================================================================================
    HTTPClient http;
    String urlgo3 = "http://localhost/smart-warehouse/my_api/main.php?device_id=RFID001&kode_scan=";
    urlgo3 += RFIDTAG;
    urlgo3.remove(69,1);
    urlgo3.remove(89,2);

    const char* sendurl3 = urlgo3.c_str();
    Serial.println(sendurl3);
    
    http.begin(sendurl3); 
    int httpCode3 = http.GET();                                      
 
    if (httpCode3 > 0) { 
 
        payload3 = http.getString();
        Serial.println(httpCode3);
        Serial.println(payload3);
        Serial.println();
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); 
}
