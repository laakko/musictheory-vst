# Base image
FROM ubuntu:18.04

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
    && rm -rf /var/lib/apt/lists/*

# Set working directory in container
WORKDIR /plugin

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
RUN ls -la JUCE/modules && \
    echo "Verifying JUCE module paths..." && \
    PROJUCER_PATH="/plugin/JUCE/extras/Projucer/Builds/LinuxMakefile/build/Projucer" && \
    VST3_SDK_PATH="/plugin/vst3sdk" && \
    xvfb-run --auto-servernum "$PROJUCER_PATH" --resave MusicTheory.jucer --set-global-search-path linux "VST3 SDK" "$VST3_SDK_PATH" --verbose

# Build the plugin using generated Makefile
WORKDIR /plugin/Builds/LinuxMakefile
RUN make -j$(nproc)

# Default command
CMD ["/bin/bash"]


## TO USE THIS DOCKERFILE:
# docker build -t musictheory-juce547 .
# docker run -it \
#    --rm \
#    -e DISPLAY=$DISPLAY \
#    -v /tmp/.X11-unix:/tmp/.X11-unix \
#    -v /home/Jukka/Documents/musictheory-vst:/code/ \
#    musictheory-juce547