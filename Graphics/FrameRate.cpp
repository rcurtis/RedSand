#include "FrameRate.h"
#include <numeric>

namespace Graphics
{

	FrameRate::FrameRate(int numberPoints)
		:m_numberPointsToHold(numberPoints)
	{
	}

	FrameRate::~FrameRate()
	{
	}

	void FrameRate::AddDataPoint(float point)
	{
		if (m_points.size() == m_numberPointsToHold)
			m_points.erase(m_points.begin());

		m_points.push_back(point);
	}

	float FrameRate::GetAverage()
	{
		auto sum = std::accumulate(m_points.begin(), m_points.end(), 0);
		return sum / m_points.size();
	}
}
