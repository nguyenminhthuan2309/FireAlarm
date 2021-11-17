#include <FirebaseESP8266.h>
//#include <FirebaseArduino.h>

#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://fire-alarm-61203-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QFIpDYBNkgGhxD74kcBJEbPDBCMCFbfD6WiGcLjI"
#define ssid "Sushi"
#define pass "20042020"
FirebaseData firebaseData;

//void notifyOnFire()
//{
// int isButtonPressed=analogRead(D1);
// if(isButtonPressed==1)
// {
//  Serial.println("FIRE DETECTED");
//  Firebase.setInt("FireStatus",0);
//  delay(1000);
// } 
// else if (isButtonPressed==0)
// {
//  Firebase.setInt("FireStatus",1);
//  delay(1000);
// }
//}
void setup()
{
 Serial.begin(9600);
 pinMode(D1, INPUT_PULLUP);
 while (WiFi.status() != WL_CONNECTED)
 {
  Serial.print(".");
  delay(500);
 }  
 Serial.println();
 Serial.print("connected: ");
 Serial.println(WiFi.localIP());

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop()
{
 int sensorVal=analogRead(D1);
 if(sensorVal ==1023)
 {
  Serial.print(".");
  Firebase.setInt(firebaseData,"/FireStatus",1);
  delay(1000);
 }
 else if(sensorVal==0)
 {
  Serial.println("FIRE DETECTED");
  Firebase.setInt(firebaseData,"/FireStatus",0);
  delay(1000);
 }
 delay(1000); 
}
