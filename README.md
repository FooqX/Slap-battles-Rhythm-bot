# Installation
1. Download the source file
2. Download Visual Studio 2022 with C++ development selected. Open it and create a new project C++ Console. Go into Project settings,  set C standard to preview. You can also change release options in there for more optimizations. Then, rename the current main file from name.cpp,  to name.c. Name can be anything. Switch to release build mode. Build project for x64 (64bit) or x86/x32 if you have 32bit computer. Right click on the project in solution explorer, then open in file explorer, or navigate to your user folder (C:/Users/youruser), then "repos", your repo, there find release folder or something, you will find an exe. You can copy it wherever you want.
Or- second option: (might be easier)
2. Download a compiler:
   Download LLVM from the Github releases. Make sure to check to add to system path.
   Check if it's downloaded correctly using `clang --version` command in CMD/Powershell 7 (you can choose any).
   Compile the source file using this command: `clang -O3 -march=native -std=c23 -target -o SBRhythm.exe THE_SOURCE_FILE_NAME__ENTER_IT_YOURSELF.c`


Basically
You have the code, compile it yourself because it needs modification for the *x and y coordinates* (find the comment in the code about that). Find the x and y coordinates of your mouse cursor when you place it on
the middle of the Rhythm glove tiles. So basically, you copy the x and y coordinates of the mouse cursor when you place it in the middle of the thing where tiles go.

# How it works
When you specify the coordinates, it simply grabs the pixel color from that location and checks for either white or yellow tile. If it detects that color, it automates a mouse click. Simple as that

# Compile it yourself
I used Visual Studio 2022 Preview to code this. Also used C17 (2018) C standard. Used Visual studio platform tools 2022 v143.
# Use any C compiler you want (Clang, GCC, TinyCC, whatever), just modify the coordinates for your own monitor. The script is configured for 1920x1080p 100% display scale, with Fullscreen on.

# Usage
When you launch it, open the game and take Rhythm glove, go closer to the portal and then press 'R' to activate the program. To pause it, press R again. To exit out of it without pressing the X button, press 'O'.
When you toggle the script, it makes a beep sound. The long beep means it's toggled OFF. Short beep means ON.
