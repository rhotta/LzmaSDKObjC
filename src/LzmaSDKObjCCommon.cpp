/*
 *   Copyright (c) 2015 - 2016 Kulykov Oleh <info@resident.name>
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in
 *   all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *   THE SOFTWARE.
 */


#include "LzmaSDKObjCCommon.h"
#include "../lzma/CPP/Common/MyGuidDef.h"

const GUID LzmaSDKObjCCLSIDFormat7z = CONSTRUCT_GUID(0x23170F69, 0x40C1, 0x278A, 0x10, 0x00, 0x00, 0x01, 0x10, 0x07, 0x00, 0x00);

const GUID LzmaSDKObjCCLSIDFormatXz = CONSTRUCT_GUID(0x23170F69, 0x40C1, 0x278A, 0x10, 0x00, 0x00, 0x01, 0x10, 0x0C, 0x00, 0x00);

uint64_t LzmaSDKObjCPROPVARIANTGetUInt64(PROPVARIANT * prop)
{
	switch (prop->vt)
	{
		case VT_UI8: return prop->uhVal.QuadPart;

		case VT_HRESULT:
		case VT_UI4:
			return prop->ulVal;

		case VT_UINT: return prop->uintVal;
		case VT_I8: return prop->hVal.QuadPart;
		case VT_UI1: return prop->bVal;
		case VT_I4: return prop->lVal;
		case VT_INT: return prop->intVal;

		default: break;
	}
	return 0;
}

bool LzmaSDKObjCPROPVARIANTGetBool(PROPVARIANT * prop)
{
	switch (prop->vt)
	{
		case VT_BOOL: return (prop->boolVal == 0) ? false : true;
		default: break;
	}
	return (LzmaSDKObjCPROPVARIANTGetUInt64(prop) == 0) ? false : true;
}

time_t LzmaSDKObjCFILETIMEToUnixTime(const FILETIME filetime)
{
	long long int t = filetime.dwHighDateTime;
	t <<= 32;
	t += (unsigned long)filetime.dwLowDateTime;
	t -= 116444736000000000LL;
	return (time_t)(t / 10000000);
}
