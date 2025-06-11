/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MusicTheoryAudioProcessor::MusicTheoryAudioProcessor()
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                       )
{
        // Initialize AudioProcessorValueTreeState
        state = std::make_unique<AudioProcessorValueTreeState>(*this, nullptr, "Parameters",
            AudioProcessorValueTreeState::ParameterLayout{
                std::make_unique<AudioParameterBool>("buttonColour", "theme", false),
                std::make_unique<AudioParameterBool>("buttonView", "view", false),

                std::make_unique<AudioParameterBool>("viewAll", "All", true),
                std::make_unique<AudioParameterBool>("viewScale", "Scale", false),
                std::make_unique<AudioParameterBool>("viewChord", "Chord", false),
                std::make_unique<AudioParameterBool>("viewMidi", "Midi", false),

                /*
                std::make_unique<AudioParameterChoice>("scaleKey", "key", Constants::ROOT_NOTES, 0),
                std::make_unique<AudioParameterChoice>("scaleMode", "scale", Constants::SCALE_MODES, 0),
                std::make_unique<AudioParameterChoice>("chordRoot", "root", Constants::ROOT_NOTES, 0),
                std::make_unique<AudioParameterChoice>("chordType", "chord", Constants::CHORD_TYPES, 0)
                */
            });
    
        buttonColourParam = state->getRawParameterValue("buttonColour");
        buttonViewParam = state->getRawParameterValue("buttonView");
        viewAllParam = state->getRawParameterValue("viewAll");
        viewScaleParam = state->getRawParameterValue("viewScale");
        viewChordParam = state->getRawParameterValue("viewChord");
        viewMidiParam = state->getRawParameterValue("viewMidi");

        //chordroot = stringToNote(state->getRawParameterValue("chordRoot")->load());
        //scaletype = BasicScale{ Constants::SCALE_MODES[state->getRawParameterValue("scaleMode")->load()].second };
}

MusicTheoryAudioProcessor::~MusicTheoryAudioProcessor()
{
}

//==============================================================================
const String MusicTheoryAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MusicTheoryAudioProcessor::acceptsMidi() const
{
   return true;
}

bool MusicTheoryAudioProcessor::producesMidi() const
{
   return false;
}

bool MusicTheoryAudioProcessor::isMidiEffect() const
{
    return true;
}

double MusicTheoryAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MusicTheoryAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MusicTheoryAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MusicTheoryAudioProcessor::setCurrentProgram (int index)
{
}

const String MusicTheoryAudioProcessor::getProgramName (int index)
{
    return {};
}

void MusicTheoryAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MusicTheoryAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MusicTheoryAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}


bool MusicTheoryAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  return true;
}


void MusicTheoryAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    std::lock_guard<std::mutex> lock(midiNotesMutex);

    for (const auto metadata : midiMessages)
    {
        const auto message = metadata.getMessage();

        if (message.isNoteOn())
        {
            String midiNote = MidiMessage::getMidiNoteName(message.getNoteNumber(), true, false, 4);
            if (std::find(activeMidiNotes.begin(), activeMidiNotes.end(), midiNote) == activeMidiNotes.end())
            {
                activeMidiNotes.push_back(midiNote);
            }
        }
        else if (message.isNoteOff()) {
            String midiNote = MidiMessage::getMidiNoteName(message.getNoteNumber(), true, false, 4);
            auto it = std::find(activeMidiNotes.begin(), activeMidiNotes.end(), midiNote);
            if (it != activeMidiNotes.end())
                activeMidiNotes.erase(it);
        }
    }
}

//==============================================================================
bool MusicTheoryAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MusicTheoryAudioProcessor::createEditor()
{
    return new PluginEditor (*this);
}

//==============================================================================
void MusicTheoryAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    auto stateTree = state->copyState();
    std::unique_ptr<XmlElement> xml(stateTree.createXml());
    copyXmlToBinary(*xml, destData);
}

void MusicTheoryAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr && xmlState->hasTagName(state->state.getType())) {
        state->replaceState(ValueTree::fromXml(*xmlState));
    }
}

std::vector<String> MusicTheoryAudioProcessor::getActiveMidiNotes()
{
    std::lock_guard<std::mutex> lock(midiNotesMutex);
    // Return copy of the active MIDI notes for use in the editor
    return activeMidiNotes;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MusicTheoryAudioProcessor();
}
