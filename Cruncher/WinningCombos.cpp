#include "WinningCombos.h"
#include "pugixml.hpp"
#include "../Utils/Log.h"
#include <string>
#include "WinningCombo.h"

Cruncher::WinningCombos::WinningCombos(const std::string& filePath)
	: m_filePath(filePath)
{
}

Cruncher::WinningCombos::~WinningCombos()
{
}

void Cruncher::WinningCombos::Load()
{
	auto log = Utils::Log::Get("WinningCombos");

	if (m_filePath.size() == 0)
	{
		std::string msg = "Filename must be set before loading WinningCombo xml file";
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
		throw msg;

#ifdef DEBUG		
		MessageBox(nullptr, msg.c_str(), nullptr, 0);
#endif
	}

	auto WinningCombos = doc.child("WinningCombos");

	for (auto combo : WinningCombos.children("WinningCombo"))
	{
		auto winningCombo = std::make_shared<WinningCombo>();
		winningCombo->AmountsPerWin = combo.attribute("AmountsPerWin").value();
		winningCombo->Freespins = combo.attribute("Freespins").as_int();
		winningCombo->LinesWon = combo.attribute("LinesWon").value();
		winningCombo->MonetizedWin = combo.attribute("MonetizedWin").as_int();
		winningCombo->Reels = combo.attribute("Reels").value();
		winningCombo->SymbolCountForWin = combo.attribute("SymbolCountForWin").value();
		winningCombo->SymbolForWin = combo.attribute("SymbolForWin").value();
		winningCombo->Win = combo.attribute("Win").as_int();

		auto progressive = combo.attribute("ProgressiveNumber");
		if (progressive)
		{
			winningCombo->ProgressiveNumber = progressive.as_int();
		}

		m_combos.insert({ winningCombo->Win, winningCombo });
	}
}
