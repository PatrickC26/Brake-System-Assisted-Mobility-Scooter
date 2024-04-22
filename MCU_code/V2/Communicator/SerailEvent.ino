void SerialEvent(){
//  Serial.println("SEIN");
  if (Serial.available()){
    char in = Serial.read();
    Serial.print(in);
    if (in == 'A'){
      bool requestRader= bool (Serial.parseInt());
      if (requestRader) {
//        Serial2.println("A1");
//        Serial3.println("A1");
        Serial4.println("A1");
        Serial2.println("A1");
      }
      else {
//        Serial2.println("A0");
//        Serial3.println("A0");
        Serial4.println("A0");
        Serial2.println("A0");
      }
    }
    else if (in == '@') {
      digitalWrite(MP,0);
      Serial2.println('@');
    }
    else if (in == '#') {
      digitalWrite(MP,1);
      Serial.println('#');
    }
    else if (in == '?') {
      SDWrite("Computer Connected");
      int YYYY = Serial.parseInt();
      int MM = Serial.parseInt();
      int DD = Serial.parseInt();
      int HH = Serial.parseInt();
      int mm = Serial.parseInt();
      int SS = Serial.parseInt();
      rtc.adjust(DateTime(YYYY,MM,DD,HH,mm,SS));   // would set to February 28, 2015 at 14:50:00 (2:50pm)
    }
    else if (in == 'E') {
      int frontBrakeForce = Serial.parseInt();
      Serial2.print("E");
      Serial2.println(frontBrakeForce);
      Serial.println(frontBrakeForce);
    }
    else if (in == 'D') {
      int backBrakeForce = Serial.parseInt();
      Serial2.print("D");
      Serial2.println(backBrakeForce);
    }
    else if (in == 'M') {
      int CTRLP = Serial.parseInt();
      Serial7.print('X');
      Serial7.println(CTRLP);
    }
  }

  if (Serial1.available()) {
    char in = Serial1.read();
//    Serial.println(in);
    if (in == '?') {
      SDWrite("Bluetooth Connected");
      int YYYY = Serial1.parseInt();
      int MM = Serial1.parseInt();
      int DD = Serial1.parseInt();
      int HH = Serial1.parseInt();
      int mm = Serial1.parseInt();
      int SS = Serial1.parseInt();
      rtc.adjust(DateTime(YYYY,MM,DD,HH,mm,SS));   // would set to February 28, 2015 at 14:50:00 (2:50pm)
      String time = ""+String(YYYY)+":"+String(MM)+":"+String(DD)+":"+String(HH)+":"+String(mm)+":"+String(SS);
      Serial.println(time);
      delay(200);
      Serial1.print('='); 
//      delay(100);
//      Serial1.print('='); 
//      delay(100);
//      Serial1.print('='); 
//      delay(100);
//      Serial1.print('='); 
      bluetoothStatus = 5;
    }
    else if (in == '@') {
      digitalWrite(MP,0);
      Serial.println('@');
    }
    else if (in == '#') {
      digitalWrite(MP,1);
      Serial.println('#');
    }
//    else if (in == '='){
//      bluetoothStatus = Serial1.parseInt();
//      if (bluetoothStatus!=5) digitalWrite(MP,1);
//      else digitalWrite(MP,0);
//      Serial.print("W");
//      Serial.println(bluetoothStatus);
//    }
  }

  if (Serial2.available()){
    char in = Serial2.read();
    String F = "F";
    if (in == 'E'){
      int frontBrakeForce = Serial2.parseInt();
      Serial.print("E");
      Serial.print(frontBrakeForce);
      Serial.println(' ');
    }
    else if (in == 'D') {
      int backBrakeForce = Serial2.parseInt();
      Serial.print("D");
      Serial.print(backBrakeForce);
      Serial.println(' ');
    }
    else if (in == 'F'){
      if (Serial2.available()){
        char a = Serial2.read();
        F += a;
      }
      Serial.println(F);
    }
  }

//  Serial4.listen(); 
  if (Serial4.available()){
    char in = Serial4.read();
//    Serial.println(in);
    if (in == 'C'){
      float disB = Serial4.parseFloat();
      String C ="C "+String(disB);
      Serial.println(C);
      if (disB>100) {
        Serial1.print("Z1b|");
        S1T = millis();
      }
    }
    else if (in == 'G'){
      int tiltA = Serial4.parseInt();
      String G = "G" + tiltA ;
      Serial.print(G);
    }
    else if (in == 'I'){
      int RiseA = Serial4.parseInt();
      String I = "I" + RiseA ;
      Serial.print(I);
      Serial2.print(I);
    }
    else if (in == 'A'){
      int Acc = Serial4.parseInt();
      String A = "A" + Acc ;
      Serial.print(A);
    }
    else if (in == 't'){
      int temp = Serial4.parseInt();
      Serial.print("t");
      Serial.println(temp);
    }
  }

  if (Serial3.available()){
    char in = Serial3.read();
//    Serial.println(in);
    if (in == 'V'){
      nowSpeed = Serial3.parseFloat();
//      Serial.println(nowSpeed);
      String send = "V" + String(nowSpeed)+' ';
      Serial.println(send);
      Serial1.print('V');
      Serial1.print(int(nowSpeed));
      Serial1.print('|');
//      Serial7.print(send);
    }
  }

  
  if (millis() - S1T < 1000){
    Serial1.print("Z0|");
    Serial1.print("Y0|");
    Serial1.print("X0|");
  }



  //======SEND======
  Serial6.print('B');
  Serial6.print(BP);
  Serial6.print('T');
  Serial6.print(MT);
  Serial6.print('S');
  Serial6.print(nowSpeed);
  Serial2.print('V');
  Serial2.println(nowSpeed);
//  Serial6.print('E');
//  Serial6.print(errC.length());
//  Serial6.print(errC);
//  Serial.println("SEOUT");
}