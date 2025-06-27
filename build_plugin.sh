#!/bin/bash
# Build Projucer
cd /plugin/JUCE/extras/Projucer/Builds/LinuxMakefile
make -j$(nproc)

# Verify JUCE modules and resave project
cd /plugin
xvfb-run --auto-servernum /plugin/JUCE/extras/Projucer/Builds/LinuxMakefile/build/Projucer --resave MusicTheory.jucer --verbose

# Build the plugin using generated Makefile
cd /plugin/Builds/LinuxMakefile
make -j$(nproc)

# -> linux standalone and vst3 should now be built in /plugin/Builds/LinuxMakeFile/build directory