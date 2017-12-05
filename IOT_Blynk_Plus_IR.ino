#define BLYNK_PRINT Serial

#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <IRremote.h> // including infrared remote header

int IRpin = 11;  // pin for the IR sensor
//int pResistor = A5; // Photoresistor at Arduino analog pin A0
int LIGHT1 = 4;    // LIGHT1 pin 
int LIGHT2 = 5;    // LIGHT2 pin 
int LIGHT3 = 6;    // LIGHT3 pin 
int LIGHT4 = 7;    // LIGHT4 pin
int LIGHT5 = 8;    // LIGHT5 pin  
int value;        // variable
IRrecv irrecv(IRpin);
decode_results results;

boolean LIGHTon = true; // initializing LIGHTon as true

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "key";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ID";
char pass[] = "Password";

// Hardware Serial on Mega, Leonardo, Micro...
#define EspSerial Serial1


// Your ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup()
{
  // Debug console
  Serial.begin(9600);

  delay(10);
  irrecv.enableIRIn(); // Start the receiver
//  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input
  pinMode(LIGHT1, OUTPUT); // initializing pin as output pin
  pinMode(LIGHT2, OUTPUT); // initializing pin as output pin
  pinMode(LIGHT3, OUTPUT); // initializing pin as output pin
  pinMode(LIGHT4, OUTPUT); // initializing pin as output pin
  pinMode(LIGHT5, OUTPUT); // initializing pin as output pin
  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  
  Blynk.begin(auth, wifi, ssid, pass);
  
}

void loop()
{
  
 /*  if(pResistor<25)
  {
    digitalWrite(LIGHT5, HIGH);
  }
  if(pResistor>25)
  {
    digitalWrite(LIGHT5, LOW);
  } */
  
  /////////////////////////////////////////////
  if (irrecv.decode(&results)) 
    {
      
      irrecv.resume();   // Receive the next value
      
    }

   if (results.value == 16724175)  // For turning 1st light ON/OFF by pressing " 1 " 9b5cb5e620504751b9c2fa4a5f22a885 on remote
     {
      
       if (LIGHTon == true)   // is LIGHTon equal to true? 
         {
          
           LIGHTon = false;  
            
           digitalWrite(LIGHT1, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            
            LIGHTon = true;
            digitalWrite(LIGHT1, LOW);
            delay(100);
            
          }
          
     }
     
     if (results.value == 16718055)  // For turning 2nd light ON/OFF by pressing " 2 " 9b5cb5e620504751b9c2fa4a5f22a885 on remote
     {
      
       if (LIGHTon == true)   // is LIGHTon equal to true? 
         {
          
           LIGHTon = false;   
           digitalWrite(LIGHT2, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            
            LIGHTon = true;
            digitalWrite(LIGHT2, LOW);
            delay(100);
            
          }
          
     }
     if (results.value == 16743045)  // For turning 3rd light ON/OFF by pressing " 3 " 9b5cb5e620504751b9c2fa4a5f22a885 on remote
     {
      
       if (LIGHTon == true)   // is LIGHTon equal to true? 
         {
          
           LIGHTon = false;   
           digitalWrite(LIGHT3, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            
            LIGHTon = true;
            digitalWrite(LIGHT3, LOW);
            delay(100);
            
          }
          
     }
     if (results.value == 16716015)  // For turning 4th light ON/OFF by pressing " 4 " 9b5cb5e620504751b9c2fa4a5f22a885 on remote
     {
        
       if (LIGHTon == true)   // is LIGHTon equal to true? 
         {
         
           LIGHTon = false;   
           digitalWrite(LIGHT4, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
           
            LIGHTon = true;
            digitalWrite(LIGHT4, LOW);
            delay(100);
            
          }
          
     }
     if (results.value == 16738455)  // for turning all light ON/OFF by pressing " 0 " 9b5cb5e620504751b9c2fa4a5f22a885 on remote
     {
      
       if (LIGHTon == true)   // is LIGHTon equal to true? 
         {
          
           LIGHTon = false;  
           digitalWrite(LIGHT1, HIGH);
           digitalWrite(LIGHT2, HIGH);
           digitalWrite(LIGHT3, HIGH); 
           digitalWrite(LIGHT4, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            
            LIGHTon = true;
            digitalWrite(LIGHT1, LOW);
            digitalWrite(LIGHT2, LOW);
            digitalWrite(LIGHT3, LOW);
            digitalWrite(LIGHT4, LOW);
            delay(100);
            
          }
          
     }
/////////////////////////////////////////////////

   Blynk.run();

}
