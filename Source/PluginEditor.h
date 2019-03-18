/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "BasicNote.h"
#include "Note.h"
#include "Interval.h"
#include "Scale.h"
#include "BasicScale.h"
#include "Chord.h"
#include "BasicChord.h"
#include "PluginProcessor.h"
#include <sstream>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public AudioProcessorEditor,
                      public ComboBox::Listener
{
public:
    //==============================================================================
    PluginEditor (MusicTheoryAudioProcessor& p);
    ~PluginEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> groupComponent;
    ScopedPointer<GroupComponent> groupComponent4;
    ScopedPointer<GroupComponent> groupComponent3;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<ComboBox> scaleKey;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<ComboBox> comboBox2;
    ScopedPointer<ComboBox> scaleMode;
    ScopedPointer<ComboBox> comboBox4;
    ScopedPointer<ComboBox> comboBox5;
    ScopedPointer<TextEditor> textEditor2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
