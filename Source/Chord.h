// Chord.h
#ifndef CHORD_H
#define CHORD_H

#include <iostream>
#include <vector>

#include "Note.h"
#include "Interval.h"
#include "BasicChord.h"

namespace acentric_core {

	class Chord {

	private:
		Note root = 1;
		std::vector<Interval> pitches;
		void cleanAndValidate();

	public:
		Chord() {}; // default ctor needed for parser
		Chord(Note root, BasicChord chord);
		Chord(Note root, std::string commonChord); // will need string to BasicChord converter...or maybe just convert string directly to vector<Interval>?
		Chord(Note root, std::vector<Interval> pitches);
		Chord(Note root, std::vector<Note> otherNotes);
		Chord(std::vector<Note> notes);

		Chord operator+(Interval interval) const;
		Chord operator-(Interval interval) const;

		Note getRoot() const { return root; }
		void setRoot(Note newRoot) { this->root = root; }
		const std::vector<Interval>& getPitches() const { return pitches; }
		

		Chord getInversion(int inversionNumber) const;

		std::string getRawString() const;
		std::string getCommonString() const; // going to be the tough one
		std::string getIntervalsString() const; // Method to format intervals as string

		// Returns the interval of the given note relative to the chord's root
		// Returns Interval(0) if the note is not in the chord
		Interval getInterval(Note note) const;

		// Returns the interval as a string (e.g. "P1", "M3", etc.) for the given note
		// Returns "P1" if the note is not in the chord
		std::string getIntervalString(Note note) const;
	};

	std::ostream& operator<<(std::ostream &os, const Chord &chord);

}

#endif // CHORD_H