void status_tombol(){
    //URL GET Response=================================================================================
    HTTPClient http;
    const char* sendurl2 = "http://alicestech.com/alicestech.com/warehouse/api/Api?id=RFID007";
    Serial.println(sendurl2);
    
    http.begin(sendurl2); 
    int httpCode2 = http.GET();                                      
 
    if (httpCode2 > 0) { 
 
        payload2 = http.getString();
        Serial.println(httpCode2);
        Serial.println(payload2);
        Serial.println();
          //Parsing Mulai
          parsingData();
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
    http.end(); 
}
