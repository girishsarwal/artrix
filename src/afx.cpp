#include "afx.h"

uint8_t safe_create_dir(const char *folder){
	const size_t len = strlen(folder);
	    char _path[PATH_MAX];
	    char *p;
	    errno = 0;
	    if (len > sizeof(_path)-1) {
	        errno = ENAMETOOLONG;
	        return -1;
	    }
	    strcpy(_path, folder);
	    for (p = _path + 1; *p; p++) {
	        if (*p == '/') {
	            *p = '\0';

	            if (mkdir(_path, S_IRWXU) != 0) {
	                if (errno != EEXIST)
	                    return -1;
	            }
	            *p = '/';
	        }
	    }

	    if (mkdir(_path, S_IRWXU) != 0) {
	        if (errno != EEXIST)
	            return -1;
	    }

}


std::ostream& operator<<(std::ostream& stream, const glm::vec3& vec) {
	stream << "\n<vec x=\"" << vec.x << "\" y=\"" << (vec.y) << "\" z=\"" << (vec.z) << "\"></vec>";
    return stream;
}

const glm::vec3 vec3fromXmlNode(tinyxml2::XMLNode* node) {
	glm::vec3 vector (0.0f, 0.0f, 0.0f);
	tinyxml2::XMLElement* element = node->ToElement();
	if(NULL != element){
		vector.x = atof(element->Attribute("x"));
		vector.y = atof(element->Attribute("y"));
		vector.z = atof(element->Attribute("z"));
	}
	return vector;
}
