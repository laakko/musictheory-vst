#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Constants.h"
#include <mutex>


//==================================================================================
class MusicTheoryAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    MusicTheoryAudioProcessor();
    ~MusicTheoryAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override {};
    void releaseResources() override {};

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override { return true; };

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }

    //==============================================================================
    const String getName() const override { return JucePlugin_Name; };
    double getTailLengthSeconds() const override { return 0.0; }

    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect () const override { return true; }

    //==============================================================================
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram (int index) override {};
    const String getProgramName (int index) override { return "None"; }
    void changeProgramName (int index, const String& newName) override {};

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    std::unique_ptr<AudioProcessorValueTreeState> state;
    
    //==============================================================================
    std::vector<String> getActiveMidiNotes();
    bool wasPaused = false; 

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MusicTheoryAudioProcessor)
    std::vector<String> activeMidiNotes; // Store MIDI note names for use in the editor
    std::mutex midiNotesMutex; // Mutex to protect access to activeMidiNotes

};
