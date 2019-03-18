#include "Scale.h"

namespace acentric_core {

	Scale::Scale(Note base, std::vector<Interval> degrees)
	{

		for (int i = 0; i < degrees.size(); ++i) {
			// Make sure each basic note is used in the scale and is passed in proper order
			if (degrees.at(i).getBasicDistance() != i + 1)
				throw "improper ordering of basic intervals passed to DiatonicScale ctor";
			// Make sure each degree is properly ordered by number of semitones; ensure 7 distinct pitch classes are in the scale
			if (i > 0 && (degrees.at(i).getSemitones() <= degrees.at(i - 1).getSemitones()))
				throw "improper ordering of semitones passed to DiatonicScale ctor"; // TODO make better error messages
		}

		this->base = base;
		this->degrees = degrees;
	}

	Scale::Scale(Note base, BasicScale scale)
	{
		this->base = base;

		switch (scale) {
		case BasicScale::Aeolian:
		case BasicScale::Minor:
			degrees.push_back(Interval{ 'M', 2 });
			degrees.push_back(Interval{ 'm', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'm', 6 });
			degrees.push_back(Interval{ 'm', 7 });
			break;

		case BasicScale::Dorian:
			degrees.push_back(Interval{ 'M', 2 });
			degrees.push_back(Interval{ 'm', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'M', 6 });
			degrees.push_back(Interval{ 'm', 7 });
			break;

		case BasicScale::Ionian:
		case BasicScale::Major:
			degrees.push_back(Interval{ 'M', 2 });
			degrees.push_back(Interval{ 'M', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'M', 6 });
			degrees.push_back(Interval{ 'M', 7 });
			break;

		case BasicScale::Locrian:
			degrees.push_back(Interval{ 'm', 2 });
			degrees.push_back(Interval{ 'm', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'd', 5 });
			degrees.push_back(Interval{ 'm', 6 });
			degrees.push_back(Interval{ 'm', 7 });
			break;

		case BasicScale::Lydian:
			degrees.push_back(Interval{ 'M', 2 });
			degrees.push_back(Interval{ 'M', 3 });
			degrees.push_back(Interval{ 'a', 4 });
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'M', 6 });
			degrees.push_back(Interval{ 'M', 7 });
			break;

		case BasicScale::Mixolydian:
			degrees.push_back(Interval{ 'M', 2 });
			degrees.push_back(Interval{ 'M', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'M', 6 });
			degrees.push_back(Interval{ 'm', 7 });
			break;

		case BasicScale::Phrygian:
			degrees.push_back(Interval{ 'm', 2 });
			degrees.push_back(Interval{ 'm', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'm', 6 });
			degrees.push_back(Interval{ 'm', 7 });
			break;
		
		case BasicScale::Blues:
			degrees.push_back(Interval{ 'm', 3});
			degrees.push_back(Interval{ 'P', 4});
			degrees.push_back(Interval{ 'm', 5});
			degrees.push_back(Interval{ 'P', 5});
			degrees.push_back(Interval{ 'm', 7});
			break;

		case BasicScale::MinorPentatonic:
			degrees.push_back(Interval{ 'm', 3});
			degrees.push_back(Interval{ 'P', 4});
			degrees.push_back(Interval{ 'P', 5});
			degrees.push_back(Interval{ 'm', 7});
			break;

		case BasicScale::MajorPentatonic:
			degrees.push_back(Interval{ 'M', 2});
			degrees.push_back(Interval{ 'M', 3});
			degrees.push_back(Interval{ 'P', 5});
			degrees.push_back(Interval{ 'M', 6});
			break;

		case BasicScale::Metallica:
			degrees.push_back(Interval{ 'm', 2 });
			degrees.push_back(Interval{ 'M', 2 });
			degrees.push_back(Interval{ 'm', 3 });
			degrees.push_back(Interval{ 'P', 4 });
			degrees.push_back(Interval{ 'm', 5});
			degrees.push_back(Interval{ 'P', 5 });
			degrees.push_back(Interval{ 'm', 6 });
			degrees.push_back(Interval{ 'm', 7 });
			break;
		}
	}

	std::vector<Note> Scale::getDegrees() const
	{
		std::vector<Note> scaleNotes;
		for (auto &interval : this->degrees)
			scaleNotes.push_back(this->base.getOtherNote(interval));


		return scaleNotes;
	}

	std::ostream & operator<<(std::ostream & os, const Scale & scale)
	{
		os << scale.getBase();
		for (auto &note : scale.getDegrees()) {
			os << " " << note; // TODO don't print octave (should be quick fix)
		}

		return os;
	}

}
