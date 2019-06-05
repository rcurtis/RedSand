#include "BingoBallDraw.h"
#include "IRandom.h"

namespace Cruncher
{
	
	BingoBallDraw::BingoBallDraw(std::shared_ptr<IRandom> random)
		:m_random(random)
	{
	}

	BingoBallDraw::BingoBallDraw()
	{
	}

	BingoBallDraw::~BingoBallDraw()
	{
	}

	void BingoBallDraw::Generate(int upperLimitInclusive)
	{
		for (auto i = 0; i < upperLimitInclusive; i++)
		{
			m_balls.push_back(i);
		}

		const auto max = m_balls.size() - 1;
		for (size_t i = 0; i < m_balls.size(); i++)
		{
			auto random = m_random->Range(i, max);
			auto temp = m_balls[i];
			m_balls[i] = m_balls[random];
			m_balls[random] = temp;
		}
	}

	void BingoBallDraw::SetBalls(std::vector<int> dummyBallDraw)
	{
		m_balls = std::vector<int>(dummyBallDraw.size());
		std::copy(dummyBallDraw.begin(), dummyBallDraw.end(), m_balls.begin());
	}

	const std::vector<int>& BingoBallDraw::GetBalls() const
	{
		return m_balls;
	}

	

}