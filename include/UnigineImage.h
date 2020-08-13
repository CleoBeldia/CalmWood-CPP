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

#include "UnigineMathLib.h"
#include "UniginePtr.h"
#include "UnigineStreams.h"

namespace Unigine
{

class Blob;

class UNIGINE_API Image : public APIInterface
{
public:
	static Ptr<Image> create();
	static Ptr<Image> create(const char *name);
	static Ptr<Image> create(const Ptr<Image> &image);
	union Pixeli
	{
		struct
		{
			int r, g, b, a;
		};
		int v[4];
		#ifdef USE_SSE2
			__m128i vec;
		#elif defined(USE_SSE)
			__m128 vec;
		#endif
	};

	// float pixel
	union Pixelf
	{
		struct
		{
			float r, g, b, a;
		};
		float v[4];
		#ifdef USE_SSE
			__m128 vec;
		#endif
	};

	// pixel
	UNIGINE_ALIGNED16(struct)
	Pixel
	{
		UNIGINE_INLINE Pixel() {}
		UNIGINE_INLINE Pixel(int r, int g = 0, int b = 0, int a = 0)
		{
			i.r = r;
			i.g = g;
			i.b = b;
			i.a = a;
		}
		UNIGINE_INLINE Pixel(float r, float g = 0.0f, float b = 0.0f, float a = 0.0f)
		{
			f.r = r;
			f.g = g;
			f.b = b;
			f.a = a;
		}
		union
		{
			Pixeli i;
			Pixelf f;
		};
	};

	enum
	{
		IMAGE_2D = 0,	// 2D image
		IMAGE_3D,	// 3D image
		IMAGE_CUBE,	// Cube image
		IMAGE_2D_ARRAY,	// 2D Array image
		IMAGE_CUBE_ARRAY,	// Cube Array image
	};

	enum
	{
		FORMAT_R8 = 0,	// 8-bits per channel integer formats
		FORMAT_RG8,
		FORMAT_RGB8,
		FORMAT_RGBA8,
		FORMAT_R16,	// 16-bits per channel integer formats
		FORMAT_RG16,
		FORMAT_RGB16,
		FORMAT_RGBA16,
		FORMAT_R16F,	// 16-bits per channel float formats
		FORMAT_RG16F,
		FORMAT_RGB16F,
		FORMAT_RGBA16F,
		FORMAT_R32F,	// 32-bits per channel float formats
		FORMAT_RG32F,
		FORMAT_RGB32F,
		FORMAT_RGBA32F,
		FORMAT_RGB565,	// combined formats
		FORMAT_RGBA4,
		FORMAT_RGB5A1,
		FORMAT_RGB10A2,
		FORMAT_DXT1,	// compressed formats
		FORMAT_DXT3,
		FORMAT_DXT5,
		FORMAT_ATI1,
		FORMAT_ATI2,
		FORMAT_ZLC1,
		FORMAT_ZLC2,
		FORMAT_LZ4,
	};

