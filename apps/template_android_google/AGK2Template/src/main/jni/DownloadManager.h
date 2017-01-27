/*
 * DownloadManager.h
 *
 *  Created on: 11-Nov-2016
 *      Author: gsarwal
 */
#ifndef DOWNLOADMANAGER_H_
#define DOWNLOADMANAGER_H_
#include "artrix.h"
#include "agk.h"
#include <string>
namespace gtfx {
class DownloadManager {
public:
	virtual ~DownloadManager();
	void FromURI(const std::string& url, const std::string& file, bool inflateArchive = false);
	void FromMediaServer(const std::string& archive, bool inflateArchive = false);
	bool InflateArchive(const std::string& from, const std::string& to);

	static DownloadManager* GetInstance();
	bool Initialize(const std::string& host, const std::string& root);
	void Shutdown();

private:
	std::string mHost;
	std::string mLocalWriteFolder;
	uint8_t mHttpConnection;
	static DownloadManager* m_pInstance;

	DownloadManager();
	void Download(const std::string& host, const std::string& url, const std::string& localFileName, bool inflateArchive);
};
}
#endif /* DOWNLOADMANAGER_H_ */
