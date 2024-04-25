Refer to this YouTube video by Veritasium for context about 3N+1:  https://www.youtube.com/watch?v=094y1Z2wpJg

This is a simple C++ program for the Arduino Uno that:

1.) Incremently Iterates through values of N for the Collatz Conjecture 3N+1

2.) Tracks the maximum number of iterations for any value of N and at which value of N it was obtained

3.) Tracks the maximum value obtained while performing calculations through the iterations and at which value of N a maximum was obtained

4.) Display the current value of N, the iteration on N, the current value calculated (V)

5.) Display (Even) or (Odd) for the current value calculated dictating the next calculation (3N+1 or /2) 

6.) Display the running values on a I2C bus connected 2004A LCD display

The program iterates continuously and indefinitely with no final result limited only by longint() and display size 

The Arduino-Uno and the LCD display through 4 wires via the standard I2C connections (SCL and SDA) along with ground and 5V
