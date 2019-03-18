/*! \file BasicChord.h
A scoped enum for basic chord names. */

#ifndef BASICCHORD_H
#define BASICCHORD_H

namespace acentric_core {

	/*! The BasicChord enum provides commonly-recognized chord names for use as input to the Chord constructor.
		See https://en.wikipedia.org/wiki/Chord_names_and_symbols_(popular_music)#Examples for details. */
	enum class BasicChord {
		maj /* The major triad; intervals M3 P5 */,
		min /* The minor triad; intervals m3 P5 */,
		aug /* The augmented triad; intervals M3 A5 */,
		dim /* The diminished triad; intervals m3 d5 */,
		maj6 /* The major sixth chord; intervals M3 P5 M6 */,
		min6 /* The minor sixth chord; intervals m3 P5 M6 */,
		dom7 /* The dominant seventh chord; intervals M3 P5 m7 */,
		maj7 /* The major seventh chord; intervals M3 P5 M7 */,
		min7 /* The minor seventh chord; intervals m3 P5 m7 */,
		aug7 /* The augmented seventh chord; intervals M3 A5 m7 */,
		dim7 /* The diminished seventh chord; intervals m3 d5 d7 */,
		halfdim7 /* The half-diminished seventh chord; intervals m3 d5 m7 */,
		min_maj7 /* The minor-major seventh chord; intervals m3 P5 M7 */ /*,
		maj9,
		hendrix,
		dom9,
		min_maj9,
		min9,
		aug_maj9,
		aug9,
		halfdim9,
		halfdim_min9,
		dim9,
		dim_min9,
		dom11,
		maj11,
		min_maj11,
		min11,
		aug_maj11,
		aug11,
		halfdim11,
		dim11,
		maj13,
		dom13,
		min_maj13,
		min13,
		aug_maj13,
		aug13,
		halfdim13 // TODO implement or remove chords past sevenths */
	};

}

#endif // BASICCHORD_H