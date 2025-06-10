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

#include "PluginEditor.h"

using namespace acentric_core;

//==============================================================================
PluginEditor::PluginEditor (MusicTheoryAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible (*(guitarComponent = std::make_unique<GroupComponent> ("new group",
                                                            TRANS("guitar"))));
    guitarComponent->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(scalesComponent = std::make_unique<GroupComponent> ("new group",
                                                             TRANS("scales"))));
    scalesComponent->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(infoComponent = std::make_unique<GroupComponent> ("new group",
                                                             TRANS("information"))));
    infoComponent->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(chordsComponent = std::make_unique<GroupComponent> ("new group",
                                                             TRANS("chords"))));
    chordsComponent->setColour (GroupComponent::outlineColourId, Colours::aquamarine);

    addAndMakeVisible (*(scaleKey = std::make_unique<ComboBox> ("new combo box")));
    scaleKey->setEditableText (false);
    scaleKey->setJustificationType (Justification::centredLeft);
    scaleKey->setTextWhenNothingSelected (TRANS("key"));
    scaleKey->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    for (int i = 0; i < Constants::ROOT_NOTES.size(); ++i) {
        scaleKey->addItem(TRANS(Constants::ROOT_NOTES[i]), i + 1);
    }
    scaleKey->setSelectedId (1, dontSendNotification);
    scaleKey->addListener (this);

    addAndMakeVisible (*(scaleMode = std::make_unique<ComboBox> ("new combo box")));
    scaleMode->setEditableText (false);
    scaleMode->setJustificationType (Justification::centredLeft);
    scaleMode->setTextWhenNothingSelected (TRANS("scale"));
    scaleMode->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    for (int i = 0; i < Constants::SCALE_MODES.size(); ++i) {
        scaleMode->addItem(TRANS(Constants::SCALE_MODES[i].first), i + 1);
    }
    scaleMode->setSelectedId (1, dontSendNotification);
    scaleMode->addListener (this);

    addAndMakeVisible (*(chordRoot = std::make_unique<ComboBox> ("new combo box")));
    chordRoot->setEditableText (false);
    chordRoot->setJustificationType (Justification::centredLeft);
    chordRoot->setTextWhenNothingSelected (TRANS("root"));
    chordRoot->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    for (int i = 0; i < Constants::ROOT_NOTES.size(); ++i) {
        chordRoot->addItem(TRANS(Constants::ROOT_NOTES[i]), i + 1);
    }
    chordRoot->setSelectedId (1, dontSendNotification);
    chordRoot->addListener (this);

    addAndMakeVisible (*(chordType = std::make_unique<ComboBox> ("new combo box")));
    chordType->setEditableText (false);
    chordType->setJustificationType (Justification::centredLeft);
    chordType->setTextWhenNothingSelected (TRANS("type"));
    chordType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    for (int i = 0; i < Constants::CHORD_TYPES.size(); ++i) {
        chordType->addItem(TRANS(Constants::CHORD_TYPES[i].first), i + 1);
    }
    chordType->setSelectedId (2, dontSendNotification);
    chordType->addListener (this);

    addAndMakeVisible (*(infoText = std::make_unique<TextEditor> ("new text editor")));
    infoText->setMultiLine (true);
    infoText->setReturnKeyStartsNewLine (true);
    infoText->setReadOnly (false);
    infoText->setScrollbarsShown (true);
    infoText->setCaretVisible (true);
    infoText->setPopupMenuEnabled (true);
    infoText->setColour (TextEditor::backgroundColourId, Colours::transparentWhite);
    infoText->setText (TRANS(""));

    addAndMakeVisible (*(txtScale = std::make_unique<TextEditor> ("new text editor")));
    txtScale->setMultiLine (true);
    txtScale->setReturnKeyStartsNewLine (false);
    txtScale->setReadOnly (true);
    txtScale->setScrollbarsShown (false);
    txtScale->setCaretVisible (false);
    txtScale->setPopupMenuEnabled (false);
    txtScale->setColour (TextEditor::backgroundColourId, Colours::transparentWhite);
    txtScale->setText ("C D E F G A B ");

    addAndMakeVisible (*(txtChord = std::make_unique<TextEditor> ("new text editor")));
    txtChord->setMultiLine (true);
    txtChord->setReturnKeyStartsNewLine (false);
    txtChord->setReadOnly (true);
    txtChord->setScrollbarsShown (false);
    txtChord->setCaretVisible (false);
    txtChord->setPopupMenuEnabled (false);
    txtChord->setColour (TextEditor::backgroundColourId, Colours::transparentWhite);
    txtChord->setText ("C E G ");

    addAndMakeVisible (*(viewAll = std::make_unique<ToggleButton> ("new toggle button")));
    viewAll->setButtonText("All");
    viewAll->setClickingTogglesState (true);
    viewAll->setToggleState (true, dontSendNotification);
    viewAll->onClick = [this]() { selectButton("All"); };

    addAndMakeVisible (*(viewScale = std::make_unique<ToggleButton> ("new toggle button")));
    viewScale->setButtonText("Scale");
    viewScale->setToggleState (false, dontSendNotification);
    viewScale->onClick = [this]() { selectButton("Scale"); };

    addAndMakeVisible (*(viewChord = std::make_unique<ToggleButton> ("new toggle button")));
    viewChord->setButtonText("Chord");
    viewChord->setToggleState (false, dontSendNotification);
    viewChord->onClick = [this]() { selectButton("Chord"); };

    addAndMakeVisible (*(viewMidi = std::make_unique<ToggleButton> ("new toggle button")));
    viewMidi->setButtonText("Midi");
    viewMidi->setToggleState (false, dontSendNotification);
    viewMidi->onClick = [this]() { selectButton("Midi"); };

    addAndMakeVisible (*(buttonColour = std::make_unique<TextButton> ("new toggle button")));
    buttonColour->setButtonText("theme");
    buttonColour->setClickingTogglesState (true);
    buttonColour->onClick = [this]() { switchColour(); };
    buttonColourAttachment = std::make_unique<AudioProcessorValueTreeState::ButtonAttachment>(*p.state, "buttonColour", *buttonColour);

    addAndMakeVisible (*(buttonView = std::make_unique<TextButton> ("new toggle button")));
    buttonView->setButtonText("view");
    buttonView->setClickingTogglesState (true);
    buttonView->onClick = [this]() { viewButton(); };

    auto createTextEditor = [this](std::unique_ptr<TextEditor>& editorPtr, const String& labelText, Colour color)
    {
        addAndMakeVisible(*(editorPtr = std::make_unique<TextEditor>("new text editor")));
        editorPtr->setColour (TextEditor::outlineColourId, Colour (0x00522d2d));
        editorPtr->setColour (TextEditor::shadowColourId, Colour (0x00c12323));
        editorPtr->setColour(TextEditor::textColourId, Colours::black);
        editorPtr->setColour(TextEditor::backgroundColourId, color);
        editorPtr->setText(TRANS(labelText));
        editorPtr->setName(editorPtr->getText());
        editorPtr->setMultiLine (true);
        editorPtr->setReturnKeyStartsNewLine (false);
        editorPtr->setReadOnly (true);
        editorPtr->setScrollbarsShown (false);
        editorPtr->setCaretVisible (false);
        editorPtr->setPopupMenuEnabled (false);
    };

    createTextEditor(C, "C", Constants::colorC);
    createTextEditor(C2, "C", Constants::colorC);
    createTextEditor(C3, "C", Constants::colorC);
    createTextEditor(C4, "C", Constants::colorC);
    createTextEditor(C5, "C", Constants::colorC);
    createTextEditor(C6, "C", Constants::colorC);
    createTextEditor(C7, "C", Constants::colorC);
    createTextEditor(C8, "C", Constants::colorC);
    createTextEditor(C9, "C", Constants::colorC);
    createTextEditor(C10, "C", Constants::colorC);
    createTextEditor(C11, "C", Constants::colorC);

    createTextEditor(CS, "C#", Constants::colorCs);
    createTextEditor(CS2, "C#", Constants::colorCs);
    createTextEditor(CS3, "C#", Constants::colorCs);
    createTextEditor(CS4, "C#", Constants::colorCs);
    createTextEditor(CS5, "C#", Constants::colorCs);
    createTextEditor(CS6, "C#", Constants::colorCs);
    createTextEditor(CS7, "C#", Constants::colorCs);
    createTextEditor(CS8, "C#", Constants::colorCs);
    createTextEditor(CS9, "C#", Constants::colorCs);

    createTextEditor(D, "D", Constants::colorD);
    createTextEditor(D2, "D", Constants::colorD);
    createTextEditor(D3, "D", Constants::colorD);
    createTextEditor(D4, "D", Constants::colorD);
    createTextEditor(D5, "D", Constants::colorD);
    createTextEditor(D6, "D", Constants::colorD);
    createTextEditor(D7, "D", Constants::colorD);
    createTextEditor(D8, "D", Constants::colorD);
    createTextEditor(D9, "D", Constants::colorD);

    createTextEditor(DS, "D#", Constants::colorDs);
    createTextEditor(DS2, "D#", Constants::colorDs);
    createTextEditor(DS3, "D#", Constants::colorDs);
    createTextEditor(DS4, "D#", Constants::colorDs);
    createTextEditor(DS5, "D#", Constants::colorDs);
    createTextEditor(DS6, "D#", Constants::colorDs);
    createTextEditor(DS7, "D#", Constants::colorDs);
    createTextEditor(DS8, "D#", Constants::colorDs);
    createTextEditor(DS9, "D#", Constants::colorDs);
    createTextEditor(DS10, "D#", Constants::colorDs);

    createTextEditor(E, "E", Constants::colorE);
    createTextEditor(E2, "E", Constants::colorE);
    createTextEditor(E3, "E", Constants::colorE);
    createTextEditor(E4, "E", Constants::colorE);
    createTextEditor(E5, "E", Constants::colorE);
    createTextEditor(E6, "E", Constants::colorE);
    createTextEditor(E7, "E", Constants::colorE);
    createTextEditor(E8, "E", Constants::colorE);
    createTextEditor(E9, "E", Constants::colorE);

    createTextEditor(F, "F", Constants::colorF);
    createTextEditor(F1, "F", Constants::colorF);
    createTextEditor(F2, "F", Constants::colorF);
    createTextEditor(F3, "F", Constants::colorF);
    createTextEditor(F4, "F", Constants::colorF);
    createTextEditor(F5, "F", Constants::colorF);
    createTextEditor(F6, "F", Constants::colorF);
    createTextEditor(F7, "F", Constants::colorF);
    createTextEditor(F8, "F", Constants::colorF);
    createTextEditor(F9, "F", Constants::colorF);
    createTextEditor(F10, "F", Constants::colorF);

    createTextEditor(FS, "F#", Constants::colorFs);
    createTextEditor(FS2, "F#", Constants::colorFs);
    createTextEditor(FS3, "F#", Constants::colorFs);
    createTextEditor(FS4, "F#", Constants::colorFs);
    createTextEditor(FS5, "F#", Constants::colorFs);
    createTextEditor(FS6, "F#", Constants::colorFs);
    createTextEditor(FS7, "F#", Constants::colorFs);
    createTextEditor(FS8, "F#", Constants::colorFs);
    createTextEditor(FS9, "F#", Constants::colorFs);
    createTextEditor(FS10, "F#", Constants::colorFs);

    createTextEditor(G, "G", Constants::colorG);
    createTextEditor(G2, "G", Constants::colorG);
    createTextEditor(G3, "G", Constants::colorG);
    createTextEditor(G4, "G", Constants::colorG);
    createTextEditor(G5, "G", Constants::colorG);
    createTextEditor(G6, "G", Constants::colorG);
    createTextEditor(G7, "G", Constants::colorG);
    createTextEditor(G8, "G", Constants::colorG);
    createTextEditor(G9, "G", Constants::colorG);
    createTextEditor(G10, "G", Constants::colorG);

    createTextEditor(GS, "G#", Constants::colorGs);
    createTextEditor(GS2, "G#", Constants::colorGs);
    createTextEditor(GS3, "G#", Constants::colorGs);
    createTextEditor(GS4, "G#", Constants::colorGs);
    createTextEditor(GS5, "G#", Constants::colorGs);
    createTextEditor(GS6, "G#", Constants::colorGs);
    createTextEditor(GS7, "G#", Constants::colorGs);
    createTextEditor(GS8, "G#", Constants::colorGs);
    createTextEditor(GS9, "G#", Constants::colorGs);
    createTextEditor(GS10, "G#", Constants::colorGs);

    createTextEditor(A, "A", Constants::colorA);
    createTextEditor(A2, "A", Constants::colorA);
    createTextEditor(A3, "A", Constants::colorA);
    createTextEditor(A4, "A", Constants::colorA);
    createTextEditor(A5, "A", Constants::colorA);
    createTextEditor(A6, "A", Constants::colorA);
    createTextEditor(A7, "A", Constants::colorA);
    createTextEditor(A8, "A", Constants::colorA);
    createTextEditor(A9, "A", Constants::colorA);
    createTextEditor(A10, "A", Constants::colorA);

    createTextEditor(AS, "A#", Constants::colorAs);
    createTextEditor(AS2, "A#", Constants::colorAs);
    createTextEditor(AS3, "A#", Constants::colorAs);
    createTextEditor(AS4, "A#", Constants::colorAs);
    createTextEditor(AS5, "A#", Constants::colorAs);
    createTextEditor(AS6, "A#", Constants::colorAs);
    createTextEditor(AS7, "A#", Constants::colorAs);
    createTextEditor(AS8, "A#", Constants::colorAs);
    createTextEditor(AS9, "A#", Constants::colorAs);
    createTextEditor(AS10, "A#", Constants::colorAs);
    createTextEditor(AS11, "A#", Constants::colorAs);

    createTextEditor(B, "B", Constants::colorB);
    createTextEditor(B2, "B", Constants::colorB);
    createTextEditor(B3, "B", Constants::colorB);
    createTextEditor(B4, "B", Constants::colorB);
    createTextEditor(B5, "B", Constants::colorB);
    createTextEditor(B6, "B", Constants::colorB);
    createTextEditor(B7, "B", Constants::colorB);
    createTextEditor(B8, "B", Constants::colorB);
    createTextEditor(B9, "B", Constants::colorB);
    createTextEditor(B10, "B", Constants::colorB);

    cachedImage_gneck_inverted_png_1 = std::make_unique<Image>(ImageCache::getFromMemory (gneck_inverted_png, gneck_inverted_pngSize));

    setSize (1000, 400); // Call Resized()
    //==============================================================================

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
}

