#include "LosingCombos.h"
#include "pugixml.hpp"
#include "LosingCombo.h"
#include <string>
#include "../Utils/Log.h"

Cruncher::LosingCombos::LosingCombos(const std::string& filePath)
	: m_filePath(filePath)
{
}

Cruncher::LosingCombos::~LosingCombos()
{
}

void Cruncher::LosingCombos::Load()
{
	auto log = Utils::Log::Get("LosingCombos");

	if (m_filePath.size() == 0)
	{
		std::string msg = "Filename must be set before loading LosingCombos xml file";
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

	auto losingCombos = doc.child("LosingCombos");
	for (auto combo : losingCombos)
	{
		auto losingCombo = std::make_shared<LosingCombo>();
		losingCombo->Reels = combo.attribute("Reels").value();

		m_combos.push_back(std::move(losingCombo));
	}
}
