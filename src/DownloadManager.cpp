/*
 * DownloadManager.cpp
 *
 *  Created on: 11-Nov-2016
 *      Author: gsarwal
 */

#include "DownloadManager.h"

DownloadManager::DownloadManager() {
	mpCurl = NULL;
}

DownloadManager::~DownloadManager() {
}
DownloadManager* DownloadManager::getInstance(){
	if(!m_pInstance){
		m_pInstance = new DownloadManager();
	};
	return m_pInstance;
};

bool DownloadManager::initialize(const string& host, const string& root){
	mHost = host;
	mRoot = root;

	printf("+--------------------DOWNLOAD MANAGER----------------------+\n");
	printf("Initializing from %s\n", mRoot.c_str());

	curl_global_init(CURL_GLOBAL_ALL);
	mpCurl= curl_easy_init();
	if(NULL == mpCurl){
		return false;
	}
	curl_easy_setopt(mpCurl, CURLOPT_VERBOSE, 1L);
	curl_easy_setopt(mpCurl, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(mpCurl, CURLOPT_WRITEFUNCTION, DownloadManager::__write_data);
	return true;
};

void DownloadManager::shutdown(){

};

DownloadManager* DownloadManager::m_pInstance = NULL;

void DownloadManager::FromURI(const string& url, const string& file) {
	Download(url, file);
}

void DownloadManager::FromMediaServer(const string& url, const string& file) {
	Download(mHost + mRoot + url, file);

}

void DownloadManager::Download(const string& url, const string& file) {
	FILE *fileHandle = NULL;
	curl_easy_setopt(mpCurl, CURLOPT_URL, url.c_str());
	fileHandle= fopen(file.c_str(), "wb");
	if(NULL == fileHandle) {
		printf("There was a problem opening the file at %s", file.c_str());
		return;
	}
	curl_easy_setopt(mpCurl, CURLOPT_WRITEDATA, fileHandle);
	curl_easy_perform(mpCurl);
	fclose(fileHandle);
	curl_easy_cleanup(mpCurl);
}

size_t DownloadManager::__write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

