//////////////////////////////////////////////////////////////////////////////
//
// Geoweb3d SDK
// Copyright (c) Geoweb3d, 2008-2021, all rights reserved.
//
// This code can be used only under the rights granted to you by the specific
// GeoWeb3d SDK license under which the SDK provided.
//
//////////////////////////////////////////////////////////////////////////////
#pragma once

#include "../core/GW3DInterFace.h"

/*! Primary namespace */
namespace Geoweb3d
{

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A Label </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////

struct IGW3DLabel
{
	virtual ~IGW3DLabel() {}

	enum class Align
	{
		Start,
		Center,
		End
	};

	virtual void insert_Text(const char* text, size_t index, float r, float g, float b, float a, const IGW3DFontWPtr& font_in) = 0;
	virtual void remove_Text(size_t index, size_t length) = 0;
	virtual void put_Text(const char* text, float r, float g, float b, float a, const IGW3DFontWPtr& font_in) = 0;
	virtual void append_Text(const char* text, float r, float g, float b, float a, const IGW3DFontWPtr& font_in) = 0;
	virtual void show_Caret(bool show) = 0;
	virtual void put_CaretPosition(int position) = 0;
	virtual int  get_CaretPosition() = 0;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	A Font </summary>
////////////////////////////////////////////////////////////////////////////////////////////////////
struct IGW3DFont
{
	/// Available font styles
	enum Style
	{
		NORMAL, // Normal font
		BOLD	//Bold font
	};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the font's name. </summary>
	///
	/// <remarks>	Gets the name of the font.	</remarks>
	///
	/// <returns>	The name. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual const char* get_FontName() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the font's style. </summary>
	///
	/// <remarks>	Gets the style of the font.	</remarks>
	///
	/// <returns>	The style. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual Style get_Style() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Query if font is underlined. </summary>
	///
	/// <remarks>	Gets the underlined state of the font.	</remarks>
	///
	/// <returns>	True if the font is underlined. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual bool get_Underline() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the font's point size. </summary>
	///
	/// <remarks>	Gets the point size of the font.	</remarks>
	///
	/// <returns>	The size. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual int get_FontSize() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the font's cell height. </summary>
	///
	/// <remarks>	Gets the cell height of the font. </remarks>
	///
	/// <returns>	The height. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual int get_CellHeight() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the font's cell width. </summary>
	///
	/// <remarks>	Gets the cell width of the font. </remarks>
	///
	/// <returns>	The width. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual int get_CellWidth() const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets width of text. </summary>
	///
	/// <remarks>	Gets the width of text in pixels. </remarks>
	///
	/// <param name="name">	The text. </param>
	///
	/// <returns>	The width. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual int get_WidthOfText(const char* text) const = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the font's configuration. </summary>
	///
	/// <remarks>	Sets the configuration of the font.	</remarks>
	///
	/// <param name="name">	The name of the font. </param>
	/// <param name="ptSize">	The point size of the font. </param>
	/// <param name="style">	The style of the font. </param>
	/// <param name="underline">	The underlined state of the font. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual void put_Config(const char* name, int ptSize, Style style, bool underline) = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Create a copy of this font. </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	virtual IGW3DFontPtr create_clone() = 0;

	static GEOWEB3DENGINE_API IGW3DFontPtr create(const char* font_name, int ptSize, Style style, bool underline,  unsigned interface_version = GEOWEB3D_INTERFACE_VERSION );

};

}