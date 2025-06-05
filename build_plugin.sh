#!/bin/bash
# Build Projucer
cd /plugin/JUCE/extras/Projucer/Builds/LinuxMakefile
make -j$(nproc)

# Verify JUCE modules and resave project\n\
cd /plugin
xvfb-run --auto-servernum /plugin/JUCE/extras/Projucer/Builds/LinuxMakefile/build/Projucer --resave MusicTheory.jucer --verbose\n\

# Build the plugin using generated Makefile\n\
cd /plugin/Builds/LinuxMakefile
make -j$(nproc)
