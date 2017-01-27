/*
 * VertexDefinitionManager.h
 *
 *  Created on: 02-Dec-2016
 *      Author: gsarwal
 */

#ifndef INCLUDE_VERTEXDEFINITIONMANAGER_H_
#define INCLUDE_VERTEXDEFINITIONMANAGER_H_
#include "afx.h"
#include "VertexDeclarations.h"
#include "Program.h"
namespace gtfx {

class VertexDefinitionManager {
public:
	VertexDefinitionManager();
	virtual ~VertexDefinitionManager();
	static void CreateVertexDefinitions();
	static const VertexDefinition& DetermineSuitableVertexFormat(Program* program);

	static VertexAttribute vaPosition;
	static VertexAttribute vaColor;
	static VertexAttribute vaTexture0;
	static VertexAttribute vaTexture1;
	static VertexAttribute vaTexture2;
	static VertexAttribute vaTexture3;
	static VertexAttribute vaTexture4;
	static VertexAttribute vaTexture5;
	static VertexAttribute vaTexture6;
	static VertexAttribute vaTexture7;
	static VertexAttribute vaTangent;
	static VertexAttribute vaNormal;
	static VertexAttribute vaBinormal;

	static VertexDefinition vdVertexOnly;
	static VertexDefinition vdVertexColor;
	static VertexDefinition vdVertexColorNormal;
	static VertexDefinition vdVertexColorNormalTexture;
	static VertexDefinition vdVertexNormalTexture;				/** minimum **/
	static VertexDefinition vdUIElements;						/** for UI elements **/

};

} /* namespace gtfx */

#endif /* INCLUDE_VERTEXDEFINITIONMANAGER_H_ */
