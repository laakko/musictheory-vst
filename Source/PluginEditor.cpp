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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
using namespace acentric_core;
Note scaleroot = Note{ BasicNote::C };
Note chordroot = Note{ BasicNote::C };
BasicScale scaletype = BasicScale{ BasicScale::Major };
BasicChord chordtype = BasicChord{ BasicChord::maj };
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (MusicTheoryAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..

    //[/Constructor_pre]

    addAndMakeVisible (groupComponent = new GroupComponent ("new group",
                                                            TRANS("guitar")));
    groupComponent->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (groupComponent4 = new GroupComponent ("new group",
                                                             TRANS("scales")));
    groupComponent4->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (groupComponent3 = new GroupComponent ("new group",
                                                             TRANS("notes")));
    groupComponent3->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("chords")));
    groupComponent2->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (scaleKey = new ComboBox ("new combo box"));
    scaleKey->setEditableText (false);
    scaleKey->setJustificationType (Justification::centredLeft);
    scaleKey->setTextWhenNothingSelected (TRANS("none"));
    scaleKey->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    scaleKey->addItem (TRANS("C"), 1);
    scaleKey->addItem (TRANS("C#"), 2);
    scaleKey->addItem (TRANS("D"), 3);
    scaleKey->addItem (TRANS("D#"), 4);
    scaleKey->addItem (TRANS("E"), 5);
    scaleKey->addItem (TRANS("F"), 6);
    scaleKey->addItem (TRANS("F#"), 7);
    scaleKey->addItem (TRANS("G"), 8);
    scaleKey->addItem (TRANS("G#"), 9);
    scaleKey->addItem (TRANS("A"), 10);
    scaleKey->addItem (TRANS("A#"), 11);
    scaleKey->addItem (TRANS("B"), 12);
    scaleKey->addListener (this);

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (true);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (false);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setColour (TextEditor::backgroundColourId, Colours::cadetblue);
    textEditor->setText (TRANS("Debug"));

    addAndMakeVisible (comboBox2 = new ComboBox ("new combo box"));
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (TRANS("Notes"));
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox2->addItem (TRANS("Notes"), 1);
    comboBox2->addItem (TRANS("Scales"), 2);
    comboBox2->addItem (TRANS("Chords"), 3);
    comboBox2->addListener (this);

    addAndMakeVisible (scaleMode = new ComboBox ("new combo box"));
    scaleMode->setEditableText (false);
    scaleMode->setJustificationType (Justification::centredLeft);
    scaleMode->setTextWhenNothingSelected (TRANS("none"));
    scaleMode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    scaleMode->addItem (TRANS("Major"), 1);
    scaleMode->addItem (TRANS("Minor"), 2);
    scaleMode->addItem (TRANS("Harmonic Minor"), 3);
    scaleMode->addItem (TRANS("Blues"), 4);
    scaleMode->addItem (TRANS("Minor Pentatonic"), 5);
    scaleMode->addItem (TRANS("Major Pentatonic"), 6);
    scaleMode->addItem (TRANS("Dorian"), 7);
    scaleMode->addItem (TRANS("Lydian"), 8);
    scaleMode->addItem (TRANS("Mixolydian"), 9);
    scaleMode->addItem (TRANS("Phrygian"), 10);
    scaleMode->addListener (this);

    addAndMakeVisible (chordRoot = new ComboBox ("new combo box"));
    chordRoot->setEditableText (false);
    chordRoot->setJustificationType (Justification::centredLeft);
    chordRoot->setTextWhenNothingSelected (TRANS("root"));
    chordRoot->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    chordRoot->addItem (TRANS("C"), 1);
    chordRoot->addItem (TRANS("C#"), 2);
    chordRoot->addItem (TRANS("D"), 3);
    chordRoot->addItem (TRANS("D#"), 4);
    chordRoot->addItem (TRANS("E"), 5);
    chordRoot->addItem (TRANS("F"), 6);
    chordRoot->addItem (TRANS("F#"), 7);
    chordRoot->addItem (TRANS("G"), 8);
    chordRoot->addItem (TRANS("G#"), 9);
    chordRoot->addItem (TRANS("A"), 10);
    chordRoot->addItem (TRANS("A#"), 11);
    chordRoot->addItem (TRANS("B"), 12);
    chordRoot->addListener (this);

    addAndMakeVisible (chordType = new ComboBox ("new combo box"));
    chordType->setEditableText (false);
    chordType->setJustificationType (Justification::centredLeft);
    chordType->setTextWhenNothingSelected (TRANS("type"));
    chordType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    chordType->addItem (TRANS("m"), 1);
    chordType->addItem (TRANS("M"), 2);
    chordType->addItem (TRANS("aug"), 3);
    chordType->addItem (TRANS("M7"), 4);
    chordType->addItem (TRANS("m7"), 5);
    chordType->addListener (this);

    addAndMakeVisible (textEditor2 = new TextEditor ("new text editor"));
    textEditor2->setMultiLine (true);
    textEditor2->setReturnKeyStartsNewLine (true);
    textEditor2->setReadOnly (false);
    textEditor2->setScrollbarsShown (true);
    textEditor2->setCaretVisible (true);
    textEditor2->setPopupMenuEnabled (true);
    textEditor2->setColour (TextEditor::backgroundColourId, Colour (0xff508385));
    textEditor2->setText (TRANS("write anything here ...\n"));

    addAndMakeVisible (txtScale = new TextEditor ("new text editor"));
    txtScale->setMultiLine (true);
    txtScale->setReturnKeyStartsNewLine (false);
    txtScale->setReadOnly (true);
    txtScale->setScrollbarsShown (false);
    txtScale->setCaretVisible (false);
    txtScale->setPopupMenuEnabled (false);
    txtScale->setColour (TextEditor::backgroundColourId, Colours::cadetblue);
    txtScale->setText (String());

    addAndMakeVisible (txtChord = new TextEditor ("new text editor"));
    txtChord->setMultiLine (true);
    txtChord->setReturnKeyStartsNewLine (false);
    txtChord->setReadOnly (true);
    txtChord->setScrollbarsShown (false);
    txtChord->setCaretVisible (false);
    txtChord->setPopupMenuEnabled (false);
    txtChord->setColour (TextEditor::backgroundColourId, Colours::cadetblue);
    txtChord->setText (String());


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 800);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent = nullptr;
    groupComponent4 = nullptr;
    groupComponent3 = nullptr;
    groupComponent2 = nullptr;
    scaleKey = nullptr;
    textEditor = nullptr;
    comboBox2 = nullptr;
    scaleMode = nullptr;
    chordRoot = nullptr;
    chordType = nullptr;
    textEditor2 = nullptr;
    txtScale = nullptr;
    txtChord = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::cadetblue);

    {
        int x = 20, y = 276, width = 200, height = 30;
        String text (TRANS("KEY"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 26.40f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 28, y = 8, width = 1076, height = 72;
        String text (TRANS("MTHVST"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 67.30f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 468, y = 196, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 468, y = 228, width = 588, height = 4;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 468, y = 260, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 468, y = 292, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 468, y = 324, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 476, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 524, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 572, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 620, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 668, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 716, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 764, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 812, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 860, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 908, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 956, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 1004, y = 136, width = 5, height = 192;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 572, y = 332, width = 44, height = 30;
        String text (TRANS("3"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 668, y = 332, width = 44, height = 30;
        String text (TRANS("5"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 332, width = 44, height = 30;
        String text (TRANS("7"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 860, y = 332, width = 44, height = 30;
        String text (TRANS("9"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1004, y = 332, width = 44, height = 30;
        String text (TRANS("12"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1052, y = 134, width = 5, height = 195;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 628, y = 300, width = 36, height = 20;
        String text (TRANS("G#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 300, width = 36, height = 20;
        String text (TRANS("G"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 532, y = 300, width = 36, height = 20;
        String text (TRANS("F#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 484, y = 300, width = 36, height = 20;
        String text (TRANS("F"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 676, y = 300, width = 36, height = 20;
        String text (TRANS("A"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 724, y = 300, width = 36, height = 20;
        String text (TRANS("A#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 300, width = 36, height = 20;
        String text (TRANS("B"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 820, y = 300, width = 36, height = 20;
        String text (TRANS("C"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 868, y = 300, width = 36, height = 20;
        String text (TRANS("C#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 916, y = 300, width = 36, height = 20;
        String text (TRANS("D"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 964, y = 300, width = 36, height = 20;
        String text (TRANS("D#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1012, y = 300, width = 36, height = 20;
        String text (TRANS("E"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 628, y = 268, width = 36, height = 20;
        String text (TRANS("C#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 268, width = 36, height = 20;
        String text (TRANS("C"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 532, y = 268, width = 36, height = 20;
        String text (TRANS("B"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 484, y = 268, width = 36, height = 20;
        String text (TRANS("A#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 676, y = 268, width = 36, height = 20;
        String text (TRANS("D"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 724, y = 268, width = 36, height = 20;
        String text (TRANS("D#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 268, width = 36, height = 20;
        String text (TRANS("E"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 820, y = 268, width = 36, height = 20;
        String text (TRANS("F"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 868, y = 268, width = 36, height = 20;
        String text (TRANS("F#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 916, y = 268, width = 36, height = 20;
        String text (TRANS("G"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 964, y = 268, width = 36, height = 20;
        String text (TRANS("G#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1012, y = 268, width = 36, height = 20;
        String text (TRANS("A"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 628, y = 204, width = 36, height = 20;
        String text (TRANS("B"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 204, width = 36, height = 20;
        String text (TRANS("A#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 532, y = 204, width = 36, height = 20;
        String text (TRANS("A"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 484, y = 204, width = 36, height = 20;
        String text (TRANS("G#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 676, y = 204, width = 36, height = 20;
        String text (TRANS("C"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 724, y = 204, width = 36, height = 20;
        String text (TRANS("C#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 204, width = 36, height = 20;
        String text (TRANS("D"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 820, y = 204, width = 36, height = 20;
        String text (TRANS("D#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 868, y = 204, width = 36, height = 20;
        String text (TRANS("E"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 916, y = 204, width = 36, height = 20;
        String text (TRANS("F"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 964, y = 204, width = 36, height = 20;
        String text (TRANS("F#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1012, y = 204, width = 36, height = 20;
        String text (TRANS("G"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 628, y = 236, width = 36, height = 20;
        String text (TRANS("F#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 236, width = 36, height = 20;
        String text (TRANS("F"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 532, y = 236, width = 36, height = 20;
        String text (TRANS("E"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 484, y = 236, width = 36, height = 20;
        String text (TRANS("D#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 676, y = 236, width = 36, height = 20;
        String text (TRANS("G"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 724, y = 236, width = 36, height = 20;
        String text (TRANS("G#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 236, width = 36, height = 20;
        String text (TRANS("A"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 820, y = 236, width = 36, height = 20;
        String text (TRANS("A#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 868, y = 236, width = 36, height = 20;
        String text (TRANS("B"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 916, y = 236, width = 36, height = 20;
        String text (TRANS("C"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 964, y = 236, width = 36, height = 20;
        String text (TRANS("C#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1012, y = 236, width = 36, height = 20;
        String text (TRANS("D"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 628, y = 172, width = 36, height = 20;
        String text (TRANS("D#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 172, width = 36, height = 20;
        String text (TRANS("D"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 532, y = 172, width = 36, height = 20;
        String text (TRANS("C#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 484, y = 172, width = 36, height = 20;
        String text (TRANS("C"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 676, y = 172, width = 36, height = 20;
        String text (TRANS("E"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 724, y = 172, width = 36, height = 20;
        String text (TRANS("F"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 172, width = 36, height = 20;
        String text (TRANS("F#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 820, y = 172, width = 36, height = 20;
        String text (TRANS("G"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 868, y = 172, width = 36, height = 20;
        String text (TRANS("G#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 916, y = 172, width = 36, height = 20;
        String text (TRANS("A"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 964, y = 172, width = 36, height = 20;
        String text (TRANS("A#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1012, y = 172, width = 36, height = 20;
        String text (TRANS("B"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 628, y = 140, width = 36, height = 20;
        String text (TRANS("G#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 580, y = 140, width = 36, height = 20;
        String text (TRANS("G"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 532, y = 140, width = 36, height = 20;
        String text (TRANS("F#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 676, y = 140, width = 36, height = 20;
        String text (TRANS("A"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 724, y = 140, width = 36, height = 20;
        String text (TRANS("A#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 140, width = 36, height = 20;
        String text (TRANS("B"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 820, y = 140, width = 36, height = 20;
        String text (TRANS("C"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 868, y = 140, width = 36, height = 20;
        String text (TRANS("C#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 916, y = 140, width = 36, height = 20;
        String text (TRANS("D"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 964, y = 140, width = 36, height = 20;
        String text (TRANS("D#"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 1012, y = 140, width = 36, height = 20;
        String text (TRANS("E"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 468, y = 164, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 468, y = 132, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 180, y = 276, width = 200, height = 30;
        String text (TRANS("MODE/SCALE"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 26.40f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 52, y = 100, width = 200, height = 30;
        String text (TRANS("CHORD"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 26.40f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 484, y = 140, width = 36, height = 20;
        String text (TRANS("F"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    groupComponent->setBounds (392, 72, 744, 358);
    groupComponent4->setBounds (48, 248, 344, 182);
    groupComponent3->setBounds (48, 425, 1088, 264);
    groupComponent2->setBounds (48, 72, 344, 176);
    scaleKey->setBounds (96, 304, 88, 24);
    textEditor->setBounds (608, 384, 150, 24);
    comboBox2->setBounds (592, 88, 150, 24);
    scaleMode->setBounds (208, 304, 168, 24);
    chordRoot->setBounds (96, 136, 64, 24);
    chordType->setBounds (168, 136, 88, 24);
    textEditor2->setBounds (56, 440, 1056, 240);
    txtScale->setBounds (96, 352, 272, 48);
    txtChord->setBounds (96, 176, 272, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == scaleKey)
    {
        //[UserComboBoxCode_scaleKey] -- add your combo box handling code here..

		std::string scalekeystr = scaleKey->getText().toStdString();
		char scalekeychar = scalekeystr[0];

		int offset = 0;
		if (scalekeystr[1] != NULL) {
			offset = 1;
		}

		scaleroot = Note{ scalekeychar, offset,4 };
		updateScale();

        //[/UserComboBoxCode_scaleKey]
    }
    else if (comboBoxThatHasChanged == comboBox2)
    {
        //[UserComboBoxCode_comboBox2] -- add your combo box handling code here..
		if (comboBox2->getText() == "Scales") {
			// Show only notes that are in the chosen scale
			texteditors.at(0)->setText(TRANS("scales"));
		}
		else if (comboBox2->getText() == "Chords") {
			// Show only notes that are in the chosen chords
			texteditors.at(0)->setText(TRANS("chords"));
		}
		else if (comboBox2->getText() == "Notes") {
			// Show all notes
			texteditors.at(0)->setText(TRANS("notes"));
		}
        //[/UserComboBoxCode_comboBox2]
    }
    else if (comboBoxThatHasChanged == scaleMode)
    {
        //[UserComboBoxCode_scaleMode] -- add your combo box handling code here..
		std::string scalemodestr = scaleMode->getText().toStdString();

		if (scalemodestr == "Major") {
			scaletype = BasicScale{ BasicScale::Major };
			updateScale();
		}
		else if (scalemodestr == "Minor") {
			scaletype = BasicScale{ BasicScale::Minor };
			updateScale();
		}
		else if (scalemodestr == "Harmonic Minor") {
			scaletype = BasicScale{ BasicScale::HarmonicMinor };
			updateScale();
		}
		else if (scalemodestr == "Minor Pentatonic") {
			scaletype = BasicScale{ BasicScale::MinorPentatonic };
			updateScale();
		}
		else if (scalemodestr == "Major Pentatonic") {
			scaletype = BasicScale{ BasicScale::MajorPentatonic };
			updateScale();
		}
		else if (scalemodestr == "Blues") {
			scaletype = BasicScale{ BasicScale::Blues };
			updateScale();
		}
		else if (scalemodestr == "Dorian") {
			scaletype = BasicScale{ BasicScale::Dorian };
			updateScale();
		}
		else if (scalemodestr == "Lydian") {
			scaletype = BasicScale{ BasicScale::Lydian};
			updateScale();
		}
		else if (scalemodestr == "Mixolydian") {
			scaletype = BasicScale{ BasicScale::Mixolydian };
			updateScale();
		}
		else if (scalemodestr == "Phrygian") {
			scaletype = BasicScale{ BasicScale::Phrygian};
			updateScale();
		}
		else if (scalemodestr == "Aeolian") {
			scaletype = BasicScale{ BasicScale::Aeolian };
			updateScale();
		}
		else if (scalemodestr == "Ionian") {
			scaletype = BasicScale{ BasicScale::Ionian};
			updateScale();
		}
		else if (scalemodestr == "Locrian") {
			scaletype = BasicScale{ BasicScale::Locrian};
			updateScale();
		}
		else if (scalemodestr == "Metallica") {
			scaletype = BasicScale{ BasicScale::Metallica };
			updateScale();
		}
		else {
			txtScale->setText(TRANS("invalid scale type"));
		}

        //[/UserComboBoxCode_scaleMode]
    }
    else if (comboBoxThatHasChanged == chordRoot)
    {
        //[UserComboBoxCode_chordRoot] -- add your combo box handling code here..
		std::string chordkeystr = chordRoot->getText().toStdString();
		char chordkeychar = chordkeystr[0];

		int offset = 0;
		if (chordkeystr[1] != NULL) {
			offset = 1;
		}

		chordroot = Note{ chordkeychar, offset,4 };
		updateChord();
        //[/UserComboBoxCode_chordRoot]
    }
    else if (comboBoxThatHasChanged == chordType)
    {
        //[UserComboBoxCode_chordType] -- add your combo box handling code here..
		std::string chordtypestr = chordType->getText().toStdString();

		if (chordtypestr == "M") {
			chordtype = BasicChord{ BasicChord::maj };
			updateChord();
		}
		else if (chordtypestr == "m") {
			chordtype = BasicChord{ BasicChord::min};
			updateChord();
		}
		else if (chordtypestr == "M7") {
			chordtype = BasicChord{ BasicChord::maj7 };
			updateChord();
		}
		else if (chordtypestr == "m7") {
			chordtype = BasicChord{ BasicChord::min7 };
			updateChord();
		}
		else if (chordtypestr == "aug") {
			chordtype = BasicChord{ BasicChord::aug };
			updateChord();
		}
		else {
			txtChord->setText(TRANS("Invalid chord type"));
		}
        //[/UserComboBoxCode_chordType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginEditor::updateScale() {
	std::ostringstream stream;
	stream << Scale(scaleroot, scaletype) << std::endl;
	std::string scalestr = stream.str();
	txtScale->setText(scalestr);
}

void PluginEditor::updateChord() {
	std::ostringstream stream;
	stream << Chord(chordroot, chordtype) << std::endl;
	std::string chordstr = stream.str();
	txtChord->setText(chordstr);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="MusicTheoryAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1200" initialHeight="800">
  <BACKGROUND backgroundColour="ff5f9ea0">
    <TEXT pos="20 276 200 30" fill="solid: ff000000" hasStroke="0" text="KEY"
          fontname="Arca Majora 3" fontsize="26.399999999999998579" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="28 8 1076 72" fill="solid: ff000000" hasStroke="0" text="MTHVST"
          fontname="Arca Majora 3" fontsize="67.299999999999997158" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <RECT pos="468 196 588 5" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="468 228 588 4" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="468 260 588 5" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="468 292 588 5" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="468 324 588 5" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="476 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="524 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="572 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="620 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="668 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="716 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="764 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="812 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="860 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="908 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="956 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="1004 136 5 192" fill="solid: ff000000" hasStroke="0"/>
    <TEXT pos="572 332 44 30" fill="solid: ff000000" hasStroke="0" text="3"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="668 332 44 30" fill="solid: ff000000" hasStroke="0" text="5"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 332 44 30" fill="solid: ff000000" hasStroke="0" text="7"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="860 332 44 30" fill="solid: ff000000" hasStroke="0" text="9"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1004 332 44 30" fill="solid: ff000000" hasStroke="0" text="12"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <RECT pos="1052 134 5 195" fill="solid: ff000000" hasStroke="0"/>
    <TEXT pos="628 300 36 20" fill="solid: ff000000" hasStroke="0" text="G#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="580 300 36 20" fill="solid: ff000000" hasStroke="0" text="G"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="532 300 36 20" fill="solid: ff000000" hasStroke="0" text="F#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="484 300 36 20" fill="solid: ff000000" hasStroke="0" text="F"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="676 300 36 20" fill="solid: ff000000" hasStroke="0" text="A"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="724 300 36 20" fill="solid: ff000000" hasStroke="0" text="A#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 300 36 20" fill="solid: ff000000" hasStroke="0" text="B"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="820 300 36 20" fill="solid: ff000000" hasStroke="0" text="C"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="868 300 36 20" fill="solid: ff000000" hasStroke="0" text="C#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="916 300 36 20" fill="solid: ff000000" hasStroke="0" text="D"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="964 300 36 20" fill="solid: ff000000" hasStroke="0" text="D#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1012 300 36 20" fill="solid: ff000000" hasStroke="0" text="E"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="628 268 36 20" fill="solid: ff000000" hasStroke="0" text="C#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="580 268 36 20" fill="solid: ff000000" hasStroke="0" text="C"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="532 268 36 20" fill="solid: ff000000" hasStroke="0" text="B"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="484 268 36 20" fill="solid: ff000000" hasStroke="0" text="A#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="676 268 36 20" fill="solid: ff000000" hasStroke="0" text="D"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="724 268 36 20" fill="solid: ff000000" hasStroke="0" text="D#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 268 36 20" fill="solid: ff000000" hasStroke="0" text="E"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="820 268 36 20" fill="solid: ff000000" hasStroke="0" text="F"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="868 268 36 20" fill="solid: ff000000" hasStroke="0" text="F#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="916 268 36 20" fill="solid: ff000000" hasStroke="0" text="G"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="964 268 36 20" fill="solid: ff000000" hasStroke="0" text="G#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1012 268 36 20" fill="solid: ff000000" hasStroke="0" text="A"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="628 204 36 20" fill="solid: ff000000" hasStroke="0" text="B"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="580 204 36 20" fill="solid: ff000000" hasStroke="0" text="A#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="532 204 36 20" fill="solid: ff000000" hasStroke="0" text="A"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="484 204 36 20" fill="solid: ff000000" hasStroke="0" text="G#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="676 204 36 20" fill="solid: ff000000" hasStroke="0" text="C"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="724 204 36 20" fill="solid: ff000000" hasStroke="0" text="C#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 204 36 20" fill="solid: ff000000" hasStroke="0" text="D"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="820 204 36 20" fill="solid: ff000000" hasStroke="0" text="D#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="868 204 36 20" fill="solid: ff000000" hasStroke="0" text="E"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="916 204 36 20" fill="solid: ff000000" hasStroke="0" text="F"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="964 204 36 20" fill="solid: ff000000" hasStroke="0" text="F#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1012 204 36 20" fill="solid: ff000000" hasStroke="0" text="G"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="628 236 36 20" fill="solid: ff000000" hasStroke="0" text="F#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="580 236 36 20" fill="solid: ff000000" hasStroke="0" text="F"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="532 236 36 20" fill="solid: ff000000" hasStroke="0" text="E"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="484 236 36 20" fill="solid: ff000000" hasStroke="0" text="D#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="676 236 36 20" fill="solid: ff000000" hasStroke="0" text="G"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="724 236 36 20" fill="solid: ff000000" hasStroke="0" text="G#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 236 36 20" fill="solid: ff000000" hasStroke="0" text="A"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="820 236 36 20" fill="solid: ff000000" hasStroke="0" text="A#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="868 236 36 20" fill="solid: ff000000" hasStroke="0" text="B"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="916 236 36 20" fill="solid: ff000000" hasStroke="0" text="C"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="964 236 36 20" fill="solid: ff000000" hasStroke="0" text="C#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1012 236 36 20" fill="solid: ff000000" hasStroke="0" text="D"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="628 172 36 20" fill="solid: ff000000" hasStroke="0" text="D#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="580 172 36 20" fill="solid: ff000000" hasStroke="0" text="D"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="532 172 36 20" fill="solid: ff000000" hasStroke="0" text="C#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="484 172 36 20" fill="solid: ff000000" hasStroke="0" text="C"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="676 172 36 20" fill="solid: ff000000" hasStroke="0" text="E"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="724 172 36 20" fill="solid: ff000000" hasStroke="0" text="F"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 172 36 20" fill="solid: ff000000" hasStroke="0" text="F#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="820 172 36 20" fill="solid: ff000000" hasStroke="0" text="G"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="868 172 36 20" fill="solid: ff000000" hasStroke="0" text="G#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="916 172 36 20" fill="solid: ff000000" hasStroke="0" text="A"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="964 172 36 20" fill="solid: ff000000" hasStroke="0" text="A#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1012 172 36 20" fill="solid: ff000000" hasStroke="0" text="B"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="628 140 36 20" fill="solid: ff000000" hasStroke="0" text="G#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="580 140 36 20" fill="solid: ff000000" hasStroke="0" text="G"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="532 140 36 20" fill="solid: ff000000" hasStroke="0" text="F#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="676 140 36 20" fill="solid: ff000000" hasStroke="0" text="A"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="724 140 36 20" fill="solid: ff000000" hasStroke="0" text="A#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="772 140 36 20" fill="solid: ff000000" hasStroke="0" text="B"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="820 140 36 20" fill="solid: ff000000" hasStroke="0" text="C"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="868 140 36 20" fill="solid: ff000000" hasStroke="0" text="C#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="916 140 36 20" fill="solid: ff000000" hasStroke="0" text="D"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="964 140 36 20" fill="solid: ff000000" hasStroke="0" text="D#"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="1012 140 36 20" fill="solid: ff000000" hasStroke="0" text="E"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <RECT pos="468 164 588 5" fill="solid: ff000000" hasStroke="0"/>
    <RECT pos="468 132 588 5" fill="solid: ff000000" hasStroke="0"/>
    <TEXT pos="180 276 200 30" fill="solid: ff000000" hasStroke="0" text="MODE/SCALE"
          fontname="Arca Majora 3" fontsize="26.399999999999998579" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="52 100 200 30" fill="solid: ff000000" hasStroke="0" text="CHORD"
          fontname="Arca Majora 3" fontsize="26.399999999999998579" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="484 140 36 20" fill="solid: ff000000" hasStroke="0" text="F"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="d3e9a3eb7c3fc20b" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="392 72 744 358" outlinecol="ff7fffd4"
                  title="guitar"/>
  <GROUPCOMPONENT name="new group" id="d6a80f42cd589941" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="48 248 344 182" outlinecol="ff7fffd4"
                  title="scales"/>
  <GROUPCOMPONENT name="new group" id="870f042dcaa691d" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="48 425 1088 264" outlinecol="ff7fffd4"
                  title="notes"/>
  <GROUPCOMPONENT name="new group" id="8bfcb5af8d4d4e7a" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="48 72 344 176" outlinecol="ff7fffd4"
                  title="chords"/>
  <COMBOBOX name="new combo box" id="d0bac3320deb23bb" memberName="scaleKey"
            virtualName="" explicitFocusOrder="0" pos="96 304 88 24" editable="0"
            layout="33" items="C&#10;C#&#10;D&#10;D#&#10;E&#10;F&#10;F#&#10;G&#10;G#&#10;A&#10;A#&#10;B"
            textWhenNonSelected="none" textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="new text editor" id="e9702388dec763e6" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="608 384 150 24" bkgcol="ff5f9ea0"
              initialText="Debug" multiline="0" retKeyStartsLine="0" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="28c57b6ee300da4c" memberName="comboBox2"
            virtualName="" explicitFocusOrder="0" pos="592 88 150 24" editable="0"
            layout="33" items="Notes&#10;Scales&#10;Chords" textWhenNonSelected="Notes"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="1c5c8e2cb3a97fca" memberName="scaleMode"
            virtualName="" explicitFocusOrder="0" pos="208 304 168 24" editable="0"
            layout="33" items="Major&#10;Minor&#10;Harmonic Minor&#10;Blues&#10;Minor Pentatonic&#10;Major Pentatonic&#10;Dorian&#10;Lydian&#10;Mixolydian&#10;Phrygian"
            textWhenNonSelected="none" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="5df79c76e34b7dfe" memberName="chordRoot"
            virtualName="" explicitFocusOrder="0" pos="96 136 64 24" editable="0"
            layout="33" items="C&#10;C#&#10;D&#10;D#&#10;E&#10;F&#10;F#&#10;G&#10;G#&#10;A&#10;A#&#10;B"
            textWhenNonSelected="root" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="f1a298a1b78330af" memberName="chordType"
            virtualName="" explicitFocusOrder="0" pos="168 136 88 24" editable="0"
            layout="33" items="m&#10;M&#10;aug&#10;M7&#10;m7" textWhenNonSelected="type"
            textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="new text editor" id="61e50ec73da81d20" memberName="textEditor2"
              virtualName="" explicitFocusOrder="0" pos="56 440 1056 240" bkgcol="ff508385"
              initialText="write anything here ...&#10;" multiline="1" retKeyStartsLine="1"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="f01c2b8f289a8b31" memberName="txtScale"
              virtualName="" explicitFocusOrder="0" pos="96 352 272 48" bkgcol="ff5f9ea0"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e8c8a7592443a9c8" memberName="txtChord"
              virtualName="" explicitFocusOrder="0" pos="96 176 272 48" bkgcol="ff5f9ea0"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
