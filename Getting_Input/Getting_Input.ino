#include <Keypad.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

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
int max_position = 240;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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
