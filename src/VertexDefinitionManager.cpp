/*
 * VertexDefinitionManager.cpp
 *
 *  Created on: 02-Dec-2016
 *      Author: gsarwal
 */


#include "VertexDefinitionManager.h"
namespace gtfx {

VertexDefinitionManager::VertexDefinitionManager() {
	// TODO Auto-generated constructor stub

}

VertexDefinitionManager::~VertexDefinitionManager() {
	// TODO Auto-generated destructor stub
}

void VertexDefinitionManager::CreateVertexDefinitions() {
	vdVertexOnly.AddVertexAttribute(&vaPosition);

	vdVertexColor.AddVertexAttribute(&vaPosition);
	vdVertexColor.AddVertexAttribute(&vaColor);

	vdVertexColorNormal.AddVertexAttribute(&vaPosition);
	vdVertexColorNormal.AddVertexAttribute(&vaColor);
	vdVertexColorNormal.AddVertexAttribute(&vaNormal);

	vdVertexColorNormalTexture.AddVertexAttribute(&vaPosition);
	vdVertexColorNormalTexture.AddVertexAttribute(&vaColor);
	vdVertexColorNormalTexture.AddVertexAttribute(&vaTexture0);
	vdVertexColorNormalTexture.AddVertexAttribute(&vaNormal);

	vdVertexNormalTexture.AddVertexAttribute(&vaPosition);
	vdVertexNormalTexture.AddVertexAttribute(&vaNormal);
	vdVertexNormalTexture.AddVertexAttribute(&vaTexture0);

	vdUIElements.AddVertexAttribute(&vaPosition);
	vdUIElements.AddVertexAttribute(&vaTexture0);

}


VertexAttribute VertexDefinitionManager::vaPosition = VertexAttribute(POSITION, 3, 4);
VertexAttribute VertexDefinitionManager::vaColor = VertexAttribute(COLOR, 4, 4);
VertexAttribute VertexDefinitionManager::vaTexture0 = VertexAttribute(TEXTURE0, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture1 = VertexAttribute(TEXTURE1, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture2 = VertexAttribute(TEXTURE2, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture3 = VertexAttribute(TEXTURE3, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture4 = VertexAttribute(TEXTURE4, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture5 = VertexAttribute(TEXTURE5, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture6 = VertexAttribute(TEXTURE6, 2, 4);
VertexAttribute VertexDefinitionManager::vaTexture7 = VertexAttribute(TEXTURE7, 2, 4);
VertexAttribute VertexDefinitionManager::vaTangent = VertexAttribute(TANGENT, 3, 4);
VertexAttribute VertexDefinitionManager::vaNormal = VertexAttribute(NORMAL, 3, 4);
VertexAttribute VertexDefinitionManager::vaBinormal = VertexAttribute(BINORMAL, 3, 4);

VertexDefinition VertexDefinitionManager::vdVertexOnly = VertexDefinition();
VertexDefinition VertexDefinitionManager::vdVertexColor = VertexDefinition();
VertexDefinition VertexDefinitionManager::vdVertexColorNormal = VertexDefinition();
VertexDefinition VertexDefinitionManager::vdVertexColorNormalTexture = VertexDefinition();
VertexDefinition VertexDefinitionManager::vdVertexNormalTexture = VertexDefinition();				/** minimum **/
VertexDefinition VertexDefinitionManager::vdUIElements = VertexDefinition();						/** for UI elements **/

const VertexDefinition& VertexDefinitionManager::DetermineSuitableVertexFormat(
		Program* program) {
	return vdVertexNormalTexture;
}

} /* namespace gtfx */
