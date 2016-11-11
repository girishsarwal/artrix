/*
 * DownloadManager.h
 *
 *  Created on: 11-Nov-2016
 *      Author: gsarwal
 */
#pragma once
#include "afx.h"
#ifndef DOWNLOADMANAGER_H_
#define DOWNLOADMANAGER_H_

class DownloadManager {
public:
	virtual ~DownloadManager();
	void FromURI(const string& url, const string& file);
	void FromMediaServer(const string& url, const string& archive);

	static DownloadManager* getInstance();
	bool initialize(const string& host, const string& root);
	void shutdown();

private:
	string mHost;
	string mRoot;
	CURL* mpCurl;
	size_t mNumBytesDownloaded;
	static DownloadManager* m_pInstance;

	DownloadManager();
	void Download(const string& url, const string& archive);
	static size_t __write_data(void *ptr, size_t size, size_t nmemb, void *stream);
};

#endif /* DOWNLOADMANAGER_H_ */
