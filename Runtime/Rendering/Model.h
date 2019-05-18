/*
Copyright(c) 2016-2019 Panos Karabelas

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

//= INCLUDES =====================
#include <memory>
#include <vector>
#include "Material.h"
#include "../RHI/RHI_Definition.h"
#include "../Resource/IResource.h"
#include "../Math/BoundingBox.h"
//================================

namespace Spartan
{
	class ResourceCache;
	class Entity;
	class Mesh;
	class Animation;

	namespace Math
	{
		class BoundingBox;
	}

	class SPARTAN_CLASS Model : public IResource
	{
	public:
		Model(Context* context);
		~Model();

		//= RESOURCE INTERFACE =================================
		bool LoadFromFile(const std::string& file_path) override;
		bool SaveToFile(const std::string& file_path) override;
		//======================================================

		// Sets the entity that represents this model in the scene
		void SetRootentity(const std::shared_ptr<Entity>& entity) { m_root_entity = entity; }
		
		//= GEOMTETRY ==================================================
		void GeometryAppend(
			std::vector<unsigned int>& indices,
			std::vector<RHI_Vertex_PosTexNorTan>& vertices,
			unsigned int* index_offset = nullptr,
			unsigned int* vertex_offset = nullptr
		) const;
		void GeometryGet(
			unsigned int index_offset,
			unsigned int index_count,
			unsigned int vertex_offset, 
			unsigned int vertex_count,
			std::vector<unsigned int>* indices,
			std::vector<RHI_Vertex_PosTexNorTan>* vertices
		) const;
		void GeometryUpdate();
		const Math::BoundingBox& GeometryAabb() const { return m_aabb; }
		//==============================================================

		// Add resources to the model
		void AddMaterial(std::shared_ptr<Material>& material, const std::shared_ptr<Entity>& entity);
		void AddAnimation(std::shared_ptr<Animation>& animation);
		void AddTexture(std::shared_ptr<Material>& material, TextureType texture_type, const std::string& file_path);

		bool IsAnimated() const						{ return m_is_animated; }
		void SetAnimated(const bool is_animated)	{ m_is_animated = is_animated; }

		void SetWorkingDirectory(const std::string& directory);

		std::shared_ptr<RHI_IndexBuffer> GetIndexBuffer() const		{ return m_index_buffer; }
		std::shared_ptr<RHI_VertexBuffer> GetVertexBuffer() const	{ return m_vertex_buffer; }

	private:
		// Load the model from disk
		bool LoadFromEngineFormat(const std::string& file_path);
		bool LoadFromForeignFormat(const std::string& file_path);

		// Geometry
		bool GeometryCreateBuffers();
		float GeometryComputeNormalizedScale() const;
		unsigned int GeometryComputeMemoryUsage() const;

		// The root entity that represents this model in the scene
		std::weak_ptr<Entity> m_root_entity;

		// Geometry
		std::shared_ptr<RHI_VertexBuffer> m_vertex_buffer;
		std::shared_ptr<RHI_IndexBuffer> m_index_buffer;
		std::shared_ptr<Mesh> m_mesh;
		Math::BoundingBox m_aabb;
		unsigned int mesh_count;

		// Material
		std::vector<std::shared_ptr<Material>> m_materials;

		// Animations
		std::vector<std::shared_ptr<Animation>> m_animations;

		// Directories relative to this model
		std::string m_model_directory_model;
		std::string m_model_directory_materials;
		std::string m_model_directory_textures;

		// Misc
		float m_normalized_scale;
		bool m_is_animated;
		ResourceCache* m_resource_manager;
		std::shared_ptr<RHI_Device> m_rhi_device;	
	};
}