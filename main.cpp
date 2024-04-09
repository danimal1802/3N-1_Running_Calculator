// Collatz 3N+1 running calculator
// Daniel Mitchell
// 9 April 2024

#include <LiquidCrystal_I2C.h>
#include <SPI.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// Adjust the address if necessary
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Initial variable settings
long enn = 10;  // start at 1
long current_val = enn; 
long iteration = 0;
long enn_max = 0;
long iter_max = 0;
long enn_at_iter_max;
long val_max = 0;
long enn_at_val_max;

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("3N+1");
}

void loop() {

  lcd.setCursor(6,0);
  lcd.print("N= ");
  lcd.setCursor(8,0);
  lcd.print(enn);

  lcd.setCursor(0,1);
  lcd.print("                    ");

  lcd.setCursor(0,1);
  lcd.print("I=");   
  lcd.setCursor(2,1);
  lcd.print(iteration);

  lcd.setCursor(6,1);
  lcd.print("V=");
  lcd.setCursor(8,1);
  lcd.print(current_val);

  if (current_val >= val_max) {
    val_max = current_val;
    enn_at_val_max = enn;
  }

  if (current_val == 1) {     // Check for Convergence to 1
    // Update max values
    if (enn >= enn_max) {
      enn_max = enn;
      //
    }

    // Update iteration max and enn at this max
    if (iteration >= iter_max) {
      iter_max = iteration;
      enn_at_iter_max = enn;
    }

    // increment enn and reset counters 
    enn = enn + 1;
    current_val = enn;
    iteration = 0;

    // clear LCD
    lcd.setCursor(0,1);
    lcd.print("                    ");
    lcd.setCursor(0,2);
    lcd.print("maxI=               ");
    lcd.setCursor(0,3);
    lcd.print("maxV=               ");
    //
    // Otherwis if not converged do this
    // 
    } else {
    iteration = iteration + 1;
    if (current_val % 2 == 0) {
      lcd.setCursor(16,1);
      lcd.print("Even");
      current_val = current_val/2;
    } else {
      lcd.setCursor(16,1);
      lcd.print("Odd ");
      current_val = (3 * current_val) + 1;  
    }

    // Update Max values on LCD screen
    lcd.setCursor (5,2);  lcd.print(iter_max);
    lcd.setCursor (14,2); lcd.print(enn_at_iter_max);
    lcd.setCursor (5,3);  lcd.print(val_max);
    lcd.setCursor (14,3); lcd.print(enn_at_val_max);

  }  
}
