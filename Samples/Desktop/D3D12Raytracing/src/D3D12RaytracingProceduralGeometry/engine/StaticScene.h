#pragma once

#include "Ray.h"
#include "Geometry.h"
#include "RootSignature.h"
#include "HitGroup.h"
#include "ShaderTable.h"
#include <vector>
#include <unordered_map>
#include <string>

namespace RtxEngine
{
	class StaticScene
	{
	public:
		// Add scene components.
		void addRay(const string& name, const RayPtr& ray);
		void addGeometry(const string& name, const GeometryPtr& geometry);
		void addGlobalSignature(const RootSignaturePtr& rootSignature);
		void addLocalSignature(const string& name, const RootSignaturePtr& rootSignature);
		void addHitGroup(const string& name, const HitGroupPtr& hitGroup);

		const GeometryMap& getGeometry() const { return m_geometry; }
		const HitGroupMap& getHitGroups() const { return m_hitGroups; }
		RootSignature& getGlobalSignature() const { return *m_globalSignature; }
		const RootSignatureMap& getLocalSignatures() const { return m_localSignatures; }
		UINT getMaxRecursion() const { return m_maxRecursion; }

		// Build the scene.
		void build();

	private:
		// Scene entities.
		RayMap m_rays;
		GeometryMap m_geometry;
		
		// Root signatures.
		RootSignaturePtr m_globalSignature;
		RootSignatureMap m_localSignatures;
		
		// Hitgroups.
		HitGroupMap m_hitGroups;

		UINT m_maxRecursion = 3;
	};

	using StaticScenePtr = shared_ptr<StaticScene>;
}