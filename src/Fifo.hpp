/*
 *	Copyright (C) 2016  Hannes Haberl
 *
 *	This file is part of GLMViz.
 *
 *	GLMViz is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	GLMViz is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with GLMViz.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include <string>
#include <fstream>

#include "Input.hpp"

#define DELAY_MIN 500
#define DELAY_MAX 5000

class Fifo : public Input{
	public:
		Fifo(const std::string&, const size_t);
		~Fifo(){};
		bool is_open() const;
		void read(Buffer<int16_t>&) const;
		void read(std::vector<Buffer<int16_t>>&) const;
	private:
		mutable std::ifstream file;
		mutable std::unique_ptr<int16_t[]> buf;
		mutable int delay = 100;
		size_t samples;
};
