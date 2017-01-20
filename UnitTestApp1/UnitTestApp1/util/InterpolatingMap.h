#include "pch.h"
#include <map>
#include "util/InverseInterpolable.h"
#include "util/Interpolable.h"

template <class K, class V>
class InterpolatingMap : public std::map<K, V> {
public:
	InterpolatingMap(size_t maximumSize) {
		m_max = maximumSize;
	}

	InterpolatingMap() {
		m_max = 0;
	}

	V put(K key, V value) {
		if (m_max > 0 && m_max <= size()) {
			auto first = begin();
			erase(first);
		}

		emplace(key, value);

		return value;
	}

	V getInterpolated(K key) {
		auto gotval = find(key);
		if (gotval == end()) {
			auto topBound = upper_bound(key);
			auto bottomBound = lower_bound(key);
			bottomBound--;

			if (topBound == end() && bottomBound == end()) {
				return end()->second;
			}
			else if (topBound == end()) {
				return bottomBound->second;
			}
			else if (bottomBound == end()) {
				return topBound->second;
			}

			V topElem = topBound->second;
			V bottomElem = bottomBound->second;
			return bottomElem.interpolate(topElem, bottomBound->first.inverseInterpolate(topBound->first, key));
		}
		else {
			return gotval->second;
		}
	}

private:	
	size_t m_max;
};