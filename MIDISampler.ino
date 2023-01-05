#include <Keypad.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <MIDI.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=216,283
AudioOutputI2S           i2s1;           //xy=762,303
AudioConnection          patchCord1(playSdWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=472,755
// GUItool: end automatically generated code
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

AudioControlSGTL5000 audioShield;
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
const int CHANNEL = 1;
const byte ROWS = 3;
const byte COLS = 3;
int ledPins[] = {0, 2, 3, 4, 5, 6, 24, 28};
int bank = 1;
int lineLevel = 29;

char keys[ROWS][COLS] = {
  {'1', '6', '7'},
  {'2', '3', '4'},
  {'8', '9', '5'}
};
byte rowPins[ROWS] = {9, 22, 17};
byte colPins[COLS] = {14, 15, 16};

Keypad buttons = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void displayOff() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], LOW);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], LOW);
}

void displayAll() {
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displayZero() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], LOW);
}

void displayOne() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], LOW);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], LOW);
}

void displayTwo() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], HIGH);
}

void displayThree() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], HIGH);
}

void displayFour() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], LOW);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displayFive() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displaySix() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displaySeven() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], LOW);
  digitalWrite(ledPins[7], LOW);
}

void displayEight() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displayNine() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displayE() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], LOW);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displayP() {
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], HIGH);
  digitalWrite(ledPins[4], HIGH);
  digitalWrite(ledPins[5], HIGH);
  digitalWrite(ledPins[6], HIGH);
  digitalWrite(ledPins[7], HIGH);
}

void displayBank() {
  switch (bank) {
    case 0:
      displayZero();
      break;
    case 1:
      displayOne();
      break;
    case 2:
      displayTwo();
      break;
    case 3:
      displayThree();
      break;
    case 4:
      displayFour();
      break;
    case 5:
      displayFive();
      break;
    case 6:
      displaySix();
      break;
    case 7:
      displaySeven();
      break;
    case 8:
      displayEight();
      break;
    case 9:
      displayNine();
      break;
    default:
      displayE();
      break;
  }
}

void setup() {
  pinMode(ledPins[0], OUTPUT);
  pinMode(ledPins[1], OUTPUT);
  pinMode(ledPins[2], OUTPUT);
  pinMode(ledPins[3], OUTPUT);
  pinMode(ledPins[4], OUTPUT);
  pinMode(ledPins[5], OUTPUT);
  pinMode(ledPins[6], OUTPUT);
  pinMode(ledPins[7], OUTPUT);
  pinMode(9, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  AudioMemory(10);
  MIDI.begin();
  displayAll();
  delay(1000);
  displayOff();
  delay(500);
  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  while (!(SD.begin(SDCARD_CS_PIN))) {
    displayE();
    delay(500);    
    displayZero();
  }
  displayAll();
  audioShield.enable();
  delay(1000);
  audioShield.unmuteLineout();
  audioShield.lineOutLevel(lineLevel);
  bank = 1;
  displayBank();
}

void loop() {
  char button = buttons.getKey();
  
  if (button == '1') {
    switch (bank) {
      case 0:
        lineLevel--;
        sgtl5000_1.lineOutLevel(lineLevel);
        break;
      case 1:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 2:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 3:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 4:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 5:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 6:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 7:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 8:
        playSdWav1.play("SoilDrop.wav");
        break;
      case 9:
        playSdWav1.play("SoilDrop.wav");
        break;
      default:
        displayE();
        break;
    }
  }
  if (button == '2') {
    switch (bank) {
      case 0:
        lineLevel++;
        sgtl5000_1.lineOutLevel(lineLevel);
        break;
      case 1:
        playSdWav1.play("Glitch.wav");
        break;
      case 2:
        playSdWav1.play("GATE INTERLUDE MONO.wav");
        break;
      case 3:
        playSdWav1.play("StarTrekShort.wav");
        break;
      case 4:
        playSdWav1.play("Chord1.wav");
        break;
      case 5:
        playSdWav1.play("CAPTAIN MORGANS SPICED DICK TOUCH.wav");
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      default:
        displayE();
        break;
    }
  }
  if (button == '3') {
    switch (bank) {
      case 0:
        break;
      case 1:
        playSdWav1.play("DREDGE INTERLUDE MONO.wav");
        break;
      case 2:
        playSdWav1.play("Popped.wav");
        break;
      case 3:
        playSdWav1.play("GHDATI.wav");
        break;
      case 4:
        playSdWav1.play("Chord2.wav");
        break;
      case 5:
        displayP();
        playSdWav1.play("NEW TERRORHORSE INTRO 2022 long pause mono.wav");
        delay(2000);
        bank = 1;
        displayBank();
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      default:
        displayE();
    }
  }
  if (button == '4') {
    switch (bank) {
      case 0:
        break;
      case 1:
        playSdWav1.play("pianokeynecktie.wav");
        break;
      case 2:
        playSdWav1.play("SON OF SUNS INTERLUDE MONO.wav");
        break;
      case 3:
        playSdWav1.play("NEW PACKET INTERLUDE MONO.wav");
        break;
      case 4:
        playSdWav1.play("Chord3.wav");
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      default:
        displayE();
    }
  }
  if (button == '5') {
    switch (bank) {
      case 0:
        break;
      case 1:
        playSdWav1.play("SoilDrop.wav");
        MIDI.sendControlChange(52, 127, CHANNEL);
        break;
      case 2:
        playSdWav1.play("surprise.wav");
        break;
      case 3:
        playSdWav1.play("CrazyPills.wav");
        break;
      case 4:
        playSdWav1.play("Chord4.wav");
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      default:
        displayE();
    }
  }
  if (button == '6') {
    switch (bank) {
      case 0:
        break;
      case 1:
        playSdWav1.play("NEW TERRORHORSE INTRO 2022 mono.wav");
        break;
      case 2:
        playSdWav1.play("Chord1long.wav");
        break;
      case 3:
        playSdWav1.play("Chord1long.wav");
        break;
      case 4:
        playSdWav1.play("ballsofsteel.wav");
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      default:
        displayE();
        break;
    }
  }
  if (button == '7') {
    switch (bank) {
      case 0:
        break;
      case 1:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 2:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 3:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 4:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 5:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 6:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 7:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 8:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      case 9:
        digitalWrite(ledPins[0], LOW);
        playSdWav1.stop();
        break;
      default:
        displayE();
        break;
    }
  }
  if (button == '8') {
    if (bank > 0) {
      bank--;
      displayBank();
    }
  }
  if (button == '9') {
    if (bank < 9) {
      bank++;
      displayBank();
    }
  }
}
