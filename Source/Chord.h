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
	};

	std::ostream& operator<<(std::ostream &os, const Chord &chord);

}

#endif // CHORD_H