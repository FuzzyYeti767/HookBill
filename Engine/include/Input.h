#pragma once
/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Input.h
Project: CS230
Author: Kevin Wright
Creation date: 2/10/2021
-----------------------------------------------------------------*/

#pragma once
#include <vector>

namespace HookBill {
	class InputKey {
	public:
		enum class Keyboard {
			None = -1,
			Space = 32,
			Apostrophe = 39,  /* ' */
			Comma = 44,           /* , */
			Minus = 45,           /* - */
			Period = 46,         /* . */
			Slash = 47,           /* / */

			/* Number keys */
			Num0 = 48,
			Num1 = 49,
			Num2 = 50,
			Num3 = 51,
			Num4 = 52,
			Num5 = 53,
			Num6 = 54,
			Num7 = 55,
			Num8 = 56,
			Num9 = 57,

			/* Alphabet keys */
			A = 65,
			B = 66,
			C = 67,
			D = 68,
			E = 69,
			F = 70,
			G = 71,
			H = 72,
			I = 73,
			J = 74,
			K = 75,
			L = 76,
			M = 77,
			N = 78,
			O = 79,
			P = 80,
			Q = 81,
			R = 82,
			S = 83,
			T = 84,
			U = 85,
			V = 86,
			W = 87,
			X = 88,
			Y = 89,
			Z = 90,

			/* Function keys */
			F1 = 290,
			F2 = 291,
			F3 = 292,
			F4 = 293,
			F5 = 294,
			F6 = 295,
			F7 = 296,
			F8 = 297,
			F9 = 298,
			F10 = 299,
			F11 = 300,
			F12 = 301,

			/* Modifier keys */
			LeftShift = 340,
			LeftControl = 341,
			LeftAlt = 342,
			RightShift = 344,
			RightControl = 345,
			RightAlt = 346,

			/* Arrow keys */
			Left = 263,
			Right = 262,
			Up = 265,
			Down = 264,

			Enter = 257,
			Escape = 256,
			Tab = 258,
			Backspace = 259,
			Insert = 260,
			Delete = 261,
			Home = 268,
			End = 269,
			PageUp = 266,
			PageDown = 267,

			/* Special keys */
			CapsLock = 280,
			ScrollLock = 281,
			NumLock = 282,
			PrintScreen = 283,
			Pause = 284,

			/* Keypad keys */
			KP0 = 320,
			KP1 = 321,
			KP2 = 322,
			KP3 = 323,
			KP4 = 324,
			KP5 = 325,
			KP6 = 326,
			KP7 = 327,
			KP8 = 328,
			KP9 = 329,
			KPDecimal = 330,
			KPDivide = 331,
			KPMultiply = 332,
			KPSubtract = 333,
			KPAdd = 334,
			KPEnter = 335,
			KPEqual = 336,

			/* Numpad keys */
			Numpad0 = 96,
			Numpad1 = 97,
			Numpad2 = 98,
			Numpad3 = 99,
			Numpad4 = 100,
			Numpad5 = 101,
			Numpad6 = 102,
			Numpad7 = 103,
			Numpad8 = 104,
			Numpad9 = 105,
			NumpadMultiply = 106,
			NumpadAdd = 107,
			NumpadSeparator = 108,
			NumpadSubtract = 109,
			NumpadDecimal = 110,
			NumpadDivide = 111,

			/* Miscellaneous keys */
			Menu = 348,

			/* Key count */
			Count
		};

		InputKey(Keyboard button);
		bool IsKeyDown() const;
		bool IsKeyReleased() const;
	private:
		Keyboard button;
	};

	class Input {
	public:
		Input();
		bool IsKeyDown(InputKey::Keyboard key) const;
		bool IsKeyReleased(InputKey::Keyboard key) const;
		void SetKeyDown(InputKey::Keyboard key, bool value);
		void Update();
	private:
		std::vector<bool> keyDown;
		std::vector<bool> wasKeyDown;
	};
}
