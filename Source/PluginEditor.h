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
	void updateGuitarNeckScales();
	void updateGuitarNeckChords();
	void resetGuitarNotes();

	juce::String simplifyNotes(std::string str);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

    // Binary resources:
    static const char* screenshot_20190321Blank20Pdf_png;
    static const int screenshot_20190321Blank20Pdf_pngSize;
    static const char* gneck_inverted_png;
    static const int gneck_inverted_pngSize;


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
    ScopedPointer<TextEditor> GS7;
    ScopedPointer<TextEditor> DS7;
    ScopedPointer<TextEditor> AS7;
    ScopedPointer<TextEditor> F6;
    ScopedPointer<TextEditor> C7;
    ScopedPointer<TextEditor> F7;
    ScopedPointer<TextEditor> A7;
    ScopedPointer<TextEditor> E7;
    ScopedPointer<TextEditor> B7;
    ScopedPointer<TextEditor> FS7;
    ScopedPointer<TextEditor> CS7;
    ScopedPointer<TextEditor> FS8;
    ScopedPointer<TextEditor> AS8;
    ScopedPointer<TextEditor> F8;
    ScopedPointer<TextEditor> C8;
    ScopedPointer<TextEditor> G7;
    ScopedPointer<TextEditor> D7;
    ScopedPointer<TextEditor> G8;
    ScopedPointer<TextEditor> B8;
    ScopedPointer<TextEditor> FS9;
    ScopedPointer<TextEditor> CS8;
    ScopedPointer<TextEditor> GS8;
    ScopedPointer<TextEditor> DS8;
    ScopedPointer<TextEditor> GS9;
    ScopedPointer<TextEditor> C9;
    ScopedPointer<TextEditor> G9;
    ScopedPointer<TextEditor> D8;
    ScopedPointer<TextEditor> A8;
    ScopedPointer<TextEditor> E8;
    ScopedPointer<TextEditor> A9;
    ScopedPointer<TextEditor> CS9;
    ScopedPointer<TextEditor> GS10;
    ScopedPointer<TextEditor> DS9;
    ScopedPointer<TextEditor> AS9;
    ScopedPointer<TextEditor> F9;
    ScopedPointer<TextEditor> AS10;
    ScopedPointer<TextEditor> D9;
    ScopedPointer<TextEditor> A10;
    ScopedPointer<TextEditor> E9;
    ScopedPointer<TextEditor> B9;
    ScopedPointer<TextEditor> FS10;
    ScopedPointer<TextEditor> B10;
    ScopedPointer<TextEditor> DS10;
    ScopedPointer<TextEditor> AS11;
    ScopedPointer<TextEditor> F10;
    ScopedPointer<TextEditor> C10;
    ScopedPointer<TextEditor> G10;
    ScopedPointer<TextEditor> C11;
    Image cachedImage_gneck_inverted_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
