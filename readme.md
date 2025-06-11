### Music Theory VST

C++/Juce VST plugin, which displays handy music theory helpers especially for guitar players: 
- Scales
- Chords
- View scale/chord notes on the guitar guitar fretboard
- View incoming MIDI notes in real time on the guitar fretboard


![sc](/screenshot1.png)  

### Usage

#### Linux build
```
docker build -t musictheory-juce709 .

xhost +local:docker

docker run -it --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /directory-where-you-cloned-the-repo/musictheory-vst:/plugin \
    musictheory-juce709

./build_plugin.sh
```
(chmod +x the build_plugin.sh file if not sufficient permissions)
  
-> Build finished at Builds/LinuxMakeFile directory.
  
Contains standalone and linux vst3. 
To run standalone ./plugin/Builds/LinuxMakeFile/build/MusicTheory

#### Windows build

Open .sln project in VisualStudio2022, build with ctrl+shift+b. Generates standalone and VST3.


### Libraries
https://github.com/laakko/acentric