PluginEditor::~PluginEditor() = default;

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    g.fillAll (backgroundColour);

    {
        int x = 16, y = 150, width = 968, height = 212;
        g.setColour (Colours::black);
        g.drawImage (*cachedImage_gneck_inverted_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_gneck_inverted_png_1->getWidth(), cachedImage_gneck_inverted_png_1->getHeight());
    }
    {
        int x = 146, y = 363, width = 48, height = 30;
        String text (TRANS("3"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont (11.0f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 264, y = 363, width = 40, height = 30;
        String text (TRANS("5"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont (11.0f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 365, y = 363, width = 51, height = 30;
        String text (TRANS("7"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont (11.0f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 470, y = 363, width = 43, height = 30;
        String text (TRANS("9"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont (11.0f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 614, y = 363, width = 43, height = 30;
        String text (TRANS("12"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont (11.0f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 742, y = 363, width = 51, height = 30;
        String text (TRANS("15"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont(11.00f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 829, y = 363, width = 43, height = 30;
        String text (TRANS("17"));
        Colour fillColour = Colours::white;
        g.setFont(11.0f);
        g.setColour (fillColour);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 901, y = 363, width = 51, height = 30;
        String text (TRANS("19"));
        Colour fillColour = Colours::white;
        g.setColour (fillColour);
        g.setFont (11.0f);
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
}

void PluginEditor::resized()
{
    // x,y,width,height
    chordsComponent->setBounds (8, 8, 200, 75);
    chordRoot->setBounds (15, 25, 60, 24);
    chordType->setBounds (75, 25, 120, 24);
    txtChord->setBounds (15, 50, 180, 25);

    scalesComponent->setBounds (208, 8, 200, 75);
    scaleKey->setBounds (215, 25, 60, 24);
    scaleMode->setBounds (275, 25, 125, 24);
    txtScale->setBounds (215, 50, 184, 25);

    infoComponent->setBounds (408, 8, 584, 75);
    infoText->setBounds (415, 25, 570, 50);

    guitarComponent->setBounds (8, 90, 985, 300);
    
    viewAll->setBounds (15, 110, 50, 24);
    viewScale->setBounds (65, 110, 75, 24);
    viewChord->setBounds (130, 110, 75, 24);
    viewMidi->setBounds (200, 110, 75, 24);
    
    buttonColour->setBounds (910, 107, 75, 24);
    buttonView->setBounds (830, 107, 75, 24);

    GS4->setBounds (24, 222, 56, 24);
    DS3->setBounds (24, 262, 56, 24);
    AS2->setBounds (24, 302, 56, 24);
    F1->setBounds (24, 347, 56, 24);
    C5->setBounds (24, 182, 56, 24);
    F2->setBounds (24, 139, 56, 24);
    A4->setBounds (84, 222, 56, 24);
    E3->setBounds (84, 262, 56, 24);
    B2->setBounds (84, 302, 56, 24);
    FS->setBounds (84, 347, 56, 24);
    CS5->setBounds (84, 182, 56, 24);
    FS6->setBounds (84, 139, 56, 24);
    AS4->setBounds (145, 222, 52, 24);
    F->setBounds (145, 262, 52, 24);
    C2->setBounds (145, 302, 52, 24);
    G->setBounds (145, 347, 52, 24);
    D5->setBounds (145, 182, 52, 24);
    G6->setBounds (145, 139, 52, 24);
    B4->setBounds (202, 222, 52, 24);
    FS3->setBounds (202, 262, 52, 24);
    CS2->setBounds (202, 302, 52, 24);
    GS->setBounds (202, 347, 52, 24);
    DS5->setBounds (202, 182, 52, 24);
    GS6->setBounds (202, 139, 52, 24);
    C4->setBounds (257, 222, 52, 24);
    G3->setBounds (257, 262, 52, 24);
    D2->setBounds (257, 302, 52, 24);
    A->setBounds (257, 347, 52, 24);
    E5->setBounds (257, 182, 52, 24);
    A6->setBounds (257, 139, 52, 24);
    CS4->setBounds (312, 222, 51, 24);
    GS3->setBounds (312, 262, 51, 24);
    DS2->setBounds (312, 302, 51, 24);
    AS->setBounds (312, 347, 51, 24);
    F5->setBounds (312, 182, 51, 24);
    AS6->setBounds (312, 139, 51, 24);
    D4->setBounds (367, 222, 48, 24);
    A3->setBounds (367, 262, 48, 24);
    E2->setBounds (367, 302, 48, 24);
    B->setBounds (367, 347, 48, 24);
    FS5->setBounds (367, 182, 48, 24);
    B6->setBounds (367, 139, 48, 24);
    DS4->setBounds (420, 222, 46, 24);
    AS3->setBounds (420, 262, 46, 24);
    F3->setBounds (420, 302, 46, 24);
    C->setBounds (420, 347, 46, 24);
    G5->setBounds (420, 182, 46, 24);
    C6->setBounds (420, 139, 46, 24);
    E4->setBounds (471, 222, 44, 24);
    B3->setBounds (471, 262, 44, 24);
    FS2->setBounds (471, 302, 44, 24);
    CS->setBounds (471, 347, 44, 24);
    GS5->setBounds (471, 182, 44, 24);
    CS6->setBounds (471, 139, 44, 24);
    F4->setBounds (520, 222, 44, 24);
    C3->setBounds (520, 262, 44, 24);
    G2->setBounds (520, 302, 44, 24);
    D->setBounds (520, 347, 44, 24);
    A5->setBounds (520, 182, 44, 24);
    D6->setBounds (520, 139, 44, 24);
    FS4->setBounds (569, 222, 43, 24);
    CS3->setBounds (569, 262, 43, 24);
    GS2->setBounds (569, 302, 43, 24);
    DS->setBounds (569, 347, 43, 24);
    AS5->setBounds (569, 182, 43, 24);
    DS6->setBounds (569, 139, 43, 24);
    G4->setBounds (616, 222, 42, 24);
    D3->setBounds (616, 262, 42, 24);
    A2->setBounds (616, 302, 42, 24);
    E->setBounds (616, 347, 42, 24);
    B5->setBounds (616, 182, 42, 24);
    E6->setBounds (616, 139, 42, 24);
    GS7->setBounds (664, 222, 39, 24);
    DS7->setBounds (664, 262, 39, 24);
    AS7->setBounds (664, 302, 39, 24);
    F6->setBounds (664, 347, 39, 24);
    C7->setBounds (664, 182, 39, 24);
    F7->setBounds (664, 139, 39, 24);
    A7->setBounds (708, 222, 38, 24);
    E7->setBounds (708, 262, 38, 24);
    B7->setBounds (708, 302, 38, 24);
    FS7->setBounds (708, 347, 38, 24);
    CS7->setBounds (708, 182, 38, 24);
    FS8->setBounds (708, 139, 38, 24);
    AS8->setBounds (751, 222, 36, 24);
    F8->setBounds (751, 262, 36, 24);
    C8->setBounds (751, 302, 36, 24);
    G7->setBounds (751, 347, 36, 24);
    D7->setBounds (751, 182, 36, 24);
    G8->setBounds (751, 139, 36, 24);
    B8->setBounds (792, 222, 36, 24);
    FS9->setBounds (792, 262, 36, 24);
    CS8->setBounds (792, 302, 36, 24);
    GS8->setBounds (792, 347, 36, 24);
    DS8->setBounds (792, 182, 36, 24);
    GS9->setBounds (792, 139, 36, 24);
    C9->setBounds (834, 222, 34, 24);
    G9->setBounds (834, 262, 34, 24);
    D8->setBounds (834, 302, 34, 24);
    A8->setBounds (834, 347, 34, 24);
    E8->setBounds (834, 182, 34, 24);
    A9->setBounds (834, 139, 34, 24);
    CS9->setBounds (873, 222, 32, 24);
    GS10->setBounds (873, 262, 32, 24);
    DS9->setBounds (873, 302, 32, 24);
    AS9->setBounds (873, 347, 32, 24);
    F9->setBounds (873, 182, 32, 24);
    AS10->setBounds (873, 139, 32, 24);
    D9->setBounds (911, 222, 32, 24);
    A10->setBounds (911, 262, 32, 24);
    E9->setBounds (911, 302, 32, 24);
    B9->setBounds (911, 347, 32, 24);
    FS10->setBounds (911, 182, 32, 24);
    B10->setBounds (911, 139, 32, 24);
    DS10->setBounds (949, 222, 30, 24);
    AS11->setBounds (949, 262, 30, 24);
    F10->setBounds (949, 302, 30, 24);
    C10->setBounds (949, 347, 30, 24);
    G10->setBounds (949, 182, 30, 24);
    C11->setBounds (949, 139, 30, 24);
}

void PluginEditor::switchColour()
{
    switch (currentColourState)
    {
        case ColourThemes::CadetBlue:
            currentColourState = ColourThemes::TransparentBlack;
            backgroundColour = Colours::transparentBlack;
            break;

        case ColourThemes::TransparentBlack:
            currentColourState = ColourThemes::CadetBlue;
            backgroundColour = Colours::cadetblue;
            break;
    }
    repaint();
}

void PluginEditor::viewButton()
{
    if(viewScale->getToggleState()) {
        updateGuitarNeckScales();
    }
    else if(viewChord->getToggleState()) {
        updateGuitarNeckChords();
    }
}

void PluginEditor::selectButton(const std::string & function)
{
    if(function == "All") {
        viewAll->setToggleState(true, dontSendNotification);
        viewScale->setToggleState(false, dontSendNotification);
        viewChord->setToggleState(false, dontSendNotification);
        viewMidi->setToggleState(false, dontSendNotification);
        infoText->setText("", dontSendNotification);
        resetGuitarNotes();
    }
    else if(function == "Scale") {
        viewScale->setToggleState(true, dontSendNotification);
        viewAll->setToggleState(false, dontSendNotification);
        viewChord->setToggleState(false, dontSendNotification);
        viewMidi->setToggleState(false, dontSendNotification);
        infoText->setText("", dontSendNotification); // TODO
        updateGuitarNeckScales();
    }
    else if(function == "Chord") {
        viewChord->setToggleState(true, dontSendNotification);
        viewAll->setToggleState(false, dontSendNotification);
        viewScale->setToggleState(false, dontSendNotification);
        viewMidi->setToggleState(false, dontSendNotification);
        infoText->setText("", dontSendNotification); // TODO
        updateGuitarNeckChords();
    }
    else if(function == "Midi") {
        viewMidi->setToggleState(true, dontSendNotification);
        viewAll->setToggleState(false, dontSendNotification);
        viewScale->setToggleState(false, dontSendNotification);
        viewChord->setToggleState(false, dontSendNotification);

        // TODO start timer or new thread to keep checking this as long as midi view is active
        auto midiNotes = processor.getActiveMidiNotes();
        String midiNotesStr;
        for (const auto& note : midiNotes) {
            midiNotesStr += note + " ";
        }
        String infostr;
        if(midiNotes.empty()) {
            infostr = "No active MIDI notes.\nPlayback MIDI in the plugin's track to see active notes on the fretboard.";
        } else {
            infostr = "Active MIDI Notes: " + midiNotesStr;
        }
        infoText->setText(infostr, dontSendNotification);
        updateGuitarNeckMidi(midiNotesStr);
    }
}

void PluginEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == scaleKey.get())
    {
		std::string scalekeystr = scaleKey->getText().toStdString();
		char scalekeychar = scalekeystr[0];
        int offset = scalekeystr[1] != '\0' ? 1 : 0;
		scaleroot = Note{ scalekeychar, offset,4 };
		updateScale();
        if(viewScale->getToggleState()) {
            updateGuitarNeckScales();
        }
    }
    else if (comboBoxThatHasChanged == scaleMode.get())
    {
        scaletype = BasicScale{ Constants::SCALE_MODES[scaleMode->getSelectedId()-1].second };
        updateScale();
        if(viewScale->getToggleState()) {
            updateGuitarNeckScales();
        }
    }
    else if (comboBoxThatHasChanged == chordRoot.get())
    {
		std::string chordkeystr = chordRoot->getText().toStdString();
		char chordkeychar = chordkeystr[0];
		int offset = chordkeystr[1] != '\0' ? 1 : 0;
		chordroot = Note{ chordkeychar, offset,4 };
		updateChord();
        if(viewChord->getToggleState()) {
            updateGuitarNeckChords();
        }
    }
    else if (comboBoxThatHasChanged == chordType.get())
    {
        chordtype = BasicChord{ Constants::CHORD_TYPES[chordType->getSelectedId()-1].second };
        updateChord();
        if(viewChord->getToggleState()) {
            updateGuitarNeckChords();
        }
    }
}

void PluginEditor::updateScale() {
	std::ostringstream stream;
	stream << Scale(scaleroot, scaletype) << std::endl;
	std::string scalestr = stream.str();
    scalestr += " ";
	juce::String jscalestr = simplifyNotes(scalestr);
	txtScale->setText(jscalestr);
}

void PluginEditor::updateChord() {
	std::ostringstream stream;
    currentChord = Chord(chordroot, chordtype);
	stream << currentChord << std::endl;
	std::string chordstr = stream.str();
    chordstr += " ";
	juce::String jchordstr = simplifyNotes(chordstr);
    txtChord->setText(jchordstr);
}

juce::String PluginEditor::simplifyNotes(const std::string & str) {
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
    juce::StringArray notesToMatch = juce::StringArray::fromTokens(txtScale->getText().trim(), " ", "");

	for (int i = 0; i < guitarnotes.size(); ++i) {
		guitarnotes.at(i)->setAlpha(Constants::NON_ROOT_NOTE_ALPHA);
        if (!(notesToMatch.contains(guitarnotes.at(i)->getName()))) {
            guitarnotes.at(i)->setVisible(false);
        }

		if (guitarnotes.at(i)->getName() == scaleKey->getText()) {
			guitarnotes.at(i)->setAlpha(1);
		}
	}
}

void PluginEditor::updateGuitarNeckChords() {
    resetGuitarNotes();
    juce::StringArray notesToMatch = juce::StringArray::fromTokens(txtChord->getText().trim(), " ", "");

    for (int i = 0; i < guitarnotes.size(); ++i) {
        guitarnotes.at(i)->setAlpha(Constants::NON_ROOT_NOTE_ALPHA);
        if (!(notesToMatch.contains(guitarnotes.at(i)->getName()))) {
            guitarnotes.at(i)->setVisible(false);
        }

        if(buttonView->getToggleState()) {
            std::string notetext = guitarnotes.at(i)->getName().toStdString();
            int offset = notetext[1] != '\0' ? 1 : 0;
            std::string intervaltxt = currentChord.getIntervalString(Note(notetext[0], offset));
            guitarnotes.at(i)->setText(intervaltxt);
        } else {
            guitarnotes.at(i)->setText(guitarnotes.at(i)->getName());
        }

        if (guitarnotes.at(i)->getName() == chordRoot->getText()) {
            guitarnotes.at(i)->setAlpha(1);
        }
    }
}

void PluginEditor::updateGuitarNeckMidi(const String & midinotes) {
    resetGuitarNotes();
    juce::StringArray notesToMatch = juce::StringArray::fromTokens(midinotes, " ", "");

    for (int i = 0; i < guitarnotes.size(); ++i) {
        guitarnotes.at(i)->setAlpha(1.0);
        if (!(notesToMatch.contains(guitarnotes.at(i)->getName()))) {
            guitarnotes.at(i)->setVisible(false);
        }
    }
}

void PluginEditor::resetGuitarNotes() {
	for (int i = 0; i < guitarnotes.size(); ++i) {
		guitarnotes.at(i)->setAlpha(1);
		guitarnotes.at(i)->setVisible(true);
        guitarnotes.at(i)->setText(guitarnotes.at(i)->getName());
	}
}

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