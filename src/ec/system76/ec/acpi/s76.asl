/* SPDX-License-Identifier: GPL-2.0-only */

// Notifications:
//   0x80 - hardware backlight toggle
//   0x81 - backlight toggle
//   0x82 - backlight down
//   0x83 - backlight up
//   0x84 - backlight color change
Device (S76D) {
	Name (_HID, "17761776")
	Name (_UID, 0)

	Method (RSET, 0, Serialized) {
		Debug = "S76D: RSET"
		SAPL(0)
		SKBL(0)
#if CONFIG(EC_SYSTEM76_EC_COLOR_KEYBOARD)
			SKBC(0xFFFFFF)
#endif // CONFIG(EC_SYSTEM76_EC_COLOR_KEYBOARD)
	}

	Method (INIT, 0, Serialized) {
		Debug = "S76D: INIT"
		RSET()
		If (^^PCI0.LPCB.EC0.ECOK) {
			// Set flags to use software control
			^^PCI0.LPCB.EC0.ECOS = 2
			Return (0)
		} Else {
			Return (1)
		}
	}

	Method (FINI, 0, Serialized) {
		Debug = "S76D: FINI"
		RSET()
		If (^^PCI0.LPCB.EC0.ECOK) {
			// Set flags to use hardware control
			^^PCI0.LPCB.EC0.ECOS = 1
			Return (0)
		} Else {
			Return (1)
		}
	}

	// Get Airplane LED
	Method (GAPL, 0, Serialized) {
		If (^^PCI0.LPCB.EC0.ECOK) {
			If (^^PCI0.LPCB.EC0.AIRP & 0x40) {
				Return (1)
			}
		}
		Return (0)
	}

	// Set Airplane LED
	Method (SAPL, 1, Serialized) {
		If (^^PCI0.LPCB.EC0.ECOK) {
			If (Arg0) {
				^^PCI0.LPCB.EC0.AIRP |= 0x40
			} Else {
				^^PCI0.LPCB.EC0.AIRP &= 0xBF
			}
		}
	}

#if CONFIG(EC_SYSTEM76_EC_COLOR_KEYBOARD)
	// Set KB LED Brightness
	Method (SKBL, 1, Serialized) {
		If (^^PCI0.LPCB.EC0.ECOK) {
			^^PCI0.LPCB.EC0.FDAT = 6
			^^PCI0.LPCB.EC0.FBUF = Arg0
			^^PCI0.LPCB.EC0.FBF1 = 0
			^^PCI0.LPCB.EC0.FBF2 = Arg0
			^^PCI0.LPCB.EC0.FCMD = 0xCA
		}
	}

	// Set Keyboard Color
	Method (SKBC, 1, Serialized) {
		If (^^PCI0.LPCB.EC0.ECOK) {
			^^PCI0.LPCB.EC0.FDAT = 0x3
			^^PCI0.LPCB.EC0.FBUF = (Arg0 & 0xFF)
			^^PCI0.LPCB.EC0.FBF1 = ((Arg0 >> 16) & 0xFF)
			^^PCI0.LPCB.EC0.FBF2 = ((Arg0 >> 8) & 0xFF)
			^^PCI0.LPCB.EC0.FCMD = 0xCA
			Return (Arg0)
		} Else {
			Return (0)
		}
	}
#else // CONFIG(EC_SYSTEM76_EC_COLOR_KEYBOARD)
	// Get KB LED
	Method (GKBL, 0, Serialized) {
		Local0 = 0
		If (^^PCI0.LPCB.EC0.ECOK) {
			^^PCI0.LPCB.EC0.FDAT = One
			^^PCI0.LPCB.EC0.FCMD = 0xCA
			Local0 = ^^PCI0.LPCB.EC0.FBUF
			^^PCI0.LPCB.EC0.FCMD = Zero
		}
		Return (Local0)
	}

	// Set KB Led
	Method (SKBL, 1, Serialized) {
		If (^^PCI0.LPCB.EC0.ECOK) {
			^^PCI0.LPCB.EC0.FDAT = Zero
			^^PCI0.LPCB.EC0.FBUF = Arg0
			^^PCI0.LPCB.EC0.FCMD = 0xCA
		}
	}
#endif // CONFIG(EC_SYSTEM76_EC_COLOR_KEYBOARD)
}
