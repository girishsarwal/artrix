/*
 * FTFontManager.h
 *
 *  Created on: 19-Jan-2017
 *      Author: gsarwal
 */

#ifndef INCLUDE_FTFONTMANAGER_H_
#define INCLUDE_FTFONTMANAGER_H_
#include "KeyedManager.h"
namespace gtfx {

class FTFontManager :
	KeyedManager<int> {
private:
	int m_iNumFonts;
	static FTFontManager* m_pInstance;
	std::map<std::string, uint>	m_Fonts;
	uint *m_arrFonts;
	std::string mRoot;
	std::string mManifest;
public:
	static FTFontManager* GetInstance();
	FTFontManager();
	virtual ~FTFontManager();
	bool loadAllFonts();
	bool initialize(const std::string& host, const std::string& root);
	void shutdown();
	void Use(const std::string&);
};

} /* namespace gtfx */

#endif /* INCLUDE_FTFONTMANAGER_H_ */


