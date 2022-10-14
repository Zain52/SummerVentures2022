//int IRSensor = 6;
//int IRTransmitter = 5;

//resistors used for IRsensor and transmitter: 98.8 ohms, 98.1 ohms, respectively

//Constants
const int pResistor = A0; // Photoresistor at Arduino analog pin A0
const int thermistor = A1;
//const int IRSensor = A2;
//const int pResistor3 = A3;
//const int pResistor4 = A4;
//const int pResistor5 = A5;
const int ledPin=9;       // Led pin at Arduino pin 9

//Variables
int IRreading;
int value;          // Store value from photoresistor (0-1023)
float val0;
float val1;
float vol = 0.0048828125; // 5 volts/1024
float actvol0;
float actvol_0;
float actvol1;
float actvol_1;
//float cur = 0.0028409091; // 0.625 (max voltage for photoresistor)/220 ohms (value of resistor used)
float curpResistor = 0.00025; //5 volts/10k ohm resistor + 10k ohm for photoresistor
//float curthermistor = 0.00014; //2.8 volts/10k ohm resistor + 10k ohm for thermistor
float actrespResistor;
float actresthermistor;
int ThermistorPin = 1;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup(){
 pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
 //pinMode(IRSensor, INPUT);
 //pinMode(IRTransmitter, INPUT);
 Serial.begin(9600);
 //  val = analogRead(pResistor);
 //  for (int i = 0; i<4; i++){
 //   calc += actvol;
 //   delay(250);
  }
  
//  avgvolt = calc/4;
//  Serial.println("Average Voltage ");
//  Serial.println(avgvolt);

void loop(){
//value = analogRead(pResistor);
//int sensorValue = analogRead(pResistor);

  //You can change value "25"
//  if (value > 25){
//    digitalWrite(ledPin, LOW);  //Turn led off
//  }
//  else{
//    digitalWrite(ledPin, HIGH); //Turn led on
//  }

//  delay(250); //Small delay

val0 = analogRead(pResistor);
actvol0 = val0*vol;
actvol_0 = 5 - actvol0;
Serial.println(actvol0, 3);
actrespResistor = actvol_0/curpResistor;
Serial.println("Resistance for photoresistor: ");
Serial.println(actrespResistor, 3);

/*val0 = analogRead(pResistor);
volresistor = val0*vol;
volpResistor = 5 - volresistor;
actresPresistor = volpResistor/curpResistor;
Serial.println("Resistance for photoresistor: ");
Serial.println(actresPresistor, 3);
*/
//actvol1 = val1*vol;
//actvol_1 = 5 - actvol1;
//Serial.println("Voltage across thermistor: ");
//Serial.println(actvol_1, 3);


val1 = analogRead(thermistor);
//actresthermistor = actvol

//actresthermistor = actvol/curthermistor;
//Serial.println("Resistance of Thermistor: ");
//Serial.println(actresthermistor, 3);

//IRreading = analogRead(IRSensor);
//Serial.println("IR Light Value: ");
//Serial.println(IRreading);

delay(500);

//  float voltage = sensorValue * (5 / 1023.0);
//  Serial.println(sensorValue);

Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");   

  delay(500);

  
//digitalWrite(IRTransmitter, HIGH);
//digitalWrite(IRSensor, HIGH);

}