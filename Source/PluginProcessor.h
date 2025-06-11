/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Constants.h"
#include <mutex>


//==============================================================================
/**
*/
class MusicTheoryAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MusicTheoryAudioProcessor();
    ~MusicTheoryAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //==============================================================================
    std::vector<String> getActiveMidiNotes();

    std::unique_ptr<AudioProcessorValueTreeState> state;
    std::atomic<float>* buttonColourParam = nullptr;
    std::atomic<float>* buttonViewParam = nullptr;
    std::atomic<float>* viewAllParam = nullptr;
    std::atomic<float>* viewMidiParam = nullptr;
    std::atomic<float>* viewChordParam = nullptr;
    std::atomic<float>* viewScaleParam = nullptr;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MusicTheoryAudioProcessor)
    std::vector<String> activeMidiNotes; // Store MIDI note names for use in the editor
    std::mutex midiNotesMutex; // Mutex to protect access to activeMidiNotes

};
