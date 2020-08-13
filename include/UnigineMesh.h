/* Copyright (C) 2005-2020, UNIGINE. All rights reserved.
 *
 * This file is a part of the UNIGINE 2 SDK.
 *
 * Your use and / or redistribution of this software in source and / or
 * binary form, with or without modification, is subject to: (i) your
 * ongoing acceptance of and compliance with the terms and conditions of
 * the UNIGINE License Agreement; and (ii) your inclusion of this notice
 * in any version of this software that you use or redistribute.
 * A copy of the UNIGINE License Agreement is available by contacting
 * UNIGINE. at http://unigine.com/
 */

// DO NOT EDIT DIRECTLY. This is an auto-generated file. Your changes will be lost.

#pragma once

#include "UniginePtr.h"
#include "UnigineBounds.h"
#include "UnigineVector.h"
#include "UnigineEllipsoid.h"

namespace Unigine
{


class UNIGINE_API Mesh : public APIInterface
{
public:
	static Ptr<Mesh> create();
	static Ptr<Mesh> create(const char *name);
	static Ptr<Mesh> create(const Ptr<Mesh> &mesh);
	void assignFrom(const Ptr<Mesh> &mesh);
	int info(const char *name) const;
	int load(const char *name);
	int save(const char *name) const;
	void clear();
	int flipYZ(int surface = -1);
	int flipTangent(int surface = -1);
	int createBounds(int surface = -1);
	int removeIndices(int surface = -1);
	int createIndices(int surface = -1);
	int optimizeIndices(int flags, int surface = -1);
	int createTangents(int surface = -1, int target = -1);
	int createTangents(float angle, const Vector< int > &surfaces);
	int createNormals(int surface = -1, int target = -1);
	int createNormals(float angle, int surface = -1, int target = -1);
	int getNumBones() const;
	int findBone(const char *name) const;
	int addBone(const char *name = 0, int parent = -1);
	void setBoneName(int bone, const char *name);
	const char *getBoneName(int bone) const;
	void setBoneParent(int bone, int parent);
	int getBoneParent(int bone) const;
	void setBoneTransform(int bone, const Math::mat4 &transform);
	Math::mat4 getBoneTransform(int bone) const;
	int setBoneTransforms(const Vector< Math::mat4 > &transforms, int animation = -1, int frame = 0);
	int getBoneTransforms(Vector< Math::mat4 > &transforms, int animation = -1, int frame = 0) const;
	int getNumAnimations() const;
	int findAnimation(const char *name) const;
	void sortAnimations();
	int addAnimation(const char *name = 0);
	void setAnimationName(int animation, const char *name);
	const char *getAnimationName(int animation) const;
	void setAnimationBones(int animation, const Vector< short > &bones);
	void getAnimationBones(int animation, Vector< short > &bones) const;
	void setNumAnimationFrames(int animation, int num);
	int getNumAnimationFrames(int animation) const;
	void setAnimationFrame(int animation, int num, const Vector< Math::mat4 > &frames);
	void getAnimationFrame(int animation, int num, Vector< Math::mat4 > &frames) const;
	void setAnimationFrame(int animation, int num, const Vector< Math::vec3 > &xyz, const Vector< Math::quat > &rot, const Vector< Math::vec3 > &scale);
	void getAnimationFrame(int animation, int num, Vector< Math::vec3 > &xyz, Vector< Math::quat > &rot, Vector< Math::vec3 > &scale) const;
	int getNumSurfaces() const;
	int findSurface(const char *name) const;
	void sortSurfaces();
	int addSurface(const char *name = 0);
	void setSurfaceName(int surface, const char *name);
	const char *getSurfaceName(int surface) const;
	void setNumSurfaceTargets(int surface, int num);
	int getNumSurfaceTargets(int surface) const;
	void setSurfaceTargetName(int surface, int target, const char *name);
	const char *getSurfaceTargetName(int surface, int target) const;
	int findSurfaceTarget(int surface, const char *name) const;
	int createIntersection(int surface = -1);
	int getIntersection(const Math::vec3 &p0, const Math::vec3 &p1, Math::vec3 * ret_point, Math::vec3 * ret_normal, int * ret_index, int surface, int target = 0);
	int setSurfaceTransform(const Math::mat4 &transform, int surface = -1, int target = -1);
	int addMeshSurface(const char *v, const Ptr<Mesh> &mesh, int surface, int target = -1);
	int addMeshSurface(int v, const Ptr<Mesh> &mesh, int surface, int target = -1);
	int addEmptySurface(const char *name, int num_vertex, int num_indices);
	int addSurfaceTarget(int surface, const char *name = 0);
	int addBoxSurface(const char *name, const Math::vec3 &size);
	int addPlaneSurface(const char *name, float width, float height, float step);
	int addSphereSurface(const char *name, float radius, int stacks, int slices);
	int addCapsuleSurface(const char *name, float radius, float height, int stacks, int slices);
	int addCylinderSurface(const char *name, float radius, float height, int stacks, int slices);
	int addPrismSurface(const char *name, float size_0, float size_1, float height, int sides);
	int addIcosahedronSurface(const char *name, float radius);
	int addDodecahedronSurface(const char *name, float radius);
	int getNumCVertex(int surface) const;
	int getNumTVertex(int surface) const;
	int remapCVertex(int surface);
	void setNumWeights(int size, int surface);
	int getNumWeights(int surface) const;
	void setWeightCount(int num, int count, int surface);
	int getWeightCount(int num, int surface) const;
	void setWeightBones(int num, const Math::ivec4 &bones, int surface);
	Math::ivec4 getWeightBones(int num, int surface) const;
	void setWeightWeights(int num, const Math::vec4 &weights, int surface);
	Math::vec4 getWeightWeights(int num, int surface) const;
	void setNumVertex(int size, int surface, int target = 0);
	int getNumVertex(int surface, int target = 0) const;
	void addVertex(const Math::vec3 &vertex, int surface, int target = 0);
	void setVertex(int num, const Math::vec3 &vertex, int surface, int target = 0);
	Math::vec3 getVertex(int num, int surface, int target = 0) const;
	void setNumTexCoords0(int size, int surface);
	int getNumTexCoords0(int surface) const;
	void addTexCoord0(const Math::vec2 &texcoord, int surface);
	void setTexCoord0(int num, const Math::vec2 &texcoord, int surface);
	Math::vec2 getTexCoord0(int num, int surface) const;
	void setNumTexCoords1(int size, int surface);
	int getNumTexCoords1(int surface) const;
	void addTexCoord1(const Math::vec2 &texcoord, int surface);
	void setTexCoord1(int num, const Math::vec2 &texcoord, int surface);
	Math::vec2 getTexCoord1(int num, int surface) const;
	void setNumNormals(int size, int surface, int target = 0);
	int getNumNormals(int surface, int target = 0) const;
	void addNormal(const Math::vec3 &normal, int surface, int target = 0);
	void setNormal(int num, const Math::vec3 &normal, int surface, int target = 0);
	Math::vec3 getNormal(int num, int surface, int target = 0) const;
	void setNumTangents(int size, int surface, int target = 0);
	int getNumTangents(int surface, int tangent = 0) const;
	void addTangent(const Math::quat &tangent, int surface, int target = 0);
	void setTangent(int num, const Math::quat &tangent, int surface, int target = 0);
	Math::quat getTangent(int num, int surface, int target = 0) const;
	void setNumColors(int size, int surface);
	int getNumColors(int surface) const;
	void addColor(const Math::vec4 &color, int surface);
	void setColor(int num, const Math::vec4 &color, int surface);
	Math::vec4 getColor(int num, int surface) const;
	void setNumCIndices(int size, int surface);
	int getNumCIndices(int surface) const;
	void addCIndex(int index, int surface);
	void setCIndex(int num, int index, int surface);
	int getCIndex(int num, int surface) const;
	void setNumTIndices(int size, int surface);
	int getNumTIndices(int surface) const;
	void addTIndex(int index, int surface);
	void setTIndex(int num, int index, int surface);
	int getTIndex(int num, int surface) const;
	void setNumIndices(int size, int surface);
	int getNumIndices(int surface) const;
	void addIndex(int index, int surface);
	void setIndex(int num, int index, int surface);
	int getIndex(int num, int surface) const;
	BoundBox getBoundBox() const;
	BoundBox getBoundBox(int surface) const;
	BoundSphere getBoundSphere() const;
	BoundSphere getBoundSphere(int surface) const;
	void setBoundBox(const BoundBox & bb, int surface);
	void setBoundBox(const BoundBox & bb);
	void setBoundSphere(const BoundSphere & bs, int surface);
	void setBoundSphere(const BoundSphere & bs);

	enum
	{
		VERTEX_CACHE = 1 << 0,	// vertex cache optimization
		BACK_TO_FRONT = 1 << 1,	// back to front order
		NUM_WEIGHTS = 4,	// vertex cache optimization
	};
};
typedef Ptr<Mesh> MeshPtr;

} // namespace Unigine
