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

#include <d3dx10.h>
#include <vcclr.h>

#include "Direct3D10Exception.h"

#include "Buffer.h"
#include "Device.h"
#include "Mesh.h"
#include "MeshBuffer.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Collections::ObjectModel;

namespace SlimDX
{
namespace Direct3D10
{
	Mesh::Mesh( ID3DX10Mesh* pointer )
	{
		Construct( pointer );
	}
	
	Mesh::v( IntPtr pointer )
	{
		Construct( pointer, NativeInterface );
	}
	
	Mesh::Mesh( Device^ device, array<InputElement>^ elements, System::String^ positionElement, int vertexCount, int faceCount, MeshFlags flags )
	{
		D3D10_INPUT_ELEMENT_DESC nativeElements[D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT];
		for( int i = 0; i < elements->Length; ++i )
			nativeElements[i] = elements[i].CreateNativeVersion();
		
		array<unsigned char>^ nameBytes = System::Text::ASCIIEncoding::ASCII->GetBytes( positionElement );
		pin_ptr<unsigned char> pinnedName = &nameBytes[ 0 ];

		ID3DX10Mesh* mesh = 0;
		if( RECORD_D3D10( D3DX10CreateMesh( device->InternalPointer, nativeElements, elements->Length, nameBytes, static_cast<UINT>( vertexCount ), static_cast<UINT>( faceCount ), static_cast<UINT>( flags ), &mesh ) ).IsFailure )
			throw gcnew Direct3D10Exception( Result::Last );

		Construct( mesh );
	}

	Mesh^ Mesh::FromPointer( ID3DX10Mesh* pointer )
	{
		if( pointer == 0 )
			return nullptr;

		Font^ tableEntry = safe_cast<Mesh^>( ObjectTable::Find( static_cast<IntPtr>( pointer ) ) );
		if( tableEntry != nullptr )
		{
			pointer->Release();
			return tableEntry;
		}

		return gcnew Mesh( pointer );
	}

	Mesh^ Mesh::FromPointer( IntPtr pointer )
	{
		if( pointer == IntPtr::Zero )
			throw gcnew ArgumentNullException( "pointer" );

		Mesh^ tableEntry = safe_cast<Mesh^>( ObjectTable::Find( static_cast<IntPtr>( pointer ) ) );
		if( tableEntry != nullptr )
		{
			return tableEntry;
		}

		return gcnew Mesh( pointer );
	}
	
	MeshFlags Mesh::Flags::get() 
	{
		return InternalPointer->GetFlags();
	}

	int Mesh::FaceCount::get() 
	{
		return InternalPointer->GetFaceCount();
	}

	int Mesh::VertexCount::get() 
	{
		return InternalPointer->GetVertexCount();
	}

	int Mesh::VertexBufferCount::get() 
	{
		return InternalPointer->GetVertexBufferCount();
	}
	
	Mesh^ Mesh::Clone( array<InputElement>^ elements, System::String^ positionElement, MeshFlags flags ) 
	{
		D3D10_INPUT_ELEMENT_DESC nativeElements[D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT];
		for( int i = 0; i < elements->Length; ++i )
			nativeElements[i] = elements[i].CreateNativeVersion();
		
		array<unsigned char>^ nameBytes = System::Text::ASCIIEncoding::ASCII->GetBytes( positionElement );
		pin_ptr<unsigned char> pinnedName = &nameBytes[ 0 ];

		ID3DX10Mesh* mesh = 0;
		if( RECORD_D3D10( InternalPointer->Clone( static_cast<UINT>( flags ), nameBytes, nativeElements, elements->Length, &mesh ) ).IsFailure )
			return nullptr;
		
		return gcnew Mesh( mesh );
	}

	Result Mesh::GenerateAdjacencyAndPointRepresentation( float epsilon )
	{
		return RECORD_D3D10( InternalPointer->GenerateAdjacencyAndPointReps( epsilon ) );
	}

	Result Mesh::GenerateAttributeBufferFromTable()
	{
		return RECORD_D3D10( InternalPointer->GenerateAttributeBufferFromTable() );
	}

	Result Mesh::GenerateGeometryShaderAdjacency()
	{
		return RECORD_D3D10( InternalPointer->GenerateGSAdjacency() );
	}

	Result Mesh::Commit()
	{
		return RECORD_D3D10( InternalPointer->CommitToDevice() );
	}

	Result Mesh::Discard( MeshDiscardFlags flags )
	{
		return RECORD_D3D10( InternalPointer->Discard( static_cast<D3DX10_MESH_DISCARD_FLAGS>( flags ) ) );
	}

	Result Mesh::DrawSubset( int id )
	{
		return RECORD_D3D10( InternalPointer->DrawSubset( id ) );
	}

	Result Mesh::DrawSubsetInstanced( int id, int count, int startLocation)
	{
		return RECORD_D3D10( InternalPointer->DrawSubsetInstanced( id, count, startLocation ) );
	}
	
