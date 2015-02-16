#define numberOfBytes 5
boolean isConnected = false;

void setup(){
  Serial.begin(9600);
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
  
  delay(2000);  
}
