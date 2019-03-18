// Scale.h
#ifndef _SCALE_H
#define _SCALE_H

#include <vector>
#include "BasicScale.h"
#include "Note.h"
#include "Interval.h"

namespace acentric_core {

	/*! The Scale class represents a musical scale with seven notes in ascending order, where each basic note name is used.

	It consists of a Note, which is the base of the scale, and a vector of six Intervals, representing degrees two through seven

	This class assumes that the first degree of a scale is always a perfect unison ("P1"). */
	class Scale {

	private:
		Note base;
		std::vector<Interval> degrees;
		//bool properOrder(std::vector<Interval> degrees); // TODO should I use this to validate BasicScale-based ctor strings?

	public:
		// The degrees vector must include six Intervals in strictly increasing order, with distances 1-6 (i.e. basic intervals 2-7)
		// and the semitone counts must also be strictly increasing
		// It is assumed the base is the first degree of the scale (but this doesn't allow, e.g., an A1 in any scale...is that a problem?)
		// TODO explain/document this better

		/*! The Interval-based constructor.

		This constructor expects a Note as a base and a vector of Intervals.

		The Intervals vector must include basic intervals two through seven, in that order, and their semitone distances must be strictly increasing. */
		Scale(Note base, std::vector<Interval> degrees);

		/*! The Note-based constructor.

		This constructor expects a Note as a base and a vector of Notes.

		The Notes vector must include six Notes in increasing order from the base note. Their absolute distances must be strictly increasing.

		The octave designation of each note is ignored. */
		// Scale(Note base, std::vector<Note> degrees); // TODO implement

		/*! The BasicScale-based constructor.

		This constructor expects a Note as a base and a BasicScale. For example, a Note C4 and BasicScale::Major would produce a C-major Scale. */
		Scale(Note base, BasicScale scale); // TODO finish implementing, dangerous to use right now

		/*! Returns a vector of Notes representing degrees two through seven. This may be changed in the future to include the first (base) degree. */
		std::vector<Note> getDegrees() const;

		/*! Returns the base note of the scale. */
		Note getBase() const { return base; };

		// TODO ...do I even need these functions? how robust do I want this library to be?
		//Scale getRelative() const;
		//Scale getParallel() const;

		bool isInScale(Note &note) const;
		Note simplify(Note &note) const;

	};

	std::ostream& operator<<(std::ostream &os, const Scale &scale);

}

#endif //_SCALE_H