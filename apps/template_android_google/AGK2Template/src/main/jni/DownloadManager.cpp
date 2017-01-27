/*
 * DownloadManager.cpp
 *
 *  Created on: 11-Nov-2016
 *      Author: gsarwal
 */

#include "DownloadManager.h"
using namespace AGK;
namespace gtfx {
DownloadManager::DownloadManager() {
}

DownloadManager::~DownloadManager() {
}
DownloadManager* DownloadManager::GetInstance(){
	if(!m_pInstance){
		m_pInstance = new DownloadManager();
	};
	return m_pInstance;
};

bool DownloadManager::Initialize(const std::string& host, const std::string& root){
	mHost = host;
	mLocalWriteFolder = root;   /** this will be made inside the write folder for agk **/
//	printf("\n+--------------------DOWNLOAD MANAGER----------------------+");
//	printf("\nInitializing from %s%s\n", mHost.c_str(), mRoot.c_str());

	return true;
};

void DownloadManager::Shutdown(){
    agk::DeleteHTTPConnection(mHttpConnection);
};

DownloadManager* DownloadManager::m_pInstance = NULL;

void DownloadManager::FromURI(const std::string& host, const std::string& file, bool inflateArchive) {
	/** TODO use AGK file functions to see if file exists, it will not be redownloaded **/
	Download(host, file, mLocalWriteFolder + file, inflateArchive);
}

void DownloadManager::FromMediaServer(const std::string& file, bool inflateArchive) {
	FromURI(mHost, file, inflateArchive);
}

void DownloadManager::Download(const std::string& host, const std::string& url, const std::string& localFileName, bool inflateArchive) {
    mHttpConnection = agk::CreateHTTPConnection();
    agk::SetHTTPHost(mHttpConnection, host.c_str(), 0);
    if(0 == mHttpConnection) {
        //ALOGE("Cannot Create http connection");
        return;
    }
    agk::GetHTTPFile(mHttpConnection, url.c_str(), localFileName.c_str());
    while(agk::GetHTTPFileComplete(mHttpConnection) != 0) {
        agk::Sync();    /** make sure our UI is responsive **/
    }
    agk::CloseHTTPConnection(mHttpConnection);
    agk::DeleteHTTPConnection(mHttpConnection);
}


bool DownloadManager::InflateArchive(const std::string& from, const std::string& to) {
    return true;
}
}
