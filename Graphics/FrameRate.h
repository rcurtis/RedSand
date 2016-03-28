#pragma once

#include <vector>

namespace Graphics
{

	class FrameRate
	{
	public:
		explicit FrameRate(int numberPoints);
		~FrameRate();

		void AddDataPoint(float point);
		float GetAverage() const;

		friend std::ostream& operator<<(std::ostream& os, const FrameRate& obj);		

	private:
		int m_numberPointsToHold;
		std::vector<float> m_points;
	};

	
}
