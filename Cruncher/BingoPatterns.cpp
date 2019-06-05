#include "BingoPatterns.h"
#include "pugixml.hpp"
#include "../Utils/Log.h"
#include "BingoPattern.h"

Cruncher::BingoPatterns::BingoPatterns(const std::string& filePath)
	: m_filePath(filePath)
{
}


Cruncher::BingoPatterns::~BingoPatterns()
{
}

void Cruncher::BingoPatterns::Load()
{
	auto log = Utils::Log::Get("BingoPatterns");

	if (m_filePath.size() == 0)
	{
		std::string msg = "Filename must be set before loading BingoPatterns xml file";
		log->critical(msg);
		throw msg;
	}

	log->info() << "Loading file: " << m_filePath;

	pugi::xml_document doc;
	auto result = doc.load_file(m_filePath.c_str());

	if (result.status != pugi::status_ok)
	{
		auto msg = "Failed to parse XML file: " + m_filePath;
		log->critical() << msg;

#ifdef DEBUG		
		MessageBox(nullptr, msg.c_str(), nullptr, 0);
#endif
	}

	auto LosingCombos = doc.child("BingoInfo");
	m_progressiveBase = LosingCombos.attribute("ProgressiveBase").as_int();

	for (auto patternXml : LosingCombos.children("Entry"))
	{
		auto pattern = std::make_unique<BingoPattern>();
		pattern->m_ballsToMatch = patternXml.attribute("BallsToMatch").as_int();
		pattern->m_creditsPaidMaxBet = patternXml.attribute("CreditsPaidMaxBet").as_int();
		pattern->m_creditsPaidSingleBet = patternXml.attribute("CreditsPaidSingleBet").as_int();
		pattern->m_freespins = patternXml.attribute("Freespins").as_int();
		pattern->m_monetizedWin = patternXml.attribute("MonetizedWin").as_int();
		pattern->m_pattern = patternXml.attribute("BingoPattern").as_int();
		pattern->m_progressiveNumber = patternXml.attribute("ProgressiveNumber").as_int();
		
		m_patterns.push_back(move(pattern));
	}
}
