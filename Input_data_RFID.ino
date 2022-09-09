void input_data(){
    HTTPClient http;
    String urlgo = "http://alicestech.com/alicestech.com/warehouse/api/Api/data?code=RFID007&barang=";
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
