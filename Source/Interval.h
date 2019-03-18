// Interval.h
#ifndef INTERVAL_H
#define INTERVAL_H

#include <iostream>
#include <string>
#include <vector>

namespace acentric_core {

	class Note;

	/*! The Interval class represents a distance between one Note and another Note.

	An Interval has two components: A basic distance, i.e. number of basic notes from one note to another (*not including the starting note*), and semitone distance.
	For instance, a major third has a basic distance of two and semitone distance of four. A minor sixth has a basic distance of five and semitone distance of eight.

	### Interval Number vs Basic Distance
	In music theory, an interval number represents the *number of notes encompassed* in the interval. For instance, an interval from C4 to D4 would have an interval number of 2.

	This library uses the notion of basic distance, rather than interval number, in its internal representation. This means that, while the *interval number* between C4 and D4 is 2,
	the *basic distance* between C4 and D4 is 1. This facilitates multi-octave calculations. It also helps to maintain consistency with computer science tradition. :)

	Due to potential confusion between the two, it is better to utilize the char-based constructor over the basicDistance/semitones-based constructor unless there is a good reason to do otherwise. */
	class Interval {

	private:
		int basicDistance; // e.g. basic distance from C#4-Eb4 is 2
		int semitones;

	public:
		/*! Standard, non-human-friendly Interval constructor.

		This constructor expects a basic distance (*not* interval number) and a semitone distance. The basic distance is simply the interval number minus one.
		For example, Interval(3, 4) would generate d4, *not* M3 (though both of these intervals are acoustically the same). On the other hand, Interval(2, 4) would generate M3. */
		Interval(int basicDistance, int semitones);

		/*! A more human-friendly constructor. The intervalType must be 'P' (perfect), 'M' (major), 'm' (minor), 'd' (diminished), or 'a' (augmented).
		The augmented interval must be lower-case to avoid ambiguity with the note name A.
		
		The intervalNumber must be a number >= 1.

		Not all letters are valid with all numbers. For example, P2 is not a valid musical interval. Refer to a music theory educational source to understand why.
		The [Wikipedia article on intervals](https://en.wikipedia.org/wiki/Interval_(music)) is a good place to start.

		Basically, a letter is valid for a number `n` for the following rules
		- If the letter is P: `n` is valid iff `n mod 7 = 1, 4, or 5`.
		- If the letter is M: `n` is valid iff `n mod 7 = 2, 3, 6, or 7`.
		- If the letter is m: `n` is valid iff `n mod 7 = 2, 3, 6, or 7`.
		- If the letter is a: `n` is valid for all positive integers
		- If the letter is d: `n` is valid for all positive integers except 1 (a d1 interval would result in a negative semitone distance)
		
		The offset adjusts the number of semitones in the interval. For instance, an M3 interval with an offset of 1 actually becomes an a3,
		and an a2 with an offset of -1 is the same as an M2. In the vast majority of cases, this offset is not used. It is useful in cases 
		where additional range is needed, e.g. for doubly- or triply-augmented intervals.*/
		Interval(char intervalType = 'P', int intervalNumber = 1, int offset = 0);

		/*! Returns the interval number of this Interval. For example, if this is a P5 interval, this function will return 5. */
		int getBasicInterval() const { return basicDistance + 1; }

		/*! Returns the basic distance of this Interval. For example, if this is a P5 interval, this function will return 4. */
		int getBasicDistance() const { return basicDistance; }

		/*! Returns the semitone distance of this interval. For examle, if this is a P5 interval, this function will return 7. */
		int getSemitones() const { return semitones; }

		Interval operator+(const Interval& other);

		Interval operator-(const Interval& other);

		// TODO add chromatic intervals, e.g. C4-F4 = I5
	};

	/*! Comparison class to compare Intervals based on semitone distance. True iff `a`'s semitone distance is less than `b`'s semitone distance. */
	struct IntervalSemitonesLessThan {
		bool operator()(const Interval& a, const Interval& b) { return a.getSemitones() < b.getSemitones(); }
	};

	/*! Prints the Interval in human-readable format, choosing from traditional or parenthesis-based format based on the interval distance.

	If a standard format exists for this interval, the function will prefer that format. If, on the other hand, no standard format exists
	(e.g. for an interval with interval number 7 and semitone distance 14), the function will use parenthesis format, e.g. (M+3)7.
	
	Parenthesis notation is useful (albeit in very niche circumstances) for intervals with disproportionate interval numbers and semitone distances.
	For example, a doubly-augmented sixth would be represented in parenthesis notation as (M+2)6. A triple-augmented fourth would be represented as (P+3)4.
	A quadruple-diminished fifth would be represented as (P-4)5, and so on.

	Parenthesis notation contains the following in order:
	- Open parenthesis
	- Interval type
	- Plus (+) or minus (-), representing the direction (augmenting or diminishing) from the interval type
	- A positive integer, representing the number of semitones away from the interval type
	- Close parenthesis
	- A positive integer for the interval number*/
	std::ostream& operator<<(std::ostream &os, const Interval &interval);

}

#endif // INTERVAL_H