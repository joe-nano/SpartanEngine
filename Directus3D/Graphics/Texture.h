/*
Copyright(c) 2016 Panos Karabelas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

//= INCLUDES =============================
#include "../Graphics/D3D11/D3D11Shader.h"
//========================================

#define NULL_TEXTURE_ID "-1"
#define TEXTURE_PATH_UNKNOWN "-1"

enum TextureType
{
	Albedo,
	Roughness,
	Metallic,
	Normal,
	Height,
	Occlusion,
	Emission,
	Mask,
	CubeMap,
};

class Texture
{
public:
	Texture();
	~Texture();

	//= IO ============================================================
private:
	void Serialize() const;
	void Deserialize();
public:
	void SaveToFile(std::string filePath);
	bool LoadFromImageFile(const std::string& filePath);
	bool LoadFromImageFile(std::string path, TextureType expectedType);
	//=================================================================

	//= PROPERTIES ===============================================================================
	std::string GetID() { return m_ID; };

	std::string GetName() { return m_name; }
	void SetName(const std::string& name) { m_name = name; }

	std::string GetFilePath() { return m_filePath; };
	void SetFilePath(const std::string& filepath) { m_filePath = filepath; }
	
	int GetWidth() { return m_width; }
	void SetWidth(int width) { m_width = width; }
	
	int GetHeight() { return m_height; }
	void SetHeight(int height) { m_height = height; }

	TextureType GetType() { return m_type; }
	void SetType(TextureType type) { m_type = type; }

	bool GetGrayscale() { return m_grayscale; }
	void SetGrayscale(bool grayscale) { m_grayscale = grayscale; }
	
	bool GetTransparency() { return m_transparency; }
	void SetTransparency(bool transparency) { m_transparency = transparency; }

	ID3D11ShaderResourceView* GetID3D11ShaderResourceView() { return m_shaderResourceView; }
	void SetID3D11ShaderResourceView(ID3D11ShaderResourceView* srv) { m_shaderResourceView = srv; }
	//=============================================================================================
private:
	std::string m_ID;
	std::string m_name;
	std::string m_filePath;
	int m_width;
	int m_height;
	TextureType m_type;
	bool m_grayscale;
	bool m_transparency;
	bool m_alphaIsTransparency;	
	ID3D11ShaderResourceView* m_shaderResourceView;
};
