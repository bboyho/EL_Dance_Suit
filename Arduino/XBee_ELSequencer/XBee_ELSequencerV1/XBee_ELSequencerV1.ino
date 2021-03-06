/**********************************************************************
XBee_ELSequencerV1.ino
Created by Ho Yun Bobby Chan @  SparkFun Electronics May 10th, 2017

 * Taken from SparkFun XBee EL Sequencer Demo Sketch
 * Ho Yun Bobby Chan @ SparkFun Electronics June 20, 2014
 * Updated by Toni Klopfenstein @ SparkFun Electronics April, 2015
 * https://github.com/sparkfun/EL_Sequencer
 *
 * Description:
 * This is a basic test of the EL Sequencer to control an EL Sequencer
 * The wireless controller consists of an RedBoard Programmed with Arduino, XBee Shield,
 * XBee Series 1 transceiver, and LED Push Button. The EL Sequencer
 * uses an EL wire, 12V EL inverter, a 9V wall wart, 9V adapter, XBee female sockets soldered,
 * battery, and a XBee Series 1 transceiver. An XBee Series 2
 * can be used but the throughput of the Series 1 is much higher. To
 * reduce latency, I recommend using the XBee Series 1. The basic
 * configuration of the XBee module with point-to-point configuratin is
 * based on Digi's Example tutorial
 * => http://examples.digi.com/get-started/basic-xbee-802-15-4-chat/ .
 * Page 5 of the tutorial shows you how to broadcast with
 * point-to-multipoint configuration so that multiple EL Sequencers
 * can be controlled.
 *
 * By pushing the button, a character is sent from a remote microcontroller.
 * The corresponding EL Sequencer will receive the character and control
 * the EL component on a channel that is associated with that character.
 *
 * EL Sequencer uses the hardware UART of the Atmega328 for communication:
 * pin 0 = Rx
 * pin 1 = Tx
 *
 * Note: Make sure to remove the XBee Series 1 on the EL Sequencer when
 * uploading a new sketch file otherwise it will brick the XBee. You can
 * always use the next generation XCTU software to unbrick and recover
 * the transceiver.
 *
 * Development environment specifics:
 * Arduino 1.6.3
 *
 * This code is beerware; if you see me (or any other SparkFun employee) at the local,
 * and you've found our code helpful, please buy us a round!
 * Distributed as-is; no warranty is given.
 *
 ***********************************************************************/

//Declare character 'val'
char val;

//LED to check if the LED is initialized.
const int status_LED = 13;

/*******************Setup Loop***************************/
void setup() {
  Serial.begin(9600); //Begin Serial communication for debugging
  Serial.println("EL Sequencer's XBee is Ready to Receive Characters");

  val = 'A';// button pressed, therefore sending  letter A

  //Initialize pins
  pinMode(status_LED, OUTPUT); //Set pin mode as output for status LED
  pinMode(2, OUTPUT); //Set pin mode as output for Channel A
  pinMode(3, OUTPUT); //Set pin mode as output for Channel B
  pinMode(4, OUTPUT); //Set pin mode as output for Channel C
  pinMode(5, OUTPUT); //Set pin mode as output for Channel D
  pinMode(6, OUTPUT); //Set pin mode as output for Channel E
  pinMode(7, OUTPUT); //Set pin mode as output for Channel F
  pinMode(8, OUTPUT); //Set pin mode as output for Channel G
  pinMode(9, OUTPUT); //Set pin mode as output for Channel H

  //Status LED to see if the EL Sequencer is initializing  
  for (int i = 0; i < 3; i++) {
    digitalWrite(status_LED, HIGH);//set Status LED on
    delay(50);
    digitalWrite(status_LED, LOW); //set Status LED off
    delay(50);
  }

  digitalWrite(2, HIGH); //Channel A
  digitalWrite(3, HIGH); //Channel B

  digitalWrite(4, LOW); //Channel C
  digitalWrite(5, LOW); //Channel D

  digitalWrite(6, LOW); //Channel E
  digitalWrite(7, LOW); //Channel F

  digitalWrite(8, LOW); //Channel G
  digitalWrite(9, LOW); //Channel H

  delay(1000); //Wait 1 second
}

/*******************Main Loop***************************/
void loop() {

  //Check if XBee is receiving data from other XBee
  if (Serial.available()) {
    val = Serial.read();

    //Check to see if character sent is letter A
    if (val == 'A') {
      digitalWrite(status_LED, LOW); //turn ON Status LED
      digitalWrite(2, LOW); //Channel A
      digitalWrite(3, LOW); //Channel B
      delay(1000);
      Serial.println("Character Received");
    }

    else {
      //rewrote controller code to stop constantly sending Z
      //toggled pins outside of this nested condition statement
    }
  }

  digitalWrite(status_LED, HIGH); //turn OFF Status LED

  digitalWrite(2, HIGH); //Channel A
  delay(50);
  digitalWrite(3, HIGH); //Channel B
}
