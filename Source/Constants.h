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

namespace Constants
{
    static const juce::StringArray ROOT_NOTES = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

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
        {"PhrygianDominant", BasicScale::PhrygianDominant}};

    static const std::vector<std::pair<juce::String, BasicChord>> CHORD_TYPES = {
        {"M", BasicChord::maj},
        {"m", BasicChord::min},
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
        {"hendrix", BasicChord::hendrix}};

    static const double NON_ROOT_NOTE_ALPHA = 0.65;

    static const juce::Colour colorF = Colour(0xff4d91a9);
    static const juce::Colour colorFs = Colour(0xff5681ab);
    static const juce::Colour colorG = Colour(0xff706ea1);
    static const juce::Colour colorGs = Colour(0xff885887);
    static const juce::Colour colorA = Colour(0xff934561);
    static const juce::Colour colorAs = Colour(0xffbd5c63);
    static const juce::Colour colorB = Colour(0xffdf7b60);
    static const juce::Colour colorC = Colour(0xfffecb5f);
    static const juce::Colour colorCs = Colour(0xffc1be4f);
    static const juce::Colour colorD = Colour(0xff86af4d);
    static const juce::Colour colorDs = Colour(0xff499b53);
    static const juce::Colour colorE = Colour(0xff007062);
}