	MeshBufer^ Mesh::GetIndexBuffer()
	{
		ID3DX10MeshBuffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetIndexBuffer( &buffer ) ).IsFailure )
			return nullptr;
		return gcnew MeshBuffer( buffer );
	}

	MeshBufer^ Mesh::GetVertexBuffer( int index )
	{
		ID3DX10MeshBuffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetVertexBuffer( index, &buffer ) ).IsFailure )
			return nullptr;
		return gcnew MeshBuffer( buffer );
	}

	MeshBuffer^ Mesh::GetPointRepresentationBuffer()
	{
		ID3DX10MeshBuffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetPointRepBuffer( &buffer ) ).IsFailure )
			return nullptr;
		return gcnew MeshBuffer( buffer );
	}

	MeshBuffer^ Mesh::GetAdjacencyBuffer()
	{
		ID3DX10MeshBuffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetAdjacencyBuffer( &buffer ) ).IsFailure )
			return nullptr;
		return gcnew MeshBuffer( buffer );
	}

	MeshBuffer^ Mesh::GetAttributeBuffer()
	{
		ID3DX10MeshBuffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetAttributeBuffer( &buffer ) ).IsFailure )
			return nullptr;
		return gcnew MeshBuffer( buffer );
	}
	
	Result Mesh::SetIndexData( DataStream^ data, int count ) 
	{
		return RECORD_D3D10( InternalPointer->SetIndexData( data->RawPointer, count ) );
	}

	Result Mesh::SetVertexData( int index, DataStream^ data ) 
	{
		return RECORD_D3D10( InternalPointer->SetVertexData( index, data->RawPointer ) );
	}

	Result Mesh::SetPointRepresentationData( DataStream^ data ) 
	{
		return RECORD_D3D10( InternalPointer->SetPointRepData( data->RawPointer ) );
	}

	Result Mesh::SetAdjacencyData( DataStream^ data ) 
	{
		return RECORD_D3D10( InternalPointer->SetAdjacencyData( data->RawPointer ) );
	}

	Result Mesh::SetAttributeData( DataStream^ data ) 
	{
		return RECORD_D3D10( InternalPointer->SetAttributeData( data->RawPointer ) );
	}

	Result Mesh::SetAttributeTable( array<MeshAttributeRange>^ ranges ) 
	{
		stack_vector<D3DX10_ATTRIBUTE_RANGE> nativeRanges( ranges->Length );
		for( int rangeIndex = 0; rangeIndex < ranges->Length; ++rangeIndex )
			nativeRanges[ rangeIndex ] = ranges[ rangeIndex].CreateNativeVersion();

		return RECORD_D3D10( InternalPointer->SetAttributeData( &nativeRanges[0], ranges->Length ) );
	}

	ReadOnlyCollection<MeshAttributeRange>^ Mesh::GetAttributeTable()
	{
		UINT count = 0;
		if( RECORD_D3D10( InternalPointer->GetAttributeTable( 0, &count ) ).IsFailure )
			return nullptr;

		stack_vector<D3DX10_ATTRIBUTE_RANGE> ranges( count );
		if( RECORD_D3D10( InternalPointer->GetAttributeTable( &ranges[0], &count ) ).IsFailure )
			return nullptr;
		
		List<MeshAttributeRange>^ list = gcnew List<MeshAttributeRange>( count );
		for( int rangeIndex = 0; rangeIndex < count; ++rangeIndex ) 
			list[rangeIndex] = MeshAttributeRange( ranges[rangeIndex] );
		return gcnew ReadOnlyCollection<MeshAttributeRange>( list );
	}

	ReadOnlyCollection<InputElement>^ Mesh::GetVertexDescription()
	{
		UINT count = 0;
		if( RECORD_D3D10( InternalPointer->GetVertexDescription( 0, &count ) ).IsFailure )
			return nullptr;

		stack_vector<D3D10_INPUT_ELEMENT_DESC> descs( count );
		if( RECORD_D3D10( InternalPointer->GetVertexDescription( &descs[0], &count ) ).IsFailure )
			return nullptr;
		
		List<InputElement>^ list = gcnew List<InputElement>( count );
		for( int descIndex = 0; descIndex < count; ++descIndex ) 
			list[descIndex] = InputElement( descs[descIndex] );
		return gcnew ReadOnlyCollection<InputElement>( list );
	}

	Buffer^ Mesh::GetDeviceIndexBuffer() 
	{
		ID3D10Buffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetDeviceIndexBuffer( &buffer ) ).IsFailure )
			return nullptr;
		return gcnew Buffer( buffer );
	}

	Buffer^ Mesh::GetDeviceVertexBuffer( int index ) 
	{
		ID3D10Buffer* buffer = 0;
		if( RECORD_D3D10( InternalPointer->GetDeviceVertexBuffer( index, &buffer ) ).IsFailure )
			return nullptr;
		return gcnew Buffer( buffer );
	}
}
}