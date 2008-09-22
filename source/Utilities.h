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

#include <windows.h>
#include <d3dx9.h>
#include <dxgi.h>

#include "Result.h"

namespace SlimDX
{
	ref class ComObject;

	ref class Utilities sealed
	{
	private:
		Utilities();
		
	public:
		static GUID GetNativeGuidForType( System::Type^ type );

		static System::Guid ConvertNativeGuid( const GUID &guid );
		static GUID ConvertManagedGuid( System::Guid guid );
		
		static int SizeOfFormatElement( DXGI_FORMAT format );
		
		static System::Drawing::Rectangle ConvertRect(RECT rect);

		static System::String^ BufferToString( ID3DXBuffer *buffer );

		static array<System::Byte>^ ReadStream( System::IO::Stream^ stream, int readLength );

		generic<typename T> where T : value class
		static array<T>^ ReadRange( ID3DXBuffer *buffer, int count );

		static void CheckBounds( int lowerBound, int size, int offset, int% count );

		static void CheckArrayBounds( System::Array^ data, int offset, int% count );
		
		generic<typename T>
		static bool CheckElementEquality( System::Collections::Generic::IList<T>^ left, System::Collections::Generic::IList<T>^ right );
		
		static void FreeNativeString( LPCSTR string );
		static void FreeNativeString( LPSTR string );

		static LPSTR AllocateNativeString( System::String^ string );

		generic<typename T> where T : value class
		static T FromIntToT( int value );
	};
}
