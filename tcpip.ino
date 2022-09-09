void tcpip(){
    Serial.print("Send Data to ");
    Serial.println(host);
    WiFiClient client;
    
    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        return;
    }
    client.print(sendtag);
    client.stop();
}
