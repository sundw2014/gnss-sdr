/*!
 * \file string_converter.h
 * \brief This class interprets the contents of a string and converts it into
 * different types.
 * \author Carlos Aviles, 2010. carlos.avilesr(at)googlemail.com
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2011  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */


#ifndef STRING_CONVERTER_H_
#define STRING_CONVERTER_H_

#include <string>

class StringConverter {

public:
	StringConverter();
	virtual ~StringConverter();

	bool convert(std::string value, bool default_value);
	long convert(std::string value, long default_value);
	int convert(std::string value, int default_value);
	unsigned int convert(std::string value, unsigned int default_value);
	float convert(std::string value, float default_value);
	double convert(std::string value, double default_value);
};

#endif /*STRING_CONVERTER_H_*/