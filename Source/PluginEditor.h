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
	void updateScale();
	void updateChord();
	juce::String simplifyNotes(std::string str);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* screenshot_20190321Blank20Pdf_png;
    static const int screenshot_20190321Blank20Pdf_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	std::vector<juce::ScopedPointer<juce::TextEditor>> texteditors;
	std::vector<juce::ScopedPointer<juce::TextEditor>> guitarnotes; // Vector to store guitar neck notes

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
    ScopedPointer<ComboBox> chordRoot;
    ScopedPointer<ComboBox> chordType;
    ScopedPointer<TextEditor> textEditor2;
    ScopedPointer<TextEditor> txtScale;
    ScopedPointer<TextEditor> txtChord;
    ScopedPointer<TextEditor> GS4;
    ScopedPointer<TextEditor> DS3;
    ScopedPointer<TextEditor> AS2;
    ScopedPointer<TextEditor> F1;
    ScopedPointer<TextEditor> C5;
    ScopedPointer<TextEditor> F2;
    ScopedPointer<TextEditor> A4;
    ScopedPointer<TextEditor> E3;
    ScopedPointer<TextEditor> B2;
    ScopedPointer<TextEditor> FS;
    ScopedPointer<TextEditor> CS5;
    ScopedPointer<TextEditor> FS6;
    ScopedPointer<TextEditor> AS4;
    ScopedPointer<TextEditor> F;
    ScopedPointer<TextEditor> C2;
    ScopedPointer<TextEditor> G;
    ScopedPointer<TextEditor> D5;
    ScopedPointer<TextEditor> G6;
    ScopedPointer<TextEditor> B4;
    ScopedPointer<TextEditor> FS3;
    ScopedPointer<TextEditor> CS2;
    ScopedPointer<TextEditor> GS;
    ScopedPointer<TextEditor> DS5;
    ScopedPointer<TextEditor> GS6;
    ScopedPointer<TextEditor> C4;
    ScopedPointer<TextEditor> G3;
    ScopedPointer<TextEditor> D2;
    ScopedPointer<TextEditor> A;
    ScopedPointer<TextEditor> E5;
    ScopedPointer<TextEditor> A6;
    ScopedPointer<TextEditor> CS4;
    ScopedPointer<TextEditor> GS3;
    ScopedPointer<TextEditor> DS2;
    ScopedPointer<TextEditor> AS;
    ScopedPointer<TextEditor> F5;
    ScopedPointer<TextEditor> AS6;
    ScopedPointer<TextEditor> D4;
    ScopedPointer<TextEditor> A3;
    ScopedPointer<TextEditor> E2;
    ScopedPointer<TextEditor> B;
    ScopedPointer<TextEditor> FS5;
    ScopedPointer<TextEditor> B6;
    ScopedPointer<TextEditor> DS4;
    ScopedPointer<TextEditor> AS3;
    ScopedPointer<TextEditor> F3;
    ScopedPointer<TextEditor> C;
    ScopedPointer<TextEditor> G5;
    ScopedPointer<TextEditor> C6;
    ScopedPointer<TextEditor> E4;
    ScopedPointer<TextEditor> B3;
    ScopedPointer<TextEditor> FS2;
    ScopedPointer<TextEditor> CS;
    ScopedPointer<TextEditor> GS5;
    ScopedPointer<TextEditor> CS6;
    ScopedPointer<TextEditor> F4;
    ScopedPointer<TextEditor> C3;
    ScopedPointer<TextEditor> G2;
    ScopedPointer<TextEditor> D;
    ScopedPointer<TextEditor> A5;
    ScopedPointer<TextEditor> D6;
    ScopedPointer<TextEditor> FS4;
    ScopedPointer<TextEditor> CS3;
    ScopedPointer<TextEditor> GS2;
    ScopedPointer<TextEditor> DS;
    ScopedPointer<TextEditor> AS5;
    ScopedPointer<TextEditor> DS6;
    ScopedPointer<TextEditor> G4;
    ScopedPointer<TextEditor> D3;
    ScopedPointer<TextEditor> A2;
    ScopedPointer<TextEditor> E;
    ScopedPointer<TextEditor> B5;
    ScopedPointer<TextEditor> E6;
    Image cachedImage_screenshot_20190321Blank20Pdf_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
