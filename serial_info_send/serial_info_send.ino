#define numberOfBytes 5
boolean isConnected = false;

void setup(){
  Serial.begin(9600);
  
  //Make sure that the arduino is connect to a valid usb port that
  //is receiving our data
  //establishContact();
}

#define numberOfBytes 4
void loop(){
    
  String content = "";
  char character;
  
  while(Serial.available() && !isConnected) {
      character = Serial.read();
      content.concat(character);
    
      if (content == "hello") {
        isConnected = true;
        Serial.println("Found you!");
      }
  }
  
  if (content != "") {
    Serial.println(content);
  }
  
  
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
    
    String serialString = "{\"input 1\" :" + inputA + ",";
    serialString += " \"input 2\" : " + inputB + ",";
    serialString += "\"input 3\" : " + inputC + "}";
    
    Serial.println(serialString);
    //30 second cycle if a connection is detected.
    delay(30000);
  }
  
  //2 second delay if arduino connection not deteted.
  delay(2000);  
}
