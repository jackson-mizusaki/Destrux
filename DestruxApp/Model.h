#pragma once
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Globals.h"
#include "VolumetricMesh.h"

class Model
{
public:
	std::vector<Mesh> meshes;
	std::string directory;
private:
	void loadModel(std::string const& path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);

};

