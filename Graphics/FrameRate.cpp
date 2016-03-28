#include "FrameRate.h"
#include <numeric>
#include <string>

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

	float FrameRate::GetAverage() const
	{
		auto sum = std::accumulate(m_points.begin(), m_points.end(), 0);
		return sum / m_points.size();
	}

	std::ostream& operator<<(std::ostream& os, const FrameRate& obj)
	{
		return os << "Framerate: " << std::to_string(obj.GetAverage());
	}
}
