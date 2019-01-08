///////////////////////////////////////////////////////////////////////////////
// subsequence.hpp
//
// Two algorithms for solving the longest increasing subsequence problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <sstream>
#include <vector>

using sequence = std::vector<int>;

std::string sequence_to_string(const sequence& seq) {
	std::stringstream ss;
	ss << "[";
	bool first = true;
	for (auto& x : seq) {
		if (!first) {
			ss << ", ";
		}
		ss << x;
		first = false;
	}
	ss << "]";
	return ss.str();
}

sequence random_sequence(size_t size, unsigned seed, int max_element) {

	assert(max_element >= 0);
	sequence result;
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> dist(0, max_element);

	for (size_t i = 0; i < size; ++i) {
		result.push_back(dist(gen));
	}
	return result;
}

bool is_increasing(const sequence& A) {
	for (size_t i = 1; i < A.size(); ++i) {
		if (A[i - 1] > A[i]) {
			return false;
		}
	}
	return true;
}

sequence longest_increasing_end_to_beginning(const sequence& A) {

	const size_t n = A.size();
	std::vector<size_t> H(n, 0);
	for (signed int i = n - 2; i >= 0; i--) {
		for (size_t j = i + 1; j < n; j++) {
			if ((A[j]>A[i]) && (H[j]) >= H[i])
			{
				H[i] = H[j] + 1;
			}
		}
	}

	auto max = *std::max_element(H.begin(), H.end()) + 1;
	std::vector<int> R(max);

	size_t index = max - 1, j = 0;
	for (size_t i = 0; i < n; ++i) {
		if (H[i] == index) {
			R[j] = A[i];
			index--;
			j++;
		}

	}

	return sequence(R.begin(), R.begin() + max);
}

sequence longest_increasing_powerset(const sequence& A) {
	const size_t n = A.size();
	sequence best;
	std::vector<size_t> stack(n + 1, 0);
	size_t k = 0;
	while (true) {

		if (stack[k] < n) {
			stack[k + 1] = stack[k] + 1;
			++k;
		}
		else {
			stack[k - 1]++;
			k--;
		}

		if (k == 0) {
			break;
		}

		sequence candidate;
		for (size_t i = 1; i <= k; ++i) {
			candidate.push_back(A[stack[i] - 1]);
		}

		if ((is_increasing(candidate)) && (candidate.size() > best.size())) {
			for (unsigned int i = 0; i < candidate.size(); i++) {
				if (i >= best.size()) {
					best.push_back(candidate[i]);
				}
				best[i] = candidate[i];
			}

		}
	}

	return best;
}
