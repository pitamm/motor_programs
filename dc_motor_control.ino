const int pwm = 3 ;  //initializing pin 2 as pwm
const int in_1 = 7 ;
const int in_2 = 8 ;
const int potentiometerPin = A2;
const int start_button = 4;
const int reverse_button = 5;
const int safety_button = 6;
int start_variable =0;


void setup()
  {
      pinMode(pwm,OUTPUT) ;   //we have to set PWM pin as output
      pinMode(in_1,OUTPUT) ;  //Logic pins are also set as output
      pinMode(in_2,OUTPUT) ;
      Serial.begin(9600);
      Serial.println(".........................DC MOTOR CONTROL................................");
      Serial.println("Type A for motor forward or C for motor reverse and press ENTER .");
  }

void loop()
{

     ////////////////////////////////function to calculate potentiometer value////////////////////////////////////////////////////
    int potentiometerValue()
       {
        int val = analogRead(potentiometerPin);
        return val;
       }    

       int potValue = potentiometerValue();
      int speed_val = map(potValue, 0, 1023, 0, 255);   // sets the value (range from 0 to 255):
      
      /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


      
      if(Serial.available()>0)
      {
      start_variable = Serial.read();
      }
      
      
      
      if(start_variable==65 || start_variable==97)          //check if A is sent
     {
      Serial.println("Command sent to Driver Module");
      Serial.println("forward motor...");
    //For Clock wise motion , in_1 = High , in_2 = Low
        
        digitalWrite(in_1,HIGH) ;
        digitalWrite(in_2,LOW) ;
        analogWrite(pwm,speed_val) ;
        delay(3000);
    
    //For brake
       digitalWrite(in_1,HIGH) ;
       digitalWrite(in_2,HIGH) ;
       delay(1000) ;
    }
    
      else if(start_variable==67 || start_variable==99)      //if C is sent
       {
          Serial.println("Command sent to Driver Module");
          Serial.println("reverse motoring...");
        //For Clock wise motion , in_1 = High , in_2 = Low
        
          digitalWrite(in_1,LOW) ;
          digitalWrite(in_2,HIGH) ;
          analogWrite(pwm,speed_val) ;
          delay(3000);
        
        //For brake
           digitalWrite(in_1,HIGH) ;
           digitalWrite(in_2,HIGH) ;
           delay(1000) ;
      }

     

}   
