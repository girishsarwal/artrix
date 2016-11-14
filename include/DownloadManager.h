/*
 * DownloadManager.h
 *
 *  Created on: 11-Nov-2016
 *      Author: gsarwal
 */
#ifndef DOWNLOADMANAGER_H_
#define DOWNLOADMANAGER_H_
#include "afx.h"
class DownloadManager {
public:
	virtual ~DownloadManager();
	void FromURI(const std::string& url, const std::string& file, bool inflateArchive = false);
	void FromMediaServer(const std::string& url, const std::string& archive, bool inflateArchive = false);
	bool InflateArchive(const std::string& from, const std::string& to);

	static DownloadManager* getInstance();
	bool initialize(const std::string& host, const std::string& root);
	void shutdown();

private:
	std::string mHost;
	std::string mRoot;
	CURL* mpCurl;
	size_t mNumBytesDownloaded;
	static DownloadManager* m_pInstance;

	DownloadManager();
	void Download(const std::string& url, const std::string& archive, bool inflateArchive = false);
	static size_t __write_data(void *ptr, size_t size, size_t nmemb, void *stream);
};
#define DM DownloadManager::getInstance()
#endif /* DOWNLOADMANAGER_H_ */
