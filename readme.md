## Music Theory VST

Linux & Windows VST3 plugin, for displaying handy music theory helpers especially for guitar players: 
- Scales
- Chords
- View scale/chord notes on the guitar guitar fretboard
- View incoming MIDI notes in real time on the guitar fretboard  

Written with Juce & C++

<br>
  
![sc](/musictheoryvst.gif)  

### Installation & Usage

- Download latest Linux or Windows vst3 plugin binaries from Github releases, or build manually from sources (instructions below).

- Search and add the plugin on your DAW of choice. To use the midi-live feature, add the plugin to a midi track. Note that it will block and mute midi instruments and effects, so use a separate track.

- The plugin has parameters for all choices, so you can use DAW automation to e.g. have certain scales to show at specific times

<br>

### Source build
#### Linux
```
docker build -t musictheory-juce709 .

xhost +local:docker

docker run -it --rm \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /directory-where-you-cloned-the-repo/musictheory-vst:/plugin \
    musictheory-juce709

./build_plugin.sh

-> Build finished at Builds/LinuxMakeFile directory.
  
Contains standalone and linux vst3. 
To run standalone ./plugin/Builds/LinuxMakeFile/build/MusicTheory

chmod +x the build_plugin.sh file if not sufficient permissions
  
Change JUCE installation path on the MusicTheory.jucer file if needed

```

#### Windows
```
Open .sln project in VisualStudio2022
  
-> build with ctrl+shift+b 
  
-> Generates standalone and VST3.

Change JUCE installation path in the MusicTheory.jucer file or in Projucer GUI if needed.
```
