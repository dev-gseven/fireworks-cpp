# fireworks-cpp
Play text art animations on terminal. Works on Windows, Linux and macOS!

## Usage
Double-click on executable to run the main animation (fireworks) or if you want to choose other animations and custom times:

### Parameters (optional)
- ```[folder]```: Folder containing text art frames (numbered 0.txt, 1.txt, etc.). Defaults to 'fireworks'
- ```[loops]```: Number of times to loop the animation (-1 for infinite). Defaults to 10

### On Linux/macOS:
Double-click on executable or open Terminal at folder and run with parameters:
```
./fireworks-cpp [folder] [loops]
```
### On Windows:
It's recommended to install [Windows Terminal](https://apps.microsoft.com/detail/9n0dx20hk701?rtc=1) to run ANSI codes, then double-click on executable or open Terminal at folder and run with parameters:
```
fireworks-cpp.exe [folder] [loops]
```
### Examples
Run the default animation
```
./fireworks-cpp
```
Run the fireplace animation forever
```
./fireworks-cpp fireplace -1
```
Run the rick animation for 3 loops
```
./fireworks-cpp rick_ascii 3
```

## Building from source
1. Install 'make' on your machine
2. Clone the repository
3. Go to downloaded repository folder
4. Open Terminal at folder and run: ```make```

#### I am using g++ to compile it, if you have a different compiler, run:
```'compiler' -std=c++17 -pthread -static fireworks-cpp.cpp -o fireworks-cpp```
#### Note:
The ```-static``` flag links all the libraries into the executable to have portability, on macOS this doesn't work, so just remove the flag on macOS.

## Acknowledgments
This project is a C++ port of [text_art_animations](https://github.com/rvizzz/text_art_animations) and [firew0rks](https://github.com/addyosmani/firew0rks) for learning purposes. Thank you all for the inspiration and amazing animations!
