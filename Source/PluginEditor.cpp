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
std::string root = "C";
Note scaleroot = Note{ BasicNote::C };
Note chordroot = Note{ BasicNote::C };
BasicScale scaletype = BasicScale{ BasicScale::Major };
BasicChord chordtype = BasicChord{ BasicChord::maj };
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (MusicTheoryAudioProcessor& p)
    : AudioProcessorEditor (&p)
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
                                                             TRANS("notepad")));
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
    textEditor->setMultiLine (true);
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

    addAndMakeVisible (GS4 = new TextEditor ("new text editor"));
    GS4->setMultiLine (true);
    GS4->setReturnKeyStartsNewLine (false);
    GS4->setReadOnly (true);
    GS4->setScrollbarsShown (false);
    GS4->setCaretVisible (false);
    GS4->setPopupMenuEnabled (false);
    GS4->setColour (TextEditor::textColourId, Colours::black);
    GS4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS4->setText (TRANS("G#"));

    addAndMakeVisible (DS3 = new TextEditor ("new text editor"));
    DS3->setMultiLine (true);
    DS3->setReturnKeyStartsNewLine (false);
    DS3->setReadOnly (true);
    DS3->setScrollbarsShown (false);
    DS3->setCaretVisible (false);
    DS3->setPopupMenuEnabled (false);
    DS3->setColour (TextEditor::textColourId, Colours::black);
    DS3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS3->setText (TRANS("D#"));

    addAndMakeVisible (AS2 = new TextEditor ("new text editor"));
    AS2->setMultiLine (true);
    AS2->setReturnKeyStartsNewLine (false);
    AS2->setReadOnly (true);
    AS2->setScrollbarsShown (false);
    AS2->setCaretVisible (false);
    AS2->setPopupMenuEnabled (false);
    AS2->setColour (TextEditor::textColourId, Colours::black);
    AS2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS2->setText (TRANS("A#"));

    addAndMakeVisible (F1 = new TextEditor ("new text editor"));
    F1->setMultiLine (true);
    F1->setReturnKeyStartsNewLine (false);
    F1->setReadOnly (true);
    F1->setScrollbarsShown (false);
    F1->setCaretVisible (false);
    F1->setPopupMenuEnabled (false);
    F1->setColour (TextEditor::textColourId, Colours::black);
    F1->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F1->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F1->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F1->setText (TRANS("F"));

    addAndMakeVisible (C5 = new TextEditor ("new text editor"));
    C5->setMultiLine (true);
    C5->setReturnKeyStartsNewLine (false);
    C5->setReadOnly (true);
    C5->setScrollbarsShown (false);
    C5->setCaretVisible (false);
    C5->setPopupMenuEnabled (false);
    C5->setColour (TextEditor::textColourId, Colours::black);
    C5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C5->setText (TRANS("C"));

    addAndMakeVisible (F2 = new TextEditor ("new text editor"));
    F2->setMultiLine (true);
    F2->setReturnKeyStartsNewLine (false);
    F2->setReadOnly (true);
    F2->setScrollbarsShown (false);
    F2->setCaretVisible (false);
    F2->setPopupMenuEnabled (false);
    F2->setColour (TextEditor::textColourId, Colours::black);
    F2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F2->setText (TRANS("F"));

    addAndMakeVisible (A4 = new TextEditor ("new text editor"));
    A4->setMultiLine (true);
    A4->setReturnKeyStartsNewLine (false);
    A4->setReadOnly (true);
    A4->setScrollbarsShown (false);
    A4->setCaretVisible (false);
    A4->setPopupMenuEnabled (false);
    A4->setColour (TextEditor::textColourId, Colours::black);
    A4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A4->setText (TRANS("A"));

    addAndMakeVisible (E3 = new TextEditor ("new text editor"));
    E3->setMultiLine (true);
    E3->setReturnKeyStartsNewLine (false);
    E3->setReadOnly (true);
    E3->setScrollbarsShown (false);
    E3->setCaretVisible (false);
    E3->setPopupMenuEnabled (false);
    E3->setColour (TextEditor::textColourId, Colours::black);
    E3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E3->setText (TRANS("E"));

    addAndMakeVisible (B2 = new TextEditor ("new text editor"));
    B2->setMultiLine (true);
    B2->setReturnKeyStartsNewLine (false);
    B2->setReadOnly (true);
    B2->setScrollbarsShown (false);
    B2->setCaretVisible (false);
    B2->setPopupMenuEnabled (false);
    B2->setColour (TextEditor::textColourId, Colours::black);
    B2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B2->setText (TRANS("B"));

    addAndMakeVisible (FS = new TextEditor ("new text editor"));
    FS->setMultiLine (true);
    FS->setReturnKeyStartsNewLine (false);
    FS->setReadOnly (true);
    FS->setScrollbarsShown (false);
    FS->setCaretVisible (false);
    FS->setPopupMenuEnabled (false);
    FS->setColour (TextEditor::textColourId, Colours::black);
    FS->setColour (TextEditor::backgroundColourId, Colour (0x3aff0000));
    FS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS->setText (TRANS("\n"
    "F#\n"));

    addAndMakeVisible (CS5 = new TextEditor ("new text editor"));
    CS5->setMultiLine (true);
    CS5->setReturnKeyStartsNewLine (false);
    CS5->setReadOnly (true);
    CS5->setScrollbarsShown (false);
    CS5->setCaretVisible (false);
    CS5->setPopupMenuEnabled (false);
    CS5->setColour (TextEditor::textColourId, Colours::black);
    CS5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS5->setText (TRANS("C#"));

    addAndMakeVisible (FS6 = new TextEditor ("new text editor"));
    FS6->setMultiLine (true);
    FS6->setReturnKeyStartsNewLine (false);
    FS6->setReadOnly (true);
    FS6->setScrollbarsShown (false);
    FS6->setCaretVisible (false);
    FS6->setPopupMenuEnabled (false);
    FS6->setColour (TextEditor::textColourId, Colours::black);
    FS6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS6->setText (TRANS("F#"));

    addAndMakeVisible (AS4 = new TextEditor ("new text editor"));
    AS4->setMultiLine (true);
    AS4->setReturnKeyStartsNewLine (false);
    AS4->setReadOnly (true);
    AS4->setScrollbarsShown (false);
    AS4->setCaretVisible (false);
    AS4->setPopupMenuEnabled (false);
    AS4->setColour (TextEditor::textColourId, Colours::black);
    AS4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS4->setText (TRANS("A#"));

    addAndMakeVisible (F = new TextEditor ("new text editor"));
    F->setMultiLine (true);
    F->setReturnKeyStartsNewLine (false);
    F->setReadOnly (true);
    F->setScrollbarsShown (false);
    F->setCaretVisible (false);
    F->setPopupMenuEnabled (false);
    F->setColour (TextEditor::textColourId, Colours::black);
    F->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F->setText (TRANS("F"));

    addAndMakeVisible (C2 = new TextEditor ("new text editor"));
    C2->setMultiLine (true);
    C2->setReturnKeyStartsNewLine (false);
    C2->setReadOnly (true);
    C2->setScrollbarsShown (false);
    C2->setCaretVisible (false);
    C2->setPopupMenuEnabled (false);
    C2->setColour (TextEditor::textColourId, Colours::black);
    C2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C2->setText (TRANS("C"));

    addAndMakeVisible (G = new TextEditor ("new text editor"));
    G->setMultiLine (true);
    G->setReturnKeyStartsNewLine (false);
    G->setReadOnly (true);
    G->setScrollbarsShown (false);
    G->setCaretVisible (false);
    G->setPopupMenuEnabled (false);
    G->setColour (TextEditor::textColourId, Colours::black);
    G->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G->setText (TRANS("G"));

    addAndMakeVisible (D5 = new TextEditor ("new text editor"));
    D5->setMultiLine (true);
    D5->setReturnKeyStartsNewLine (false);
    D5->setReadOnly (true);
    D5->setScrollbarsShown (false);
    D5->setCaretVisible (false);
    D5->setPopupMenuEnabled (false);
    D5->setColour (TextEditor::textColourId, Colours::black);
    D5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D5->setText (TRANS("D"));

    addAndMakeVisible (G6 = new TextEditor ("new text editor"));
    G6->setMultiLine (true);
    G6->setReturnKeyStartsNewLine (false);
    G6->setReadOnly (true);
    G6->setScrollbarsShown (false);
    G6->setCaretVisible (false);
    G6->setPopupMenuEnabled (false);
    G6->setColour (TextEditor::textColourId, Colours::black);
    G6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G6->setText (TRANS("G"));

    addAndMakeVisible (B4 = new TextEditor ("new text editor"));
    B4->setMultiLine (true);
    B4->setReturnKeyStartsNewLine (false);
    B4->setReadOnly (true);
    B4->setScrollbarsShown (false);
    B4->setCaretVisible (false);
    B4->setPopupMenuEnabled (false);
    B4->setColour (TextEditor::textColourId, Colours::black);
    B4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B4->setText (TRANS("B"));

    addAndMakeVisible (FS3 = new TextEditor ("new text editor"));
    FS3->setMultiLine (true);
    FS3->setReturnKeyStartsNewLine (false);
    FS3->setReadOnly (true);
    FS3->setScrollbarsShown (false);
    FS3->setCaretVisible (false);
    FS3->setPopupMenuEnabled (false);
    FS3->setColour (TextEditor::textColourId, Colours::black);
    FS3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS3->setText (TRANS("F#"));

    addAndMakeVisible (CS2 = new TextEditor ("new text editor"));
    CS2->setMultiLine (true);
    CS2->setReturnKeyStartsNewLine (false);
    CS2->setReadOnly (true);
    CS2->setScrollbarsShown (false);
    CS2->setCaretVisible (false);
    CS2->setPopupMenuEnabled (false);
    CS2->setColour (TextEditor::textColourId, Colours::black);
    CS2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS2->setText (TRANS("C#"));

    addAndMakeVisible (GS = new TextEditor ("new text editor"));
    GS->setMultiLine (true);
    GS->setReturnKeyStartsNewLine (false);
    GS->setReadOnly (true);
    GS->setScrollbarsShown (false);
    GS->setCaretVisible (false);
    GS->setPopupMenuEnabled (false);
    GS->setColour (TextEditor::textColourId, Colours::black);
    GS->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS->setText (TRANS("G#"));

    addAndMakeVisible (DS5 = new TextEditor ("new text editor"));
    DS5->setMultiLine (true);
    DS5->setReturnKeyStartsNewLine (false);
    DS5->setReadOnly (true);
    DS5->setScrollbarsShown (false);
    DS5->setCaretVisible (false);
    DS5->setPopupMenuEnabled (false);
    DS5->setColour (TextEditor::textColourId, Colours::black);
    DS5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS5->setText (TRANS("D#"));

    addAndMakeVisible (GS6 = new TextEditor ("new text editor"));
    GS6->setMultiLine (true);
    GS6->setReturnKeyStartsNewLine (false);
    GS6->setReadOnly (true);
    GS6->setScrollbarsShown (false);
    GS6->setCaretVisible (false);
    GS6->setPopupMenuEnabled (false);
    GS6->setColour (TextEditor::textColourId, Colours::black);
    GS6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS6->setText (TRANS("G#"));

    addAndMakeVisible (C4 = new TextEditor ("new text editor"));
    C4->setMultiLine (true);
    C4->setReturnKeyStartsNewLine (false);
    C4->setReadOnly (true);
    C4->setScrollbarsShown (false);
    C4->setCaretVisible (false);
    C4->setPopupMenuEnabled (false);
    C4->setColour (TextEditor::textColourId, Colours::black);
    C4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C4->setText (TRANS("C"));

    addAndMakeVisible (G3 = new TextEditor ("new text editor"));
    G3->setMultiLine (true);
    G3->setReturnKeyStartsNewLine (false);
    G3->setReadOnly (true);
    G3->setScrollbarsShown (false);
    G3->setCaretVisible (false);
    G3->setPopupMenuEnabled (false);
    G3->setColour (TextEditor::textColourId, Colours::black);
    G3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G3->setText (TRANS("G"));

    addAndMakeVisible (D2 = new TextEditor ("new text editor"));
    D2->setMultiLine (true);
    D2->setReturnKeyStartsNewLine (false);
    D2->setReadOnly (true);
    D2->setScrollbarsShown (false);
    D2->setCaretVisible (false);
    D2->setPopupMenuEnabled (false);
    D2->setColour (TextEditor::textColourId, Colours::black);
    D2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D2->setText (TRANS("D"));

    addAndMakeVisible (A = new TextEditor ("new text editor"));
    A->setMultiLine (true);
    A->setReturnKeyStartsNewLine (false);
    A->setReadOnly (true);
    A->setScrollbarsShown (false);
    A->setCaretVisible (false);
    A->setPopupMenuEnabled (false);
    A->setColour (TextEditor::textColourId, Colours::black);
    A->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A->setText (TRANS("A"));

    addAndMakeVisible (E5 = new TextEditor ("new text editor"));
    E5->setMultiLine (true);
    E5->setReturnKeyStartsNewLine (false);
    E5->setReadOnly (true);
    E5->setScrollbarsShown (false);
    E5->setCaretVisible (false);
    E5->setPopupMenuEnabled (false);
    E5->setColour (TextEditor::textColourId, Colours::black);
    E5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E5->setText (TRANS("E"));

    addAndMakeVisible (A6 = new TextEditor ("new text editor"));
    A6->setMultiLine (true);
    A6->setReturnKeyStartsNewLine (false);
    A6->setReadOnly (true);
    A6->setScrollbarsShown (false);
    A6->setCaretVisible (false);
    A6->setPopupMenuEnabled (false);
    A6->setColour (TextEditor::textColourId, Colours::black);
    A6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A6->setText (TRANS("A"));

    addAndMakeVisible (CS4 = new TextEditor ("new text editor"));
    CS4->setMultiLine (true);
    CS4->setReturnKeyStartsNewLine (false);
    CS4->setReadOnly (true);
    CS4->setScrollbarsShown (false);
    CS4->setCaretVisible (false);
    CS4->setPopupMenuEnabled (false);
    CS4->setColour (TextEditor::textColourId, Colours::black);
    CS4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS4->setText (TRANS("C#"));

    addAndMakeVisible (GS3 = new TextEditor ("new text editor"));
    GS3->setMultiLine (true);
    GS3->setReturnKeyStartsNewLine (false);
    GS3->setReadOnly (true);
    GS3->setScrollbarsShown (false);
    GS3->setCaretVisible (false);
    GS3->setPopupMenuEnabled (false);
    GS3->setColour (TextEditor::textColourId, Colours::black);
    GS3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS3->setText (TRANS("G#"));

    addAndMakeVisible (DS2 = new TextEditor ("new text editor"));
    DS2->setMultiLine (true);
    DS2->setReturnKeyStartsNewLine (false);
    DS2->setReadOnly (true);
    DS2->setScrollbarsShown (false);
    DS2->setCaretVisible (false);
    DS2->setPopupMenuEnabled (false);
    DS2->setColour (TextEditor::textColourId, Colours::black);
    DS2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS2->setText (TRANS("D#"));

    addAndMakeVisible (AS = new TextEditor ("new text editor"));
    AS->setMultiLine (true);
    AS->setReturnKeyStartsNewLine (false);
    AS->setReadOnly (true);
    AS->setScrollbarsShown (false);
    AS->setCaretVisible (false);
    AS->setPopupMenuEnabled (false);
    AS->setColour (TextEditor::textColourId, Colours::black);
    AS->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS->setText (TRANS("A#"));

    addAndMakeVisible (F5 = new TextEditor ("new text editor"));
    F5->setMultiLine (true);
    F5->setReturnKeyStartsNewLine (false);
    F5->setReadOnly (true);
    F5->setScrollbarsShown (false);
    F5->setCaretVisible (false);
    F5->setPopupMenuEnabled (false);
    F5->setColour (TextEditor::textColourId, Colours::black);
    F5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F5->setText (TRANS("F"));

    addAndMakeVisible (AS6 = new TextEditor ("new text editor"));
    AS6->setMultiLine (true);
    AS6->setReturnKeyStartsNewLine (false);
    AS6->setReadOnly (true);
    AS6->setScrollbarsShown (false);
    AS6->setCaretVisible (false);
    AS6->setPopupMenuEnabled (false);
    AS6->setColour (TextEditor::textColourId, Colours::black);
    AS6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS6->setText (TRANS("A#"));

    addAndMakeVisible (D4 = new TextEditor ("new text editor"));
    D4->setMultiLine (true);
    D4->setReturnKeyStartsNewLine (false);
    D4->setReadOnly (true);
    D4->setScrollbarsShown (false);
    D4->setCaretVisible (false);
    D4->setPopupMenuEnabled (false);
    D4->setColour (TextEditor::textColourId, Colours::black);
    D4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D4->setText (TRANS("D"));

    addAndMakeVisible (A3 = new TextEditor ("new text editor"));
    A3->setMultiLine (true);
    A3->setReturnKeyStartsNewLine (false);
    A3->setReadOnly (true);
    A3->setScrollbarsShown (false);
    A3->setCaretVisible (false);
    A3->setPopupMenuEnabled (false);
    A3->setColour (TextEditor::textColourId, Colours::black);
    A3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A3->setText (TRANS("A"));

    addAndMakeVisible (E2 = new TextEditor ("new text editor"));
    E2->setMultiLine (true);
    E2->setReturnKeyStartsNewLine (false);
    E2->setReadOnly (true);
    E2->setScrollbarsShown (false);
    E2->setCaretVisible (false);
    E2->setPopupMenuEnabled (false);
    E2->setColour (TextEditor::textColourId, Colours::black);
    E2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E2->setText (TRANS("E"));

    addAndMakeVisible (B = new TextEditor ("new text editor"));
    B->setMultiLine (true);
    B->setReturnKeyStartsNewLine (false);
    B->setReadOnly (true);
    B->setScrollbarsShown (false);
    B->setCaretVisible (false);
    B->setPopupMenuEnabled (false);
    B->setColour (TextEditor::textColourId, Colours::black);
    B->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B->setText (TRANS("B"));

    addAndMakeVisible (FS5 = new TextEditor ("new text editor"));
    FS5->setMultiLine (true);
    FS5->setReturnKeyStartsNewLine (false);
    FS5->setReadOnly (true);
    FS5->setScrollbarsShown (false);
    FS5->setCaretVisible (false);
    FS5->setPopupMenuEnabled (false);
    FS5->setColour (TextEditor::textColourId, Colours::black);
    FS5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS5->setText (TRANS("F#"));

    addAndMakeVisible (B6 = new TextEditor ("new text editor"));
    B6->setMultiLine (true);
    B6->setReturnKeyStartsNewLine (false);
    B6->setReadOnly (true);
    B6->setScrollbarsShown (false);
    B6->setCaretVisible (false);
    B6->setPopupMenuEnabled (false);
    B6->setColour (TextEditor::textColourId, Colours::black);
    B6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B6->setText (TRANS("B"));

    addAndMakeVisible (DS4 = new TextEditor ("new text editor"));
    DS4->setMultiLine (true);
    DS4->setReturnKeyStartsNewLine (false);
    DS4->setReadOnly (true);
    DS4->setScrollbarsShown (false);
    DS4->setCaretVisible (false);
    DS4->setPopupMenuEnabled (false);
    DS4->setColour (TextEditor::textColourId, Colours::black);
    DS4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS4->setText (TRANS("D#"));

    addAndMakeVisible (AS3 = new TextEditor ("new text editor"));
    AS3->setMultiLine (true);
    AS3->setReturnKeyStartsNewLine (false);
    AS3->setReadOnly (true);
    AS3->setScrollbarsShown (false);
    AS3->setCaretVisible (false);
    AS3->setPopupMenuEnabled (false);
    AS3->setColour (TextEditor::textColourId, Colours::black);
    AS3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS3->setText (TRANS("A#"));

    addAndMakeVisible (F3 = new TextEditor ("new text editor"));
    F3->setMultiLine (true);
    F3->setReturnKeyStartsNewLine (false);
    F3->setReadOnly (true);
    F3->setScrollbarsShown (false);
    F3->setCaretVisible (false);
    F3->setPopupMenuEnabled (false);
    F3->setColour (TextEditor::textColourId, Colours::black);
    F3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F3->setText (TRANS("F"));

    addAndMakeVisible (C = new TextEditor ("new text editor"));
    C->setMultiLine (true);
    C->setReturnKeyStartsNewLine (false);
    C->setReadOnly (true);
    C->setScrollbarsShown (false);
    C->setCaretVisible (false);
    C->setPopupMenuEnabled (false);
    C->setColour (TextEditor::textColourId, Colours::black);
    C->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C->setText (TRANS("C"));

    addAndMakeVisible (G5 = new TextEditor ("new text editor"));
    G5->setMultiLine (true);
    G5->setReturnKeyStartsNewLine (false);
    G5->setReadOnly (true);
    G5->setScrollbarsShown (false);
    G5->setCaretVisible (false);
    G5->setPopupMenuEnabled (false);
    G5->setColour (TextEditor::textColourId, Colours::black);
    G5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G5->setText (TRANS("G"));

    addAndMakeVisible (C6 = new TextEditor ("new text editor"));
    C6->setMultiLine (true);
    C6->setReturnKeyStartsNewLine (false);
    C6->setReadOnly (true);
    C6->setScrollbarsShown (false);
    C6->setCaretVisible (false);
    C6->setPopupMenuEnabled (false);
    C6->setColour (TextEditor::textColourId, Colours::black);
    C6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C6->setText (TRANS("C"));

    addAndMakeVisible (E4 = new TextEditor ("new text editor"));
    E4->setMultiLine (true);
    E4->setReturnKeyStartsNewLine (false);
    E4->setReadOnly (true);
    E4->setScrollbarsShown (false);
    E4->setCaretVisible (false);
    E4->setPopupMenuEnabled (false);
    E4->setColour (TextEditor::textColourId, Colours::black);
    E4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E4->setText (TRANS("E"));

    addAndMakeVisible (B3 = new TextEditor ("new text editor"));
    B3->setMultiLine (true);
    B3->setReturnKeyStartsNewLine (false);
    B3->setReadOnly (true);
    B3->setScrollbarsShown (false);
    B3->setCaretVisible (false);
    B3->setPopupMenuEnabled (false);
    B3->setColour (TextEditor::textColourId, Colours::black);
    B3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B3->setText (TRANS("B"));

    addAndMakeVisible (FS2 = new TextEditor ("new text editor"));
    FS2->setMultiLine (true);
    FS2->setReturnKeyStartsNewLine (false);
    FS2->setReadOnly (true);
    FS2->setScrollbarsShown (false);
    FS2->setCaretVisible (false);
    FS2->setPopupMenuEnabled (false);
    FS2->setColour (TextEditor::textColourId, Colours::black);
    FS2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS2->setText (TRANS("F#"));

    addAndMakeVisible (CS = new TextEditor ("new text editor"));
    CS->setMultiLine (true);
    CS->setReturnKeyStartsNewLine (false);
    CS->setReadOnly (true);
    CS->setScrollbarsShown (false);
    CS->setCaretVisible (false);
    CS->setPopupMenuEnabled (false);
    CS->setColour (TextEditor::textColourId, Colours::black);
    CS->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS->setText (TRANS("C#"));

    addAndMakeVisible (GS5 = new TextEditor ("new text editor"));
    GS5->setMultiLine (true);
    GS5->setReturnKeyStartsNewLine (false);
    GS5->setReadOnly (true);
    GS5->setScrollbarsShown (false);
    GS5->setCaretVisible (false);
    GS5->setPopupMenuEnabled (false);
    GS5->setColour (TextEditor::textColourId, Colours::black);
    GS5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS5->setText (TRANS("G#"));

    addAndMakeVisible (CS6 = new TextEditor ("new text editor"));
    CS6->setMultiLine (true);
    CS6->setReturnKeyStartsNewLine (false);
    CS6->setReadOnly (true);
    CS6->setScrollbarsShown (false);
    CS6->setCaretVisible (false);
    CS6->setPopupMenuEnabled (false);
    CS6->setColour (TextEditor::textColourId, Colours::black);
    CS6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS6->setText (TRANS("C#"));

    addAndMakeVisible (F4 = new TextEditor ("new text editor"));
    F4->setMultiLine (true);
    F4->setReturnKeyStartsNewLine (false);
    F4->setReadOnly (true);
    F4->setScrollbarsShown (false);
    F4->setCaretVisible (false);
    F4->setPopupMenuEnabled (false);
    F4->setColour (TextEditor::textColourId, Colours::black);
    F4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F4->setText (TRANS("F"));

    addAndMakeVisible (C3 = new TextEditor ("new text editor"));
    C3->setMultiLine (true);
    C3->setReturnKeyStartsNewLine (false);
    C3->setReadOnly (true);
    C3->setScrollbarsShown (false);
    C3->setCaretVisible (false);
    C3->setPopupMenuEnabled (false);
    C3->setColour (TextEditor::textColourId, Colours::black);
    C3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C3->setText (TRANS("C"));

    addAndMakeVisible (G2 = new TextEditor ("new text editor"));
    G2->setMultiLine (true);
    G2->setReturnKeyStartsNewLine (false);
    G2->setReadOnly (true);
    G2->setScrollbarsShown (false);
    G2->setCaretVisible (false);
    G2->setPopupMenuEnabled (false);
    G2->setColour (TextEditor::textColourId, Colours::black);
    G2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G2->setText (TRANS("G"));

    addAndMakeVisible (D = new TextEditor ("new text editor"));
    D->setMultiLine (true);
    D->setReturnKeyStartsNewLine (false);
    D->setReadOnly (true);
    D->setScrollbarsShown (false);
    D->setCaretVisible (false);
    D->setPopupMenuEnabled (false);
    D->setColour (TextEditor::textColourId, Colours::black);
    D->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D->setText (TRANS("D"));

    addAndMakeVisible (A5 = new TextEditor ("new text editor"));
    A5->setMultiLine (true);
    A5->setReturnKeyStartsNewLine (false);
    A5->setReadOnly (true);
    A5->setScrollbarsShown (false);
    A5->setCaretVisible (false);
    A5->setPopupMenuEnabled (false);
    A5->setColour (TextEditor::textColourId, Colours::black);
    A5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A5->setText (TRANS("A"));

    addAndMakeVisible (D6 = new TextEditor ("new text editor"));
    D6->setMultiLine (true);
    D6->setReturnKeyStartsNewLine (false);
    D6->setReadOnly (true);
    D6->setScrollbarsShown (false);
    D6->setCaretVisible (false);
    D6->setPopupMenuEnabled (false);
    D6->setColour (TextEditor::textColourId, Colours::black);
    D6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D6->setText (TRANS("D"));

    addAndMakeVisible (FS4 = new TextEditor ("new text editor"));
    FS4->setMultiLine (true);
    FS4->setReturnKeyStartsNewLine (false);
    FS4->setReadOnly (true);
    FS4->setScrollbarsShown (false);
    FS4->setCaretVisible (false);
    FS4->setPopupMenuEnabled (false);
    FS4->setColour (TextEditor::textColourId, Colours::black);
    FS4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS4->setText (TRANS("F#"));

    addAndMakeVisible (CS3 = new TextEditor ("new text editor"));
    CS3->setMultiLine (true);
    CS3->setReturnKeyStartsNewLine (false);
    CS3->setReadOnly (true);
    CS3->setScrollbarsShown (false);
    CS3->setCaretVisible (false);
    CS3->setPopupMenuEnabled (false);
    CS3->setColour (TextEditor::textColourId, Colours::black);
    CS3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS3->setText (TRANS("C#"));

    addAndMakeVisible (GS2 = new TextEditor ("new text editor"));
    GS2->setMultiLine (true);
    GS2->setReturnKeyStartsNewLine (false);
    GS2->setReadOnly (true);
    GS2->setScrollbarsShown (false);
    GS2->setCaretVisible (false);
    GS2->setPopupMenuEnabled (false);
    GS2->setColour (TextEditor::textColourId, Colours::black);
    GS2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS2->setText (TRANS("G#"));

    addAndMakeVisible (DS = new TextEditor ("new text editor"));
    DS->setMultiLine (true);
    DS->setReturnKeyStartsNewLine (false);
    DS->setReadOnly (true);
    DS->setScrollbarsShown (false);
    DS->setCaretVisible (false);
    DS->setPopupMenuEnabled (false);
    DS->setColour (TextEditor::textColourId, Colours::black);
    DS->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS->setText (TRANS("D#"));

    addAndMakeVisible (AS5 = new TextEditor ("new text editor"));
    AS5->setMultiLine (true);
    AS5->setReturnKeyStartsNewLine (false);
    AS5->setReadOnly (true);
    AS5->setScrollbarsShown (false);
    AS5->setCaretVisible (false);
    AS5->setPopupMenuEnabled (false);
    AS5->setColour (TextEditor::textColourId, Colours::black);
    AS5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS5->setText (TRANS("A#"));

    addAndMakeVisible (DS6 = new TextEditor ("new text editor"));
    DS6->setMultiLine (true);
    DS6->setReturnKeyStartsNewLine (false);
    DS6->setReadOnly (true);
    DS6->setScrollbarsShown (false);
    DS6->setCaretVisible (false);
    DS6->setPopupMenuEnabled (false);
    DS6->setColour (TextEditor::textColourId, Colours::black);
    DS6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS6->setText (TRANS("D#"));

    addAndMakeVisible (G4 = new TextEditor ("new text editor"));
    G4->setMultiLine (true);
    G4->setReturnKeyStartsNewLine (false);
    G4->setReadOnly (true);
    G4->setScrollbarsShown (false);
    G4->setCaretVisible (false);
    G4->setPopupMenuEnabled (false);
    G4->setColour (TextEditor::textColourId, Colours::black);
    G4->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G4->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G4->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G4->setText (TRANS("G"));

    addAndMakeVisible (D3 = new TextEditor ("new text editor"));
    D3->setMultiLine (true);
    D3->setReturnKeyStartsNewLine (false);
    D3->setReadOnly (true);
    D3->setScrollbarsShown (false);
    D3->setCaretVisible (false);
    D3->setPopupMenuEnabled (false);
    D3->setColour (TextEditor::textColourId, Colours::black);
    D3->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D3->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D3->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D3->setText (TRANS("D"));

    addAndMakeVisible (A2 = new TextEditor ("new text editor"));
    A2->setMultiLine (true);
    A2->setReturnKeyStartsNewLine (false);
    A2->setReadOnly (true);
    A2->setScrollbarsShown (false);
    A2->setCaretVisible (false);
    A2->setPopupMenuEnabled (false);
    A2->setColour (TextEditor::textColourId, Colours::black);
    A2->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A2->setText (TRANS("A"));

    addAndMakeVisible (E = new TextEditor ("new text editor"));
    E->setMultiLine (true);
    E->setReturnKeyStartsNewLine (false);
    E->setReadOnly (true);
    E->setScrollbarsShown (false);
    E->setCaretVisible (false);
    E->setPopupMenuEnabled (false);
    E->setColour (TextEditor::textColourId, Colours::black);
    E->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E->setText (TRANS("E"));

    addAndMakeVisible (B5 = new TextEditor ("new text editor"));
    B5->setMultiLine (true);
    B5->setReturnKeyStartsNewLine (false);
    B5->setReadOnly (true);
    B5->setScrollbarsShown (false);
    B5->setCaretVisible (false);
    B5->setPopupMenuEnabled (false);
    B5->setColour (TextEditor::textColourId, Colours::black);
    B5->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B5->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B5->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B5->setText (TRANS("B"));

    addAndMakeVisible (E6 = new TextEditor ("new text editor"));
    E6->setMultiLine (true);
    E6->setReturnKeyStartsNewLine (false);
    E6->setReadOnly (true);
    E6->setScrollbarsShown (false);
    E6->setCaretVisible (false);
    E6->setPopupMenuEnabled (false);
    E6->setColour (TextEditor::textColourId, Colours::black);
    E6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E6->setText (TRANS("E"));

    cachedImage_screenshot_20190321Blank20Pdf_png_1 = ImageCache::getFromMemory (screenshot_20190321Blank20Pdf_png, screenshot_20190321Blank20Pdf_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 600);


    //[Constructor] You can add your own custom stuff here..

	texteditors.push_back(textEditor);

	guitarnotes.push_back(C);
	guitarnotes.push_back(C2);
	guitarnotes.push_back(C3);
	guitarnotes.push_back(C4);
	guitarnotes.push_back(C5);
	guitarnotes.push_back(C6);

	guitarnotes.push_back(CS);
	guitarnotes.push_back(CS2);
	guitarnotes.push_back(CS3);
	guitarnotes.push_back(CS4);
	guitarnotes.push_back(CS5);
	guitarnotes.push_back(CS6);

	guitarnotes.push_back(D);
	guitarnotes.push_back(D2);
	guitarnotes.push_back(D3);
	guitarnotes.push_back(D4);
	guitarnotes.push_back(D5);
	guitarnotes.push_back(D6);

	guitarnotes.push_back(DS);
	guitarnotes.push_back(DS2);
	guitarnotes.push_back(DS3);
	guitarnotes.push_back(DS4);
	guitarnotes.push_back(DS5);
	guitarnotes.push_back(DS6);

	guitarnotes.push_back(E);
	guitarnotes.push_back(E2);
	guitarnotes.push_back(E3);
	guitarnotes.push_back(E4);
	guitarnotes.push_back(E5);
	guitarnotes.push_back(E6);

	guitarnotes.push_back(F);
	guitarnotes.push_back(F1);
	guitarnotes.push_back(F2);
	guitarnotes.push_back(F3);
	guitarnotes.push_back(F4);
	guitarnotes.push_back(F5);
	
	guitarnotes.push_back(FS);
	guitarnotes.push_back(FS2);
	guitarnotes.push_back(FS3);
	guitarnotes.push_back(FS4);
	guitarnotes.push_back(FS5);
	guitarnotes.push_back(FS6);

	guitarnotes.push_back(G);
	guitarnotes.push_back(G2);
	guitarnotes.push_back(G3);
	guitarnotes.push_back(G4);
	guitarnotes.push_back(G5);
	guitarnotes.push_back(G6);

	guitarnotes.push_back(GS);
	guitarnotes.push_back(GS2);
	guitarnotes.push_back(GS3);
	guitarnotes.push_back(GS4);
	guitarnotes.push_back(GS5);
	guitarnotes.push_back(GS6);

	guitarnotes.push_back(A);
	guitarnotes.push_back(A2);
	guitarnotes.push_back(A3);
	guitarnotes.push_back(A4);
	guitarnotes.push_back(A5);
	guitarnotes.push_back(A6);

	guitarnotes.push_back(AS);
	guitarnotes.push_back(AS2);
	guitarnotes.push_back(AS3);
	guitarnotes.push_back(AS4);
	guitarnotes.push_back(AS5);
	guitarnotes.push_back(AS6);

	guitarnotes.push_back(B);
	guitarnotes.push_back(B2);
	guitarnotes.push_back(B3);
	guitarnotes.push_back(B4);
	guitarnotes.push_back(B5);
	guitarnotes.push_back(B6);
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
    GS4 = nullptr;
    DS3 = nullptr;
    AS2 = nullptr;
    F1 = nullptr;
    C5 = nullptr;
    F2 = nullptr;
    A4 = nullptr;
    E3 = nullptr;
    B2 = nullptr;
    FS = nullptr;
    CS5 = nullptr;
    FS6 = nullptr;
    AS4 = nullptr;
    F = nullptr;
    C2 = nullptr;
    G = nullptr;
    D5 = nullptr;
    G6 = nullptr;
    B4 = nullptr;
    FS3 = nullptr;
    CS2 = nullptr;
    GS = nullptr;
    DS5 = nullptr;
    GS6 = nullptr;
    C4 = nullptr;
    G3 = nullptr;
    D2 = nullptr;
    A = nullptr;
    E5 = nullptr;
    A6 = nullptr;
    CS4 = nullptr;
    GS3 = nullptr;
    DS2 = nullptr;
    AS = nullptr;
    F5 = nullptr;
    AS6 = nullptr;
    D4 = nullptr;
    A3 = nullptr;
    E2 = nullptr;
    B = nullptr;
    FS5 = nullptr;
    B6 = nullptr;
    DS4 = nullptr;
    AS3 = nullptr;
    F3 = nullptr;
    C = nullptr;
    G5 = nullptr;
    C6 = nullptr;
    E4 = nullptr;
    B3 = nullptr;
    FS2 = nullptr;
    CS = nullptr;
    GS5 = nullptr;
    CS6 = nullptr;
    F4 = nullptr;
    C3 = nullptr;
    G2 = nullptr;
    D = nullptr;
    A5 = nullptr;
    D6 = nullptr;
    FS4 = nullptr;
    CS3 = nullptr;
    GS2 = nullptr;
    DS = nullptr;
    AS5 = nullptr;
    DS6 = nullptr;
    G4 = nullptr;
    D3 = nullptr;
    A2 = nullptr;
    E = nullptr;
    B5 = nullptr;
    E6 = nullptr;


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
        int x = 13, y = 168, width = 109, height = 30;
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
        int x = 341, y = 0, width = 411, height = 72;
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
        int x = 220, y = 716, width = 588, height = 5;
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 324, y = 724, width = 44, height = 30;
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
        int x = 420, y = 724, width = 44, height = 30;
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
        int x = 524, y = 724, width = 44, height = 30;
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
        int x = 612, y = 724, width = 44, height = 30;
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
        int x = 756, y = 724, width = 44, height = 30;
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
        int x = 93, y = 168, width = 200, height = 30;
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
        int x = 29, y = 24, width = 200, height = 30;
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
        int x = 445, y = 48, width = 200, height = 30;
        String text (TRANS("MusicTheoryHelperVST"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 16, y = 328, width = 968, height = 212;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (cachedImage_screenshot_20190321Blank20Pdf_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_screenshot_20190321Blank20Pdf_png_1.getWidth(), cachedImage_screenshot_20190321Blank20Pdf_png_1.getHeight());
    }

    {
        int x = 144, y = 544, width = 48, height = 30;
        String text (TRANS("3"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 264, y = 544, width = 40, height = 30;
        String text (TRANS("5"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 365, y = 544, width = 51, height = 30;
        String text (TRANS("7"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 469, y = 544, width = 43, height = 30;
        String text (TRANS("9"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 613, y = 544, width = 43, height = 30;
        String text (TRANS("12"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 741, y = 544, width = 51, height = 30;
        String text (TRANS("15"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 829, y = 544, width = 43, height = 30;
        String text (TRANS("17"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 901, y = 544, width = 51, height = 30;
        String text (TRANS("19"));
        Colour fillColour = Colours::black;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Arca Majora 3", 15.00f, Font::plain).withTypefaceStyle ("Bold"));
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

    groupComponent->setBounds (8, 264, 984, 320);
    groupComponent4->setBounds (8, 136, 272, 128);
    groupComponent3->setBounds (288, 72, 704, 192);
    groupComponent2->setBounds (8, 8, 272, 128);
    scaleKey->setBounds (40, 192, 64, 24);
    textEditor->setBounds (832, 8, 150, 24);
    comboBox2->setBounds (24, 288, 150, 24);
    scaleMode->setBounds (120, 192, 152, 24);
    chordRoot->setBounds (56, 56, 64, 24);
    chordType->setBounds (144, 56, 88, 24);
    textEditor2->setBounds (304, 96, 680, 160);
    txtScale->setBounds (32, 224, 224, 32);
    txtChord->setBounds (16, 96, 256, 32);
    GS4->setBounds (24, 400, 56, 24);
    DS3->setBounds (24, 440, 56, 24);
    AS2->setBounds (24, 480, 56, 24);
    F1->setBounds (24, 525, 56, 24);
    C5->setBounds (24, 360, 56, 24);
    F2->setBounds (24, 317, 56, 24);
    A4->setBounds (85, 400, 56, 24);
    E3->setBounds (85, 440, 56, 24);
    B2->setBounds (85, 480, 56, 24);
    FS->setBounds (85, 525, 56, 24);
    CS5->setBounds (85, 360, 56, 24);
    FS6->setBounds (85, 317, 56, 24);
    AS4->setBounds (145, 400, 54, 24);
    F->setBounds (145, 440, 54, 24);
    C2->setBounds (145, 480, 54, 24);
    G->setBounds (145, 525, 54, 24);
    D5->setBounds (145, 360, 54, 24);
    G6->setBounds (145, 317, 54, 24);
    B4->setBounds (201, 401, 54, 24);
    FS3->setBounds (201, 441, 54, 24);
    CS2->setBounds (201, 481, 54, 24);
    GS->setBounds (201, 526, 54, 24);
    DS5->setBounds (201, 361, 54, 24);
    GS6->setBounds (201, 318, 54, 24);
    C4->setBounds (257, 396, 54, 24);
    G3->setBounds (257, 436, 54, 24);
    D2->setBounds (257, 476, 54, 24);
    A->setBounds (257, 521, 54, 24);
    E5->setBounds (257, 356, 54, 24);
    A6->setBounds (257, 313, 54, 24);
    CS4->setBounds (311, 400, 54, 24);
    GS3->setBounds (311, 440, 54, 24);
    DS2->setBounds (311, 480, 54, 24);
    AS->setBounds (311, 525, 54, 24);
    F5->setBounds (311, 360, 54, 24);
    AS6->setBounds (311, 317, 54, 24);
    D4->setBounds (367, 396, 49, 24);
    A3->setBounds (367, 436, 49, 24);
    E2->setBounds (367, 476, 49, 24);
    B->setBounds (367, 521, 49, 24);
    FS5->setBounds (367, 356, 49, 24);
    B6->setBounds (367, 313, 49, 24);
    DS4->setBounds (419, 397, 45, 24);
    AS3->setBounds (419, 437, 45, 24);
    F3->setBounds (419, 477, 45, 24);
    C->setBounds (419, 522, 45, 24);
    G5->setBounds (419, 357, 45, 24);
    C6->setBounds (419, 314, 45, 24);
    E4->setBounds (472, 397, 45, 24);
    B3->setBounds (472, 437, 45, 24);
    FS2->setBounds (472, 477, 45, 24);
    CS->setBounds (472, 522, 45, 24);
    GS5->setBounds (472, 357, 45, 24);
    CS6->setBounds (472, 314, 45, 24);
    F4->setBounds (518, 396, 45, 24);
    C3->setBounds (518, 436, 45, 24);
    G2->setBounds (518, 476, 45, 24);
    D->setBounds (518, 521, 45, 24);
    A5->setBounds (518, 356, 45, 24);
    D6->setBounds (518, 313, 45, 24);
    FS4->setBounds (568, 395, 45, 24);
    CS3->setBounds (568, 435, 45, 24);
    GS2->setBounds (568, 475, 45, 24);
    DS->setBounds (568, 520, 45, 24);
    AS5->setBounds (568, 355, 45, 24);
    DS6->setBounds (568, 312, 45, 24);
    G4->setBounds (614, 398, 45, 24);
    D3->setBounds (614, 438, 45, 24);
    A2->setBounds (614, 478, 45, 24);
    E->setBounds (614, 523, 45, 24);
    B5->setBounds (614, 358, 45, 24);
    E6->setBounds (614, 315, 45, 24);
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
		root = scalekeystr[0];
		char scalekeychar = scalekeystr[0];

		int offset = 0;
		if (scalekeystr[1] != NULL) {
			offset = 1;
			root += "#";
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
			//texteditors.at(0)->setText(root);

			// Disable notes that are not in scale
			for (int i = 0; i < guitarnotes.size(); ++i) {
				if (! (txtScale->getText().contains(guitarnotes.at(i)->getText() + " "))) {
					guitarnotes.at(i)->setVisible(false);
				}
				if (txtScale->getText().getLastCharacters(3).trim() == guitarnotes.at(i)->getText()) {
					guitarnotes.at(i)->setVisible(true);
				}

				// Make root note distinct
				if (guitarnotes.at(i)->getText() == root) {
					guitarnotes.at(i)->setAlpha(1);

				}
			}

		}
		else if (comboBox2->getText() == "Chords") {
			// Show only notes that are in the chosen chords
			texteditors.at(0)->setText(TRANS("chords"));
		}

		else if (comboBox2->getText() == "Notes") {
			// Show all notes
			texteditors.at(0)->setText(TRANS("notes"));

			// Enable everyting
			for (int i = 0; i < guitarnotes.size(); ++i) {
				guitarnotes.at(i)->setVisible(true);
				guitarnotes.at(i)->setAlpha(0.8);
			}
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
	juce::String jscalestr = simplifyNotes(scalestr);
	txtScale->setText(jscalestr);
}

void PluginEditor::updateChord() {
	std::ostringstream stream;
	stream << Chord(chordroot, chordtype) << std::endl;
	std::string chordstr = stream.str();
	txtChord->setText(chordstr);
}

juce::String PluginEditor::simplifyNotes(std::string str) {
	// This is a bit stupid but works

	juce::String jscalestr = str;

	jscalestr = jscalestr.replace("B#", "C");
	jscalestr = jscalestr.replace("E#", "F");

	jscalestr = jscalestr.replace("Cb", "B");
	jscalestr = jscalestr.replace("Db", "C#");
	jscalestr = jscalestr.replace("Eb", "D#");
	jscalestr = jscalestr.replace("Fb", "E");
	jscalestr = jscalestr.replace("Gb", "F#");
	jscalestr = jscalestr.replace("Ab", "G#");
	jscalestr = jscalestr.replace("Bb", "A#");

	jscalestr = jscalestr.replace("C##", "D");
	jscalestr = jscalestr.replace("D##", "E");
	jscalestr = jscalestr.replace("E##", "F#");
	jscalestr = jscalestr.replace("F##", "G");
	jscalestr = jscalestr.replace("G##", "A#");
	jscalestr = jscalestr.replace("A##", "B");
	jscalestr = jscalestr.replace("B##", "C#");


	return jscalestr;
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
                 fixedSize="1" initialWidth="1000" initialHeight="600">
  <BACKGROUND backgroundColour="ff5f9ea0">
    <TEXT pos="13 168 109 30" fill="solid: ff000000" hasStroke="0" text="KEY"
          fontname="Arca Majora 3" fontsize="26.399999999999998579" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="341 0 411 72" fill="solid: ff000000" hasStroke="0" text="MTHVST"
          fontname="Arca Majora 3" fontsize="67.299999999999997158" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <RECT pos="220 716 588 5" fill="solid: ff000000" hasStroke="0"/>
    <TEXT pos="324 724 44 30" fill="solid: ff000000" hasStroke="0" text="3"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="420 724 44 30" fill="solid: ff000000" hasStroke="0" text="5"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="524 724 44 30" fill="solid: ff000000" hasStroke="0" text="7"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="612 724 44 30" fill="solid: ff000000" hasStroke="0" text="9"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="756 724 44 30" fill="solid: ff000000" hasStroke="0" text="12"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="93 168 200 30" fill="solid: ff000000" hasStroke="0" text="MODE/SCALE"
          fontname="Arca Majora 3" fontsize="26.399999999999998579" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="29 24 200 30" fill="solid: ff000000" hasStroke="0" text="CHORD"
          fontname="Arca Majora 3" fontsize="26.399999999999998579" kerning="0"
          bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
    <TEXT pos="445 48 200 30" fill="solid: ff000000" hasStroke="0" text="MusicTheoryHelperVST"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <IMAGE pos="16 328 968 212" resource="screenshot_20190321Blank20Pdf_png"
           opacity="1" mode="0"/>
    <TEXT pos="144 544 48 30" fill="solid: ff000000" hasStroke="0" text="3"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="264 544 40 30" fill="solid: ff000000" hasStroke="0" text="5"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="365 544 51 30" fill="solid: ff000000" hasStroke="0" text="7"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="469 544 43 30" fill="solid: ff000000" hasStroke="0" text="9"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="613 544 43 30" fill="solid: ff000000" hasStroke="0" text="12"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="741 544 51 30" fill="solid: ff000000" hasStroke="0" text="15"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="829 544 43 30" fill="solid: ff000000" hasStroke="0" text="17"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
    <TEXT pos="901 544 51 30" fill="solid: ff000000" hasStroke="0" text="19"
          fontname="Arca Majora 3" fontsize="15" kerning="0" bold="1" italic="0"
          justification="36" typefaceStyle="Bold"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="d3e9a3eb7c3fc20b" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 264 984 320" outlinecol="ff7fffd4"
                  title="guitar"/>
  <GROUPCOMPONENT name="new group" id="d6a80f42cd589941" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="8 136 272 128" outlinecol="ff7fffd4"
                  title="scales"/>
  <GROUPCOMPONENT name="new group" id="870f042dcaa691d" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="288 72 704 192" outlinecol="ff7fffd4"
                  title="notepad"/>
  <GROUPCOMPONENT name="new group" id="8bfcb5af8d4d4e7a" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 8 272 128" outlinecol="ff7fffd4"
                  title="chords"/>
  <COMBOBOX name="new combo box" id="d0bac3320deb23bb" memberName="scaleKey"
            virtualName="" explicitFocusOrder="0" pos="40 192 64 24" editable="0"
            layout="33" items="C&#10;C#&#10;D&#10;D#&#10;E&#10;F&#10;F#&#10;G&#10;G#&#10;A&#10;A#&#10;B"
            textWhenNonSelected="none" textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="new text editor" id="e9702388dec763e6" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="832 8 150 24" bkgcol="ff5f9ea0"
              initialText="Debug" multiline="0" retKeyStartsLine="0" readonly="1"
              scrollbars="1" caret="0" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="28c57b6ee300da4c" memberName="comboBox2"
            virtualName="" explicitFocusOrder="0" pos="24 288 150 24" editable="0"
            layout="33" items="Notes&#10;Scales&#10;Chords" textWhenNonSelected="Notes"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="1c5c8e2cb3a97fca" memberName="scaleMode"
            virtualName="" explicitFocusOrder="0" pos="120 192 152 24" editable="0"
            layout="33" items="Major&#10;Minor&#10;Harmonic Minor&#10;Blues&#10;Minor Pentatonic&#10;Major Pentatonic&#10;Dorian&#10;Lydian&#10;Mixolydian&#10;Phrygian"
            textWhenNonSelected="none" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="5df79c76e34b7dfe" memberName="chordRoot"
            virtualName="" explicitFocusOrder="0" pos="56 56 64 24" editable="0"
            layout="33" items="C&#10;C#&#10;D&#10;D#&#10;E&#10;F&#10;F#&#10;G&#10;G#&#10;A&#10;A#&#10;B"
            textWhenNonSelected="root" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="f1a298a1b78330af" memberName="chordType"
            virtualName="" explicitFocusOrder="0" pos="144 56 88 24" editable="0"
            layout="33" items="m&#10;M&#10;aug&#10;M7&#10;m7" textWhenNonSelected="type"
            textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="new text editor" id="61e50ec73da81d20" memberName="textEditor2"
              virtualName="" explicitFocusOrder="0" pos="304 96 680 160" bkgcol="ff508385"
              initialText="write anything here ...&#10;" multiline="1" retKeyStartsLine="1"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="f01c2b8f289a8b31" memberName="txtScale"
              virtualName="" explicitFocusOrder="0" pos="32 224 224 32" bkgcol="ff5f9ea0"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e8c8a7592443a9c8" memberName="txtChord"
              virtualName="" explicitFocusOrder="0" pos="16 96 256 32" bkgcol="ff5f9ea0"
              initialText="" multiline="1" retKeyStartsLine="0" readonly="1"
              scrollbars="0" caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c47feac105422dee" memberName="GS4"
              virtualName="" explicitFocusOrder="0" pos="24 400 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="8c65bc6efcc4c953" memberName="DS3"
              virtualName="" explicitFocusOrder="0" pos="24 440 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="11e8748facae5482" memberName="AS2"
              virtualName="" explicitFocusOrder="0" pos="24 480 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="38889325be6cdf59" memberName="F1"
              virtualName="" explicitFocusOrder="0" pos="24 525 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="256b55a354c61630" memberName="C5"
              virtualName="" explicitFocusOrder="0" pos="24 360 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ee66443517e5cc2a" memberName="F2"
              virtualName="" explicitFocusOrder="0" pos="24 317 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1150582751d8f554" memberName="A4"
              virtualName="" explicitFocusOrder="0" pos="85 400 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="48d1d426ce401fa7" memberName="E3"
              virtualName="" explicitFocusOrder="0" pos="85 440 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="85bf0d6659d292cf" memberName="B2"
              virtualName="" explicitFocusOrder="0" pos="85 480 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="248c44bfea1f4b03" memberName="FS"
              virtualName="" explicitFocusOrder="0" pos="85 525 56 24" textcol="ff000000"
              bkgcol="3aff0000" outlinecol="522d2d" shadowcol="c12323" initialText="&#10;F#&#10;"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9e3372e35d461be6" memberName="CS5"
              virtualName="" explicitFocusOrder="0" pos="85 360 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1446fd17a02ce952" memberName="FS6"
              virtualName="" explicitFocusOrder="0" pos="85 317 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d6412f64c5d61ed9" memberName="AS4"
              virtualName="" explicitFocusOrder="0" pos="145 400 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="6b6a95ce76a43e78" memberName="F" virtualName=""
              explicitFocusOrder="0" pos="145 440 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="845fa63053d672b7" memberName="C2"
              virtualName="" explicitFocusOrder="0" pos="145 480 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="51298939a8a19acd" memberName="G" virtualName=""
              explicitFocusOrder="0" pos="145 525 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="7a2cca9782229d3c" memberName="D5"
              virtualName="" explicitFocusOrder="0" pos="145 360 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3b60e4e31b65c698" memberName="G6"
              virtualName="" explicitFocusOrder="0" pos="145 317 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f2d240f22b9509ad" memberName="B4"
              virtualName="" explicitFocusOrder="0" pos="201 401 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="db1be30023af9b5d" memberName="FS3"
              virtualName="" explicitFocusOrder="0" pos="201 441 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="b2f7b9627635e43e" memberName="CS2"
              virtualName="" explicitFocusOrder="0" pos="201 481 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3c29dcee22064d9f" memberName="GS"
              virtualName="" explicitFocusOrder="0" pos="201 526 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="fe43304bd428c553" memberName="DS5"
              virtualName="" explicitFocusOrder="0" pos="201 361 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="63533c6138e94925" memberName="GS6"
              virtualName="" explicitFocusOrder="0" pos="201 318 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2a65236799f11be3" memberName="C4"
              virtualName="" explicitFocusOrder="0" pos="257 396 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="bef9f3ce5b8183c3" memberName="G3"
              virtualName="" explicitFocusOrder="0" pos="257 436 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="541ba0a7b0dcda21" memberName="D2"
              virtualName="" explicitFocusOrder="0" pos="257 476 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="709c3ff69cde455a" memberName="A" virtualName=""
              explicitFocusOrder="0" pos="257 521 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f4c7f8a29ae2686d" memberName="E5"
              virtualName="" explicitFocusOrder="0" pos="257 356 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9e062d3865c3a6d6" memberName="A6"
              virtualName="" explicitFocusOrder="0" pos="257 313 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="afb5bca316e5cc6e" memberName="CS4"
              virtualName="" explicitFocusOrder="0" pos="311 400 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="678d85789080f749" memberName="GS3"
              virtualName="" explicitFocusOrder="0" pos="311 440 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="13f02da8033a15fa" memberName="DS2"
              virtualName="" explicitFocusOrder="0" pos="311 480 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="17541f8aa0e0c16f" memberName="AS"
              virtualName="" explicitFocusOrder="0" pos="311 525 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d34dddb5bda2afc8" memberName="F5"
              virtualName="" explicitFocusOrder="0" pos="311 360 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9541c70a1c430578" memberName="AS6"
              virtualName="" explicitFocusOrder="0" pos="311 317 54 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="36d89d85d2491463" memberName="D4"
              virtualName="" explicitFocusOrder="0" pos="367 396 49 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f56d4450a66f4d65" memberName="A3"
              virtualName="" explicitFocusOrder="0" pos="367 436 49 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="be86533ab2c0f36e" memberName="E2"
              virtualName="" explicitFocusOrder="0" pos="367 476 49 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2298f80f641b190d" memberName="B" virtualName=""
              explicitFocusOrder="0" pos="367 521 49 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a50cf62188f318cc" memberName="FS5"
              virtualName="" explicitFocusOrder="0" pos="367 356 49 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c5aa0440900f2b14" memberName="B6"
              virtualName="" explicitFocusOrder="0" pos="367 313 49 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="8b11edbbb6b93a3d" memberName="DS4"
              virtualName="" explicitFocusOrder="0" pos="419 397 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="35663d800eb06fe" memberName="AS3"
              virtualName="" explicitFocusOrder="0" pos="419 437 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="82bdd472cd349cf9" memberName="F3"
              virtualName="" explicitFocusOrder="0" pos="419 477 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="49bda9d59f9250c9" memberName="C" virtualName=""
              explicitFocusOrder="0" pos="419 522 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d2a1e2d6e4ec8efc" memberName="G5"
              virtualName="" explicitFocusOrder="0" pos="419 357 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ad744b27041092fe" memberName="C6"
              virtualName="" explicitFocusOrder="0" pos="419 314 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="527437bcdc447b1d" memberName="E4"
              virtualName="" explicitFocusOrder="0" pos="472 397 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ce62bba04be5dd5b" memberName="B3"
              virtualName="" explicitFocusOrder="0" pos="472 437 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f652d10509ebe94b" memberName="FS2"
              virtualName="" explicitFocusOrder="0" pos="472 477 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e0f6882bcc88dd0b" memberName="CS"
              virtualName="" explicitFocusOrder="0" pos="472 522 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="683dc1af36244b1c" memberName="GS5"
              virtualName="" explicitFocusOrder="0" pos="472 357 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9f5df1efa442c0c3" memberName="CS6"
              virtualName="" explicitFocusOrder="0" pos="472 314 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="aec7cefcf70eec10" memberName="F4"
              virtualName="" explicitFocusOrder="0" pos="518 396 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="5aecebb3ce5a6274" memberName="C3"
              virtualName="" explicitFocusOrder="0" pos="518 436 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="cdc65c06f224bb35" memberName="G2"
              virtualName="" explicitFocusOrder="0" pos="518 476 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="37bc7174c5d9f43b" memberName="D" virtualName=""
              explicitFocusOrder="0" pos="518 521 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="711cb79dd815b051" memberName="A5"
              virtualName="" explicitFocusOrder="0" pos="518 356 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a9fa6acc8204956f" memberName="D6"
              virtualName="" explicitFocusOrder="0" pos="518 313 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="eaaa77e97e97c2dc" memberName="FS4"
              virtualName="" explicitFocusOrder="0" pos="568 395 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a7db4ff38469c8c2" memberName="CS3"
              virtualName="" explicitFocusOrder="0" pos="568 435 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2648f4d1b0918a9d" memberName="GS2"
              virtualName="" explicitFocusOrder="0" pos="568 475 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e0a2f56fdc20e35b" memberName="DS"
              virtualName="" explicitFocusOrder="0" pos="568 520 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ab71d96f3affec99" memberName="AS5"
              virtualName="" explicitFocusOrder="0" pos="568 355 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f202c01a1c02b479" memberName="DS6"
              virtualName="" explicitFocusOrder="0" pos="568 312 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="7e5131977f911f5b" memberName="G4"
              virtualName="" explicitFocusOrder="0" pos="614 398 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1b61964a64e39cd7" memberName="D3"
              virtualName="" explicitFocusOrder="0" pos="614 438 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9d98dce091c93330" memberName="A2"
              virtualName="" explicitFocusOrder="0" pos="614 478 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c976fc24f6659c21" memberName="E" virtualName=""
              explicitFocusOrder="0" pos="614 523 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="78566031c387cffd" memberName="B5"
              virtualName="" explicitFocusOrder="0" pos="614 358 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="5f4415d59eaada7f" memberName="E6"
              virtualName="" explicitFocusOrder="0" pos="614 315 45 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: screenshot_20190321Blank20Pdf_png, 6469, "Screenshot_2019-03-21 blank-20 pdf.png"
static const unsigned char resource_PluginEditor_screenshot_20190321Blank20Pdf_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,4,78,0,0,0,124,8,6,0,0,0,119,193,245,57,0,0,25,12,73,68,65,84,
120,156,237,221,217,82,35,75,178,70,225,126,255,39,68,51,66,76,18,131,144,160,24,170,106,151,247,69,90,91,116,23,65,155,8,41,210,227,247,92,203,204,239,206,133,167,8,80,212,215,251,72,255,58,59,59,51,
134,97,24,134,97,24,134,97,24,134,97,24,230,243,252,235,144,255,163,217,108,102,139,197,98,176,147,123,77,166,211,169,251,94,30,51,159,207,63,189,22,163,209,104,112,103,100,58,157,102,207,133,247,94,125,
205,144,207,193,108,54,27,220,179,15,237,188,15,229,111,126,244,231,156,207,231,54,30,143,195,222,105,114,207,54,153,76,220,247,58,118,38,147,73,168,231,138,244,126,249,213,239,148,218,223,141,220,25,
27,143,199,238,123,29,50,185,247,227,241,120,108,243,249,220,125,183,104,123,171,253,238,42,189,39,40,220,63,114,103,246,32,56,217,110,183,246,246,246,54,216,201,189,38,119,119,119,238,123,121,204,143,
31,63,178,7,125,104,103,100,179,217,100,207,133,247,94,125,205,243,243,115,246,31,35,67,56,7,251,253,62,251,236,79,79,79,238,187,213,154,187,187,187,65,157,247,161,252,205,207,93,178,214,235,181,251,94,
167,154,253,126,159,189,160,69,249,59,181,92,46,63,61,219,213,213,149,251,94,199,206,229,229,229,167,231,186,188,188,116,223,171,116,94,95,95,179,255,152,121,124,124,116,223,237,187,243,252,252,108,231,
231,231,159,158,231,254,254,222,125,183,239,204,213,213,213,167,103,88,173,86,238,123,29,50,185,247,227,229,114,105,47,47,47,238,187,69,219,251,171,187,110,171,247,189,213,106,37,243,158,160,112,255,184,
191,191,183,209,104,244,125,56,249,241,227,135,13,185,175,48,105,136,253,243,207,63,89,56,121,121,121,241,94,173,215,182,219,109,246,92,12,165,95,191,126,125,122,246,249,124,110,175,175,175,222,171,85,
239,227,227,227,211,179,47,22,11,123,123,123,243,94,173,90,79,79,79,131,58,239,185,103,125,122,122,242,94,235,228,229,254,87,215,135,135,7,239,181,78,214,199,199,71,246,31,121,81,238,52,57,96,88,175,215,
222,107,29,221,237,237,237,167,231,186,185,185,241,94,171,184,63,127,254,132,185,55,253,250,245,203,46,46,46,62,61,207,110,183,243,94,237,91,229,206,216,245,245,181,247,90,7,149,123,63,94,173,86,246,235,
215,47,239,213,254,111,138,123,255,252,249,83,234,174,123,125,125,253,105,223,219,219,91,239,181,178,41,220,63,118,187,29,112,82,18,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,
237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,
24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,
25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,
0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,
24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,
133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,
56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,
3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,
56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,
97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,
1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,
167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,7,112,82,24,112,146,2,
78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,1,39,237,6,156,248,167,8,16,102,154,123,3,39,245,82,184,127,20,195,201,253,253,189,61,63,63,15,118,114,175,201,122,189,118,223,203,99,246,251,253,
167,215,98,50,153,12,238,140,228,222,116,207,206,206,220,247,234,107,114,111,128,211,233,212,30,30,30,220,119,171,61,57,52,155,205,102,246,248,248,232,190,91,173,89,175,215,131,58,239,67,249,155,63,30,
143,179,255,64,245,222,235,84,179,221,110,109,62,159,135,189,211,228,80,232,242,242,210,125,175,99,103,181,90,101,255,129,229,189,87,233,68,186,55,61,61,61,217,98,177,144,255,251,152,59,99,203,229,210,
125,175,67,38,247,126,124,126,126,110,187,221,206,125,183,146,189,159,158,158,220,119,251,106,114,247,189,150,239,186,57,212,108,245,111,167,194,253,99,189,94,151,193,201,120,60,182,201,100,50,216,225,
53,225,245,248,123,114,191,240,255,185,12,13,101,134,124,14,254,126,238,209,104,20,250,217,135,118,222,135,114,182,135,240,156,127,95,122,34,61,99,238,217,70,163,145,251,94,60,215,231,137,244,187,22,225,
119,74,249,140,229,222,143,21,118,87,221,91,233,119,87,233,92,43,188,174,185,51,123,16,156,48,12,195,48,12,195,48,12,195,48,12,195,12,113,14,130,147,229,114,105,151,151,151,131,157,220,107,114,126,126,
238,190,87,43,175,199,104,52,26,220,25,201,253,167,170,103,103,103,238,123,245,53,185,255,204,117,60,30,15,226,28,228,254,83,200,241,120,108,23,23,23,238,187,213,154,220,255,75,64,228,243,62,148,191,249,
185,255,117,106,177,88,184,239,117,170,185,184,184,200,254,47,91,81,254,78,77,167,211,79,207,54,155,205,220,247,58,118,102,179,89,184,231,138,114,111,90,173,86,217,223,41,181,191,143,185,51,54,157,78,
221,247,58,100,114,239,199,211,233,212,86,171,149,251,110,223,221,123,50,153,52,189,247,87,119,221,86,239,123,74,239,9,10,247,143,220,153,229,195,97,15,40,247,154,240,225,176,255,251,7,91,241,67,206,142,
137,15,135,229,195,97,255,254,99,207,135,195,198,41,247,172,124,56,172,94,124,56,172,102,124,56,108,187,241,225,176,254,41,126,200,170,153,230,222,124,56,108,189,20,238,31,124,171,78,97,192,73,10,56,233,
2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,199,194,201,
159,63,127,122,153,239,236,19,229,222,4,156,248,167,8,16,102,154,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,217,49,112,178,219,237,236,246,246,182,
151,57,244,111,62,112,210,94,192,73,255,41,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,199,192,201,102,179,233,237,171,42,247,251,253,65,59,
1,39,237,5,156,244,159,226,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,
156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,
6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,
31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,
36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,
212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,
238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,
230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,
4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,118,12,156,188,189,189,
217,110,183,235,101,126,254,252,121,208,78,192,73,123,1,39,253,167,184,55,112,82,47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,29,3,39,45,6,156,180,23,112,210,
127,138,123,3,39,245,82,184,127,0,39,133,1,39,41,224,164,11,56,1,78,128,147,184,231,29,56,137,17,112,162,25,112,210,110,192,137,127,138,0,97,166,185,55,112,82,47,133,251,71,49,156,220,221,221,217,126,
191,31,236,228,94,147,155,155,27,247,189,60,102,183,219,125,122,45,38,147,201,224,206,200,205,205,77,246,92,120,239,213,215,228,224,104,58,157,218,253,253,189,251,110,181,231,241,241,113,112,207,158,187,
100,70,62,239,185,103,189,189,189,117,223,235,212,51,30,143,179,255,120,240,222,235,84,243,248,248,104,243,249,60,236,157,38,135,66,171,213,202,125,175,99,39,247,15,243,139,139,11,247,189,74,39,210,189,
105,187,221,218,98,177,200,130,157,247,110,223,153,213,106,245,233,25,150,203,165,251,94,135,76,238,253,120,177,88,216,118,187,117,223,45,218,222,106,247,189,229,114,41,243,183,83,225,254,145,59,179,7,
193,9,195,48,12,195,48,12,195,48,12,195,48,204,16,7,56,97,24,134,97,24,134,97,24,134,97,24,134,249,98,14,130,147,241,120,60,232,201,189,38,163,209,200,125,175,150,94,15,239,157,250,158,191,255,127,222,
134,248,58,12,249,249,135,246,236,67,59,239,67,249,155,63,132,231,140,124,110,115,191,151,17,126,126,17,159,43,210,57,204,253,124,188,119,58,197,51,168,156,49,213,221,85,247,86,250,221,85,122,141,21,238,
31,185,215,147,15,135,61,160,220,107,194,135,195,166,81,253,144,179,99,226,195,97,249,112,216,255,30,62,28,54,86,185,103,229,195,97,245,226,195,97,53,227,195,97,219,141,15,135,245,79,241,67,86,205,52,
247,230,195,97,235,165,112,255,224,91,117,10,3,78,82,192,73,23,112,2,156,0,39,113,207,59,112,18,35,224,68,51,224,164,221,128,19,255,20,1,194,76,115,111,224,164,94,10,247,15,224,164,48,224,36,5,156,116,
1,39,192,9,112,18,247,188,3,39,49,2,78,52,3,78,218,13,56,241,79,17,32,204,52,247,6,78,234,165,112,255,0,78,10,3,78,82,181,224,228,231,207,159,246,240,240,208,203,156,226,178,2,156,156,30,78,250,250,249,
63,61,61,29,245,70,13,156,148,159,247,63,127,254,244,246,115,222,237,118,246,251,247,239,162,231,5,78,14,239,245,245,181,183,159,233,119,239,34,192,137,102,192,73,187,13,25,78,90,121,239,82,4,8,179,239,
239,253,242,242,210,219,107,254,241,241,145,221,33,42,156,180,112,23,3,78,2,7,156,164,106,193,201,203,203,139,77,38,147,94,230,20,250,10,156,156,30,78,250,250,249,47,151,203,163,144,3,56,57,14,78,250,
250,57,95,94,94,218,207,159,63,139,158,23,56,57,188,135,135,135,222,126,166,119,119,119,223,218,13,56,209,12,56,105,183,161,194,73,75,239,93,67,129,147,245,122,221,219,107,254,213,239,98,100,56,241,62,
207,167,184,127,212,14,56,41,12,56,73,1,39,93,192,9,112,2,156,0,39,234,157,226,226,2,156,248,5,156,104,4,156,180,23,112,210,127,192,73,253,128,147,211,6,156,20,6,156,164,128,147,46,224,4,56,1,78,128,19,
245,78,113,113,1,78,252,2,78,52,2,78,218,11,56,233,63,224,164,126,192,201,105,3,78,10,3,78,82,192,73,23,112,2,156,0,39,192,137,122,167,184,184,0,39,126,1,39,26,1,39,237,5,156,244,31,112,82,63,224,228,
180,1,39,133,1,39,41,224,164,11,56,1,78,128,19,224,68,189,83,92,92,128,19,191,128,19,141,128,147,246,2,78,250,15,56,169,31,112,114,218,128,147,194,128,147,20,112,210,5,156,0,39,192,9,112,162,222,41,46,
46,192,137,95,192,137,70,192,73,123,1,39,253,7,156,212,15,56,57,109,192,73,97,192,73,10,56,233,2,78,128,19,224,4,56,81,239,20,23,23,224,196,47,224,68,35,224,164,189,128,147,254,3,78,234,7,156,156,54,224,
164,48,224,36,5,156,116,1,39,192,9,112,2,156,168,119,138,139,11,112,226,23,112,162,17,112,210,94,192,73,255,1,39,245,3,78,78,27,112,82,24,112,146,2,78,186,128,19,224,4,56,1,78,212,59,197,197,5,56,241,
11,56,209,8,56,105,47,224,164,255,128,147,250,1,39,167,13,56,41,12,56,73,1,39,93,192,9,112,2,156,0,39,234,157,226,226,2,156,248,5,156,104,4,156,180,23,112,210,127,192,73,253,128,147,211,6,156,20,6,156,
164,128,147,46,224,4,56,1,78,128,19,245,78,113,113,1,78,252,2,78,52,2,78,218,11,56,233,63,224,164,126,192,201,105,3,78,10,3,78,82,192,73,23,112,2,156,0,39,192,137,122,167,184,184,0,39,126,1,39,26,1,39,
237,5,156,244,31,112,82,63,224,228,180,1,39,133,1,39,41,224,164,11,56,1,78,128,19,224,68,189,83,92,92,128,19,191,128,19,141,128,147,246,2,78,250,15,56,169,31,112,114,218,128,147,194,128,147,84,45,56,121,
127,127,183,219,219,219,94,230,20,111,240,192,201,233,225,164,175,159,255,253,253,125,241,63,168,205,128,147,99,225,164,175,159,243,227,227,163,253,254,253,187,232,121,129,147,195,123,126,126,238,237,
103,186,223,239,191,181,27,112,162,25,112,210,110,67,134,147,190,254,206,61,60,60,252,223,247,174,161,192,201,110,183,235,237,53,127,127,127,207,238,16,25,78,188,239,98,192,73,224,128,147,84,45,56,81,
11,56,57,61,156,168,4,156,196,63,239,192,73,140,128,19,205,128,147,118,27,42,156,180,212,80,224,164,133,162,194,73,11,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,8,56,
209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,194,253,163,24,78,246,251,189,253,254,253,123,176,147,123,77,254,243,159,30,13,109,114,127,68,166,211,233,224,206,200,195,195,67,246,92,120,
239,213,215,188,191,191,127,122,246,217,108,102,207,207,207,238,187,213,158,215,215,215,236,27,233,203,203,139,251,110,181,230,241,241,113,80,231,125,40,127,243,115,23,151,251,251,123,247,189,78,53,175,
175,175,89,56,137,242,119,106,181,90,101,129,193,123,175,99,39,119,249,191,190,190,118,223,171,116,114,255,67,131,234,189,233,253,253,61,11,39,219,237,214,125,183,239,204,205,205,205,167,103,184,186,186,
114,223,235,144,201,189,31,95,92,92,216,199,199,135,251,110,37,123,191,191,191,187,239,246,213,188,189,189,73,221,247,174,174,174,100,222,19,20,238,31,219,237,182,12,78,24,134,97,24,134,97,24,134,97,24,
134,97,134,56,192,9,195,48,12,195,48,12,195,48,12,195,48,204,23,3,156,48,12,195,48,12,195,48,12,195,48,12,195,124,49,7,193,201,104,52,26,244,240,154,240,122,240,58,240,252,67,127,246,33,61,243,80,158,
117,8,207,25,249,25,121,54,157,137,244,60,81,158,69,249,57,84,119,87,220,91,105,103,118,173,191,39,223,170,115,64,185,215,132,111,213,73,163,250,233,240,199,196,183,234,240,173,58,255,61,124,171,78,172,
114,207,202,183,234,232,197,183,234,104,198,183,234,180,27,223,170,227,159,226,183,211,152,105,238,205,183,234,212,75,225,254,193,215,17,23,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,
137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,
254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,199,192,201,102,179,177,201,100,210,203,236,247,251,131,118,2,78,218,11,56,233,63,197,189,129,147,122,41,220,63,128,147,
194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,8,56,209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,194,253,3,56,41,12,56,73,1,39,93,192,9,112,2,156,196,61,239,192,73,140,128,
19,205,128,147,118,3,78,252,83,4,8,51,205,189,129,147,122,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,8,56,209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,
194,253,3,56,41,12,56,73,1,39,93,192,9,112,2,156,196,61,239,192,73,140,128,19,205,128,147,118,3,78,252,83,4,8,51,205,189,129,147,122,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,
14,156,196,8,56,209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,194,253,3,56,41,12,56,73,1,39,93,192,9,112,2,156,196,61,239,192,73,140,128,19,205,128,147,118,3,78,252,83,4,8,51,205,189,129,
147,122,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,8,56,209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,194,253,3,56,41,12,56,73,1,39,93,192,9,112,2,156,
196,61,239,192,73,140,128,19,205,128,147,118,3,78,252,83,4,8,51,205,189,129,147,122,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,8,56,209,12,56,105,55,224,196,63,69,128,
48,211,220,27,56,169,151,194,253,3,56,41,12,56,73,1,39,93,192,9,112,2,156,196,61,239,192,73,140,128,19,205,128,147,118,3,78,252,83,4,8,51,205,189,129,147,122,41,220,63,128,147,194,128,147,20,112,210,5,
156,0,39,192,73,220,243,14,156,196,8,56,209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,194,253,3,56,41,12,56,73,1,39,93,192,9,112,2,156,196,61,239,192,73,140,128,19,205,128,147,118,3,78,252,
83,4,8,51,205,189,129,147,122,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,8,56,209,236,24,56,185,187,187,179,217,108,214,203,0,39,192,137,71,138,0,97,166,185,55,112,82,
47,133,251,7,112,82,24,112,146,2,78,186,128,19,224,4,56,137,123,222,129,147,24,1,39,154,29,3,39,239,239,239,246,252,252,220,203,28,250,15,62,224,164,189,128,147,254,83,220,27,56,169,151,194,253,3,56,41,
12,56,73,1,39,93,192,9,112,2,156,196,61,239,192,73,140,128,19,205,142,129,147,22,3,78,218,11,56,233,63,197,189,129,147,122,41,220,63,128,147,194,128,147,20,112,210,5,156,0,39,192,73,220,243,14,156,196,
8,56,209,12,56,105,55,224,196,63,69,128,48,211,220,27,56,169,151,194,253,163,24,78,24,134,97,24,134,97,24,134,97,24,134,97,134,56,192,9,195,48,12,195,48,12,195,48,12,195,48,204,23,3,156,48,12,195,48,12,
195,48,12,195,48,12,195,124,49,192,9,195,48,12,195,48,12,195,48,12,195,48,204,23,115,16,156,92,95,95,219,221,221,221,96,39,247,154,92,94,94,186,239,229,49,155,205,230,211,107,49,30,143,7,119,70,114,31,
202,119,118,118,230,190,87,95,179,94,175,63,61,251,100,50,177,155,155,27,247,221,106,79,238,67,229,166,211,169,221,222,222,186,239,86,107,134,118,222,135,242,55,255,239,15,61,59,59,235,62,172,207,123,
175,83,205,237,237,173,205,102,179,176,119,154,249,124,254,233,217,150,203,165,251,94,199,78,238,3,125,207,207,207,221,247,58,102,162,220,155,214,235,117,246,220,169,253,125,204,157,177,197,98,225,190,
215,33,147,123,63,158,207,231,182,217,108,220,119,43,217,123,189,94,187,239,246,213,168,221,117,23,139,133,204,223,78,133,251,199,213,213,85,25,156,68,249,4,250,210,114,175,9,223,170,243,191,255,104,84,
252,116,248,99,226,91,117,248,86,157,191,47,92,124,171,78,156,114,207,202,183,234,232,197,183,234,104,198,183,234,180,27,223,170,227,159,226,183,211,152,105,238,205,183,234,212,75,225,254,193,215,17,23,
6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,
6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,
31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,
36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,
212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,
238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,
230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,
4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,
34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,
56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,
187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,192,73,97,192,73,10,56,233,2,78,128,19,224,36,238,121,7,78,98,4,156,104,6,156,180,27,112,226,159,34,64,152,105,238,13,156,212,75,225,254,1,156,20,
6,156,164,128,147,46,224,4,56,1,78,226,158,119,224,36,70,192,137,102,192,73,187,1,39,254,41,2,132,153,230,222,192,73,189,20,238,31,197,112,242,240,240,96,47,47,47,131,157,220,107,178,94,175,221,247,242,
152,231,231,231,79,175,197,100,50,25,220,25,89,175,215,217,115,225,189,87,95,179,219,237,178,23,193,33,156,131,28,154,205,102,51,123,124,124,116,223,173,214,108,54,155,65,157,247,220,179,110,54,27,247,
189,78,61,227,241,56,123,201,242,222,235,84,179,221,110,109,62,159,135,189,211,228,80,232,242,242,210,125,175,99,103,181,90,101,255,129,229,189,87,233,124,117,111,186,191,191,119,223,237,187,179,219,237,
178,231,78,237,239,99,14,29,47,46,46,220,247,58,100,114,247,207,243,243,115,219,237,118,238,187,69,219,59,135,61,45,223,247,114,168,217,234,123,130,194,253,99,179,217,148,193,201,100,50,177,233,116,58,
216,201,189,38,227,241,216,125,175,150,94,143,161,157,145,220,47,252,127,240,96,8,147,147,226,209,104,52,136,115,48,196,103,207,61,115,228,243,62,148,191,113,209,223,219,38,147,201,167,75,79,164,159,101,
238,217,34,252,252,114,239,175,234,207,21,233,111,74,132,223,169,220,25,27,141,70,238,123,69,222,93,113,111,181,251,158,210,123,130,194,253,35,247,243,63,8,78,24,134,97,24,134,97,24,134,97,24,134,97,134,
56,192,9,195,48,12,195,48,12,195,48,12,195,48,204,23,3,156,48,12,195,48,12,195,48,12,195,48,12,195,124,49,255,6,154,240,109,11,111,164,106,218,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::screenshot_20190321Blank20Pdf_png = (const char*) resource_PluginEditor_screenshot_20190321Blank20Pdf_png;
const int PluginEditor::screenshot_20190321Blank20Pdf_pngSize = 6469;


//[EndFile] You can add extra defines here...
//[/EndFile]
