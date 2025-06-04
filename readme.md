### Music Theory Helper VST - MTHVST 

C++/Juce VST plugin, which contains handy music theory helpers especially for guitar players: 
- Scales
- Chords
- View scale/chord notes on guitar neck
- Notepad for writing notes/chord progressions, whatnot.


![sc](/screenshot.PNG)  

### Usage
docker build -t musictheory-juce709 .
docker run -it --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /directory-where-you-cloned-the-repo/musictheory-vst:/plugin \
    musictheory-juce709
cd Builds/LinuxMakeFile && make clean && make
./builds/MusicTheory


### Libraries
https://github.com/laakko/acentric
