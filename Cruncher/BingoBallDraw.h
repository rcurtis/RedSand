#pragma once
#include <memory>
#include <vector>

namespace Cruncher
{
	class IRandom;
	class BingoBallDraw
	{
		friend class Cruncher;

	public:
		explicit BingoBallDraw(std::shared_ptr<IRandom> random);
		BingoBallDraw();
		~BingoBallDraw();

		void SetBalls(int upperLimitInclusive);
		void SetBalls(std::vector<int> dummyBallDraw);

		const std::vector<int>& GetBalls() const;

	private:
		std::shared_ptr<IRandom> m_random;
		std::vector<int> m_balls;
	};

}
