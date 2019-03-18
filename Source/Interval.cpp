#include <stdexcept>
#include "Interval.h"

namespace acentric_core {

	Interval::Interval(int basicDistance, int semitones)
	{
		if (basicDistance < 0)
			throw std::invalid_argument("Invalid basic distance: " + std::to_string(basicDistance) + " (number must be >= 0)");
		this->basicDistance = basicDistance;

		if (semitones < 0)
			throw std::invalid_argument("Invalid semitones number: " + std::to_string(semitones) + " (number must be >= 0)");
		this->semitones = semitones;
	}

	Interval::Interval(char intervalType, int intervalNumber, int offset) {
		if (intervalNumber < 1)
			throw std::invalid_argument("Invalid interval number: " + std::to_string(intervalNumber) + "(number must be >= 1)");
		this->basicDistance = intervalNumber - 1;

		this->semitones = (this->basicDistance / 7) * 12;
		int remainder{ this->basicDistance % 7 };
		switch (intervalType) {
		case 'P':
			if (remainder == 0) break; // P1
			else if (remainder == 3) this->semitones += 5; // P4
			else if (remainder == 4) this->semitones += 7; // P5
			else throw std::invalid_argument("Invalid interval number given for interval class P: " + std::to_string(intervalNumber) \
				+ "\n(number mod 7 must equal 1, 4, or 5)");
			break;
		case 'm':
			if (remainder == 1) this->semitones += 1; // m2
			else if (remainder == 2) this->semitones += 3; // m3
			else if (remainder == 4) this->semitones += 6; // m5
			else if (remainder == 5) this->semitones += 8; // m6
			else if (remainder == 6) this->semitones += 10; // m7
			else throw std::invalid_argument("Invalid interval number given for interval class m: " + std::to_string(remainder) + std::to_string(intervalNumber) \
				+ "\n(number mod 7 must equal 2, 3, 6, or 7)");
			break;
		case 'M':
			if (remainder == 1) this->semitones += 2; // M2
			else if (remainder == 2) this->semitones += 4; // M3
			else if (remainder == 5) this->semitones += 9; // M6
			else if (remainder == 6) this->semitones += 11; // M7
			else throw std::invalid_argument("Invalid interval number given for interval class M: " + std::to_string(intervalNumber) \
				+ "\n(number mod 7 must equal 2, 3, 6, or 7)");
			break;
		case 'd':
			// d8 special case
			if (remainder == 0 && this->semitones >= 12) {
				this->semitones -= 1;
				break;
			}
			if (remainder == 1) break; // d2
			else if (remainder == 2) this->semitones += 2; // d3
			else if (remainder == 3) this->semitones += 4; // d4
			else if (remainder == 4) this->semitones += 6; // d5
			else if (remainder == 5) this->semitones += 7; // d6
			else if (remainder == 6) this->semitones += 9; // d7
			else throw std::invalid_argument("Invalid interval number given for interval class d: " + std::to_string(intervalNumber) \
				+ "\n(number must be >= 2)");
			break;
		case 'a':
			if (remainder == 0) this->semitones += 1; // a1
			else if (remainder == 1) this->semitones += 3; // a2
			else if (remainder == 2) this->semitones += 5; // a3
			else if (remainder == 3) this->semitones += 6; // a4
			else if (remainder == 4) this->semitones += 8; // a5
			else if (remainder == 5) this->semitones += 10; // a6
			else if (remainder == 6) this->semitones += 12; // a7
			else throw std::invalid_argument("Invalid interval number given for interval class a: " + std::to_string(intervalNumber) \
				+ "\n(number must be >= 1)");
			break;
		default:
			throw std::invalid_argument("Invalid interval type: " + std::to_string(intervalType) + "\n(type must be P, m, M, d, or a)");
		}

		// Add offset and check to make sure it's still positive
		this->semitones += offset;
		if (this->semitones < 0)
			throw std::invalid_argument("Invalid interval semitones calculated: " + std::to_string(this->semitones) + \
				"\n(value must be >= 0)");
	}

	Interval Interval::operator+(const Interval & other)
	{
		int basicDistance = this->getBasicDistance() + other.getBasicDistance();
		int semitones = this->semitones + other.semitones;

		return Interval(basicDistance, semitones);
	}

	Interval Interval::operator-(const Interval & other)
	{
		int basicDistance = this->getBasicDistance() - other.getBasicDistance();
		if (basicDistance < 0)
			throw std::invalid_argument("Invalid interval subtraction;\ncalculated basic distance " \
				+ std::to_string(this->getBasicDistance()) + " - " \
				+ std::to_string(other.getBasicDistance()) + " = " \
				+ std::to_string(basicDistance) \
				+ "\n(distance must be >= 0)");

		int semitones = this->semitones - other.semitones;
		if (semitones < 0)
			throw std::invalid_argument("Invalid interval subtraction;\ncalculated semitone distance " \
				+ std::to_string(this->semitones) + " - " \
				+ std::to_string(other.semitones) + " = " \
				+ std::to_string(semitones) \
				+ "\n(distance must be >= 0)");

		return Interval(basicDistance, semitones);
	}

	std::ostream & operator<<(std::ostream & os, const Interval & interval)
	{
		// Determine if the interval, unmodified, would be P or M
		bool perfect{ false };
		int basicDistance{ interval.getBasicDistance() };

		if (basicDistance % 7 == 0 || basicDistance % 7 == 3 || basicDistance % 7 == 4)
			perfect = true;
		else
			perfect = false; // so it would be Major instead

		// Find how many semitones the P/M interval would have
		int naturalSemitones{ (basicDistance / 7) * 12 };
		switch (basicDistance % 7) {
		case 0:
			break;
		case 1:
			naturalSemitones += 2;
			break;
		case 2:
			naturalSemitones += 4;
			break;
		case 3:
			naturalSemitones += 5;
			break;
		case 4:
			naturalSemitones += 7;
			break;
		case 5:
			naturalSemitones += 9;
			break;
		case 6:
			naturalSemitones += 11;
			break;
		}
		// The interval may dictate a different number of semitones than the "natural" M or P
		// Find this number...If it's within 1 or 2 it may have a canonical name like m, d or a
		// Otherwise display how many semitones away from the M or P the interval is
		int offset{ interval.getSemitones() - naturalSemitones };

		if ((offset < -2) || (offset == -2 && perfect)) {
			if (perfect)
				os << "(P";
			else
				os << "(M";
			os << offset << ")";
		}
		else if ((offset == -2 && !perfect) || (offset == -1 && perfect))
			os << "d";
		else if (offset == -1 && !perfect)
			os << "m";
		else if (offset == 0 && perfect)
			os << "P";
		else if (offset == 0 && !perfect)
			os << "M";
		else if (offset == 1)
			os << "a";
		else if (offset > 1) {
			if (perfect)
				os << "(P";
			else
				os << "(M";
			os << "+" << offset << ")";
		}

		os << basicDistance + 1;

		return os;
	}

}
