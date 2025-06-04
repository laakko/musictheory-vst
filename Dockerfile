# Base image
FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    unzip \
    pkg-config \
    libx11-dev \
    libxrandr-dev \
    libxinerama-dev \
    libxext-dev \
    libfreetype6-dev \
    libxcomposite-dev \
    libxcursor-dev \
    libasound2-dev \
    libjack-jackd2-dev \
    libcurl4-openssl-dev \
    libglu1-mesa-dev \
    libgl1-mesa-dev \
    libgtk-3-dev \
    libwebkit2gtk-4.0-dev \
    x11-apps \
    nano \
    xfce4 \
    python3 \
    xvfb \
    dos2unix \
    mingw-w64 \
    && rm -rf /var/lib/apt/lists/*

# Set working directory in container
WORKDIR /plugin

# Clone JUCE if not already in current directory
# RUN git clone --branch 7.0.9 --depth 1 https://github.com/juce-framework/JUCE.git

# Copy everything (JUCE + your project)
COPY . .

# Ensure correct permissions and line endings
RUN chmod -R 755 /plugin && \
    find /plugin -type f -name "*.h" -o -name "*.cpp" -exec chmod 644 {} \; && \
    dos2unix MusicTheory.jucer

# Build Projucer
WORKDIR /plugin/JUCE/extras/Projucer/Builds/LinuxMakefile
RUN make -j$(nproc)

# Verify JUCE modules and resave project
WORKDIR /plugin
RUN xvfb-run --auto-servernum /plugin/JUCE/extras/Projucer/Builds/LinuxMakefile/build/Projucer --resave MusicTheory.jucer --verbose

# Build the plugin using generated Makefile
WORKDIR /plugin/Builds/LinuxMakefile
RUN make -j$(nproc)

# Default command
CMD ["/bin/bash"]

## IF BUILD FAILS DUE TO VST2 errors
# MODIFY JUCE/modules/juce_audio_plugin_client.h
#ifndef JUCE_VST3_CAN_REPLACE_VST2
 #define JUCE_VST3_CAN_REPLACE_VST2 0
#endif