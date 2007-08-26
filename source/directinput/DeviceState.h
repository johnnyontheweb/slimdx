/*
* Copyright (c) 2007 SlimDX Group
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

using namespace System;

#include "DeviceConstants.h"
#include "Enums.h"

namespace SlimDX
{
	namespace DirectInput
	{
		/// <summary>
		/// Describes the state of a joystick device.
		/// </summary>
		public ref class JoystickState
		{
		private:
			int x;
			int y;
			int z;
			int rx;
			int ry;
			int rz;
			array<int>^ sliders;
			array<int>^ povs;
			array<bool>^ buttons;
			int vx;
			int vy;
			int vz;
			int vrx;
			int vry;
			int vrz;
			array<int>^ vsliders;
			int ax;
			int ay;
			int az;
			int arx;
			int ary;
			int arz;
			array<int>^ asliders;
			int fx;
			int fy;
			int fz;
			int frx;
			int fry;
			int frz;
			array<int>^ fsliders;

		internal:
			JoystickState( const DIJOYSTATE2 &joystate );

		public:
			/// <summary>
			/// Gets the state of each point-of-view controller on the joystick.
			/// </summary>
			property array<int>^ PointOfViewControllers
			{
				array<int>^ get() { return povs; }
			}

			/// <summary>
			/// Gets the position of each slider on the joystick.
			/// </summary>
			property array<int>^ Sliders
			{
				array<int>^ get() { return sliders; }
			}

			/// <summary>
			/// Gets the velocity of each slider on the joystick.
			/// </summary>
			property array<int>^ VelocitySliders
			{
				array<int>^ get() { return vsliders; }
			}

			/// <summary>
			/// Gets the acceleration of each slider on the joystick.
			/// </summary>
			property array<int>^ AccelerationSliders
			{
				array<int>^ get() { return asliders; }
			}

			/// <summary>
			/// Gets the force of each slider on the joystick.
			/// </summary>
			property array<int>^ ForceSliders
			{
				array<int>^ get() { return fsliders; }
			}

			/// <summary>
			/// Gets the state of each button on the joystick.
			/// </summary>
			property array<bool>^ Buttons
			{
				array<bool>^ get() { return buttons; }
			}

			/// <summary>
			/// Gets the X-axis, usually the left-right movement of a stick.
			/// </summary>
			property int X
			{
				int get() { return x; }
			}

			/// <summary>
			/// Gets the Y-axis, usually the forward-backward movement of a stick.
			/// </summary>
			property int Y
			{
				int get() { return y; }
			}

			/// <summary>
			/// Gets the Z-axis, often the throttle control.
			/// </summary>
			property int Z
			{
				int get() { return z; }
			}

			/// <summary>
			/// Gets the X-axis rotation.
			/// </summary>
			property int RotationX
			{
				int get() { return rx; }
			}

			/// <summary>
			/// Gets the Y-axis rotation.
			/// </summary>
			property int RotationY
			{
				int get() { return ry; }
			}

			/// <summary>
			/// Gets the Z-axis rotation.
			/// </summary>
			property int RotationZ
			{
				int get() { return rz; }
			}

			/// <summary>
			/// Gets the X-axis velocity.
			/// </summary>
			property int VelocityX
			{
				int get() { return vx; }
			}

			/// <summary>
			/// Gets the Y-axis velocity.
			/// </summary>
			property int VelocityY
			{
				int get() { return vy; }
			}

			/// <summary>
			/// Gets the Z-axis velocity.
			/// </summary>
			property int VelocityZ
			{
				int get() { return vz; }
			}

			/// <summary>
			/// Gets the X-axis angular velocity.
			/// </summary>
			property int AngularVelocityX
			{
				int get() { return vrx; }
			}

			/// <summary>
			/// Gets the Y-axis angular velocity.
			/// </summary>
			property int AngularVelocityY
			{
				int get() { return vry; }
			}

			/// <summary>
			/// Gets the Z-axis angular velocity.
			/// </summary>
			property int AngularVelocityZ
			{
				int get() { return vrz; }
			}

			/// <summary>
			/// Gets the X-axis acceleration.
			/// </summary>
			property int AccelerationX
			{
				int get() { return ax; }
			}

			/// <summary>
			/// Gets the Y-axis acceleration.
			/// </summary>
			property int AccelerationY
			{
				int get() { return ay; }
			}

			/// <summary>
			/// Gets the Z-axis acceleration.
			/// </summary>
			property int AccelerationZ
			{
				int get() { return az; }
			}

			/// <summary>
			/// Gets the X-axis angular acceleration.
			/// </summary>
			property int AngularAccelerationX
			{
				int get() { return arx; }
			}

			/// <summary>
			/// Gets the Y-axis angular acceleration.
			/// </summary>
			property int AngularAccelerationY
			{
				int get() { return ary; }
			}

			/// <summary>
			/// Gets the Z-axis angular acceleration.
			/// </summary>
			property int AngularAccelerationZ
			{
				int get() { return arz; }
			}

			/// <summary>
			/// Gets the X-axis force.
			/// </summary>
			property int ForceX
			{
				int get() { return fx; }
			}

			/// <summary>
			/// Gets the Y-axis force.
			/// </summary>
			property int ForceY
			{
				int get() { return fy; }
			}

			/// <summary>
			/// Gets the Z-axis force.
			/// </summary>
			property int ForceZ
			{
				int get() { return fz; }
			}

			/// <summary>
			/// Gets the X-axis torque.
			/// </summary>
			property int TorqueX
			{
				int get() { return frx; }
			}

			/// <summary>
			/// Gets the Y-axis torque.
			/// </summary>
			property int TorqueY
			{
				int get() { return fry; }
			}

			/// <summary>
			/// Gets the Z-axis torque.
			/// </summary>
			property int TorqueZ
			{
				int get() { return frz; }
			}
		};

		/// <summary>
		/// Describes the state of a keyboard device.
		/// </summary>
		public ref class KeyboardState
		{
		internal:
			KeyboardState() { keys = gcnew array<bool>( 256 ); }
			array<bool>^ keys;

		public:
			/// <summary>
			/// Gets the state of the specified key.
			/// </summary>
			property bool default [Keys]
			{
				bool get( Keys index ) { return keys[(int)index]; }
			}
		};

		/// <summary>
		/// Describes the state of a mouse device.
		/// </summary>
		public ref class MouseState
		{
		private:
			array<bool>^ buttons;
			int x;
			int y;
			int z;

		internal:
			MouseState( int x, int y, int z ) : x(x), y(y), z(z)
			{
				buttons = gcnew array<bool>( 8 );
			}

		public:
			/// <summary>
			/// Gets the X axis of the mouse.
			/// </summary>
			property int X
			{
				int get() { return x; }
			}

			/// <summary>
			/// Gets the Y axis of the mouse.
			/// </summary>
			property int Y
			{
				int get() { return y; }
			}

			/// <summary>
			/// Gets the Z axis of the mouse.
			/// </summary>
			property int Z
			{
				int get() { return z; }
			}

			/// <summary>
			/// Gets the state of the mouse buttons.
			/// </summary>
			property array<bool>^ Buttons
			{
				array<bool>^ get() { return buttons; }
			}
		};
	}
}