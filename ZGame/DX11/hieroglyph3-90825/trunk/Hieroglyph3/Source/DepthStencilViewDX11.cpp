﻿//--------------------------------------------------------------------------------
// This file is a portion of the Hieroglyph 3 Rendering Engine.  It is distributed
// under the MIT License, available in the root of this distribution and
// at the following URL:
//
// http://www.opensource.org/licenses/mit-license.php
//
// Copyright (c) Jason Zink
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
#include "PCH.h"
#include "DepthStencilViewDX11.h"
//--------------------------------------------------------------------------------
using namespace Glyph3;
//--------------------------------------------------------------------------------
DepthStencilViewDX11::DepthStencilViewDX11( DepthStencilViewComPtr pView )
{
    m_pDepthStencilView = pView;
}
//--------------------------------------------------------------------------------
DepthStencilViewDX11::~DepthStencilViewDX11()
{
}
//--------------------------------------------------------------------------------
