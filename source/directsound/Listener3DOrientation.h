/*
* Copyright (c) 2007-2008 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#include <dsound.h>
#include "../Math/Vector3.h"

namespace SlimDX
{
	namespace DirectSound
	{
		/// <summary>
		/// Encompasses the front and top 3-D vectors for listeners orientation.
		/// </summary>
		public value class Listener3DOrientation
		{
		internal:
			Listener3DOrientation( D3DVECTOR front, D3DVECTOR top );

		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="SlimDX::DirectSound::Listener3DOrientation"/> class.
			/// </summary>
			/// <param name="front">The front vector.</param>
			/// <param name="front">The top vector.</param>
			Listener3DOrientation( Vector3 front, Vector3 top );

			/// <summary>
			/// Gets or Sets the top of the listener's orientation.
			/// </summary>
			property Vector3 Top;
			/// <summary>
			/// Gets or Sets the front of the listener's orientation.
			/// </summary>
			property Vector3 Front;
		};
	}
}