	enum
	{
		FILTER_POINT = 0,	// point filter
		FILTER_LINEAR,	// linear filter
	};
	bool create2D(int width, int height, int format, int num_mipmaps = 1, bool clear = true, bool allocate = true);
	bool create3D(int width, int height, int depth, int format, int num_mipmaps = 1, bool clear = true, bool allocate = true);
	bool createCube(int width, int height, int format, int num_mipmaps = 1, bool clear = true, bool allocate = true);
	bool create2DArray(int width, int height, int num_layers, int format, int num_mipmaps = 1, bool clear = true, bool allocate = true);
	bool createCubeArray(int width, int height, int num_layers, int format, int num_mipmaps = 1, bool clear = true, bool allocate = true);
	void create3DTurbulence(int size, float scale, int frequency, int seed);
	bool allocData(bool clear = true);
	void clearData();
	bool info(const char *file);
	bool load(const char *file);
	bool load(const char *file, int min_mip, int max_mip);
	bool load(const char *file, int offset);
	bool save(const char *file, float quality) const;
	bool save(const char *file) const;
	bool save(const Ptr<Stream> &stream) const;
	bool load(const Ptr<Stream> &stream);
	void clear();
	bool isLoaded() const;
	int getType() const;
	const char *getTypeName() const;
	static const char *getTypeName(int type);
	bool is2DType() const;
	bool is3DType() const;
	bool isCubeType() const;
	bool isArrayType() const;
	int getFormat() const;
	const char *getFormatName() const;
	static const char *getFormatName(int format);
	static int getFormat(int num_channels, int format);
	static bool isRawFormat(int format);
	bool isRawFormat() const;
	static bool isUCharFormat(int format);
	bool isUCharFormat() const;
	static bool isUShortFormat(int format);
	bool isUShortFormat() const;
	static bool isHalfFormat(int format);
	bool isHalfFormat() const;
	static bool isFloatFormat(int format);
	bool isFloatFormat() const;
	static bool isCombinedFormat(int format);
	bool isCombinedFormat() const;
	static bool isCompressedFormat(int format);
	bool isCompressedFormat() const;
	static bool isBCCompressedFormat(int format);
	bool isBCCompressedFormat() const;
	static bool isZCompressedFormat(int format);
	bool isZCompressedFormat() const;
	static int getNumChannels(int format);
	int getNumChannels() const;
	static int getPixelSize(int format);
	int getPixelSize() const;
	static size_t getPixelsSize(int format, int w, int h);
	size_t getPixelsSize() const;
	static int getBlockSize(int format);
	int getBlockSize() const;
	int getWidth() const;
	int getWidth(int level) const;
	int getHeight() const;
	int getHeight(int level) const;
	int getDepth() const;
	int getDepth(int level) const;
	bool hasMipmaps() const;
	int getNumMipmaps() const;
	int getNumLayers() const;
	int getNumFaces() const;
	size_t getOffset(int level) const;
	size_t getSize() const;
	size_t getSize(int level) const;
	size_t getStride(int level = 0) const;
	size_t getDepthStride(int level = 0) const;
	bool set(int channel, int value);
	bool swap(int channel, int index);
	void assignFrom(const Ptr<Image> &src_image);
	bool resizeFrom(const Ptr<Image> &src_image);
	bool copy(const Ptr<Image> &src_image, int layer);
	bool copy(const Ptr<Image> &src_image, int dest_channel, int src_channel);
	bool copy(const Ptr<Image> &src_image, int x_dst, int y_dst, int x_src, int y_src, int width, int height, bool safe = false);
	bool copyFast(const Ptr<Image> &src_image, size_t x_dst, size_t y_dst, size_t x_src, size_t y_src, size_t w, size_t h);
	bool blend(const Ptr<Image> &image, int x0, int y0, int x1, int y1, int width, int height, float scale = 1.0f, bool safe = false);
	bool compare(const Ptr<Image> &image, int x0, int y0, int x1, int y1, int width, int height, int threshold = 0);
	bool resize(int new_width, int new_height, int filter = FILTER_LINEAR);
	bool rotate(int angle);
	bool blur(int size);
	bool extrude(int pixels);
	bool normalize();
	bool invert();
	bool flipX();
	bool flipY();
	bool sign();
	bool createMipmaps(int filter = FILTER_LINEAR, float gamma = 1.0f);
	bool removeMipmaps();
	bool combineMipmaps();
	bool decombineMipmaps();
	int convertToType(int type);
	int convertToFormat(int new_format);
	bool decombine();
	bool combine(int new_format = -1);
	bool decompress();
	bool compress(int new_format = -1);
	void swap(const Ptr<Image> &image);
	static Image::Pixel toPixel(int format, const Math::vec4 &color);
	Image::Pixel toPixel(const Math::vec4 &color);
	static Math::vec4 toVec4(int format, const Image::Pixel & p);
	Math::vec4 toVec4(const Image::Pixel & pixel);
	Math::vec4 get(const Math::ivec2 &coord, int offset) const;
	void get(const Math::ivec2 &coord, int offset, Math::vec4 &p00, Math::vec4 &p01, Math::vec4 &p10, Math::vec4 &p11) const;
	void get8F(const Math::ivec2 &coord, Math::vec4 &p) const;
	float get8F(const Math::ivec2 &coord) const;
	void get16F(const Math::ivec2 &coord, Math::vec4 &p) const;
	float get16F(const Math::ivec2 &coord) const;
	void get32F(const Math::ivec2 &coord, Math::vec4 &p) const;
	float get32F(const Math::ivec2 &coord) const;
	void set2D(int x, int y, const Image::Pixel & p);
	Image::Pixel get2D(int x, int y) const;
	Image::Pixel get2D(float x, float y) const;
	Image::Pixel get2D(float x, float y, const Image::Pixel & skip_pixel) const;
	void set3D(int x, int y, int z, const Image::Pixel & p);
	Image::Pixel get3D(int x, int y, int z) const;
	Image::Pixel get3D(float x, float y, float z) const;
	Image::Pixel get3DSmooth(float x, float y, float z) const;
	void setCube(int x, int y, int face, const Image::Pixel & p);
	Image::Pixel getCube(int x, int y, int face) const;
	Image::Pixel getCube(float x, float y, int face) const;
	Image::Pixel getCube(const Math::vec3 &direction) const;
	void set2DArray(int x, int y, int layer, const Image::Pixel & p);
	Image::Pixel get2DArray(int x, int y, int layer) const;
	Image::Pixel get2DArray(float x, float y, int layer) const;
	void setCubeArray(int x, int y, int face, int layer, const Image::Pixel & p);
	Image::Pixel getCubeArray(int v1, int v2, int face, int layer) const;
	Image::Pixel getCubeArray(float v1, float v2, int face, int layer) const;
	Image::Pixel getCubeArray(const Math::vec3 &direction, int layer) const;
	unsigned char * getPixels() const;
	unsigned char * getPixels2D(int level = 0) const;
	unsigned char * getPixels3D(int level = 0) const;
	unsigned char * getPixelsCube(int face, int level = 0) const;
	unsigned char * getPixels2DArray(int layer, int level = 0) const;
	unsigned char * getPixelsCubeArray(int face, int layer, int level = 0) const;
	void setPixels(unsigned char * pixels);
	void getPixels(const Ptr<Blob> &blob) const;
	int setPixels(const Ptr<Blob> &blob);
	bool invertChannel(unsigned char ch);
};
typedef Ptr<Image> ImagePtr;

} // namespace Unigine
