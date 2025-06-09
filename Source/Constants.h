#pragma once

#include <JuceHeader.h>
#include "BasicNote.h"
#include "Note.h"
#include "Interval.h"
#include "Scale.h"
#include "BasicScale.h"
#include "Chord.h"
#include "BasicChord.h"

using namespace acentric_core;

namespace Constants {
    static const StringArray ROOT_NOTES = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };

    static const std::vector<std::pair<juce::String, BasicScale>> SCALE_MODES = {
        {"Major", BasicScale::Major},
        {"Minor", BasicScale::Minor},
        {"Harmonic Minor", BasicScale::HarmonicMinor},
        {"Minor Pentatonic", BasicScale::MinorPentatonic},
        {"Major Pentatonic", BasicScale::MajorPentatonic},
        {"Blues", BasicScale::Blues},
        {"Dorian", BasicScale::Dorian},
        {"Lydian", BasicScale::Lydian},
        {"Mixolydian", BasicScale::Mixolydian},
        {"Phrygian", BasicScale::Phrygian},
        {"Aeolian", BasicScale::Aeolian},
        {"Ionian", BasicScale::Ionian},
        {"Locrian", BasicScale::Locrian},
        {"Metallica", BasicScale::Metallica},
        {"PhrygianDominant", BasicScale::PhrygianDominant}
    };

    static const std::vector<std::pair<juce::String, BasicChord>> CHORD_TYPES = {
        {"m", BasicChord::min},
        {"M", BasicChord::maj},
        {"aug", BasicChord::aug},
        {"dim", BasicChord::dim},
        {"sus2", BasicChord::sus2},
        {"sus4", BasicChord::sus4},
        {"m6", BasicChord::min6},
        {"M6", BasicChord::maj6},
        {"m7", BasicChord::min7},
        {"M7", BasicChord::maj7},
        {"dom7", BasicChord::dom7},
        {"min_maj7", BasicChord::min_maj7},
        {"hendrix", BasicChord::hendrix}
    };

    static const double NON_ROOT_NOTE_ALPHA = 0.6;
} 