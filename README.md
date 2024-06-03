# Whack-A-Mole Game

A fun, interactive Whack-A-Mole game implemented on an Arduino platform. This project uses LCD displays, LEDs, and push buttons to create a competitive game for two players. The code is modular and organized, utilizing I2C communication for efficient pin usage.

## Features

- Two-player support with individual scoring
- LED indicators and LCD displays for each player
- Randomized LED lighting for gameplay variation
- Buzzer for game over notification
- Modular code structure for easy maintenance and readability

## Hardware Requirements

- Arduino Uno (or compatible)
- 2 x 16x2 I2C LCD displays
- 10 x LEDs (5 for each player)
- 10 x Push buttons (5 for each player)
- 1 x Buzzer
- Resistors, jumper wires, and breadboard for connections

## Setup and Installation

1. **Clone the Repository**

    ```sh
    git clone https://github.com/yourusername/Whack-A-Mole-Game.git
    cd Whack-A-Mole-Game
    ```

2. **Hardware Connections**

    - Connect the LEDs and push buttons to the Arduino as specified in the `Config.h` 
      file.
    - Connect the LCD displays using I2C communication (A4 for SDA, A5 for SCL).
    - Connect the buzzer to the specified pin.

3. **Open the Project in Arduino IDE**

    - Open the `WhackMoleGame.ino` file in the Arduino IDE.
    - Ensure all the required libraries (`Wire.h` and `LiquidCrystal_I2C.h`) are 
      installed.

4. **Upload the Code**

    - Connect the Arduino to your computer.
    - Select the appropriate board and port in the Arduino IDE.
    - Upload the code to the Arduino.

## Code Structure

- **WhackMoleGame.ino**: Main Arduino sketch file that ties everything together.
- **Config.h**: Configuration file containing constants and global variables.
- **LCDManager.h / LCDManager.cpp**: Functions for initializing and updating the LCD 
  displays.
- **PinManager.h / PinManager.cpp**: Functions for pin initialization.
- **GameManager.h / GameManager.cpp**: Functions for managing the game logic.
- **ButtonHandler.h / ButtonHandler.cpp**: Functions for handling button presses.
- **EndGameSequence.h / EndGameSequence.cpp**: Functions for handling the end game 
   sequence.

## Usage

1. **Start the Game**

    - Power on the Arduino.
    - The LCD displays will initialize and display "PLAYER1:" and "PLAYER2:".

2. **Gameplay**

    - LEDs will light up randomly for each player.
    - Press the corresponding button to turn off the LED and score a point.
    - The game speed will increase as you progress.

3. **End of Game**

    - The game ends when one player reaches the maximum score.
    - The winner and loser will be displayed on the LCDs, and the buzzer will sound.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Arduino](https://www.arduino.cc/)
- [LiquidCrystal I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)

## Author

- Mohamed Awadin

