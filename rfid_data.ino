void rfidData()
{
      int j=0;
      
      dt[j]="";
      for(i=1;i<dataIn.length();i++)
      {
        dt[j] = dt[j] + dataIn[i];
      }

      RFIDTAG = dt[0];
      
      rfidtag = "{\"Device_ID\":\"34532\",\"tag\":\"'";
      rfidtag += RFIDTAG;
      rfidtag += "'\",\"tahun\":2022}";
      rfidtag.remove(29,1);
      rfidtag.remove(50,1);
      rfidtag.remove(49,1);
      
      sendtag = rfidtag.c_str();
      
      Serial.print("RFID TAG : ");
      Serial.print(sendtag);
      Serial.print("\n\n");
}
