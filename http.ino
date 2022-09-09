void getmethod(){
  if ((WiFi.status() == WL_CONNECTED)) { 
    //URL Push Data
    status_tombol();
    input_data();
    status_get();
    
    if(record == "Record" && payload == "rejected"){
      Serial.println("Data Kembar, Barang diperbolehkan Masuk");
      digitalWrite(alert, LOW);
    }

    if(record == "Record" && payload == "sukses"){
      Serial.println("Data Baru, Barang diperbolehkan Masuk");
      digitalWrite(alert, LOW);
    }

    if(record == "UNRecord" && rilis == "UNRelease" && payload == "rejected"){
      Serial.println("Data Baru, Barang Tidak diizinkan Masuk");
      Serial.println("Alarm Dinyalakan");
      digitalWrite(alert, HIGH);
      delay(5000);
    }

    //Logika Rilis
    if(rilis == "Release" && payload3 == "terhapus") {
      Serial.println("Data Kembar, Barang diperbolehkan Keluar");
      digitalWrite(alert, LOW);
    }

    if(rilis == "Release" && payload3 == "witing") {
      Serial.println("Menunggu Konfirmasi Release");
      digitalWrite(alert, LOW);
    }

    if(rilis == "UNRelease" && record == "UNRecord" && payload3 == "witingEr"){
      Serial.println("Barang Tidak diizinkan Keluar");
      Serial.println("Alarm Dinyalakan");
      digitalWrite(alert, HIGH);
      delay(5000);
    }
  }
}
