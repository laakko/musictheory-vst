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

    struct ScaleInfo {
        juce::String name;
        BasicScale type;
        juce::String description;
        
        ScaleInfo(const juce::String& n, BasicScale t, const juce::String& d = "")
            : name(n), type(t), description(d) {}
    };

    static const std::vector<ScaleInfo> SCALE_MODES = {
    {"Major", BasicScale::Major, "Standard major scale (Ionian mode)"},
    {"Minor", BasicScale::Minor, "Natural minor scale (Aeolian mode)"},
    {"Harmonic Minor", BasicScale::HarmonicMinor, "Minor scale with a raised 7th. More exotic and dramatic sound than the natural minor. Common in metal and classical music. Typically used during the V7 chord in a minor key."},
    {"Minor Pentatonic", BasicScale::MinorPentatonic, "Five-note minor scale. Timeless and commonly used across musical genres."},
    {"Major Pentatonic", BasicScale::MajorPentatonic, "Five-note major scale. Timeless and commonly used across musical genres."},
    {"Blues", BasicScale::Blues, "Minor pentatonic with added 'blue note' (the flat 5th)."},
    {"Dorian", BasicScale::Dorian, "Minor mode with raised 6th. Blends minor and major tonality; melancholic, yet mystical and uplifting. Often used in groove-based music like funk and latin."},
    {"Lydian", BasicScale::Lydian, "Major mode with raised 4th. Bright, dreamy, ethereal."},
    {"Mixolydian", BasicScale::Mixolydian, "Major mode with flat 7th. Major feel with more 'attitude'. Commonly used in rock and modal jazz, especially over the V7 chord."},
    {"Phrygian", BasicScale::Phrygian, "Minor mode with flat 2nd. Exotic, middle-eastern sound."},
    {"Locrian", BasicScale::Locrian, "Minor mode with flat 2nd and flat 5th. Extremely dark and unstable, rarely used."},
    {"Metallica", BasicScale::Metallica, "For Metallica style riffs, use like minor scale but add chromatic passing tones from the added intervals. Idea from Signals Music Studio: https://www.youtube.com/watch?v=UuqvZDDm_bk"},
    {"Phrygian Dominant", BasicScale::PhrygianDominant, "Phrygian with major 3rd. Common in flamenco and middle-eastern folk music. Alternatively called 'Andalusian scale' (region where flamenco originated) or 'Ahava Rabbah' (Hebrew)."}};

    
    static juce::StringArray getScaleModesStringArray() {
        juce::StringArray names;
        for (const auto& scale : SCALE_MODES) {
            names.add(scale.name);
        }
        return names;
    }


    struct ChordInfo {
        juce::String name;
        BasicChord type;
        juce::String description;
        
        ChordInfo(const juce::String& n, BasicChord t, const juce::String& d = "")
            : name(n), type(t), description(d) {}
    };

    static const std::vector<ChordInfo> CHORD_TYPES = {
        {"major", BasicChord::maj, "Major triad. Stable, happy, bright."},
        {"m", BasicChord::min, "Minor triad. Stable, sad, melancholic."},
        {"aug", BasicChord::aug, "Augmented triad. Unstable, tense, like a 'floating question mark'. Wants to resolve to a stable chord."},
        {"dim", BasicChord::dim, "Diminished triad. Unstable and chaotic. Wants to resolve, e.g. to a stable major/minor chord half step higher or whole step lower."},
        {"sus2", BasicChord::sus2, "Suspended second chord. No major or minor quality due to the missing 3rd, 'suspended' in between them. Usually paired with major chord of the same root."},
        {"sus4", BasicChord::sus4, "Suspended fourth chord. No major or minor quality due to the missing 3rd, 'suspended' in between them. Usually paired with major chord of the same root."},
        {"m6", BasicChord::min6, "Minor sixth chord. The added M6 interval creates some brightness to the minor sound."},
        {"M6", BasicChord::maj6, "Major sixth chord. Adds warm and mellow color to major triad."},
        {"m7", BasicChord::min7, "Minor seventh chord. Colors a minor chord less harsh and a bit brighter."},
        {"M7", BasicChord::maj7, "Major seventh chord. Adds jazzy, smooth and relaxing color to a major chord."},
        {"7", BasicChord::dom7, "Dominant seventh chord. Tense and unstable. Commonly used on 12 bar blues on all chords. Often used as the V7 chord, creates strong pull to the tonic."},
        {"min_maj7", BasicChord::min_maj7, "Minor-major seventh chord. Conflicting minor and major tonality, cinematic, 'noir', emotional."},
        {"7#9", BasicChord::hendrix, "The Hendrix chord. Raw and bluesy dominant chord. Works great with blues/rock music."}};
    
    static juce::StringArray getChordTypesStringArray() {
        juce::StringArray names;
        for (const auto& chord : CHORD_TYPES) {
            names.add(chord.name);
        }
        return names;
    }

    static const double NON_ROOT_NOTE_ALPHA = 0.65;

    static const int MIDI_UPDATE_TIMER_FREQ_HZ = 30;

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