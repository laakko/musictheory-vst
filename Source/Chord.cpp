#include <algorithm>
#include <stdexcept>
#include <sstream>

#include "Chord.h"

namespace acentric_core {
	void Chord::cleanAndValidate() // TODO this function needs rigorous testing and documentation (also might need this func for scales later)
	{


		// Sort intervals by semitone distance
		std::sort(pitches.begin(), pitches.end(), IntervalSemitonesLessThan());

		// Add P1 to front if not already present
		auto firstInterval = pitches.at(0);
		if (firstInterval.getBasicDistance() != 0 || firstInterval.getSemitones() != 0) {
			pitches.insert(pitches.begin(), Interval{ 'P', 1 });
		}

		// Remove duplicates and check semitones strictly increasing and basic distance increasing
		int prevSemitones = 0;
		int prevBasicDist = 0;

		for (int i = 1; i < pitches.size(); ++i) { // (start at 1 because index 0 is definitely a P1)
			int curSemitones = pitches.at(i).getSemitones();
			int curBasicDist = pitches.at(i).getBasicDistance();

			// Check semitones
			if (curSemitones <= prevSemitones) {

				// Check for and remove duplicates
				if (curSemitones == prevSemitones && curBasicDist == prevBasicDist) {
					pitches.erase(pitches.begin() + i);
					--i;
					continue;
				}
				std::ostringstream errorString;
				errorString << "Attempted to create chord with non-strictly-increasing semitone distances\n"
					<< "(intervals " << pitches.at(i - 1) << " and " << pitches.at(i) << " have semitone distances "
					<< prevSemitones << " and " << curSemitones << ")";

				throw std::invalid_argument(errorString.str());
			}

			// Check basic distance (extremely rare/unlikely to be wrong)
			if (curBasicDist < prevBasicDist) {
				std::ostringstream errorString;
				errorString << "Attempted to create chord with non-increasing basic distances"
					<< "(intervals " << pitches.at(i - 1) << " and " << pitches.at(i) << " have basic distances "
					<< prevBasicDist << " and " << curBasicDist << ")";

				throw std::invalid_argument(errorString.str());
			}

			prevSemitones = curSemitones;
			prevBasicDist = curBasicDist;
		}

		// Ensure resulting pitch vector has more than just the P1
		if (pitches.size() <= 1) {
			throw std::invalid_argument("Attempted to create chord without any non-P1 interval");
		}
	}

	Chord::Chord(Note root, BasicChord chord) :
		root(root)
	{
		switch (chord) {
		case BasicChord::maj:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'M', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			break;

		case BasicChord::min:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			break;

		case BasicChord::aug:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'M', 3 });
			pitches.push_back(Interval{ 'a', 5 });
			break;

		case BasicChord::dim:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'd', 5 });
			break;

		case BasicChord::maj6:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'M', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			pitches.push_back(Interval{ 'M', 6 });
			break;

		case BasicChord::min6:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			pitches.push_back(Interval{ 'M', 6 });
			break;

		case BasicChord::dom7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'M', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			pitches.push_back(Interval{ 'm', 7 });
			break;

		case BasicChord::maj7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'M', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			pitches.push_back(Interval{ 'M', 7 });
			break;

		case BasicChord::min7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			pitches.push_back(Interval{ 'm', 7 });
			break;

		case BasicChord::aug7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'M', 3 });
			pitches.push_back(Interval{ 'a', 5 });
			pitches.push_back(Interval{ 'm', 7 });
			break;

		case BasicChord::dim7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'd', 5 });
			pitches.push_back(Interval{ 'd', 7 });
			break;

		case BasicChord::halfdim7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'd', 5 });
			pitches.push_back(Interval{ 'm', 7 });
			break;

		case BasicChord::min_maj7:
			pitches.push_back(Interval{ 'P', 1 });
			pitches.push_back(Interval{ 'm', 3 });
			pitches.push_back(Interval{ 'P', 5 });
			pitches.push_back(Interval{ 'M', 7 });
			break;

		}

		// TODO any reason to call cleanAndValidate() here? probably not
	}

	Chord::Chord(Note root, std::vector<Interval> pitches) :
		root(root),
		pitches(pitches)
	{
		this->cleanAndValidate();
	}

	Chord::Chord(Note root, std::vector<Note> otherNotes) : // TODO test
		root(root)
	{
		for (auto otherNote : otherNotes) {
			this->pitches.push_back(root.getInterval(otherNote));
		}
		this->cleanAndValidate();
	}

	Chord::Chord(std::vector<Note> notes) // TODO test
	{
		// Ensure chord has at least two pitches (really just need size >0 here but might as well deal with the size==1 case before the validation function sees it)
		if (notes.size() <= 1) {
			throw std::invalid_argument("Attempted to create Chord with Note vector size " + std::to_string(notes.size()) \
				+ "\n(size must be >= 2)");
		}

		// Find minimum note; set as root
		std::sort(notes.begin(), notes.end(), NoteAbsoluteDistLessThan());
		this->root = notes.at(0);

		// Set intervals based on the root
		this->pitches.push_back(Interval{ 'P', 1 });
		for (int i = 1; i < notes.size(); ++i) {
			this->pitches.push_back(notes.at(0).getInterval(notes.at(i)));
		}
		this->cleanAndValidate();
	}

	std::ostream & operator<<(std::ostream & os, const Chord & chord)
	{
		// TODO add functionality for recognizing standard chords and their inversions
		// this will take a very long time to do right but will be very useful
		// Some sort of search through a pre-built tree may be a good approach...
		// Check from root for match; if none, check inversions; if none still, default to just printing all notes

		Note base = chord.getRoot();
		std::vector<Interval> pitches = chord.getPitches();
		os << "Chord:";

		for (auto pitch : pitches) {
			os << " " << (base + pitch);
		}
		return os;
	}

}
