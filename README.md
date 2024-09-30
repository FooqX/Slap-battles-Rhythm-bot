# SBRhythm
Slap battles Rhythm glove bot

# Installation
You have the code, compile it yourself because it needs modification for the x and y coordinates (find the comment in the code about that). Find the x and y coordinates of your mouse cursor when you place it on
the middle of the Rhythm glove tiles. So basically, you copy the x and y coordinates of the mouse cursor when you place it in the middle of the thing where tiles go.

# How it works
When you specify the coordinates, it simply grabs the pixel color from that location and checks for either white or yellow tile. If it detects that color, it automates a mouse click. Simple as that

# Compile it yourself
I used Visual Studio 2022 Preview to code this. Also used C17 (2018) C standard. Used Visual studio platform tools 2022 v143.
# Use any C compiler you want (Clang, GCC, TinyCC, whatever), just modify the coordinates for your own monitor. The script is configured for 1920x1080p 100% display scale, with Fullscreen on.

# Usage
When you launch it, open the game and take Rhythm glove, go closer to the portal and then press 'R' to activate the program. To pause it, press R again. To exit out of it without pressing the X button, press 'O'.
When you toggle the script, it makes a beep sound. The long beep means it's toggled OFF. Short beep means ON.
