# SupercatJoyglide
A unique jetpack joyride style game by Aiden, Luke, and Wade.

# How to install
1. Open the terminal
2. Update the terminal
```
sudo apt-get update && sudo apt-get upgrade -y
```
3. Install the GNU compiler tools
```
sudo apt-get install build-essential gdb
```
4. Install git
```
sudo apt-get install git
```
5. Install SFML
```
sudo apt-get install libsfml-dev
```
6. Clone the repository
```
git clone https://github.com/lsteinford/supercatJoyglide SupercatJoyglide
```
7. Change into the directory
```
cd SupercatJoyglide
```
8. Compile the game
```
g++ -std=c++11 *.cpp -o supercatJoyglide -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```
9. Run the executable
```
./supercatJoyglide
```

# How to play
Click start button on main menu
Press 'Space' to move player up
Release 'Space' to move player down
Collect coins to increase score
Dodge doge obstacles to save the city
Press 'Esc' at anytime to quit

## Difficulty
Score 0-499: Doge w/ velocity of 3

Score 500-1499: Robo Doge w/ velocity of 4

Score 1500-1999: Final Villain Doge w/ velocity of 6

Score 2000+: Velocity of Doge is multiplied by 1.3 for every 500 score increment over 2000

# Contribution
* Aiden - Made the doge obstacles and function to move them. Implented waves of different doge obstacles. Added music.
* Luke - Added animation to the player sprite and coins. Created a start button. Consolidated code into fewer and more organized cpps. Created parallax background. Implemented a vector for the coins and obstacles to allow for multiple obstacles on screen. Created main menu and death screen
* Wade - Made the player and function to move it. Implemented a frame per second limiter. Adjusted player movement speed to increase with coin pickup. Made the final villain doge sprite
