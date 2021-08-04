#include <Keypad.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <ClearPathMotorSD.h>
#include <ClearPathStepGen.h>

# define M_PI 3.14159265358979323846

ClearPathMotorSD X;
ClearPathStepGen machine(&X);

const byte ROWS = 4;
const byte COLS = 4;

char hexa_keys[ROWS][COLS] = {
  {'1', '2', '3', '\0'},
  {'4', '5', '6', '\0'},
  {'7', '8', '9', 'C'},
  {'.', '0', '\0', 'D'}
};

byte row_pins[ROWS] = {6, 7, 8, 9};
byte col_pins[COLS] = {2, 3, 4, 5};

Keypad custom_keypad = Keypad(makeKeymap(hexa_keys), col_pins, row_pins, COLS, ROWS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

char input[12];
int index = 0;

float current_position = 0.00;
float next_position;
int max_position = 29;

float diameter = 1.004;  // Diameter of the wheel in inches. Adjust this value to change the distance.


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  X.attach(22, 23, 24, 25);  // Direction/A is pin 22, Step/B is pin 23, Enable is pin 24, HLFB is pin 25

  X.setMaxVel(20000);  // Value between 2 and 100,000 steps/sec
  X.setMaxAccel(50000);  // Value between 4000 and 2,000,000 steps/sec^2

  X.enable();  // Homimg will automatically occur at this call. Be sure to account for its moving.

  delay(100);

  machine.Start();

  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Curr: ");
  lcd.print(current_position, 4);
  lcd.setCursor(0, 1);
  lcd.print("Next: ");
  lcd.print(input);

  char key = custom_keypad.getKey();

  if (key && key != 'D') {
    lcd.clear();
    input[index] = key;
    index++;
  }
  else if (key && key == 'D') {
    next_position = atof(input);
    if (next_position > max_position) {
      lcd.clear();
      lcd.print("Out of Range");
      delay(2000);
    }
    else {
      X.move(get_count(current_position) - get_count(next_position));  // To reverse the direction, swap the current_position and next_position.
      while (!X.commandDone()) {
        Serial.println("Moving");
      }
      Serial.println("Done Moving");
      current_position = next_position;
    }
    reset();
  }
  
  if (key == 'C' || index == 11) {
    reset();
  }
}

void clear_input() {
  for (int i = 0; i < sizeof input; i++) {
    input[i] = '\0';
  }
}

void reset() {
  clear_input();
  lcd.clear();
  index = 0;
}

float get_count(float distance) {
  return 800*distance/(M_PI*diameter);
}
