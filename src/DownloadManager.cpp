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

bool DownloadManager::initialize(const std::string& host, const std::string& root){
	mHost = host;
	mRoot = root;

	printf("\n+--------------------DOWNLOAD MANAGER----------------------+\n");
	printf("Initializing from %s%s\n", mHost.c_str(), mRoot.c_str());

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

void DownloadManager::FromURI(const std::string& url, const std::string& file, bool inflateArchive) {
	FILE* fp = fopen(file.c_str(), "r");
	if(NULL != fp) {
		printf("File exists. will not be downloaded. Remove file to force download.\n");
		fclose(fp);
		return;
	}
	Download(url, file, inflateArchive);
}

void DownloadManager::FromMediaServer(const std::string& url, const std::string& file, bool inflateArchive) {
	FromURI(mHost + mRoot + url, file, inflateArchive);
}

void DownloadManager::Download(const std::string& url, const std::string& file, bool inflateArchive) {
	FILE *fileHandle = NULL;
	std::string tmpfileName = "/tmp/.artrixdlc";
	curl_easy_setopt(mpCurl, CURLOPT_URL, url.c_str());
	if(inflateArchive){
		safe_create_dir(file.c_str());
	}
	fileHandle= fopen(inflateArchive? tmpfileName.c_str() : file.c_str(), "wb");
	if(NULL == fileHandle) {
		printf("There was a problem opening the file at %s", file.c_str());
		return;
	}
	curl_easy_setopt(mpCurl, CURLOPT_WRITEDATA, fileHandle);
	curl_easy_perform(mpCurl);

	fclose(fileHandle);

	if(inflateArchive){
		InflateArchive(inflateArchive? tmpfileName.c_str() : file.c_str(), file.c_str());
	}

	curl_easy_cleanup(mpCurl);
}

size_t DownloadManager::__write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}


bool DownloadManager::InflateArchive(const std::string& from, const std::string& to) {
	struct zip *za;
	struct zip_file *zf;
	struct zip_stat sb;

	char buf[100];

	int err;
	int i, len;
	int fd;
	long long sum;

    if ((za = zip_open(from.c_str(), 0, &err)) == NULL) {
        zip_error_to_str(buf, sizeof(buf), err, errno);
        fprintf(stderr, "%s: can't open zip archive `%s': %s/n", from.c_str(),
            from.c_str(), buf);
        return false;
    }
    safe_create_dir(to.c_str());
    for (i = 0; i < zip_get_num_entries(za, 0); i++) {
        if (zip_stat_index(za, i, 0, &sb) == 0) {
        	len = strlen(sb.name);
        	std::string absolutePath = to + "/" + std::string(sb.name);
            printf("Asset: [%s] - [%llu] - [%u]\n, ", sb.name, sb.size, (unsigned int)sb.mtime);
            if (sb.name[len - 1] == '/') {
                safe_create_dir(absolutePath.c_str());
            } else {
                zf = zip_fopen_index(za, i, 0);
                if (!zf) {
                    exit(100);
                }

                fd = open(absolutePath.c_str(), O_RDWR | O_TRUNC | O_CREAT, 0644);
                if (fd < 0) {
                    exit(101);
                }

                sum = 0;
                while (sum != sb.size) {
                    len = zip_fread(zf, buf, 100);
                    if (len < 0) {
                        exit(102);
                    }
                    write(fd, buf, len);
                    sum += len;
                }
                printf("wrote %llu bytes to %s", sum, absolutePath.c_str());
                close(fd);
                zip_fclose(zf);
            }
        } else {
            printf("File[%s] Line[%d]/n", __FILE__, __LINE__);
        }
    }

    if (zip_close(za) == -1) {
        fprintf(stderr, "%s: can't close zip archive `%s'/n", from.c_str(), from.c_str());
        return false;
    }
    return true;
}
