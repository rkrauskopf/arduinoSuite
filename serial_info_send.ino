#define numberOfBytes 4
boolean isConnected = true;

void setup(){
  Serial.begin(9600);
  
  //Make sure that the arduino is connect to a valid usb port that
  //is receiving our data
  //establishContact();
}

#define numberOfBytes 4
void loop(){
  /*
  char salutation[numberOfBytes];
  
  while((Serial.available() > numberOfBytes) && !isConnected) {
    Serial.print("inside the initial while loop peek returns: ");
    Serial.println(Serial.peek());
    
    if (Serial.peek() == 0) { //send a 0 before your string as a start byte      
      Serial.read();
      for (byte i = 0; i < numberOfBytes; i++) {
        salutation[i] = Serial.read();
      }
      if (salutation == "hello") {
        isConnected = true;
        Serial.println("Hello! I found you!");
      }
    }
  }
  */
  
  if(isConnected) {
    
    /*
      Arduino has trouble concatenating string of different value types
        (Ex.) String x = int + string 
        gives unexpected results so an int input value needs to be cast a string before
        being concatenated into the serial string being sent over the wire.
    */
    String inputA = String(random(0, 10));
    String inputB = String(random(20,200));
    String inputC = String(random(0, 100));
    
    String jsonString = "{ 'input1': }";
    
    String closingTag = ",";
    
    String serialString = "{\"input 1\" :" + inputA + ",";
    serialString += " \"input 2\" : " + inputB + ",";
    serialString += "\"input 3\" : " + inputC + "}";
    
    Serial.println(serialString);
    
  }
  
  //30 second delay
  delay(60000);  
}
