void parsingData()
{
      int j=0;
      Serial.print("data masuk : ");
      Serial.print(payload2);
      Serial.print("\n");
      dt1[j]="";
      for(i=1;i<payload2.length();i++)
      {
             if ((payload2[i] == '#') || (payload2[i] == ','))
             {
                   j++;
                  dt1[j]=""; 
             }
             else
             {
                  dt1[j] = dt1[j] + payload2[i];
             }
      }

      id_device = dt1[0];
      rilis = dt1[1];
      record = dt1[2];
      
}
