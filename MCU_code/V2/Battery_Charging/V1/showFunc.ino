void showFunc(bool func){
  if (func){
    screen.clearDisplay();
    screen.setCursor(0,15);
    Serial.println("\n<Or REMOVE the power if finish using>\n");
    screen.setTextSize(1.05);
    screen.println("  REMOVE wire \n or RIGHT push  \n    to reselect");
    //reselect the function 
    screen.display();
    while (!Serial.available()&&analogRead(A1)<900);
  }

  
  screen.clearDisplay();
  screen.setCursor(0, 15); // (x,y)
  screen.setFont(&FreeSans9pt7b);
  screen.println("Please Select :");
  Serial.println("Please select a function below");
  screen.setFont(&FreeSansBold9pt7b);
  screen.println("1. Get Voltage");
  Serial.println("1. Get battery voltage");
  screen.setFont(&FreeSans9pt7b);
  screen.println("2. Charge\n");
  Serial.println("2. Let battery charge");
  screen.display();
  buzzer(50,1);
  buzzer(150,1);
  delay(500);
}
