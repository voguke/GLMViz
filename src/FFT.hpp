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

// Include FFTW3
#include <fftw3.h>

#include <vector>
#include <math.h>
#include <stdint.h>
#include <algorithm>

#include "Buffer.hpp"

class FFT {
	public:
		FFT(const size_t);
		// disable copy construction
		FFT(const FFT&) = delete;

		// allow move construction
		FFT(FFT&&);
		FFT& operator=(FFT&&) = default;
		~FFT();

		template<typename T> void calculate(Buffer<T>&);
		void resize(const size_t);

		size_t max_bin(const size_t, const size_t);
		std::vector<float> magnitudes(const float);

		fftwf_complex* output;
	private:
		float* input;
		fftwf_plan plan;
		size_t size;

		void calculate_window(const size_t);
		std::vector<float> window;
};
