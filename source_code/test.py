import serial
import time

# Define the Arduino's serial port (adjust as needed)
#arduino_port = 'COM3'  # Replace with your Arduino's serial port
#baud_rate = 9600  # Must match baud rate set in Arduino IDE

# Establish serial communication with Arduino
ser = serial.Serial('COM3', 9600, timeout=1)

try:
    # Send integers from 0 to 3 continuously
    while True:
        for value in range(4):
            ser.write(str(value).encode())  # Send the integer as bytes
            print(f"Sent value: {value}")
            time.sleep(2)  # Wait for 2 seconds before sending the next value

except KeyboardInterrupt:
    print("\nProgram terminated by user.")

#finally:
    #ser.close()  # Close the serial connection when done
