/*! \file BasicScale.h
A scoped enum for basic scale names. */

// BasicScale.h
#ifndef BASICSCALE_H
#define BASICSCALE_H

namespace acentric_core {

	/*! The BasicScale enum provides commonly-recognized scales for use as input to the Scale constructor. */
	enum class BasicScale {

		Major			/*! The major scale; intervals P1 M2 M3 P4 P5 M6 M7 */,
		Minor			/*! The natural minor scale; intervals P1 M2 m3 P4 P5 m6 m7 */,
		HarmonicMinor	/*! The harmonic minor scale; intervals P1 M2 m3 P4 P5 m6 M7 */,
		Ionian			/*! The Ionian mode, also known as the major scale; intervals P1 M2 M3 P4 P5 M6 M7 */,
		Dorian			/*! The Dorian mode; intervals P1 M2 m3 P4 P5 M6 m7 */,
		Phrygian		/*! The Phrygian mode; intervals P1 m2 m3 P4 P5 m6 m7 */,
		Lydian			/*! The Lydian mode; intervals P1 M2 M3 A4 P5 M6 M7 */,
		Mixolydian		/*! The Mixolydian mode; intervals P1 M2 M3 P4 P5 M6 m7 */,
		Aeolian			/*! The Aeolian mode, also known as the natural minor scale; intervals P1 M2 m3 P4 P5 m6 m7 */,
		Locrian			/*! The Locrian mode; intervals P1 m2 m3 P4 d5 m6 m7 */,
		MinorPentatonic /*! Minor Pentatonic scales; */,
		MajorPentatonic /*! Major Pentatonic scales; */,
		Blues			/*! The blues scale; Based on pentatonic scales with added m5 blue note */,
		Metallica		/*! Minor scale with an added b2 and b5*/,
		PhrygianDominant /*! The Phrygian Dominant scale; intervals P1 m2 M3 P4 P5 m6 m7 */
	};

}

#endif // BASICSCALE_H