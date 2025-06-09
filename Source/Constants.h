#pragma once

#include <JuceHeader.h>

namespace Constants {
    static const StringArray SCALE_KEYS = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };

    static const StringArray SCALE_MODES = {
        "Major", "Minor", "Harmonic Minor", "Blues", 
        "Minor Pentatonic", "Major Pentatonic", "Dorian", 
        "Lydian", "Mixolydian", "Phrygian", "PhrygianDominant", "Metallica"
    };

    static const StringArray CHORD_TYPES = {
        "m", "M", "aug", "dim", "sus2", "sus4", 
        "m6", "M6", "m7", "M7", "dom7", "min_maj7", "hendrix"
    };
} 