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


juce::Colour colorF = Colour(0xff4d91a9);
juce::Colour colorFs = Colour(0xff5681ab);
juce::Colour colorG = Colour(0xff706ea1);
juce::Colour colorGs = Colour(0xff885887);
juce::Colour colorA = Colour(0xff934561);
juce::Colour colorAs = Colour(0xffbd5c63);
juce::Colour colorB = Colour(0xffdf7b60);
juce::Colour colorC = Colour(0xfffecb5f);
juce::Colour colorCs = Colour(0xffc1be4f);
juce::Colour colorD = Colour(0xff86af4d);
juce::Colour colorDs = Colour(0xff499b53);
juce::Colour colorE = Colour(0xff007062);



//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (MusicTheoryAudioProcessor& p)
    : AudioProcessorEditor (&p)
{
    //[Constructor_pre] You can add your own custom stuff here..

    //[/Constructor_pre]

    addAndMakeVisible (*(groupComponent = std::make_unique<GroupComponent> ("new group",
                                                            TRANS("guitar"))));
    groupComponent->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(groupComponent4 = std::make_unique<GroupComponent> ("new group",
                                                             TRANS("scales"))));
    groupComponent4->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(groupComponent3 = std::make_unique<GroupComponent> ("new group",
                                                             TRANS("notepad"))));
    groupComponent3->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(groupComponent2 = std::make_unique<GroupComponent> ("new group",
                                                             TRANS("chords"))));
    groupComponent2->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(scaleKey = std::make_unique<ComboBox> ("new combo box")));
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

    addAndMakeVisible (*(comboBox2 = std::make_unique<ComboBox> ("new combo box")));
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (TRANS("Notes"));
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox2->addItem (TRANS("Notes"), 1);
    comboBox2->addItem (TRANS("Scales"), 2);
    comboBox2->addItem (TRANS("Chords"), 3);
    comboBox2->addListener (this);

    addAndMakeVisible (*(scaleMode = std::make_unique<ComboBox> ("new combo box")));
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

    addAndMakeVisible (*(chordRoot = std::make_unique<ComboBox> ("new combo box")));
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

    addAndMakeVisible (*(chordType = std::make_unique<ComboBox> ("new combo box")));
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

    addAndMakeVisible (*(textEditor2 = std::make_unique<TextEditor> ("new text editor")));
    textEditor2->setMultiLine (true);
    textEditor2->setReturnKeyStartsNewLine (true);
    textEditor2->setReadOnly (false);
    textEditor2->setScrollbarsShown (true);
    textEditor2->setCaretVisible (true);
    textEditor2->setPopupMenuEnabled (true);
    textEditor2->setColour (TextEditor::backgroundColourId, Colour (0xff508385));
    textEditor2->setText (TRANS("write anything here ...\n"));

    addAndMakeVisible (*(txtScale = std::make_unique<TextEditor> ("new text editor")));
    txtScale->setMultiLine (true);
    txtScale->setReturnKeyStartsNewLine (false);
    txtScale->setReadOnly (true);
    txtScale->setScrollbarsShown (false);
    txtScale->setCaretVisible (false);
    txtScale->setPopupMenuEnabled (false);
    txtScale->setColour (TextEditor::backgroundColourId, Colours::cadetblue);
    txtScale->setText (String());

    addAndMakeVisible (*(txtChord = std::make_unique<TextEditor> ("new text editor")));
    txtChord->setMultiLine (true);
    txtChord->setReturnKeyStartsNewLine (false);
    txtChord->setReadOnly (true);
    txtChord->setScrollbarsShown (false);
    txtChord->setCaretVisible (false);
    txtChord->setPopupMenuEnabled (false);
    txtChord->setColour (TextEditor::backgroundColourId, Colours::cadetblue);
    txtChord->setText (String());

    addAndMakeVisible (*(GS4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(DS3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(AS2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(F1 = std::make_unique<TextEditor> ("new text editor")));
    F1->setMultiLine (true);
    F1->setReturnKeyStartsNewLine (false);
    F1->setReadOnly (true);
    F1->setScrollbarsShown (false);
    F1->setCaretVisible (false);
    F1->setPopupMenuEnabled (false);
    F1->setColour (TextEditor::textColourId, Colours::black);
    F1->setColour (TextEditor::backgroundColourId, Colour (0xff4d91a9));
    F1->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F1->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F1->setText (TRANS("F"));

    addAndMakeVisible (*(C5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(F2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(A4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(E3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(B2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(FS = std::make_unique<TextEditor> ("new text editor")));
    FS->setMultiLine (true);
    FS->setReturnKeyStartsNewLine (false);
    FS->setReadOnly (true);
    FS->setScrollbarsShown (false);
    FS->setCaretVisible (false);
    FS->setPopupMenuEnabled (false);
    FS->setColour (TextEditor::textColourId, Colours::black);
    FS->setColour (TextEditor::backgroundColourId, Colour (0xff5681ab));
    FS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS->setText (TRANS("F#"));

    addAndMakeVisible (*(CS5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(FS6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(AS4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(F = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(C2 = std::make_unique<TextEditor> ("new text editor")));
    C2->setMultiLine (true);
    C2->setReturnKeyStartsNewLine (false);
    C2->setReadOnly (true);
    C2->setScrollbarsShown (false);
    C2->setCaretVisible (false);
    C2->setPopupMenuEnabled (false);
    C2->setColour (TextEditor::textColourId, Colours::black);
    C2->setColour (TextEditor::backgroundColourId, Colour (0xd4ab1e1e));
    C2->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C2->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C2->setText (TRANS("C"));

    addAndMakeVisible (*(G = std::make_unique<TextEditor> ("new text editor")));
    G->setMultiLine (true);
    G->setReturnKeyStartsNewLine (false);
    G->setReadOnly (true);
    G->setScrollbarsShown (false);
    G->setCaretVisible (false);
    G->setPopupMenuEnabled (false);
    G->setColour (TextEditor::textColourId, Colours::black);
    G->setColour (TextEditor::backgroundColourId, Colour (0xff706ea1));
    G->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G->setText (TRANS("G"));

    addAndMakeVisible (*(D5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(G6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(B4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(FS3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(CS2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(GS = std::make_unique<TextEditor> ("new text editor")));
    GS->setMultiLine (true);
    GS->setReturnKeyStartsNewLine (false);
    GS->setReadOnly (true);
    GS->setScrollbarsShown (false);
    GS->setCaretVisible (false);
    GS->setPopupMenuEnabled (false);
    GS->setColour (TextEditor::textColourId, Colours::black);
    GS->setColour (TextEditor::backgroundColourId, Colour (0xff885887));
    GS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS->setText (TRANS("G#"));

    addAndMakeVisible (*(DS5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(GS6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(C4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(G3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(D2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(A = std::make_unique<TextEditor> ("new text editor")));
    A->setMultiLine (true);
    A->setReturnKeyStartsNewLine (false);
    A->setReadOnly (true);
    A->setScrollbarsShown (false);
    A->setCaretVisible (false);
    A->setPopupMenuEnabled (false);
    A->setColour (TextEditor::textColourId, Colours::black);
    A->setColour (TextEditor::backgroundColourId, Colour (0xff934561));
    A->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A->setText (TRANS("A"));

    addAndMakeVisible (*(E5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(A6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(CS4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(GS3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(DS2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(AS = std::make_unique<TextEditor> ("new text editor")));
    AS->setMultiLine (true);
    AS->setReturnKeyStartsNewLine (false);
    AS->setReadOnly (true);
    AS->setScrollbarsShown (false);
    AS->setCaretVisible (false);
    AS->setPopupMenuEnabled (false);
    AS->setColour (TextEditor::textColourId, Colours::black);
    AS->setColour (TextEditor::backgroundColourId, Colour (0xffbd5c63));
    AS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS->setText (TRANS("A#"));

    addAndMakeVisible (*(F5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(AS6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(D4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(A3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(E2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(B = std::make_unique<TextEditor> ("new text editor")));
    B->setMultiLine (true);
    B->setReturnKeyStartsNewLine (false);
    B->setReadOnly (true);
    B->setScrollbarsShown (false);
    B->setCaretVisible (false);
    B->setPopupMenuEnabled (false);
    B->setColour (TextEditor::textColourId, Colours::black);
    B->setColour (TextEditor::backgroundColourId, Colour (0xffdf7b60));
    B->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B->setText (TRANS("B"));

    addAndMakeVisible (*(FS5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(B6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(DS4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(AS3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(F3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(C = std::make_unique<TextEditor> ("new text editor")));
    C->setMultiLine (true);
    C->setReturnKeyStartsNewLine (false);
    C->setReadOnly (true);
    C->setScrollbarsShown (false);
    C->setCaretVisible (false);
    C->setPopupMenuEnabled (false);
    C->setColour (TextEditor::textColourId, Colours::black);
    C->setColour (TextEditor::backgroundColourId, Colour (0xfffecb5f));
    C->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C->setText (TRANS("C"));

    addAndMakeVisible (*(G5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(C6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(E4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(B3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(FS2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(CS = std::make_unique<TextEditor> ("new text editor")));
    CS->setMultiLine (true);
    CS->setReturnKeyStartsNewLine (false);
    CS->setReadOnly (true);
    CS->setScrollbarsShown (false);
    CS->setCaretVisible (false);
    CS->setPopupMenuEnabled (false);
    CS->setColour (TextEditor::textColourId, Colours::black);
    CS->setColour (TextEditor::backgroundColourId, Colour (0xffc1be4f));
    CS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS->setText (TRANS("C#"));

    addAndMakeVisible (*(GS5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(CS6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(F4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(C3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(G2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(D = std::make_unique<TextEditor> ("new text editor")));
    D->setMultiLine (true);
    D->setReturnKeyStartsNewLine (false);
    D->setReadOnly (true);
    D->setScrollbarsShown (false);
    D->setCaretVisible (false);
    D->setPopupMenuEnabled (false);
    D->setColour (TextEditor::textColourId, Colours::black);
    D->setColour (TextEditor::backgroundColourId, Colour (0xff86af4d));
    D->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D->setText (TRANS("D"));

    addAndMakeVisible (*(A5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(D6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(FS4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(CS3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(GS2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(DS = std::make_unique<TextEditor> ("new text editor")));
    DS->setMultiLine (true);
    DS->setReturnKeyStartsNewLine (false);
    DS->setReadOnly (true);
    DS->setScrollbarsShown (false);
    DS->setCaretVisible (false);
    DS->setPopupMenuEnabled (false);
    DS->setColour (TextEditor::textColourId, Colours::black);
    DS->setColour (TextEditor::backgroundColourId, Colour (0xff499b53));
    DS->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS->setText (TRANS("D#"));

    addAndMakeVisible (*(AS5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(DS6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(G4 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(D3 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(A2 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(E = std::make_unique<TextEditor> ("new text editor")));
    E->setMultiLine (true);
    E->setReturnKeyStartsNewLine (false);
    E->setReadOnly (true);
    E->setScrollbarsShown (false);
    E->setCaretVisible (false);
    E->setPopupMenuEnabled (false);
    E->setColour (TextEditor::textColourId, Colours::black);
    E->setColour (TextEditor::backgroundColourId, Colour (0xff007062));
    E->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E->setText (TRANS("E"));

    addAndMakeVisible (*(B5 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(E6 = std::make_unique<TextEditor> ("new text editor")));
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

    addAndMakeVisible (*(GS7 = std::make_unique<TextEditor> ("new text editor")));
    GS7->setMultiLine (true);
    GS7->setReturnKeyStartsNewLine (false);
    GS7->setReadOnly (true);
    GS7->setScrollbarsShown (false);
    GS7->setCaretVisible (false);
    GS7->setPopupMenuEnabled (false);
    GS7->setColour (TextEditor::textColourId, Colours::black);
    GS7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS7->setText (TRANS("G#"));

    addAndMakeVisible (*(DS7 = std::make_unique<TextEditor> ("new text editor")));
    DS7->setMultiLine (true);
    DS7->setReturnKeyStartsNewLine (false);
    DS7->setReadOnly (true);
    DS7->setScrollbarsShown (false);
    DS7->setCaretVisible (false);
    DS7->setPopupMenuEnabled (false);
    DS7->setColour (TextEditor::textColourId, Colours::black);
    DS7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS7->setText (TRANS("D#"));

    addAndMakeVisible (*(AS7 = std::make_unique<TextEditor> ("new text editor")));
    AS7->setMultiLine (true);
    AS7->setReturnKeyStartsNewLine (false);
    AS7->setReadOnly (true);
    AS7->setScrollbarsShown (false);
    AS7->setCaretVisible (false);
    AS7->setPopupMenuEnabled (false);
    AS7->setColour (TextEditor::textColourId, Colours::black);
    AS7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS7->setText (TRANS("A#"));

    addAndMakeVisible (*(F6 = std::make_unique<TextEditor> ("new text editor")));
    F6->setMultiLine (true);
    F6->setReturnKeyStartsNewLine (false);
    F6->setReadOnly (true);
    F6->setScrollbarsShown (false);
    F6->setCaretVisible (false);
    F6->setPopupMenuEnabled (false);
    F6->setColour (TextEditor::textColourId, Colours::black);
    F6->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F6->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F6->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F6->setText (TRANS("F"));

    addAndMakeVisible (*(C7 = std::make_unique<TextEditor> ("new text editor")));
    C7->setMultiLine (true);
    C7->setReturnKeyStartsNewLine (false);
    C7->setReadOnly (true);
    C7->setScrollbarsShown (false);
    C7->setCaretVisible (false);
    C7->setPopupMenuEnabled (false);
    C7->setColour (TextEditor::textColourId, Colours::black);
    C7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C7->setText (TRANS("C"));

    addAndMakeVisible (*(F7 = std::make_unique<TextEditor> ("new text editor")));
    F7->setMultiLine (true);
    F7->setReturnKeyStartsNewLine (false);
    F7->setReadOnly (true);
    F7->setScrollbarsShown (false);
    F7->setCaretVisible (false);
    F7->setPopupMenuEnabled (false);
    F7->setColour (TextEditor::textColourId, Colours::black);
    F7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F7->setText (TRANS("F"));

    addAndMakeVisible (*(A7 = std::make_unique<TextEditor> ("new text editor")));
    A7->setMultiLine (true);
    A7->setReturnKeyStartsNewLine (false);
    A7->setReadOnly (true);
    A7->setScrollbarsShown (false);
    A7->setCaretVisible (false);
    A7->setPopupMenuEnabled (false);
    A7->setColour (TextEditor::textColourId, Colours::black);
    A7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A7->setText (TRANS("A"));

    addAndMakeVisible (*(E7 = std::make_unique<TextEditor> ("new text editor")));
    E7->setMultiLine (true);
    E7->setReturnKeyStartsNewLine (false);
    E7->setReadOnly (true);
    E7->setScrollbarsShown (false);
    E7->setCaretVisible (false);
    E7->setPopupMenuEnabled (false);
    E7->setColour (TextEditor::textColourId, Colours::black);
    E7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E7->setText (TRANS("E"));

    addAndMakeVisible (*(B7 = std::make_unique<TextEditor> ("new text editor")));
    B7->setMultiLine (true);
    B7->setReturnKeyStartsNewLine (false);
    B7->setReadOnly (true);
    B7->setScrollbarsShown (false);
    B7->setCaretVisible (false);
    B7->setPopupMenuEnabled (false);
    B7->setColour (TextEditor::textColourId, Colours::black);
    B7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B7->setText (TRANS("B"));

    addAndMakeVisible (*(FS7 = std::make_unique<TextEditor> ("new text editor")));
    FS7->setMultiLine (true);
    FS7->setReturnKeyStartsNewLine (false);
    FS7->setReadOnly (true);
    FS7->setScrollbarsShown (false);
    FS7->setCaretVisible (false);
    FS7->setPopupMenuEnabled (false);
    FS7->setColour (TextEditor::textColourId, Colours::black);
    FS7->setColour (TextEditor::backgroundColourId, Colour (0xff5681ab));
    FS7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS7->setText (TRANS("\n"
    "F#\n"));

    addAndMakeVisible (*(CS7 = std::make_unique<TextEditor> ("new text editor")));
    CS7->setMultiLine (true);
    CS7->setReturnKeyStartsNewLine (false);
    CS7->setReadOnly (true);
    CS7->setScrollbarsShown (false);
    CS7->setCaretVisible (false);
    CS7->setPopupMenuEnabled (false);
    CS7->setColour (TextEditor::textColourId, Colours::black);
    CS7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS7->setText (TRANS("C#"));

    addAndMakeVisible (*(FS8 = std::make_unique<TextEditor> ("new text editor")));
    FS8->setMultiLine (true);
    FS8->setReturnKeyStartsNewLine (false);
    FS8->setReadOnly (true);
    FS8->setScrollbarsShown (false);
    FS8->setCaretVisible (false);
    FS8->setPopupMenuEnabled (false);
    FS8->setColour (TextEditor::textColourId, Colours::black);
    FS8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS8->setText (TRANS("F#"));

    addAndMakeVisible (*(AS8 = std::make_unique<TextEditor> ("new text editor")));
    AS8->setMultiLine (true);
    AS8->setReturnKeyStartsNewLine (false);
    AS8->setReadOnly (true);
    AS8->setScrollbarsShown (false);
    AS8->setCaretVisible (false);
    AS8->setPopupMenuEnabled (false);
    AS8->setColour (TextEditor::textColourId, Colours::black);
    AS8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS8->setText (TRANS("A#"));

    addAndMakeVisible (*(F8 = std::make_unique<TextEditor> ("new text editor")));
    F8->setMultiLine (true);
    F8->setReturnKeyStartsNewLine (false);
    F8->setReadOnly (true);
    F8->setScrollbarsShown (false);
    F8->setCaretVisible (false);
    F8->setPopupMenuEnabled (false);
    F8->setColour (TextEditor::textColourId, Colours::black);
    F8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F8->setText (TRANS("F"));

    addAndMakeVisible (*(C8 = std::make_unique<TextEditor> ("new text editor")));
    C8->setMultiLine (true);
    C8->setReturnKeyStartsNewLine (false);
    C8->setReadOnly (true);
    C8->setScrollbarsShown (false);
    C8->setCaretVisible (false);
    C8->setPopupMenuEnabled (false);
    C8->setColour (TextEditor::textColourId, Colours::black);
    C8->setColour (TextEditor::backgroundColourId, Colour (0xd4ab1e1e));
    C8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C8->setText (TRANS("C"));

    addAndMakeVisible (*(G7 = std::make_unique<TextEditor> ("new text editor")));
    G7->setMultiLine (true);
    G7->setReturnKeyStartsNewLine (false);
    G7->setReadOnly (true);
    G7->setScrollbarsShown (false);
    G7->setCaretVisible (false);
    G7->setPopupMenuEnabled (false);
    G7->setColour (TextEditor::textColourId, Colours::black);
    G7->setColour (TextEditor::backgroundColourId, Colour (0xff706ea1));
    G7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G7->setText (TRANS("G"));

    addAndMakeVisible (*(D7 = std::make_unique<TextEditor> ("new text editor")));
    D7->setMultiLine (true);
    D7->setReturnKeyStartsNewLine (false);
    D7->setReadOnly (true);
    D7->setScrollbarsShown (false);
    D7->setCaretVisible (false);
    D7->setPopupMenuEnabled (false);
    D7->setColour (TextEditor::textColourId, Colours::black);
    D7->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D7->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D7->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D7->setText (TRANS("D"));

    addAndMakeVisible (*(G8 = std::make_unique<TextEditor> ("new text editor")));
    G8->setMultiLine (true);
    G8->setReturnKeyStartsNewLine (false);
    G8->setReadOnly (true);
    G8->setScrollbarsShown (false);
    G8->setCaretVisible (false);
    G8->setPopupMenuEnabled (false);
    G8->setColour (TextEditor::textColourId, Colours::black);
    G8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G8->setText (TRANS("G"));

    addAndMakeVisible (*(B8 = std::make_unique<TextEditor> ("new text editor")));
    B8->setMultiLine (true);
    B8->setReturnKeyStartsNewLine (false);
    B8->setReadOnly (true);
    B8->setScrollbarsShown (false);
    B8->setCaretVisible (false);
    B8->setPopupMenuEnabled (false);
    B8->setColour (TextEditor::textColourId, Colours::black);
    B8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B8->setText (TRANS("B"));

    addAndMakeVisible (*(FS9 = std::make_unique<TextEditor> ("new text editor")));
    FS9->setMultiLine (true);
    FS9->setReturnKeyStartsNewLine (false);
    FS9->setReadOnly (true);
    FS9->setScrollbarsShown (false);
    FS9->setCaretVisible (false);
    FS9->setPopupMenuEnabled (false);
    FS9->setColour (TextEditor::textColourId, Colours::black);
    FS9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS9->setText (TRANS("F#"));

    addAndMakeVisible (*(CS8 = std::make_unique<TextEditor> ("new text editor")));
    CS8->setMultiLine (true);
    CS8->setReturnKeyStartsNewLine (false);
    CS8->setReadOnly (true);
    CS8->setScrollbarsShown (false);
    CS8->setCaretVisible (false);
    CS8->setPopupMenuEnabled (false);
    CS8->setColour (TextEditor::textColourId, Colours::black);
    CS8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS8->setText (TRANS("C#"));

    addAndMakeVisible (*(GS8 = std::make_unique<TextEditor> ("new text editor")));
    GS8->setMultiLine (true);
    GS8->setReturnKeyStartsNewLine (false);
    GS8->setReadOnly (true);
    GS8->setScrollbarsShown (false);
    GS8->setCaretVisible (false);
    GS8->setPopupMenuEnabled (false);
    GS8->setColour (TextEditor::textColourId, Colours::black);
    GS8->setColour (TextEditor::backgroundColourId, Colour (0xff885887));
    GS8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS8->setText (TRANS("G#"));

    addAndMakeVisible (*(DS8 = std::make_unique<TextEditor> ("new text editor")));
    DS8->setMultiLine (true);
    DS8->setReturnKeyStartsNewLine (false);
    DS8->setReadOnly (true);
    DS8->setScrollbarsShown (false);
    DS8->setCaretVisible (false);
    DS8->setPopupMenuEnabled (false);
    DS8->setColour (TextEditor::textColourId, Colours::black);
    DS8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS8->setText (TRANS("D#"));

    addAndMakeVisible (*(GS9 = std::make_unique<TextEditor> ("new text editor")));
    GS9->setMultiLine (true);
    GS9->setReturnKeyStartsNewLine (false);
    GS9->setReadOnly (true);
    GS9->setScrollbarsShown (false);
    GS9->setCaretVisible (false);
    GS9->setPopupMenuEnabled (false);
    GS9->setColour (TextEditor::textColourId, Colours::black);
    GS9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS9->setText (TRANS("G#"));

    addAndMakeVisible (*(C9 = std::make_unique<TextEditor> ("new text editor")));
    C9->setMultiLine (true);
    C9->setReturnKeyStartsNewLine (false);
    C9->setReadOnly (true);
    C9->setScrollbarsShown (false);
    C9->setCaretVisible (false);
    C9->setPopupMenuEnabled (false);
    C9->setColour (TextEditor::textColourId, Colours::black);
    C9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C9->setText (TRANS("C"));

    addAndMakeVisible (*(G9 = std::make_unique<TextEditor> ("new text editor")));
    G9->setMultiLine (true);
    G9->setReturnKeyStartsNewLine (false);
    G9->setReadOnly (true);
    G9->setScrollbarsShown (false);
    G9->setCaretVisible (false);
    G9->setPopupMenuEnabled (false);
    G9->setColour (TextEditor::textColourId, Colours::black);
    G9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G9->setText (TRANS("G"));

    addAndMakeVisible (*(D8 = std::make_unique<TextEditor> ("new text editor")));
    D8->setMultiLine (true);
    D8->setReturnKeyStartsNewLine (false);
    D8->setReadOnly (true);
    D8->setScrollbarsShown (false);
    D8->setCaretVisible (false);
    D8->setPopupMenuEnabled (false);
    D8->setColour (TextEditor::textColourId, Colours::black);
    D8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D8->setText (TRANS("D"));

    addAndMakeVisible (*(A8 = std::make_unique<TextEditor> ("new text editor")));
    A8->setMultiLine (true);
    A8->setReturnKeyStartsNewLine (false);
    A8->setReadOnly (true);
    A8->setScrollbarsShown (false);
    A8->setCaretVisible (false);
    A8->setPopupMenuEnabled (false);
    A8->setColour (TextEditor::textColourId, Colours::black);
    A8->setColour (TextEditor::backgroundColourId, Colour (0xff934561));
    A8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A8->setText (TRANS("A"));

    addAndMakeVisible (*(E8 = std::make_unique<TextEditor> ("new text editor")));
    E8->setMultiLine (true);
    E8->setReturnKeyStartsNewLine (false);
    E8->setReadOnly (true);
    E8->setScrollbarsShown (false);
    E8->setCaretVisible (false);
    E8->setPopupMenuEnabled (false);
    E8->setColour (TextEditor::textColourId, Colours::black);
    E8->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E8->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E8->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E8->setText (TRANS("E"));

    addAndMakeVisible (*(A9 = std::make_unique<TextEditor> ("new text editor")));
    A9->setMultiLine (true);
    A9->setReturnKeyStartsNewLine (false);
    A9->setReadOnly (true);
    A9->setScrollbarsShown (false);
    A9->setCaretVisible (false);
    A9->setPopupMenuEnabled (false);
    A9->setColour (TextEditor::textColourId, Colours::black);
    A9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A9->setText (TRANS("A"));

    addAndMakeVisible (*(CS9 = std::make_unique<TextEditor> ("new text editor")));
    CS9->setMultiLine (true);
    CS9->setReturnKeyStartsNewLine (false);
    CS9->setReadOnly (true);
    CS9->setScrollbarsShown (false);
    CS9->setCaretVisible (false);
    CS9->setPopupMenuEnabled (false);
    CS9->setColour (TextEditor::textColourId, Colours::black);
    CS9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    CS9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    CS9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    CS9->setText (TRANS("C#"));

    addAndMakeVisible (*(GS10 = std::make_unique<TextEditor> ("new text editor")));
    GS10->setMultiLine (true);
    GS10->setReturnKeyStartsNewLine (false);
    GS10->setReadOnly (true);
    GS10->setScrollbarsShown (false);
    GS10->setCaretVisible (false);
    GS10->setPopupMenuEnabled (false);
    GS10->setColour (TextEditor::textColourId, Colours::black);
    GS10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    GS10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    GS10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    GS10->setText (TRANS("G#"));

    addAndMakeVisible (*(DS9 = std::make_unique<TextEditor> ("new text editor")));
    DS9->setMultiLine (true);
    DS9->setReturnKeyStartsNewLine (false);
    DS9->setReadOnly (true);
    DS9->setScrollbarsShown (false);
    DS9->setCaretVisible (false);
    DS9->setPopupMenuEnabled (false);
    DS9->setColour (TextEditor::textColourId, Colours::black);
    DS9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS9->setText (TRANS("D#"));

    addAndMakeVisible (*(AS9 = std::make_unique<TextEditor> ("new text editor")));
    AS9->setMultiLine (true);
    AS9->setReturnKeyStartsNewLine (false);
    AS9->setReadOnly (true);
    AS9->setScrollbarsShown (false);
    AS9->setCaretVisible (false);
    AS9->setPopupMenuEnabled (false);
    AS9->setColour (TextEditor::textColourId, Colours::black);
    AS9->setColour (TextEditor::backgroundColourId, Colour (0xffbd5c63));
    AS9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS9->setText (TRANS("A#"));

    addAndMakeVisible (*(F9 = std::make_unique<TextEditor> ("new text editor")));
    F9->setMultiLine (true);
    F9->setReturnKeyStartsNewLine (false);
    F9->setReadOnly (true);
    F9->setScrollbarsShown (false);
    F9->setCaretVisible (false);
    F9->setPopupMenuEnabled (false);
    F9->setColour (TextEditor::textColourId, Colours::black);
    F9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F9->setText (TRANS("F"));

    addAndMakeVisible (*(AS10 = std::make_unique<TextEditor> ("new text editor")));
    AS10->setMultiLine (true);
    AS10->setReturnKeyStartsNewLine (false);
    AS10->setReadOnly (true);
    AS10->setScrollbarsShown (false);
    AS10->setCaretVisible (false);
    AS10->setPopupMenuEnabled (false);
    AS10->setColour (TextEditor::textColourId, Colours::black);
    AS10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS10->setText (TRANS("A#"));

    addAndMakeVisible (*(D9 = std::make_unique<TextEditor> ("new text editor")));
    D9->setMultiLine (true);
    D9->setReturnKeyStartsNewLine (false);
    D9->setReadOnly (true);
    D9->setScrollbarsShown (false);
    D9->setCaretVisible (false);
    D9->setPopupMenuEnabled (false);
    D9->setColour (TextEditor::textColourId, Colours::black);
    D9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    D9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    D9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    D9->setText (TRANS("D"));

    addAndMakeVisible (*(A10 = std::make_unique<TextEditor> ("new text editor")));
    A10->setMultiLine (true);
    A10->setReturnKeyStartsNewLine (false);
    A10->setReadOnly (true);
    A10->setScrollbarsShown (false);
    A10->setCaretVisible (false);
    A10->setPopupMenuEnabled (false);
    A10->setColour (TextEditor::textColourId, Colours::black);
    A10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    A10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    A10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    A10->setText (TRANS("A"));

    addAndMakeVisible (*(E9 = std::make_unique<TextEditor> ("new text editor")));
    E9->setMultiLine (true);
    E9->setReturnKeyStartsNewLine (false);
    E9->setReadOnly (true);
    E9->setScrollbarsShown (false);
    E9->setCaretVisible (false);
    E9->setPopupMenuEnabled (false);
    E9->setColour (TextEditor::textColourId, Colours::black);
    E9->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    E9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    E9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    E9->setText (TRANS("E"));

    addAndMakeVisible (*(B9 = std::make_unique<TextEditor> ("new text editor")));
    B9->setMultiLine (true);
    B9->setReturnKeyStartsNewLine (false);
    B9->setReadOnly (true);
    B9->setScrollbarsShown (false);
    B9->setCaretVisible (false);
    B9->setPopupMenuEnabled (false);
    B9->setColour (TextEditor::textColourId, Colours::black);
    B9->setColour (TextEditor::backgroundColourId, Colour (0xffdf7b60));
    B9->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B9->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B9->setText (TRANS("B"));

    addAndMakeVisible (*(FS10 = std::make_unique<TextEditor> ("new text editor")));
    FS10->setMultiLine (true);
    FS10->setReturnKeyStartsNewLine (false);
    FS10->setReadOnly (true);
    FS10->setScrollbarsShown (false);
    FS10->setCaretVisible (false);
    FS10->setPopupMenuEnabled (false);
    FS10->setColour (TextEditor::textColourId, Colours::black);
    FS10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    FS10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    FS10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    FS10->setText (TRANS("F#"));

    addAndMakeVisible (*(B10 = std::make_unique<TextEditor> ("new text editor")));
    B10->setMultiLine (true);
    B10->setReturnKeyStartsNewLine (false);
    B10->setReadOnly (true);
    B10->setScrollbarsShown (false);
    B10->setCaretVisible (false);
    B10->setPopupMenuEnabled (false);
    B10->setColour (TextEditor::textColourId, Colours::black);
    B10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    B10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    B10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    B10->setText (TRANS("B"));

    addAndMakeVisible (*(DS10 = std::make_unique<TextEditor> ("new text editor")));
    DS10->setMultiLine (true);
    DS10->setReturnKeyStartsNewLine (false);
    DS10->setReadOnly (true);
    DS10->setScrollbarsShown (false);
    DS10->setCaretVisible (false);
    DS10->setPopupMenuEnabled (false);
    DS10->setColour (TextEditor::textColourId, Colours::black);
    DS10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    DS10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    DS10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    DS10->setText (TRANS("D#"));

    addAndMakeVisible (*(AS11 = std::make_unique<TextEditor> ("new text editor")));
    AS11->setMultiLine (true);
    AS11->setReturnKeyStartsNewLine (false);
    AS11->setReadOnly (true);
    AS11->setScrollbarsShown (false);
    AS11->setCaretVisible (false);
    AS11->setPopupMenuEnabled (false);
    AS11->setColour (TextEditor::textColourId, Colours::black);
    AS11->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    AS11->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    AS11->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    AS11->setText (TRANS("A#"));

    addAndMakeVisible (*(F10 = std::make_unique<TextEditor> ("new text editor")));
    F10->setMultiLine (true);
    F10->setReturnKeyStartsNewLine (false);
    F10->setReadOnly (true);
    F10->setScrollbarsShown (false);
    F10->setCaretVisible (false);
    F10->setPopupMenuEnabled (false);
    F10->setColour (TextEditor::textColourId, Colours::black);
    F10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    F10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    F10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    F10->setText (TRANS("F"));

    addAndMakeVisible (*(C10 = std::make_unique<TextEditor> ("new text editor")));
    C10->setMultiLine (true);
    C10->setReturnKeyStartsNewLine (false);
    C10->setReadOnly (true);
    C10->setScrollbarsShown (false);
    C10->setCaretVisible (false);
    C10->setPopupMenuEnabled (false);
    C10->setColour (TextEditor::textColourId, Colours::black);
    C10->setColour (TextEditor::backgroundColourId, Colour (0xfffecb5f));
    C10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C10->setText (TRANS("C"));

    addAndMakeVisible (*(G10 = std::make_unique<TextEditor> ("new text editor")));
    G10->setMultiLine (true);
    G10->setReturnKeyStartsNewLine (false);
    G10->setReadOnly (true);
    G10->setScrollbarsShown (false);
    G10->setCaretVisible (false);
    G10->setPopupMenuEnabled (false);
    G10->setColour (TextEditor::textColourId, Colours::black);
    G10->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    G10->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    G10->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    G10->setText (TRANS("G"));

    addAndMakeVisible (*(C11 = std::make_unique<TextEditor> ("new text editor")));
    C11->setMultiLine (true);
    C11->setReturnKeyStartsNewLine (false);
    C11->setReadOnly (true);
    C11->setScrollbarsShown (false);
    C11->setCaretVisible (false);
    C11->setPopupMenuEnabled (false);
    C11->setColour (TextEditor::textColourId, Colours::black);
    C11->setColour (TextEditor::backgroundColourId, Colour (0x49ab1e1e));
    C11->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
    C11->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
    C11->setText (TRANS("C"));

    cachedImage_gneck_inverted_png_1 = std::make_unique<Image>(ImageCache::getFromMemory (gneck_inverted_png, gneck_inverted_pngSize));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 600);


    //[Constructor] You can add your own custom stuff here..

	guitarnotes.push_back(std::move(C));
	guitarnotes.push_back(std::move(C2));
	guitarnotes.push_back(std::move(C3));
	guitarnotes.push_back(std::move(C4));
	guitarnotes.push_back(std::move(C5));
	guitarnotes.push_back(std::move(C6));
	guitarnotes.push_back(std::move(C7));
	guitarnotes.push_back(std::move(C8));
	guitarnotes.push_back(std::move(C9));
	guitarnotes.push_back(std::move(C10));
	guitarnotes.push_back(std::move(C11));

	guitarnotes.push_back(std::move(CS));
	guitarnotes.push_back(std::move(CS2));
	guitarnotes.push_back(std::move(CS3));
	guitarnotes.push_back(std::move(CS4));
	guitarnotes.push_back(std::move(CS5));
	guitarnotes.push_back(std::move(CS6));
	guitarnotes.push_back(std::move(CS7));
	guitarnotes.push_back(std::move(CS8));
	guitarnotes.push_back(std::move(CS9));

	guitarnotes.push_back(std::move(D));
	guitarnotes.push_back(std::move(D2));
	guitarnotes.push_back(std::move(D3));
	guitarnotes.push_back(std::move(D4));
	guitarnotes.push_back(std::move(D5));
	guitarnotes.push_back(std::move(D6));
	guitarnotes.push_back(std::move(D7));
	guitarnotes.push_back(std::move(D8));
	guitarnotes.push_back(std::move(D9));

	guitarnotes.push_back(std::move(DS));
	guitarnotes.push_back(std::move(DS2));
	guitarnotes.push_back(std::move(DS3));
	guitarnotes.push_back(std::move(DS4));
	guitarnotes.push_back(std::move(DS5));
	guitarnotes.push_back(std::move(DS6));
	guitarnotes.push_back(std::move(DS7));
	guitarnotes.push_back(std::move(DS8));
	guitarnotes.push_back(std::move(DS9));
	guitarnotes.push_back(std::move(DS10));

	guitarnotes.push_back(std::move(E));
	guitarnotes.push_back(std::move(E2));
	guitarnotes.push_back(std::move(E3));
	guitarnotes.push_back(std::move(E4));
	guitarnotes.push_back(std::move(E5));
	guitarnotes.push_back(std::move(E6));
	guitarnotes.push_back(std::move(E7));
	guitarnotes.push_back(std::move(E8));
	guitarnotes.push_back(std::move(E9));

	guitarnotes.push_back(std::move(F));
	guitarnotes.push_back(std::move(F1));
	guitarnotes.push_back(std::move(F2));
	guitarnotes.push_back(std::move(F3));
	guitarnotes.push_back(std::move(F4));
	guitarnotes.push_back(std::move(F5));
	guitarnotes.push_back(std::move(F6));
	guitarnotes.push_back(std::move(F7));
	guitarnotes.push_back(std::move(F8));
	guitarnotes.push_back(std::move(F9));
	guitarnotes.push_back(std::move(F10));


	guitarnotes.push_back(std::move(FS));
	guitarnotes.push_back(std::move(FS2));
	guitarnotes.push_back(std::move(FS3));
	guitarnotes.push_back(std::move(FS4));
	guitarnotes.push_back(std::move(FS5));
	guitarnotes.push_back(std::move(FS6));
	guitarnotes.push_back(std::move(FS7));
	guitarnotes.push_back(std::move(FS8));
	guitarnotes.push_back(std::move(FS9));
	guitarnotes.push_back(std::move(FS10));

	guitarnotes.push_back(std::move(G));
	guitarnotes.push_back(std::move(G2));
	guitarnotes.push_back(std::move(G3));
	guitarnotes.push_back(std::move(G4));
	guitarnotes.push_back(std::move(G5));
	guitarnotes.push_back(std::move(G6));
	guitarnotes.push_back(std::move(G7));
	guitarnotes.push_back(std::move(G8));
	guitarnotes.push_back(std::move(G9));
	guitarnotes.push_back(std::move(G10));

	guitarnotes.push_back(std::move(GS));
	guitarnotes.push_back(std::move(GS2));
	guitarnotes.push_back(std::move(GS3));
	guitarnotes.push_back(std::move(GS4));
	guitarnotes.push_back(std::move(GS5));
	guitarnotes.push_back(std::move(GS6));
	guitarnotes.push_back(std::move(GS7));
	guitarnotes.push_back(std::move(GS8));
	guitarnotes.push_back(std::move(GS9));
	guitarnotes.push_back(std::move(GS10));

	guitarnotes.push_back(std::move(A));
	guitarnotes.push_back(std::move(A2));
	guitarnotes.push_back(std::move(A3));
	guitarnotes.push_back(std::move(A4));
	guitarnotes.push_back(std::move(A5));
	guitarnotes.push_back(std::move(A6));
	guitarnotes.push_back(std::move(A7));
	guitarnotes.push_back(std::move(A8));
	guitarnotes.push_back(std::move(A9));
	guitarnotes.push_back(std::move(A10));

	guitarnotes.push_back(std::move(AS));
	guitarnotes.push_back(std::move(AS2));
	guitarnotes.push_back(std::move(AS3));
	guitarnotes.push_back(std::move(AS4));
	guitarnotes.push_back(std::move(AS5));
	guitarnotes.push_back(std::move(AS6));
	guitarnotes.push_back(std::move(AS7));
	guitarnotes.push_back(std::move(AS8));
	guitarnotes.push_back(std::move(AS9));
	guitarnotes.push_back(std::move(AS10));
	guitarnotes.push_back(std::move(AS11));

	guitarnotes.push_back(std::move(B));
	guitarnotes.push_back(std::move(B2));
	guitarnotes.push_back(std::move(B3));
	guitarnotes.push_back(std::move(B4));
	guitarnotes.push_back(std::move(B5));
	guitarnotes.push_back(std::move(B6));
	guitarnotes.push_back(std::move(B7));
	guitarnotes.push_back(std::move(B8));
	guitarnotes.push_back(std::move(B9));
	guitarnotes.push_back(std::move(B10));

	resetGuitarNotes();
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
    GS7 = nullptr;
    DS7 = nullptr;
    AS7 = nullptr;
    F6 = nullptr;
    C7 = nullptr;
    F7 = nullptr;
    A7 = nullptr;
    E7 = nullptr;
    B7 = nullptr;
    FS7 = nullptr;
    CS7 = nullptr;
    FS8 = nullptr;
    AS8 = nullptr;
    F8 = nullptr;
    C8 = nullptr;
    G7 = nullptr;
    D7 = nullptr;
    G8 = nullptr;
    B8 = nullptr;
    FS9 = nullptr;
    CS8 = nullptr;
    GS8 = nullptr;
    DS8 = nullptr;
    GS9 = nullptr;
    C9 = nullptr;
    G9 = nullptr;
    D8 = nullptr;
    A8 = nullptr;
    E8 = nullptr;
    A9 = nullptr;
    CS9 = nullptr;
    GS10 = nullptr;
    DS9 = nullptr;
    AS9 = nullptr;
    F9 = nullptr;
    AS10 = nullptr;
    D9 = nullptr;
    A10 = nullptr;
    E9 = nullptr;
    B9 = nullptr;
    FS10 = nullptr;
    B10 = nullptr;
    DS10 = nullptr;
    AS11 = nullptr;
    F10 = nullptr;
    C10 = nullptr;
    G10 = nullptr;
    C11 = nullptr;


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
        int x = 16, y = 328, width = 968, height = 212;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (*cachedImage_gneck_inverted_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_gneck_inverted_png_1->getWidth(), cachedImage_gneck_inverted_png_1->getHeight());
    }

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

    groupComponent->setBounds (8, 264, 985, 320);
    groupComponent4->setBounds (8, 136, 272, 128);
    groupComponent3->setBounds (288, 72, 704, 192);
    groupComponent2->setBounds (8, 8, 272, 128);
    scaleKey->setBounds (40, 200, 64, 24);
    comboBox2->setBounds (24, 288, 150, 24);
    scaleMode->setBounds (120, 200, 152, 24);
    chordRoot->setBounds (56, 56, 64, 24);
    chordType->setBounds (144, 56, 88, 24);
    textEditor2->setBounds (304, 96, 680, 160);
    txtScale->setBounds (32, 224, 224, 32);
    txtChord->setBounds (16, 90, 256, 32);
    GS4->setBounds (24, 400, 56, 24);
    DS3->setBounds (24, 440, 56, 24);
    AS2->setBounds (24, 480, 56, 24);
    F1->setBounds (24, 525, 56, 24);
    C5->setBounds (24, 360, 56, 24);
    F2->setBounds (24, 317, 56, 24);
    A4->setBounds (84, 400, 56, 24);
    E3->setBounds (84, 440, 56, 24);
    B2->setBounds (84, 480, 56, 24);
    FS->setBounds (84, 525, 56, 24);
    CS5->setBounds (84, 360, 56, 24);
    FS6->setBounds (84, 317, 56, 24);
    AS4->setBounds (145, 400, 52, 24);
    F->setBounds (145, 440, 52, 24);
    C2->setBounds (145, 480, 52, 24);
    G->setBounds (145, 525, 52, 24);
    D5->setBounds (145, 360, 52, 24);
    G6->setBounds (145, 317, 52, 24);
    B4->setBounds (202, 400, 52, 24);
    FS3->setBounds (202, 440, 52, 24);
    CS2->setBounds (202, 480, 52, 24);
    GS->setBounds (202, 525, 52, 24);
    DS5->setBounds (202, 360, 52, 24);
    GS6->setBounds (202, 317, 52, 24);
    C4->setBounds (257, 400, 52, 24);
    G3->setBounds (257, 440, 52, 24);
    D2->setBounds (257, 480, 52, 24);
    A->setBounds (257, 525, 52, 24);
    E5->setBounds (257, 360, 52, 24);
    A6->setBounds (257, 317, 52, 24);
    CS4->setBounds (312, 400, 51, 24);
    GS3->setBounds (312, 440, 51, 24);
    DS2->setBounds (312, 480, 51, 24);
    AS->setBounds (312, 525, 51, 24);
    F5->setBounds (312, 360, 51, 24);
    AS6->setBounds (312, 317, 51, 24);
    D4->setBounds (367, 400, 48, 24);
    A3->setBounds (367, 440, 48, 24);
    E2->setBounds (367, 480, 48, 24);
    B->setBounds (367, 525, 48, 24);
    FS5->setBounds (367, 360, 48, 24);
    B6->setBounds (367, 317, 48, 24);
    DS4->setBounds (420, 400, 46, 24);
    AS3->setBounds (420, 440, 46, 24);
    F3->setBounds (420, 480, 46, 24);
    C->setBounds (420, 525, 46, 24);
    G5->setBounds (420, 360, 46, 24);
    C6->setBounds (420, 317, 46, 24);
    E4->setBounds (471, 400, 44, 24);
    B3->setBounds (471, 440, 44, 24);
    FS2->setBounds (471, 480, 44, 24);
    CS->setBounds (471, 525, 44, 24);
    GS5->setBounds (471, 360, 44, 24);
    CS6->setBounds (471, 317, 44, 24);
    F4->setBounds (520, 400, 44, 24);
    C3->setBounds (520, 440, 44, 24);
    G2->setBounds (520, 480, 44, 24);
    D->setBounds (520, 525, 44, 24);
    A5->setBounds (520, 360, 44, 24);
    D6->setBounds (520, 317, 44, 24);
    FS4->setBounds (569, 400, 43, 24);
    CS3->setBounds (569, 440, 43, 24);
    GS2->setBounds (569, 480, 43, 24);
    DS->setBounds (569, 525, 43, 24);
    AS5->setBounds (569, 360, 43, 24);
    DS6->setBounds (569, 317, 43, 24);
    G4->setBounds (616, 400, 42, 24);
    D3->setBounds (616, 440, 42, 24);
    A2->setBounds (616, 480, 42, 24);
    E->setBounds (616, 525, 42, 24);
    B5->setBounds (616, 360, 42, 24);
    E6->setBounds (616, 317, 42, 24);
    GS7->setBounds (664, 400, 39, 24);
    DS7->setBounds (664, 440, 39, 24);
    AS7->setBounds (664, 480, 39, 24);
    F6->setBounds (664, 525, 39, 24);
    C7->setBounds (664, 360, 39, 24);
    F7->setBounds (664, 317, 39, 24);
    A7->setBounds (708, 400, 38, 24);
    E7->setBounds (708, 440, 38, 24);
    B7->setBounds (708, 480, 38, 24);
    FS7->setBounds (708, 525, 38, 24);
    CS7->setBounds (708, 360, 38, 24);
    FS8->setBounds (708, 317, 38, 24);
    AS8->setBounds (751, 400, 36, 24);
    F8->setBounds (751, 440, 36, 24);
    C8->setBounds (751, 480, 36, 24);
    G7->setBounds (751, 525, 36, 24);
    D7->setBounds (751, 360, 36, 24);
    G8->setBounds (751, 317, 36, 24);
    B8->setBounds (792, 400, 36, 24);
    FS9->setBounds (792, 440, 36, 24);
    CS8->setBounds (792, 480, 36, 24);
    GS8->setBounds (792, 525, 36, 24);
    DS8->setBounds (792, 360, 36, 24);
    GS9->setBounds (792, 317, 36, 24);
    C9->setBounds (834, 400, 34, 24);
    G9->setBounds (834, 440, 34, 24);
    D8->setBounds (834, 480, 34, 24);
    A8->setBounds (834, 525, 34, 24);
    E8->setBounds (834, 360, 34, 24);
    A9->setBounds (834, 317, 34, 24);
    CS9->setBounds (873, 400, 32, 24);
    GS10->setBounds (873, 440, 32, 24);
    DS9->setBounds (873, 480, 32, 24);
    AS9->setBounds (873, 525, 32, 24);
    F9->setBounds (873, 360, 32, 24);
    AS10->setBounds (873, 317, 32, 24);
    D9->setBounds (911, 400, 32, 24);
    A10->setBounds (911, 440, 32, 24);
    E9->setBounds (911, 480, 32, 24);
    B9->setBounds (911, 525, 32, 24);
    FS10->setBounds (911, 360, 32, 24);
    B10->setBounds (911, 317, 32, 24);
    DS10->setBounds (949, 400, 30, 24);
    AS11->setBounds (949, 440, 30, 24);
    F10->setBounds (949, 480, 30, 24);
    C10->setBounds (949, 525, 30, 24);
    G10->setBounds (949, 360, 30, 24);
    C11->setBounds (949, 317, 30, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == scaleKey.get())
    {
        //[UserComboBoxCode_scaleKey] -- add your combo box handling code here..

		std::string scalekeystr = scaleKey->getText().toStdString();
		root = scalekeystr[0];
		char scalekeychar = scalekeystr[0];

		int offset = 0;
		if (scalekeystr[1] != '\0') {
			offset = 1;
			root += "#";
		}

		scaleroot = Note{ scalekeychar, offset,4 };
		updateScale();

        //[/UserComboBoxCode_scaleKey]
    }
    else if (comboBoxThatHasChanged == comboBox2.get())
    {
        //[UserComboBoxCode_comboBox2] -- add your combo box handling code here..
		if (comboBox2->getText() == "Scales") {
			// Show only notes that are in the chosen scale
			updateGuitarNeckScales();
		}
		else if (comboBox2->getText() == "Chords") {
			// Show only notes that are in the chosen chords
			updateGuitarNeckChords();
		}

		else if (comboBox2->getText() == "Notes") {
			// Show all notes
			resetGuitarNotes();
		}
        //[/UserComboBoxCode_comboBox2]
    }
    else if (comboBoxThatHasChanged == scaleMode.get())
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
    else if (comboBoxThatHasChanged == chordRoot.get())
    {
        //[UserComboBoxCode_chordRoot] -- add your combo box handling code here..
		std::string chordkeystr = chordRoot->getText().toStdString();
		char chordkeychar = chordkeystr[0];

		int offset = 0;
		if (chordkeystr[1] != '\0') {
			offset = 1;
		}

		chordroot = Note{ chordkeychar, offset,4 };
		updateChord();
        //[/UserComboBoxCode_chordRoot]
    }
    else if (comboBoxThatHasChanged == chordType.get())
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

	if (comboBox2->getText() == "Scales") {
		updateGuitarNeckScales();
	}
}

void PluginEditor::updateChord() {
	std::ostringstream stream;
	stream << Chord(chordroot, chordtype) << std::endl;
	std::string chordstr = stream.str();
	juce::String jchordstr = simplifyNotes(chordstr);
    txtChord->setText(jchordstr);
    
	if (comboBox2->getText() == "Chords") {
		updateGuitarNeckChords();
	}
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


void PluginEditor::updateGuitarNeckScales() {
	resetGuitarNotes();
	for (int i = 0; i < guitarnotes.size(); ++i) {
		guitarnotes.at(i)->setAlpha(0.7);
		if (!(txtScale->getText().contains(guitarnotes.at(i)->getText() + " "))) {
			guitarnotes.at(i)->setVisible(false);
		}
		if (txtScale->getText().getLastCharacters(3).trim() == guitarnotes.at(i)->getText()) {
			guitarnotes.at(i)->setVisible(true);
		}

		// Make root note distinct
		if (guitarnotes.at(i)->getText() == String(root.c_str())) {
			guitarnotes.at(i)->setAlpha(1);
		}
	}
}

void PluginEditor::updateGuitarNeckChords() {
    resetGuitarNotes();
    for (int i = 0; i < guitarnotes.size(); ++i) {
        guitarnotes.at(i)->setAlpha(0.7);
        if (!(txtChord->getText().contains(guitarnotes.at(i)->getText() + " "))) {
            guitarnotes.at(i)->setVisible(false);
        }
        if (txtChord->getText().getLastCharacters(3).trim() == guitarnotes.at(i)->getText()) {
            guitarnotes.at(i)->setVisible(true);
        }

   		// Make root note distinct
        if (guitarnotes.at(i)->getText() == chordRoot->getText()) {
            guitarnotes.at(i)->setAlpha(1);
        }
    }
}

void PluginEditor::resetGuitarNotes() {
	for (int i = 0; i < guitarnotes.size(); ++i) {
		guitarnotes.at(i)->setAlpha(1);
		guitarnotes.at(i)->setVisible(true);

		if (guitarnotes.at(i)->getText() == "F") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorF);
		}
		else if (guitarnotes.at(i)->getText() == "F#") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorFs);
		}
		else if (guitarnotes.at(i)->getText() == "G") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorG);
		}
		else if (guitarnotes.at(i)->getText() == "G#") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorGs);
		}
		else if (guitarnotes.at(i)->getText() == "A") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorA);
		}
		else if (guitarnotes.at(i)->getText() == "A#") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorAs);
		}
		else if (guitarnotes.at(i)->getText() == "B") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorB);
		}
		else if (guitarnotes.at(i)->getText() == "C") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorC);
		}
		else if (guitarnotes.at(i)->getText() == "C#") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorCs);
		}
		else if (guitarnotes.at(i)->getText() == "D") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorD);
		}
		else if (guitarnotes.at(i)->getText() == "D#") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorDs);
		}
		else if (guitarnotes.at(i)->getText() == "E") {
			guitarnotes.at(i)->setColour(TextEditor::backgroundColourId, colorE);
		}
	}
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
    <IMAGE pos="16 328 968 212" resource="gneck_inverted_png" opacity="1"
           mode="0"/>
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
                  virtualName="" explicitFocusOrder="0" pos="8 264 985 320" outlinecol="ff7fffd4"
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
              bkgcol="ff4d91a9" outlinecol="522d2d" shadowcol="c12323" initialText="F"
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
              virtualName="" explicitFocusOrder="0" pos="84 400 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="48d1d426ce401fa7" memberName="E3"
              virtualName="" explicitFocusOrder="0" pos="84 440 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="85bf0d6659d292cf" memberName="B2"
              virtualName="" explicitFocusOrder="0" pos="84 480 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="248c44bfea1f4b03" memberName="FS"
              virtualName="" explicitFocusOrder="0" pos="84 525 56 24" textcol="ff000000"
              bkgcol="ff5681ab" outlinecol="522d2d" shadowcol="c12323" initialText="&#10;F#&#10;"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9e3372e35d461be6" memberName="CS5"
              virtualName="" explicitFocusOrder="0" pos="84 360 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1446fd17a02ce952" memberName="FS6"
              virtualName="" explicitFocusOrder="0" pos="84 317 56 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d6412f64c5d61ed9" memberName="AS4"
              virtualName="" explicitFocusOrder="0" pos="145 400 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="6b6a95ce76a43e78" memberName="F" virtualName=""
              explicitFocusOrder="0" pos="145 440 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="845fa63053d672b7" memberName="C2"
              virtualName="" explicitFocusOrder="0" pos="145 480 52 24" textcol="ff000000"
              bkgcol="d4ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="51298939a8a19acd" memberName="G" virtualName=""
              explicitFocusOrder="0" pos="145 525 52 24" textcol="ff000000"
              bkgcol="ff706ea1" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="7a2cca9782229d3c" memberName="D5"
              virtualName="" explicitFocusOrder="0" pos="145 360 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3b60e4e31b65c698" memberName="G6"
              virtualName="" explicitFocusOrder="0" pos="145 317 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f2d240f22b9509ad" memberName="B4"
              virtualName="" explicitFocusOrder="0" pos="202 400 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="db1be30023af9b5d" memberName="FS3"
              virtualName="" explicitFocusOrder="0" pos="202 440 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="b2f7b9627635e43e" memberName="CS2"
              virtualName="" explicitFocusOrder="0" pos="202 480 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3c29dcee22064d9f" memberName="GS"
              virtualName="" explicitFocusOrder="0" pos="202 525 52 24" textcol="ff000000"
              bkgcol="ff885887" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="fe43304bd428c553" memberName="DS5"
              virtualName="" explicitFocusOrder="0" pos="202 360 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="63533c6138e94925" memberName="GS6"
              virtualName="" explicitFocusOrder="0" pos="202 317 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2a65236799f11be3" memberName="C4"
              virtualName="" explicitFocusOrder="0" pos="257 400 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="bef9f3ce5b8183c3" memberName="G3"
              virtualName="" explicitFocusOrder="0" pos="257 440 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="541ba0a7b0dcda21" memberName="D2"
              virtualName="" explicitFocusOrder="0" pos="257 480 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="709c3ff69cde455a" memberName="A" virtualName=""
              explicitFocusOrder="0" pos="257 525 52 24" textcol="ff000000"
              bkgcol="ff934561" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f4c7f8a29ae2686d" memberName="E5"
              virtualName="" explicitFocusOrder="0" pos="257 360 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9e062d3865c3a6d6" memberName="A6"
              virtualName="" explicitFocusOrder="0" pos="257 317 52 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="afb5bca316e5cc6e" memberName="CS4"
              virtualName="" explicitFocusOrder="0" pos="312 400 51 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="678d85789080f749" memberName="GS3"
              virtualName="" explicitFocusOrder="0" pos="312 440 51 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="13f02da8033a15fa" memberName="DS2"
              virtualName="" explicitFocusOrder="0" pos="312 480 51 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="17541f8aa0e0c16f" memberName="AS"
              virtualName="" explicitFocusOrder="0" pos="312 525 51 24" textcol="ff000000"
              bkgcol="ffbd5c63" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d34dddb5bda2afc8" memberName="F5"
              virtualName="" explicitFocusOrder="0" pos="312 360 51 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9541c70a1c430578" memberName="AS6"
              virtualName="" explicitFocusOrder="0" pos="312 317 51 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="36d89d85d2491463" memberName="D4"
              virtualName="" explicitFocusOrder="0" pos="367 400 48 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f56d4450a66f4d65" memberName="A3"
              virtualName="" explicitFocusOrder="0" pos="367 440 48 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="be86533ab2c0f36e" memberName="E2"
              virtualName="" explicitFocusOrder="0" pos="367 480 48 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2298f80f641b190d" memberName="B" virtualName=""
              explicitFocusOrder="0" pos="367 525 48 24" textcol="ff000000"
              bkgcol="ffdf7b60" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a50cf62188f318cc" memberName="FS5"
              virtualName="" explicitFocusOrder="0" pos="367 360 48 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c5aa0440900f2b14" memberName="B6"
              virtualName="" explicitFocusOrder="0" pos="367 317 48 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="8b11edbbb6b93a3d" memberName="DS4"
              virtualName="" explicitFocusOrder="0" pos="420 400 46 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="35663d800eb06fe" memberName="AS3"
              virtualName="" explicitFocusOrder="0" pos="420 440 46 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="82bdd472cd349cf9" memberName="F3"
              virtualName="" explicitFocusOrder="0" pos="420 480 46 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="49bda9d59f9250c9" memberName="C" virtualName=""
              explicitFocusOrder="0" pos="420 525 46 24" textcol="ff000000"
              bkgcol="fffecb5f" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d2a1e2d6e4ec8efc" memberName="G5"
              virtualName="" explicitFocusOrder="0" pos="420 360 46 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ad744b27041092fe" memberName="C6"
              virtualName="" explicitFocusOrder="0" pos="420 317 46 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="527437bcdc447b1d" memberName="E4"
              virtualName="" explicitFocusOrder="0" pos="471 400 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ce62bba04be5dd5b" memberName="B3"
              virtualName="" explicitFocusOrder="0" pos="471 440 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f652d10509ebe94b" memberName="FS2"
              virtualName="" explicitFocusOrder="0" pos="471 480 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e0f6882bcc88dd0b" memberName="CS"
              virtualName="" explicitFocusOrder="0" pos="471 525 44 24" textcol="ff000000"
              bkgcol="ffc1be4f" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="683dc1af36244b1c" memberName="GS5"
              virtualName="" explicitFocusOrder="0" pos="471 360 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9f5df1efa442c0c3" memberName="CS6"
              virtualName="" explicitFocusOrder="0" pos="471 317 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="aec7cefcf70eec10" memberName="F4"
              virtualName="" explicitFocusOrder="0" pos="520 400 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="5aecebb3ce5a6274" memberName="C3"
              virtualName="" explicitFocusOrder="0" pos="520 440 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="cdc65c06f224bb35" memberName="G2"
              virtualName="" explicitFocusOrder="0" pos="520 480 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="37bc7174c5d9f43b" memberName="D" virtualName=""
              explicitFocusOrder="0" pos="520 525 44 24" textcol="ff000000"
              bkgcol="ff86af4d" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="711cb79dd815b051" memberName="A5"
              virtualName="" explicitFocusOrder="0" pos="520 360 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a9fa6acc8204956f" memberName="D6"
              virtualName="" explicitFocusOrder="0" pos="520 317 44 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="eaaa77e97e97c2dc" memberName="FS4"
              virtualName="" explicitFocusOrder="0" pos="569 400 43 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a7db4ff38469c8c2" memberName="CS3"
              virtualName="" explicitFocusOrder="0" pos="569 440 43 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2648f4d1b0918a9d" memberName="GS2"
              virtualName="" explicitFocusOrder="0" pos="569 480 43 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e0a2f56fdc20e35b" memberName="DS"
              virtualName="" explicitFocusOrder="0" pos="569 525 43 24" textcol="ff000000"
              bkgcol="ff499b53" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ab71d96f3affec99" memberName="AS5"
              virtualName="" explicitFocusOrder="0" pos="569 360 43 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f202c01a1c02b479" memberName="DS6"
              virtualName="" explicitFocusOrder="0" pos="569 317 43 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="7e5131977f911f5b" memberName="G4"
              virtualName="" explicitFocusOrder="0" pos="616 400 42 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1b61964a64e39cd7" memberName="D3"
              virtualName="" explicitFocusOrder="0" pos="616 440 42 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9d98dce091c93330" memberName="A2"
              virtualName="" explicitFocusOrder="0" pos="616 480 42 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c976fc24f6659c21" memberName="E" virtualName=""
              explicitFocusOrder="0" pos="616 525 42 24" textcol="ff000000"
              bkgcol="ff007062" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="78566031c387cffd" memberName="B5"
              virtualName="" explicitFocusOrder="0" pos="616 360 42 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="5f4415d59eaada7f" memberName="E6"
              virtualName="" explicitFocusOrder="0" pos="616 317 42 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="6a4e8ecf68a67b8f" memberName="GS7"
              virtualName="" explicitFocusOrder="0" pos="664 400 39 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="e76aab8d5c26d98c" memberName="DS7"
              virtualName="" explicitFocusOrder="0" pos="664 440 39 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ca01491146053d39" memberName="AS7"
              virtualName="" explicitFocusOrder="0" pos="664 480 39 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f804716a51416b47" memberName="F6"
              virtualName="" explicitFocusOrder="0" pos="664 525 39 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="39cd5f30a8579f6e" memberName="C7"
              virtualName="" explicitFocusOrder="0" pos="664 360 39 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="8b2ae6fc1aa6bb19" memberName="F7"
              virtualName="" explicitFocusOrder="0" pos="664 317 39 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="813bc65bf4cc13b1" memberName="A7"
              virtualName="" explicitFocusOrder="0" pos="708 400 38 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c751671410e9b16d" memberName="E7"
              virtualName="" explicitFocusOrder="0" pos="708 440 38 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f76cba3b6e845220" memberName="B7"
              virtualName="" explicitFocusOrder="0" pos="708 480 38 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3be7532decf1ec47" memberName="FS7"
              virtualName="" explicitFocusOrder="0" pos="708 525 38 24" textcol="ff000000"
              bkgcol="ff5681ab" outlinecol="522d2d" shadowcol="c12323" initialText="&#10;F#&#10;"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="fa7344c71665a69d" memberName="CS7"
              virtualName="" explicitFocusOrder="0" pos="708 360 38 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="4f1b58bd90216f08" memberName="FS8"
              virtualName="" explicitFocusOrder="0" pos="708 317 38 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="2fc9142567c7d22f" memberName="AS8"
              virtualName="" explicitFocusOrder="0" pos="751 400 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c2ad20cbf7074689" memberName="F8"
              virtualName="" explicitFocusOrder="0" pos="751 440 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d265f4ad8ef157c2" memberName="C8"
              virtualName="" explicitFocusOrder="0" pos="751 480 36 24" textcol="ff000000"
              bkgcol="d4ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="5905c54918f4638a" memberName="G7"
              virtualName="" explicitFocusOrder="0" pos="751 525 36 24" textcol="ff000000"
              bkgcol="ff706ea1" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="6734dca45d7272a5" memberName="D7"
              virtualName="" explicitFocusOrder="0" pos="751 360 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="deacafc969b4dd68" memberName="G8"
              virtualName="" explicitFocusOrder="0" pos="751 317 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1a3233b14b075b02" memberName="B8"
              virtualName="" explicitFocusOrder="0" pos="792 400 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="760083f33f8090fa" memberName="FS9"
              virtualName="" explicitFocusOrder="0" pos="792 440 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="25dc2468cff9a323" memberName="CS8"
              virtualName="" explicitFocusOrder="0" pos="792 480 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="b49227e3554e39fa" memberName="GS8"
              virtualName="" explicitFocusOrder="0" pos="792 525 36 24" textcol="ff000000"
              bkgcol="ff885887" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="69770d0e9306bae" memberName="DS8"
              virtualName="" explicitFocusOrder="0" pos="792 360 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="630a74800b89eed0" memberName="GS9"
              virtualName="" explicitFocusOrder="0" pos="792 317 36 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="ef3a7c27764f4c60" memberName="C9"
              virtualName="" explicitFocusOrder="0" pos="834 400 34 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c63ff8a25a654b15" memberName="G9"
              virtualName="" explicitFocusOrder="0" pos="834 440 34 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="fce36c5d506942a0" memberName="D8"
              virtualName="" explicitFocusOrder="0" pos="834 480 34 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="276b467bf37aaf95" memberName="A8"
              virtualName="" explicitFocusOrder="0" pos="834 525 34 24" textcol="ff000000"
              bkgcol="ff934561" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="346cf5aa5e8328b3" memberName="E8"
              virtualName="" explicitFocusOrder="0" pos="834 360 34 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a7fd9daa59e61cf1" memberName="A9"
              virtualName="" explicitFocusOrder="0" pos="834 317 34 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="f50004115de09a61" memberName="CS9"
              virtualName="" explicitFocusOrder="0" pos="873 400 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="b343afe4af32edd8" memberName="GS10"
              virtualName="" explicitFocusOrder="0" pos="873 440 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="c624556af48185b1" memberName="DS9"
              virtualName="" explicitFocusOrder="0" pos="873 480 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="bb127f86d163652f" memberName="AS9"
              virtualName="" explicitFocusOrder="0" pos="873 525 32 24" textcol="ff000000"
              bkgcol="ffbd5c63" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="3698e08d1bd3a134" memberName="F9"
              virtualName="" explicitFocusOrder="0" pos="873 360 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="49687131b28c55c9" memberName="AS10"
              virtualName="" explicitFocusOrder="0" pos="873 317 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a3735da997fc7382" memberName="D9"
              virtualName="" explicitFocusOrder="0" pos="911 400 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="81e3046a31ae1f3b" memberName="A10"
              virtualName="" explicitFocusOrder="0" pos="911 440 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="df21a3524a6a8415" memberName="E9"
              virtualName="" explicitFocusOrder="0" pos="911 480 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="E"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="9b85bd427f4c501c" memberName="B9"
              virtualName="" explicitFocusOrder="0" pos="911 525 32 24" textcol="ff000000"
              bkgcol="ffdf7b60" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a7b339ce729013f4" memberName="FS10"
              virtualName="" explicitFocusOrder="0" pos="911 360 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="100c0673289ac95" memberName="B10"
              virtualName="" explicitFocusOrder="0" pos="911 317 32 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="B"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="b74717f7ff7f84a8" memberName="DS10"
              virtualName="" explicitFocusOrder="0" pos="949 400 30 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="D#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1c3f6bbaeaee26a2" memberName="AS11"
              virtualName="" explicitFocusOrder="0" pos="949 440 30 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="A#"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="d304d2073a4648d8" memberName="F10"
              virtualName="" explicitFocusOrder="0" pos="949 480 30 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="F"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="a347f501b552d8d2" memberName="C10"
              virtualName="" explicitFocusOrder="0" pos="949 525 30 24" textcol="ff000000"
              bkgcol="fffecb5f" outlinecol="522d2d" shadowcol="c12323" initialText="C"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="1461e3a30095cada" memberName="G10"
              virtualName="" explicitFocusOrder="0" pos="949 360 30 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="G"
              multiline="0" retKeyStartsLine="0" readonly="1" scrollbars="0"
              caret="0" popupmenu="0"/>
  <TEXTEDITOR name="new text editor" id="8a36f1d76d71d77b" memberName="C11"
              virtualName="" explicitFocusOrder="0" pos="949 317 30 24" textcol="ff000000"
              bkgcol="49ab1e1e" outlinecol="522d2d" shadowcol="c12323" initialText="C"
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

// JUCER_RESOURCE: gneck_inverted_png, 5025, "gneck_inverted.png"
static const unsigned char resource_PluginEditor_gneck_inverted_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,4,78,0,0,0,124,8,6,0,0,0,119,193,245,57,0,0,0,1,115,82,71,66,0,174,206,28,233,
0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,0,9,112,72,89,115,0,0,14,196,0,0,14,196,1,149,43,14,27,0,0,19,54,73,68,65,84,120,94,237,221,103,111,220,86,214,0,96,202,170,86,183,157,168,88,187,73,212,
255,255,207,17,176,95,22,218,68,205,150,100,91,189,190,57,226,245,59,147,241,16,145,139,20,94,242,121,0,33,60,131,0,230,37,207,45,60,67,14,7,54,55,55,239,11,0,0,0,0,190,240,168,194,201,245,245,117,113,
119,119,151,162,246,25,29,29,77,91,29,55,55,55,197,237,237,109,138,218,99,96,96,160,24,25,25,73,81,233,254,254,254,225,120,180,41,71,6,7,7,139,161,161,161,20,117,92,94,94,166,173,102,107,115,30,188,120,
241,162,24,30,30,78,81,169,233,109,111,91,190,183,101,204,111,122,59,99,156,138,188,141,62,219,173,41,107,154,24,135,122,219,22,231,46,206,97,206,226,156,197,152,211,45,231,118,53,105,190,172,234,83,185,
141,27,253,114,44,206,69,140,13,117,215,111,62,142,125,143,115,16,121,85,87,57,238,119,110,125,55,167,57,33,135,245,71,191,156,125,84,225,100,111,111,175,184,184,184,72,81,251,252,250,235,175,105,171,
227,253,251,247,197,201,201,73,138,218,35,58,228,191,255,253,239,20,149,34,209,227,120,180,41,71,166,166,166,138,215,175,95,167,168,227,191,255,253,111,218,106,182,24,72,150,150,150,82,84,138,5,199,225,
225,97,227,243,32,38,166,183,111,223,166,168,20,109,143,62,208,212,66,194,228,228,100,241,230,205,155,20,117,52,53,223,219,50,230,199,88,222,187,200,58,58,58,42,62,126,252,152,162,188,69,95,141,188,237,
93,160,53,101,77,51,55,55,87,188,124,249,50,69,165,79,159,62,61,140,195,57,139,115,22,99,78,183,232,123,209,7,115,20,23,95,191,252,242,75,138,74,113,113,16,237,57,63,63,79,159,228,33,230,254,56,63,99,
99,99,233,147,210,187,119,239,138,211,211,211,20,213,95,172,223,98,29,215,45,246,63,218,81,119,253,230,227,200,163,200,167,58,23,175,114,220,239,170,181,110,236,115,29,215,123,63,253,244,83,49,49,49,145,
162,82,93,231,132,28,214,31,113,44,35,103,99,12,255,236,81,133,147,237,237,237,226,236,236,44,69,237,243,231,49,74,91,29,177,240,58,62,62,78,81,123,68,146,175,175,175,167,168,20,133,147,221,221,221,172,
38,205,239,53,59,59,91,204,207,207,167,168,99,107,107,43,109,53,91,76,38,171,171,171,41,42,93,93,93,61,228,65,110,11,193,175,21,223,62,44,47,47,167,168,20,19,104,180,189,169,69,163,153,153,153,98,97,97,
33,69,29,77,205,247,126,99,126,156,223,15,31,62,164,168,25,214,214,214,190,248,214,245,224,224,32,251,11,239,207,162,175,46,46,46,126,113,145,215,148,53,77,44,232,123,11,12,177,240,220,223,223,79,81,158,
98,110,141,57,182,91,244,189,232,131,57,138,69,247,198,198,70,138,74,185,174,155,98,238,143,62,53,62,62,158,62,41,237,236,236,100,85,112,237,151,99,177,255,209,142,186,235,55,31,71,30,69,62,213,241,206,
130,207,114,220,239,40,190,175,172,172,164,168,84,231,181,110,244,205,233,233,233,20,149,226,90,53,174,89,235,38,135,245,71,28,203,200,217,238,194,201,95,75,61,0,0,0,0,252,63,133,19,0,0,0,128,10,10,39,
0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,
1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,6,54,55,55,239,211,118,165,119,239,222,21,151,151,151,41,106,159,165,165,165,180,213,113,116,
116,84,156,157,157,165,168,61,6,6,6,138,183,111,223,166,168,116,123,123,251,112,60,218,148,35,19,19,19,197,236,236,108,138,58,126,255,253,247,180,213,108,131,131,131,197,194,194,66,138,74,55,55,55,15,
121,112,117,117,149,62,105,166,161,161,161,98,126,126,62,69,165,235,235,235,135,182,199,127,155,104,124,124,188,120,245,234,85,138,58,154,154,239,109,25,243,23,23,23,139,23,47,254,250,253,201,135,15,31,
138,147,147,147,20,229,45,250,106,228,237,200,200,72,250,164,212,148,53,205,155,55,111,138,177,177,177,20,149,226,220,197,57,204,89,204,173,49,199,118,59,61,61,45,142,143,143,83,148,151,38,173,155,98,
238,143,62,53,58,58,154,62,41,229,54,62,246,203,177,243,243,243,226,240,240,48,69,245,213,111,62,190,184,184,120,56,7,119,119,119,233,147,250,169,218,239,232,215,209,31,234,168,223,122,175,206,107,221,
56,190,113,156,187,213,117,236,204,97,253,17,199,50,198,138,24,195,63,123,84,225,36,58,226,253,253,223,254,111,141,21,19,69,175,54,31,19,199,163,92,8,245,118,248,80,215,193,255,41,180,57,15,122,219,30,
109,254,252,215,68,109,203,247,182,228,118,27,218,25,121,219,189,232,9,77,105,99,191,182,69,187,162,125,57,107,98,187,154,212,215,154,208,167,114,206,177,216,239,216,255,110,57,236,123,174,251,157,83,
223,205,41,175,115,56,174,253,114,246,81,133,19,0,0,0,128,54,122,84,225,36,110,95,107,211,55,233,189,38,39,39,211,86,71,220,94,22,183,107,181,81,239,241,136,234,96,28,143,54,229,200,240,240,240,23,183,
170,134,166,220,226,254,119,162,10,219,123,155,107,84,138,227,182,227,166,231,65,84,159,123,111,133,140,182,71,31,168,99,85,255,71,136,219,85,123,31,9,8,77,205,247,182,140,249,209,135,123,191,157,138,
62,220,148,71,206,162,175,198,56,221,251,205,86,83,214,52,209,39,163,111,118,139,115,151,251,99,72,113,206,98,142,237,150,123,187,154,178,110,138,241,34,242,174,183,79,229,54,62,246,203,177,216,255,104,
71,221,245,155,143,99,223,163,127,212,241,46,136,207,250,237,119,228,127,28,243,186,238,119,213,90,55,246,185,142,235,189,156,230,132,28,214,31,253,114,246,81,133,147,237,237,237,86,254,158,199,103,127,
30,163,180,213,177,183,183,151,237,243,182,223,35,22,162,235,235,235,41,42,197,128,189,187,187,251,240,28,93,91,196,51,111,189,207,61,134,173,173,173,180,213,108,49,152,172,174,174,166,168,20,207,123,
70,30,196,69,73,147,197,239,37,44,47,47,167,168,20,131,125,180,61,135,69,215,183,152,153,153,249,226,55,109,66,83,243,189,223,152,31,231,55,247,223,142,232,181,182,182,246,197,5,208,193,193,65,22,207,
249,63,70,244,213,120,142,186,119,225,211,148,53,77,252,22,79,239,5,121,60,123,191,191,191,159,162,60,197,220,218,251,27,98,209,247,162,15,230,40,46,14,54,54,54,82,84,202,117,221,20,115,127,244,169,222,
47,15,118,118,118,138,143,31,63,166,168,254,250,229,88,236,127,180,163,238,250,205,199,145,71,145,79,117,46,94,229,184,223,81,92,91,89,89,73,81,169,206,107,221,232,155,211,211,211,41,42,197,181,106,92,
179,214,77,14,235,143,56,150,145,179,221,5,158,47,31,90,7,0,0,0,224,129,194,9,0,0,141,16,223,14,62,199,31,0,237,162,112,2,0,64,246,226,214,234,185,185,185,103,249,235,125,4,12,128,102,83,56,1,0,32,123,
241,163,159,83,83,83,207,242,215,251,227,162,0,52,155,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,
194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,144,189,79,159,62,21,251,251,251,207,242,119,113,113,145,254,85,0,218,64,225,4,0,128,236,69,49,227,227,199,143,207,242,
119,125,125,157,254,85,0,218,64,225,4,0,0,0,160,194,192,230,230,230,125,218,174,244,254,253,251,226,242,242,50,69,237,243,246,237,219,180,213,241,225,195,135,226,244,244,52,69,237,49,48,48,80,44,46,46,
166,168,116,123,123,91,28,31,31,183,42,71,38,38,38,138,153,153,153,20,117,252,241,199,31,105,171,217,6,7,7,139,249,249,249,20,149,110,110,110,30,242,224,234,234,42,125,210,76,67,67,67,197,220,220,92,138,
74,77,111,251,248,248,120,49,59,59,155,162,142,166,230,123,191,49,63,206,239,217,217,89,138,154,97,97,97,161,120,241,226,175,223,159,196,55,233,39,39,39,41,202,91,244,213,200,219,145,145,145,244,73,169,
41,107,154,215,175,95,23,99,99,99,41,42,197,186,36,214,39,57,139,115,22,99,78,183,232,123,209,7,115,212,164,117,83,204,253,113,126,70,71,71,211,39,165,163,163,163,226,252,252,60,69,245,23,235,183,88,199,
117,139,253,143,118,212,93,191,249,56,242,40,242,41,242,170,174,114,220,239,220,214,123,175,94,189,42,94,190,124,153,162,82,93,199,206,28,214,31,253,114,246,81,133,19,0,0,0,128,54,242,168,14,0,0,0,64,
133,71,221,113,114,119,119,151,182,218,169,247,86,162,112,127,127,255,240,215,70,253,142,71,219,114,36,110,189,141,191,94,109,58,14,109,206,131,182,181,189,109,249,222,150,49,191,13,237,108,114,95,237,
215,47,155,112,254,154,216,174,38,229,97,191,243,147,91,91,114,206,177,92,247,61,215,253,206,169,239,230,116,140,115,88,127,244,59,158,143,42,156,108,111,111,55,238,217,238,175,241,231,49,74,91,29,123,
123,123,181,124,102,236,169,69,162,175,175,175,167,168,20,207,251,237,238,238,182,234,55,95,226,153,183,222,223,248,8,91,91,91,105,171,217,226,185,207,213,213,213,20,149,226,121,207,200,131,156,158,115,
254,22,241,123,9,203,203,203,41,42,197,115,186,209,246,166,190,158,50,158,7,143,231,81,123,53,53,223,251,141,249,113,126,115,255,237,136,94,107,107,107,15,191,89,208,237,224,224,160,56,60,60,76,81,222,
162,175,198,111,75,244,254,14,72,83,214,52,75,75,75,197,228,228,100,138,74,241,27,13,241,170,220,156,197,220,218,251,92,121,244,189,232,131,57,138,133,247,198,198,70,138,74,185,174,155,98,238,143,62,213,
251,27,52,59,59,59,15,191,79,144,139,126,57,22,251,31,237,168,187,126,243,113,228,81,228,83,228,85,93,229,184,223,195,195,195,197,202,202,74,138,74,117,94,235,70,223,156,158,158,78,81,41,174,85,227,154,
181,110,114,88,127,196,177,140,156,237,46,158,124,89,238,1,0,0,0,224,129,194,9,0,0,0,64,5,143,234,60,130,71,117,58,158,234,81,157,184,29,110,106,106,42,69,79,43,30,171,248,222,219,99,61,170,243,227,31,
213,137,87,107,62,135,120,237,93,156,255,111,189,53,212,163,58,29,95,155,239,113,187,99,188,46,239,57,196,249,141,243,252,45,175,57,244,168,206,227,111,149,141,87,31,246,190,254,240,169,68,255,250,154,
181,136,71,117,242,228,81,157,250,106,243,163,58,207,181,70,249,187,185,171,45,143,234,196,235,162,123,95,123,253,84,226,21,184,253,94,47,220,212,71,117,234,176,22,203,245,81,29,133,147,71,80,56,233,120,
170,194,73,12,144,209,225,159,195,167,79,159,190,251,121,63,133,147,31,95,56,137,65,244,57,196,126,198,133,197,183,22,57,20,78,58,190,165,112,210,155,55,79,37,242,48,206,243,245,245,117,250,228,241,20,
78,30,191,112,137,139,137,231,186,160,136,57,247,221,187,119,41,250,123,10,39,121,82,56,169,175,182,22,78,234,52,119,181,165,112,50,55,55,247,69,17,224,169,196,121,239,215,23,155,92,56,249,167,243,217,
111,156,0,0,0,0,52,140,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,194,9,0,0,0,64,5,133,19,0,0,
0,128,10,10,39,0,0,0,0,21,6,54,55,55,239,211,118,165,237,237,237,226,236,236,44,69,237,243,231,49,74,91,29,123,123,123,197,241,241,113,138,218,227,197,139,23,197,250,250,122,138,74,55,55,55,197,238,238,
110,113,122,122,154,62,249,122,163,163,163,197,236,236,108,138,158,214,249,249,121,241,241,227,199,20,125,155,216,215,249,249,249,20,117,108,109,109,165,173,102,27,26,26,42,86,87,87,83,84,186,186,186,
122,200,131,56,190,223,162,223,241,124,10,145,175,113,254,175,175,175,211,39,95,103,100,100,164,88,94,94,78,81,233,242,242,242,161,237,23,23,23,233,147,102,153,153,153,41,22,22,22,82,212,241,181,249,62,
48,48,80,204,205,205,165,232,105,69,62,198,121,190,189,189,77,159,60,94,191,49,63,206,239,135,15,31,82,212,12,107,107,107,197,224,224,96,138,74,7,7,7,197,225,225,97,138,254,222,228,228,100,49,49,49,145,
162,167,21,235,144,79,159,62,165,232,239,69,95,93,92,92,44,198,198,198,210,39,165,166,172,105,150,150,150,30,142,127,183,163,163,163,98,127,127,63,69,121,138,185,160,119,61,16,125,47,250,96,142,98,220,
219,216,216,72,81,233,71,172,155,254,9,49,247,71,159,26,31,31,79,159,148,118,118,118,190,123,93,245,156,250,229,88,236,127,180,163,159,231,156,187,98,109,18,249,94,53,119,245,155,143,35,143,34,159,34,
175,234,234,107,247,123,122,122,186,120,249,242,101,138,158,86,92,207,197,58,174,215,240,240,112,177,178,178,146,162,210,247,174,117,159,82,244,205,56,110,221,162,109,113,205,218,173,14,107,177,31,177,
254,120,106,113,44,35,103,227,120,125,166,112,242,8,10,39,29,79,85,56,201,141,194,201,143,47,156,228,66,225,164,163,169,249,174,112,82,159,133,203,247,80,56,201,147,194,73,125,181,181,112,82,39,109,41,
156,212,65,83,11,39,117,144,107,225,196,163,58,0,0,0,0,21,30,117,199,201,31,127,252,209,234,59,78,162,42,214,43,190,209,201,169,186,254,163,196,29,39,189,213,215,168,20,199,241,104,83,142,68,229,252,231,
159,127,78,81,199,127,254,243,159,180,213,108,241,173,211,111,191,253,150,162,82,220,94,26,121,208,134,59,78,126,249,229,151,20,149,226,27,136,104,123,83,239,56,137,170,123,191,219,58,155,154,239,109,
25,243,227,206,169,222,111,124,222,189,123,215,152,187,41,163,175,70,222,246,222,113,242,251,239,191,55,98,156,138,111,23,123,31,147,138,59,51,226,91,187,156,197,57,235,253,214,52,250,94,244,193,28,197,
183,149,189,119,104,230,186,110,138,185,63,206,79,239,29,39,241,141,246,215,60,70,247,79,139,245,91,172,227,186,197,254,215,241,155,249,94,253,230,227,200,163,216,247,111,121,52,245,185,84,237,119,244,
131,58,223,113,242,235,175,191,166,168,84,231,245,94,220,73,53,53,53,149,162,82,93,231,132,28,214,31,113,44,35,103,191,250,81,29,0,0,0,128,54,242,168,14,0,0,0,64,5,133,19,0,0,0,128,10,143,122,84,231,254,
190,221,79,243,116,63,219,244,89,155,143,137,227,81,106,251,113,104,115,251,219,216,246,54,181,185,45,109,109,67,59,155,220,70,109,203,71,147,218,211,148,182,228,220,142,92,247,61,199,253,206,105,159,
237,235,143,215,187,159,94,71,252,8,253,94,77,233,117,196,29,241,163,78,57,190,86,239,123,120,29,177,215,17,119,243,58,226,102,233,55,230,199,249,245,58,226,188,120,29,113,158,188,142,184,190,188,142,
248,159,231,117,196,207,199,235,136,159,142,215,17,3,0,0,0,52,140,194,9,0,0,0,64,5,133,19,0,0,178,247,243,207,63,63,220,2,254,28,127,83,83,83,233,95,5,160,13,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,
0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,128,236,221,
223,223,23,119,119,119,207,242,7,64,187,40,156,0,0,144,189,79,159,62,21,251,251,251,207,242,119,126,126,158,254,85,0,218,64,225,4,0,128,236,93,94,94,22,39,39,39,207,242,119,115,115,147,254,85,0,218,64,
225,4,0,0,0,160,194,192,230,230,230,125,218,6,0,0,0,160,139,59,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,0,0,0,168,240,168,223,56,249,248,241,99,113,125,125,157,162,246,121,243,230,77,218,234,136,95,84,
143,95,111,111,155,129,129,129,226,245,235,215,41,42,221,221,221,61,28,143,54,229,200,232,232,104,49,57,57,153,162,142,247,239,223,167,173,102,123,241,226,69,241,234,213,171,20,149,110,111,111,91,241,
166,129,193,193,193,98,118,118,54,69,165,104,115,180,61,142,65,19,181,45,223,219,50,230,199,88,30,99,122,183,211,211,211,226,226,226,34,69,121,139,190,58,49,49,81,12,15,15,167,79,74,77,89,211,76,77,77,
21,35,35,35,41,42,197,43,114,207,206,206,82,148,167,56,103,99,99,99,41,42,69,78,70,110,230,170,119,76,201,117,221,20,115,127,156,159,222,188,203,109,124,236,151,99,159,223,200,84,119,253,230,227,171,171,
171,135,125,191,191,175,239,207,86,86,237,119,244,235,232,15,117,148,219,90,55,142,111,28,231,110,117,29,59,115,88,127,196,56,23,243,108,183,71,21,78,182,183,183,179,159,136,191,199,159,199,40,109,117,
236,237,237,21,199,199,199,41,106,143,24,68,214,215,215,83,84,138,193,99,119,119,55,235,69,205,215,138,11,231,249,249,249,20,117,108,109,109,165,173,102,27,26,26,42,86,87,87,83,84,138,9,48,242,32,22,238,
77,22,3,233,242,242,114,138,74,177,224,138,182,55,229,130,179,215,204,204,76,177,176,176,144,162,142,166,230,123,191,49,63,206,239,135,15,31,82,212,12,107,107,107,15,197,133,110,7,7,7,197,225,225,97,138,
242,22,125,117,113,113,241,139,11,164,166,172,105,150,150,150,190,184,16,57,58,58,42,246,247,247,83,148,167,152,91,123,139,211,209,247,162,15,230,40,46,14,54,54,54,82,84,202,117,221,20,115,127,244,169,
241,241,241,244,73,105,103,103,231,161,32,153,139,126,57,22,251,31,237,168,187,126,243,113,228,81,228,83,157,191,184,202,113,191,163,232,190,178,178,146,162,82,157,215,186,209,55,167,167,167,83,84,138,
107,213,184,102,173,155,28,214,31,113,44,35,103,187,11,60,30,213,1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,
0,0,84,80,56,1,0,0,0,168,160,112,2,0,0,0,80,65,225,4,0,0,0,160,130,194,9,0,0,0,64,5,133,19,0,0,0,128,10,10,39,0,0,0,0,21,20,78,0,0,0,0,42,40,156,0,0,0,0,84,80,56,1,0,0,0,168,48,176,185,185,121,159,182,
43,29,28,28,20,151,151,151,41,106,159,127,253,235,95,105,171,227,232,232,168,56,61,61,77,81,123,12,12,12,20,75,75,75,41,42,221,222,222,22,135,135,135,173,202,145,137,137,137,226,213,171,87,41,234,248,
223,255,254,151,182,154,109,112,112,176,88,92,92,76,81,233,230,230,230,161,95,52,61,15,134,135,135,139,249,249,249,20,149,174,175,175,31,218,126,117,117,149,62,105,150,241,241,241,226,245,235,215,41,234,
104,106,190,247,27,243,99,140,59,59,59,75,81,51,188,125,251,182,120,241,226,175,223,159,28,31,31,23,39,39,39,41,202,91,244,213,24,167,71,70,70,210,39,165,166,172,105,126,250,233,167,98,108,108,44,69,165,
56,119,113,14,115,22,231,44,230,216,110,177,222,138,49,54,71,85,235,166,104,207,197,197,69,250,36,15,49,247,199,249,233,205,187,220,198,199,217,217,217,98,114,114,50,69,165,216,255,104,71,221,245,91,127,
70,30,69,62,69,94,213,85,142,251,61,52,52,84,44,44,44,164,168,84,231,245,94,172,211,98,189,214,173,174,115,66,14,235,143,56,150,145,179,49,134,127,246,168,194,73,36,244,253,253,223,254,111,141,21,29,167,
215,221,221,221,195,95,27,245,59,30,109,203,145,232,236,189,29,62,68,241,160,13,98,16,137,5,84,183,56,255,209,39,154,158,7,109,108,123,191,54,135,166,230,123,91,198,184,166,207,109,145,183,49,78,119,47,
122,66,83,206,101,244,201,222,182,53,225,252,245,155,95,115,111,87,147,198,148,126,121,151,91,91,250,229,88,236,127,180,163,238,114,221,247,28,247,187,223,218,39,246,57,198,162,58,230,123,78,115,66,14,
235,143,126,231,255,81,133,19,0,0,0,128,54,250,242,43,115,0,0,0,0,30,40,156,0,0,0,0,244,85,20,255,7,53,7,232,206,222,49,86,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* PluginEditor::gneck_inverted_png = (const char*) resource_PluginEditor_gneck_inverted_png;
const int PluginEditor::gneck_inverted_pngSize = 5025;


//[EndFile] You can add extra defines here...
//[/EndFile]
