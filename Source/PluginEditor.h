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
#include <memory>
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
	std::vector<std::unique_ptr<juce::TextEditor>> texteditors;
	std::vector<std::unique_ptr<juce::TextEditor>> guitarnotes; // Vector to store guitar neck notes

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<GroupComponent> groupComponent4;
    std::unique_ptr<GroupComponent> groupComponent3;
    std::unique_ptr<GroupComponent> groupComponent2;
    std::unique_ptr<ComboBox> scaleKey;
    std::unique_ptr<ComboBox> comboBox2;
    std::unique_ptr<ComboBox> scaleMode;
    std::unique_ptr<ComboBox> chordRoot;
    std::unique_ptr<ComboBox> chordType;
    std::unique_ptr<TextEditor> textEditor2;
    std::unique_ptr<TextEditor> txtScale;
    std::unique_ptr<TextEditor> txtChord;
    std::unique_ptr<TextEditor> GS4;
    std::unique_ptr<TextEditor> DS3;
    std::unique_ptr<TextEditor> AS2;
    std::unique_ptr<TextEditor> F1;
    std::unique_ptr<TextEditor> C5;
    std::unique_ptr<TextEditor> F2;
    std::unique_ptr<TextEditor> A4;
    std::unique_ptr<TextEditor> E3;
    std::unique_ptr<TextEditor> B2;
    std::unique_ptr<TextEditor> FS;
    std::unique_ptr<TextEditor> CS5;
    std::unique_ptr<TextEditor> FS6;
    std::unique_ptr<TextEditor> AS4;
    std::unique_ptr<TextEditor> F;
    std::unique_ptr<TextEditor> C2;
    std::unique_ptr<TextEditor> G;
    std::unique_ptr<TextEditor> D5;
    std::unique_ptr<TextEditor> G6;
    std::unique_ptr<TextEditor> B4;
    std::unique_ptr<TextEditor> FS3;
    std::unique_ptr<TextEditor> CS2;
    std::unique_ptr<TextEditor> GS;
    std::unique_ptr<TextEditor> DS5;
    std::unique_ptr<TextEditor> GS6;
    std::unique_ptr<TextEditor> C4;
    std::unique_ptr<TextEditor> G3;
    std::unique_ptr<TextEditor> D2;
    std::unique_ptr<TextEditor> A;
    std::unique_ptr<TextEditor> E5;
    std::unique_ptr<TextEditor> A6;
    std::unique_ptr<TextEditor> CS4;
    std::unique_ptr<TextEditor> GS3;
    std::unique_ptr<TextEditor> DS2;
    std::unique_ptr<TextEditor> AS;
    std::unique_ptr<TextEditor> F5;
    std::unique_ptr<TextEditor> AS6;
    std::unique_ptr<TextEditor> D4;
    std::unique_ptr<TextEditor> A3;
    std::unique_ptr<TextEditor> E2;
    std::unique_ptr<TextEditor> B;
    std::unique_ptr<TextEditor> FS5;
    std::unique_ptr<TextEditor> B6;
    std::unique_ptr<TextEditor> DS4;
    std::unique_ptr<TextEditor> AS3;
    std::unique_ptr<TextEditor> F3;
    std::unique_ptr<TextEditor> C;
    std::unique_ptr<TextEditor> G5;
    std::unique_ptr<TextEditor> C6;
    std::unique_ptr<TextEditor> E4;
    std::unique_ptr<TextEditor> B3;
    std::unique_ptr<TextEditor> FS2;
    std::unique_ptr<TextEditor> CS;
    std::unique_ptr<TextEditor> GS5;
    std::unique_ptr<TextEditor> CS6;
    std::unique_ptr<TextEditor> F4;
    std::unique_ptr<TextEditor> C3;
    std::unique_ptr<TextEditor> G2;
    std::unique_ptr<TextEditor> D;
    std::unique_ptr<TextEditor> A5;
    std::unique_ptr<TextEditor> D6;
    std::unique_ptr<TextEditor> FS4;
    std::unique_ptr<TextEditor> CS3;
    std::unique_ptr<TextEditor> GS2;
    std::unique_ptr<TextEditor> DS;
    std::unique_ptr<TextEditor> AS5;
    std::unique_ptr<TextEditor> DS6;
    std::unique_ptr<TextEditor> G4;
    std::unique_ptr<TextEditor> D3;
    std::unique_ptr<TextEditor> A2;
    std::unique_ptr<TextEditor> E;
    std::unique_ptr<TextEditor> B5;
    std::unique_ptr<TextEditor> E6;
    std::unique_ptr<TextEditor> GS7;
    std::unique_ptr<TextEditor> DS7;
    std::unique_ptr<TextEditor> AS7;
    std::unique_ptr<TextEditor> F6;
    std::unique_ptr<TextEditor> C7;
    std::unique_ptr<TextEditor> F7;
    std::unique_ptr<TextEditor> A7;
    std::unique_ptr<TextEditor> E7;
    std::unique_ptr<TextEditor> B7;
    std::unique_ptr<TextEditor> FS7;
    std::unique_ptr<TextEditor> CS7;
    std::unique_ptr<TextEditor> FS8;
    std::unique_ptr<TextEditor> AS8;
    std::unique_ptr<TextEditor> F8;
    std::unique_ptr<TextEditor> C8;
    std::unique_ptr<TextEditor> G7;
    std::unique_ptr<TextEditor> D7;
    std::unique_ptr<TextEditor> G8;
    std::unique_ptr<TextEditor> B8;
    std::unique_ptr<TextEditor> FS9;
    std::unique_ptr<TextEditor> CS8;
    std::unique_ptr<TextEditor> GS8;
    std::unique_ptr<TextEditor> DS8;
    std::unique_ptr<TextEditor> GS9;
    std::unique_ptr<TextEditor> C9;
    std::unique_ptr<TextEditor> G9;
    std::unique_ptr<TextEditor> D8;
    std::unique_ptr<TextEditor> A8;
    std::unique_ptr<TextEditor> E8;
    std::unique_ptr<TextEditor> A9;
    std::unique_ptr<TextEditor> CS9;
    std::unique_ptr<TextEditor> GS10;
    std::unique_ptr<TextEditor> DS9;
    std::unique_ptr<TextEditor> AS9;
    std::unique_ptr<TextEditor> F9;
    std::unique_ptr<TextEditor> AS10;
    std::unique_ptr<TextEditor> D9;
    std::unique_ptr<TextEditor> A10;
    std::unique_ptr<TextEditor> E9;
    std::unique_ptr<TextEditor> B9;
    std::unique_ptr<TextEditor> FS10;
    std::unique_ptr<TextEditor> B10;
    std::unique_ptr<TextEditor> DS10;
    std::unique_ptr<TextEditor> AS11;
    std::unique_ptr<TextEditor> F10;
    std::unique_ptr<TextEditor> C10;
    std::unique_ptr<TextEditor> G10;
    std::unique_ptr<TextEditor> C11;
    std::unique_ptr<Image> cachedImage_gneck_inverted_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
